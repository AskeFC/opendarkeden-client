//----------------------------------------------------------------------
// CAlphaSpritePackList555.cpp
//----------------------------------------------------------------------

#include "CAlphaSprite555.h"
#include "CAlphaSpritePackList.h"
#include "CAlphaSpritePackList555.h"
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
CAlphaSpritePackList555::LoadFromFile(ifstream& file)
{
	// memory���� list����
	Release();

	// file���� sprite ������ �о�´�.	
	TYPE_SPRITEID size;
	file.read((char*)&size, SIZE_SPRITEID);


	CAlphaSprite* pSprite;

	// file�� �ִ� Sprite���� Load	
	for (TYPE_SPRITEID i=0; i<size; i++)	
	{			
		// �޸� ���
		pSprite = new CAlphaSprite555;

		pSprite->LoadFromFile(file);	// Sprite �о����

		// List�� �߰�
		AddSprite(pSprite);
	}
}

