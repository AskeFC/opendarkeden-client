//----------------------------------------------------------------------
// CSpritePackList565.cpp
//----------------------------------------------------------------------

#include "CSprite565.h"
#include "CSpritePackList.h"
#include "CSpritePackList565.h"
#include <fstream.h>


//----------------------------------------------------------------------
//
// member functions
//
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Load From File
//----------------------------------------------------------------------
// file���� ID�� Sprite�� �о�ͼ� list �ϳ��� �����Ѵ�.
//----------------------------------------------------------------------
void		
CSpritePackList565::LoadFromFile(ifstream& file)
{
	// memory���� list����
	Release();

	// file���� sprite ������ �о�´�.	
	TYPE_SPRITEID size;
	file.read((char*)&size, SIZE_SPRITEID);


	CSprite* pSprite;

	// file�� �ִ� Sprite���� Load	
	for (TYPE_SPRITEID i=0; i<size; i++)	
	{			
		// �޸� ���
		pSprite = new CSprite565;

		pSprite->LoadFromFile(file);	// Sprite �о����

		// List�� �߰�
		AddSprite(pSprite);
	}
}

