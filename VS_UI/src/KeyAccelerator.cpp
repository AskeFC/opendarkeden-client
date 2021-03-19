//----------------------------------------------------------------------
// KeyAccelerator.cpp
//----------------------------------------------------------------------

#include "client_PCH.h"
#include <fstream>
#include "KeyAccelerator.h"
#include "CDirectInput.h"
//----------------------------------------------------------------------
// define functions
//----------------------------------------------------------------------
#define READ_CHECK_EOF( value, temp, bytes )		\
		{											\
			file.read((char*)&temp, bytes);			\
			if (!file.eof())						\
			{										\
				value = temp;						\
				return false;						\
			}										\
			else									\
			{										\
				return true;						\
			}										\
		}
//----------------------------------------------------------------------
// Global
//----------------------------------------------------------------------
KeyAccelerator*		g_pKeyAccelerator = NULL;

//----------------------------------------------------------------------
//
// constructor / destructor
//
//----------------------------------------------------------------------
KeyAccelerator::KeyAccelerator()
{
}

KeyAccelerator::~KeyAccelerator()
{
}

//----------------------------------------------------------------------
// Init ( max )
//----------------------------------------------------------------------
void				
KeyAccelerator::Init( int max )
{
	m_Keys.clear();
	m_Accelerators.clear();

	m_Accelerators.reserve( max );
}

//----------------------------------------------------------------------
// Set AcceleratorKey ( accel, key )
//----------------------------------------------------------------------
// key�� ������ accel�� ����ȴ�..�� �ǹ�.
// accel�� key�� ����Ǿ��ִ�..�� �ǹ̵� �ǰ�..
//----------------------------------------------------------------------
void				
KeyAccelerator::SetAcceleratorKey(BYTE accel, WORD key)
{
	if (accel >= m_Accelerators.capacity())
	{
		return;
	}

	KEY_MAP::iterator iKey = m_Keys.find( m_Accelerators[accel] );

	if (iKey != m_Keys.end())
	{
		// �̹� ������ key�� �־��ٸ� �����Ѵ�.
		m_Keys.erase( iKey );
	}

	m_Keys[key] = accel;
	
	m_Accelerators[accel] = key;
}

//----------------------------------------------------------------------
// Get Accelerator ( key )
//----------------------------------------------------------------------
// Ȯ���� �� key�� �Էµ� ���
//----------------------------------------------------------------------
BYTE
KeyAccelerator::GetAccelerator(WORD key) const
{
	KEY_MAP::const_iterator iKey = m_Keys.find( key );

	if (iKey==m_Keys.end())
	{
		return 0;
	}

	return iKey->second;
}

//----------------------------------------------------------------------
// Get AcceleratorSimilar ( key )
//----------------------------------------------------------------------
// ctrl+I�� ������ ����Ǵ°�
// ctrl+shift+I�� ������ ������ �ȵȴ�.
// �̷� ��쿡�� ����ǰ� �ҷ���.. ����Ű�� ����ؼ� üũ�ؾ� �Ѵ�.
//----------------------------------------------------------------------
BYTE				
KeyAccelerator::GetAcceleratorSimilar(WORD key) const
{
	// �Էµ� key
	KEY_MAP::const_iterator iKey = m_Keys.find( key );

	if (iKey!=m_Keys.end())
	{
		return iKey->second;
	}

	WORD checkKey;	

	int bHasControl	= ACCEL_HAS_CONTROL(key);
	int bHasAlt		= ACCEL_HAS_ALT(key);
	int bHasShift	= ACCEL_HAS_SHIFT(key);

	//------------------------------------------------------------
	// ���� key�� ���� ���
	//------------------------------------------------------------
//	if (!bHasControl && !bHasAlt && !bHasShift)
//	{
//		return 0;
//	}

	//------------------------------------------------------------
	// ctrl����
	//------------------------------------------------------------
	if (bHasControl)
	{
		checkKey = ACCEL_REMOVE_CONTROL( key );
		iKey = m_Keys.find( checkKey );
		if (iKey!=m_Keys.end())	return iKey->second;
	}

	//------------------------------------------------------------
	// alt����
	//------------------------------------------------------------
	if (bHasAlt)
	{
		checkKey = ACCEL_REMOVE_ALT( key );
		iKey = m_Keys.find( checkKey );
		if (iKey!=m_Keys.end())	return iKey->second;
	}

	//------------------------------------------------------------
	// shift����
	//------------------------------------------------------------
	if (bHasShift)
	{
		checkKey = ACCEL_REMOVE_SHIFT( key );
		iKey = m_Keys.find( checkKey );
		if (iKey!=m_Keys.end())	return iKey->second;
	}

	WORD keyOnly = ACCEL_GET_KEY( key );

	//------------------------------------------------------------
	// ctrl + alt + shift �� ���
	//------------------------------------------------------------
	if (bHasControl && bHasAlt && bHasShift)
	{
		//------------------------------------------------------------
		// ctrl�� �����.
		//------------------------------------------------------------
		checkKey = ACCEL_ADD_CONTROL( keyOnly );
		iKey = m_Keys.find( checkKey );
		if (iKey!=m_Keys.end())	return iKey->second;	

		//------------------------------------------------------------
		// alt�� �����
		//------------------------------------------------------------
		checkKey = ACCEL_ADD_ALT( keyOnly );
		iKey = m_Keys.find( checkKey );
		if (iKey!=m_Keys.end())	return iKey->second;		

		//------------------------------------------------------------
		// shift�� �����
		//------------------------------------------------------------
		checkKey = ACCEL_ADD_SHIFT( keyOnly );
		iKey = m_Keys.find( checkKey );
		if (iKey!=m_Keys.end())	return iKey->second;
	}

	//------------------------------------------------------------
	// �� ������ ���
	//------------------------------------------------------------
	iKey = m_Keys.find( keyOnly );
	if (iKey!=m_Keys.end())	return iKey->second;

	return 0;
}

//----------------------------------------------------------------------
// Get Key ( accel )
//----------------------------------------------------------------------
WORD
KeyAccelerator::GetKey(BYTE accel) const
{
	if (accel < m_Accelerators.capacity())
	{	
		return m_Accelerators[accel];
	}

	return 0;
}

//----------------------------------------------------------------------
// Save To File
//----------------------------------------------------------------------
void				
KeyAccelerator::SaveToFile(ofstream& file)
{
	int num = m_Accelerators.capacity();

	file.write((const char*)&num, 4);

	// key-accelerator�� ���踸 �����ϸ� �ȴ�.
	// �ٵ� accel�� ��������̱� ����.. ������ �ʿ����.
	// �׷��� key�� �����ϸ� �ȴ�.
	for (int accel=1; accel<num; accel++)
	{
		WORD key = m_Accelerators[accel];

		file.write((const char*)&key, 2);
	}
}

//----------------------------------------------------------------------
// Load From File
//----------------------------------------------------------------------
void				
KeyAccelerator::LoadFromFile(ifstream& file)
{
	int num;
	file.read((char*)&num, 4);

	Init( num );

	WORD key;

	for (int accel=1; accel<num; accel++)
	{
		file.read((char*)&key, 2);

		if(!file.eof())
			SetAcceleratorKey( accel , key );
	}
}
