#if !defined(AFX_ANIDLG_H__1543B100_4E8D_11D4_AC04_0050DABAC3D4__INCLUDED_)
#define AFX_ANIDLG_H__1543B100_4E8D_11D4_AC04_0050DABAC3D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AniDlg.h : header file
//


#include <mmsystem.h>


//#include "SpriteManagerDlg.h"
#include "DIBList.h"

class CDIBList;


/////////////////////////////////////////////////////////////////
// From CLIENT
/////////////////////////////////////////////////////////////////
// ���忡 ���� ��
enum ADDON
{
	ADDON_HAIR,			// �Ӹ�
	ADDON_HELM,			// ����
	ADDON_COAT,			// ����
	ADDON_TROUSER,		// ����
	//ADDON_SHOES,		// �Ź�
	//ADDON_LEFTGLOVE,		// �޼� �尩
	//ADDON_RIGHTGLOVE,		// ������ �尩
	ADDON_LEFTHAND,		// �޼�			
	ADDON_RIGHTHAND,	// ������
	//ADDON_CLOAK,		// ����
	ADDON_MOTOR,		// �������
	ADDON_MAX,
	ADDON_NULL	= 0xFFFF,
};

enum AC_ADDON
{
	ADDON_AC_HELMET,
	ADDON_AC_BODY,
	ADDON_AC_SHOULDER,
	ADDON_AC_LEFTHAND,
	ADDON_AC_RIGHTHAND,
	ADDON_AC_MOTOR,
	ADDON_AC_MAX
};


class CSpriteManagerDlg;


/////////////////////////////////////////////////////////////////////////////
// CAniDlg dialog

class CAniDlg : public CDialog
{
// Construction
public:
	void DrawScene();
	void CheckTime();
	void MakeAnimations();
	void ChangeBg();
	void ResetCombos();
	void UpdateInfoStatic();
//	CSpriteManagerDlg* GetParent();
	CAniDlg(CWnd* pParent = NULL);   // standard constructor
	~CAniDlg();

// Dialog Data
	//{{AFX_DATA(CAniDlg)
	enum { IDD = IDD_DIALOG_ANI };
	CComboBox	m_comboList[ADDON_MAX];
	CComboBox	m_comboVampire;
	CComboBox	m_comboOusters;
	CComboBox	m_comboOustersWeapon;
	CComboBox	m_comboACVampireWeapon;

	CComboBox	m_ACComboList[ ADDON_AC_MAX ];
	/*CComboBox	m_comboACHelmet;
	CComboBox	m_comboACLefthand;
	CComboBox	m_comboACRighthand;
	CComboBox	m_comboACShoulder;
	CComboBox	m_comboACMotor;*/

	CEdit		m_editFPS;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAniDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	public:
	BOOL Create( UINT nIDTemplate, CWnd* pParentWnd = NULL );
	//}}AFX_VIRTUAL

	BOOL					m_bResetFPS;
	BOOL					m_bShowWindow;
	DWORD					m_dwUpdates;
	DWORD					m_dwOldTickCount;

	float					m_fRealFPS;
	int						m_iFPS;
	int						m_addons[ ADDON_MAX];	// part ����.
	int						m_ACAddons[ ADDON_AC_MAX ];
	CDIBList				m_dibList[ ADDON_MAX];
	CDIBList				m_shadowDibList[ ADDON_MAX];
	BOOL					m_bPlayingAni;
	int						m_iAniTime;
	CSpriteManagerDlg*		m_pParentWnd;
//	CDib					m_bgDib;
	CBitmap					m_bgBitmap[4+1];	// +1 custom bmp...
	DWORD					m_dwBGBMP;
	CDC						m_backDC;
	CDC*					m_pMemDC;
	HBITMAP					m_pHOldBmps[100];	// �ִ� 100��..m_pMemDC������ ���õ� bitmap��
	int						m_iCurAnis;		// �ܼ��� m_pMemDC�� bitmap�� �����ϱ� ���� ���
	HBITMAP					m_hOldBMP, m_hBMP;	// m_backDC�� ���� HBITMAP

	RECT					m_aniRect;

	float					m_fWidthRatio, m_fHeightRatio;	// animation ũ�Ⱑ ���Ӱ� �����ϵ��� ����� ����
															// ���� ���� ũ�⿡ �̸� ���Ѵ�.
	BOOL					m_bResize;	// animation��½� resizing�� �� ���ΰ�?

	BOOL					m_bDragging;
	BOOL					m_bDrawTile;

	int						m_iCreatureXOffset, m_iCreatureYOffset;
	CPoint					m_fromPt, m_curPt;

	MMRESULT				m_timerID;	// multimedia timer id


	void Load( BOOL bForce = FALSE);

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAniDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	afx_msg void OnPaint();

	afx_msg void OnSelchangeCombo();
	afx_msg void OnSelchangeComboBG();
	afx_msg void OnButtonExit();
	afx_msg void OnButtonPlay();
	afx_msg void OnButtonNext();
	afx_msg void OnButtonPrev();
	afx_msg void OnButtonBg();
	afx_msg void OnCheckResize();
	afx_msg void OnCheckTile();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point) ;
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point) ;
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point) ;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point) ;
	afx_msg void OnChangeEditFPS();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus) ;
	afx_msg void OnClose();

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIDLG_H__1543B100_4E8D_11D4_AC04_0050DABAC3D4__INCLUDED_)
