//----------------------------------------------------------------------
// CSpriteOutlineManager.cpp
//----------------------------------------------------------------------
#include "client_PCH.h"
#include "CSpriteOutlineManager.h"
#include "CSprite.h"
#include "CAlphaSprite.h"
#include "CIndexSprite.h"

//----------------------------------------------------------------------
// 
// constructor/destructor
//
//----------------------------------------------------------------------
CSpriteOutlineManager::CSpriteOutlineManager()
{
	m_Width			= 0;
	m_Height		= 0;
	m_ppPixelInfo	= NULL;
	m_ppColorInfo	= NULL;

	Clear();
}

CSpriteOutlineManager::~CSpriteOutlineManager()
{
	ReleaseInfo();
}

//----------------------------------------------------------------------
//
// member functions
//
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Init
//----------------------------------------------------------------------
void
CSpriteOutlineManager::Clear()
{
	// ��ϵ� sprite�� ���� �Ѵ�.
	for (int i=0; i<MAX_SPRITE_MERGE; i++)
	{
		m_Type[i]		= SPRITETYPE_NULL;
		m_pSprite[i]	= NULL;		
	}

	m_nSprite = 0;

	m_rectOutline.left		= 999;
	m_rectOutline.right		= -999;
	m_rectOutline.top		= 999;
	m_rectOutline.bottom	= -999;

	m_pointOutput.x			= 0;
	m_pointOutput.y			= 0;

	// �ܰ��� ���� ����
	ReleaseInfo();

}

//----------------------------------------------------------------------
// Release
//----------------------------------------------------------------------
void
CSpriteOutlineManager::InitInfo(int width, int height)
{
	// �ϴ� �޸� ����
	ReleaseInfo();

	// ���̰� ���� ���
	if (width==0 || height==0)
		return;

	m_Width = width;
	m_Height = height;

	// �޸� ���..
	m_ppPixelInfo = new BYTE* [m_Height];
	m_ppColorInfo = new WORD* [m_Height];

	for (int i=0; i<m_Height; i++)
	{
		m_ppPixelInfo[i] = new BYTE [m_Width];
		m_ppColorInfo[i] = new WORD [m_Width];

		// �ϴ� ��� ���� ��������� �ʱ�ȭ�Ѵ�.
		//for (int j=0; j<m_Width; j++)
		//{
		//	m_ppPixelInfo[i][j] = PIXELTYPE_TRANS;
		//}
		memset((void*)m_ppPixelInfo[i], PIXELTYPE_TRANS, m_Width);
	}
}

//----------------------------------------------------------------------
// Release
//----------------------------------------------------------------------
void
CSpriteOutlineManager::ReleaseInfo()
{
	// m_ppPixelInfo����
	if (m_ppPixelInfo != NULL)
	{		
		for (int i=0; i<m_Height; i++)
		{
			delete [] m_ppPixelInfo[i];
		}

		delete [] m_ppPixelInfo;
		m_ppPixelInfo	= NULL;
	}

	// m_ppColorInfo����
	if (m_ppColorInfo != NULL)
	{				
		for (int i=0; i<m_Height; i++)
		{
			delete [] m_ppColorInfo[i];
		}

		delete [] m_ppColorInfo;
		m_ppColorInfo	= NULL;
	}

	m_Width		= 0;
	m_Height	= 0;

}

//----------------------------------------------------------------------
// Add Sprite( CSprite* )
//----------------------------------------------------------------------
void		
CSpriteOutlineManager::Add(int x, int y, CSprite* pSprite)
{
	// Sprite�� ���� �������� ���� ���..
	if (pSprite->IsNotInit())
		return;

	// MAX_SPRITE_MERGE�� ���� �ʵ��� �Ѵ�.
	if (m_nSprite < MAX_SPRITE_MERGE)
	{
		m_Type[m_nSprite]		= SPRITETYPE_NORMAL;	
		m_Position[m_nSprite].x	= x;
		m_Position[m_nSprite].y	= y;
		m_pSprite[m_nSprite]	= (void*)pSprite;

		m_nSprite++;

		
		// �ܰ��� ������ ũ�⸦ �����Ѵ�.
		int temp;

		if (x < m_rectOutline.left)
			m_rectOutline.left = x;

		temp = x+pSprite->GetWidth();
		if (temp > m_rectOutline.right)
			m_rectOutline.right = temp;

		if (y < m_rectOutline.top)
			m_rectOutline.top = y;

		temp = y+pSprite->GetHeight();
		if (temp > m_rectOutline.bottom)
			m_rectOutline.bottom = temp;
	}
}

