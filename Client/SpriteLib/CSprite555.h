//----------------------------------------------------------------------
// CSprite555.h
//----------------------------------------------------------------------
// 5:5:5 video card�� ���� sprite class
//----------------------------------------------------------------------

#ifndef	__CSPRITE555_H__
#define	__CSPRITE555_H__

#include <Windows.h>

#include "CSprite.h"


class CSprite555 : public CSprite {
	public :
		//---------------------------------------------------------
		// fstream���� save/load�� �Ѵ�.
		//---------------------------------------------------------
		bool		SaveToFile(ofstream& file);
		bool		LoadFromFile(ifstream& file);
		//bool		LoadFromFileToBuffer(ifstream& file);

};


#endif



