/*-----------------------------------------------------------------------------

	CI.h

	Character Inputer.

	2000.10.4. KJTINC

-----------------------------------------------------------------------------*/

#ifndef __CI_H__
#define __CI_H__

#include <windows.h>
#include "BasicS.h"

//-----------------------------------------------------------------------------
// CI
//
// Character inputer.
//
// Windows IME(Input Method Editor)�� ���� �Է¹��� ���ڸ� ó���Ѵ�.
// DBCS(Double-Byte Character Set) ����̴�.
//-----------------------------------------------------------------------------
class CI
{
private:
	char_t		m_composing_char[2]; // one character + '\0'

	//
	// m_bl_insert_mode
	//
	// insert or edit mode
	// �������� ��ü���� �ٸ��� ���� �ʱ� ���ؼ� CI�� �����Ѵ�.
	//
	bool			m_bl_insert_mode; 

	bool			m_bl_end_of_ime;
	bool			m_bl_ime_running;

public:
	CI();
	~CI();

	void	ClearCurrentIMEComposition();
	void	RunCursorBlinker();
	void	Init();
	void	IME_MessageProcessor(UINT message, WPARAM wParam, LPARAM lParam = 0);
	const char_t * GetComposingBufPtr() { return m_composing_char; }
	char_t GetComposingChar() { return m_composing_char[0]; }
	bool	GetInsertModeState() const { return m_bl_insert_mode; }
	void	ToggleInsertMode() { m_bl_insert_mode = !m_bl_insert_mode; }
	bool	GetEndOfIME();
	bool	ImeRunning() const { return m_bl_ime_running; } // IME�� ������?
	bool	GetCursorBlink() const;
	void	ForceShowCursor() const;
	void	FinishImeRunning();
	bool	IsEngInput() const;
	void	SetEngInput(bool bHangul = false);
};

extern CI gC_ci;

#endif