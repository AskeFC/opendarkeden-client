#pragma once

const char* 	strOustersAction[ OUSTERS_ACTION_MAX ] = {
	"��ũ������",
	"��ũ���ȱ�",
	"��ũ������",
	"��������",
	"�����",
	"�������ϱ�",
	"�ױ�",
	"����",
	"�ȱ�",
	"��ũ�����",
	"��������",
	"��",
	"�����̵�����",
	"�����̵��̵�",
	"��ũ������Slow",
	"��ũ������Fast",
	"��ũ�����Slow",
	"��ũ�����Fast",
};

const char* strOustersActionForSearch[ OUSTERS_ACTION_MAX ] =
{
	"��ũ������",
	"��ũ���ȱ�",
	"��ũ������",
	"��������",
	"�����",
	"�������ϱ�",
	"�ױ�",
	"����",
	"�ȱ�",
	"��ũ�����",
	"��������",
	"��",
	"����",
	"�̵�",
	"��ũ������",
	"��ũ������",
	"��ũ�����",
	"��ũ�����",
};

const char* strOustersPart[OUSTERS_PART_MAX] = {
	"��ũ��",
	"��1",
	"��2",
	"��3",
	"��4",
};

const DWORD oustersActionIndex[ OUSTERS_ACTION_MAX ] = 
{
	OUSTERS_ACTION_SHAK_STOP,
	OUSTERS_ACTION_SHAK_MOVE,
	OUSTERS_ACTION_SHAK_ATTACK,
	OUSTERS_ACTION_SKILL,
	OUSTERS_ACTION_DAMAGED,
	OUSTERS_ACTION_DRAINED,
	OUSTERS_ACTION_DIE,
	
	OUSTERS_ACTION_STOP,
	OUSTERS_ACTION_MOVE,
	OUSTERS_ACTION_SHAK_SKILL,	
	OUSTERS_ACTION_MAGIC_ATTACK,
	OUSTERS_ACTION_GETTING_SOUL,
	OUSTERS_ACTION_FAST_MOVE_STOP,
	OUSTERS_ACTION_FAST_MOVE,
	OUSTERS_ACTION_SHAK_ATTACK_SLOW,
	OUSTERS_ACTION_SHAK_ATTACK_FAST,
	OUSTERS_ACTION_SHAK_SKILL_SLOW,
	OUSTERS_ACTION_SHAK_SKILL_FAST,
};

const char* strPromotionOustersAction[ ACTION_OUSTERS_PROMOTION_MAX ] =
{
	"��ũ������",
	"��ũ���ȱ�",
	"����Ʋ������",
	"����Ʋ���ȱ�",

	"����SLOW",
	"����NORMAL",
	"����FAST",
	"��ųSLOW",
	"��ųNORMAL",
	"��ųFAST",

	"��������",

	"��������",
	"��",
	"�������ϱ�",
	"�ױ�",
	"�����",
	"Ư������",
	"�����̵�����",
	"�����̵��̵�",
};

const char* strPromotionOustersActionForSearch[ ACTION_OUSTERS_PROMOTION_MAX ] =
{
	"��ũ������",
	"��ũ���ȱ�",
	"����Ʋ������",
	"����Ʋ���ȱ�",

	"����",
	"����",
	"����",
	"��ų",
	"��ų",
	"��ų",

	"��������",

	"��������",
	"��",
	"�������ϱ�",
	"�ױ�",
	"�����",
	"Ư������",
	"�����̵�",
	"�����̵�",
};

const DWORD g_PromotionOustersActionIndex[ ACTION_OUSTERS_PROMOTION_MAX ] = 
{
	ACTION_OUSTERS_PROMOTION_CHAKRAM_STOP,
	ACTION_OUSTERS_PROMOTION_CHAKRAM_MOVE,
	ACTION_OUSTERS_PROMOTION_WRISTLET_STOP,
	ACTION_OUSTERS_PROMOTION_WRISTLET_MOVE,

	ACTION_OUSTERS_PROMOTION_ATTACK_SLOW,
	ACTION_OUSTERS_PROMOTION_ATTACK_NORMAL,
	ACTION_OUSTERS_PROMOTION_ATTACK_FAST,
	ACTION_OUSTERS_PROMOTION_SKILL_SLOW,
	ACTION_OUSTERS_PROMOTION_SKILL_NORMAL,
	ACTION_OUSTERS_PROMOTION_SKILL_FAST,

	ACTION_OUSTERS_PROMOTION_MAGIC_ATTACK,

	ACTION_OUSTERS_PROMOTION_MAGIC,
	ACTION_OUSTERS_PROMOTION_ABSORB_SOUL,
	ACTION_OUSTERS_PROMOTION_DRAINED,
	ACTION_OUSTERS_PROMOTION_DIE,
	ACTION_OUSTERS_PROMOTION_DAMAGED,
	ACTION_OUSTERS_PROMOTION_SPECIAL,	

	ACTION_OUSTERS_PROMOTION_FAST_MOVE_STOP,
	ACTION_OUSTERS_PROMOTION_FAST_MOVE,
};

const char* strPromotionOustersPart[PO_PART_MAX] = {
	"��ũ��",
	"��1",	
};
