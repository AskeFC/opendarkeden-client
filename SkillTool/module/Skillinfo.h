#pragma once
typedef struct sSkillOUSTERS
{
	int SkillPoint;     //���ܵ�
	int LevelUpPoint;   //�������ܵ�
	int szSkill;        //���ܳ���
	int * Skilllist;    //�����б�
	int Fire;           //��
	int Water;			//ˮ
	int Earth;			//��
	int Wind;			//��
	int Sum;			//�ϼ�
	int Wristlet;		//
	int Stone1;
	int Stone2;
	int Stone3;
	int Stone4;
	byte CanDelete;


	sSkillOUSTERS()
	{
		SkillPoint=0;
		LevelUpPoint=0;
		szSkill=0;
		Skilllist=NULL;
		Fire=0;
		Water=0;
		Earth=0;
		Wind=0;
		Sum=0;
		Wristlet=0;
		Stone1=0;
		Stone2=0;
		Stone3=0;
		Stone4=0;
		CanDelete=0;
	}
	~sSkillOUSTERS()
	{
		if (Skilllist !=NULL)
		{
			delete[] Skilllist;
		}
	}

}sSkillOUSTERS,*lpsSkillOUSTERS;
typedef struct sSkillnode{
	int skillID;      //����ID
	int LearnLevel;   //ѧϰ�ȼ�
	int DomainType;   //��������
	DWORD dwNameLen;  //�������Ƴ���
	char* name;       //��������
	DWORD dwHnameLen; //�����������Ƴ���
	char* Hname;      //������������
	int minDamage;    //������С�˺�
	int maxDamage;    //��������˺�
	int minDelay;     //������С��ʱ
	int maxDelay;     //���������ʱ
	int minDuration;  //������С����ʱ��
	int maxDuration;  //����������ʱ��
	int mp;           //��������MP
	int minRange;     //������Сʹ�þ���
	int maxRange;     //�������ʹ�þ���
	int maxExp;       //���������
	int ElementalDomain;//����ˮ������������
	lpsSkillOUSTERS m_sSkillOUSTERS; //ħ��
	
	
	sSkillnode()
	{	
		skillID=0;
		LearnLevel=0;
		DomainType=0;
		dwNameLen=0;
		name=NULL;
		dwHnameLen=0;
		Hname=NULL;
		minDamage=0;
		maxDamage=0;
		minDelay=0;
		maxDelay=0;
		minDuration=0;
		maxDuration=0;
		mp=0;
		minRange=0;
		maxRange=0;
		maxExp=0;
		ElementalDomain=-1;
		m_sSkillOUSTERS = NULL;

	}
	~sSkillnode()
	{
		if(name!=NULL)
		{
			delete[] name;
		}
		if (Hname!=NULL)
		{
			delete[] Hname;
		}
	}

}sSkillnode,*lpsSkillnode;
typedef struct sSkillnodeString
{
	int skillID;
	int LearnLevel;
	int DomainType;
	DWORD dwNameLen;
	CString name;
	DWORD dwHnameLen;
	CString Hname;
	int minDamage;
	int maxDamage;
	int minDelay;
	int maxDelay;
	int minDuration;
	int maxDuration;
	int mp;
	int minRange;
	int maxRange;
	int maxExp;
	int ElementalDomain;

	lpsSkillOUSTERS m_sSkillOUSTERS;

	sSkillnodeString()
	{	
		skillID=0;
		LearnLevel=0;
		DomainType=0;
		dwNameLen=0;
		dwHnameLen=0;
		minDamage=0;
		maxDamage=0;
		minDelay=0;
		maxDelay=0;
		minDuration=0;
		maxDuration=0;
		mp=0;
		minRange=0;
		maxRange=0;
		maxExp=0;
		ElementalDomain=-1;
		m_sSkillOUSTERS = NULL;
	}
	~sSkillnodeString()
	{
		if (m_sSkillOUSTERS)
		{	
			delete m_sSkillOUSTERS;
		}
	}
}sSkillnodeString,*lpsSkillnodeString;
class CSkillinfo
{
public:
	CSkillinfo(void);
	~CSkillinfo(void);
	
	bool OpenFromFile(CString FileName);
	lpsSkillnode Getnode(int num);
	int NumofSkill;
private:
	lpsSkillnode m_lpsSkillnode;
	lpsSkillnode m_curlpsSkillnode;
	CString m_FileName;
public:
	// ���浽�ļ�
	bool SavetoFile(void);
};
