//----------------------------------------------------------------------
// CAlphaSprite565.h
//----------------------------------------------------------------------
// 5:6:5 video card�� ���� sprite class
//----------------------------------------------------------------------

#ifndef	__CALPHASPRITE565_H__
#define	__CALPHASPRITE565_H__

#include <Windows.h>


#include "CAlphaSprite.h"


class CAlphaSprite565 : public CAlphaSprite {
	public :
		//---------------------------------------------------------
		// fstream���� save/load�� �Ѵ�.
		//---------------------------------------------------------
		bool		SaveToFile(ofstream& file);
		bool		LoadFromFile(ifstream& file);
		//bool	LoadFromFileToBuffer(ifstream& file);
};


#endif