//----------------------------------------------------------------------
// Add Sprite( CIndexSprite* )
//----------------------------------------------------------------------
void		
CSpriteOutlineManager::Add(int x, int y, CIndexSprite* pSprite, WORD colorSet)
{
	// Sprite�� ���� �������� ���� ���..
	if (pSprite->IsNotInit())
		return;

	register int i;
	// MAX_SPRITE_MERGE�� ���� �ʵ��� �Ѵ�.
	if (m_nSprite < MAX_SPRITE_MERGE)
	{
		m_Type[m_nSprite]		= SPRITETYPE_INDEX;	
		m_Position[m_nSprite].x	= x;
		m_Position[m_nSprite].y	= y;
		m_ChangeColorSet[m_nSprite] = colorSet;

		for(i = 0; i < 256; i++)
		{
			m_Value[m_nSprite][i]	= CIndexSprite::GetUsingColorSet( i );
		}
		m_pSprite[m_nSprite]	= (void*)pSprite;

		m_nSprite++;

		
		// �ܰ��� ������ ũ�⸦ �����Ѵ�.
		int temp;

		if (x < m_rectOutline.left)
			m_rectOutline.left = x;

		temp = x+pSprite->GetWidth();
		if (temp > m_rectOutline.right)
			m_rectOutline.right = temp;

		if (y < m_rectOutline.top)
			m_rectOutline.top = y;

		temp = y+pSprite->GetHeight();
		if (temp > m_rectOutline.bottom)
			m_rectOutline.bottom = temp;
	}
}

//----------------------------------------------------------------------
// Add Sprite( CAlphaSprite* )
//----------------------------------------------------------------------
void		
CSpriteOutlineManager::Add(int x, int y, CAlphaSprite* pSprite)
{
	// Sprite�� ���� �������� ���� ���..
	if (pSprite->IsNotInit())
		return;

	// MAX_SPRITE_MERGE�� ���� �ʵ��� �Ѵ�.
	if (m_nSprite < MAX_SPRITE_MERGE)
	{
		m_Type[m_nSprite]		= SPRITETYPE_ALPHA;	
		m_Position[m_nSprite].x	= x;
		m_Position[m_nSprite].y	= y;
		m_pSprite[m_nSprite]	= (void*)pSprite;

		m_nSprite++;

		
		// �ܰ��� ������ ũ�⸦ �����Ѵ�.
		int temp;

		if (x < m_rectOutline.left)
			m_rectOutline.left = x;

		temp = x+pSprite->GetWidth();
		if (temp > m_rectOutline.right)
			m_rectOutline.right = temp;

		if (y < m_rectOutline.top)
			m_rectOutline.top = y;

		temp = y+pSprite->GetHeight();
		if (temp > m_rectOutline.bottom)
			m_rectOutline.bottom = temp;
	}
}

