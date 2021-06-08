// MEFFECTSPRITETYPETABLE_INFO.h: interface for the MEFFECTSPRITETYPETABLE_INFO class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEFFECTSPRITETYPETABLE_INFO_H__26830D52_AD83_4A21_BEDE_FC0B06755DC0__INCLUDED_)
#define AFX_MEFFECTSPRITETYPETABLE_INFO_H__26830D52_AD83_4A21_BEDE_FC0B06755DC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum BLT_TYPE 
{
	BLT_NORMAL = 0,
	BLT_EFFECT,
	BLT_SHADOW,
	BLT_SCREEN
};
typedef unsigned short TYPE_FRAMEID;
typedef unsigned short TYPE_EFFECTSPRITETYPE;

class CEffectSpriteType  
{
public:
	CEffectSpriteType();
	virtual ~CEffectSpriteType();
public:
	int LoadFromFile(CFile* file);
public:
		BLT_TYPE					BltType;				// �������
		unsigned short				FrameID;				// Frame ID	
		bool						RepeatFrame;			// �ݺ��Ǵ� frame�ΰ�?
		unsigned short				ActionEffectFrameID;	// action ���� �ٸ� frame�� ��������ϴ� effect�ΰ�?
		//TYPE_FRAMEID				PairFrameID;			// ���ÿ� ��µǾ�� �ϴ� ¦~�̴�.
		WORD*						PairFrameIDList;		// ���ÿ� ��µǾ�� �ϴ� ����Ʈ��~�̴�.
		// add by coffee
		int							PairFrameIDListNum;     //PairFrameIDlist����
		// end 
		bool						bPairFrameBack;			// ���ÿ� ��µǴ� ����Ʈ�� �ڿ� ��µǴ°�
		unsigned short				FemaleEffectSpriteType;	// ���ڿ�..
};


class CEffectSpriteTypeManager
{
public:
	CEffectSpriteTypeManager();
	virtual ~CEffectSpriteTypeManager();
public:
	//��ȡ����
	CEffectSpriteType* GetEffectTable(int id)	{ if (id>m_size) { return NULL; } return &m_pEffectTab[id];	}
	//��ȡ����С
	int GetSize(){ return m_size;}
	//��ȡ�ļ�
	int LoadFromFile(char* FileName);
protected:
private:
	//����������
	CEffectSpriteType* m_pEffectTab;
	//��������
	int m_size;

};
#endif // !defined(AFX_MEFFECTSPRITETYPETABLE_INFO_H__26830D52_AD83_4A21_BEDE_FC0B06755DC0__INCLUDED_)
