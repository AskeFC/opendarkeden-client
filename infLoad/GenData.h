// GenData.h: interface for the CGenData class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GENDATA_H__6C3FEB45_0042_42A7_8C03_40559F96FA8B__INCLUDED_)
#define AFX_GENDATA_H__6C3FEB45_0042_42A7_8C03_40559F96FA8B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

//////////////////////////////////////////////////////////////////////////
//���ฺ����һЩ��������
class CGenData  
{
public:
	CGenData(CListCtrl &List);
	virtual ~CGenData();
public:
	//�����б�����
	int GetListInt(int nItem);
	CString GetListCString(int nItem);
	BYTE GetListBYTE(int nItem);
	BOOL GetListBool(int nItem);
private:
	CListCtrl *CLList;
};

#endif // !defined(AFX_GENDATA_H__6C3FEB45_0042_42A7_8C03_40559F96FA8B__INCLUDED_)
