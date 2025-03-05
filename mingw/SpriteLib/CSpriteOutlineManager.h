//----------------------------------------------------------------------
// CSpriteOutlineManager.h
//----------------------------------------------------------------------
/*
                    <<<   �ܰ��� ����ϱ�   >>>



	�������� Sprite�� ���ļ� ��µ� ���... 
	Sprite���� �� ��µ� ���� �ܰ����� �����ؾ� �Ѵ�.
	(ĳ���� �� + ����� + ����...)
	SpriteOutlineManager class�� ���� �̿��Ѵ�.


	(���� ����)

	  SpriteOutlineManager SOM;

	  // ����ҷ��� Sprite�� SpriteOutlineManager�� ����Ѵ�.
	  SOM.Add( x0,y0, ĳ���͸� );
	  SOM.Add( x1,y1, ĳ���ͺ���1 );
	  SOM.Add( x2,y2, ĳ���ͺ���2 );
	  SOM.Add( x3,y3, ĳ���͹��� );

	  // ����Ѵ�.
	  SOM.BltOutline( CDirectDrawSurface* );



	(���� ����)

	Add( Sprite* )
	  - Sprite�� ���ļ� ������� ����� ���� ���¿����� 
		Sprite�� ��µ� ������ ũ�⸦ ���ؾ� �ϹǷ�
		Sprite Size�� �о MaximumRect�� ����صд�.
		�� ��, Sprite�� ��µǴ� ��ġ�� �� �������� �Ѵ�. (���� ����)
	  - Sprite List�� Sprite�� �߰��Ѵ�.


	BltOutline( CDirectDrawSurface* )
	  - MaximumRect�� �ܰ��� ������
		����ũ�⺸�� ������� 1 Pixel�� Ŀ���� �Ѵ�.
 
	  - �ܰ����� �����ϱ� ���ؼ���.. 
		������� �������� �ִ� �κ��� �����ؾ� �ϹǷ�
		�� Sprite�� GetPixelInfo( PixelInfo*, ColorInfo* )�� �̿��ؼ�
		SpriteOutlineManager ������ PixelInfo�� Sprite�� �����+������
		������ �����ϰ� ColorInfo���� �� Sprite�� ���� ���� �����Ѵ�.
		PixelInfo���� 0(�����)�� 1(����)�� ���еǰ� ColorInfo����
		���� ���� ���� �ǹ��Ѵ�.
		PixelInfo�� SpriteOutlineManager�� ������ �� 0���� 
		�ʱ�ȭ�ؾ� �Ǹ�, Sprite�� GetPixelInfo������ ����κи� 1��
		�������� �Ѵ�.

	  - ������ PixelInfo�� ColorInfo�� ������ �̿��ؼ�
		Surface�� �ܰ����� �Բ�, ���� ������ ����ؾ� �Ѵ�.

	  - �ϴ� PixelInfo�� 0(����)�� 1(����)�� �˻��ϸ鼭 
		�ܰ��� �κп��� 2(�ܰ�)�� �������ش�.
		���� �ܰ� �˻��� ����� �ϰ�,
		���� �ܰ� �˻��� Add���� ���� ���� �ִ�.
		������, ���� �ܰ� �˻��� Add���� ���� �ʴ� �ٸ�, 
		�� �ܰ迡�� ���η� �˻��ϸ鼭 ������κ� ������ �ؼ�
		��� ���� ��¿��� �� ������ Ȱ���� �� �ִ�.
         
	  - ��� �Ҷ��� PixelInfo�� ���� ����
		���� �κ��� �ǳʶ��,
		�ܰ��� �κ��� �ܰ��� ���� ����ϰ�,
		����κ��� ������ ������ ����Ѵ�.
*/
//----------------------------------------------------------------------


#ifndef	__CSPRITEOUTLINEMANAGER_H__
#define	__CSPRITEOUTLINEMANAGER_H__

// �ܰ����� ����Ҷ� �������� Sprite���� �ִ� ����
#define	MAX_SPRITE_MERGE	20

#include <Windows.h>
class CSprite;
class CAlphaSprite;
class CIndexSprite;

class CSpriteOutlineManager {
	public :
		CSpriteOutlineManager();
		~CSpriteOutlineManager();

		bool		IsInit()	{ return m_nSprite!=0; }

		//--------------------------------------------------------------
		// Clear
		//--------------------------------------------------------------
		void		Clear();		

