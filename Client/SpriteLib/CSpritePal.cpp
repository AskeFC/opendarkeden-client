#include "client_PCH.h"
#include "CSpritePal.h"
#include "CSpriteSurface.h"


DWORD	CSpritePal::s_Value1 = 1;
DWORD	CSpritePal::s_Value2 = 31;
DWORD	CSpritePal::s_Value3 = 1;

void CSpritePal::SetPixel(BYTE *pSource, WORD pitch, WORD width, WORD height)
{
	// memory����
	Release();

	m_Width = width;
	m_Height = height;

	// �ϴ� memory�� ������ ��Ƶд�.	
	BYTE*	data = new BYTE[m_Width*2+10];

	int		index;				// data�� index�� ���
	int		count;				// �ݺ���
	int		trans,				// ����� ����
			color;				// ������ �ƴѻ� ����

	BOOL	bCheckTrans;		// �ֱٿ� �˻��Ѱ� ������ΰ�?

	BYTE	*pSourceTemp;


	// height�� ��ŭ memory���
	m_pPixels = new BYTE* [height];
	BYTE **Pixels = new BYTE* [height];
	std::vector<int> PixelSize;

	register int i;
	register int j;

	for (i=0; i<height; i++)
	{
		index = 0;
		count = 0;
		trans = 0;
		color = 0;
		bCheckTrans = TRUE;
		pSourceTemp = pSource;

//		// �� line�� ���ؼ� ����~
//		for (j=0; j<width; j++)
//		{
//			// 0�� color�� ���ؼ� ����
//			if (*pSourceTemp==s_Colorkey)
//			{
//				// �ֱٿ� �˻��Ѱ� ������� �ƴϾ��ٸ�
//				if (!bCheckTrans)
//				{
//					// ' (����,�����,�����) '�� �� set�� �������� �ǹ��ϹǷ�
//					count++;					
//					data[lastColorIndex] = color;
//					color = 0;
//					bCheckTrans = TRUE;
//				}				
//				trans++;				
//			}
//			else
//			{
//				// �ֱٿ� �˻��Ѱ� ������̾��ٸ�..
//				if (bCheckTrans)
//				{						
//					data[index++] = trans;		// ���� byte�� ������� �ִ´�.
//					trans = 0;
//					lastColorIndex=index++;			// ������� ���� ��ġ�� ���
//					bCheckTrans = FALSE;
//				}
//				data[index++] = *pSourceTemp;	// ���� ������ �����Ѵ�.
//				color++;								
//			}
//			pSourceTemp++;
//		}
		
		for( j=0; j<width;)
		{
			int trans_count = 0;
			int image_count = 0;
			
			while( *(pSourceTemp+j) == s_Colorkey )
			{
				if( j >= width  || trans_count == 255)
					break;
				trans_count++;
				j++;				
			}
			count++;
			data[index++] = trans_count;
			
			while( *(pSourceTemp + j) != s_Colorkey )
			{
				if( j>= width || image_count == 255 )
					break;
				image_count ++;
				j++;
				
			}
			data[index++] = image_count;
			if( image_count > 0)
			{
				memcpy(data+index, pSourceTemp+(j-image_count), image_count);
				index+=image_count;
			}			
		}
		
//		// �� ���� ������ ���� ������ΰ�?
//		if (bCheckTrans)
//		{
//			// ������̸� ���ٸ� ó���� �����൵ �ɰ� ����.
//		}	
//		// ������� �ƴ� ���, ���� ������ ���������� �Ѵ�.
//		else
//		{			
//			count++;
//			data[lastColorIndex] = color;
//		}
		
		// memory�� �ٽ� ��´�.
		Pixels[i] = new BYTE [index+1];
		m_Size += index+1;

		// m_pPixels[i]�� ���������Ƿ� data�� ��ü�Ѵ�.
		// m_pPixels[i][0]���� count�� �־�� �Ѵ�.
		Pixels[i][0] = count;
		memcpy(Pixels[i]+1, data, index);
		PixelSize.push_back(index+1);

		pSource = pSource + pitch;
	}

	m_pData = new BYTE[m_Size+sizeof(BYTE *)*height];
	m_pPixels = (BYTE **)(m_pData+m_Size);
	BYTE *TempData = m_pData;

	for(i = 0; i < height; i++)
	{
		memcpy(TempData, Pixels[i], PixelSize[i]);
		m_pPixels[i] = TempData;
		TempData += PixelSize[i];
		delete [] Pixels[i];
	}

	delete [] data;
	delete [] Pixels;

	m_bInit = true;
}