//----------------------------------------------------------------------
// Generate
//----------------------------------------------------------------------
// �ܰ����� ���� ������ �����Ѵ�.
//----------------------------------------------------------------------
void		
CSpriteOutlineManager::Generate(int opt)
{	
	if (m_nSprite==0)
		return;

	register int i;
	register int j;

	//------------------------------------------------------
	// �ܰ��� ������ ũ��(m_rectOutline)�� ���� ���� ����.
	//------------------------------------------------------
	//
	// ex) (100,100) ~ (200,200) : ��ϵ� Sprite���� �ܰ�
	//
	// --> (0,0) ~ (100,100)     : (0,0)�� ����������.. 
	// --> (0,0) ~ (102,102)     : �ܰ��� ���پ� �� �߰�.
	//
	// �����ġ : (100,100) - (1,1) = (99,99)
	//
	//------------------------------------------------------
	m_pointOutput.x		= m_rectOutline.left - 1;
	m_pointOutput.y		= m_rectOutline.top - 1;

	m_rectOutline.right -= m_rectOutline.left;
	m_rectOutline.bottom -= m_rectOutline.top;
	//m_rectOutline.left = 0;
	//m_rectOutline.top = 0;
	m_rectOutline.right += 1;	// +2	�Ʒ��ʿ��� ����� ���ǻ� +1�� g��
	m_rectOutline.bottom += 1;	// +2
	
	// ���� ����
	InitInfo( m_rectOutline.right+1, m_rectOutline.bottom+1 );


	//------------------------------------------------------
	//
	// �� Sprite�� ���� �ܰ��� ������ ������� �ش�.
	//
	//------------------------------------------------------
	for (i=0; i<m_nSprite; i++)
	{
		// �ܰ��� �������� �� Sprite�� ��ġ�ϴ� position
		m_Position[i].x	-= m_rectOutline.left;
		m_Position[i].x	+= 1;
		m_Position[i].y	-= m_rectOutline.top;
		m_Position[i].y	+= 1;

		switch (m_Type[i])
		{
			case SPRITETYPE_NORMAL :
				MergeNormalSprite( i );
			break;

			case SPRITETYPE_INDEX :
				if (m_ChangeColorSet[i] < MAX_COLORSET)
				{
					MergeIndexSpriteColorSet( i );					
				}
				else
				{
					MergeIndexSprite( i );
				}
			break;

			case SPRITETYPE_ALPHA :
				MergeAlphaSprite( i );
			break;
		}		
	}

	//------------------------------------------------------
	//
	// ������ �ܰ��� ������ -->  �ܰ����� �����Ѵ�.
	//
	//
	// m_ppPixelInfo�� PIXELTYPE_OUTLINE�� �߰��Ѵ�.
	// 
	//------------------------------------------------------
	//------------------------------------------------------
	// ���η� Scan
	//------------------------------------------------------
	BOOL bPreviousTrans;
	for (i=1; i<m_rectOutline.right; i++)
	{
		bPreviousTrans = TRUE;

		for (j=1; j<m_rectOutline.bottom; j++)
		{
			// ������� ���
			if (m_ppPixelInfo[j][i] == PIXELTYPE_TRANS)
			{
				// ������ ���� ������� �ƴ� ���
				if (!bPreviousTrans)
				{
					m_ppPixelInfo[j][i] = PIXELTYPE_OUTLINE;
					bPreviousTrans = TRUE;
				}
			}
			// ������� �ƴ� ���
			else
			{
				// ������ ���� ������� ���
				if (bPreviousTrans)
				{
					m_ppPixelInfo[j-1][i] = PIXELTYPE_OUTLINE;
					bPreviousTrans = FALSE;
				}
			}	
		}

		// ������ ���� ������� �ƴ� ���
		if (!bPreviousTrans)
		{
			m_ppPixelInfo[j][i] = PIXELTYPE_OUTLINE;
		}
	}
	
	//------------------------------------------------------
	// ���η� Scan
	//------------------------------------------------------
	if(opt != GENERATE_EXCEPT_SIDE)
	{
		int	transCount;		// ����� ����
		int transIndex;
		int	colorCount;		// �� ����
		int colorIndex;
		for (i=1; i<m_rectOutline.bottom; i++)
		{
			transCount		= 0;
			transIndex		= 0;
			colorCount		= 0;
			colorIndex		= 0;
			bPreviousTrans	= TRUE;

			for (j=1; j<m_rectOutline.right; j++)
			{
				// ������� ���
				if (m_ppPixelInfo[i][j] == PIXELTYPE_TRANS)
				{
					// ������ ���� ������� �ƴ� ���
					if (!bPreviousTrans)
					{
						// ������ ���� outline�̸�..
						if (m_ppPixelInfo[i][j-1]==PIXELTYPE_OUTLINE)
						{
							// ����� ������ ������ ��ġ
							transIndex		= j;
							bPreviousTrans = TRUE;
						}
						// ������ ���� outline�� �ƴϸ�(�����̸�)..
						else
						{				
							if(opt != GENERATE_EXCEPT_RIGHT)
								m_ppPixelInfo[i][j] = PIXELTYPE_OUTLINE;
							continue;
						}										
					}
					transCount++;
				}
				// ������� �ƴ� ���
				else
				{
					// ������ ���� ������� ���
					if (bPreviousTrans)
					{
						// �̹� ����scan���� outlineüũ�� �Ǿ� �ִٸ�
						if (m_ppPixelInfo[i][j]==PIXELTYPE_OUTLINE)
						{
						}
						// �ƴϸ�..
						else
						{
							if(opt != GENERATE_EXCEPT_LEFT)
							{
								transCount --;
								m_ppPixelInfo[i][j-1] = PIXELTYPE_OUTLINE;						
							}
						}
						
						bPreviousTrans = FALSE;

						// ����� ������ �����صд�.
						//
						// (!) transCount�� 200�̻��� ���.. check
						//
						// 0�̸� �����ؼ��� �ȵȴ�.
						if (transCount > 0)
						{
							m_ppPixelInfo[i][transIndex] = transCount;
							transCount = 0;
						}					
					}				
				}	
			}

			// ������ ���� ������� ���
			if (bPreviousTrans)
			{
				// �ڷδ� ��� ������̶�� �ǹ�.
				if (transCount > 0)
				{
					m_ppPixelInfo[i][transIndex] = PIXELTYPE_TRANSEND;
				}
			}
			// ������ ���� ������� �ƴ� ���
			else if (m_ppPixelInfo[i][j-1] != PIXELTYPE_OUTLINE)
			{
				if(opt != GENERATE_EXCEPT_RIGHT)
					m_ppPixelInfo[i][j] = PIXELTYPE_OUTLINE;
			}
		}
	}	
}

