//----------------------------------------------------------------------
// CAlphaSprite555.h
//----------------------------------------------------------------------
// 5:5:5 video card�� ���� sprite class
//----------------------------------------------------------------------

#ifndef	__CALPHASPRITE555_H__
#define	__CALPHASPRITE555_H__

#include <Windows.h>
class ofstream;
class ifstream;


#include "CAlphaSprite.h"


class CAlphaSprite555 : public CAlphaSprite {
	public :
	
		//---------------------------------------------------------
		// fstream���� save/load�� �Ѵ�.
		//---------------------------------------------------------
		bool		SaveToFile(class ofstream& file);
		bool		LoadFromFile(class ifstream& file);
};


#endif



