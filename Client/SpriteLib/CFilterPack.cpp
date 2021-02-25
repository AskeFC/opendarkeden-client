//----------------------------------------------------------------------
// CFilterPack.cpp
//----------------------------------------------------------------------

#include "CFilter.h"
#include "CFilterPack.h"
#include <fstream.h>

//----------------------------------------------------------------------
//
// constructor/destructor
//
//----------------------------------------------------------------------

CFilterPack::CFilterPack()
{
	m_nFilters = 0;
	m_pFilters = NULL;
}

CFilterPack::~CFilterPack()
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
CFilterPack::Init(TYPE_FILTERID count)
{
	// ������ ���� ��� 
	if (count==0) 
		return;

	// �ϴ� ����
	Release();

	// �޸� ���
	m_nFilters = count;

	m_pFilters = new CFilter [m_nFilters];
}


//----------------------------------------------------------------------
// Release
//----------------------------------------------------------------------
void
CFilterPack::Release()
{
	if (m_pFilters != NULL)
	{
		// ��� CFilter�� �����.
		delete [] m_pFilters;
		m_pFilters = NULL;
		
		m_nFilters = 0;
	}
}

//----------------------------------------------------------------------
// Save To File
//----------------------------------------------------------------------
void
CFilterPack::SaveToFile(ofstream& file)
{
	// ���� ����
	file.write((const char*)&m_nFilters, SIZE_FILTERID);

	// ����� ���� ������ return
	if (m_nFilters==0 || m_pFilters==NULL)
		return;

	// ������ Filter�� File�� �����Ѵ�.
	for (TYPE_FILTERID i=0; i<m_nFilters; i++)
	{
		m_pFilters[i].SaveToFile( file );
	}
}

//----------------------------------------------------------------------
// Load From File
//----------------------------------------------------------------------
void		
CFilterPack::LoadFromFile(ifstream& file)
{
	// ���� �о����
	file.read((char*)&m_nFilters, SIZE_FILTERID);

	// ������ return
	if (m_nFilters==0)
		return;

	// memory���
	Init( m_nFilters );

	// ������ Filter�� Load�� �´�.
	for (TYPE_FILTERID i=0; i<m_nFilters; i++)
	{
		m_pFilters[i].LoadFromFile( file );
	}
}