//----------------------------------------------------------------------
// Blt
//----------------------------------------------------------------------
// �ܰ����� ȭ�鿡 ����Ѵ�. 
//
// pSurface��.. �ܰ����� color�� 
//----------------------------------------------------------------------
void		
CSpriteOutlineManager::Blt(WORD* pSurface, WORD Pitch, WORD color)
{
	if (m_nSprite==0)
		return;

	// ��ǥ ����
	pSurface = (WORD*)((BYTE*)pSurface + Pitch*m_pointOutput.y + (m_pointOutput.x<<1));

	register int i;
	register int j;

	WORD	*pSurfaceTemp;	

	int rectBottom = m_rectOutline.bottom;
	int rectRight = m_rectOutline.right;

	int info;

	// Clipping�� �ؾ��Ѵ�. T_T;;;
	for (i=0; i<=rectBottom; i++)
	{
		pSurfaceTemp = pSurface;

		//for (j=0; j<=m_rectOutline.right; j++)
		j = 0;
		BYTE* pPixelInfo = m_ppPixelInfo[i];
		while (j <= rectRight)
		{		
			info = *pPixelInfo;

			// �������ŭ �ǳʶڴ�.
			if (info < PIXELTYPE_MAXCOUNT)
			{				
				pSurfaceTemp += info;
				pPixelInfo += info;
				j += info;
			}

			// �ܰ����� ��� 
			if (info == PIXELTYPE_OUTLINE)
			{
				*pSurfaceTemp = color;
			}
			// ������ ���
			else if (info == PIXELTYPE_COLOR)
			{
				*pSurfaceTemp = m_ppColorInfo[i][j];
			}
			// ������ ������� ���
			else if (info==PIXELTYPE_TRANSEND)
			{
				break;
			}

			pSurfaceTemp++;
			pPixelInfo++;
			j++;
		}

		// ���� ��
		pSurface = (WORD*)((BYTE*)pSurface + Pitch);
	}
}

//----------------------------------------------------------------------
// Blt Clip
//----------------------------------------------------------------------
// �ܰ����� ȭ�鿡 ����Ѵ�. 
//
// pSurface��.. �ܰ����� color�� 
//----------------------------------------------------------------------
void		
CSpriteOutlineManager::BltClip(WORD* pSurface, WORD Pitch, WORD color, RECT* pRect)
{
	if (m_nSprite==0)
		return;

	// ��ǥ ����
	pSurface = (WORD*)((BYTE*)pSurface + Pitch*m_pointOutput.y + (m_pointOutput.x<<1));

	pSurface = (WORD*)((BYTE*)pSurface + Pitch*pRect->top + (pRect->left<<1));

	register int i;
	register int j;

	WORD	*pSurfaceTemp;	

	int rectBottom = pRect->bottom;
	int rectLeft = pRect->left;
	int rectRight = pRect->right;

	// Clipping�� �ؾ��Ѵ�. T_T;;;
	for (i=pRect->top; i<rectBottom; i++)
	{
		pSurfaceTemp = pSurface;

		//for (j=0; j<=m_rectOutline.right; j++)
		j = rectLeft;
		while (j < rectRight)
		{		
			// �������ŭ �ǳʶڴ�.
			if (m_ppPixelInfo[i][j] < PIXELTYPE_MAXCOUNT)
			{				
				pSurfaceTemp += m_ppPixelInfo[i][j];
				j += m_ppPixelInfo[i][j];

				continue;
			}

			// �ܰ����� ��� 
			if (m_ppPixelInfo[i][j] == PIXELTYPE_OUTLINE)
			{
				*pSurfaceTemp = color;
			}
			// ������ ���
			else if (m_ppPixelInfo[i][j] == PIXELTYPE_COLOR)
			{
				*pSurfaceTemp = m_ppColorInfo[i][j];
			}
			// ������ ������� ���
			else if (m_ppPixelInfo[i][j]==PIXELTYPE_TRANSEND)
			{
				break;
			}



			pSurfaceTemp++;
			j++;
		}

		// ���� ��
		pSurface = (WORD*)((BYTE*)pSurface + Pitch);
	}
}

