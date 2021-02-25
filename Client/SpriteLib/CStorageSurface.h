//----------------------------------------------------------------------
// CStorageSurface.h
//----------------------------------------------------------------------
// Surface�� �Ϻκ��� ����ϰ� �ִٰ� 
// �ʿ��Ѷ��� �ٽ� ���� ������ �������Ѽ� ����� �� �ְ� �Ѵ�.
//----------------------------------------------------------------------

#ifndef	__CSTORAGESURFACE_H__
#define	__CSTORAGESURFACE_H__


#pragma warning(disable:4786)


#include <Windows.h>
class CDirectDrawSurface;


class CStorageSurface {
	public :
		CStorageSurface();
		~CStorageSurface();

		//--------------------------------------------------------
		// Init / Release
		//--------------------------------------------------------
		// (Surface����, width, height)
		void					Init(int size, int width, int height);
		void					Release();

		//--------------------------------------------------------
		// Store / Restore		
		//--------------------------------------------------------
		void					Store(int i, CDirectDrawSurface* pSurface, POINT* pPoint);
		void					Restore(int i, CDirectDrawSurface* pSurface, POINT* pPoint=NULL) const;

		//--------------------------------------------------------
		// Get
		//--------------------------------------------------------
		int						GetSize() const		{ return m_Size; }

	protected :
		int						m_Size;				// surface����
		POINT*					m_pPoint;			// surface�� ���� ��ġ
		CDirectDrawSurface*		m_pStorageSurface;	// ���� surface����
};


#endif
