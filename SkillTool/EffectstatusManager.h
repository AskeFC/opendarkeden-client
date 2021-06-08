// EffectstatusManager.h: interface for the CEffectstatusManager class.
//
//////////////////////////////////////////////////////////////////////


#if !defined(AFX_EFFECTSTATUSMANAGER_H__E2E376DF_501B_41FD_B040_773B880C3C6F__INCLUDED_)
#define AFX_EFFECTSTATUSMANAGER_H__E2E376DF_501B_41FD_B040_773B880C3C6F__INCLUDED_

#include "../Client/MTypeDef.h"
#include "../Client/EffectSpriteTypeDef.h"
#include "../SkillDef.h"


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CEffectstatus
{
public:
	int LoadFromFile(CFile *file);
	CEffectstatus();
	virtual ~CEffectstatus();
public:
	bool						bUseEffectSprite;		// �Ƿ�ʹ��EffectSpriteЧ��
	bool						bAttachGround;			// һ��ΪĬ��ֵ
	TYPE_EFFECTSPRITETYPE		EffectSpriteType;		// ENUM_EFFECTSPRITETYPE �����ļ� EffectSpriteType.h
	WORD						EffectColor;			// Ч����ɫ
	ADDON						EffectColorPart;		// Ч����λ
	TYPE_ACTIONINFO				ActionInfo;				// ACTIONINFO ��������   �����ļ� SkillDef.h  
	TYPE_ACTIONINFO				OriginalActionInfo;		// ACTIONINFO ��������   �����ļ� SkillDef.h 
	int							SoundID;				// SoundID
private:
};


class CEffectstatusManager  
{
public:

	//���캯��
	CEffectstatusManager();
	//���⺯��
	virtual ~CEffectstatusManager();
public:
	//��ȡ�ļ�
	int LoadFromFile(char* FileName);
	//��ȡ����
	CEffectstatus* GetTable(int n){	if (n<m_size){return &m_pTable[n];}return NULL;}
	//��ȡ��С
	int GetSize(){return m_size;}

private:
	int m_size;
	CEffectstatus* m_pTable;

};

#endif // !defined(AFX_EFFECTSTATUSMANAGER_H__E2E376DF_501B_41FD_B040_773B880C3C6F__INCLUDED_)