//----------------------------------------------------------------------
// BltOutline
//----------------------------------------------------------------------
// �ܰ����� ȭ�鿡 ����Ѵ�. 
//
// pSurface��.. �ܰ����� color�� 
//----------------------------------------------------------------------
void		
CSpriteOutlineManager::BltOutline(WORD* pSurface, WORD Pitch, WORD color)
{
	if (m_nSprite==0)
		return;

	// ��ǥ ����
	pSurface = (WORD*)((BYTE*)pSurface + Pitch*m_pointOutput.y + (m_pointOutput.x<<1));

	register int i;
	register int j;

	WORD	*pSurfaceTemp;	

	int rectBottom = m_rectOutline.bottom;
	int rectRight = m_rectOutline.right;

	// Clipping�� �ؾ��Ѵ�. T_T;;;
	for (i=0; i<=rectBottom; i++)
	{
		pSurfaceTemp = pSurface;

		//for (j=0; j<=m_rectOutline.right; j++)
		j = 0;
		while (j <= rectRight)
		{		
			// �������ŭ �ǳʶڴ�.
			if (m_ppPixelInfo[i][j] < PIXELTYPE_MAXCOUNT)
			{				
				pSurfaceTemp += m_ppPixelInfo[i][j];
				j += m_ppPixelInfo[i][j];
			}

			// �ܰ����� ��� 
			if (m_ppPixelInfo[i][j] == PIXELTYPE_OUTLINE)
			{
				*pSurfaceTemp = color;
			}
			// ������ ���
			//else if (m_ppPixelInfo[i][j] == PIXELTYPE_COLOR)
			//{
			//	*pSurfaceTemp = m_ppColorInfo[i][j];
			//}
			// ������ ������� ���
			else if (m_ppPixelInfo[i][j]==PIXELTYPE_TRANSEND)
			{
				break;
			}



			pSurfaceTemp++;
			j++;
		}

		// ���� ��
		pSurface = (WORD*)((BYTE*)pSurface + Pitch);
	}
}

//----------------------------------------------------------------------
// BltOutline Clip
//----------------------------------------------------------------------
// �ܰ����� ȭ�鿡 ����Ѵ�. 
//
// pSurface��.. �ܰ����� color�� 
//----------------------------------------------------------------------
void		
CSpriteOutlineManager::BltOutlineClip(WORD* pSurface, WORD Pitch, WORD color, RECT* pRect)
{
	if (m_nSprite==0)
		return;

	// ��ǥ ����
	pSurface = (WORD*)((BYTE*)pSurface + Pitch*m_pointOutput.y + (m_pointOutput.x<<1));

	pSurface = (WORD*)((BYTE*)pSurface + Pitch*pRect->top + (pRect->left<<1));

	register int i;
	register int j;

	WORD	*pSurfaceTemp;	

	int rectBottom = pRect->bottom;
	int rectLeft = pRect->left;
	int rectRight = pRect->right;

	// Clipping�� �ؾ��Ѵ�. T_T;;;
	for (i=pRect->top; i<rectBottom; i++)
	{
		pSurfaceTemp = pSurface;

		//for (j=0; j<=m_rectOutline.right; j++)
		j = rectLeft;
		while (j < rectRight)
		{		
			// �������ŭ �ǳʶڴ�.
			if (m_ppPixelInfo[i][j] < PIXELTYPE_MAXCOUNT)
			{				
				pSurfaceTemp += m_ppPixelInfo[i][j];
				j += m_ppPixelInfo[i][j];

				continue;
			}

			// �ܰ����� ��� 
			if (m_ppPixelInfo[i][j] == PIXELTYPE_OUTLINE)
			{
				*pSurfaceTemp = color;
			}
			// ������ ���
			//else if (m_ppPixelInfo[i][j] == PIXELTYPE_COLOR)
			//{
				//*pSurfaceTemp = m_ppColorInfo[i][j];
			//}
			// ������ ������� ���
			else if (m_ppPixelInfo[i][j]==PIXELTYPE_TRANSEND)
			{
				break;
			}



			pSurfaceTemp++;
			j++;
		}

		// ���� ��
		pSurface = (WORD*)((BYTE*)pSurface + Pitch);
	}
}


