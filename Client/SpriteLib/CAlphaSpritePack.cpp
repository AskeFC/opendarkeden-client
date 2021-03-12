//----------------------------------------------------------------------
// CAlphaSpritePack.cpp
//----------------------------------------------------------------------

#include "CSpriteSurface.h"
#include "CAlphaSprite555.h"
#include "CAlphaSprite565.h"
#include "CAlphaSpritePack.h"
#include <fstream.h>

//----------------------------------------------------------------------
//
// constructor/destructor
//
//----------------------------------------------------------------------

CAlphaSpritePack::CAlphaSpritePack()
{
	m_nSprites = 0;
	m_pSprites = NULL;
}

CAlphaSpritePack::~CAlphaSpritePack()
{
	// array�� �޸𸮿��� �����Ѵ�.
	Release();
}

//----------------------------------------------------------------------
//
// member functions
//
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Init
//----------------------------------------------------------------------
void
CAlphaSpritePack::Init(TYPE_SPRITEID count, bool b565)
{
	// ������ ���� ��� 
	if (count==0) 
		return;

	// �ϴ� ����
	Release();

	// �޸� ���
	m_nSprites = count;

	if (b565)
	{
		m_pSprites = new CAlphaSprite565 [m_nSprites];
	}
	else
	{
		m_pSprites = new CAlphaSprite555 [m_nSprites];
	}
}


//----------------------------------------------------------------------
// Release
//----------------------------------------------------------------------
void
CAlphaSpritePack::Release()
{
	if (m_pSprites != NULL)
	{
		// ��� CAlphaSprite�� �����.
		delete [] m_pSprites;
		m_pSprites = NULL;
		
		m_nSprites = 0;
	}
}

//----------------------------------------------------------------------
// Release Part
//----------------------------------------------------------------------
// firstSpriteID ~ lastSpriteID������ �޸𸮿��� �����Ѵ�.
//----------------------------------------------------------------------
void			
CAlphaSpritePack::ReleasePart(TYPE_SPRITEID firstSpriteID, TYPE_SPRITEID lastSpriteID)
{
	// SpritePack�� memory�� �������� ������ �׳� return�Ѵ�.	
	if (m_pSprites==NULL
		|| firstSpriteID >= m_nSprites)
		return;

	int last = min(lastSpriteID, m_nSprites-1);

	for (int id=firstSpriteID; id<=last; id++)
	{
		m_pSprites[id].Release();
	}
}

//----------------------------------------------------------------------
// Save To File
//----------------------------------------------------------------------
// map ��ü�� ���󰡸鼭 file�� �����ؾ��Ѵ�.
//----------------------------------------------------------------------
bool		
CAlphaSpritePack::SaveToFile(ofstream& spkFile, ofstream& indexFile)
{
	// �ʱ�ȭ���� �ʾ����� 
	if (m_nSprites==0 || m_pSprites==NULL)
		return false;
	
	//--------------------------------------------------
	// index file�� �����ϱ� ���� ����
	//--------------------------------------------------
	long*	pIndex = new long [m_nSprites];


	//--------------------------------------------------
	// Size ����
	//--------------------------------------------------
	spkFile.write((const char *)&m_nSprites, SIZE_SPRITEID); 
	indexFile.write((const char *)&m_nSprites, SIZE_SPRITEID); 

	//--------------------------------------------------
	//
	// SpritePack�� Array�� ��� Sprite�� �����Ѵ�.
	//
	//--------------------------------------------------
	for (TYPE_SPRITEID i=0; i<m_nSprites; i++)
	{
		// SpritePack file�� �������� index�� ����
		pIndex[i] = spkFile.tellp();

		// m_pSprites[i]�� ����� pixel�� ���
		// CAlphaSprite ���������� ���̸� �����ϹǷ� 
		// ������ Load�� �� ������ ���� ���̴�.

		m_pSprites[i].SaveToFile(spkFile);		// CAlphaSprite����	
	}

	//--------------------------------------------------
	// index ����
	//--------------------------------------------------
	for (i=0; i<m_nSprites; i++)
	{
		indexFile.write((const char*)&pIndex[i], 4);
	}

	delete [] pIndex;

	return true;
}

//----------------------------------------------------------------------
// Save To File
//----------------------------------------------------------------------
// map ��ü�� ���󰡸鼭 file�� �����ؾ��Ѵ�.
//----------------------------------------------------------------------
bool
CAlphaSpritePack::SaveToFileSpriteOnly(ofstream& spkFile, long &filePosition)
{
	// �ʱ�ȭ���� �ʾ����� 
	if (m_nSprites==0 || m_pSprites==NULL)
		return false;

	// SpritePack file�� �������� index�� ����
	filePosition = spkFile.tellp();
	
	//--------------------------------------------------
	//
	// SpritePack�� Array�� ��� Sprite�� �����Ѵ�.
	//
	//--------------------------------------------------
	for (TYPE_SPRITEID i=0; i<m_nSprites; i++)
	{
		// m_pSprites[i]�� ����� pixel�� ���
		// CSprite ���������� ���̸� �����ϹǷ� 
		// ������ Load�� �� ������ ���� ���̴�.

		m_pSprites[i].SaveToFile(spkFile);		// CSprite����	
	}

	return true;
}

