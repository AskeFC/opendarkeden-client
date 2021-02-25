
#include "Client_PCH.h"
#include "CAlphaSpritePal.h"

#include "CSpriteSurface.h"


int		CAlphaSpritePal::s_Value1	= 0;
int		CAlphaSpritePal::s_Value2	= 0;

void CAlphaSpritePal::SetPixel(BYTE *pSource, WORD pitch, BYTE *pSourceAlpha, WORD alphaPitch, WORD width, WORD height)
{
	// memory����
	Release();

	m_Width = width;
	m_Height = height;

	// �ϴ� memory�� ������ ��Ƶд�.	
	BYTE*	data = new BYTE[m_Width*4+10];

	int		index;//,				// data�� index�� ���
//			lastColorIndex;		// ������ �ƴѻ� ������ �ֱ� index
	int		count;				// �ݺ���
	int		trans,				// ����� ����
			color;				// ������ �ƴѻ� ����

	BOOL	bCheckTrans;		// �ֱٿ� �˻��Ѱ� ������ΰ�?

	BYTE	*pSourceTemp;
	BYTE	*pAlphaTemp;


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
		pAlphaTemp = pSourceAlpha;
		
		for( j=0; j<width;)
		{
			int trans_count = 0;
			int image_count = 0;
			
			while( *(pSourceTemp+j) == s_Colorkey || *(pAlphaTemp+j) == 0 )
			{
				if( j >= width  || trans_count == 255)
					break;
				trans_count++;
				j++;				
			}
			count++;
			data[index++] = trans_count;
			
			while( *(pSourceTemp + j) != s_Colorkey && *(pAlphaTemp+j) != 0)
			{
				if( j>= width || image_count == 255 )
					break;
				image_count ++;
				j++;
				
			}
			data[index++] = image_count;
			
			if( image_count > 0)
			{
				for( int t = 0; t < image_count; t++ )
				{
					BYTE alpha;
					
					alpha = *( pAlphaTemp + ( j - image_count ) + t);//(BYTE)(*pAlphaTemp & 0x001F);	// Alpha��(Blue���� ���Ѵ�.)
					data[index++] = alpha;
					data[index++] = *( pSourceTemp + ( j - image_count ) + t );
				}
			}			
		}
/*
		
		// �� line�� ���ؼ� ����~
		for (j=0; j<width; j++)
		{
			// 0�� color�� ���ؼ� ����
			if (*pSourceTemp==s_Colorkey || *pAlphaTemp==0)
			{
				// �ֱٿ� �˻��Ѱ� ������� �ƴϾ��ٸ�
				if (!bCheckTrans)
				{
					// ' (����,�����,�����) '�� �� set�� �������� �ǹ��ϹǷ�
					// ������� (alpha,�����)�� ������ �ǹ��Ѵ�.
					count++;
					
					// color���� ����
					data[lastColorIndex] = color;
					color = 0;

					bCheckTrans = TRUE;
				}
				
				trans++;				
			}
			else
			{
				// �ֱٿ� �˻��Ѱ� ������̾��ٸ�..
				if (bCheckTrans)
				{						
					data[index++] = trans;		// ���� byte�� ������� �ִ´�.
					trans = 0;

					lastColorIndex=index++;			// ������� ���� ��ġ�� ���					

					bCheckTrans = FALSE;
				}
				// alpha�� �����
				BYTE alpha;
				alpha = *pAlphaTemp;//(BYTE)(*pAlphaTemp & 0x001F);	// Alpha��(Blue���� ���Ѵ�.)

				data[index++] = alpha;					// Alpha ���� �����Ѵ�.				
				data[index++] = *pSourceTemp;	// ���� ������ �����Ѵ�.

				color++;								
			}

			pSourceTemp++;
			pAlphaTemp++;
		}
		*/
		
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

		pSource += pitch;
		pSourceAlpha += alphaPitch;
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

void CAlphaSpritePal::Blt(int x, int y, WORD* pDest, int pitch, MPalette &pal)
{
	int	count,			
		colorCount;
	
	WORD	*pDestTemp;
	BYTE	*pPixels;
	
	register int i;
	register int j;
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
					memcpyAlpha(pDestTemp, pPixels, colorCount, pal);
					
					pDestTemp	+= colorCount;
					// ���� �� ������ alpha�� ������ 2���̴�.
					pPixels		+= (colorCount<<1);
				} while (--j);
			}
			
		} while (i++ < rectBottom-1);
	}
}

//----------------------------------------------------------------------
// AlphaChannel Copy
//----------------------------------------------------------------------
// Alpha�� : 1~32
//----------------------------------------------------------------------
// pSource�� ���� pDest�� ����� �ؾ��Ѵ�.
// pSource�� ������ (alpha,���� �ϳ�)�� pixels��ŭ �ݺ��̴�.
//----------------------------------------------------------------------
void	
CAlphaSpritePal::memcpyAlpha(WORD* pDest, BYTE* pSource, WORD pixels, MPalette &pal)
{
	register WORD		sTemp,dTemp;
	register int		sr,sg,sb,dr,dg,db;

	register int i = pixels;
	
	BYTE alpha;
	
	// Alpha Channel Blending
	// ������ ���
	while (i--)
	{	
		// Source���� Alpha���� ���ԵǾ� �ִ�.
		alpha = *pSource;

		pSource++;
		
		// ���� ���
		sTemp = pal[*pSource];
		dTemp = *pDest;
		
		sr = CDirectDraw::Red(sTemp);
		sg = CDirectDraw::Green(sTemp);
		sb = CDirectDraw::Blue(sTemp);
		
		dr = CDirectDraw::Red(dTemp);
		dg = CDirectDraw::Green(dTemp);
		db = CDirectDraw::Blue(dTemp);		

		*pDest = ((((sb - db)*alpha >> 5) + db) |
		((((sg - dg)*alpha >> 5) + dg) << CDirectDraw::s_bSHIFT_G) |
		(((sr - dr)*alpha >> 5) + dr) << CDirectDraw::s_bSHIFT_R);
		
		pDest++;
		pSource++;
	}
	
}