//----------------------------------------------------------------------
// Blt Darkness
//----------------------------------------------------------------------
// �ܰ����� ȭ�鿡 ����Ѵ�. 
//
// pSurface��.. �ܰ����� color�� 
//----------------------------------------------------------------------
void		
CSpriteOutlineManager::BltDarkness(WORD* pSurface, WORD Pitch, WORD color, BYTE DarkBits)
{
	if (m_nSprite==0)
		return;

	// ��ǥ ����
	pSurface = (WORD*)((BYTE*)pSurface + Pitch*m_pointOutput.y + (m_pointOutput.x<<1));

	register int i;
	register int j;

	WORD	*pSurfaceTemp;
	
	int rectBottom = m_rectOutline.bottom;
	int rectRight = m_rectOutline.right;

	// Clipping�� �ؾ��Ѵ�. T_T;;;
	for (i=0; i<=rectBottom; i++)
	{
		pSurfaceTemp = pSurface;

		//for (j=0; j<=m_rectOutline.right; j++)
		j = 0;
		while (j <= rectRight)
		{		
			// �������ŭ �ǳʶڴ�.
			if (m_ppPixelInfo[i][j] < PIXELTYPE_MAXCOUNT)
			{				
				pSurfaceTemp += m_ppPixelInfo[i][j];
				j += m_ppPixelInfo[i][j];
			}

			// �ܰ����� ��� 
			if (m_ppPixelInfo[i][j] == PIXELTYPE_OUTLINE)
			{
				*pSurfaceTemp = color;
			}
			// ������ ���
			else if (m_ppPixelInfo[i][j] == PIXELTYPE_COLOR)
			{
				*pSurfaceTemp = (m_ppColorInfo[i][j] >> DarkBits) & CDirectDraw::s_wMASK_SHIFT[DarkBits];				
			}
			// ������ ������� ���
			else if (m_ppPixelInfo[i][j]==PIXELTYPE_TRANSEND)
			{
				break;
			}



			pSurfaceTemp++;
			j++;
		}

		// ���� ��
		pSurface = (WORD*)((BYTE*)pSurface + Pitch);
	}
}


//----------------------------------------------------------------------
// Blt Darkness Clip
//----------------------------------------------------------------------
// �ܰ����� ȭ�鿡 ����Ѵ�. 
//
// pSurface��.. �ܰ����� color�� 
//----------------------------------------------------------------------
void		
CSpriteOutlineManager::BltDarknessClip(WORD* pSurface, WORD Pitch, WORD color, BYTE DarkBits, RECT* pRect)
{
	if (m_nSprite==0)
		return;

	// ��ǥ ����
	pSurface = (WORD*)((BYTE*)pSurface + Pitch*m_pointOutput.y + (m_pointOutput.x<<1));

	pSurface = (WORD*)((BYTE*)pSurface + Pitch*pRect->top + (pRect->left<<1));

	register int i;
	register int j;

	WORD	*pSurfaceTemp;	

	int rectBottom = pRect->bottom;
	int rectLeft = pRect->left;
	int rectRight = pRect->right;

	// Clipping�� �ؾ��Ѵ�. T_T;;;
	for (i=pRect->top; i<rectBottom; i++)
	{
		pSurfaceTemp = pSurface;

		//for (j=0; j<=m_rectOutline.right; j++)
		j = rectLeft;
		while (j < rectRight)
		{		
			// �������ŭ �ǳʶڴ�.
			if (m_ppPixelInfo[i][j] < PIXELTYPE_MAXCOUNT)
			{				
				pSurfaceTemp += m_ppPixelInfo[i][j];
				j += m_ppPixelInfo[i][j];

				continue;
			}

			// �ܰ����� ��� 
			if (m_ppPixelInfo[i][j] == PIXELTYPE_OUTLINE)
			{
				*pSurfaceTemp = color;
			}
			// ������ ���
			else if (m_ppPixelInfo[i][j] == PIXELTYPE_COLOR)
			{
				*pSurfaceTemp = (m_ppColorInfo[i][j] >> DarkBits) & CDirectDraw::s_wMASK_SHIFT[DarkBits];
			}
			// ������ ������� ���
			else if (m_ppPixelInfo[i][j]==PIXELTYPE_TRANSEND)
			{
				break;
			}



			pSurfaceTemp++;
			j++;
		}

		// ���� ��
		pSurface = (WORD*)((BYTE*)pSurface + Pitch);
	}
}

