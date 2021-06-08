#pragma once

// SLAYER_PART�� � addon type���� ����..
const BYTE SlayerPartType[SLAYER_PART_MAX] = 
{
	ADDON_HELM,
	ADDON_COAT,
	ADDON_TROUSER,
	ADDON_RIGHTHAND,
	ADDON_RIGHTHAND,
	ADDON_LEFTHAND,
	ADDON_LEFTHAND,
	ADDON_LEFTHAND,
	ADDON_RIGHTHAND,
	ADDON_RIGHTHAND,
	ADDON_RIGHTHAND,
	ADDON_HAIR,
	ADDON_HAIR,
	ADDON_HAIR,
	ADDON_HELM,
	ADDON_COAT,
	ADDON_TROUSER,
	ADDON_RIGHTHAND,
	ADDON_RIGHTHAND,
	ADDON_MOTOR,
	ADDON_COAT,
	ADDON_TROUSER,
#ifdef _TEMP_FOR_INTERFACE
	ADDON_HAIR,	// �ӽ�.
	ADDON_HAIR,
	ADDON_HAIR,
#endif
};

const char* strAction[ ACTION_MAX ] = {
	"����",			// ACTION_STOP	 = 	0,
	"�ȱ�",			// ACTION_MOVE,
	"����",			// ACTION_ATTACK,	
	"����",			// ACTION_SKILL,			// magic
	"�����",			// ACTION_DAMAGED,	
	"�������ϱ�",			// ACTION_DRAINED,	
	"�ױ�",			// ACTION_DIE,		
	"����",				// ACTION_DRAIN,			// 
	"TR",			// ACTION_SR,
	"AR",			// ACTION_AR,
	"�˱⺻",			// ACTION_SWORD,
	"���⺻",			// ACTION_BLADE,
	"������1",			// ACTION_THROW1,
	"��������̵�",			// ACTION_BIKE_MOVE1,
	"SG",			// ACTION_SG,
	"SMG",			// ACTION_SMG,
	"�˱��",			// ACTION_SWORD2,
	"�����",			// ACTION_BLADE2,
	"������2",			// ACTION_THROW2,
	"�����������",			// ACTION_BIKE_STOP1,	
	"TR SLOW",			// ACTION_SR_SLOW,
	"TR FAST",			// ACTION_SR_FAST,
	"AR SLOW",			// ACTION_AR_SLOW,
	"AR FAST",			// ACTION_AR_FAST,
	"SG SLOW",			// ACTION_SG_SLOW,
	"SG FAST",			// ACTION_SG_FAST,
	"SMG SLOW",			// ACTION_SMG_SLOW,
	"SMG FAST",				// ACTION_SMG_FAST,
	"�˱⺻SLOW",			// ACTION_SWORD_SLOW,
	"�˱⺻FAST",			// ACTION_SWORD_FAST,
	"���⺻SLOW",			// ACTION_BLADE_SLOW,
	"���⺻FAST",			// ACTION_BLADE_FAST,
	"�˱��SLOW",			// ACTION_SWORD2_SLOW,
	"�˱��FAST",			// ACTION_SWORD2_FAST,
	"�����SLOW",			// ACTION_BLADE2_SLOW,
	"�����FAST",			// ACTION_BLADE2_FAST,
};

// -------------------------------------------------
// directoryã�⸦ ���� ��, ���ǰ� �ڵ�����
//	���Ѱ� ���ݿ����� ���Ͻ��ϱ� ���ؼ�..
// -------------------------------------------------
const char* strActionForSearch[ ACTION_MAX] = { 
	"����",
	"�ȱ�",
	"����",
	"����",
	"�����",
	"�������ϱ�",
	"�ױ�",
	"����",	
	"TR",
	"AR",
	"��",
	"��",
	"������",
	"�������",
	"SG",
	"SMG",
	"��2",
	"��2",
	"������",
	"�������",
	"TR",
	"TR",
	"AR",
	"AR",
	"SG",
	"SG",
	"SMG",
	"SMG",	
	"��",
	"��",
	"��",
	"��",
	"��",
	"��",
	"��",
	"��",
};