//----------------------------------------------------------------------
// AlphaChannel Copy  4444
//----------------------------------------------------------------------
// Alpha�� : 1~32
//----------------------------------------------------------------------
// pSource�� ���� pDest�� ����� �ؾ��Ѵ�.
// pSource�� ������ (alpha,���� �ϳ�)�� pixels��ŭ �ݺ��̴�.
//
// A:R:G:B = 4:4:4:4 Texture�� ���� ���̴�.
//----------------------------------------------------------------------
void	
CAlphaSpritePal::memcpyAlpha4444(WORD* pDest, BYTE* pSource, WORD pixels, MPalette &pal)
{
	register WORD		sTemp;
	register int		sr,sg,sb;
	//static WORD		temp, temp2;

	register int i = pixels;

	BYTE alpha;

	// Alpha Channel Blending
	// ������ ���
	while (i--)
	{	
		// Source���� Alpha���� ���ԵǾ� �ִ�.
		alpha = *pSource >> 1;	//	alpha = (*pSource >> 8) >> 1;
		pSource++;

		// ���� ���
		sTemp = pal[*pSource];
	
		sr = (sTemp >> CDirectDraw::s_bSHIFT4_R);// & 0x0F;
		sg = (sTemp >> CDirectDraw::s_bSHIFT4_G) & 0x0F;
		sb = (sTemp >> CDirectDraw::s_bSHIFT4_B) & 0x0F;
		
		*pDest =	(alpha << 12) |
					(sr << 8) |
					(sg << 4) |
					(sb);
	
		pDest++;
		pSource++;
	}
}

//----------------------------------------------------------------------
// BltClip
//----------------------------------------------------------------------
// pRect�� ������ ����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::BltClip(WORD* pDest, WORD pitch, RECT* pRect, MPalette &pal)
{
	BYTE	*pPixels;
	WORD	*pDestTemp;

	//--------------------------------------------	
	// ù �� (x,y)
	//--------------------------------------------
	pDest = (WORD*)((BYTE*)pDest + pitch*pRect->top + pRect->left);
	//WORD width = ((pRect->right - pRect->left)<<1);

	//--------------------------------------------
	// pRect��ŭ�� ���� ����Ѵ�.
	//--------------------------------------------
	int	count,
			transCount, 
			colorCount,
			index,
			dist;

	BOOL	bPut;		

	register int i;
	register int j;
	int rectBottom = pRect->bottom;	

	for (i=pRect->top; i<rectBottom; i++)
	{
		pPixels = m_pPixels[i];
		pDestTemp = pDest;		

		// (�����,�����,�����)�� �ݺ� ��
		count = *pPixels++;		

		// �� �� ���
		bPut = (pRect->left==0)? TRUE:FALSE;
		index = 0;
			
		// �� �ٸ��� Clipping�� ����� �ϴµ�...
		// xxxxxOOOOOOOOOOOOOO �̰ų�  (x:��¾���, O:�����)
		// OOOOOOOOOOOOOOxxxxx �̰�.. �� ���� ����.			
		if (count > 0)
		{
			j = count;
			do 
			{				
				transCount = *pPixels++;		// ����� ��			
				colorCount = *pPixels++;		// ���� �ƴ� �� ��			
						
				// �������ŭ �ǳ� �ڴ�.
				//lpSurfaceTemp += transCount;
				index += transCount;

				// ����ص� �Ǵ� ��쿡�� ����Ѵ�.
				if (bPut)
				{
					// ����ϰ� �ִٰ� �����ʺκк��� ������� ���ƾ� �� ��찡 �ִ�.
					// ���� ����ϴ� ���� ��� ����� ���̹Ƿ� break�ؾ� �Ѵ�.

					// ��������� ����ϴ°͸����� �� �̻� ����� �ʿ䰡 ���� ���
					if (index > pRect->right)
						break;

					pDestTemp += transCount;

					// ����� �ƴ� ���� ���� ����ؾ� �� ���
					if (index+colorCount > pRect->right)
					{							
						// ������ �ƴ� ������ Surface�� ����Ѵ�.
						memcpyAlpha(pDestTemp, pPixels, pRect->right - index, pal);
						break;
					}						

					// ��� ���
					memcpyAlpha(pDestTemp, pPixels, colorCount, pal);
					pDestTemp += colorCount;
				}				
				// ����ϸ� �� �� ���(���� ���ʺκ�)���� ����ص� �Ǵ��� Ȯ���غ���.
				else
				{
					// ����������� ������ �Ѿ���Ƿ� ��� ���
					if (index > pRect->left)
					{	
						pDestTemp += index - pRect->left;
						memcpyAlpha(pDestTemp, pPixels, colorCount, pal);
						pDestTemp += colorCount;
						bPut = TRUE;
					}
					else
					if (index+colorCount > pRect->left)
					{
						dist = pRect->left - index;

						// ������ �ƴ� ������ Surface�� ����Ѵ�.
						memcpyAlpha(pDestTemp, pPixels+dist, colorCount-dist, pal);
						pDestTemp += colorCount-dist;

						// �������ʹ� ��� ����Ѵ�.
						bPut = TRUE;
					}
				}				

				// ������ �ƴ� ����ŭ index����				
				pPixels += (colorCount<<1);		

				index += colorCount;
			} while (--j);
		}

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// Blt
//----------------------------------------------------------------------
// Clipping���� �ʴ´�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::Blt(WORD *pDest, WORD pitch, MPalette &pal)
{
	int	count,			
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
					pDestTemp += *pPixels++;		// �������ŭ �ǳ� �ڴ�.
					colorCount = *pPixels++;		// ���� �ƴ� �� ��				

					// ������ �ƴ� ������ Surface�� ����Ѵ�.
					memcpyAlpha(pDestTemp, pPixels, colorCount, pal);
					
					pDestTemp	+= colorCount;

					// ���� �� ������ alpha�� ������ 2���̴�.
					pPixels		+= (colorCount<<1);
				} while (--j);
			}

			pDest = (WORD*)((BYTE*)pDest - pitch);
		} while (i--);
	}
}