void CSpritePal::Blt(int x, int y, WORD* pDest, int pitch, MPalette &pal)
{
	int	count,			
		colorCount;
	
	WORD	*pDestTemp;
	BYTE	*pPixels;
	
	register int i;
	register int j;
	register int k;
	int rectBottom = m_Height;
	
	pDest = (WORD*)((BYTE*)pDest + y*pitch +x*2);
	
	if (rectBottom > 0)
	{
		i = 0;
		
		do
		{
			pPixels		= m_pPixels[i];
			pDestTemp = (WORD*)((BYTE*)pDest + i*pitch);
			
			// (�����,�����,�����)�� �ݺ� ��		
			count	= *pPixels++;		
			// �� �� ���
			if (count > 0)
			{	
				j = count;
				do {
					pDestTemp += *pPixels++;			// �������ŭ �ǳ� �ڴ�.
					colorCount = *pPixels++;		// ���� �ƴ� �� ��				
					
					// ������ �ƴ� ������ Surface�� ����Ѵ�.
					for(k = 0; k < colorCount; k++)
					{
						memcpy((void*)(pDestTemp+k), (void*)(&pal[*(pPixels+k)]), 2);
					}
					
					pDestTemp	+= colorCount;
					pPixels		+= colorCount;
				} while (--j);
			}
			
		} while (i++ < rectBottom-1);
	}
}

//----------------------------------------------------------------------
// BltEffect
//----------------------------------------------------------------------
// Clipping���� �ʴ´�.
//----------------------------------------------------------------------
void
CSpritePal::BltEffect(WORD *pDest, WORD pitch, MPalette &pal)
{
	int		count,			
			colorCount;

	WORD	*pDestTemp;
	BYTE	*pPixels;

	register int i;
	register int j;

	int rectBottom = m_Height;
	if (rectBottom > 0)
	{
		i = rectBottom-1;
		pDest = (WORD*)((BYTE*)pDest + i*pitch);

		do
		{
			pPixels		= m_pPixels[i];
			pDestTemp	= pDest;

			// (�����,�����,�����)�� �ݺ� ��		
			count	= *pPixels++;		

			// �� �� ���
			if (count > 0)
			{
				j = count;
				do 
				{
					pDestTemp += *pPixels++;			// �������ŭ �ǳ� �ڴ�.
					colorCount = *pPixels++;		// ���� �ƴ� �� ��				

					// ������ �ƴ� ������ Surface�� ����Ѵ�.
					CSpriteSurface::memcpyPalEffect(pDestTemp, pPixels, colorCount, pal);
					
					pDestTemp	+= colorCount;
					pPixels		+= colorCount;
				} while (--j);
			}

			pDest = (WORD*)((BYTE*)pDest - pitch);
		} while (i--);
	}
}

