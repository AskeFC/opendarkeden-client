//----------------------------------------------------------------------
// CSprite555.h
//----------------------------------------------------------------------
// 5:5:5 video card�� ���� sprite class
//----------------------------------------------------------------------

#ifndef	__CSPRITE555_H__
#define	__CSPRITE555_H__

#include <Windows.h>
class ofstream;
class ifstream;


#include "CSprite.h"


class CSprite555 : public CSprite {
	public :
		//---------------------------------------------------------
		// fstream���� save/load�� �Ѵ�.
		//---------------------------------------------------------
		bool		SaveToFile(class ofstream& file);
		bool		LoadFromFile(class ifstream& file);
		//bool		LoadFromFileToBuffer(ifstream& file);

};


#endif