//----------------------------------------------------------------------
// Blt ClipLeft
//----------------------------------------------------------------------
// ���� clipping.  
// rectLeft���� ���� �ǳʶ� �������� pDest�� ����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::BltClipLeft(WORD* pDest, WORD pitch, RECT* pRect, MPalette &pal)
{
	BYTE	*pPixels;
	WORD	*pDestTemp;

	//--------------------------------------------
	// pRect��ŭ�� ���� ����Ѵ�.
	//--------------------------------------------
	int	count,
			transCount, 
			colorCount,
			index,
			dist;

	register int i;
	register int j;

	int rectBottom = pRect->bottom;
	int rectLeft = pRect->left;

	//---------------------------------------------
	// ����ؾ��ϴ� ��� �ٿ� ���ؼ�..
	//---------------------------------------------
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
		// �� �� ���
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
						memcpyAlpha(pDestTemp, pPixels, colorCount, pal);
						pDestTemp += colorCount;
						pPixels += (colorCount<<1);

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
						memcpyAlpha(pDestTemp, pPixels+(dist<<1), colorCount-dist, pal);
						pDestTemp += colorCount-dist;
						pPixels += (colorCount<<1);

						// �������ʹ� ��� ����Ѵ�.
						break;
					}
				}					

				// ������ �ƴ� ����ŭ index����				
				pPixels += (colorCount<<1);
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
					memcpyAlpha(pDestTemp, pPixels, colorCount, pal);

					// memory addr ����
					pDestTemp += colorCount;
					pPixels += (colorCount<<1);
				} while (--j);
			}
		}
		

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// Blt ClipRight
//----------------------------------------------------------------------
// ������ clipping.  
// rectRight�� ������ ���� pDest�� ����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::BltClipRight(WORD* pDest, WORD pitch, RECT* pRect, MPalette &pal)
{
	BYTE	*pPixels;
	WORD	*pDestTemp;

	//--------------------------------------------
	// pRect��ŭ�� ���� ����Ѵ�.
	//--------------------------------------------
	int	count,
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
		// �� �� ���
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
						memcpyAlpha(pDestTemp, pPixels, rectRight - index, pal);
						break;
					}
				}

				// �������ŭ �ǳʶ��
				pDestTemp += transCount;

				// ���
				memcpyAlpha(pDestTemp, pPixels, colorCount, pal);
				pDestTemp += colorCount;
				pPixels += (colorCount<<1);
				index += colorCount;
			} while (--j);
		}
		
		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// Blt ClipWidth
//----------------------------------------------------------------------
// ���� clipping.  
// rectLeft���� ���� �ǳʶ� �������� pDest�� ����Ѵ�.
// rectRight����..
//----------------------------------------------------------------------
void
CAlphaSpritePal::BltClipWidth(WORD* pDest, WORD pitch, RECT* pRect, MPalette &pal)
{
	BYTE	*pPixels;
	WORD	*pDestTemp;

	//--------------------------------------------
	// pRect��ŭ�� ���� ����Ѵ�.
	//--------------------------------------------
	int	count,
			transCount, 
			colorCount,
			index,
			dist;

	register int i;
	register int j;

	int rectBottom = pRect->bottom;
	int rectLeft = pRect->left;
	int rectRight = pRect->right;

	//---------------------------------------------
	// ����ؾ��ϴ� ��� �ٿ� ���ؼ�..
	//---------------------------------------------
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
		// �� �� ���
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
						// ������ ���� �Ѿ�� ���..
						if (index+colorCount > rectRight)
						{							
							// ����������� ������ �� �Ѿ�� ���
							if (index > rectRight)
							{
							}
							else
							{
								//memset((void*)pDestTemp, 0, (rectRight - index)<<1);
								memcpyAlpha(pDestTemp, pPixels, (rectRight - index), pal);
							}

							j = 0;
							
							break;
						}
						memcpyAlpha(pDestTemp, pPixels, colorCount, pal);
						pDestTemp += colorCount;
						pPixels += (colorCount<<1);
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

						// ������ �ƴ� ������ Surface�� ����Ѵ�.
						// ������ ���� �Ѿ�� ���..
						if (index+colorCount > rectRight)
						{
							memcpyAlpha(pDestTemp, pPixels+(dist<<1), (rectRight - rectLeft), pal);

							j = 0;						
							break;
						}		
						memcpyAlpha(pDestTemp, pPixels+(dist<<1), colorCount-dist, pal);
						pDestTemp += colorCount-dist;
						pPixels += (colorCount<<1);
						index += colorCount;

						// �������ʹ� ��� ����Ѵ�.
						break;
					}
				}					

				// ������ �ƴ� ����ŭ index����				
				pPixels += (colorCount<<1);
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
							memcpyAlpha(pDestTemp, pPixels, rectRight - index, pal);
							break;
						}
					}

					// �������ŭ �ǳʶ��
					pDestTemp += transCount;

					// ���
					memcpyAlpha(pDestTemp, pPixels, colorCount, pal);
					pDestTemp += colorCount;
					pPixels += (colorCount<<1);
					index += colorCount;
				} while (--j);
			}
		}		

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// Blt Clip Height
//----------------------------------------------------------------------
// pRect->top, rectBottom��ŭ�� ����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::BltClipHeight(WORD *pDest, WORD pitch, RECT* pRect, MPalette &pal)
{
	int	count,			
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
		// �� �� ���
		if (count > 0)
		{			
			j = count;
			do
			{
				pDestTemp += *pPixels++;		// �������ŭ �ǳ� �ڴ�.
				colorCount = *pPixels++;		// ���� �ƴ� �� ��				

				// ������ �ƴ� ������ Surface�� ����Ѵ�.
				memcpyAlpha(pDestTemp, pPixels, colorCount, pal);
				
				pDestTemp	+= colorCount;
				pPixels		+= (colorCount<<1);
			} while (--j);
		}

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// Blt4444
//----------------------------------------------------------------------
// Clipping���� �ʴ´�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::Blt4444(WORD *pDest, WORD pitch, MPalette &pal)
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
			// �� �� ���
			if (count > 0)
			{			
				j = count;
				do
				{				
					pDestTemp += *pPixels++;		// �������ŭ �ǳ� �ڴ�.
					colorCount = *pPixels++;		// ���� �ƴ� �� ��				

					// ������ �ƴ� ������ Surface�� ����Ѵ�.
					memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);
					
					pDestTemp	+= colorCount;

					// ���� �� ������ alpha�� ������ 2���̴�.
					pPixels		+= (colorCount<<1);
				} while (--j);
			}

			pDest = (WORD*)((BYTE*)pDest - pitch);
		} while (i--);
	}
}