//----------------------------------------------------------------------
// Merge NormalSprite
//----------------------------------------------------------------------
// n��° Sprite�� Normal Sprite�̹Ƿ� 
// Normal Sprite ������ �о �ܰ��� ������ �߰��Ѵ�.
//----------------------------------------------------------------------
void
CSpriteOutlineManager::MergeNormalSprite( int n )
{
	CSprite*	pSprite = (CSprite*)m_pSprite[n];

	register int i;
	register int j;

	int		count, 
			colorCount;

	WORD	*pPixels;
	BYTE	*pPixelInfoTemp;
	WORD	*pColorInfoTemp;

	int px = m_Position[n].x;
	int py = m_Position[n].y;

	// �� �ٿ� ���ؼ�...
	int height = pSprite->GetHeight();
	for (i=0; i<height; i++)
	{
		// i��° ���� �о���δ�.
		pPixels			= pSprite->GetPixelLine( i );

		// �ܰ��� �������� �� Sprite�� ����� ��ġ..
		pPixelInfoTemp	= m_ppPixelInfo[py] + px;
		pColorInfoTemp	= m_ppColorInfo[py] + px;

		// (�����,�����,�����)�� �ݺ� ��		
		count	= *pPixels++;

 		// �� �� ���
		if (count > 0)
		{
			j = count;
			do {		
				pPixelInfoTemp += *pPixels;			// �������ŭ �ǳ� �ڴ�.
				pColorInfoTemp += *pPixels;			// �������ŭ �ǳ� �ڴ�.
				pPixels ++;	

				colorCount = *pPixels++;		// ���� �ƴ� �� ��				

				// ������ �ƴ� ������ ColorInfo�� �߰�
				memcpy((void*)pColorInfoTemp, (void*)pPixels, colorCount << 1);
				
				// PixelInfo���� �����̶�� ǥ�ø� �صд�.
				memset((void*)pPixelInfoTemp, PIXELTYPE_COLOR, colorCount);
				
				// ����� ����ŭ pointer����
				pPixels			+= colorCount;
				pPixelInfoTemp	+= colorCount;
				pColorInfoTemp	+= colorCount;
			} while (--j);
		} 

		py++;
	}
}


//----------------------------------------------------------------------
// Merge AlphaSprite
//----------------------------------------------------------------------
void
CSpriteOutlineManager::MergeAlphaSprite( int n )
{
	CAlphaSprite*	pSprite = (CAlphaSprite*)m_pSprite[n];

	register int i;
	register int j;
	register int k;

	int		count, 
			colorCount;

	WORD	*pPixels;
	BYTE	*pPixelInfoTemp;
	WORD	*pColorInfoTemp;

	int px = m_Position[n].x;
	int py = m_Position[n].y;

	// �� �ٿ� ���ؼ�...
	int height = pSprite->GetHeight();
	for (i=0; i<height; i++)
	{
		// i��° ���� �о���δ�.
		pPixels			= pSprite->GetPixelLine( i );

		// �ܰ��� �������� �� Sprite�� ����� ��ġ..
		pPixelInfoTemp	= m_ppPixelInfo[py] + px;
		pColorInfoTemp	= m_ppColorInfo[py] + px;

		// (�����,�����,�����)�� �ݺ� ��		
		count	= *pPixels++;

 		// �� �� ���
		if (count > 0)
		{
			j = count;
			do {				
				pPixelInfoTemp += *pPixels;			// �������ŭ �ǳ� �ڴ�.
				pColorInfoTemp += *pPixels;			// �������ŭ �ǳ� �ڴ�.
				pPixels ++;	

				colorCount = *pPixels++;		// ���� �ƴ� �� ��				

				// ������ �ƴ� ������ ColorInfo�� �߰�
				//memcpy((void*)pColorInfoTemp, (void*)pPixels, colorCount << 1);
				for (k=0; k<colorCount; k++)
				{
					*pColorInfoTemp = *pPixels;
					
					pColorInfoTemp++;
					pPixels += 2;
				}
				
				// PixelInfo���� �����̶�� ǥ�ø� �صд�.
				memset((void*)pPixelInfoTemp, PIXELTYPE_COLOR, colorCount);
				
				// ����� ����ŭ pointer����
				//pPixels			+= colorCount;
				//pPixelInfoTemp	+= colorCount;
				pColorInfoTemp	+= colorCount;
			} while (--j);
		}
		
		py++;
	}
}