		//--------------------------------------------------------------
		// Add Sprite
		//--------------------------------------------------------------
		void		Add(int x, int y, CSprite* pSprite);
		void		Add(int x, int y, CIndexSprite* pSprite, WORD colorSet=0xFFFF);
		void		Add(int x, int y, CAlphaSprite* pSprite);

		//--------------------------------------------------------------
		// Generate  : �ܰ��� ������ �����Ѵ�.
		//--------------------------------------------------------------
		void		Generate(int opt = 0);

		//--------------------------------------------------------------
		// Get
		//--------------------------------------------------------------
		// ��� ��ġ
		POINT		GetPosition() const		{ return m_pointOutput; }
		// �ܰ��� ������ ũ��
		int			GetWidth() const		{ return m_Width; }
		int			GetHeight() const		{ return m_Height; }

		//--------------------------------------------------------------
		// Blt  : ȭ�鿡 ����Ѵ�.
		//--------------------------------------------------------------
		void		Blt(WORD* pSurface, WORD Pitch, WORD color);
		void		BltClip(WORD* pSurface, WORD Pitch, WORD color, RECT* pRect);
		void		BltOutline(WORD* pSurface, WORD Pitch, WORD color);
		void		BltOutlineClip(WORD* pSurface, WORD Pitch, WORD color, RECT* pRect);
		void		BltDarkness(WORD* pSurface, WORD Pitch, WORD color, BYTE DarkBits);
		void		BltDarknessClip(WORD* pSurface, WORD Pitch, WORD color, BYTE DarkBits, RECT* pRect);

	public :
		// Sprite�� ����
		enum SPRITETYPE 
		{
			SPRITETYPE_NULL = 0,
			SPRITETYPE_NORMAL,
			SPRITETYPE_ALPHA,
			SPRITETYPE_INDEX
		};

		// �� ���� ����(m_ppPixelInfo���� ���)
		enum PIXELTYPE
		{			
			PIXELTYPE_MAXCOUNT = 0xF0,
			PIXELTYPE_TRANS = 0xFC,
			PIXELTYPE_COLOR = 0xFD,
			PIXELTYPE_OUTLINE = 0xFE,
			PIXELTYPE_TRANSEND = 0xFF
		};
		// 2004, 8, 18 sobeit add start - ������ ���� Ÿ���ö����� �������� �߰�..
		enum GENERATE_OPTION{
			GENERATE_ALL = 0,
			GENERATE_EXCEPT_LEFT,	// ���� �ƿ������� ����
			GENERATE_EXCEPT_RIGHT,  // ������ �ƿ������� ����
			GENERATE_EXCEPT_SIDE,	// �� ���̵� �ƿ������� ����
			// -_- ��,�Ʒ��� ����� ���� �ϳ�..-_-;
		};
		// 2004, 8, 18 sobeit add start
	
	protected :
		//--------------------------------------------------------------
		// Init/Release
		//--------------------------------------------------------------
		void		InitInfo(int width, int height);
		void		ReleaseInfo();

		//--------------------------------------------------------------
		// Sprite�� Pixel������ �ܰ��� ������ �߰�
		//--------------------------------------------------------------
		void		MergeNormalSprite( int n );
		void		MergeAlphaSprite( int n );
		void		MergeIndexSprite( int n );
		void		MergeIndexSpriteColorSet( int n );	// ��ü ������ �ٲ�� IndexSprite


	protected :
		int			m_nSprite;						// ������� Sprite����
		int			m_Type[MAX_SPRITE_MERGE];		// Sprite�� ����		
		POINT		m_Position[MAX_SPRITE_MERGE];	// Sprite�� ����� ��ġ
		WORD		m_ChangeColorSet[MAX_SPRITE_MERGE];	// IndexSprite�� ��ü������ �ٲ��� Set��
		WORD		m_Value[MAX_SPRITE_MERGE][256];		// IndexSprite�� Set��
		void*		m_pSprite[MAX_SPRITE_MERGE];	// Sprite�� ���� pointer

		RECT		m_rectOutline;					// ��ü ����
		POINT		m_pointOutput;					// ��µǴ� ��ġ

		// �ܰ��� ����
		int			m_Width;						// ���� ����
		int			m_Height;						// ���� ����
		BYTE**		m_ppPixelInfo;					// pixel�� ����
		WORD**		m_ppColorInfo;					// pixel�� ����
};

#endif