//----------------------------------------------------------------------
// Blt4444 ClipLeft
//----------------------------------------------------------------------
// ���� clipping.  
// rectLeft���� ���� �ǳʶ� �������� pDest�� ����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::Blt4444ClipLeft(WORD* pDest, WORD pitch, RECT* pRect, MPalette &pal)
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

	int rectBottom = pRect->bottom;
	int rectLeft = pRect->left;

	//---------------------------------------------
	// ����ؾ��ϴ� ��� �ٿ� ���ؼ�..
	//---------------------------------------------
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
		// �� �� ���
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
						memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);
						pDestTemp += colorCount;
						pPixels += (colorCount<<1);

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
						memcpyAlpha4444(pDestTemp, pPixels+(dist<<1), colorCount-dist, pal);
						pDestTemp += colorCount-dist;
						pPixels += (colorCount<<1);

						// �������ʹ� ��� ����Ѵ�.
						break;
					}
				}					

				// ������ �ƴ� ����ŭ index����				
				pPixels += (colorCount<<1);
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
					memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);

					// memory addr ����
					pDestTemp += colorCount;
					pPixels += (colorCount<<1);
				} while (--j);
			}
		}
		

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// Blt4444 ClipRight
//----------------------------------------------------------------------
// ������ clipping.  
// rectRight�� ������ ���� pDest�� ����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::Blt4444ClipRight(WORD* pDest, WORD pitch, RECT* pRect, MPalette &pal)
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
		// �� �� ���
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
						memcpyAlpha4444(pDestTemp, pPixels, rectRight - index, pal);
						break;
					}
				}

				// �������ŭ �ǳʶ��
				pDestTemp += transCount;

				// ���
				memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);
				pDestTemp += colorCount;
				pPixels += (colorCount<<1);
				index += colorCount;
			} while (--j);
		}
		
		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// Blt4444 ClipWidth
//----------------------------------------------------------------------
// ���� clipping.  
// rectLeft���� ���� �ǳʶ� �������� pDest�� ����Ѵ�.
// rectRight����..
//----------------------------------------------------------------------
void
CAlphaSpritePal::Blt4444ClipWidth(WORD* pDest, WORD pitch, RECT* pRect, MPalette &pal)
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

	int rectBottom = pRect->bottom;
	int rectLeft = pRect->left;
	int rectRight = pRect->right;

	//---------------------------------------------
	// ����ؾ��ϴ� ��� �ٿ� ���ؼ�..
	//---------------------------------------------
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
		// �� �� ���
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
						memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);
						pDestTemp += colorCount;
						pPixels += (colorCount<<1);
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

						// ������ �ƴ� ������ Surface�� ����Ѵ�.
						memcpyAlpha4444(pDestTemp, pPixels+(dist<<1), colorCount-dist, pal);
						pDestTemp += colorCount-dist;
						pPixels += (colorCount<<1);
						index += colorCount;

						// �������ʹ� ��� ����Ѵ�.
						break;
					}
				}					

				// ������ �ƴ� ����ŭ index����				
				pPixels += (colorCount<<1);
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
							memcpyAlpha4444(pDestTemp, pPixels, rectRight - index, pal);
							break;
						}
					}

					// �������ŭ �ǳʶ��
					pDestTemp += transCount;

					// ���
					memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);
					pDestTemp += colorCount;
					pPixels += (colorCount<<1);
					index += colorCount;
				} while (--j);
			}
		}		

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// Blt4444 Clip Height
//----------------------------------------------------------------------
// pRect->top, rectBottom��ŭ�� ����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::Blt4444ClipHeight(WORD *pDest, WORD pitch, RECT* pRect, MPalette &pal)
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
		// �� �� ���
		if (count > 0)
		{			
			j = count;
			do
			{	
				pDestTemp += *pPixels++;		// �������ŭ �ǳ� �ڴ�.
				colorCount = *pPixels++;		// ���� �ƴ� �� ��				

				// ������ �ƴ� ������ Surface�� ����Ѵ�.
				memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);
				
				pDestTemp	+= colorCount;
				pPixels		+= (colorCount<<1);
			} while (--j);
		}

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}