//----------------------------------------------------------------------
// BltEffect ClipLeft
//----------------------------------------------------------------------
// ���� clipping.  
// pRect->left���� ���� �ǳʶ� �������� pDest�� ����Ѵ�.
//----------------------------------------------------------------------
void
CSpritePal::BltEffectClipLeft(WORD* pDest, WORD pitch, RECT* pRect, MPalette &pal)
{
	WORD	*pDestTemp;
	BYTE	*pPixels;

	//--------------------------------------------
	// pRect��ŭ�� ���� ����Ѵ�.
	//--------------------------------------------
	int		count,
			transCount, 
			colorCount,
			index,
			dist;

	register int i;
	register int j;

	//---------------------------------------------
	// ����ؾ��ϴ� ��� �ٿ� ���ؼ�..
	//---------------------------------------------
	int rectBottom = pRect->bottom;
	int rectLeft = pRect->left;
	for (i=pRect->top; i<rectBottom; i++)
	{
		pPixels = m_pPixels[i];
		pDestTemp = pDest;		

		// (�����,�����,�����)�� �ݺ� ��
		count = *pPixels++;		

		// �� �� ���		
		index = 0;
		
		//---------------------------------------------
		// �� �ٸ��� Clipping�� ����� �ϴµ�...
		// xxxxOOOOOOOOOOOOOO�� ����̹Ƿ�..
		//---------------------------------------------
		// xxxx�κб��� check���ִ� ��ƾ
		//---------------------------------------------
		if (count > 0)
		{
			j = count;
			do 
			{
				transCount = *pPixels++;		// ����� ��			
				colorCount = *pPixels++;		// ���� �ƴ� �� ��			
						
				// �������ŭ index����			
				index += transCount;
				
			
				//---------------------------------------------
				// xxxx������ �Ѿ�� �Ǵ� ���
				//---------------------------------------------
				if (index+colorCount > rectLeft)
				{
					//---------------------------------------------
					// ����������� xxxx������ �Ѿ�� ���
					//---------------------------------------------
					if (index > rectLeft)
					{	
						// ������κ� �ǳʶ�
						pDestTemp += index - rectLeft;

						// �̹� �ܰ�� ��� ���
						CSpriteSurface::memcpyPalEffect(pDestTemp, pPixels, colorCount, pal);
						pDestTemp += colorCount;
						pPixels += colorCount;

						// �������ʹ� ��� ����Ѵ�.
						break;
					}
					//---------------------------------------------
					// �����+����ƴѻ��� �Ϻα��� ����ϸ� 
					// xxxx������ �Ѿ�� �Ǵ� ���
					//---------------------------------------------
					else
					{
						dist = rectLeft - index;

						// ������ �ƴ� ������ Surface�� ����Ѵ�.
						CSpriteSurface::memcpyPalEffect(pDestTemp, pPixels+dist, colorCount-dist, pal);					
						pDestTemp += colorCount-dist;
						pPixels += colorCount;

						// �������ʹ� ��� ����Ѵ�.
						break;
					}
				}					

				// ������ �ƴ� ����ŭ index����				
				pPixels += colorCount;
				index += colorCount;
			} while (--j);

			//---------------------------------------------
			// �������ʹ� ��� ����Ѵ�.		
			//---------------------------------------------		
			if (--j > 0)
			{
				do 
				{
					transCount = *pPixels++;		// ����� ��			
					colorCount = *pPixels++;		// ���� �ƴ� �� ��			
							
					// �������ŭ �ǳ� �ڴ�.
					pDestTemp += transCount;			
					
					// ������� �ƴѸ�ŭ ������ش�.
					CSpriteSurface::memcpyPalEffect(pDestTemp, pPixels, colorCount, pal);

					// memory addr ����
					pDestTemp += colorCount;
					pPixels += colorCount;			
				} while (--j);
			}
		}
		

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// BltEffect ClipRight
//----------------------------------------------------------------------
// ������ clipping.  
// pRect->right�� ������ ���� pDest�� ����Ѵ�.
//----------------------------------------------------------------------
void
CSpritePal::BltEffectClipRight(WORD* pDest, WORD pitch, RECT* pRect, MPalette &pal)
{
	BYTE	*pPixels;
	WORD	*pDestTemp;

	//--------------------------------------------
	// pRect��ŭ�� ���� ����Ѵ�.
	//--------------------------------------------
	int		count,
			transCount, 
			colorCount,
			index;

	register int	i;
	register int	j;

	int rectBottom = pRect->bottom;
	int rectRight = pRect->right;
	for (i=pRect->top; i<rectBottom; i++)
	{
		pPixels = m_pPixels[i];
		pDestTemp = pDest;		

		// (�����,�����,�����)�� �ݺ� ��
		count = *pPixels++;		

		// �� �� ���		
		index = 0;
			
		//---------------------------------------------
		// �� �ٸ��� Clipping�� ����� �ϴµ�...		
		// OOOOOOOOOOOOOOxxxxx �̷� ����̴�.
		//---------------------------------------------
		// OOOOOOOOOOOOOO������ ������ָ� �ȴ�.
		//---------------------------------------------
		if (count > 0)
		{
			j = count;
			do 
			{
				transCount = *pPixels++;		// ����� ��			
				colorCount = *pPixels++;		// ���� �ƴ� �� ��			
						
				// �������ŭ index����
				index += transCount;
				
				// ����ϰ� �ִٰ� �����ʺκк��� ������� ���ƾ� �� ��찡 �ִ�.
				// ���� ����ϴ� ���� ��� ����� ���̹Ƿ� break�ؾ� �Ѵ�.

				// ��������� ����ϴ°͸����� �� �̻� ����� �ʿ䰡 ���� ���

				//---------------------------------------------
				// ������ ������ �������� ���
				//---------------------------------------------			
				if (index+colorCount > rectRight)
				{
					// ����������� �� ����� �ʿ䰡 ���� ��
					if (index > rectRight)
					{
						break;
					}
					// ����� �ƴ� ���� ���� ����ؾ� �� ���
					else
					{
						pDestTemp += transCount;
					
						// ������ �ƴ� ������ Surface�� ����Ѵ�.
						CSpriteSurface::memcpyPalEffect(pDestTemp, pPixels, rectRight - index, pal);
						break;
					}
				}

				// �������ŭ �ǳʶ��
				pDestTemp += transCount;

				// ���
				CSpriteSurface::memcpyPalEffect(pDestTemp, pPixels, colorCount, pal);
				pDestTemp += colorCount;
				pPixels += colorCount;			
				index += colorCount;
			} while (--j);
		}
		
		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// BltEffect ClipWidth
//----------------------------------------------------------------------
// ���� clipping.  
// pRect->left���� ���� �ǳʶ� �������� pDest�� ����Ѵ�.
// rectRight����..
//----------------------------------------------------------------------
void
CSpritePal::BltEffectClipWidth(WORD* pDest, WORD pitch, RECT* pRect, MPalette &pal)
{
	BYTE	*pPixels;
	WORD	*pDestTemp;

	//--------------------------------------------
	// pRect��ŭ�� ���� ����Ѵ�.
	//--------------------------------------------
	int		count,
			transCount, 
			colorCount,
			index,
			dist;

	register int i;
	register int j;

	//---------------------------------------------
	// ����ؾ��ϴ� ��� �ٿ� ���ؼ�..
	//---------------------------------------------
	int rectBottom = pRect->bottom;
	int rectLeft = pRect->left;
	int rectRight = pRect->right;
	for (i=pRect->top; i<rectBottom; i++)
	{
		pPixels = m_pPixels[i];
		pDestTemp = pDest;		

		// (�����,�����,�����)�� �ݺ� ��
		count = *pPixels++;		

		// �� �� ���		
		index = 0;
		
		//---------------------------------------------
		// �� �ٸ��� Clipping�� ����� �ϴµ�...
		// xxxxOOOOOOOOOOOOOO�� ����̹Ƿ�..
		//---------------------------------------------
		// xxxx�κб��� check���ִ� ��ƾ
		//---------------------------------------------
		if (count > 0)
		{
			j = count;
			do 
			{
				transCount = *pPixels++;		// ����� ��			
				colorCount = *pPixels++;		// ���� �ƴ� �� ��			
						
				// �������ŭ index����			
				index += transCount;
				
			
				//---------------------------------------------
				// xxxx������ �Ѿ�� �Ǵ� ���
				//---------------------------------------------
				if (index+colorCount > rectLeft)
				{
					//---------------------------------------------
					// ����������� xxxx������ �Ѿ�� ���
					//---------------------------------------------
					if (index > rectLeft)
					{	
						// ������κ� �ǳʶ�
						pDestTemp += index - rectLeft;

						// �̹� �ܰ�� ��� ���?
						// ������ ���� �Ѿ�� ���..
						if (index+colorCount > rectRight)
						{							
							// ����������� ������ �� �Ѿ�� ���
							if (index > rectRight)
							{
							}
							else
							{
								CSpriteSurface::memcpyPalEffect(pDestTemp, pPixels, rectRight - index, pal);
							}

							j = 0;
							
							break;
						}

						// �̹� �ܰ�� ��� ���
						CSpriteSurface::memcpyPalEffect(pDestTemp, pPixels, colorCount, pal);
						pDestTemp += colorCount;
						pPixels += colorCount;
						index += colorCount;

						// �������ʹ� ��� ����Ѵ�.
						break;
					}
					//---------------------------------------------
					// �����+����ƴѻ��� �Ϻα��� ����ϸ� 
					// xxxx������ �Ѿ�� �Ǵ� ���
					//---------------------------------------------
					else
					{
						dist = rectLeft - index;

						// ������ ���� �Ѿ�� ���..
						if (index+colorCount > rectRight)
						{
							CSpriteSurface::memcpyPalEffect(pDestTemp, pPixels+dist, rectRight - rectLeft, pal);

							j = 0;						
							break;
						}		

						// ������ �ƴ� ������ Surface�� ����Ѵ�.
						CSpriteSurface::memcpyPalEffect(pDestTemp, pPixels+dist, colorCount-dist, pal);					
						pDestTemp += colorCount-dist;
						pPixels += colorCount;
						index += colorCount;

						// �������ʹ� ��� ����Ѵ�.
						break;
					}
				}					

				// ������ �ƴ� ����ŭ index����				
				pPixels += colorCount;
				index += colorCount;
			} while (--j);

			//---------------------------------------------
			// �� �ٸ��� Clipping�� ����� �ϴµ�...		
			// OOOOOOOOOOOOOOxxxxx �̷� ����̴�.
			//---------------------------------------------
			// OOOOOOOOOOOOOO������ ������ָ� �ȴ�.
			//---------------------------------------------
			if (--j > 0)
			{
				do 
				{
					transCount = *pPixels++;		// ����� ��			
					colorCount = *pPixels++;		// ���� �ƴ� �� ��			
							
					// �������ŭ index����
					index += transCount;
					
					// ����ϰ� �ִٰ� �����ʺκк��� ������� ���ƾ� �� ��찡 �ִ�.
					// ���� ����ϴ� ���� ��� ����� ���̹Ƿ� break�ؾ� �Ѵ�.

					// ��������� ����ϴ°͸����� �� �̻� ����� �ʿ䰡 ���� ���

					//---------------------------------------------
					// ������ ������ �������� ���
					//---------------------------------------------			
					if (index+colorCount > rectRight)
					{
						// ����������� �� ����� �ʿ䰡 ���� ��
						if (index > rectRight)
						{
							break;
						}
						// ����� �ƴ� ���� ���� ����ؾ� �� ���
						else
						{
							pDestTemp += transCount;
						
							// ������ �ƴ� ������ Surface�� ����Ѵ�.
							CSpriteSurface::memcpyPalEffect(pDestTemp, pPixels, rectRight - index, pal);
							break;
						}
					}

					// �������ŭ �ǳʶ��
					pDestTemp += transCount;

					// ���
					CSpriteSurface::memcpyPalEffect(pDestTemp, pPixels, colorCount, pal);
					pDestTemp += colorCount;
					pPixels += colorCount;			
					index += colorCount;
				} while (--j);
			}		
		}

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// BltEffect Clip Height
//----------------------------------------------------------------------
// pRect->top, pRect->bottom��ŭ�� ����Ѵ�.
//----------------------------------------------------------------------
void
CSpritePal::BltEffectClipHeight(WORD *pDest, WORD pitch, RECT* pRect, MPalette &pal)
{
	int		count,			
			colorCount;

	WORD	*pDestTemp;
	BYTE	*pPixels;


	register int i;
	register int j;

	int rectBottom = pRect->bottom;
	for (i=pRect->top; i<rectBottom; i++)
	{			
		pPixels		= m_pPixels[i];
		pDestTemp	= pDest;

		// (�����,�����,�����)�� �ݺ� ��		
		count	= *pPixels++;		

		// �� �� ���
		if (count > 0)
		{
			j = count;
			do 
			{				
				pDestTemp += *pPixels++;		// �������ŭ �ǳ� �ڴ�.
				colorCount = *pPixels++;		// ���� �ƴ� �� ��				

				// ������ �ƴ� ������ Surface�� ����Ѵ�.
				CSpriteSurface::memcpyPalEffect(pDestTemp, pPixels, colorCount, pal);
				
				pDestTemp	+= colorCount;
				pPixels		+= colorCount;
			} while (--j);
		}

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
} 

//----------------------------------------------------------------------
// Blt1555NotTrans
//----------------------------------------------------------------------
// Clipping���� �ʴ´�.
//----------------------------------------------------------------------
void
CSpritePal::Blt1555NotTrans(WORD *pDest, WORD pitch, MPalette &pal)
{
	//s_Value1 = alpha >> 4;	// 1 bit�̹Ƿ�
	
	int		count,	
		transCount,
		colorCount;
	
	WORD	*pDestTemp;
	BYTE	*pPixels;
	
	register int i;
	register int j;
	
	int rectBottom = m_Height;
	
	if (rectBottom > 0)
	{
		i = rectBottom-1;
		pDest = (WORD*)((BYTE*)pDest + i*pitch);
		
		do
		{
			pPixels		= m_pPixels[i];
			pDestTemp	= pDest;
			
			// (�����,�����,�����)�� �ݺ� ��		
			count	= *pPixels++;		
			
			// �� �� ���
			if (count > 0)
			{			
				j = count;
				do
				{		
					transCount = *pPixels++;					
					colorCount = *pPixels++;		// ���� �ƴ� �� ��				
					
					// 0�� ����Ѵ�.
					memset(pDestTemp, 0, transCount<<1);
					pDestTemp += transCount;		// �������ŭ �ǳ� �ڴ�.
					
					// ������ �ƴ� ������ Surface�� ����Ѵ�.
					memcpy1555(pDestTemp, pPixels, colorCount, pal);
					
					pDestTemp	+= colorCount;
					
					pPixels		+= colorCount;
				} while (--j);
			}
			
			pDest = (WORD*)((BYTE*)pDest - pitch);
		} while (i--);
	}
}

//----------------------------------------------------------------------
// Blt1555SmallNotTrans
//----------------------------------------------------------------------
// ����ؼ� ���.. 
// Clipping���� �ʴ´�.
//
// alpha���� 50%(������)���� �Ѵ�.
//----------------------------------------------------------------------
void
CSpritePal::Blt1555SmallNotTrans(WORD *pDest, WORD pitch, BYTE shift, MPalette &pal)
{
	//s_Value1 = alpha >> 4;	// 1 bit�̹Ƿ�
	s_Value2 = shift;
	// memcpy���� �ǳʶ�� ��
	s_Value3 = 1 << shift;
	
	
	int		count,	
		transCount,
		colorCount,
		transCountShift,
		colorCountShift;
	
	WORD	*pDestTemp;
	BYTE	*pPixels;
	
	register int i;
	register int j;
	
	int rectBottom = m_Height;
	
	if (rectBottom > 0)
	{
		i = rectBottom-1;
		int stepY = 1 << shift;		// y�� �ǳʶ�� pixel��
		pDest = (WORD*)((BYTE*)pDest + (i>>shift)*pitch);
		
		do
		{
			pPixels		= m_pPixels[i];
			pDestTemp	= pDest;
			
			// (�����,�����,�����)�� �ݺ� ��		
			count	= *pPixels++;		
			
			// �� �� ���
			if (count > 0)
			{			
				j = count;
				do
				{		
					transCount = *pPixels++;					
					colorCount = *pPixels++;		// ���� �ƴ� �� ��	
					
					// shift��ŭ �ٿ��� ���� ����Ѵ�.
					transCountShift = transCount >> shift;
					colorCountShift = colorCount >> shift;
					
					// 0�� ����Ѵ�.
					memset(pDestTemp, 0, transCountShift<<1);
					pDestTemp += transCountShift;		// �������ŭ �ǳ� �ڴ�.
					
					// ������ �ƴ� ������ Surface�� ����Ѵ�.
					memcpy1555Small(pDestTemp, pPixels, colorCount, pal);
					
					pDestTemp	+= colorCountShift;
					
					pPixels		+= colorCount;
				} while (--j);
			}
			
			pDest = (WORD*)((BYTE*)pDest - pitch);
			
			i-=stepY;
			
		} while (i>0);
	}
}

//----------------------------------------------------------------------
// AlphaChannel Copy  1555
//----------------------------------------------------------------------
// Alpha�� : �ǹ̾���.
//----------------------------------------------------------------------
// pSource�� ���� pDest�� ����� �ؾ��Ѵ�.
// pSource�� ������ (alpha,���� �ϳ�)�� pixels��ŭ �ݺ��̴�.
//
// A:R:G:B = 1:5:5:5 Texture�� ���� ���̴�.
//----------------------------------------------------------------------
void	
CSpritePal::memcpy1555(WORD* pDest, BYTE* pSource, WORD pixels, MPalette &pal)
{
	register int		sTemp;
	register int		sr,sg,sb;
	//static WORD		temp, temp2;
	
	register int i = pixels;
	
	// Alpha Channel Blending
	// ������ ���
	while (i--)
	{	
		// ���� ���
		sTemp = pal[*pSource];
		
		sr = (sTemp >> CDirectDraw::s_bSHIFT_R);// & 0x0F;
		sg = (sTemp >> CDirectDraw::s_bSHIFT_G) & 0x0000001F;
		sb = (sTemp >> CDirectDraw::s_bSHIFT_B) & 0x0000001F;
		
		*pDest =	0x8000 |
			(sr << 10) |
			(sg << 5) |
			(sb);
		
		pDest++;
		pSource++;
	}
}

//----------------------------------------------------------------------
// Alpha Copy  1555 Small
//----------------------------------------------------------------------
// Alpha�� : �ǹ̾��� - -;
//----------------------------------------------------------------------
// pSource�� ���� pDest�� ����� �ؾ��Ѵ�.
// pSource�� ������ (alpha,���� �ϳ�)�� pixels��ŭ �ݺ��̴�.
//
// A:R:G:B = 1:5:5:5 Texture�� ���� ���̴�.
//
// s_Value2�� shift��
// s_Value3�� �ǳʶ�� ��(�³�? ����� ��������. - -;;)
//----------------------------------------------------------------------
void	
CSpritePal::memcpy1555Small(WORD* pDest, BYTE* pSource, WORD pixels, MPalette &pal)
{
	register int		sTemp;
	register int		sr,sg,sb;
	//static WORD		temp, temp2;
	
	register int i = pixels >> s_Value2;
	
	// ������ ���
	while (i--)
	{	
		// ���� ���
		sTemp = pal[*pSource];
		
		sr = (sTemp >> CDirectDraw::s_bSHIFT_R);// & 0x0F;
		sg = (sTemp >> CDirectDraw::s_bSHIFT_G) & 0x0000001F;
		sb = (sTemp >> CDirectDraw::s_bSHIFT_B) & 0x0000001F;
		
		*pDest =	0x8000 | //(s_Value1 << 15) |
			(sr << 10) |
			(sg << 5) |
			(sb);
		
		pDest++;
		pSource += s_Value3;
	}
}

bool
CSpritePal::IsColorPixel( short x, short y )
{
	if( x >= m_Width || x< 0 || y>= m_Height || y< 0)
		return false;

	int	count, colorCount , offset=0;
	
	const BYTE	*pPixels = m_pPixels[y];
	
	register int j;
	
	count	= *pPixels++;		
	// �� �� ���
	if (count > 0)
	{	
		j = count;
		do {
			offset += *pPixels++;			// �������ŭ �ǳ� �ڴ�.
			if( offset > x ) return false;
			colorCount = *pPixels++;	// ���� �ƴ� �� ��						
			offset += colorCount;
			if( offset > x ) return true;
			pPixels	+= colorCount;
		} while (--j);
	}	
	return false;
}

WORD
CSpritePal::GetPixel( short x, short y, MPalette &pal )
{
	if( y >= m_Height || y < 0 || x < 0 || x >= m_Width )
		return 0;
	
	const BYTE *pPixels = m_pPixels[y];
	int offset=0, colorCount,count;
	register int j;

	count = *pPixels++;

	if(count > 0 )
	{
		j = count;

		do {
			offset += *pPixels++;			// ������κ� �ǳ� ��
			if( offset > x ) return 0;			//  ����� �κ��̸� 0��..
			colorCount = *pPixels++;
			offset += colorCount;
			if( offset > x )		// �� �ȿ� ���� ������
			{
				offset -= colorCount;
				pPixels += (x - offset);
				return pal[*pPixels];
			}
			pPixels += colorCount;
		} while(--j);
	}

	return 0;
}
