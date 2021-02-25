//----------------------------------------------------------------------
// CDirect3D.h
//----------------------------------------------------------------------
//
// Texture�� ����� Surface�� �߰��Ǹ� ����(!?) flag
//
//    ddsd.ddsCaps.dwCaps2 |= DDSCAPS2_TEXTUREMANAGE;
//
// �׷���, Hardware������ �Ǵ� ���¿��߸� �Ѵ�.
//----------------------------------------------------------------------
#ifndef	__CDIRECT3D_H__
#define	__CDIRECT3D_H__

#ifndef	D3D_OVERLOADS
#define	D3D_OVERLOADS
#endif

#include <D3D.h>


#include <ddraw.h>

//#include "d3dtextr.h"
//#include "d3dutil.h"

#include "CDirectDraw.h"




class CDirect3D : public CDirectDraw {
	public :
		CDirect3D() {}
		~CDirect3D() {}

		//--------------------------------------------------
		// �ʱ�ȭ
		//--------------------------------------------------
		static bool				Init();
		static void				Release();

		//--------------------------------------------------
		// Restore
		//--------------------------------------------------
		static BOOL				IsLost();
		static void				Restore();

		//--------------------------------------------------
		// Is Support HAL?
		//--------------------------------------------------
		static bool				CheckHAL();

		//--------------------------------------------------
		// Get
		//--------------------------------------------------
		static const LPDIRECT3DDEVICE7	GetDevice() { return m_pD3DD; }
		static bool						IsHAL()		{ return m_bHAL; }

		//--------------------------------------------------
		// Texture ���� ���� ����
		//--------------------------------------------------
		static void		GetTextureSize(int& width, int& height);
		static DWORD	GetTextureWidthMax()	{ return m_TextureWidthMax; }
		static DWORD	GetTextureHeightMax()	{ return m_TextureHeightMax; }

		static bool		IsTexturePow2()			{ return m_bTexturePow2; }
		static bool		IsTextureSquareOnly()	{ return m_bTextureSquareOnly; }

		static const LPDDPIXELFORMAT	GetPixelFormat4444() { return &m_PixelFormat4444; }
		static const LPDDPIXELFORMAT	GetPixelFormat1555() { return &m_PixelFormat1555; }

		//--------------------------------------------------
		// PixelFormat
		//--------------------------------------------------
		static bool				FindBestPixelFormat(int bitsA, int bitsR, int bitsG, int bitsB, 
													LPDDPIXELFORMAT pddpfBestMatch);

		// Device : Texture
		//static void				SetTexture(DWORD dwStage, const char* filename);

	public :
		// 3D Rendering Mode
		/*
		enum CD3DMODE 
		{
			MODE_NULL = 0,
			MODE_HARDWARE,
			MODE_MMX,
			MODE_SOFTWARE
		};
		*/		

	protected :
		static bool				Init(GUID* pDriverGUID, const GUID* pDeviceGUID);
		static bool				CheckDeviceForTexture();

	private :
		static WORD				GetNumberOfBits( DWORD dwMask );
		static HRESULT WINAPI	EnumZBufferCallback(DDPIXELFORMAT* DDP_Format ,VOID* DDP_Desired);
		static HRESULT WINAPI	EnumTextureCallback( DDPIXELFORMAT* pddpf, VOID* );


	protected :
		//CD3DMODE			m_Mode;		// 3D Rendering Mode

		static bool						m_bHAL;

		static LPDIRECT3D7				m_pD3D;
		static LPDIRECT3DDEVICE7		m_pD3DD;
		static LPDIRECTDRAWSURFACE7		m_pDDZBuffer;

		// PixelFormat
	    static DDPIXELFORMAT			m_PixelFormats[100]; // Stores pixel formats
	    static DWORD					m_dwNumPixelFormats;

		//------------------------------------------------------------------
		// Texture ���� ���� ����
		//------------------------------------------------------------------
		// �ϵ��� �����ϴ� Texture�� �ִ� ũ��
		static int						m_TextureWidthMax;
		static int						m_TextureHeightMax;

		static bool						m_bTexturePow2;		// 2^n�� �Ǵ°�?		
		static bool						m_bTextureSquareOnly;	// ���簢���� �Ǵ°�?

	public :
		// PixelFormat
		static DDPIXELFORMAT			m_PixelFormat4444;
		static DDPIXELFORMAT			m_PixelFormat1555;
};

#endif