//----------------------------------------------------------------------
// Blt4444NotTrans
//----------------------------------------------------------------------
// Clipping���� �ʴ´�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::Blt4444NotTrans(WORD *pDest, WORD pitch, MPalette &pal)
{
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
					memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);
					
					pDestTemp	+= colorCount;

					// ���� �� ������ alpha�� ������ 2���̴�.
					pPixels		+= (colorCount<<1);
				} while (--j);
			}

			pDest = (WORD*)((BYTE*)pDest - pitch);
		} while (i--);
	}
}

//----------------------------------------------------------------------
// Blt4444NotTrans ClipLeft
//----------------------------------------------------------------------
// ���� clipping.  
// rectLeft���� ���� �ǳʶ� �������� pDest�� ����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::Blt4444NotTransClipLeft(WORD* pDest, WORD pitch, RECT* pRect, MPalette &pal)
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

	int rectBottom = pRect->bottom;
	int rectLeft = pRect->left;

	//---------------------------------------------
	// ����ؾ��ϴ� ��� �ٿ� ���ؼ�..
	//---------------------------------------------
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
		// �� �� ���
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
						// 0�� ����Ѵ�.
						transCount = index - rectLeft;
						memset(pDestTemp, 0, transCount<<1);
						pDestTemp += transCount;		// �������ŭ �ǳ� �ڴ�.
						
						// �̹� �ܰ�� ��� ���
						memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);
						pDestTemp += colorCount;
						pPixels += (colorCount<<1);

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
						memcpyAlpha4444(pDestTemp, pPixels+(dist<<1), colorCount-dist, pal);
						pDestTemp += colorCount-dist;
						pPixels += (colorCount<<1);

						// �������ʹ� ��� ����Ѵ�.
						break;
					}
				}					

				// ������ �ƴ� ����ŭ index����				
				pPixels += (colorCount<<1);
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
							
					// 0�� ����Ѵ�.
					memset(pDestTemp, 0, transCount<<1);
					pDestTemp += transCount;		// �������ŭ �ǳ� �ڴ�.
					
					// ������� �ƴѸ�ŭ ������ش�.
					memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);

					// memory addr ����
					pDestTemp += colorCount;
					pPixels += (colorCount<<1);
				} while (--j);
			}
		}
		

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// Blt4444NotTrans ClipRight
//----------------------------------------------------------------------
// ������ clipping.  
// rectRight�� ������ ���� pDest�� ����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::Blt4444NotTransClipRight(WORD* pDest, WORD pitch, RECT* pRect, MPalette &pal)
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
		// �� �� ���
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
						// 0�� ����Ѵ�.
						memset(pDestTemp, 0, transCount<<1);
						pDestTemp += transCount;		// �������ŭ �ǳ� �ڴ�.
					
						// ������ �ƴ� ������ Surface�� ����Ѵ�.
						memcpyAlpha4444(pDestTemp, pPixels, rectRight - index, pal);
						break;
					}
				}

				// 0�� ����Ѵ�.
				memset(pDestTemp, 0, transCount<<1);
				pDestTemp += transCount;		// �������ŭ �ǳ� �ڴ�.

				// ���
				memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);
				pDestTemp += colorCount;
				pPixels += (colorCount<<1);
				index += colorCount;
			} while (--j);
		}
		
		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// Blt4444NotTrans ClipWidth
//----------------------------------------------------------------------
// ���� clipping.  
// rectLeft���� ���� �ǳʶ� �������� pDest�� ����Ѵ�.
// rectRight����..
//----------------------------------------------------------------------
void
CAlphaSpritePal::Blt4444NotTransClipWidth(WORD* pDest, WORD pitch, RECT* pRect, MPalette &pal)
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

	int rectBottom = pRect->bottom;
	int rectLeft = pRect->left;
	int rectRight = pRect->right;

	//---------------------------------------------
	// ����ؾ��ϴ� ��� �ٿ� ���ؼ�..
	//---------------------------------------------
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
		// �� �� ���
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
						transCount = index - rectLeft;
						// 0�� ����Ѵ�.
						memset(pDestTemp, 0, transCount<<1);
						pDestTemp += transCount;		// �������ŭ �ǳ� �ڴ�.

						// �̹� �ܰ�� ��� ���
						memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);
						pDestTemp += colorCount;
						pPixels += (colorCount<<1);
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

						// ������ �ƴ� ������ Surface�� ����Ѵ�.
						memcpyAlpha4444(pDestTemp, pPixels+(dist<<1), colorCount-dist, pal);
						pDestTemp += colorCount-dist;
						pPixels += (colorCount<<1);
						index += colorCount;

						// �������ʹ� ��� ����Ѵ�.
						break;
					}
				}					

				// ������ �ƴ� ����ŭ index����				
				pPixels += (colorCount<<1);
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
							// 0�� ����Ѵ�.
							memset(pDestTemp, 0, transCount<<1);
							pDestTemp += transCount;		// �������ŭ �ǳ� �ڴ�.
						
							// ������ �ƴ� ������ Surface�� ����Ѵ�.
							memcpyAlpha4444(pDestTemp, pPixels, rectRight - index, pal);
							break;
						}
					}

					// 0�� ����Ѵ�.
					memset(pDestTemp, 0, transCount<<1);
					pDestTemp += transCount;		// �������ŭ �ǳ� �ڴ�.

					// ���
					memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);
					pDestTemp += colorCount;
					pPixels += (colorCount<<1);
					index += colorCount;
				} while (--j);
			}
		}		

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// Blt4444NotTrans Clip Height
//----------------------------------------------------------------------
// pRect->top, rectBottom��ŭ�� ����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::Blt4444NotTransClipHeight(WORD *pDest, WORD pitch, RECT* pRect, MPalette &pal)
{
	int		count,
			transCount,
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
		// �� �� ���
		if (count > 0)
		{			
			j = count;
			do
			{	
				transCount = *pPixels++;		// �������ŭ �ǳ� �ڴ�.
				colorCount = *pPixels++;		// ���� �ƴ� �� ��				

				// 0�� ����Ѵ�.
				memset(pDestTemp, 0, transCount<<1);
				pDestTemp += transCount;		// �������ŭ �ǳ� �ڴ�.

				// ������ �ƴ� ������ Surface�� ����Ѵ�.
				memcpyAlpha4444(pDestTemp, pPixels, colorCount, pal);
				
				pDestTemp	+= colorCount;
				pPixels		+= (colorCount<<1);
			} while (--j);
		}

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}


