//----------------------------------------------------------------------
// CFilterPack.h
//----------------------------------------------------------------------
//
// FilterPack�� Filter�� ���� File Pointer Index�� �ʿ��ϴ�.
// FilterSet���� �б� ���ؼ�.
//
//----------------------------------------------------------------------

#ifndef	__CFILTERPACK_H__
#define	__CFILTERPACK_H__

#include "DrawTypeDef.h"
#include "CFilter.h"

class CFilterPack {
	public :
		CFilterPack();
		~CFilterPack();

		//--------------------------------------------------------
		// Init/Release
		//--------------------------------------------------------
		void		Init(TYPE_FILTERID count);		
		void		Release();		
		
		//--------------------------------------------------------
		// file I/O
		//--------------------------------------------------------
		void		SaveToFile(ofstream& file);
		void		LoadFromFile(ifstream& file);		
		
		//--------------------------------------------------------
		// size
		//--------------------------------------------------------
		TYPE_FILTERID	GetSize() const		{ return m_nFilters; }

		//--------------------------------------------------------
		// operator
		//--------------------------------------------------------
		CFilter&	operator [] (TYPE_FILTERID n) { return m_pFilters[n]; }

	protected :
		TYPE_FILTERID		m_nFilters;		// CFilter�� ����
		CFilter*			m_pFilters;		// CFilter���� �����صд�.
};

#endif
	