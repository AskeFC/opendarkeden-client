//----------------------------------------------------------------------
// CAlphaSpritePackList565.cpp
//----------------------------------------------------------------------

#include "CAlphaSprite565.h"
#include "CAlphaSpritePackList.h"
#include "CAlphaSpritePackList565.h"
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
CAlphaSpritePackList565::LoadFromFile(ifstream& file)
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
		pSprite = new CAlphaSprite565;

		pSprite->LoadFromFile(file);	// Sprite �о����

		// List�� �߰�
		AddSprite(pSprite);
	}
}