//----------------------------------------------------------------------
// BltAlpha
//----------------------------------------------------------------------
// Clipping���� �ʴ´�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::BltAlpha(WORD *pDest, WORD pitch, BYTE alpha, MPalette &pal)
{
	s_Value1 = alpha;

	int	count,			
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
					pDestTemp += *pPixels++;		// �������ŭ �ǳ� �ڴ�.
					colorCount = *pPixels++;		// ���� �ƴ� �� ��				

					// ������ �ƴ� ������ Surface�� ����Ѵ�.
					memcpyAlphaValue(pDestTemp, pPixels, colorCount, pal);
					
					pDestTemp	+= colorCount;

					// ���� �� ������ alpha�� ������ 2���̴�.
					pPixels		+= (colorCount<<1);
				} while (--j);
			}

			pDest = (WORD*)((BYTE*)pDest - pitch);
		} while (i--);
	}
}

//----------------------------------------------------------------------
// BltAlpha ClipLeft
//----------------------------------------------------------------------
// ���� clipping.  
// rectLeft���� ���� �ǳʶ� �������� pDest�� ����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::BltAlphaClipLeft(WORD* pDest, WORD pitch, RECT* pRect, BYTE alpha, MPalette &pal)
{
	s_Value1 = alpha;

	BYTE	*pPixels;
	WORD	*pDestTemp;

	//--------------------------------------------
	// pRect��ŭ�� ���� ����Ѵ�.
	//--------------------------------------------
	int	count,
			transCount, 
			colorCount,
			index,
			dist;

	register int i;
	register int j;

	int rectBottom = pRect->bottom;
	int rectLeft = pRect->left;

	//---------------------------------------------
	// ����ؾ��ϴ� ��� �ٿ� ���ؼ�..
	//---------------------------------------------
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
		// �� �� ���
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
						memcpyAlphaValue(pDestTemp, pPixels, colorCount, pal);
						pDestTemp += colorCount;
						pPixels += (colorCount<<1);

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
						memcpyAlphaValue(pDestTemp, pPixels+(dist<<1), colorCount-dist, pal);
						pDestTemp += colorCount-dist;
						pPixels += (colorCount<<1);

						// �������ʹ� ��� ����Ѵ�.
						break;
					}
				}					

				// ������ �ƴ� ����ŭ index����				
				pPixels += (colorCount<<1);
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
					memcpyAlphaValue(pDestTemp, pPixels, colorCount, pal);

					// memory addr ����
					pDestTemp += colorCount;
					pPixels += (colorCount<<1);
				} while (--j);
			}
		}
		

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// BltAlpha ClipRight
//----------------------------------------------------------------------
// ������ clipping.  
// rectRight�� ������ ���� pDest�� ����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::BltAlphaClipRight(WORD* pDest, WORD pitch, RECT* pRect, BYTE alpha, MPalette &pal)
{
	s_Value1 = alpha;

	BYTE	*pPixels;
	WORD	*pDestTemp;

	//--------------------------------------------
	// pRect��ŭ�� ���� ����Ѵ�.
	//--------------------------------------------
	int	count,
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
		// �� �� ���
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
						memcpyAlphaValue(pDestTemp, pPixels, rectRight - index, pal);
						break;
					}
				}

				// �������ŭ �ǳʶ��
				pDestTemp += transCount;

				// ���
				memcpyAlphaValue(pDestTemp, pPixels, colorCount, pal);
				pDestTemp += colorCount;
				pPixels += (colorCount<<1);
				index += colorCount;
			} while (--j);
		}
		
		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// BltAlpha ClipWidth
