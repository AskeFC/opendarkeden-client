// SkillFileManager.h: interface for the CSkillFileManager class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SKILLFILEMANAGER_H__1D994268_F217_4124_B9D6_8410F2DF1795__INCLUDED_)
#define AFX_SKILLFILEMANAGER_H__1D994268_F217_4124_B9D6_8410F2DF1795__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CSkillFile
{
public:
	CSkillFile();
	virtual ~CSkillFile();
	int LoadFromFile(CFile *file);
protected:
private:
};


class CSkillFileManager  
{
public:
	CSkillFileManager();
	virtual ~CSkillFileManager();

public:
	//��ȡ�ļ�
	int LoadFromFile(char* FileName);
	//��ȡ����
	CSkillFile* GetTable(int n){	if (n<m_size){return &m_pTable[n];}return NULL;}
	//��ȡ��С
	int GetSize(){return m_size;}
public:
	//��������
	CSkillFile* m_pTable;
	//����
	int			m_size;
};

#endif // !defined(AFX_SKILLFILEMANAGER_H__1D994268_F217_4124_B9D6_8410F2DF1795__INCLUDED_)
