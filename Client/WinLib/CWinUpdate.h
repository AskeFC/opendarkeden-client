//-----------------------------------------------------------------------------
// CWinUpdate.h
//-----------------------------------------------------------------------------
// �ð��� ���ϸ鼭 �����ð����� �ѹ��� Update�� �ǵ��� �Ѵ�.
//-----------------------------------------------------------------------------

#ifndef	__CWINUPDATE_H__
#define	__CWINUPDATE_H__

#include <Windows.h>
#include <MMSystem.h>

class CWinUpdate {
	public :
		CWinUpdate();
		virtual ~CWinUpdate();

		//-------------------------------------------------------
		// Init
		//-------------------------------------------------------
		virtual void	Init() {}

		//-------------------------------------------------------
		// Update
		//-------------------------------------------------------
		virtual void	Update();

		//-------------------------------------------------------
		// Current Time
		//-------------------------------------------------------
		static void		SetCurrentTime()	{ m_CurrentTime	= timeGetTime(); }
		static DWORD	GetCurrentTime()	{ return m_CurrentTime; }

		//-------------------------------------------------------
		// Update Delay
		//-------------------------------------------------------
		void			SetDelay(DWORD delay)	{ m_UpdateDelay = delay; }
		DWORD			GetDelay() const		{ return m_UpdateDelay; }

		//-------------------------------------------------------
		// Last Time
		//-------------------------------------------------------
		DWORD			GetLastTime()		{ return m_LastTime; }
		

	private :
		static DWORD	m_CurrentTime;		// ���� time

	protected :
		DWORD			m_LastTime;			// ���� �ֱٿ� Update()�� �ð�
		DWORD			m_UpdateDelay;		// update delay�ð�
};

#endif		