//----------------------------------------------------------------------
// Merge IndexSprite
//----------------------------------------------------------------------
void
CSpriteOutlineManager::MergeIndexSprite( int n )
{
	CIndexSprite*	pSprite = (CIndexSprite*)m_pSprite[n];

	register int i;
	register int j;
	register int k;

	int		count,
			indexCount,
			colorCount;
	
	BYTE	colorSet,
			colorGradation;

	WORD	*pPixels;
	BYTE	*pPixelInfoTemp;
	WORD	*pColorInfoTemp;

	int px = m_Position[n].x;
	int py = m_Position[n].y;

	// �� �ٿ� ���ؼ�...
	int height = pSprite->GetHeight();
	for (i=0; i<height; i++)
	{
		// i��° ���� �о���δ�.
		pPixels			= pSprite->GetPixelLine( i );

		// �ܰ��� �������� �� Sprite�� ����� ��ġ..
		pPixelInfoTemp	= m_ppPixelInfo[py] + px;
		pColorInfoTemp	= m_ppColorInfo[py] + px;

		// (�����,�����,�����)�� �ݺ� ��		
		count	= *pPixels++;

 		// �� �� ���
		if (count > 0)
		{
			j = count;
			do {				
				pPixelInfoTemp += *pPixels;			// �������ŭ �ǳ� �ڴ�.
				pColorInfoTemp += *pPixels;			// �������ŭ �ǳ� �ڴ�.
				pPixels ++;	

				indexCount = *pPixels++;		// ���� �ƴ� �� ��
				
				// index���� ColorInfo�� �߰�			
				for (k=0; k<indexCount; k++)
				{
					colorSet		= (*pPixels >> 8) & 0xFF;	// set
					colorGradation	= (BYTE)*pPixels;			// gradation
					pPixels++;

					// s_Value�� ���õ� ���� �����ؼ� ����Ѵ�.
					*pColorInfoTemp		= CIndexSprite::ColorSet[m_Value[n][colorSet]][colorGradation];
					pColorInfoTemp ++;
				}

				// Normal ���� ��
				colorCount = *pPixels++;

				// Normal���� ColorInfo�� �߰�
				memcpy((void*)pColorInfoTemp, (void*)pPixels, colorCount << 1);
				
				// PixelInfo���� �����̶�� ǥ�ø� �صд�.
				memset((void*)pPixelInfoTemp, PIXELTYPE_COLOR, indexCount+colorCount);
				
				// ����� ����ŭ pointer����
				pPixels			+= colorCount;			
				pColorInfoTemp	+= colorCount;
				pPixelInfoTemp	+= indexCount + colorCount;
			} while (--j);
		}

		py++;
	}
}

//----------------------------------------------------------------------
// Merge IndexSprite ColorSet
//----------------------------------------------------------------------
// Ư�� ColorSet���� ����Ѵ�.
//----------------------------------------------------------------------
void
CSpriteOutlineManager::MergeIndexSpriteColorSet( int n )
{
	int colorSet = m_ChangeColorSet[n];
	CSpriteSurface::s_Value1 = colorSet;	
	for(int ic = 0; ic < 256; ic++)
	{
		m_Value[n][ic] = 0;
	}

	CIndexSprite*	pSprite = (CIndexSprite*)m_pSprite[n];

	register int i;
	register int j;
	register int k;

	int		count,
			indexCount,
			colorCount;
	
	int	colorGradation;

	WORD	*pPixels;
	BYTE	*pPixelInfoTemp;
	WORD	*pColorInfoTemp;

	int px = m_Position[n].x;
	int py = m_Position[n].y;

	// �� �ٿ� ���ؼ�...
	int height = pSprite->GetHeight();
	for (i=0; i<height; i++)
	{
		// i��° ���� �о���δ�.
		pPixels			= pSprite->GetPixelLine( i );

		// �ܰ��� �������� �� Sprite�� ����� ��ġ..
		pPixelInfoTemp	= m_ppPixelInfo[py] + px;
		pColorInfoTemp	= m_ppColorInfo[py] + px;

		// (�����,�����,�����)�� �ݺ� ��		
		count	= *pPixels++;

 		// �� �� ���
		if (count > 0)
		{
			j = count;
			do {				
				pPixelInfoTemp += *pPixels;			// �������ŭ �ǳ� �ڴ�.
				pColorInfoTemp += *pPixels;			// �������ŭ �ǳ� �ڴ�.
				pPixels ++;	

				indexCount = *pPixels++;		// ���� �ƴ� �� ��
				
				// index���� ColorInfo�� �߰�			
				for (k=0; k<indexCount; k++)
				{
					//colorSet		= (*pPixels >> 8) & 0xFF;	// set
					colorGradation	= (*pPixels & 0xFF);			// gradation
					pPixels++;

					// s_Value�� ���õ� ���� �����ؼ� ����Ѵ�.				
					*pColorInfoTemp		= CIndexSprite::ColorSet[colorSet][colorGradation];
					pColorInfoTemp ++;
				}

				// Normal ���� ��
				colorCount = *pPixels++;

				// Normal���� ColorInfo�� �߰�
				CSpriteSurface::memcpyEffectGradation(pColorInfoTemp, pPixels, colorCount);
				//memcpy((void*)pColorInfoTemp, (void*)pPixels, colorCount << 1);
				
				// PixelInfo���� �����̶�� ǥ�ø� �صд�.
				memset((void*)pPixelInfoTemp, PIXELTYPE_COLOR, indexCount+colorCount);
				
				// ����� ����ŭ pointer����
				pPixels			+= colorCount;			
				pColorInfoTemp	+= colorCount;
				pPixelInfoTemp	+= indexCount + colorCount;
			} while (--j);
		}

		py++;
	}
}