//----------------------------------------------------------------------
// ���� clipping.  
// rectLeft���� ���� �ǳʶ� �������� pDest�� ����Ѵ�.
// rectRight����..
//----------------------------------------------------------------------
void
CAlphaSpritePal::BltAlphaClipWidth(WORD* pDest, WORD pitch, RECT* pRect, BYTE alpha, MPalette &pal)
{
	s_Value1 = alpha;

	BYTE	*pPixels;
	WORD	*pDestTemp;

	//--------------------------------------------
	// pRect��ŭ�� ���� ����Ѵ�.
	//--------------------------------------------
	int	count,
			transCount, 
			colorCount,
			index,
			dist;

	register int i;
	register int j;

	int rectBottom = pRect->bottom;
	int rectLeft = pRect->left;
	int rectRight = pRect->right;

	//---------------------------------------------
	// ����ؾ��ϴ� ��� �ٿ� ���ؼ�..
	//---------------------------------------------
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
		// �� �� ���
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
						// ������ ���� �Ѿ�� ���..
						if (index+colorCount > rectRight)
						{							
							// ����������� ������ �� �Ѿ�� ���
							if (index > rectRight)
							{
							}
							else
							{
								//memset((void*)pDestTemp, 0, (rectRight - index)<<1);
								memcpyAlphaValue(pDestTemp, pPixels, (rectRight - index), pal);
							}

							j = 0;
							
							break;
						}

						memcpyAlphaValue(pDestTemp, pPixels, colorCount, pal);
						pDestTemp += colorCount;
						pPixels += (colorCount<<1);
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

						// ������ �ƴ� ������ Surface�� ����Ѵ�.
						// ������ ���� �Ѿ�� ���..
						if (index+colorCount > rectRight)
						{
							memcpyAlphaValue(pDestTemp, pPixels+(dist<<1), (rectRight - rectLeft), pal);

							j = 0;						
							break;
						}		

						memcpyAlphaValue(pDestTemp, pPixels+(dist<<1), colorCount-dist, pal);
						pDestTemp += colorCount-dist;
						pPixels += (colorCount<<1);
						index += colorCount;

						// �������ʹ� ��� ����Ѵ�.
						break;
					}
				}					

				// ������ �ƴ� ����ŭ index����				
				pPixels += (colorCount<<1);
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
							memcpyAlphaValue(pDestTemp, pPixels, rectRight - index, pal);
							break;
						}
					}

					// �������ŭ �ǳʶ��
					pDestTemp += transCount;

					// ���
					memcpyAlphaValue(pDestTemp, pPixels, colorCount, pal);
					pDestTemp += colorCount;
					pPixels += (colorCount<<1);
					index += colorCount;
				} while (--j);
			}
		}		

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}

//----------------------------------------------------------------------
// BltAlpha Clip Height
//----------------------------------------------------------------------
// pRect->top, rectBottom��ŭ�� ����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePal::BltAlphaClipHeight(WORD *pDest, WORD pitch, RECT* pRect, BYTE alpha, MPalette &pal)
{
	s_Value1 = alpha;

	int	count,			
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
		// �� �� ���
		if (count > 0)
		{			
			j = count;
			do
			{
				pDestTemp += *pPixels++;		// �������ŭ �ǳ� �ڴ�.
				colorCount = *pPixels++;		// ���� �ƴ� �� ��				

				// ������ �ƴ� ������ Surface�� ����Ѵ�.
				memcpyAlphaValue(pDestTemp, pPixels, colorCount, pal);
				
				pDestTemp	+= colorCount;
				pPixels		+= (colorCount<<1);
			} while (--j);
		}

		pDest = (WORD*)((BYTE*)pDest + pitch);
	}
}


//----------------------------------------------------------------------
// AlphaChannel Copy
//----------------------------------------------------------------------
// Alpha�� : 1~32
//----------------------------------------------------------------------
// pSource�� ���� pDest�� ����� �ؾ��Ѵ�.
// pSource�� ������ (alpha,���� �ϳ�)�� pixels��ŭ �ݺ��̴�.
//----------------------------------------------------------------------
void	
CAlphaSpritePal::memcpyAlphaValue(WORD* pDest, BYTE* pSource, WORD pixels, MPalette &pal)
{
	register WORD		sTemp,dTemp;
	register int		sr,sg,sb,dr,dg,db;
	//static WORD		temp, temp2;

	register int i = pixels;

	//BYTE alpha;

	// Alpha Channel Blending
	// ������ ���
	while (i--)
	{	
		// Source���� Alpha���� ���ԵǾ� �ִ�.
		//alpha = *pSource >> 8;
		pSource++;

		// ���� ���
		sTemp = pal[*pSource];
		dTemp = *pDest;

		sr = CDirectDraw::Red(sTemp);
		sg = CDirectDraw::Green(sTemp);
		sb = CDirectDraw::Blue(sTemp);

		dr = CDirectDraw::Red(dTemp);
		dg = CDirectDraw::Green(dTemp);
		db = CDirectDraw::Blue(dTemp);		
		
		*pDest = ((s_Value1 * (sb - db) >> 5) + db |
					((s_Value1 * (sg - dg) >> 5) + dg) << CDirectDraw::s_bSHIFT_G |
					((s_Value1 * (sr - dr) >> 5) + dr) << CDirectDraw::s_bSHIFT_R);
	
		/*
		// ��... �̰� �� ������.. �� �׷���.. - -;;;
		temp = sb-db;
		temp *= alpha;
		temp >>= 5;
		temp += db;

		temp2 = sg-dg;
		temp2 *= alpha;
		temp2 >>= 5;
		temp2 += dg;
		temp2 <<= 5;

		temp |= temp2;

		temp2 = sr-dr;
		temp2 *= alpha;
		temp2 >>= 5;
		temp2 += dr;
		temp2 <<= CDirectDraw::s_bSHIFT_R;

		temp |= temp2;

		*pDest = temp;
		*/

		pDest++;
		pSource++;
	}
}