const char* strSlayerPart[SLAYER_PART_MAX] = {
							"������",		// 0
							"������",
							"������",
							"SMG",
							"��",
							"����",
							"�巡�����",
							"��������",
							"SG",
							"��",
							"AR",
							"�Ӹ�1",
							"�Ӹ�2",
							"�Ӹ�3",
							"������",
							"�Ż���",
							"������",
							"���ڹ���",
							"TR",
							"�������",
							"�ǻ���",
							"������",
};

///////////////////////////////////////////////////////
//	�����̾��� ���� �ƴ� ��� action�� ���� index�� Ʋ���Ƿ�..
///////////////////////////////////////////////////////
const DWORD slayerActionIndex[ SLAYER_ACTION_MAX] =
{
	ACTION_STOP,
	ACTION_MOVE,
	ACTION_ATTACK,	
	ACTION_SKILL,			// magic
	ACTION_DAMAGED,	
	ACTION_DRAINED,	
	ACTION_DIE,		

	ACTION_SR,
	ACTION_AR,		// ����
	ACTION_SWORD,		// �˱⺻
	ACTION_BLADE,	// ���⺻
	ACTION_THROW1,			// ����ź.
	ACTION_BIKE_MOVE1,		// ������� �̵�1
	ACTION_SG,		// ����
	ACTION_SMG,		// �ڵ� ����.

	ACTION_SWORD2,
	ACTION_BLADE2,
	ACTION_THROW2,
	ACTION_BIKE_STOP1,
	ACTION_SR_SLOW,
	ACTION_SR_FAST,
	ACTION_AR_SLOW,
	ACTION_AR_FAST,
	ACTION_SG_SLOW,
	ACTION_SG_FAST,
	ACTION_SMG_SLOW,
	ACTION_SMG_FAST,
	ACTION_SWORD_SLOW,
	ACTION_SWORD_FAST,
	ACTION_BLADE_SLOW,
	ACTION_BLADE_FAST,
	ACTION_SWORD2_SLOW,
	ACTION_SWORD2_FAST,
	ACTION_BLADE2_SLOW,
	ACTION_BLADE2_FAST,
	
};

const BYTE s_AddonOrder[DIR_MAX][ADDON_MAX] = 
{
	{ ADDON_MOTOR, ADDON_TROUSER, ADDON_COAT, ADDON_HAIR, ADDON_HELM, ADDON_RIGHTHAND, ADDON_LEFTHAND },	// LEFT
	{ ADDON_MOTOR, ADDON_TROUSER, ADDON_COAT, ADDON_HAIR, ADDON_HELM, ADDON_RIGHTHAND, ADDON_LEFTHAND },	// LEFTDOWN
	{ ADDON_MOTOR, ADDON_TROUSER, ADDON_COAT, ADDON_HAIR, ADDON_HELM, ADDON_LEFTHAND, ADDON_RIGHTHAND },	// DOWN	
	{ ADDON_MOTOR, ADDON_TROUSER, ADDON_COAT, ADDON_HAIR, ADDON_HELM, ADDON_LEFTHAND, ADDON_RIGHTHAND },	// RIGHTDOWN	
	{ ADDON_MOTOR, ADDON_TROUSER, ADDON_COAT, ADDON_HAIR, ADDON_HELM, ADDON_LEFTHAND, ADDON_RIGHTHAND },	// RIGHT
	{ ADDON_MOTOR, ADDON_TROUSER, ADDON_COAT, ADDON_HAIR, ADDON_HELM, ADDON_LEFTHAND, ADDON_RIGHTHAND },	// RIGHTUP
	{ ADDON_MOTOR, ADDON_TROUSER, ADDON_COAT, ADDON_HAIR, ADDON_HELM, ADDON_RIGHTHAND, ADDON_LEFTHAND },	// UP
	{ ADDON_MOTOR, ADDON_TROUSER, ADDON_COAT, ADDON_HAIR, ADDON_HELM, ADDON_RIGHTHAND, ADDON_LEFTHAND }	// LEFTUP
};
