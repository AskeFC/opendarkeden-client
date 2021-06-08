//----------------------------------------------------------------------
// CSpriteDef.h
//----------------------------------------------------------------------
#ifndef	__CSPRITEDEF_H__
#define	__CSPRITEDEF_H__

#pragma warning(disable:4786)

#include <list>
#include "DrawTypeDef.h"
#include "TArray.h"
class ifstream;
class ofstream;

// int list
typedef	std::list<int>	INT_LIST;

//----------------------------------------------------------------------
// (SpriteID, FilePosition)�� List�� �޾Ƽ� Load�Ѵ�.
//----------------------------------------------------------------------
class SPRITE_FILEPOSITION_NODE
{
	public :
		TYPE_SPRITEID		SpriteID;
		long				FilePosition;

	public :
		void		SaveToFile(class ofstream& file);
		void		LoadFromFile(class ifstream& file);

};

//----------------------------------------------------------------------
// FilePosition Array ����
//----------------------------------------------------------------------
typedef	TArray<SPRITE_FILEPOSITION_NODE, TYPE_SPRITEID>	CSpriteFilePositionArray;



#endif
