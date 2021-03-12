//----------------------------------------------------------------------
// CIndexSpritePack.h
//----------------------------------------------------------------------
//
// SpritePack�� Sprite�� ���� File Pointer Index�� �ʿ��ϴ�.
// SpriteSet���� �б� ���ؼ�.
//
//----------------------------------------------------------------------

#ifndef	__CINDEXSPRITEPACK_H__
#define	__CINDEXSPRITEPACK_H__

#include "CIndexSprite555.h"
#include "CIndexSprite565.h"
#include "CTypePack.h"

typedef CTypePack2<CIndexSprite, CIndexSprite555, CIndexSprite565> CIndexSpritePack;

//class CIndexSpritePack : public CTypePack<CIndexSprite>
//{
//public:
//	//--------------------------------------------------------
//	// Init/Release
//	//--------------------------------------------------------
//	void	Init(WORD size, bool b565 = true);
//	
//	//--------------------------------------------------------
//	// file I/O
//	//--------------------------------------------------------
//	bool LoadFromFile(ifstream &file, bool b565 = true);
//	bool LoadFromFile(LPCTSTR lpszFilename, bool b565 = true);
//	bool LoadFromFileRunning(LPCTSTR lpszFilename, bool b565 = true);
//	
//protected:
//	bool			m_b565;
//};

#endif


