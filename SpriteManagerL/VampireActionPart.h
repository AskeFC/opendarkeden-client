
#pragma once


const char* strVampirePart[VAMPIRE_PART_MAX] = {
							"��Ʈ1",
							"��Ʈ2",
							"��Ʈ3",
};

const DWORD vampireActionIndex[ VAMPIRE_ACTION_MAX] =
{
	ACTION_STOP,
	ACTION_MOVE,
	ACTION_ATTACK,	
	ACTION_SKILL,			// magic
	ACTION_DAMAGED,	
	ACTION_DRAINED,	
	ACTION_DIE,		
	ACTION_DRAIN,	
};


const DWORD npcActionIndex[ NPC_ACTION_MAX] =
{
	ACTION_STOP,
	ACTION_MOVE,
	ACTION_ATTACK,	
	ACTION_SKILL,			// magic
	ACTION_DAMAGED,	
	ACTION_DRAINED,	
	ACTION_DIE,			
};

const DWORD g_AdvancementClassVampireActionIndex[ ACTION_ADVANCEMENT_MAX ] =
{
	ACTION_ADVANCEMENT_STOP,
	ACTION_ADVANCEMENT_MOVE,
	ACTION_ADVANCEMENT_DAMAGED,
	ACTION_ADVANCEMENT_DIE,
	ACTION_ADVANCEMENT_DRAIN,
	ACTION_ADVANCEMENT_DRAINED,

	ACTION_ADVANCEMENT_ATTACK_SLOW,
	ACTION_ADVANCEMENT_ATTACK_NORMAL,
	ACTION_ADVANCEMENT_ATTACK_FAST,

	ACTION_ADVANCEMENT_SKILL_SLOW,
	ACTION_ADVANCEMENT_SKILL_NORMAL,
	ACTION_ADVANCEMENT_SKILL_FAST,

	ACTION_ADVANCEMENT_MAGIC,
	ACTION_ADVANCEMENT_MAGIC_ATTACK,
	ACTION_ADVANCEMENT_SPECIAL,
	ACTION_ADVANCEMENT_CREATE_WEAPON,
	ACTION_ADVANCEMENT_DESTROY_WEAPON,
};

const char* strAdvancementClassVampirePart[ AC_PART_MAX ] = 
{
	"��",
	"����",
};

const char* strAdvancementClassVampireAction[ACTION_ADVANCEMENT_MAX] = {
	"����",
	"�ȱ�",
	"�����",
	"�ױ�",
	"����",
	"�������ϱ�",

	"����SLOW",
	"����NORMAL",
	"����FAST",

	"��ųSLOW",
	"��ųNORMAL",
	"��ųFAST",

	"��������",
	"��������",
	"Ư������",
	"�������",
	"����Ҹ�",
};

const char* strAdvancementClassVampireActionForSearch[ ACTION_ADVANCEMENT_MAX ] =
{
	"����",
	"�ȱ�",
	"�����",
	"�ױ�",
	"����",
	"�������ϱ�",

	"����",
	"����",
	"����",

	"��ų",
	"��ų",
	"��ų",

	"��������",
	"��������",
	"Ư������",
	"�������",
	"����Ҹ�",
};