//////////////////////////////////////////////////////////////////////////////
/// \file PromotionSlayerActionName.h
/// \author sonee
/// \date 2004.12.9
//////////////////////////////////////////////////////////////////////////////

#pragma once


const char* strPromotionSlayerAction[ ACTION_SLAYER_PROMOTION_MAX ] =
{
	"������",
	"������",
	"������",
	"���ڰ�����",	
	
	"�˰ȱ�",
	"���ȱ�",
	"�Ѱȱ�",
	"���ڰ��ȱ�",

	"�˰���SLOW",
	"�˰���NORMAL",
	"�˰���FAST",
	
	"������SLOW",
	"������NORMAL",
	"������FAST",
	
	"AR����SLOW",
	"AR����NORMAL",
	"AR����FAST",

	"SR����SLOW",
	"SR����NORMAL",
	"SR����FAST",

	"�˽�ųSLOW",
	"�˽�ųNORMAL",
	"�˽�ųFAST",

	"����ųSLOW",
	"����ųNORMAL",
	"����ųFAST",

	"�ѽ�ųSLOW",
	"�ѽ�ųNORMAL",
	"�ѽ�ųFAST",
	
	"��������",
	"��������",
	
	"�������ϱ�",
	"�˸±�",
	"���±�",
	"�Ѹ±�",
	"���ڰ����̽��±�",
	"�ױ�",

	"��������̵�",
	"�����������",

	"Ư���˵�",
	"Ư���ѽ��ڰ�",
	"�����̵�����",
	"�����̵���"
};

const char* strPromotionSlayerActionForSearch[ ACTION_SLAYER_PROMOTION_MAX ] =
{
	"������",
	"������",
	"������",
	"���ڰ�����",	
	
	"�˰ȱ�",
	"���ȱ�",
	"�Ѱȱ�",
	"���ڰ��ȱ�",

	"�˽�ų",
	"�˽�ų",
	"�˽�ų",
	
	"������",
	"������",
	"������",
	
	"�Ѱ���",
	"�Ѱ���",
	"�Ѱ���",

	"�Ѱ���",
	"�Ѱ���",
	"�Ѱ���",

	"�˽�ų",
	"�˽�ų",
	"�˽�ų",

	"����ų",
	"����ų",
	"����ų",

	"�ѽ�ų",
	"�ѽ�ų",
	"�ѽ�ų",
	
	"��������",
	"��������",
	
	"�������ϱ�",
	"�˸±�",
	"���±�",
	"�Ѹ±�",
	"���ڰ����̽��±�",
	"�ױ�",

	"��������̵�",
	"�����������",

	"Ư���˵�",
	"Ư���ѽ��ڰ�",
	"�����̵�����",
	"�����̵���"
};

const DWORD g_PromotionSlayerActionIndex[ ACTION_SLAYER_PROMOTION_MAX ] =
{
	ACTION_SLAYER_PROMOTION_STOP_SWORD,
	ACTION_SLAYER_PROMOTION_STOP_BLADE,
	ACTION_SLAYER_PROMOTION_STOP_GUN,
	ACTION_SLAYER_PROMOTION_STOP_MACE_AND_CROSS,
	
	ACTION_SLAYER_PROMOTION_MOVE_SWORD,
	ACTION_SLAYER_PROMOTION_MOVE_BLADE,
	ACTION_SLAYER_PROMOTION_MOVE_GUN,
	ACTION_SLAYER_PROMOTION_MOVE_MACE_AND_CROSS,

	ACTION_SLAYER_PROMOTION_ATTACK_SWORD_SLOW,
	ACTION_SLAYER_PROMOTION_ATTACK_SWORD_NORMAL,
	ACTION_SLAYER_PROMOTION_ATTACK_SWORD_FAST,
	
	ACTION_SLAYER_PROMOTION_ATTACK_BLADE_SLOW,
	ACTION_SLAYER_PROMOTION_ATTACK_BLADE_NORMAL,
	ACTION_SLAYER_PROMOTION_ATTACK_BLADE_FAST,
	
	ACTION_SLAYER_PROMOTION_ATTACK_GUN_AR_SLOW,
	ACTION_SLAYER_PROMOTION_ATTACK_GUN_AR_NORMAL,
	ACTION_SLAYER_PROMOTION_ATTACK_GUN_AR_FAST,

	ACTION_SLAYER_PROMOTION_ATTACK_GUN_SR_SLOW,
	ACTION_SLAYER_PROMOTION_ATTACK_GUN_SR_NORMAL,
	ACTION_SLAYER_PROMOTION_ATTACK_GUN_SR_FAST,

	ACTION_SLAYER_PROMOTION_SKILL_SWORD_SLOW,
	ACTION_SLAYER_PROMOTION_SKILL_SWORD_NORMAL,
	ACTION_SLAYER_PROMOTION_SKILL_SWORD_FAST,

	ACTION_SLAYER_PROMOTION_SKILL_BLADE_SLOW,
	ACTION_SLAYER_PROMOTION_SKILL_BLADE_NORMAL,
	ACTION_SLAYER_PROMOTION_SKILL_BLADE_FAST,

	ACTION_SLAYER_PROMOTION_SKILL_GUN_SLOW,
	ACTION_SLAYER_PROMOTION_SKILL_GUN_NORMAL,
	ACTION_SLAYER_PROMOTION_SKILL_GUN_FAST,
	
	ACTION_SLAYER_PROMOTION_MAGIC,
	ACTION_SLAYER_PROMOTION_MAGIC_ATTACK,

	ACTION_SLAYER_PROMOTION_DRAINED,
	ACTION_SLAYER_PROMOTION_DAMAGED_SWORD,
	ACTION_SLAYER_PROMOTION_DAMAGED_BLADE,
	ACTION_SLAYER_PROMOTION_DAMAGED_GUN,
	ACTION_SLAYER_PROMOTION_DAMAGED_CROSS_MACE,
	ACTION_SLAYER_PROMOTION_DIE,

	ACTION_SLAYER_PROMOTION_BIKE_MOVE,
	ACTION_SLAYER_PROMOTION_BIKE_STOP,

	ACTION_SLAYER_PROMOTION_SPECIAL,
	ACTION_SLAYER_PROMOTION_SPECIAL_2,
	ACTION_SLAYER_PROMOTION_SLIDING,
	ACTION_SLAYER_PROMOTION_SLIDING_END,
};

const char* strPromotionSlayerPart[ PS_PART_MAX ] =
{
	"��",
	"���",
	"��",
	"��",
	"���ڰ�",
	"���̽�",
	"AR",
	"SR",
	"����",
	"�������1",
	"�������2",
	"�������"
};

const BYTE ACSlayerPartType[ PS_PART_MAX ] =
{
	ADDON_AC_BODY,
	ADDON_AC_HELMET,
	ADDON_AC_RIGHTHAND,
	ADDON_AC_RIGHTHAND,
	ADDON_AC_RIGHTHAND,
	ADDON_AC_RIGHTHAND,
	ADDON_AC_RIGHTHAND,
	ADDON_AC_RIGHTHAND,
	ADDON_AC_LEFTHAND,
	ADDON_AC_MOTOR,
	ADDON_AC_MOTOR,
	ADDON_AC_SHOULDER,
};