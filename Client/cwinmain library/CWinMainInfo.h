//-----------------------------------------------------------------------------
// CWinMainInfo.h
//-----------------------------------------------------------------------------
// CWinMain�� �ʱ�ȭ�ϴµ� �ʿ��� ����
//-----------------------------------------------------------------------------

#ifndef	__CWINMAININFO_H__
#define	__CWINMAININFO_H__

enum WINMAIN_WINDOW_MODE
{
	WINMAIN_WINDOW_STYPE_FULLSCREEN,
	WINMAIN_WINDOW_STYPE_WINDOWMODE,
	WINMAIN_WINDOW_STYPE_USERDEFINE
};

struct WINMAIN_INFO
{
	HINSTANCE					hInstance;
	char						ProgramName[128];
	int							SizeX;
	int							SizeY;
	WINMAIN_WINDOW_MODE			Mode;	
};


#endif