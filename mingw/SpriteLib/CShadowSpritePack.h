//----------------------------------------------------------------------
// CShadowSpritePack.h
//----------------------------------------------------------------------
// ������(����~~)�� ShadowSprite Image���� �����صΰ� �ʿ��� ����
// ShadowSpriteID�� ���ؼ� �о ����ϰ� �ȴ�.
// ���������� std::map�� �����...����
//
//----------------------------------------------------------------------
// [ Test��� ]
//
// CShadowSpritePack�� 170���� CShadowSprite�� ���� ��,
//
// map  ��� ��  : 43 Frame
// Array ��� �� : 49 Frame
//
// �׷���, map�� �ӵ� ������ ���ؼ� array�� ����ϱ�� �ߴ�. - -;
//
//----------------------------------------------------------------------
// 
// [ ���� ]
//
// CShadowSpritePack sp;
//
// sp.Init( 3 );
//
// sp[0].SetPixel( ... );
// sp[1].SetPixel( ... );
// sp[2].SetPixel( ... );
//
// Surface->CopyShadowSprite( sp[1], ... )
//
//----------------------------------------------------------------------
//
// ShadowSpritePack�� ShadowSprite�� ���� File Pointer Index�� �ʿ��ϴ�.
// ShadowSpriteSet���� �б� ���ؼ�.
//
//----------------------------------------------------------------------

#ifndef	__CSHADOWSPRITEPACK_H__
#define	__CSHADOWSPRITEPACK_H__

#include "DrawTypeDef.h"
#include "CShadowSprite.h"
#include "CIndexSpritePack.h"
#include <list>

class CShadowSpritePack {
	public :
		CShadowSpritePack();
		~CShadowSpritePack();

		//--------------------------------------------------------
		// Init/Release
		//--------------------------------------------------------
		void			Init(TYPE_SPRITEID count);				
		void			Release();
		void			ReleasePart(TYPE_SPRITEID firstShadowSpriteID, TYPE_SPRITEID lastShadowSpriteID);
		void			ReleaseLoaded();

		//--------------------------------------------------------
		// file I/O
		//--------------------------------------------------------
		bool			SaveToFile(ofstream& spkFile, ofstream& indexFile);
		bool			SaveToFileSpriteOnly(ofstream& spkFile, long &filePosition);
		void			LoadFromFile(ifstream& file);		
		void			LoadFromFilePart(ifstream& file, long filePosition,
										 TYPE_SPRITEID firstShadowSpriteID, TYPE_SPRITEID lastShadowSpriteID);
		void			LoadFromFilePart(ifstream& spkFile, const CSpriteFilePositionArray& fpArray);

		//--------------------------------------------------------
		// Convert
		//--------------------------------------------------------
		void			InitPart(CIndexSpritePack& ISPK, TYPE_SPRITEID firstShadowSpriteID, TYPE_SPRITEID lastShadowSpriteID);

		//--------------------------------------------------------
		// size
		//--------------------------------------------------------
		TYPE_SPRITEID	GetSize() const		{ return m_nSprites; }

		//--------------------------------------------------------
		// operator
		//--------------------------------------------------------
		CShadowSprite&		operator [] (TYPE_SPRITEID n) { return m_pSprites[n]; }

	protected :
		TYPE_SPRITEID		m_nSprites;		// CShadowSprite�� ����
		CShadowSprite*		m_pSprites;		// CShadowSprite���� �����صд�.

		INT_LIST		m_listLoad;		// Load�� ShadowSprite�鿡 ���� ID
		
};

#endif