//----------------------------------------------------------------------
// Load From File
//----------------------------------------------------------------------
// file���� ID�� Sprite�� �о�ͼ� map�� �ϳ��� �����Ѵ�.
//----------------------------------------------------------------------
void
CAlphaSpritePack::LoadFromFile(ifstream& file)
{
	// memory���� map����
	Release();

	// file���� sprite ������ �о�´�.	
	file.read((char*)&m_nSprites, SIZE_SPRITEID);

	// memory��´�.
	Init(m_nSprites, CDirectDraw::Is565());

	// file�� �ִ� Sprite���� Load	
	for (TYPE_SPRITEID i=0; i<m_nSprites; i++)
	{			
		m_pSprites[i].LoadFromFile(file);	// Sprite �о����
	}
}


//----------------------------------------------------------------------
// Load From File Part
//----------------------------------------------------------------------
// file���� �Ϻ��� Sprite�鸸 �о���δ�.
// 
// file�� filePosition�������� �о���̰�..
// FirstSpriteID���� SpriteSize����ŭ�� �о���δ�.
//----------------------------------------------------------------------
void			
CAlphaSpritePack::LoadFromFilePart(ifstream& file, long filePosition,
							  TYPE_SPRITEID firstSpriteID, TYPE_SPRITEID lastSpriteID)
{
	if (firstSpriteID==SPRITEID_NULL || lastSpriteID==SPRITEID_NULL)
		return;

	// SpritePack�� memory�� �������� ������ �׳� return�Ѵ�.	
	if (m_pSprites==NULL)
		return;

	// Load�ҷ��� ��ġ���� FilePosition�� �̵��Ѵ�.
	file.seekg( filePosition, ios::beg );

	// firstSpriteID ~ lastSpriteID������ Sprite�� Load�Ѵ�.
	for (TYPE_SPRITEID id=firstSpriteID; id<=lastSpriteID; id++)
	{
		// ���� Load���� ���� ��쿡�� Load�Ѵ�.
		//if (m_pSprites[id].IsInit())
		//	continue;
		// file position�� �̵�������� �ϹǷ� ������ loading�ؾ� �Ѵ�.

		m_pSprites[id].LoadFromFile( file );
	}
}

//----------------------------------------------------------------------
// LoadFromFile Sprite
//----------------------------------------------------------------------
// indexFile�� �̿��ؼ� spkFile���� spriteID��° sprite�� �о�´�.
//----------------------------------------------------------------------
bool
CAlphaSpritePack::LoadFromFileSprite(int spriteID, int fileSpriteID, ifstream& spkFile, ifstream& indexFile)
{
	if (spriteID < 0 || spriteID >= m_nSprites)
	{
		return false;
	}

	//-------------------------------------------------------------------
	// index�� ������ üũ�Ѵ�. fileSpriteID�� �ִ���..?
	//-------------------------------------------------------------------
	TYPE_SPRITEID num;
	indexFile.read((char*)&num, SIZE_SPRITEID);

	if (fileSpriteID >= num)
	{
		return false;
	}

	//-------------------------------------------------------------------
	// load�� sprite�� file pointer�� �д´�.
	//-------------------------------------------------------------------
	long fp;	
	indexFile.seekg( 2 + fileSpriteID*4 );		// 2(num) + spriteID * (4 bytes)
	indexFile.read((char*)&fp, 4);

	//-------------------------------------------------------------------
	// minimap sprite loading
	//-------------------------------------------------------------------
	spkFile.seekg( fp );	

	m_pSprites[spriteID].LoadFromFile( spkFile );

	return true;
}

//----------------------------------------------------------------------
// LoadFromFile Sprite
//----------------------------------------------------------------------
// indexFile�� �̿��ؼ� spkFile���� spriteID��° sprite�� �о�´�.
//----------------------------------------------------------------------
bool
CAlphaSpritePack::LoadFromFileSprite(int spriteID, int fileSpriteID, const char* spkFilename, const char* indexFilename)
{
	if (spriteID < 0 || spriteID >= m_nSprites)
	{
		return false;
	}

	ifstream spkFile(spkFilename, ios::binary | ios::nocreate);

	if (!spkFile.is_open())
	{
		return false;
	}

	ifstream indexFile(indexFilename, ios::binary | ios::nocreate);

	if (!indexFile.is_open())
	{
		return false;
	}

	return LoadFromFileSprite( spriteID, fileSpriteID, spkFile, indexFile );
}