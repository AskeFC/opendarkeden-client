//----------------------------------------------------------------------
// CShadowSpritePack.cpp
//----------------------------------------------------------------------

#include "CSpriteSurface.h"
#include "CShadowSprite.h"
#include "CShadowSpritePack.h"
#include <fstream>

//----------------------------------------------------------------------
//
// constructor/destructor
//
//----------------------------------------------------------------------

CShadowSpritePack::CShadowSpritePack()
{
	m_nSprites = 0;
	m_pSprites = NULL;
}

CShadowSpritePack::~CShadowSpritePack()
{
	// array�� �޸𸮿��� �����Ѵ�.
	Release();
	
	m_listLoad.clear();
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
CShadowSpritePack::Init(TYPE_SPRITEID count)
{
	// ������ ���� ��� 
	if (count==0) 
		return;

	// �ϴ� ����
	Release();

	// �޸� ���
	m_nSprites = count;

	m_pSprites = new CShadowSprite [m_nSprites];
}


//----------------------------------------------------------------------
// Release
//----------------------------------------------------------------------
void
CShadowSpritePack::Release()
{
	if (m_pSprites != NULL)
	{
		// ��� CShadowSprite�� �����.
		delete [] m_pSprites;
		m_pSprites = NULL;
		
		m_nSprites = 0;

		m_listLoad.clear();
	}
}

//----------------------------------------------------------------------
// Release Part
//----------------------------------------------------------------------
// firstSpriteID ~ lastSpriteID������ �޸𸮿��� �����Ѵ�.
//----------------------------------------------------------------------
void			
CShadowSpritePack::ReleasePart(TYPE_SPRITEID firstSpriteID, TYPE_SPRITEID lastSpriteID)
{
	// SpritePack�� memory�� �������� ������ �׳� return�Ѵ�.	
	if (m_pSprites==NULL
		|| firstSpriteID >= m_nSprites)
		return;

	int last = min(lastSpriteID, m_nSprites-1);

	for (TYPE_SPRITEID id=firstSpriteID; id<=last; id++)
	{
		m_pSprites[id].Release();

		// m_listLoad������ ������ �ϴµ�,
		// ���� �� �־... ����. - -;;		
	}
}

//----------------------------------------------------------------------
// Release Loaded
//----------------------------------------------------------------------
// m_listLoad���� ���� Load�� SpriteID�� �ִ�.
// �̰Ÿ� ��� Release����� �Ѵ�.
//----------------------------------------------------------------------
void
CShadowSpritePack::ReleaseLoaded()
{
	INT_LIST::iterator iID = m_listLoad.begin();

	while (iID != m_listLoad.end())
	{
		m_pSprites[*iID].Release();

		iID ++;
	}

	m_listLoad.clear();
}

//----------------------------------------------------------------------
// Save To File
//----------------------------------------------------------------------
// map ��ü�� ���󰡸鼭 file�� �����ؾ��Ѵ�.
//----------------------------------------------------------------------
bool		
CShadowSpritePack::SaveToFile(ofstream& spkFile, ofstream& indexFile)
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
		// CShadowSprite ���������� ���̸� �����ϹǷ� 
		// ������ Load�� �� ������ ���� ���̴�.

		m_pSprites[i].SaveToFile(spkFile);		// CShadowSprite����	
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
CShadowSpritePack::SaveToFileSpriteOnly(ofstream& spkFile, long &filePosition)
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
		// CShadowSprite ���������� ���̸� �����ϹǷ� 
		// ������ Load�� �� ������ ���� ���̴�.

		m_pSprites[i].SaveToFile(spkFile);		// CShadowSprite����	
	}

	return true;
}

//----------------------------------------------------------------------
// Load From File
//----------------------------------------------------------------------
// file���� ID�� Sprite�� �о�ͼ� �ϳ��� �����Ѵ�.
//----------------------------------------------------------------------
void
CShadowSpritePack::LoadFromFile(ifstream& file)
{
	// memory���� map����
	Release();

	// file���� sprite ������ �о�´�.	
	file.read((char*)&m_nSprites, SIZE_SPRITEID);

	// memory��´�.
	Init(m_nSprites);

	// file�� �ִ� Sprite���� Load	
	for (TYPE_SPRITEID i=0; i<m_nSprites; i++)
	{			
		m_pSprites[i].LoadFromFile(file);	// Sprite �о����

		// load�� �͵��� list�� �����Ѵ�. (�̰Ŵ� �ʿ�����ŵ� ������..)
		//m_listLoad.push_back( id );
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
CShadowSpritePack::LoadFromFilePart(ifstream& file, long filePosition,
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
		m_pSprites[id].LoadFromFile( file );

		// load�� sprite list�� ���.
		m_listLoad.push_back( id );
	}
}

//----------------------------------------------------------------------
// Load From File Part
//----------------------------------------------------------------------
// file���� �Ϻ��� Sprite�鸸 �о���δ�.
// 
// fpArray�� (SpriteID, FilePosition)�� �̿��ؼ�
// SpriteID�� Sprite�� FilePosition���� �о���δ�.
//
//----------------------------------------------------------------------
void			
CShadowSpritePack::LoadFromFilePart(ifstream& spkFile, const CSpriteFilePositionArray& fpArray)
{
	// SpritePack�� memory�� �������� ������ �׳� return�Ѵ�.	
	if (m_pSprites==NULL)
		return;

	for (int i=0; i<fpArray.GetSize(); i++)
	{
		// Load�ҷ��� ��ġ���� FilePosition�� �̵��Ѵ�.
		spkFile.seekg( fpArray[i].FilePosition, ios::beg );

		// Sprite�� Load�Ѵ�.
		m_pSprites[fpArray[i].SpriteID].LoadFromFile( spkFile );

		// load�� sprite list�� ���.
		m_listLoad.push_back( fpArray[i].SpriteID );
	}
}

//----------------------------------------------------------------------
// Init( IndexSpritepack )
//----------------------------------------------------------------------
// IndexSpritePack --> ShadowSpritePack
//----------------------------------------------------------------------
void			
CShadowSpritePack::InitPart(CIndexSpritePack& ISPK, TYPE_SPRITEID firstShadowSpriteID, TYPE_SPRITEID lastShadowSpriteID)
{
	// ��� IndexSprite�� �̿��ؼ� ShadowSprite�� �����.
	for (int i=firstShadowSpriteID; i<lastShadowSpriteID; i++)
	{
		m_pSprites[i].SetPixel( ISPK[i] );
	}
}