//----------------------------------------------------------------------
// Blt4444SmallNotTrans
//----------------------------------------------------------------------
// ����ؼ� ���.. 
// Clipping���� �ʴ´�.
//----------------------------------------------------------------------
// shift�� ���ؼ� ���� ������ ���̴ٺ���
// ���� ���̰� ���� ���� �Ǵµ�,
// �װ� ��������� �Ѵ�.
// ����� �� ������.. T_T;;
// �ٿ��� ���̸� �ٽ� �ø���(-_-;)
// ������ ���� ������ �� �� �ִ�.					
//----------------------------------------------------------------------
void
CAlphaSpritePal::Blt4444SmallNotTrans(WORD *pDest, WORD pitch, BYTE shift, MPalette &pal)
{
	s_Value1 = shift;
	// memcpy���� �ϳ��� alpha���� �����ϰ� +�ϴ� ��
	s_Value2 = (2 << shift) - 1; //((1 << s_Value1) << 1) - 1;	


	int		count,	
			transCount,
			colorCount,
			transCountShift,
			colorCountShift,
			totalCount,
			totalShiftCount,
			pixelGap,
			pixelGapShift;

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
			totalCount = 0;
			totalShiftCount = 0;
			if (count > 0)
			{			
				j = count;
				do
				{		
					transCount = *pPixels++;					
					colorCount = *pPixels++;		// ���� �ƴ� �� ��	
					
					//--------------------------------------------------
					// shift��ŭ �ٿ��� ���� ����Ѵ�.
					//--------------------------------------------------
					transCountShift = transCount >> shift;
					colorCountShift = colorCount >> shift;

					//--------------------------------------------------
					//				���� �κ� ���� ����
					//--------------------------------------------------
					// ���� size�� pixel��..
					//--------------------------------------------------
					totalCount += transCount;
					totalShiftCount += transCountShift;

					// ����pixel - shift�ؼ� �ø� pixel(-_-;)
					pixelGap = totalCount - (totalShiftCount << shift);

					// gap�� �ٽ� shift�ؼ� �����ش�.
					pixelGapShift = pixelGap >> shift;
					transCountShift += pixelGapShift;
					totalShiftCount += pixelGapShift;

					
					//--------------------------------------------------
					// 0�� ����Ѵ�. ������̴�..
					//--------------------------------------------------
					memset(pDestTemp, 0, transCountShift<<1);
					pDestTemp += transCountShift;		// �������ŭ �ǳ� �ڴ�.


					//--------------------------------------------------
					//				���� �κ� ���� ����
					//--------------------------------------------------
					// (!!!) �ٵ� ���⼭ ������ �ִ�.
					// ������̾� �׳� ������ε�..
					// ������ �ִ� �κп����� 
					// �� ��� �� ���ߵ� ���..
					// � ���� ����ұ�?? ��..
					// �̴�ζ��.. 
					// ������ ����ŭ �׳� �ǳʶ� ��.. ��..- -;
					//
					// �׷���, �ϴ� ����.. - -;
					//--------------------------------------------------
					totalCount += colorCount;
					totalShiftCount += colorCountShift;

					//--------------------------------------------------
					// ������ �ƴ� ������ Surface�� ����Ѵ�.
					//--------------------------------------------------					
					memcpyAlpha4444Small(pDestTemp, pPixels, colorCount, pal);
					
					pDestTemp	+= colorCountShift;

					// ���� �� ������ alpha�� ������ 2���̴�.
					pPixels		+= (colorCount<<1);
				} while (--j);
			}

			pDest = (WORD*)((BYTE*)pDest - pitch);

			i-=stepY;

		} while (i>0);
	}
}


//----------------------------------------------------------------------
// AlphaChannel Copy  4444 Small
//----------------------------------------------------------------------
// Alpha�� : 1~32
//----------------------------------------------------------------------
// pSource�� ���� pDest�� ����� �ؾ��Ѵ�.
// pSource�� ������ (alpha,���� �ϳ�)�� pixels��ŭ �ݺ��̴�.
//
// A:R:G:B = 4:4:4:4 Texture�� ���� ���̴�.
//----------------------------------------------------------------------
void	
CAlphaSpritePal::memcpyAlpha4444Small(WORD* pDest, BYTE* pSource, WORD pixels, MPalette &pal)
{
	register WORD		sTemp;
	register int		sr,sg,sb;
	//static WORD		temp, temp2;

	register int i = pixels >> s_Value1;

	BYTE alpha;
	
	// Alpha Channel Blending
	// ������ ���
	while (i--)
	{	
		// Source���� Alpha���� ���ԵǾ� �ִ�.
		alpha = *pSource >> 1;	//	alpha = (*pSource >> 8) >> 1;	4 bit�̱� ������..
		pSource++;

		// ���� ���
		sTemp = pal[*pSource];
	
		sr = (sTemp >> CDirectDraw::s_bSHIFT4_R);// & 0x0F;
		sg = (sTemp >> CDirectDraw::s_bSHIFT4_G) & 0x0F;
		sb = (sTemp >> CDirectDraw::s_bSHIFT4_B) & 0x0F;
		
		*pDest =	(alpha << 12) |
					(sr << 8) |
					(sg << 4) |
					(sb);
	
		pDest++;
		pSource += s_Value2;
	}
}

bool
CAlphaSpritePal::IsColorPixel(short x, short y)
{
	if( y >= m_Height || y < 0 || x < 0 || x >= m_Width )
		return false;

	int	colorCount, count;
	int offset=0;

	const BYTE	*pPixels = m_pPixels[y];
	
	register int j;
	count	= *pPixels++;		
	if (count > 0)
	{	
		j = count;
		do {
			offset += *pPixels++;
			if( offset > x ) return false;
			colorCount = *pPixels++;		// ���� �ƴ� �� ��				
			offset += colorCount;
			if( offset > x ) return true;
			pPixels		+= (colorCount<<1);
		} while (--j);
	}
	return false;
}

WORD
CAlphaSpritePal::GetPixel( short x, short y, MPalette &pal )
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
				pPixels ++;		// ���İ��� �ǳʶٰ�				
				pPixels += ((x - offset)<<1);
				return pal[*pPixels];
			}
			pPixels += (colorCount<<1);
		} while(--j);
	}

	return 0;
}
