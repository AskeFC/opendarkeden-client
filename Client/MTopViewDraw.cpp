//#define __3D_IMAGE_OBJECT__					// by sonee
//----------------------------------------------------------------------
// MTopViewDraw.cpp
//----------------------------------------------------------------------
//
// ������ Draw �Լ� �κи� ���� �����´�.
// �۾��ϱⰡ �� �����ؼ� 
//----------------------------------------------------------------------
#pragma warning(disable:4786)
#include "Client_PCH.h"
#include "DX3D.h"
#include <math.h>
#include <list>
#include <stdio.h>
#include <fstream.h>
#include "MZone.h"
#include "MCreature.h"
#include "MFakeCreature.h"
#include "MPlayer.h"
#include "MItem.h"
#include "MImageObject.h"
#include "MAnimationObject.h"
#include "MShadowAnimationObject.h"
#include "assert.h"

#include "MMovingEffect.h"
#include "MScreenEffect.h"
#include "MTopView.h"
#include "MItemTable.h"
#include "MCreatureTable.h"
#include "MWeather.h"
#include "CMessageArray.h"
#include "DXLib.h"
#include "SP.h"
#include "FL2.h"
//#include "2D.h"
#include "ClientConfig.h"
#include "VS_UI_BASE.h"
#include "VS_UI_Mouse_Pointer.h"
#include "UIFunction.h"
#include "AddonDef.h"
#include "MZoneTable.h"
#include "MGameTime.h"
#include "UserOption.h"
#include "UserInformation.h"
#include "SpriteIDDef.h"
#include "MGameStringTable.h"
//#include "MZoneInfo.h"
#include "MObjectSelector.h"
#include "MPortal.h"
#include "EffectSpriteTypeDef.h"
#include "MScreenEffectManager.h"
#include "MEffectSpriteTypeTable.h"
#include "Profiler.h"
//#include "MFileDef.h"
#include "Properties.h"
#include "MEventManager.h"
#include "DebugInfo.h"
#include "MItemOptionTable.h"
#include "Client.h"
#include "SkillDef.h"
#include "vs_ui_item.h"
#include "MTopViewDraw.inl"

#define	SHIFT_SNIPPING			2

#ifdef __METROTECH_TEST__
	extern bool g_bLight;
#endif

#ifdef OUTPUT_DEBUG
	int g_WipeValue = 0;
	int g_WipeStep = 0;
#endif


static int g_nRocketPosValue[4] = {0,2,4,2};
extern int defaultSkinColor;
extern int defaultCoatColor;
extern int defaultTrouserColor;

namespace {
	POINT pointTemp;
	RECT rect;
};



int AdvancementOustersActionConvTable[ ACTION_MAX_SLAYER ] =
{
	ACTION_STAND,		// ���� ���� ��ȯ �ʿ�
	ACTION_MOVE,		// ���� ���� ��ȯ �ʿ�
	ACTION_ADVANCEMENT_OUSTERS_ATTACK_NORMAL,
	ACTION_ADVANCEMENT_OUSTERS_MAGIC,
	ACTION_ADVANCEMENT_OUSTERS_DAMAGED,
	ACTION_ADVANCEMENT_OUSTERS_DRAINED,
	ACTION_ADVANCEMENT_OUSTERS_DIE,
	ACTION_STAND,		// ���� ���� ��ȯ �ʿ�	(���ֱ�)
	ACTION_MOVE,		// ���� ���� ��ȯ �ʿ�	(�ȱ�)
	ACTION_ADVANCEMENT_OUSTERS_SKILL_NORMAL,
	ACTION_ADVANCEMENT_OUSTERS_MAGIC_ATTACK,
	ACTION_ADVANCEMENT_OUSTERS_ABSORB_SOUL,
	ACTION_ADVANCEMENT_OUSTERS_FAST_MOVE_STOP,		// ���� ���� ��ȯ �ʿ�	(��������)
	ACTION_ADVANCEMENT_OUSTERS_FAST_MOVE,		    // ���� ���� ��ȯ �ʿ�  (�����̵�)
	ACTION_ADVANCEMENT_OUSTERS_ATTACK_SLOW,
	ACTION_ADVANCEMENT_OUSTERS_ATTACK_FAST,
	ACTION_ADVANCEMENT_OUSTERS_SKILL_SLOW,
	ACTION_ADVANCEMENT_OUSTERS_SKILL_FAST,
	-1,
};

int AdvancementSlayerActionConvTable[ ACTION_MAX_SLAYER ] = 
{
	ACTION_STAND,	// ���� ���� ��ȯ �ʿ�
	ACTION_MOVE,	// ���� ���� ��ȯ �ʿ�
	-1,	// ���� ���� ��ȯ �ʿ�
	ACTION_ADVANCEMENT_SLAYER_MAGIC,
	ACTION_DAMAGED,
	ACTION_ADVANCEMENT_SLAYER_DRAINED,
	ACTION_ADVANCEMENT_SLAYER_DIE,
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_NORMAL,		//SR
	ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_NORMAL,		//AR
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SWORD_NORMAL,
	ACTION_ADVANCEMENT_SLAYER_ATTACK_BLADE_NORMAL,
	-1,													//��ź ������
	ACTION_ADVANCEMENT_SLAYER_BIKE_MOVE,
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_NORMAL,		//SG
	ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_NORMAL,		//SMG
	ACTION_ADVANCEMENT_SLAYER_SKILL_SWORD_NORMAL,
	ACTION_ADVANCEMENT_SLAYER_SKILL_BLADE_NORMAL,
	-1,													//���� ������
	ACTION_ADVANCEMENT_SLAYER_BIKE_STOP,				//18
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_SLOW,		//SR
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_FAST,		//SR
	ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_SLOW,		//AR
	ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_FAST,		//AR
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_SLOW,		//SG
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_FAST,		//SG
	ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_SLOW,		//SMG
	ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_FAST,		//SMG
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SWORD_SLOW,
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SWORD_FAST,
	ACTION_ADVANCEMENT_SLAYER_ATTACK_BLADE_SLOW,
	ACTION_ADVANCEMENT_SLAYER_ATTACK_BLADE_FAST,
	ACTION_ADVANCEMENT_SLAYER_SKILL_SWORD_SLOW,
	ACTION_ADVANCEMENT_SLAYER_SKILL_SWORD_FAST,
	ACTION_ADVANCEMENT_SLAYER_SKILL_BLADE_SLOW,
	ACTION_ADVANCEMENT_SLAYER_SKILL_BLADE_FAST,
};
	
int AdvancementVampireActionConvTable[ ACTION_MAX_SLAYER ] =
{
	ACTION_ADVANCEMENT_STOP,
	ACTION_ADVANCEMENT_MOVE,
	ACTION_ADVANCEMENT_ATTACK_NORMAL,
	ACTION_ADVANCEMENT_MAGIC,
	ACTION_ADVANCEMENT_DAMAGED,
	ACTION_ADVANCEMENT_DRAINED,
	ACTION_ADVANCEMENT_DIE,
	ACTION_ADVANCEMENT_DRAIN,
	ACTION_ADVANCEMENT_ATTACK_SLOW,				
	ACTION_ADVANCEMENT_ATTACK_FAST,
	ACTION_ADVANCEMENT_SKILL_SLOW,		// 10
	ACTION_ADVANCEMENT_SKILL_NORMAL,	// 11
	ACTION_ADVANCEMENT_SKILL_FAST,		// 12
	ACTION_ADVANCEMENT_MAGIC_ATTACK,
	ACTION_ADVANCEMENT_SPECIAL,
	ACTION_ADVANCEMENT_CREATE_WEAPON,
	ACTION_ADVANCEMENT_DESTROY_WEAPON,	// 16
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,

	-1,
	-1,
	-1, // 30
	-1,
	-1,
	-1,
	-1,
};

/*
int AdvancementOustersActionConvTable[ ACTION_MAX_SLAYER ] =
{
	ACTION_STAND,		// ���� ���� ��ȯ �ʿ�
	ACTION_MOVE,		// ���� ���� ��ȯ �ʿ�
	ACTION_ADVANCEMENT_OUSTERS_COMBO_NORMAL , //ACTION_ADVANCEMENT_OUSTERS_ATTACK_NORMAL,
	ACTION_ADVANCEMENT_OUSTERS_MAGIC,
	ACTION_ADVANCEMENT_OUSTERS_DAMAGED,
	ACTION_ADVANCEMENT_OUSTERS_DRAINED,
	ACTION_ADVANCEMENT_OUSTERS_DIE,
	ACTION_STAND,		// ���� ���� ��ȯ �ʿ�	(���ֱ�)
	ACTION_MOVE,		// ���� ���� ��ȯ �ʿ�	(�ȱ�)
	ACTION_ADVANCEMENT_OUSTERS_COMBO_NORMAL,		//ACTION_ADVANCEMENT_OUSTERS_SKILL_NORMAL,
	ACTION_ADVANCEMENT_OUSTERS_MAGIC_ATTACK,
	ACTION_ADVANCEMENT_OUSTERS_ABSORB_SOUL,
	ACTION_ADVANCEMENT_OUSTERS_FAST_MOVE_STOP,		// ���� ���� ��ȯ �ʿ�	(��������)
	ACTION_ADVANCEMENT_OUSTERS_FAST_MOVE,		    // ���� ���� ��ȯ �ʿ�  (�����̵�)
	ACTION_ADVANCEMENT_OUSTERS_COMBO_SLOW ,			// ACTION_ADVANCEMENT_OUSTERS_ATTACK_SLOW,
	ACTION_ADVANCEMENT_OUSTERS_COMBO_FAST,			// ACTION_ADVANCEMENT_OUSTERS_ATTACK_FAST,
	ACTION_ADVANCEMENT_OUSTERS_COMBO_SLOW,			//ACTION_ADVANCEMENT_OUSTERS_SKILL_SLOW,
	ACTION_ADVANCEMENT_OUSTERS_COMBO_FAST ,			//ACTION_ADVANCEMENT_OUSTERS_SKILL_FAST,
	-1,
};

int AdvancementSlayerActionConvTable[ ACTION_MAX_SLAYER ] = 
{
	ACTION_STAND,	// ���� ���� ��ȯ �ʿ�
	ACTION_MOVE,	// ���� ���� ��ȯ �ʿ�
	-1,	// ���� ���� ��ȯ �ʿ�
	ACTION_ADVANCEMENT_SLAYER_MAGIC,
	ACTION_DAMAGED,
	ACTION_ADVANCEMENT_SLAYER_DRAINED,
	ACTION_ADVANCEMENT_SLAYER_DIE,
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_NORMAL,		//SR
	ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_NORMAL,		//AR
	ACTION_ADVANCEMENT_SLAYER_COMBO_SWARD_NORMAL,		//ACTION_ADVANCEMENT_SLAYER_ATTACK_SWORD_NORMAL,
	ACTION_ADVANCEMENT_SLAYER_COMBO_BLADE_NORMAL,		//ACTION_ADVANCEMENT_SLAYER_ATTACK_BLADE_NORMAL,
	-1,													//��ź ������
	ACTION_ADVANCEMENT_SLAYER_BIKE_MOVE,
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_NORMAL,		//SG
	ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_NORMAL,		//SMG
	ACTION_ADVANCEMENT_SLAYER_COMBO_SWARD_NORMAL,		//ACTION_ADVANCEMENT_SLAYER_SKILL_SWORD_NORMAL,
	ACTION_ADVANCEMENT_SLAYER_COMBO_BLADE_NORMAL,		//ACTION_ADVANCEMENT_SLAYER_SKILL_BLADE_NORMAL,
	-1,													//���� ������
	ACTION_ADVANCEMENT_SLAYER_BIKE_STOP,				//18
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_SLOW,		//SR
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_FAST,		//SR
	ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_SLOW,		//AR
	ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_FAST,		//AR
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_SLOW,		//SG
	ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_FAST,		//SG
	ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_SLOW,		//SMG
	ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_FAST,		//SMG
	ACTION_ADVANCEMENT_SLAYER_COMBO_SWARD_SLOW,			//ACTION_ADVANCEMENT_SLAYER_ATTACK_SWORD_SLOW,
	ACTION_ADVANCEMENT_SLAYER_COMBO_SWARD_FAST,			//ACTION_ADVANCEMENT_SLAYER_ATTACK_SWORD_FAST,
	ACTION_ADVANCEMENT_SLAYER_COMBO_BLADE_SLOW,			//ACTION_ADVANCEMENT_SLAYER_ATTACK_BLADE_SLOW,
	ACTION_ADVANCEMENT_SLAYER_COMBO_BLADE_FAST,			//ACTION_ADVANCEMENT_SLAYER_ATTACK_BLADE_FAST,
	ACTION_ADVANCEMENT_SLAYER_COMBO_SWARD_SLOW,			//ACTION_ADVANCEMENT_SLAYER_SKILL_SWORD_SLOW,
	ACTION_ADVANCEMENT_SLAYER_COMBO_SWARD_FAST,			//ACTION_ADVANCEMENT_SLAYER_SKILL_SWORD_FAST,
	ACTION_ADVANCEMENT_SLAYER_COMBO_BLADE_SLOW,			//ACTION_ADVANCEMENT_SLAYER_SKILL_BLADE_SLOW,
	ACTION_ADVANCEMENT_SLAYER_COMBO_BLADE_FAST,			//ACTION_ADVANCEMENT_SLAYER_SKILL_BLADE_FAST,
};
	
int AdvancementVampireActionConvTable[ ACTION_MAX_SLAYER ] =
{
	ACTION_ADVANCEMENT_STOP,
	ACTION_ADVANCEMENT_MOVE,
	ACTION_ADVANCEMENT_COMBO_NORMAL ,	//ACTION_ADVANCEMENT_ATTACK_NORMAL,
	ACTION_ADVANCEMENT_MAGIC,
	ACTION_ADVANCEMENT_DAMAGED,
	ACTION_ADVANCEMENT_DRAINED,
	ACTION_ADVANCEMENT_DIE,
	ACTION_ADVANCEMENT_DRAIN,
	ACTION_ADVANCEMENT_COMBO_SLOW,		//ACTION_ADVANCEMENT_ATTACK_SLOW,				
	ACTION_ADVANCEMENT_COMBO_FAST,		//ACTION_ADVANCEMENT_ATTACK_FAST,
	ACTION_ADVANCEMENT_COMBO_SLOW,		//ACTION_ADVANCEMENT_SKILL_SLOW,		// 10
	ACTION_ADVANCEMENT_COMBO_NORMAL,	//ACTION_ADVANCEMENT_SKILL_NORMAL,	// 11
	ACTION_ADVANCEMENT_COMBO_FAST ,		//ACTION_ADVANCEMENT_SKILL_FAST,		// 12
	ACTION_ADVANCEMENT_MAGIC_ATTACK,
	ACTION_ADVANCEMENT_SPECIAL,
	ACTION_ADVANCEMENT_CREATE_WEAPON,
	ACTION_ADVANCEMENT_DESTROY_WEAPON,	// 16
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1,
	-1, // 30
	-1,
	-1,
	-1,
	-1,
};


int AdvanceComboActionFrameTable[7][3][4] = 
{
	// �����̾� �� / ���� ��  
	13,26,39,58, 10,21,32,49, 8,17,26,41 ,
	13,26,39,58, 10,21,32,49, 8,17,26,41 ,

	// �����̾� �� / ���� ��
	14,29,44,65, 12,25,38,57, 10,21,32,49 ,
	14,29,44,65, 12,25,38,57, 10,21,32,49 ,

	// �����̾� �� / ����
	12,25,38,57, 10,21,32,49, 8,17,26,41,  
	12,26,40,59, 10,21,32,49, 8,17,26,41,  

    // �ƿ콺��  
	12,26,40,59, 10,21,32,49, 8,17,26,41 ,
};


int AdvanceComboNextActionTable[12] = 
{
	// �����̾�
	ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_SWARD_SLOW,
	ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_SWARD_NORMAL,
	ACTION_ADVANCEMENT_SLAYERN_COMBO_CANCEL_SWARD_FAST,

	ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_BLADE_SLOW,
	ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_BLADE_NORMAL,
	ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_BLADE_FAST,
	
	// �����̾�
	ACTION_ADVANCEMENT_OUSTERS_COMBO_CANCEL_SLOW ,//ACTION_ADVANCEMENT_COMBO_CANCEL_SLOW,
	ACTION_ADVANCEMENT_OUSTERS_COMBO_CANCEL_SLOW,//ACTION_ADVANCEMENT_COMBO_CANCEL_NORMAL,
	ACTION_ADVANCEMENT_OUSTERS_COMBO_CANCEL_SLOW,//ACTION_ADVANCEMENT_COMBO_CANCEL_FAST,
    // �ƿ콺��
	ACTION_ADVANCEMENT_OUSTERS_COMBO_CANCEL_SLOW,
	ACTION_ADVANCEMENT_OUSTERS_COMBO_CANCEL_NORMAL,
	ACTION_ADVANCEMENT_OUSTERS_COMBO_CANCEL_FAST,
};




int AdvanceComboNextRepeatActionTable[12] = 
{
	// �����̾�
	ACTION_SLAYER_SWORD_SLOW,
	ACTION_SLAYER_SWORD,
	ACTION_SLAYER_SWORD_FAST,

	ACTION_SLAYER_BLADE_SLOW,
	ACTION_SLAYER_BLADE,
	ACTION_SLAYER_BLADE_FAST,
	
	// �����̾�
	ACTION_VAMPIRE_ATTACK_SLOW ,
	ACTION_ATTACK,
	ACTION_VAMPIRE_ATTACK_FAST,
    // �ƿ콺��
	ACTION_OUSTERS_ATTACK_SLOW,
	ACTION_ATTACK,
	ACTION_OUSTERS_ATTACK_FAST,
};


int AdvanceComboCancelFrameTable[5][3][3] = 
{
	// �����̾� �� / ���� 
	1,3,5, 1,3,5, 1,3,5,
	1,3,5, 1,3,5, 1,3,5,
	// �����̾� �� / ���� 
	1,3,5, 1,3,5, 1,3,5,
	1,3,5, 1,3,5, 1,3,5,
    // �ƿ콺��
	1,3,5, 1,3,5, 1,3,5,
};
*/

BYTE GetCreatureActionCountMax( const MCreature* pCreature, int action );

int GetAdvancementVampireActionFromVampireAction( int CurAction, const MCreature* pCreature )
{
	if( CurAction >= ADVANCEMENT_ACTION_START )
		return CurAction;

	return AdvancementVampireActionConvTable[ CurAction ];
}

int GetAdvancementPartFromItemClass( ITEM_CLASS itemClass , TYPE_FRAMEID frameID)
{
//	assert(false && "���� ���333");

	switch( itemClass )
	{
	case ITEM_CLASS_MOTORCYCLE :
		{
			if(frameID == AC_BIKE_2)
				return AC_BIKE_2;
			return AC_BIKE_1;
		}
		
	case ITEM_CLASS_SWORD :
		return AC_SWORD;

	case ITEM_CLASS_BLADE :
		return AC_BLADE;

	case ITEM_CLASS_AR :
		return AC_GUN_AR;

	case ITEM_CLASS_SG :
	case ITEM_CLASS_SMG :
	case ITEM_CLASS_SR :
		return AC_GUN_SR;

	case ITEM_CLASS_MACE :
		return AC_MACE;

	case ITEM_CLASS_CROSS :
		return AC_CROSS;

	case ITEM_CLASS_SHIELD :
		return AC_SHIELD;

	case ITEM_CLASS_HELM :
		return AC_HELMET;

	case ITEM_CLASS_COAT :
	case ITEM_CLASS_TROUSER :
		return AC_BODY;

	case ITEM_CLASS_SHOULDER_ARMOR :
		return AC_SHOULDER;
	}

	return -1;
}

int	GetAdvancementSlayerStandActionFromItemClass( ITEM_CLASS itemclass )
{
	switch( itemclass )
	{
	case ITEM_CLASS_SWORD :
		return ACTION_ADVANCEMENT_SLAYER_STOP_SWORD;

	case ITEM_CLASS_BLADE :
		return ACTION_ADVANCEMENT_SLAYER_STOP_BLADE;

	case ITEM_CLASS_SG :
	case ITEM_CLASS_SMG :
	case ITEM_CLASS_AR :
	case ITEM_CLASS_SR :
		return ACTION_ADVANCEMENT_SLAYER_STOP_GUN;		
	}

	return ACTION_ADVANCEMENT_SLAYER_STOP_MACE_AND_CROSS;
}

int GetAdvancementSlayerMoveActionFromItemClass( ITEM_CLASS itemclass )
{
	switch( itemclass )
	{
	case ITEM_CLASS_SWORD :
		return ACTION_ADVANCEMENT_SLAYER_MOVE_SWORD;

	case ITEM_CLASS_BLADE :
		return ACTION_ADVANCEMENT_SLAYER_MOVE_BLADE;

	case ITEM_CLASS_SG :
	case ITEM_CLASS_SMG :
	case ITEM_CLASS_AR :
	case ITEM_CLASS_SR :
		return ACTION_ADVANCEMENT_SLAYER_MOVE_GUN;
	}

	return ACTION_ADVANCEMENT_SLAYER_MOVE_MACE_AND_CROSS;
}

int GetAdvancementSlayerDamagedActionFromItemClass( ITEM_CLASS itemclass )
{
	switch( itemclass )
	{
	case ITEM_CLASS_SWORD :
		return ACTION_ADVANCEMENT_SLAYER_DAMAGED_SWORD;

	case ITEM_CLASS_BLADE :
		return ACTION_ADVANCEMENT_SLAYER_DAMAGED_BLADE;

	case ITEM_CLASS_SG :
	case ITEM_CLASS_SMG :
	case ITEM_CLASS_AR :
	case ITEM_CLASS_SR :
		return ACTION_ADVANCEMENT_SLAYER_DAMAGED_GUN;
	}

	return ACTION_ADVANCEMENT_SLAYER_DAMAGED_CROSS_MACE;
}

int GetAdvancementSlayerAttackActionFromItemClass( ITEM_CLASS itemClass, MCreature* pCreature )
{
	switch( itemClass )
	{
	case ITEM_CLASS_AR :
		return ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_SLOW + pCreature->GetWeaponSpeed();
	
	case ITEM_CLASS_SG :
	case ITEM_CLASS_SMG :
	case ITEM_CLASS_SR :
		return ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_SLOW + pCreature->GetWeaponSpeed();
	}

	return -1;
}

int ConvAdvancementSlayerActionFromSlayerAction( int CurAction, MCreatureWear* pCreatureWear )
{
	Assert( pCreatureWear != NULL );

	if( ADVANCEMENT_ACTION_START <= CurAction )
		return CurAction;

	const MCreatureWear::ADDON_INFO& addon = pCreatureWear->GetAddonInfo( ADDON_RIGHTHAND );

	switch( CurAction )
	{
	case ACTION_DAMAGED :
		return GetAdvancementSlayerDamagedActionFromItemClass( addon.ItemClass );

	case ACTION_STAND :
		return GetAdvancementSlayerStandActionFromItemClass( addon.ItemClass );		
		
	case ACTION_MOVE :
		return GetAdvancementSlayerMoveActionFromItemClass( addon.ItemClass );
/*
	case ACTION_SLAYER_GUN_SR :
	case ACTION_SLAYER_GUN_AR :
	case ACTION_SLAYER_GUN_SG :
	case ACTION_SLAYER_GUN_SMG :
		case ACTION_SLAYER_GUN_SR_SLOW :
		return GetAdvancementSlayerAttackActionFromItemClass( addon.ItemClass, pCreatureWear );*/
	}	

	return AdvancementSlayerActionConvTable[ CurAction ];
};

int ConvAdvancementOustersActionFromOusterAction( int CurAction, bool bChakram )
{
	if( ADVANCEMENT_ACTION_START <= CurAction )
		return CurAction;

	switch( CurAction )
	{
	case ACTION_STAND :
		if( bChakram )
			return ACTION_ADVANCEMENT_OUSTERS_CHAKRAM_STOP;
		else
			return ACTION_ADVANCEMENT_OUSTERS_WRISTLET_STOP;
		
	case ACTION_MOVE :
		if( bChakram )
			return ACTION_ADVANCEMENT_OUSTERS_CHAKRAM_MOVE;
		else
			return ACTION_ADVANCEMENT_OUSTERS_WRISTLET_MOVE;
	}
	
	if( CurAction > ACTION_OUSTERS_CHAKRAM_FAST )
		return -1;

	return AdvancementOustersActionConvTable[ CurAction ];
}

bool IsEscapeDrawCreatureFunction( MCreature* pCreature )
{
	bool InGroundElemental = pCreature->IsOusters() && pCreature->IsPlayer() && g_pPlayer->IsOusters() == false
							&& pCreature->IsInGroundElemental();

	bool bGhost = pCreature->HasEffectStatus(EFFECTSTATUS_GHOST) || g_pEventManager->GetEventByFlag(EVENTFLAG_NOT_DRAW_CREATURE)
		|| pCreature->IsGhost(1) && pCreature->IsGhost(2) && pCreature->IsGhost(4);

		
	// 2004, 6, 7 sobeit add start - ���� ��� ������ ��ũ�Ͻ� �ȿ� ������ �Ⱥ��̰�..
	bool bPet1 = false;
	if(pCreature->IsFakeCreature())
	{
		MCreature *OwnerCreature = g_pZone->GetCreature(((MFakeCreature*)pCreature)->GetOwnerID());
		if(NULL != OwnerCreature)
		{
			if(OwnerCreature->IsInDarkness())
				bPet1 = true;
		}
	}

	bool bBlind = false;
	if(
		(g_pPlayer->HasEffectStatus(EFFECTSTATUS_YELLOW_POISON_TO_CREATURE) || 
		g_pPlayer->HasEffectStatus(EFFECTSTATUS_FLARE )||
		g_pPlayer->HasEffectStatus(EFFECTSTATUS_BLINDNESS))
		&& pCreature != g_pPlayer 
		)
	{
		// �Ÿ��� ���� ��� ���θ� �����Ѵ�.
		int sx,sy,ex,ey;

		sx = g_pPlayer->GetX() - 1;
		ex = g_pPlayer->GetX() + 1;

		sy = g_pPlayer->GetY() - 1;
		ey = g_pPlayer->GetY() + 1;

		if( pCreature->GetX() < sx || pCreature->GetX() > ex ||
			pCreature->GetY() < sy || pCreature->GetY() > ey )
			bBlind = true;
	}


	return InGroundElemental || bGhost || bPet1 || bBlind;
}

//----------------------------------------------------------------------
// Draw Creature : character ����ϱ�	
//----------------------------------------------------------------------
// pSurface�� pPoint�� pCreature�� ����Ѵ�.
//----------------------------------------------------------------
void	
MTopView::DrawCreature(POINT* pPoint, MCreature* pCreature)
{	
	// EFFECTSTATUS_GHOST �� �ɷ������� ���� ������ ���� ������
	//DEBUG_ADD_FORMAT("[DrawCreature] Start %s %s %s", pCreature->IsGhost(1)?"true":"false", pCreature->IsGhost(2)?"true":"false", pCreature->IsGhost(4)?"true":"false");
	if( IsEscapeDrawCreatureFunction( pCreature ) )
		return;

	// 2004, 6, 7 sobeit add end
	__BEGIN_PROFILE("DrawCreature");

	int body, action, direction, frame, creature_type, frameCount;

	frameCount  = pCreature->GetCreatureFrameCount();

	for(int FrameIndex = 0; FrameIndex< frameCount ; FrameIndex++)
	{
		body		= pCreature->GetCreatureFrameID(FrameIndex);
		action		= pCreature->GetAction();
		direction	= pCreature->GetDirection();
		frame		= pCreature->GetFrame();//%m_CreatureFPK[body][action][direction].GetCount();
		creature_type = pCreature->GetCreatureType();

	//	if(action>ACTION_OUSTERS_MAGIC_ATTACK)
	//		int i = 0;
		//----------------------------------------------------------
		// Charm�� �ɷ� �ִ� ĳ����..
		// �������ϴ� �������� ǥ��..
		//----------------------------------------------------------
		if (pCreature->HasEffectStatus(EFFECTSTATUS_CHARM))
		{
			action = ACTION_DRAINED;
			frame = 6 + (frame & 0x07);		// ���� ���ۿ��� �ݺ� frame�� ������ 6�̴�.		
		}
		if(pCreature->HasEffectStatus(EFFECTSTATUS_BIKE_CRASH))
			frame = 0;
		
		bool isSlayerCharacter	= pCreature->IsSlayerCharacter();
		//bool isOustersCharacter = pCreature->IsOusters();

		bool isOustersCharacter = (pCreature->IsOusters() && pCreature->GetCreatureType() != CREATURETYPE_OUSTERS_OPERATOR
								&&	creature_type != 717 && creature_type != 721 && creature_type != 723);
							
		
		// �ҷ簡 �ɷ����� �׼� �����ӵ��� �ٲٴµ�... �� ���� ���³� ���� ���¿����� 
		// �ٲ��� �ʵ��� �Ѵ�. �ϴ� ��ȹ���� ���ؼ� �ּ�ó���س��Ҵ�.
		if (pCreature->IsHallu()
	//		&& !pCreature->HasEffectStatus( EFFECTSTATUS_TRANSFORM_TO_BAT )
	//		&& !pCreature->HasEffectStatus( EFFECTSTATUS_TRANSFORM_TO_WOLF )
			&& !g_pPlayer->HasEffectStatus( EFFECTSTATUS_GHOST )
	#ifdef __METROTECH_TEST__
			&& !g_bLight
	#endif
			)
		{
			isSlayerCharacter = false;
			isOustersCharacter = false;

			body	= pCreature->GetHalluCreatureFrameID();
			action	= pCreature->GetHalluAction();
			frame	= pCreature->GetHalluFrame();
			creature_type = pCreature->GetHalluCreatureType();
		}

		//////////////////////////////////////////////////////
		// 2005.11.21 by chyaya
		// �ҷ�ó��̼ǿ� �ɷ��� ��� ĳ���͸� ���ͷ� ó���ϱ� ������
		// ���� ĳ���ͷ� ������� �ʰ� �Ϲ� ĳ���ͷ� ����� ó���Ѵ�.
		// �Ʒ��� ������ ����Ͽ� �ϵ� �ڵ��ߴ� -_-;;

			bool bHallu = pCreature->IsHallu();

		//
		//////////////////////////////////////////////////////

		bool bGildreDead = false;
		bool bSlayerPet_ShowTurret = false;
		GENERATE_OPTION  OutLineOption = GENERATE_ALL;
		// 2004, 7, 23 sobeit modify start

		// 2004.12.9 created exception processing function by sonee
		std::map< DWORD, DrawCreatureExceptionProc >::iterator itr = m_ExceptionProcMap.find( creature_type );

		if( m_ExceptionProcMap.end() != itr )
			itr->second( pCreature, action, frame, direction );

		switch(creature_type)
		{		
		case 717:
		case 721:
			if(pCreature->IsDead())
			{
				if(pCreature->GetActionCount()>=pCreature->GetActionCountMax())
					bGildreDead = true;
			}
			break;
		case 702:
		case 703:
		case 704:
			if( action == ACTION_STAND || action == ACTION_MOVE )
				bSlayerPet_ShowTurret = true;
			break;
		case 726: // ���� 4��
		case 727:
		case 728:
		case 729:
			{
				MCreature* TempCreature = g_pZone->GetCreature(m_SelectCreatureID);
				if(TempCreature != NULL)
				{
					if(	TempCreature->GetCreatureType() == 726 ||
						TempCreature->GetCreatureType() == 727 ||
						TempCreature->GetCreatureType() == 728 ||
						TempCreature->GetCreatureType() == 729 )
					{
						if(creature_type == 726)
							OutLineOption = GENERATE_EXCEPT_RIGHT;
						else if(creature_type == 727 || creature_type == 728 )
							OutLineOption = GENERATE_EXCEPT_SIDE;
						else if(creature_type == 729)
							OutLineOption = GENERATE_EXCEPT_LEFT;
					}
				}
			}
			break;
		case 753 :
			if(pCreature->IsDead())
			{
				action = ACTION_DIE;
				if(pCreature->GetActionCount()>=pCreature->GetActionCountMax()) return;
			}
			break;

		case 767:// ���� ����
			{
				if(direction == 0 || direction == 4)
				{
					pPoint->y -= g_nRocketPosValue[frame];
//					pPoint->y -= sin((double)pCreature->GetMoveCount()*3.141592/(double)pCreature->GetMoveCountMax())*5;
				}
				else 
				{
					pPoint->x -= g_nRocketPosValue[frame];
//					pPoint->x -= sin((double)pCreature->GetMoveCount()*3.141592/(double)pCreature->GetMoveCountMax())*5;
				}
			}
			frame = 0;
			action = ACTION_MOVE;
		
			break;
		case 769:
			if(pCreature->IsDead())
				return;
			break;

		}
		// 2004, 7, 23 sobeit modify end
		
		// 2004, 11, 22, sobeit add start - set afire ����
		//int		ComboActionCnt = pCreature->GetCombo();
		//int		MaxFrame       = pCreature->GetActionCountMax();
		if(pCreature->GetID() != g_pPlayer->GetID())
		{
			if(pCreature->GetSpecialActionInfo() == SKILL_SET_AFIRE)
			{
				if(action == ACTION_ATTACK || action == ACTION_VAMPIRE_ATTACK_SLOW || action == ACTION_VAMPIRE_ATTACK_FAST)
				{
					action = ACTION_ATTACK;
					frame = 3+((frame)%4);
				}
			}
			// �޺� Action �϶� ó��  Sjheon 2005.06.10 Add
			//if(pCreature->IsAdvancementClass())  // �޺� ����� ���� �ɷ��� �� �����ϴ�  Sjheon 2005.06.10
			//	frame = GetAdvancementComboFrame(pCreature ,frame , action , ComboActionCnt , MaxFrame) ; 
			// �޺� Action �϶� ó��  Sjheon 2005.06.10 End
		}
		else
		{
			if(pCreature->GetUsedActionInfo() == SKILL_SET_AFIRE)
			{
				if(action == ACTION_ATTACK || action == ACTION_VAMPIRE_ATTACK_SLOW || action == ACTION_VAMPIRE_ATTACK_FAST)
				{
					action = ACTION_ATTACK;
					frame = 3+((frame)%4);
				}
			}
            // �޺� Action �϶� ó��  Sjheon 2005.06.10 Add
			//if(pCreature->IsAdvancementClass())  // �޺� ����� ���� �ɷ��� �� �����ϴ�  Sjheon 2005.06.10
			//	frame = GetAdvancementComboFrame(pCreature ,frame , action , ComboActionCnt , MaxFrame) ; 
			// �޺� Action �϶� ó��  Sjheon 2005.06.10 End
		}
		// 2004, 11, 22, sobeit add end - set afire ����
		// ������ ������ �Ʒ�, ũ��������Ʈ��


		if(pCreature->IsFakeDie())
			frame = 0;
	
		int	creatureID			= pCreature->GetID();
		bool bPlayerVampire = 
				(*g_pCreatureSpriteTable)[(*g_pCreatureTable)[creature_type].SpriteTypes[0]].IsPlayerVampireOnlySprite()
	//			&& (pCreature==g_pPlayer || pCreature->HasEffectStatus(EFFECTSTATUS_COMA))
				&& (pCreature->GetActionCount()>=pCreature->GetActionCountMax()	)
				&& !pCreature->IsExistAttachEffect()
				&& pCreature->IsDead();

		bool bTeenVersion = 
				(
					g_pUserInformation->GoreLevel == false
					&& !(
					creature_type >= 526 && creature_type <= 549 || 
					creature_type >= 371 && creature_type <= 376 || 
					creature_type >= 560 && creature_type <= 563 || 
					creature_type == 482 || 
					creature_type == 650 || 
					creature_type == 670 || 
					creature_type == 672 ||
					creature_type == 673 ||
					creature_type == 730 || // ���� ����Ʈ1
					creature_type == 731 || // ���� ����Ʈ2
					creature_type == 732 || // ���� ����Ʈ3
					creature_type == 636 // ���� ���� ������

					)	// ���� // ũ���� ���� Ʈ��
					|| creature_type >= 377 && creature_type <= 386	// ��ũ ������� ������ ǥ��
					|| creature_type == 480 
				)
				&&
				(
					pCreature->GetActionCount()>=pCreature->GetActionCountMax()/2
					&& pCreature->IsDead()
				)
				&&
				(
					creature_type < 431		// ���丮
					|| creature_type > 436	// ������
				);

		//---------------------------------------------------------
		// PC Vampire�� ��� ������ '����'�� ǥ���Ѵ�.
		//
		// player�� �׾ ���������� ������ �ʱ� ������..
		// ƾ�������� ��� ��ü�� '����'�� ǥ���Ѵ�.
		//---------------------------------------------------------	
		if (bPlayerVampire || bTeenVersion || bGildreDead )
		{
			{
				CSprite* pSprite;
				
				if(pCreature->IsSlayer())
				{
					pSprite = &m_EtcSPK[ SPRITEID_SLAYER_CROSS ];
					// ��ǥ ����
					pointTemp.x = pPoint->x - 5+20;
					pointTemp.y = pPoint->y - 30;				
				}
				//else if((*g_pCreatureSpriteTable)[(*g_pCreatureTable)[creature_type].SpriteType].IsPlayerVampireOnlySprite())
				else if((*g_pCreatureSpriteTable)[(*g_pCreatureTable)[creature_type].SpriteTypes[0]].IsPlayerVampireOnlySprite())
				{
					pSprite = &m_EtcSPK[ SPRITEID_VAMPIRE_DUST ];
					// ��ǥ ����
					pointTemp.x = pPoint->x - 5;
					pointTemp.y = pPoint->y;				
				}
				else
				{
					pSprite = &m_EtcSPK[ SPRITEID_MONSTER_DUST ];
					// ��ǥ ����
					pointTemp.x = pPoint->x - 5;
					pointTemp.y = pPoint->y;				
				}


				// ���õ� ���� ���
				if (m_SelectItemID == creatureID
					|| m_SelectCreatureID == creatureID)
				{
					m_SOMOutlineColor = m_ColorOutlineItem;
					
					m_SOM.Add( pointTemp.x, pointTemp.y, pSprite );
					
					m_SOM.Generate();

					m_pSurface->BltSpriteOutline( &m_SOM, m_SOMOutlineColor );
					
					//---------------------------------------- 	
					// �̸� ����� ��ǥ ����
					//---------------------------------------- 	
					const int FontHeight = g_pClientConfig->FONT_HEIGHT;
					const int FontHeight2 = FontHeight << 1;
					
					pointTemp.x = pPoint->x;			
					if (pointTemp.x<0) pointTemp.x=0;
					
					//---------------------------------------- 	
					// Level Name ���� ��ġ�� ���
					//---------------------------------------- 	
					if (pCreature->HasLevelName())
					{
						pointTemp.y = pPoint->y - FontHeight2;
						
						if (pointTemp.y < FontHeight2)
						{
							pointTemp.y = FontHeight2;
						}
					}
					//---------------------------------------- 	
					// �׳� �̸��� ���� ��
					//---------------------------------------- 	
					else
					{
						pointTemp.y = pPoint->y - FontHeight;
						
						if (pointTemp.y < FontHeight) 
						{
							pointTemp.y = FontHeight;
						}
					}
					
					m_pointChatString	= pointTemp;
					m_pSelectedCreature = pCreature;
				}
				else
				{
					m_pSurface->BltSprite(&pointTemp, pSprite);	
				}			

				//------------------------------------------------
				// ���� ĳ�����̸� ���� �簢����
				// �� Tile ũ��� �����Ѵ�.
				//------------------------------------------------
				RECT rect;
				rect.left	= pPoint->x;
				rect.top	= pPoint->y;
				rect.right	= pPoint->x + TILE_X;
				rect.bottom = pPoint->y + TILE_Y;
				if(FrameIndex ==0 )	
					pCreature->SetScreenRect( &rect );
				
	#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD("EndDrawCreature-S");
	#endif
				
				
				if(pCreature->GetActionCount()>=pCreature->GetActionCountMax()/2)
				{
					if (pCreature->IsExistAttachEffect())
					{	
	#ifdef OUTPUT_DEBUG_DRAW_PROCESS
						DEBUG_ADD("DrawAttachEffect");
	#endif
						
						pointTemp = *pPoint;
						//pointTemp.x += pCreature->GetSX();
						//pointTemp.y += pCreature->GetSY();
						
						DrawAttachEffect(&pointTemp, 
							pCreature->GetAttachEffectIterator(), 
							pCreature->GetAttachEffectSize(),
							pCreature,
							1);	// foreground���
						
	#ifdef OUTPUT_DEBUG_DRAW_PROCESS
						DEBUG_ADD("DAE ok");
	#endif
					}
				}
				m_pSurface->Unlock();
				const int firstY = DrawChatString(&pointTemp, pCreature, pCreature->GetChatColor());//CDirectDraw::Color(26,26,26));		
				pointTemp.y = firstY;
				DrawCreatureHPModify(&pointTemp, pCreature);
				m_pSurface->Lock();	
				return;
			}
		}

		//------------------------------------------------
		// Slayer�� ��� Darkness ���� �� �� ����.
		//------------------------------------------------
		if (
			!( creature_type >= 526 && creature_type <= 549 || 
			   creature_type == 670 || 
			   creature_type == 672 ||
			   creature_type == 673 ||
			   creature_type >= 371 && creature_type <= 376 || 
			   creature_type >= 560 && creature_type <= 563
			 ) &&
			pCreature->IsInDarkness() && !pCreature->IsNPC() && !g_pPlayer->IsVampire() && g_pPlayer!=pCreature
			&& !g_pPlayer->HasEffectStatus( EFFECTSTATUS_LIGHTNESS )
			&& g_pZone->GetID() != 3001
			&& !g_pPlayer->HasEffectStatus( EFFECTSTATUS_GHOST )
	#ifdef __METROTECH_TEST__
			&& !g_bLight
	#endif
			)
		{
			#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD("EndDrawCreature-D");
			#endif

			return;
		}

		//------------------------------------------------
		//
		// �� �ӿ� �Ĺ��� �ֵ��� ������ �׸�..
		//
		//------------------------------------------------
		// 2004, 04, 24 sobeit modify - ���巹 ���� ghost�� ���� ũ�������� ������ �׸��� �ƴ�..^^;
		if (pCreature->IsUndergroundCreature() && pCreature->GetCreatureType() != CREATURETYPE_GHOST)
		{
			DrawUndergroundCreature(pPoint, pCreature );
			#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD( "End DrawCreature" );
			#endif		

			return;
		}

		//----------------------------------------------------------
		// �Ӹ��� ���� ���
		//----------------------------------------------------------
		if (!pCreature->HasHead()
			&& pCreature->GetActionCount()==pCreature->GetActionCountMax()
			&& g_pUserInformation->GoreLevel == true)
		{
			if (action==ACTION_DIE)
			{
				// �����δ�..������ frame + 1�̴�.
				//frame	= (*g_pCreatureTable)[creature_type].GetActionCount( action );
				frame	= GetCreatureActionCountMax( pCreature, action);
			}
		}

		// Teen������ ��� �״� ���� �ִϸ��̼� ����
		// ó���� �������������������� ���۸� 0���� �����ߴµ� �� ���ʿ��� ��� ���� ��� return�ع����� �ǹ̾���
		if(g_pUserInformation->GoreLevel == false && action == ACTION_DIE
			&&	(
					creature_type < 431		// ���丮
					|| creature_type > 436	// ������
				)
			)
		{
			frame = 0;
		}
		
		// Creature�� �����ϴ� ���̸�ŭ ���ش�.
		pPoint->y -= pCreature->GetZ();

		if(!pCreature->IsNPC() &&  pCreature->HasEffectStatus(EFFECTSTATUS_DIVINE_GUIDANCE))
		{	
			if(isSlayerCharacter)
			{
				if( pCreature->IsAdvancementClass() && !bHallu )
					DrawDivineGuidanceAdvancementClassSlayerCharacter( pPoint, pCreature, direction );
				else
					DrawDivineGuidanceSlayerCharacter( pPoint, pCreature, direction );
			}
			else if(isOustersCharacter)
			{
				if( pCreature->IsAdvancementClass() && !bHallu )
					DrawDivineGuidanceAdvancementClassOustersCharacter( pPoint, pCreature, direction );
				else
					DrawDivineGuidanceOustersCharacter( pPoint, pCreature, direction );				
			}
			else
			{
				if( pCreature->IsAdvancementClass() && !bHallu )
					DrawDivineGuidanceAdvancementClassVampireCharacter( pPoint, pCreature, direction, body );
				else
					DrawDivineGuidanceVampireCharacter( pPoint, pCreature, direction, body );
			}
		}

		//----------------------------------------
		// �ٴڿ� ���� Effect ���
		//----------------------------------------
		if (pCreature->IsExistGroundAttachEffect())
		{				
			pointTemp = *pPoint;
			//pointTemp.x += pCreature->GetSX();
			//pointTemp.y += pCreature->GetSY();

			DrawAttachEffect(&pointTemp, pCreature->GetGroundAttachEffectIterator(), pCreature->GetGroundAttachEffectSize(), pCreature);
		}

		//---------------------------------------------------------------
		//
		//                  Background AttachEffectNode ���
		//
		//---------------------------------------------------------------
		if (pCreature->IsExistAttachEffect())
		{				
	//		DEBUG_ADD("BackAttachEffect");

			pointTemp = *pPoint;
			//pointTemp.x += pCreature->GetSX();
			//pointTemp.y += pCreature->GetSY();

			DrawAttachEffect(&pointTemp, 
								pCreature->GetAttachEffectIterator(), 
								pCreature->GetAttachEffectSize(),
								pCreature,
								2);	// background���

	//		DEBUG_ADD("BAE ok");
		}

		//---------------------------------------------------------------
		//
		//                  Mouse�� ���� --> �ܰ���
		//
		//---------------------------------------------------------------

		//------------------------------------------------
		// Mouse�� ����Ű�� �ִ� Creature
		//------------------------------------------------
		
		if (m_SelectCreatureID == creatureID || OutLineOption)
		{			
			#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD("Sel Creature");
			#endif

			// SpriteOutlineManager�� �߰�
			if (pCreature->IsNPC()							// NPC�� ���
				// ���丮�� ���� �ȵȴ�. �ϵ��ڵ� - -;;
				&& !(creature_type==217)
				|| IsRequestMode()								// trade mode�� ���
					// player�� �ȴ�.
					//pCreature->GetCreatureType()<=CREATURETYPE_VAMPIRE_FEMALE				
				//	&& (*g_pCreatureSpriteTable)[(*g_pCreatureTable)[creature_type].SpriteType].IsPlayerOnlySprite()
				&& (*g_pCreatureSpriteTable)[(*g_pCreatureTable)[creature_type].SpriteTypes[0]].IsPlayerOnlySprite()
				|| !IsRequestMode()							// trade�ҷ��� �������� creature�� ���
					&& g_pPlayer->IsRequestMode() 
					&& g_pPlayer->IsTraceCreature() 
					&& g_pPlayer->GetTraceID()==creatureID)	
			{
				m_SOMOutlineColor = m_ColorOutlineNPC;
			}
			else if (g_pObjectSelector->CanAttack( pCreature )
				|| creature_type==217)		// ���丮�� ���. �ϵ��ڵ� - -;;
			{
				m_SOMOutlineColor = m_ColorOutlineAttackPossible;
			}
			else
			{
				m_SOMOutlineColor = m_ColorOutlineAttackImpossible;
			}

			#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD("drawBody");
			#endif
			
			//----------------------------------------
			//
			//         ���� �ִ� ��쿡 ���
			//
			//---------------------------------------- 		
			if (body!=FRAMEID_NULL)
			{
				// body ���� �ʿ�
				if( pCreature->IsAdvancementClass() && !bHallu )
					DrawSelectedAdvancementVampireCreature( pPoint, pCreature, action, direction, frame, 0, FrameIndex );
				else
					DrawSelectedVampireCreature( pPoint, pCreature, action, direction, frame, body, FrameIndex );
			}
			else
			{
				//----------------------------------------------------
				// ĳ������ ���� �簢�� ������ �����ش�.
				//----------------------------------------------------
				pCreature->ClearScreenRect();
			}
			
			#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD("draw clothes");
			#endif

			//----------------------------------------
			//
			//            ���� ���
			//
			//----------------------------------------
			// ��� ���� �� �ִ� ������ �� �߿��� 
			// �԰� �ִ� ���� Ȯ���ؼ� �������� �Ѵ�.		
			if (isSlayerCharacter)
			{		
				// 2004, 9, 15, sobeit add start  - install turret
				if(pCreature->HasEffectStatus(EFFECTSTATUS_INSTALL_TURRET))
					DrawInstallTurret( pPoint, pCreature, action, direction, frame, FrameIndex );
				else
				{
					if( pCreature->IsAdvancementClass() && !bHallu )
						DrawSelectedAdvancementSlayerCreature(pPoint, pCreature, action, direction, frame );
					else
						DrawSelectedSlayerCreature( pPoint, pCreature, action, direction, frame );
				}
			}
			else if(isOustersCharacter)
			{
				if( pCreature->IsAdvancementClass() && !bHallu )
					DrawSelectedAdvancementOustersCreature(pPoint, pCreature, action, direction, frame );
				else
					DrawSelectedOustersCreature( pPoint, pCreature, action, direction, frame );
			}
			
			// ���� ���� ���� �ͷ� ������ �ȴ�-��-;;;; �ϵ��ϵ�..�ƾ�-_-/~
			if( bSlayerPet_ShowTurret )
			{
				DrawCentauroTurret( pPoint, pCreature, action, direction, frame , body);				
			}
			m_SOM.Generate(OutLineOption);
			
	//			// 2004, 8, 18 sobeit add start - ������ ���� Ÿ���ö����� �������� �߰�..
	//		enum GENERATE_OPTION{
	//			GENERATE_ALL = 0,
	//			GENERATE_EXCEPT_LEFT,	// ���� �ƿ������� ����
	//			GENERATE_EXCEPT_RIGHT,  // ������ �ƿ������� ����
	//			GENERATE_EXCEPT_SIDE,	// �� ���̵� �ƿ������� ����
	//			// -_- ��,�Ʒ��� ����� ���� �ϳ�..-_-;
	//		};
	//		// 2004, 8, 18 sobeit add start
			//if (CDirect3D::IsHAL() || 
			//	DarkBits==0 || 
			//	g_pPlayer->GetID()==pCreature->GetID())
			//{	
			
				if (pCreature->IsInvisible() || pCreature->IsFakeDie()
	//				#ifdef OUTPUT_DEBUG
	//					||	g_pDXInput->KeyDown(DIK_RCONTROL)
	//				#endif
					)
				{
					// slayer�� invisible�� snipping
					if (pCreature->HasEffectStatus(EFFECTSTATUS_SNIPPING_MODE))
					{
						m_pSurface->BltSpriteOutlineDarkness( &m_SOM,  m_SOMOutlineColor, SHIFT_SNIPPING );
					}
					m_pSurface->BltSpriteOutlineOnly( &m_SOM,  m_SOMOutlineColor );
				}
				else
				{
					// ��Ӱ� ���
					if (pCreature->IsFade())
					{
						m_pSurface->BltSpriteOutlineDarkness( &m_SOM,  m_SOMOutlineColor, 1 );
					}
					else
					{
						m_pSurface->BltSpriteOutline( &m_SOM,  m_SOMOutlineColor );
					}
				}
				//m_pSurface->BltSpriteOutlineOnly( &m_SOM,  0xF800 );
			//}
			//else
			//{
			//	m_pSurface->BltSpriteOutlineDarkness( &m_SOM, m_SOMOutlineColor, DarkBits );
			//}		
				m_SOM.Clear();
			#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD("drawSelOK");
			#endif
		}
		//------------------------------------------------
		//
		//       �Ϲ����� Creature ���
		//
		//------------------------------------------------
		else
		{
			
			//------------------------------------------------
			//
			//         Body���
			//
			//------------------------------------------------
			if (body!=FRAMEID_NULL)
			{
				bool bBat = pCreature->GetCreatureType() == CREATURETYPE_BAT;
				bool bWolf = pCreature->GetCreatureType() == CREATURETYPE_WOLF;
				bool bWerWolf = pCreature->GetCreatureType() == CREATURETYPE_WER_WOLF;

				if( pCreature->IsAdvancementClass() && !bBat && !bWolf && !bWerWolf && !bHallu )
					DrawAdvancementClassVampireCharacter( pPoint, pCreature, action, direction, frame, body, FrameIndex );
				else
					DrawVampireCharacter( pPoint, pCreature, action, direction, frame, body, FrameIndex );			
				
			}
			else
			{
				//----------------------------------------------------
				// ĳ������ ���� �簢�� ������ �����ش�.
				//----------------------------------------------------
				pCreature->ClearScreenRect();		
			}
			
			//----------------------------------------
			//
			//            ���� ���
			//
			//----------------------------------------
			// ��� ���� �� �ִ� ������ �� �߿��� 
			// �԰� �ִ� ���� Ȯ���ؼ� �������� �Ѵ�.
			//WORD colorSet = pCreature->GetAttachEffectColor();
							
			//if (pCreature->IsWear())
			if (isSlayerCharacter)
			{
				if( pCreature->IsAdvancementClass() && !bHallu )
					DrawAdvancementClassSlayerCharacter( pPoint, pCreature, action, direction, frame, FrameIndex );
				else
					DrawSlayerCharacter( pPoint, pCreature, action, direction, frame, FrameIndex );
			}
			else if(isOustersCharacter)
			{
				if( pCreature->IsAdvancementClass() && !bHallu )
					DrawAdvancementClassOustersCharacter( pPoint, pCreature, action, direction, frame );
				else
					DrawOustersCharacter( pPoint, pCreature, action, direction, frame );
			}

			// ���� ���� ���� �ͷ� ������ �ȴ�-��-;;;; �ϵ��ϵ�..�ƾ�-_-/~
			if( bSlayerPet_ShowTurret )
			{
				DrawCentauroTurret( pPoint, pCreature, action, direction, frame , body);				
			}
		}


		//---------------------------------------------------------------
		//
		//                  AttachEffectNode ���
		//
		//---------------------------------------------------------------
		if (pCreature->IsExistAttachEffect())
		{	
			#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD("DrawAttachEffect");
			#endif

			pointTemp = *pPoint;
			//pointTemp.x += pCreature->GetSX();
			//pointTemp.y += pCreature->GetSY();

			DrawAttachEffect(&pointTemp, 
								pCreature->GetAttachEffectIterator(), 
								pCreature->GetAttachEffectSize(),
								pCreature,
								1);	// foreground���

			#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD("DAE ok");
			#endif
		}



		//pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
		//pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
		bool bPlayerParty = (pCreature->IsPlayerParty() 
								&& pCreature!=g_pPlayer
								// �ҷ� �ɸ��� ��Ƽ���� �� �˾ƺ���.
								&& !g_pPlayer->HasEffectStatus(EFFECTSTATUS_HALLUCINATION));	

		//------------------------------------------------
		// Chat String ���
		//------------------------------------------------
		// Mouse�� ���õ� ĳ�����̸�..
		if (m_SelectCreatureID == creatureID)
		{
			#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD("SelectedCreature");
			#endif

			//---------------------------------------- 	
			// �̸� ����� ��ǥ ����
			//---------------------------------------- 	
			const int FontHeight = g_pClientConfig->FONT_HEIGHT;
			const int FontHeight2 = FontHeight << 1;

			pointTemp.x = pPoint->x;			
			if (pointTemp.x<0) pointTemp.x=0;
				
			pointTemp.y = pPoint->y - pCreature->GetHeight();
				
			//---------------------------------------- 	
			// Level Name ���� ��ġ�� ���
			//---------------------------------------- 	
			if (pCreature->HasLevelName())
			{
				if (pointTemp.y < FontHeight2)
				{
					pointTemp.y = FontHeight2;
				}
			}
			//---------------------------------------- 	
			// �׳� �̸��� ���� ��
			//---------------------------------------- 	
			else
			{
				if (pointTemp.y < FontHeight) 
				{
					pointTemp.y = FontHeight;
				}
			}
			
			m_pointChatString	= pointTemp;
			m_pSelectedCreature = pCreature;	

		}
		else
		{		
			#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD("noSelCre");
			#endif

			pointTemp.x = pPoint->x;
			pointTemp.y = pPoint->y - pCreature->GetHeight();
				
			//------------------------------------------------
			// ��Ƽ���� ��� HP ������ش�.
			//------------------------------------------------
			if (bPlayerParty)
			{			
				DrawPartyHP( &pointTemp, pCreature );

				pointTemp.y = pPoint->y - pCreature->GetHeight() - m_EtcSPK[SPRITEID_PARTY_HP].GetHeight();
			}
			else
			{
				pointTemp.y = pPoint->y - pCreature->GetHeight();
			}

			pointTemp.x = pPoint->x;			

			//
			// �̰� ���ϰ� �� �ɸ���... ��~~
			//
			#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD("DrawChat");
			#endif

			m_pSurface->Unlock();
			const int firstY = DrawChatString(&pointTemp, pCreature, pCreature->GetChatColor());//CDirectDraw::Color(26,26,26));		
			pointTemp.y = firstY;
			DrawCreatureHPModify(&pointTemp, pCreature);
			m_pSurface->Lock();	

			// 2004, 8, 18, sobeit add start - ������ ��帶ũ ǥ��
			DrawGuildMarkInSiegeWar(pCreature,pointTemp.y);
			// 2004, 8, 18, sobeit add end
		}	

		//------------------------------------------------
		// ��Ƽ���� �þ߸� �����ش�.
		//------------------------------------------------
		if (bPlayerParty)
		{
			#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD("partySight");
			#endif

			int pX = pCreature->GetPixelX() - m_FirstZonePixel.x + TILE_X_HALF;
			int pY = pCreature->GetPixelY() - m_FirstZonePixel.y - TILE_Y;

			//int addLight = (pCreature->GetCreatureType()==CREATURETYPE_BAT ? 3 : 0);
	//		int addLight = (pCreature->IsFlyingCreature() ? 3 : 0);
			// player��ŭ�� �þ߶�� �����Ѵ�. - -;
			int creatureLight = g_pPlayer->GetLightSight();// + addLight);
			
			if (CDirect3D::IsHAL())
			{
				AddLightFilter3D( pX, 
									pY - (pCreature->IsFlyingCreature()? 72:0 ),	//g_pPlayer->GetZ(), 
									creatureLight, 
									false,	// screenPixel��ǥ			
									true);	// ������ ����ؾ��ϴ� ��	

				// ������� �Һ�
				ADD_MOTORCYCLE_LIGHT_XY_3D( pCreature, pX, pY, true );
			}
			else
			{
				AddLightFilter2D( pX, 
									pY - pCreature->GetZ(), 
									creatureLight,  
									false,	// screenPixel��ǥ			
									true);	// ������ ����ؾ��ϴ� ��

				// ������� �Һ�
				ADD_MOTORCYCLE_LIGHT_XY_2D( pCreature, pX, pY, true );
			}
		}
		//------------------------------------------------
		// ��Ƽ�� �ƴ� ��쿡...
		//------------------------------------------------
		else
		{
			#ifdef OUTPUT_DEBUG_DRAW_PROCESS
				DEBUG_ADD("noPParty?");
			#endif

			// ������� �Һ�
			if (CDirect3D::IsHAL())
			{		
				ADD_MOTORCYCLE_LIGHT_3D( pCreature, false );
			}
			else
			{
				ADD_MOTORCYCLE_LIGHT_2D( pCreature, false );
			}
		}

		if(gpC_item != NULL && pCreature != NULL && pCreature->GetHeadSkin() != 0)
		{
			int spriteID = pCreature->GetHeadSkin();
			int pX = pCreature->GetPixelX() - m_FirstZonePixel.x + TILE_X_HALF-gpC_item->GetWidth(spriteID)/2;
			int pY = pCreature->GetPixelY() - m_FirstZonePixel.y - TILE_Y -18-gpC_item->GetHeight(spriteID);
			CIndexSprite::SetUsingColorSet(377, 0);
			gpC_item->BltLocked(pX, pY, spriteID);
		}
	}

	__END_PROFILE("DrawCreature")

	#ifdef OUTPUT_DEBUG_DRAW_PROCESS
		DEBUG_ADD( "End DrawCreature" );
	#endif
//	DEBUG_ADD("[DrawCreature] End");

}

void	MTopView::DrawSelectedSlayerCreature( POINT* pPoint, MCreature* pCreature, int action, int direction, int frame )
{
	MCreatureWear*	pCreatureWear = (MCreatureWear*)pCreature;
	// Creature�� Action�� �´� add-on�� ����Ѵ�.
	//action = pCreature->GetAction();	
	WORD clothes;
	BYTE clothesType;
	
	for (int i=0; i<ADDON_MAX; i++)
	{
		// Creature�� ���� ���⿡ ����...
		// ���� ������ִ� ������ �ٸ� �� �ִ�.
		clothesType = MCreatureWear::s_AddonOrder[pCreature->GetDirection()][i];
		
		// i��° ������ ���� �԰� �ִٸ� ����� �ش�.
		const MCreatureWear::ADDON_INFO& addonInfo = pCreatureWear->GetAddonInfo(clothesType);
		
		if (addonInfo.bAddon)
		{
			clothes = addonInfo.FrameID;
			
			FRAME_ARRAY &FA = m_AddonFPK[clothes][action][direction];
			
			// �ִ� ������ ���
			if (FA.GetSize() > frame)
			{
				CFrame &Frame = FA[frame];					
				int sprite	= Frame.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
				int cx		= Frame.GetCX();	//m_AddonFPK[clothes][action][direction][frame].GetCX();
				int cy		= Frame.GetCY();	//m_AddonFPK[clothes][action][direction][frame].GetCY();
				
				pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
				pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
				
				CIndexSprite* pSprite = &m_AddonSPK[ sprite ];
				
				// ����Sprite�� �ʱ�ȭ ���� ���� ���
				//						if (pSprite->IsNotInit())
				//						{
				//							LoadFromFileAddonSPK( clothes, action );
				//							//continue;
				//						}
				
				//---------------------------------------- 
				// ĳ���� ���� �簢�� ���� ����
				//---------------------------------------- 	
				rect.left	= pointTemp.x;
				rect.top	= pointTemp.y;
				rect.right	= rect.left + pSprite->GetWidth();
				rect.bottom = rect.top + pSprite->GetHeight();
				pCreature->AddScreenRect( &rect );
				
				// SpriteOutlineManager�� �߰�
				//CIndexSprite::SetUsingColorSet((pCreature->GetID()+3*(clothesType,1),7)%MAX_COLORSET, ((pCreature->GetID()*pCreature->GetID(),7*(clothesType+2)))%MAX_COLORSET);
				//CIndexSprite::SetUsingColorSet((c1+3*(clothesType+1)+7)%MAX_COLORSET, ((c2*c2+7*(clothesType+2)))%MAX_COLORSET);
				//---------------------------------------- 
				// ĳ���� �κ� ������ �ٲ�� ���
				//---------------------------------------- 
				if (addonInfo.bEffectColor)	//colorSet < MAX_COLORSET)
				{
					m_SOM.Add( pointTemp.x, pointTemp.y, pSprite, addonInfo.EffectColorSet );
				}
				//---------------------------------------- 
				// ���������..
				//---------------------------------------- 
				else
				{
					int colorSet1 = addonInfo.ColorSet1, colorSet2 = addonInfo.ColorSet2;
					if(colorSet2 == UNIQUE_ITEM_COLOR || colorSet2 == QUEST_ITEM_COLOR)
					{
						if(colorSet2 == QUEST_ITEM_COLOR || colorSet2 == UNIQUE_ITEM_COLOR )
							colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
						
						if(addonInfo.ItemClass != ITEM_CLASS_COAT && addonInfo.ItemClass != ITEM_CLASS_TROUSER)
							colorSet1 = colorSet2;
					}							
					
					CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
					m_SOM.Add( pointTemp.x, pointTemp.y, pSprite );
				}
			}
		}
	}
}



void	MTopView::DrawSelectedOustersCreature( POINT* pPoint, MCreature* pCreature, int action, int direction, int frame )
{
	//  íũ���� �ִ�
	MCreatureWear *pCreatureWear = (MCreatureWear *)pCreature;
	
	const MCreatureWear::ADDON_INFO& addonInfoChakram = pCreatureWear->GetAddonInfo(ADDON_RIGHTHAND);
	bool bChakram = addonInfoChakram.bAddon && addonInfoChakram.ItemClass == ITEM_CLASS_OUSTERS_CHAKRAM;
	
	int tempAction = action;
	if(bChakram == false)
	{
		switch(tempAction)
		{
		case ACTION_STAND:
			tempAction = ACTION_OUSTERS_STAND;
			break;
			
		case ACTION_MOVE:
			tempAction = ACTION_OUSTERS_MOVE;
			break;
		}
	}
	
	// ���� ��� íũ���� ��´�
	const MCreatureWear::ADDON_INFO& addonInfo = pCreatureWear->GetAddonInfo(ADDON_COAT);
	const MCreatureWear::ADDON_INFO& bootsAddonInfo = pCreatureWear->GetAddonInfo(ADDON_TROUSER);
	
	if (addonInfo.bAddon && !pCreatureWear->IsGhost(1))
	{
		int clothes = addonInfo.FrameID;
		
		
		FRAME_ARRAY &FA = m_OustersFPK[clothes][tempAction][direction];
		
		// �ִ� ������ ���
		if (FA.GetSize() > frame)
		{
			CFrame &Frame = FA[frame];					
			int sprite	= Frame.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
			int cx		= Frame.GetCX();	//m_AddonFPK[clothes][action][direction][frame].GetCX();
			int cy		= Frame.GetCY();	//m_AddonFPK[clothes][action][direction][frame].GetCY();
			
			CIndexSprite* pSprite = &m_OustersSPK[ sprite ];					
			
			pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
			pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
			
			//---------------------------------------- 
			// ĳ���� ���� �簢�� ���� ����
			//---------------------------------------- 	
			rect.left	= pointTemp.x;
			rect.top	= pointTemp.y;
			rect.right	= rect.left + pSprite->GetWidth();
			rect.bottom = rect.top + pSprite->GetHeight();
			pCreature->AddScreenRect( &rect );
			
			//---------------------------------------- 
			// ĳ���� �κ� ������ �ٲ�� ���
			//---------------------------------------- 
			if (addonInfo.bEffectColor)	//colorSet < MAX_COLORSET)
			{
				m_SOM.Add( pointTemp.x, pointTemp.y, pSprite, addonInfo.EffectColorSet );
			}
			//---------------------------------------- 
			// �������� ĳ���� ���
			//---------------------------------------- 
			else
			{
				CIndexSprite::SetUsingColorSetOnly( 0, pCreature->GetBodyColor1() );	// �Ӹ���
				
				int coatColor = addonInfo.ColorSet2, Colorset;
				if( coatColor == QUEST_ITEM_COLOR || coatColor == UNIQUE_ITEM_COLOR )
					coatColor = MItem::GetSpecialColorItemColorset( coatColor );						
				CIndexSprite::SetUsingColorSetOnly( 1, coatColor );	// �ʻ�
				if(bChakram == false)	// ����Ʋ���� ���� ������
				{
					if(addonInfoChakram.bAddon)
					{
						Colorset = addonInfoChakram.ColorSet2;
						if( Colorset == QUEST_ITEM_COLOR || Colorset == UNIQUE_ITEM_COLOR )
							Colorset = MItem::GetSpecialColorItemColorset( Colorset );
						CIndexSprite::SetUsingColorSetOnly( 2, Colorset );	// ��								
					}
					else
					{
						Colorset = defaultCoatColor;								
						if( Colorset == QUEST_ITEM_COLOR || Colorset == UNIQUE_ITEM_COLOR )
							Colorset = MItem::GetSpecialColorItemColorset( Colorset );
						
						CIndexSprite::SetUsingColorSetOnly( 2, Colorset );	// ��
					}
				}
				else
				{
					Colorset = defaultCoatColor;
					if(addonInfoChakram.bAddon)
						Colorset = addonInfoChakram.ColorSet2;
					if( Colorset == QUEST_ITEM_COLOR || Colorset == UNIQUE_ITEM_COLOR )
						Colorset = MItem::GetSpecialColorItemColorset( Colorset );
					CIndexSprite::SetUsingColorSetOnly( 2, Colorset );	// ��
				}
				
				if(bootsAddonInfo.bAddon)
				{
					Colorset = bootsAddonInfo.ColorSet2;
					if( Colorset == QUEST_ITEM_COLOR || Colorset == UNIQUE_ITEM_COLOR )
						Colorset = MItem::GetSpecialColorItemColorset( Colorset );
					CIndexSprite::SetUsingColorSetOnly( 3, Colorset );	// ������
				}
				else
				{
					Colorset = defaultCoatColor;
					
					if( Colorset == QUEST_ITEM_COLOR || Colorset == UNIQUE_ITEM_COLOR )
						Colorset = MItem::GetSpecialColorItemColorset( Colorset );
					CIndexSprite::SetUsingColorSetOnly( 3, Colorset );	// ��
				}
				
				m_SOM.Add( pointTemp.x, pointTemp.y, pSprite );
			}						
			
		}
	}
	
	if (bChakram && !pCreatureWear->IsGhost(2))
	{
		int clothes = addonInfoChakram.FrameID;
		
		FRAME_ARRAY &FA = m_OustersFPK[clothes][tempAction][direction];
		
		// �ִ� ������ ���
		if (FA.GetSize() > frame)
		{
			CFrame &Frame = FA[frame];					
			int sprite	= Frame.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
			int cx		= Frame.GetCX();	//m_AddonFPK[clothes][action][direction][frame].GetCX();
			int cy		= Frame.GetCY();	//m_AddonFPK[clothes][action][direction][frame].GetCY();
			
			CIndexSprite* pSprite = &m_OustersSPK[ sprite ];					
			
			pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
			pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
			
			//---------------------------------------- 
			// ĳ���� �κ� ������ �ٲ�� ���
			//---------------------------------------- 
			if (addonInfoChakram.bEffectColor)	//colorSet < MAX_COLORSET)
			{
				m_SOM.Add( pointTemp.x, pointTemp.y, pSprite, addonInfo.EffectColorSet );
			}
			//---------------------------------------- 
			// �������� ĳ���� ���
			//---------------------------------------- 
			else
			{
				int colorset1, colorset2;
				
				colorset1 = addonInfoChakram.ColorSet1;
				colorset2 = addonInfoChakram.ColorSet2;
				if( colorset1 == QUEST_ITEM_COLOR || colorset1 == UNIQUE_ITEM_COLOR )
					colorset1 = MItem::GetSpecialColorItemColorset( colorset1 );
				if( colorset2 == QUEST_ITEM_COLOR || colorset2 == UNIQUE_ITEM_COLOR )
					colorset2 = MItem::GetSpecialColorItemColorset( colorset2 );
				
				
				CIndexSprite::SetUsingColorSet(colorset1, colorset2);
				m_SOM.Add( pointTemp.x, pointTemp.y, pSprite );
			}						
			
		}
	}
}

void	MTopView::DrawVampireCharacter( POINT* pPoint, MCreature* pCreature, int action, int direction, int frame, int body, int frameindex )
{
	//------------------------------------------------
	// �� �������
	//------------------------------------------------
	int casketValue = pCreature->GetCasketCount();
	int creature_type = pCreature->GetCreatureType();
	bool bInCasket = pCreature->IsInCasket();
	bool bCasketOnly = (bInCasket && casketValue==0);
	
	BOOL	bAffterEffect = FALSE ; 
	//------------------------------------------------------------
	// �ܻ� �׸����� ���� ó�� 
	//------------------------------------------------------------
	if ( (pCreature->HasEffectStatus( EFFECTSTATUS_DARK_FORCE) )
	)
	{
			if( ((action >=  ACTION_MOVE				&& action <=  ACTION_ATTACK)  ||
				(action >=  ACTION_VAMPIRE_ATTACK_SLOW	&& action <=  ACTION_VAMPIRE_ATTACK_FAST)  ||
				(action >=  ACTION_VAMPIRE_SKILL_ATTACK	&& action <=  ACTION_VAMPIRE_SKILL_ATTACK_FAST))
			)
			{
				//bAffterEffect = TRUE ; 
			}
				
	}

	//if(direction != 6 && bAffterEffect)
	//	DrawAfterVampire( pPoint, pCreature, action, direction, frame , body );

	//----------------------------------------------------
	// ������ ���� ����ϴ� ���� �� ����� ���Ѵ�.
	//----------------------------------------------------
	if (!bCasketOnly)
	{
		FRAME_ARRAY& FA = m_CreatureFPK[body][action][direction];
		
		if (FA.GetSize() > frame)
		{
			CFrame& Frame =	FA[frame];
			int sprite = Frame.GetSpriteID(),	//m_CreatureFPK[body][action][direction][frame].GetSpriteID(),
				cx		= Frame.GetCX(),	//m_CreatureFPK[body][action][direction][frame].GetCX(),
				cy		= Frame.GetCY();	//m_CreatureFPK[body][action][direction][frame].GetCY();
			
			// ��ǥ ����
			pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
			pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
			
			CIndexSprite* pSprite = &m_CreatureSPK[ sprite ];
			
			//---------------------------------------- 
			// ĳ���� ���� �簢�� ���� ����
			//---------------------------------------- 	
			rect.left	= pointTemp.x;
			rect.top	= pointTemp.y;
			rect.right	= rect.left + pSprite->GetWidth();
			rect.bottom = rect.top + pSprite->GetHeight();
			if(frameindex==0 )
				pCreature->SetScreenRect( &rect );
			
			// Player�� �������� Character ǥ��
			//if (g_pPlayer->GetTraceCreatureID()==pCreature->GetID())			
			
			//CIndexSprite::SetUsingColorSet(c1%MAX_COLORSET, c2%MAX_COLORSET);
			
			//-----------------------------------------------------------
			// CutHeight
			//-----------------------------------------------------------
			bool bCutHeight = pCreature->IsCutHeight();
			int previousClipBottom;
			if (bCutHeight)
			{
				previousClipBottom = m_pSurface->GetClipBottom();
				m_pSurface->SetClipBottom( rect.bottom - TILE_Y_HALF );
				
				pointTemp.y += pCreature->GetCutHeightCount() - TILE_Y_HALF;
			}
			
			//-----------------------------------------------------------
			// ���� ���� ��� 			
			//-----------------------------------------------------------
			// vampire
			if (pCreature->IsFakeDie())
			{
				WORD colorSet = pCreature->GetAttachEffectColor();
				
				if( pCreature->GetCreatureType() == CREATURETYPE_BAT && pCreature->GetBatColor() != 0xFFFF)
					colorSet = pCreature->GetBatColor();
				
				//---------------------------------------- 
				// ĳ���� ��ü ������ �ٲ�� ���					
				//---------------------------------------- 
				if (colorSet < MAX_COLORSET)
				{
					// IndexSprite���� EFFECT...�ְ�...
					// ������~ �ܰ������� ��Ÿ����/�������� �ؾߵ�.. - -;
					m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, colorSet);
				}
				else
				{
					int colorSet1 = pCreature->GetBodyColor1();
					int colorSet2 = pCreature->GetBodyColor2();
					
					if( colorSet1 == QUEST_ITEM_COLOR || colorSet1 == UNIQUE_ITEM_COLOR )
						colorSet1 = MItem::GetSpecialColorItemColorset( colorSet1 );
					
					if( colorSet2 == QUEST_ITEM_COLOR || colorSet2 == UNIQUE_ITEM_COLOR )
						colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
					
					CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
					
					int netValue = pCreature->GetFakeDieCount()/5;
					
					CSpriteSurface::s_Value1 = netValue;
					
					CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_NET );
					CIndexSprite::SetEffect( CIndexSprite::EFFECT_NET );
					
					m_pSurface->BltIndexSpriteEffect(&pointTemp, pSprite);
					
				}
			}
			else if (pCreature->IsInvisible())
			{
				WORD colorSet = pCreature->GetAttachEffectColor();
				
				if( pCreature->GetCreatureType() == CREATURETYPE_BAT && pCreature->GetBatColor() != 0xFFFF)
					colorSet = pCreature->GetBatColor();
				
				//---------------------------------------- 
				// ĳ���� ��ü ������ �ٲ�� ���					
				//---------------------------------------- 
				if (colorSet < MAX_COLORSET)
				{
					// IndexSprite���� EFFECT...�ְ�...
					// ������~ �ܰ������� ��Ÿ����/�������� �ؾߵ�.. - -;
					m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, colorSet);
				}
				else
				{
					int colorSet1 = pCreature->GetBodyColor1();
					int colorSet2 = pCreature->GetBodyColor2();
					
					if( colorSet1 == QUEST_ITEM_COLOR || colorSet1 == UNIQUE_ITEM_COLOR )
						colorSet1 = MItem::GetSpecialColorItemColorset( colorSet1 );
					
					if( colorSet2 == QUEST_ITEM_COLOR || colorSet2 == UNIQUE_ITEM_COLOR )
						colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
					
					CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
					
					int wipeValue = pCreature->GetInvisibleCount();
					
					if (wipeValue==0)
					{
						m_pSurface->BltIndexSprite(&pointTemp, pSprite);							
					}
					else if (wipeValue==64)
					{
						CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_SIMPLE_OUTLINE );
						CIndexSprite::SetEffect( CIndexSprite::EFFECT_SIMPLE_OUTLINE );
						
						m_pSurface->BltIndexSpriteEffect(&pointTemp, pSprite);
					}
					else
					{
						CSpriteSurface::s_Value1 = wipeValue;
						
						CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_WIPE_OUT );
						CIndexSprite::SetEffect( CIndexSprite::EFFECT_WIPE_OUT );
						
						m_pSurface->BltIndexSpriteEffect(&pointTemp, pSprite);
						
						//CSpriteSurface::s_Value1 = wipeValue/10+1;
						
						//CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_NET );
						//CIndexSprite::SetEffect( CIndexSprite::EFFECT_NET );
						
						//m_pSurface->BltIndexSpriteEffect(&pointTemp, pSprite);
					}							
				}
			}					
			else
			{	
				//-----------------------------------------------------------
				// ������ �����̴� ��
				//-----------------------------------------------------------
				if (pCreature->IsFastMove() || pCreature->IsBloodyZenith())
				{
					int colorSet1 = pCreature->GetBodyColor1();
					int colorSet2 = pCreature->GetBodyColor2();
					
					if( colorSet1 == QUEST_ITEM_COLOR || colorSet1 == UNIQUE_ITEM_COLOR )
						colorSet1 = MItem::GetSpecialColorItemColorset( colorSet1 );
					
					if( colorSet2 == QUEST_ITEM_COLOR || colorSet2 == UNIQUE_ITEM_COLOR )
						colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
					
					
					CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
					
					POINT pointTemp2;
					
					//CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_NET );
					//CIndexSprite::SetEffect( CIndexSprite::EFFECT_NET );
					
					int fastMoveShadowMax = 2;
					
					if(creature_type == CREATURETYPE_WILD_WOLF)
						fastMoveShadowMax = 6;
					if(pCreature->IsBloodyZenith())
					{
						fastMoveShadowMax = pCreature->GetBloodyZenithCount();
						pCreature->UpdateBloodyZenith();
					}
					for(int fastMoveShadow = fastMoveShadowMax; fastMoveShadow > 0; fastMoveShadow--)
					{
						// 1 pixel skip
						pointTemp2.x = pointTemp.x - (pCreature->GetCX() >> 1)*fastMoveShadow;
						pointTemp2.y = pointTemp.y - (pCreature->GetCY() >> 1)*fastMoveShadow;
						if(pCreature->IsBloodyZenith())
						{
							pointTemp2.y -= sin((double)max(0, pCreature->GetMoveCount()-fastMoveShadow)*3.141592/(double)pCreature->GetMoveCountMax())*100;
						}
						
						//CSpriteSurface::s_Value1 = 1;
						//m_pSurface->BltIndexSpriteEffect(&pointTemp2, pSprite);
						m_pSurface->BltIndexSpriteDarkness(&pointTemp2, pSprite, min(2, fastMoveShadow));
					}
					
				}
				
				if(pCreature->IsBloodyZenith())
				{
					pointTemp.y -= sin((double)pCreature->GetMoveCount()*3.141592/(double)pCreature->GetMoveCountMax())*100;
				}
				WORD colorSet = pCreature->GetAttachEffectColor();
				
				if( pCreature->GetCreatureType() == CREATURETYPE_BAT && pCreature->GetBatColor() != 0xFFFF)
					colorSet = pCreature->GetBatColor();
				
				//---------------------------------------- 
				// ĳ���� ��ü ������ �ٲ�� ���					
				//---------------------------------------- 
				if (colorSet < MAX_COLORSET)
				{
					m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, colorSet);
				}
				//---------------------------------------- 
				// �������� ���� ���
				//---------------------------------------- 					
				else
				{				
					int colorSet1 = pCreature->GetBodyColor1();
					int colorSet2 = pCreature->GetBodyColor2();
					
					if( colorSet1 == QUEST_ITEM_COLOR || colorSet1 == UNIQUE_ITEM_COLOR )
						colorSet1 = MItem::GetSpecialColorItemColorset( colorSet1 );
					
					if( colorSet2 == QUEST_ITEM_COLOR || colorSet2 == UNIQUE_ITEM_COLOR )
						colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
					
					CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
					
					int shadowCount = pCreature->GetShadowCount();
					
					//----------------------------------------
					// Shadow���
					//----------------------------------------
					if (shadowCount)
					{
						bool bDrawShadowFirst = (direction<=4) || creature_type == 764 ||  creature_type == 765;
						if (!bDrawShadowFirst)
						{
							if (pCreature->IsFade())
							{
								m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
							}
							else
							{
								m_pSurface->BltIndexSprite(&pointTemp, pSprite);
							}
						}
						
						// 0, 1, 2, 3, 4, 5
						const int darkbits[6] =
						{
							0, 1, 1, 2, 2, 3
						};
						
						POINT pointTemp2;
						
						// �̵��̸� ��ǥ�� �ٲ��
						int cxStep = 0, cyStep = 0, cxInc =0 , cyInc = 0;
						if (action==ACTION_MOVE)
						{
							cxInc = -pCreature->GetCX();
							cyInc = -pCreature->GetCY();
						}
						
						
						int faNum = FA.GetSize();
						for (int f=1; f<=shadowCount; f++)
						{
							int frame_f = frame-f;
							
							//---------------------------------------- 
							// f frame ��
							//---------------------------------------- 
							if (frame_f < 0)
							{
								frame_f += faNum;
							}
							
							CFrame &Frame_f = FA[frame_f];
							int sprite_f	= Frame_f.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
							
							CIndexSprite* pSprite_f = &m_CreatureSPK[ sprite_f ];
							
							//									if (pSprite_f->IsNotInit())
							//									{
							//										LoadFromFileCreatureActionSPK( body, action );
							//									}
							
							int cx_f		= Frame_f.GetCX();
							int cy_f		= Frame_f.GetCY();
							
							pointTemp2.x = pPoint->x + cx_f + cxStep;
							pointTemp2.y = pPoint->y + cy_f + cyStep;
							cxStep += cxInc;
							cyStep += cyInc;
							
							m_pSurface->BltIndexSpriteDarkness(&pointTemp2, pSprite_f, darkbits[f]);																		
						}
						
						if (bDrawShadowFirst)
						{
							if (pCreature->IsFade())
							{
								m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
							}
							else
							{
								m_pSurface->BltIndexSprite(&pointTemp, pSprite);
							}
						}
					}
					//----------------------------------------
					// ���� ���
					//----------------------------------------
					else
					{
						// ��Ӱ� ���
						if (pCreature->IsFade())
						{
							m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
						}
						else
						{
							m_pSurface->BltIndexSprite(&pointTemp, pSprite);
							
						}
						//if(direction == 6 && bAffterEffect)
						//	DrawAfterVampire( pPoint, pCreature, action, direction, frame , body );
					}
				}
			}

			if (bCutHeight)
			{
				m_pSurface->SetClipBottom( previousClipBottom );
			}

			// 2004, 10, 28, sobeit add start  - ���� ų ����Ʈ �ش� ���Ϳ� ǥ��.
			if(pCreature->IsAlive() && (g_CurrentFrame&0x04)&&UI_IsMonsterKillQuest_Monster((*g_pCreatureTable)[pCreature->GetCreatureType()].SpriteTypes[0]))
			//if(pCreature->IsAlive() && (g_CurrentFrame&0x04))
			{
				UI_ShowTargetArrow(pPoint->x + 12 ,pPoint->y- pCreature->GetHeight()-20);
			}
		// 2004, 10, 28, sobeit add end


		}
	}
		
	//----------------------------------------------------
	// �� ���
	//----------------------------------------------------
	if (bInCasket)
	{
		// �׸��� ������ *2�ؾ��Ѵ�.
		int casketID = SPRITEID_CASKET_1 + pCreature->GetCasketType()*2;
		
		if (casketID < m_EtcSPK.GetSize())
		{
			CSprite* pSprite = &m_EtcSPK[casketID];
			
			if (pSprite!=NULL)
			{
				// tile�� �߽ɿ��� �����.
				pointTemp.x = pPoint->x + TILE_X_HALF - (pSprite->GetWidth()>>1);
				pointTemp.y = pPoint->y + TILE_Y - pSprite->GetHeight();
				
				//---------------------------------------- 
				// ĳ���� ���� �簢�� ���� ����
				//---------------------------------------- 	
				rect.left	= pointTemp.x;
				rect.top	= pointTemp.y;
				rect.right	= rect.left + pSprite->GetWidth();
				rect.bottom = rect.top + pSprite->GetHeight();
				if(frameindex==0 )
					pCreature->SetScreenRect( &rect );
				
				if (casketValue==0)
				{
					m_pSurface->BltSprite(&pointTemp, pSprite);						
				}
				else if (casketValue==64)
				{
					CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_SIMPLE_OUTLINE );
					
					m_pSurface->BltSpriteEffect(&pointTemp, pSprite);
				}
				else
				{
					CSpriteSurface::s_Value1 = casketValue;
					
					CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_WIPE_OUT );
					
					m_pSurface->BltSpriteEffect(&pointTemp, pSprite);
				}
			}
		}
	}		
}





void	MTopView::DrawOustersCharacter( POINT* pPoint, MCreature* pCreature, int action, int direction, int frame )
{
	//  íũ���� �ִ�
	MCreatureWear *pCreatureWear = (MCreatureWear *)pCreature;
	
	const MCreatureWear::ADDON_INFO& addonInfoChakram = pCreatureWear->GetAddonInfo(ADDON_RIGHTHAND);
	bool bChakram = addonInfoChakram.bAddon && addonInfoChakram.ItemClass == ITEM_CLASS_OUSTERS_CHAKRAM;
	
	int tempAction = action;
	if(bChakram == false)
	{
		switch(tempAction)
		{
		case ACTION_STAND:
			tempAction = ACTION_OUSTERS_STAND;
			break;
			
		case ACTION_MOVE:
			tempAction = ACTION_OUSTERS_MOVE;
			break;
		}
	}
	
	// ���� ��� íũ���� ��´�
	const MCreatureWear::ADDON_INFO& addonInfo = pCreatureWear->GetAddonInfo(ADDON_COAT);
	const MCreatureWear::ADDON_INFO& bootsAddonInfo = pCreatureWear->GetAddonInfo(ADDON_TROUSER);
	
	BOOL	bAffterEffect  = FALSE ; 

	//------------------------------------------------------------
	// �ܻ� �׸����� ���� ó�� 
	//------------------------------------------------------------
	if ( (pCreature->HasEffectStatus( EFFECTSTATUS_NATURAL_FORCE)  || 
		  pCreature->HasEffectStatus( EFFECTSTATUS_FIRE_FORCE)	||
		  pCreature->HasEffectStatus( EFFECTSTATUS_EARTH_FORCE))
	)
	{
			if( ((action >=  ACTION_MOVE				&& action <=  ACTION_ATTACK)  ||
				(action >=  ACTION_OUSTERS_ATTACK_SLOW	&& action <=  ACTION_OUSTERS_CHAKRAM_FAST)  ||
				(action >=  ACTION_OUSTERS_MOVE)
				) 
			)
			{
				//bAffterEffect = TRUE ; 
			}
				
				
	}


//	if(direction != 6 && bAffterEffect)
//		DrawAfterOusters( pPoint, pCreature, action, direction, frame );

	if (addonInfo.bAddon && !pCreatureWear->IsGhost(1))
	{
		//				DEBUG_ADD("[DrawCreature] DrawCloth");
		int clothes = addonInfo.FrameID;
		
		
		FRAME_ARRAY &FA = m_OustersFPK[clothes][tempAction][direction];
		
		// �ִ� ������ ���
		if (FA.GetSize() > frame)
		{
			CFrame &Frame = FA[frame];					
			int sprite	= Frame.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
			int cx		= Frame.GetCX();	//m_AddonFPK[clothes][action][direction][frame].GetCX();
			int cy		= Frame.GetCY();	//m_AddonFPK[clothes][action][direction][frame].GetCY();
			
			CIndexSprite* pSprite = &m_OustersSPK[ sprite ];					
			
			pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
			pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
			
			//---------------------------------------- 
			// ĳ���� ���� �簢�� ���� ����
			//---------------------------------------- 	
			rect.left	= pointTemp.x;
			rect.top	= pointTemp.y;
			rect.right	= rect.left + pSprite->GetWidth();
			rect.bottom = rect.top + pSprite->GetHeight();
			pCreature->AddScreenRect( &rect );
			
			//---------------------------------------- 
			// ĳ���� �κ� ������ �ٲ�� ���
			//---------------------------------------- 
			if (addonInfo.bEffectColor)	//colorSet < MAX_COLORSET)
			{
				m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, 
					addonInfo.EffectColorSet);
			}
			//---------------------------------------- 
			// �������� ĳ���� ���
			//---------------------------------------- 
			else
			{
				CIndexSprite::SetUsingColorSetOnly( 0, pCreature->GetBodyColor1() );	// �Ӹ���
				
				int Colorset;
				
				Colorset = addonInfo.ColorSet2;
				
				if( Colorset == QUEST_ITEM_COLOR || Colorset == UNIQUE_ITEM_COLOR )
					Colorset = MItem::GetSpecialColorItemColorset( Colorset );
				CIndexSprite::SetUsingColorSetOnly( 1, Colorset );	// �ʻ�
				
				if(bChakram == false)	// ����Ʋ���� ���� ������
				{
					if(addonInfoChakram.bAddon)
					{
						Colorset = addonInfoChakram.ColorSet2;
						if (Colorset == QUEST_ITEM_COLOR||Colorset == UNIQUE_ITEM_COLOR )
							Colorset = MItem::GetSpecialColorItemColorset( Colorset );
						
						CIndexSprite::SetUsingColorSetOnly( 2, Colorset );	// ��
					}
					else
					{
						Colorset = defaultCoatColor;
						if (Colorset == QUEST_ITEM_COLOR||Colorset == UNIQUE_ITEM_COLOR )
							Colorset = MItem::GetSpecialColorItemColorset( Colorset );
						
						CIndexSprite::SetUsingColorSetOnly( 2, Colorset );	// ��
					}
				}
				else
				{
					Colorset = defaultCoatColor;
					if(addonInfoChakram.bAddon)
						Colorset = addonInfoChakram.ColorSet2;
					if (Colorset == QUEST_ITEM_COLOR||Colorset == UNIQUE_ITEM_COLOR )
						Colorset = MItem::GetSpecialColorItemColorset( Colorset );
					
					CIndexSprite::SetUsingColorSetOnly( 2, Colorset );	// ��
					
				}
				
				if(bootsAddonInfo.bAddon)
				{
					Colorset = bootsAddonInfo.ColorSet2;
					if (Colorset == QUEST_ITEM_COLOR||Colorset == UNIQUE_ITEM_COLOR )
						Colorset = MItem::GetSpecialColorItemColorset( Colorset );
					
					CIndexSprite::SetUsingColorSetOnly( 3, Colorset );	// ������
				}
				else
				{
					Colorset = defaultCoatColor ;
					if (Colorset == QUEST_ITEM_COLOR||Colorset == UNIQUE_ITEM_COLOR )
						Colorset = MItem::GetSpecialColorItemColorset( Colorset );
					
					CIndexSprite::SetUsingColorSetOnly( 3, Colorset );	// ��
				}
				
				// ��Ӱ� ���
				if (pCreature->IsFade())
				{
					m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
				}
				else
				{
					m_pSurface->BltIndexSprite(&pointTemp, pSprite);
				}
				//if(direction == 6 && bAffterEffect)
				//	DrawAfterOusters( pPoint, pCreature, action, direction, frame );
			}			
		}
	}
	
	if (bChakram && !pCreatureWear->IsGhost(2))
	{
		//				DEBUG_ADD("[DrawCreature] DrawChakram");
		int clothes = addonInfoChakram.FrameID;
		
		FRAME_ARRAY &FA = m_OustersFPK[clothes][tempAction][direction];
		
		// �ִ� ������ ���
		if (FA.GetSize() > frame)
		{
			//					DEBUG_ADD_FORMAT("[DrawCreature] FA.GetSize() > frame %d %d", FA.GetSize(), frame);
			CFrame &Frame = FA[frame];					
			int sprite	= Frame.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
			int cx		= Frame.GetCX();	//m_AddonFPK[clothes][action][direction][frame].GetCX();
			int cy		= Frame.GetCY();	//m_AddonFPK[clothes][action][direction][frame].GetCY();
			
			CIndexSprite* pSprite = &m_OustersSPK[ sprite ];					
			
			pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
			pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
			
			//---------------------------------------- 
			// ĳ���� �κ� ������ �ٲ�� ���
			//---------------------------------------- 
			if (addonInfoChakram.bEffectColor)	//colorSet < MAX_COLORSET)
			{
				m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, 
					addonInfoChakram.EffectColorSet);
			}
			//---------------------------------------- 
			// �������� ĳ���� ���
			//---------------------------------------- 
			else
			{
				int colorset1, colorset2;
				colorset1 = addonInfoChakram.ColorSet1;
				colorset2 = addonInfoChakram.ColorSet2;
				
				if( colorset1 == QUEST_ITEM_COLOR || colorset1 == UNIQUE_ITEM_COLOR )
					colorset1 = MItem::GetSpecialColorItemColorset( colorset1 );
				if( colorset2 == QUEST_ITEM_COLOR || colorset2 == UNIQUE_ITEM_COLOR )
					colorset2 = MItem::GetSpecialColorItemColorset( colorset2 );
				CIndexSprite::SetUsingColorSet( colorset1, colorset2 );
				// ��Ӱ� ���
				if (pCreature->IsFade())
				{
					m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
				}
				else
				{
					m_pSurface->BltIndexSprite(&pointTemp, pSprite);
				}
				//if(direction == 6 && bAffterEffect)
				//	DrawAfterOusters( pPoint, pCreature, action, direction, frame );
			}						
			
		}
		else
		{
			DEBUG_ADD_FORMAT("[DrawCreature] FA.GetSize() <= frame %d %d %d %d", FA.GetSize(), frame, pCreatureWear->GetActionCount(), pCreatureWear->GetActionCountMax());
			//					DEBUG_ADD_FORMAT("[DrawCreature] FA.GetSize() <= frame %d %d %d", clothes, tempAction, direction);
		}
	}
	
#ifdef OUTPUT_DEBUG_DRAW_PROCESS
	DEBUG_ADD("dcOK");
#endif
}

void	MTopView::DrawAdvancementClassOustersCharacter( 
				POINT* pPoint, MCreature* pCreature, int action, int direction, int frame )
{
	//  íũ���� �ִ�
	MCreatureWear *pCreatureWear = (MCreatureWear *)pCreature;
	
	const MCreatureWear::ADDON_INFO& addonInfoChakram = pCreatureWear->GetAddonInfo(ADDON_RIGHTHAND);
	bool bChakram = addonInfoChakram.bAddon && addonInfoChakram.ItemClass == ITEM_CLASS_OUSTERS_CHAKRAM;
	
	int tempAction = ConvAdvancementOustersActionFromOusterAction( action, bChakram );

	if( tempAction == -1 )
		return;
	else
		tempAction -= ADVANCEMENT_ACTION_START;
	
	// 2005.08.12 Sjheon �޺� ��ų ���� Add
	/*
	int		iComboCnt = pCreature->GetCombo();

	if((action >= (ACTION_ADVANCEMENT_OUSTERS_COMBO_SLOW - ADVANCEMENT_ACTION_START))  && (iComboCnt < 4)) //  ; && iComboCnt > 0 ))
	{
		//frame -= 8 ; 
		WORD  fCreatureType	= action - 	(ACTION_ADVANCEMENT_OUSTERS_COMBO_SLOW  - ADVANCEMENT_ACTION_START)  ; 

		WORD  fWeaponSpeed = pCreature->GetWeaponSpeed() ;

		WORD Frame = AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][iComboCnt - 1] + 1 ; 

		if(frame > (Frame - 1) )
		{
			frame -= Frame  - ((iComboCnt -1) *2); 
			action += 3 ; 
		}
	}
	*/
	// 2005.08.12 Sjheon �޺� ��ų ���� End	
	

	// ���� ��� íũ���� ��´�
	const MCreatureWear::ADDON_INFO& addonInfo = pCreatureWear->GetAddonInfo(ADDON_COAT);
	const MCreatureWear::ADDON_INFO& bootsAddonInfo = pCreatureWear->GetAddonInfo(ADDON_TROUSER);
	
	BOOL	bAffterEffect  = FALSE ; 

	//------------------------------------------------------------
	// �ܻ� �׸����� ���� ó�� 
	//------------------------------------------------------------
	if ( (pCreature->HasEffectStatus( EFFECTSTATUS_NATURAL_FORCE)  || 
		  pCreature->HasEffectStatus( EFFECTSTATUS_FIRE_FORCE)	||
		  pCreature->HasEffectStatus( EFFECTSTATUS_EARTH_FORCE))
	)
	{
		int AdvancementAction = ACTION_ADVANCEMENT_OUSTERS_CHAKRAM_STOP + action ; 

		//if( ((AdvancementAction >=  ACTION_ADVANCEMENT_OUSTERS_CHAKRAM_MOVE	  && 
		//	 AdvancementAction <=  ACTION_ADVANCEMENT_OUSTERS_WRISTLET_MOVE)  ||
		//	(AdvancementAction >=  ACTION_ADVANCEMENT_OUSTERS_COMBO_SLOW      && 
		//	 AdvancementAction <=  ACTION_ADVANCEMENT_OUSTERS_COMBO_FAST)     ||
		//	(AdvancementAction >=  ACTION_ADVANCEMENT_OUSTERS_MAGIC_ATTACK)	  ||	
		//	(AdvancementAction >=  	ACTION_ADVANCEMENT_OUSTERS_MAGIC)		  ||	
		//	(AdvancementAction >=  	ACTION_ADVANCEMENT_OUSTERS_FAST_MOVE))
		//)	
		//{
			//bAffterEffect  = TRUE ; 
		//}

	}
	//------------------------------------------------------------

	//if(direction != 6 && bAffterEffect)
	//	DrawAfterACOusters( pPoint, pCreature, action, direction, frame );

	if (addonInfo.bAddon && !pCreatureWear->IsGhost(1))
	{
		//				DEBUG_ADD("[DrawCreature] DrawCloth");
		int clothes = addonInfo.FrameID;
		
		
		//FRAME_ARRAY &FA = m_OustersFPK[clothes][tempAction][direction];
		
		FRAME_ARRAY &FA = m_AdvancementOustersFPK[ 1 ][ tempAction ][ direction ];
		
		// �ִ� ������ ���
		if (FA.GetSize() > frame)
		{
			CFrame &Frame = FA[frame];					
			int sprite	= Frame.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
			int cx		= Frame.GetCX();	//m_AddonFPK[clothes][action][direction][frame].GetCX();
			int cy		= Frame.GetCY();	//m_AddonFPK[clothes][action][direction][frame].GetCY();
			
			//CIndexSprite* pSprite = &m_OustersSPK[ sprite ];					
			CIndexSprite* pSprite = &m_AdvancementOustersSPK[ sprite ];
			
			pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
			pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
			
			//---------------------------------------- 
			// ĳ���� ���� �簢�� ���� ����
			//---------------------------------------- 	
			rect.left	= pointTemp.x;
			rect.top	= pointTemp.y;
			rect.right	= rect.left + pSprite->GetWidth();
			rect.bottom = rect.top + pSprite->GetHeight();
			pCreature->AddScreenRect( &rect );
			
			//---------------------------------------- 
			// ĳ���� �κ� ������ �ٲ�� ���
			//---------------------------------------- 
			if (addonInfo.bEffectColor)	//colorSet < MAX_COLORSET)
			{
				m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, 
					addonInfo.EffectColorSet);
			}
			//---------------------------------------- 
			// �������� ĳ���� ���
			//---------------------------------------- 
			else
			{
				CIndexSprite::SetUsingColorSetOnly( 0, pCreature->GetBodyColor1() );	// �Ӹ���
				
				int Colorset;
				
				Colorset = addonInfo.ColorSet2;
				
				if( Colorset == QUEST_ITEM_COLOR || Colorset == UNIQUE_ITEM_COLOR )
					Colorset = MItem::GetSpecialColorItemColorset( Colorset );
				CIndexSprite::SetUsingColorSetOnly( 1, Colorset );	// �ʻ�
				
				if(bChakram == false)	// ����Ʋ���� ���� ������
				{
					if(addonInfoChakram.bAddon)
					{
						Colorset = addonInfoChakram.ColorSet2;
						if (Colorset == QUEST_ITEM_COLOR||Colorset == UNIQUE_ITEM_COLOR )
							Colorset = MItem::GetSpecialColorItemColorset( Colorset );
						
						CIndexSprite::SetUsingColorSetOnly( 2, Colorset );	// ��
					}
					else
					{
						Colorset = defaultCoatColor;
						if (Colorset == QUEST_ITEM_COLOR||Colorset == UNIQUE_ITEM_COLOR )
							Colorset = MItem::GetSpecialColorItemColorset( Colorset );
						
						CIndexSprite::SetUsingColorSetOnly( 2, Colorset );	// ��
					}
				}
				else
				{
					Colorset = defaultCoatColor;
					if(addonInfoChakram.bAddon)
						Colorset = addonInfoChakram.ColorSet2;
					if (Colorset == QUEST_ITEM_COLOR||Colorset == UNIQUE_ITEM_COLOR )
						Colorset = MItem::GetSpecialColorItemColorset( Colorset );
					
					CIndexSprite::SetUsingColorSetOnly( 2, Colorset );	// ��
					
				}
				
				if(bootsAddonInfo.bAddon)
				{
					Colorset = bootsAddonInfo.ColorSet2;
					if (Colorset == QUEST_ITEM_COLOR||Colorset == UNIQUE_ITEM_COLOR )
						Colorset = MItem::GetSpecialColorItemColorset( Colorset );
					
					CIndexSprite::SetUsingColorSetOnly( 3, Colorset );	// ������
				}
				else
				{
					Colorset = defaultCoatColor ;
					if (Colorset == QUEST_ITEM_COLOR||Colorset == UNIQUE_ITEM_COLOR )
						Colorset = MItem::GetSpecialColorItemColorset( Colorset );
					
					CIndexSprite::SetUsingColorSetOnly( 3, Colorset );	// ��
				}
				
				
				// ��Ӱ� ���
				if (pCreature->IsFade())
				{
					m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
				}
				else
				{
					m_pSurface->BltIndexSprite(&pointTemp, pSprite);
				}
				//if(direction == 6 && bAffterEffect)
				//	DrawAfterACOusters( pPoint, pCreature, action, direction, frame );
			}			
		}
	}
	
	if (bChakram && !pCreatureWear->IsGhost(2))
	{
		//				DEBUG_ADD("[DrawCreature] DrawChakram");
		int clothes = addonInfoChakram.FrameID;
		
		//FRAME_ARRAY &FA = m_OustersFPK[clothes][tempAction][direction];
		
		
		

		FRAME_ARRAY &FA = m_AdvancementOustersFPK[ 0 ][ tempAction ][ direction ];
		
		// �ִ� ������ ���
		if (FA.GetSize() > frame)
		{
			//					DEBUG_ADD_FORMAT("[DrawCreature] FA.GetSize() > frame %d %d", FA.GetSize(), frame);
			CFrame &Frame = FA[frame];					
			int sprite	= Frame.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
			int cx		= Frame.GetCX();	//m_AddonFPK[clothes][action][direction][frame].GetCX();
			int cy		= Frame.GetCY();	//m_AddonFPK[clothes][action][direction][frame].GetCY();
			
			//CIndexSprite* pSprite = &m_OustersSPK[ sprite ];					
			CIndexSprite* pSprite = &m_AdvancementOustersSPK[ sprite ];
			
			pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
			pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
			
			//---------------------------------------- 
			// ĳ���� �κ� ������ �ٲ�� ���
			//---------------------------------------- 
			if (addonInfoChakram.bEffectColor)	//colorSet < MAX_COLORSET)
			{
				m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, 
					addonInfoChakram.EffectColorSet);
			}
			//---------------------------------------- 
			// �������� ĳ���� ���
			//---------------------------------------- 
			else
			{
				int colorset1, colorset2;
				colorset1 = addonInfoChakram.ColorSet1;
				colorset2 = addonInfoChakram.ColorSet2;
				
				if( colorset1 == QUEST_ITEM_COLOR || colorset1 == UNIQUE_ITEM_COLOR )
					colorset1 = MItem::GetSpecialColorItemColorset( colorset1 );
				if( colorset2 == QUEST_ITEM_COLOR || colorset2 == UNIQUE_ITEM_COLOR )
					colorset2 = MItem::GetSpecialColorItemColorset( colorset2 );
				CIndexSprite::SetUsingColorSet( colorset1, colorset2 );

				

				// ��Ӱ� ���
				if (pCreature->IsFade())
				{
					m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
				}
				else
				{
					m_pSurface->BltIndexSprite(&pointTemp, pSprite);
				}
				//if(direction == 6 && bAffterEffect)
				//	DrawAfterACOusters( pPoint, pCreature, action, direction, frame );
			}						
			
		}
		else
		{
			DEBUG_ADD_FORMAT("[DrawCreature] FA.GetSize() <= frame %d %d %d %d", FA.GetSize(), frame, pCreatureWear->GetActionCount(), pCreatureWear->GetActionCountMax());
			//					DEBUG_ADD_FORMAT("[DrawCreature] FA.GetSize() <= frame %d %d %d", clothes, tempAction, direction);
		}
	}
	
#ifdef OUTPUT_DEBUG_DRAW_PROCESS
	DEBUG_ADD("dcOK");
#endif
}


void	MTopView::DrawSlayerCharacter( POINT *pPoint, MCreature* pCreature, int action, int direction, int frame, int FrameIndex )
{
	if(pCreature->HasEffectStatus(EFFECTSTATUS_INSTALL_TURRET))
		DrawInstallTurret( pPoint, pCreature, action, direction, frame, FrameIndex );
	else
	{
		MCreatureWear*	pCreatureWear = (MCreatureWear*)pCreature;
		
		// Creature�� Action�� �´� add-on�� ����Ѵ�.
		//action = pCreature->GetAction();
		
		WORD clothes;
		BYTE clothesType;
		
		BOOL	bAffterEffect  = FALSE ; 
		//------------------------------------------------------------
		// �ܻ� �׸����� ���� ó�� 
		//------------------------------------------------------------
		if ( (pCreature->HasEffectStatus( EFFECTSTATUS_HOLY_SWORD) || 
			  pCreature->HasEffectStatus( EFFECTSTATUS_HOLY_BLADE) ||
			  pCreature->HasEffectStatus( EFFECTSTATUS_BURST_GUN)  || 	
			 pCreature->HasEffectStatus( EFFECTSTATUS_HOLY_MACE))
		)
		{
				if( ((action >=  ACTION_MOVE				&& action <=  ACTION_ATTACK)  ||
					(action >=  ACTION_SLAYER_GUN_SR	    && action <=  ACTION_SLAYER_THROW_WEAPON)  ||
					(action >=  ACTION_SLAYER_GUN_SG	    && action <=  ACTION_SLAYER_THROW_POTION)  ||
					(action >=  ACTION_SLAYER_GUN_SR_SLOW	&& action <=  ACTION_SLAYER_BLADE_2_FAST) ) && (direction != 2) 
				)
				{	
					//bAffterEffect = TRUE ; 
				}
					
		}
		
		//------------------------------------------------------------
		// Fade Out ���
		//------------------------------------------------------------
		if (pCreature->HasEffectStatus( EFFECTSTATUS_FADE_OUT ))
		{
			DrawFadeOut( pPoint, pCreature, action, direction, frame);
		}
		
	//	if(direction != 6 && bAffterEffect)
	//		DrawAfterSlayer( pPoint, pCreature, action, direction, frame );


		//------------------------------------------------------------
		// Fast Move ���
		//------------------------------------------------------------
		if (pCreature->IsFastMove())
		{
			DrawFastMove( pPoint, pCreature, action, direction, frame );						
		}
		//------------------------------------------------------------
		// Invisible  - Slayer�� snipping mode���� �����̴�.
		//------------------------------------------------------------
		else if (pCreature->IsInvisible())
		{
			DrawInvisible( pPoint, pCreature, action, direction, frame );
		}
		//------------------------------------------------------------
		// ���� �ܻ� ���
		//------------------------------------------------------------
		else if (
			(pCreature->HasEffectStatus( EFFECTSTATUS_DANCING_SWORD )
			|| pCreature->HasEffectStatus( EFFECTSTATUS_GHOST_BLADE )
			|| pCreature->HasEffectStatus( EFFECTSTATUS_REDIANCE ) && pCreature->GetAction() == ACTION_STAND
			)
			)
		{
			DrawWeaponFadeOut( pPoint, pCreature, action, direction, frame );			
		}
		//------------------------------------------------------------
		// �Ϲ����� ���
		//------------------------------------------------------------
		else
		{
			for (int i=0; i<ADDON_MAX; i++)
			{
				// Creature�� ���� ���⿡ ����...
				// ���� ������ִ� ������ �ٸ� �� �ִ�.
				clothesType = MCreatureWear::s_AddonOrder[pCreature->GetDirection()][i];
				
				// i��° ������ ���� �԰� �ִٸ� ����� �ش�.
				const MCreatureWear::ADDON_INFO& addonInfo = pCreatureWear->GetAddonInfo(clothesType);
				
				if (addonInfo.bAddon)
				{
					clothes = addonInfo.FrameID;
					
					
					FRAME_ARRAY &FA = m_AddonFPK[clothes][action][direction];
					
					// �ִ� ������ ���
					if (FA.GetSize() > frame)
					{
						CFrame &Frame = FA[frame];					
						int sprite	= Frame.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
						int cx		= Frame.GetCX();	//m_AddonFPK[clothes][action][direction][frame].GetCX();
						int cy		= Frame.GetCY();	//m_AddonFPK[clothes][action][direction][frame].GetCY();
						
						
						CIndexSprite* pSprite = &m_AddonSPK[ sprite ];
						
						
						pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
						pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
						
						//---------------------------------------- 
						// ĳ���� ���� �簢�� ���� ����
						//---------------------------------------- 	
						rect.left	= pointTemp.x;
						rect.top	= pointTemp.y;
						rect.right	= rect.left + pSprite->GetWidth();
						rect.bottom = rect.top + pSprite->GetHeight();
						pCreature->AddScreenRect( &rect );
						
						//---------------------------------------- 
						// ĳ���� �κ� ������ �ٲ�� ���
						//---------------------------------------- 
						if (addonInfo.bEffectColor)	//colorSet < MAX_COLORSET)
						{
							m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, 
								addonInfo.EffectColorSet);
						}
						//---------------------------------------- 
						// �������� ĳ���� ���
						//---------------------------------------- 
						else
						{
							int colorSet1 = addonInfo.ColorSet1, colorSet2 = addonInfo.ColorSet2;
							if(colorSet2 == UNIQUE_ITEM_COLOR || colorSet2 == QUEST_ITEM_COLOR)
							{
								// ����ũ �������̸�
								//									if(colorSet2 == QUEST_ITEM_COLOR)
								//										colorSet2 = MItem::GetQuestItemColorset();
								//									else
								//										colorSet2 = MItem::GetUniqueItemColorset();										
								
								colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
								if(addonInfo.ItemClass != ITEM_CLASS_COAT && addonInfo.ItemClass != ITEM_CLASS_TROUSER)
									colorSet1 = colorSet2;
							}
							
							CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
							
							//if(direction == 6 && bAffterEffect)
							//	DrawAfterSlayer( pPoint, pCreature, action, direction, frame );
							
							// ��Ӱ� ���
							if (pCreature->IsFade())
							{
								m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
							}
							else
							{
								m_pSurface->BltIndexSprite(&pointTemp, pSprite);
							}
						}						
						
						// �������� ���
						//CIndexSprite::SetUsingColorSet( addonInfo.ColorSet1, addonInfo.ColorSet2 );
						//m_pSurface->BltIndexSprite(&pointTemp, pSprite);
						
					}
				}
			}
		}
	}
#ifdef OUTPUT_DEBUG_DRAW_PROCESS
DEBUG_ADD("dcOK");
#endif
}

void	MTopView::DrawAdvancementClassSlayerCharacter( POINT *pPoint, MCreature* pCreature, int action, int direction, int frame, int FrameIndex )
{
	if(pCreature->HasEffectStatus(EFFECTSTATUS_INSTALL_TURRET))
		DrawInstallTurret( pPoint, pCreature, action, direction, frame, FrameIndex );
	else
	{
		
		// ToT �ð�����.. �ϵ� �ڵ�.. by sonee
		action = ConvAdvancementSlayerActionFromSlayerAction( action, dynamic_cast< MCreatureWear* >(pCreature) );

		if( action == -1 )
			return;
		else
			action -= ADVANCEMENT_ACTION_START;

		// 2005.08.12 Sjheon �޺� ��ų ���� Add
		/*int Frame_Save = frame ; 
		int Action_Save= action;
	
		int		iComboCnt = pCreature->GetCombo();

		if((action >= (ACTION_ADVANCEMENT_SLAYER_COMBO_SWARD_SLOW - ADVANCEMENT_ACTION_START)) && (iComboCnt < 4 && iComboCnt > 0 ))
		{
			//frame -= 8 ; 
			WORD  fCreatureType	= action - 	(ACTION_ADVANCEMENT_SLAYER_COMBO_SWARD_SLOW  - ADVANCEMENT_ACTION_START)  ; 

			WORD  fWeaponSpeed = pCreature->GetWeaponSpeed() ;

			WORD Frame = AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][iComboCnt - 1] + 1 ; 

			if(frame > (Frame - 1) )
			{
				
				frame = frame  - (Frame - 1) ; // ame_Save - (Frame  - ((iComboCnt -1) *2)); 
				frame += (2 * (iComboCnt - 1)) ; 
				//AdvanceComboCancelFrameTable[fCreatureType][fWeaponSpeed][ComboActionCnt - 1])

				action = action + 6 ; 
			}
		}*/
		// 2005.08.12 Sjheon �޺� ��ų ���� End
	
		MCreatureWear*	pCreatureWear = (MCreatureWear*)pCreature;
		
		// Creature�� Action�� �´� add-on�� ����Ѵ�.
		//action = pCreature->GetAction();
		
		int clothes;
		BYTE clothesType;
		BOOL	bAffterEffect  = FALSE ; 
		//------------------------------------------------------------
		// �ܻ� �׸����� ���� ó�� 
		//------------------------------------------------------------
		if ( (pCreature->HasEffectStatus( EFFECTSTATUS_HOLY_SWORD) || 
			  pCreature->HasEffectStatus( EFFECTSTATUS_HOLY_BLADE) ||
			  pCreature->HasEffectStatus( EFFECTSTATUS_BURST_GUN)  || 	
			 pCreature->HasEffectStatus( EFFECTSTATUS_HOLY_MACE))
		)
		{
			int AdvancementAction = ACTION_ADVANCEMENT_SLAYER_STOP_SWORD + action ; 
			//if( ((AdvancementAction >=  ACTION_ADVANCEMENT_SLAYER_MOVE_SWORD		  && 
			//	 AdvancementAction <=  ACTION_ADVANCEMENT_SLAYER_MOVE_MACE_AND_CROSS) ||
			//	(AdvancementAction >=  ACTION_ADVANCEMENT_SLAYER_COMBO_SWARD_SLOW	  && 
			//	 AdvancementAction <=  ACTION_ADVANCEMENT_SLAYER_COMBO_BLADE_FAST)	  ||
			//	(AdvancementAction >=  ACTION_ADVANCEMENT_SLAYER_ATTACK_AR_GUN_SLOW   && 
			//	 AdvancementAction <=  ACTION_ADVANCEMENT_SLAYER_ATTACK_SR_GUN_FAST)) 
			//)/
			//{
				//bAffterEffect = TRUE ; 
			//}
		}
		//------------------------------------------------------------
		
		//------------------------------------------------------------
		// Fade Out ���
		//------------------------------------------------------------
		if (pCreature->HasEffectStatus( EFFECTSTATUS_FADE_OUT ))
		{
			DrawFadeOutForACSlayer( pPoint, pCreature, action, direction, frame);			
		}
		
	//	if(direction == 2 && bAffterEffect)
	//	{
	//		DrawAfterACSlayer( pPoint, pCreature, action, direction, frame );
	//	}
				
		
		//------------------------------------------------------------
		// Fast Move ���
		//------------------------------------------------------------
		if (pCreature->IsFastMove())
		{
			DrawFastMoveForACSlayer( pPoint, pCreature, action, direction, frame );				
		}
		//------------------------------------------------------------
		// Invisible  - Slayer�� snipping mode���� �����̴�.
		//------------------------------------------------------------
		else if (pCreature->IsInvisible())
		{
			DrawInvisibleForACSlayer( pPoint, pCreature, action, direction, frame );			
		}
		//------------------------------------------------------------
		// ���� �ܻ� ���
		//------------------------------------------------------------
		else if (
			(pCreature->HasEffectStatus( EFFECTSTATUS_DANCING_SWORD )
			|| pCreature->HasEffectStatus( EFFECTSTATUS_GHOST_BLADE )
			|| pCreature->HasEffectStatus( EFFECTSTATUS_REDIANCE ) && pCreature->GetAction() == ACTION_STAND
			)
			)
		{
			DrawWeaponFadeOutForACSlayer( pPoint, pCreature, action, direction, frame );
		}
		//------------------------------------------------------------
		// �Ϲ����� ���
		//------------------------------------------------------------
		else
		{
			CCreatureFramePack& slayerFPK = pCreature->IsMale() ? m_AdvancementSlayerManFPK : m_AdvancementSlayerWomanFPK;
			CIndexSpritePack& addonISPK = pCreature->IsMale() ? m_AdvancementSlayerManSPK : m_AdvancementSlayerWomanSPK;
			
			for( int i = 0; i < AC_ADDON_MAX; ++i )
			{
				clothesType = MCreatureWear::s_ACAddonOrder[ direction ][ i ];
				
				const MCreatureWear::ADDON_INFO& addonInfo = pCreatureWear->GetACAddonInfo( clothesType );
			
				if( addonInfo.bAddon || clothesType == AC_ADDON_BODY )
				{
					// ������ ��Ʈ �״�θ� ����Ѵ�. ���Ŀ� ���� �߰� �Ǿ����� ���� ������ ���� �ؼ� ����.
					// addonInfo.FrameID �� �� ������ �ְ� �����Ͽ� ����ȴ�.

					clothes = GetAdvancementPartFromItemClass( addonInfo.ItemClass, addonInfo.FrameID );

					if( clothes == -1 ) continue;

					
					//int iFrame = FA.GetSize() ; 

					//if(action >= ACTION_ADVANCEMENT_SLAYER_COMBO_SWARD_SLOW)
					//	iFrame = 8  ; 
		
					

					//int Frame_Save = frame ; 
					//int Action_Save= action;

					FRAME_ARRAY& FA = slayerFPK[ clothes ][ action ][ direction ];

					if( FA.GetSize() > frame )
					{
						CFrame &Frame = FA[frame];					
						int sprite	= Frame.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
						int cx		= Frame.GetCX();	//m_AddonFPK[clothes][action][direction][frame].GetCX();
						int cy		= Frame.GetCY();	//m_AddonFPK[clothes][action][direction][frame].GetCY();

						CIndexSprite* pSprite = &addonISPK[ sprite ];
						pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
						pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
						
						//---------------------------------------- 
						// ĳ���� ���� �簢�� ���� ����
						//---------------------------------------- 	
						rect.left	= pointTemp.x;
						rect.top	= pointTemp.y;
						rect.right	= rect.left + pSprite->GetWidth();
						rect.bottom = rect.top + pSprite->GetHeight();
						pCreature->AddScreenRect( &rect );
						
						//---------------------------------------- 
						// ĳ���� �κ� ������ �ٲ�� ���
						//---------------------------------------- 
						if (addonInfo.bEffectColor)	//colorSet < MAX_COLORSET)
						{
							m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, 
								addonInfo.EffectColorSet);
						}
						//---------------------------------------- 
						// �������� ĳ���� ���
						//---------------------------------------- 
						else
						{
							if( addonInfo.bAddon )
							{
								int colorSet1 = addonInfo.ColorSet1, colorSet2 = addonInfo.ColorSet2;
								if(colorSet2 == UNIQUE_ITEM_COLOR || colorSet2 == QUEST_ITEM_COLOR)
								{
									colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
									if(addonInfo.ItemClass != ITEM_CLASS_COAT && addonInfo.ItemClass != ITEM_CLASS_TROUSER)
										colorSet1 = colorSet2;
								}
								CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
							}
							else
								CIndexSprite::SetUsingColorSet( 375, 375 );
							

						//	if(direction != 2 && bAffterEffect)
						//	{
						//		DrawAfterACSlayer( pPoint, pCreature, action, direction, frame );
						//	}
							
							if (pCreature->IsFade())
							{	
								m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
							}
							else
							{
								m_pSurface->BltIndexSprite(&pointTemp, pSprite);
							}
						}						
					}
				}
			}
		}
	}
}

void	MTopView::DrawAdvancementClassVampireCharacter( POINT* pPoint, MCreature* pCreature, int action, int direction, int frame, int body, int frameindex )
{
	//------------------------------------------------
	// �� �������
	//------------------------------------------------
	int casketValue = pCreature->GetCasketCount();
	int creature_type = pCreature->GetCreatureType();
	bool bInCasket = pCreature->IsInCasket();
	bool bCasketOnly = (bInCasket && casketValue==0);

	action = GetAdvancementVampireActionFromVampireAction( action, pCreature );

	if( action == -1 )
		return;
	else
		action -= ADVANCEMENT_ACTION_START;
	
	// 2005.08.12 Sjheon �޺� ��ų ���� Add
	/*
	int		iComboCnt = pCreature->GetCombo();

	if((action >= (ACTION_ADVANCEMENT_COMBO_SLOW - ADVANCEMENT_ACTION_START)) && (iComboCnt < 4 && iComboCnt > 0 ))
	{
		//frame -= 8 ; 
		WORD  fCreatureType	= action - 	(ACTION_ADVANCEMENT_COMBO_SLOW  - ADVANCEMENT_ACTION_START)  ; 

		WORD  fWeaponSpeed = pCreature->GetWeaponSpeed() ;

		WORD Frame = AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][iComboCnt - 1] + 1 ; 

		if(frame > (Frame - 1) )
		{
			frame -= Frame  - ((iComboCnt -1) *2); 
			action += 3 ; 
		}
	}*/
	// 2005.08.12 Sjheon �޺� ��ų ���� End

	CCreatureFramePack& advanceVampireFPK = pCreature->IsMale() ? m_AdvancementVampireManFPK : m_AdvancementVampireWomanFPK;
	CIndexSpritePack& advanceVampireSPK = pCreature->IsMale() ? m_AdvancementVampireManSPK : m_AdvancementVampireWomanSPK;
	
	BOOL	bAffterEffect  = FALSE ; 
	int iAction = GetAdvancementVampireActionFromVampireAction(action , pCreature) ; 
	//------------------------------------------------------------
	// �ܻ� �׸����� ���� ó�� 
	//------------------------------------------------------------
	if ( (pCreature->HasEffectStatus( EFFECTSTATUS_DARK_FORCE))
	)
	{
		int AdvancementAction = ACTION_ADVANCEMENT_STOP + action ; 

 
		//if( (AdvancementAction >=  	ACTION_ADVANCEMENT_MOVE)		   ||	
		//	((AdvancementAction >=  ACTION_ADVANCEMENT_MAGIC		   && 
		//	 AdvancementAction <=  ACTION_ADVANCEMENT_DESTROY_WEAPON)  ||
		//	(AdvancementAction >=  ACTION_ADVANCEMENT_COMBO_SLOW      && 
		//	 AdvancementAction <=  ACTION_ADVANCEMENT_COMBO_FAST))
		//)
		//{
		//	if( iAction != -1 )
		//		iAction -= ADVANCEMENT_ACTION_START;
			//bAffterEffect  = TRUE ; 
		//}

	}
	//------------------------------------------------------------
	

	//if(direction != 6 && bAffterEffect)
	//{
	//	if( iAction != -1 )
	//	{
		//	iAction -= ADVANCEMENT_ACTION_START;
	//		DrawAfterACVampire( pPoint, pCreature, iAction, direction, frame );
	//	}
	//}
	//----------------------------------------------------
	// ������ ���� ����ϴ� ���� �� ����� ���Ѵ�.
	//----------------------------------------------------
	if (!bCasketOnly)
	{
		
		FRAME_ARRAY& FA = advanceVampireFPK[0][action][direction];
		
		if (FA.GetSize() > frame)
		{
			CFrame& Frame =	FA[frame];
			int sprite = Frame.GetSpriteID(),	//m_CreatureFPK[body][action][direction][frame].GetSpriteID(),
				cx		= Frame.GetCX(),	//m_CreatureFPK[body][action][direction][frame].GetCX(),
				cy		= Frame.GetCY();	//m_CreatureFPK[body][action][direction][frame].GetCY();
			
			// ��ǥ ����
			pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
			pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
			
			CIndexSprite* pSprite = &advanceVampireSPK[ sprite ];
			
			//---------------------------------------- 
			// ĳ���� ���� �簢�� ���� ����
			//---------------------------------------- 	
			rect.left	= pointTemp.x;
			rect.top	= pointTemp.y;
			rect.right	= rect.left + pSprite->GetWidth();
			rect.bottom = rect.top + pSprite->GetHeight();
			if(frameindex==0 )
				pCreature->SetScreenRect( &rect );
			//-----------------------------------------------------------
			// CutHeight
			//-----------------------------------------------------------
			bool bCutHeight = pCreature->IsCutHeight();
			int previousClipBottom;
			if (bCutHeight)
			{
				previousClipBottom = m_pSurface->GetClipBottom();
				m_pSurface->SetClipBottom( rect.bottom - TILE_Y_HALF );
				
				pointTemp.y += pCreature->GetCutHeightCount() - TILE_Y_HALF;
			}
			
			//-----------------------------------------------------------
			// ���� ���� ��� 			
			//-----------------------------------------------------------
			// vampire
			if (pCreature->IsFakeDie())
			{
				WORD colorSet = pCreature->GetAttachEffectColor();
				
				if( pCreature->GetCreatureType() == CREATURETYPE_BAT && pCreature->GetBatColor() != 0xFFFF)
					colorSet = pCreature->GetBatColor();
				
				//---------------------------------------- 
				// ĳ���� ��ü ������ �ٲ�� ���					
				//---------------------------------------- 
				if (colorSet < MAX_COLORSET)
				{
					m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, colorSet);
				}
				else
				{
					int colorSet1 = pCreature->GetBodyColor1();
					int colorSet2 = pCreature->GetBodyColor2();
					
					if( colorSet1 == QUEST_ITEM_COLOR || colorSet1 == UNIQUE_ITEM_COLOR )
						colorSet1 = MItem::GetSpecialColorItemColorset( colorSet1 );
					
					if( colorSet2 == QUEST_ITEM_COLOR || colorSet2 == UNIQUE_ITEM_COLOR )
						colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
					
					CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
					
					int netValue = pCreature->GetFakeDieCount()/5;
					
					CSpriteSurface::s_Value1 = netValue;
					
					CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_NET );
					CIndexSprite::SetEffect( CIndexSprite::EFFECT_NET );
					
					m_pSurface->BltIndexSpriteEffect(&pointTemp, pSprite);
					
				}
			}
			else if (pCreature->IsInvisible())
			{
				WORD colorSet = pCreature->GetAttachEffectColor();
				
				if( pCreature->GetCreatureType() == CREATURETYPE_BAT && pCreature->GetBatColor() != 0xFFFF)
					colorSet = pCreature->GetBatColor();
				
				//---------------------------------------- 
				// ĳ���� ��ü ������ �ٲ�� ���					
				//---------------------------------------- 
				if (colorSet < MAX_COLORSET)
				{
					// IndexSprite���� EFFECT...�ְ�...
					// ������~ �ܰ������� ��Ÿ����/�������� �ؾߵ�.. - -;
					m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, colorSet);
				}
				else
				{
					int colorSet1 = pCreature->GetBodyColor1();
					int colorSet2 = pCreature->GetBodyColor2();
					
					if( colorSet1 == QUEST_ITEM_COLOR || colorSet1 == UNIQUE_ITEM_COLOR )
						colorSet1 = MItem::GetSpecialColorItemColorset( colorSet1 );
					
					if( colorSet2 == QUEST_ITEM_COLOR || colorSet2 == UNIQUE_ITEM_COLOR )
						colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
					
					CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
					
					int wipeValue = pCreature->GetInvisibleCount();
					
					if (wipeValue==0)
					{
						m_pSurface->BltIndexSprite(&pointTemp, pSprite);							
					}
					else if (wipeValue==64)
					{
						CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_SIMPLE_OUTLINE );
						CIndexSprite::SetEffect( CIndexSprite::EFFECT_SIMPLE_OUTLINE );
						
						m_pSurface->BltIndexSpriteEffect(&pointTemp, pSprite);
					}
					else
					{
						CSpriteSurface::s_Value1 = wipeValue;
						
						CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_WIPE_OUT );
						CIndexSprite::SetEffect( CIndexSprite::EFFECT_WIPE_OUT );
						
						m_pSurface->BltIndexSpriteEffect(&pointTemp, pSprite);
					}							
				}
			}					
			else
			{	
				//-----------------------------------------------------------
				// ������ �����̴� ��
				//-----------------------------------------------------------
				if (pCreature->IsFastMove() || pCreature->IsBloodyZenith())
				{
					int colorSet1 = pCreature->GetBodyColor1();
					int colorSet2 = pCreature->GetBodyColor2();
					
					if( colorSet1 == QUEST_ITEM_COLOR || colorSet1 == UNIQUE_ITEM_COLOR )
						colorSet1 = MItem::GetSpecialColorItemColorset( colorSet1 );
					
					if( colorSet2 == QUEST_ITEM_COLOR || colorSet2 == UNIQUE_ITEM_COLOR )
						colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
					
					
					CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
					
					POINT pointTemp2;
					
					int fastMoveShadowMax = 2;
					if(pCreature->IsBloodyZenith())
					{
						fastMoveShadowMax = pCreature->GetBloodyZenithCount();
						pCreature->UpdateBloodyZenith();
					}
					for(int fastMoveShadow = fastMoveShadowMax; fastMoveShadow > 0; fastMoveShadow--)
					{
						// 1 pixel skip
						pointTemp2.x = pointTemp.x - (pCreature->GetCX() >> 1)*fastMoveShadow;
						pointTemp2.y = pointTemp.y - (pCreature->GetCY() >> 1)*fastMoveShadow;
						if(pCreature->IsBloodyZenith())
						{
							pointTemp2.y -= sin((double)max(0, pCreature->GetMoveCount()-fastMoveShadow)*3.141592/(double)pCreature->GetMoveCountMax())*100;
						}
						
						m_pSurface->BltIndexSpriteDarkness(&pointTemp2, pSprite, min(2, fastMoveShadow));
					}
					
				}
				
				if(pCreature->IsBloodyZenith())
				{
					pointTemp.y -= sin((double)pCreature->GetMoveCount()*3.141592/(double)pCreature->GetMoveCountMax())*100;
				}
				WORD colorSet = pCreature->GetAttachEffectColor();
				
				if( pCreature->GetCreatureType() == CREATURETYPE_BAT && pCreature->GetBatColor() != 0xFFFF)
					colorSet = pCreature->GetBatColor();
				
				//---------------------------------------- 
				// ĳ���� ��ü ������ �ٲ�� ���					
				//---------------------------------------- 
				if (colorSet < MAX_COLORSET)
				{
					m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, colorSet);
				}
				//---------------------------------------- 
				// �������� ���� ���
				//---------------------------------------- 					
				else
				{				
					int colorSet1 = pCreature->GetBodyColor1();
					int colorSet2 = pCreature->GetBodyColor2();
					
					if( colorSet1 == QUEST_ITEM_COLOR || colorSet1 == UNIQUE_ITEM_COLOR )
						colorSet1 = MItem::GetSpecialColorItemColorset( colorSet1 );
					
					if( colorSet2 == QUEST_ITEM_COLOR || colorSet2 == UNIQUE_ITEM_COLOR )
						colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
					
					CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
					
					int shadowCount = pCreature->GetShadowCount();
					
					//----------------------------------------
					// Shadow���
					//----------------------------------------
					if (shadowCount)
					{
						bool bDrawShadowFirst = (direction<=4) || creature_type == 764 ||  creature_type == 765;
						if (!bDrawShadowFirst)
						{
							if (pCreature->IsFade())
							{
								m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
							}
							else
							{
								m_pSurface->BltIndexSprite(&pointTemp, pSprite);
							}
						}

						// 0, 1, 2, 3, 4, 5
						const int darkbits[6] =
						{
							0, 1, 1, 2, 2, 3
						};
						
						POINT pointTemp2;
						
						// �̵��̸� ��ǥ�� �ٲ��
						int cxStep = 0, cyStep = 0, cxInc =0 , cyInc = 0;
						if (action==ACTION_MOVE)
						{
							cxInc = -pCreature->GetCX();
							cyInc = -pCreature->GetCY();
						}
						
						
						int faNum = FA.GetSize();
						for (int f=1; f<=shadowCount; f++)
						{
							int frame_f = frame-f;
							
							//---------------------------------------- 
							// f frame ��
							//---------------------------------------- 
							if (frame_f < 0)
							{
								frame_f += faNum;
							}
							
							CFrame &Frame_f = FA[frame_f];
							int sprite_f	= Frame_f.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
							
							CIndexSprite* pSprite_f = &m_CreatureSPK[ sprite_f ];
							
							int cx_f		= Frame_f.GetCX();
							int cy_f		= Frame_f.GetCY();
							
							pointTemp2.x = pPoint->x + cx_f + cxStep;
							pointTemp2.y = pPoint->y + cy_f + cyStep;
							cxStep += cxInc;
							cyStep += cyInc;
							
							m_pSurface->BltIndexSpriteDarkness(&pointTemp2, pSprite_f, darkbits[f]);																		

						}
						
						if (bDrawShadowFirst)
						{
							if (pCreature->IsFade())
							{
								m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
							}
							else
							{
								m_pSurface->BltIndexSprite(&pointTemp, pSprite);
							}

						}
					}
					//----------------------------------------
					// ���� ���
					//----------------------------------------
					else
					{
						// ��Ӱ� ���
						if (pCreature->IsFade())
						{
							m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
						}
						else
						{
							m_pSurface->BltIndexSprite(&pointTemp, pSprite);
							
						}
					//	if(direction == 6 && bAffterEffect)
					//	{
					//		if( iAction != -1 )
					//		{
					//		//	iAction -= ADVANCEMENT_ACTION_START;
					//			DrawAfterACVampire( pPoint, pCreature, iAction, direction, frame );
					//		}
					//		
					//	}
					}
				}
			}

			if (bCutHeight)
			{
				m_pSurface->SetClipBottom( previousClipBottom );
			}

			// 2004, 10, 28, sobeit add start  - ���� ų ����Ʈ �ش� ���Ϳ� ǥ��.
			if(pCreature->IsAlive() && (g_CurrentFrame&0x04)&&UI_IsMonsterKillQuest_Monster((*g_pCreatureTable)[pCreature->GetCreatureType()].SpriteTypes[0]))
			//if(pCreature->IsAlive() && (g_CurrentFrame&0x04))
			{
				UI_ShowTargetArrow(pPoint->x + 12 ,pPoint->y- pCreature->GetHeight()-20);
			}
		// 2004, 10, 28, sobeit add end
		}

		bool bWeapon = true;

		bool bBat = pCreature->GetCreatureType() == CREATURETYPE_BAT;
		bool bWolf = pCreature->GetCreatureType() == CREATURETYPE_WOLF;
		bool bWerWolf = pCreature->GetCreatureType() == CREATURETYPE_WER_WOLF;

		if( bWeapon && !bBat && !bWolf && !bWerWolf )
		{
			
			FRAME_ARRAY& FAWEAPON = advanceVampireFPK[1][action][direction];
			if (FAWEAPON.GetSize() > frame)
			{
				CFrame& Frame =	FAWEAPON[frame];
				int sprite = Frame.GetSpriteID(),	//m_CreatureFPK[body][action][direction][frame].GetSpriteID(),
					cx		= Frame.GetCX(),	//m_CreatureFPK[body][action][direction][frame].GetCX(),
					cy		= Frame.GetCY();	//m_CreatureFPK[body][action][direction][frame].GetCY();
				
				// ��ǥ ����
				pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
				pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
				
				CIndexSprite* pSprite = &advanceVampireSPK[ sprite ];
				
				//---------------------------------------- 
				// ĳ���� ���� �簢�� ���� ����
				//---------------------------------------- 	
				rect.left	= pointTemp.x;
				rect.top	= pointTemp.y;
				rect.right	= rect.left + pSprite->GetWidth();
				rect.bottom = rect.top + pSprite->GetHeight();
//				if(frameindex==0 )
//					pCreature->SetScreenRect( &rect );
				//-----------------------------------------------------------
				// CutHeight
				//-----------------------------------------------------------
				bool bCutHeight = pCreature->IsCutHeight();
				int previousClipBottom;
				if (bCutHeight)
				{
					previousClipBottom = m_pSurface->GetClipBottom();
					m_pSurface->SetClipBottom( rect.bottom - TILE_Y_HALF );
					
					pointTemp.y += pCreature->GetCutHeightCount() - TILE_Y_HALF;
				}
				
				//-----------------------------------------------------------
				// ���� ���� ��� 			
				//-----------------------------------------------------------
				// vampire
				if (pCreature->IsFakeDie())
				{
					WORD colorSet = pCreature->GetAttachEffectColor();
					
					//---------------------------------------- 
					// ĳ���� ��ü ������ �ٲ�� ���					
					//---------------------------------------- 
					if (colorSet < MAX_COLORSET)
					{
						m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, colorSet);
					}
					else
					{
						int netValue = pCreature->GetFakeDieCount()/5;
						
						CSpriteSurface::s_Value1 = netValue;
						
						CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_NET );
						CIndexSprite::SetEffect( CIndexSprite::EFFECT_NET );
						
						m_pSurface->BltIndexSpriteEffect(&pointTemp, pSprite);

					}
				}
				else if (pCreature->IsInvisible())
				{
					WORD colorSet = pCreature->GetAttachEffectColor();
					
					if( pCreature->GetCreatureType() == CREATURETYPE_BAT && pCreature->GetBatColor() != 0xFFFF)
						colorSet = pCreature->GetBatColor();
					
					//---------------------------------------- 
					// ĳ���� ��ü ������ �ٲ�� ���					
					//---------------------------------------- 
					if (colorSet < MAX_COLORSET)
					{
						// IndexSprite���� EFFECT...�ְ�...
						// ������~ �ܰ������� ��Ÿ����/�������� �ؾߵ�.. - -;
						m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, colorSet);
					}
					else
					{
						int wipeValue = pCreature->GetInvisibleCount();
						
						if (wipeValue==0)
						{
							m_pSurface->BltIndexSprite(&pointTemp, pSprite);							
						}
						else if (wipeValue==64)
						{
							CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_SIMPLE_OUTLINE );
							CIndexSprite::SetEffect( CIndexSprite::EFFECT_SIMPLE_OUTLINE );
							
							m_pSurface->BltIndexSpriteEffect(&pointTemp, pSprite);
						}
						else
						{
							CSpriteSurface::s_Value1 = wipeValue;
							
							CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_WIPE_OUT );
							CIndexSprite::SetEffect( CIndexSprite::EFFECT_WIPE_OUT );
							
							m_pSurface->BltIndexSpriteEffect(&pointTemp, pSprite);
						}
					}
				}					
				else
				{	
					//-----------------------------------------------------------
					// ������ �����̴� ��
					//-----------------------------------------------------------
					if (pCreature->IsFastMove() || pCreature->IsBloodyZenith())
					{
						POINT pointTemp2;
						
						int fastMoveShadowMax = 2;
						if(pCreature->IsBloodyZenith())
						{
							fastMoveShadowMax = pCreature->GetBloodyZenithCount();
							pCreature->UpdateBloodyZenith();
						}
						for(int fastMoveShadow = fastMoveShadowMax; fastMoveShadow > 0; fastMoveShadow--)
						{
							// 1 pixel skip
							pointTemp2.x = pointTemp.x - (pCreature->GetCX() >> 1)*fastMoveShadow;
							pointTemp2.y = pointTemp.y - (pCreature->GetCY() >> 1)*fastMoveShadow;
							if(pCreature->IsBloodyZenith())
							{
								pointTemp2.y -= sin((double)max(0, pCreature->GetMoveCount()-fastMoveShadow)*3.141592/(double)pCreature->GetMoveCountMax())*100;
							}
							
							m_pSurface->BltIndexSpriteDarkness(&pointTemp2, pSprite, min(2, fastMoveShadow));
						}
						
					}
					
					if(pCreature->IsBloodyZenith())
					{
						pointTemp.y -= sin((double)pCreature->GetMoveCount()*3.141592/(double)pCreature->GetMoveCountMax())*100;
					}
					WORD colorSet = pCreature->GetAttachEffectColor();
					
					//---------------------------------------- 
					// ĳ���� ��ü ������ �ٲ�� ���					
					//---------------------------------------- 
					if (colorSet < MAX_COLORSET)
					{
						m_pSurface->BltIndexSpriteColorSet(&pointTemp, pSprite, colorSet);
					}
					//---------------------------------------- 
					// �������� ���� ���
					//---------------------------------------- 					
					else
					{				
						int shadowCount = pCreature->GetShadowCount();
						
						//----------------------------------------
						// Shadow���
						//----------------------------------------
						if (shadowCount)
						{
							bool bDrawShadowFirst = (direction<=4) || creature_type == 764 ||  creature_type == 765;
							if (!bDrawShadowFirst)
							{
								if (pCreature->IsFade())
								{
									m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
								}
								else
								{
									m_pSurface->BltIndexSprite(&pointTemp, pSprite);
								}
							}
							
							// 0, 1, 2, 3, 4, 5
							const int darkbits[6] =
							{
								0, 1, 1, 2, 2, 3
							};
							
							POINT pointTemp2;
							
							// �̵��̸� ��ǥ�� �ٲ��
							int cxStep = 0, cyStep = 0, cxInc =0 , cyInc = 0;
							if (action==ACTION_MOVE)
							{
								cxInc = -pCreature->GetCX();
								cyInc = -pCreature->GetCY();
							}
							
							
							int faNum = FA.GetSize();
							for (int f=1; f<=shadowCount; f++)
							{
								int frame_f = frame-f;
								
								//---------------------------------------- 
								// f frame ��
								//---------------------------------------- 
								if (frame_f < 0)
								{
									frame_f += faNum;
								}
								
								CFrame &Frame_f = FA[frame_f];
								int sprite_f	= Frame_f.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
								
								CIndexSprite* pSprite_f = &m_CreatureSPK[ sprite_f ];
								
								int cx_f		= Frame_f.GetCX();
								int cy_f		= Frame_f.GetCY();
								
								pointTemp2.x = pPoint->x + cx_f + cxStep;
								pointTemp2.y = pPoint->y + cy_f + cyStep;
								cxStep += cxInc;
								cyStep += cyInc;
								
								m_pSurface->BltIndexSpriteDarkness(&pointTemp2, pSprite_f, darkbits[f]);																		
							}
							
							if (bDrawShadowFirst)
							{
								if (pCreature->IsFade())
								{
									m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
								}
								else
								{
									m_pSurface->BltIndexSprite(&pointTemp, pSprite);
								}
							}
						}
						//----------------------------------------
						// ���� ���
						//----------------------------------------
						else
						{
							// ��Ӱ� ���
							if (pCreature->IsFade())
							{
								m_pSurface->BltIndexSpriteDarkness(&pointTemp, pSprite, 1);
							}
							else
							{
								m_pSurface->BltIndexSprite(&pointTemp, pSprite);
								
							}
						//	if(direction == 6 && bAffterEffect)
						//	{
						//		if( iAction != -1 )
						//		{
						//			//iAction -= ADVANCEMENT_ACTION_START;
						//			DrawAfterACVampire( pPoint, pCreature, iAction, direction, frame );
						//		}
						//	}			
						}
					}
				}
			}
		}
	}
		
	//----------------------------------------------------
	// �� ���
	//----------------------------------------------------
	if (bInCasket)
	{
		// �׸��� ������ *2�ؾ��Ѵ�.
		int casketID = SPRITEID_CASKET_1 + pCreature->GetCasketType()*2;
		
		if (casketID < m_EtcSPK.GetSize())
		{
			CSprite* pSprite = &m_EtcSPK[casketID];
			
			if (pSprite!=NULL)
			{
				// tile�� �߽ɿ��� �����.
				pointTemp.x = pPoint->x + TILE_X_HALF - (pSprite->GetWidth()>>1);
				pointTemp.y = pPoint->y + TILE_Y - pSprite->GetHeight();
				
				//---------------------------------------- 
				// ĳ���� ���� �簢�� ���� ����
				//---------------------------------------- 	
				rect.left	= pointTemp.x; 
				rect.top	= pointTemp.y;
				rect.right	= rect.left + pSprite->GetWidth();
				rect.bottom = rect.top + pSprite->GetHeight();
				if(frameindex==0 )
					pCreature->SetScreenRect( &rect );
				
				if (casketValue==0)
				{
					m_pSurface->BltSprite(&pointTemp, pSprite);					
				}
				else if (casketValue==64)
				{
					CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_SIMPLE_OUTLINE );
					
					m_pSurface->BltSpriteEffect(&pointTemp, pSprite);
				}
				else
				{
					CSpriteSurface::s_Value1 = casketValue;
					
					CSpriteSurface::SetEffect( CSpriteSurface::EFFECT_WIPE_OUT );
					
					m_pSurface->BltSpriteEffect(&pointTemp, pSprite);
				}
			}
		}
	}
}

void	
MTopView::DrawSelectedVampireCreature( POINT* pPoint, MCreature* pCreature, int action, int direction, int frame, int body, int frameindex )
{
	//------------------------------------------------
	// �� �������
	//------------------------------------------------
	int casketValue = pCreature->GetCasketCount();
	bool bInCasket = pCreature->IsInCasket();
	bool bCasketOnly = (bInCasket && casketValue==0);
	
	if (!bCasketOnly)
	{
		FRAME_ARRAY& FA = m_CreatureFPK[body][action][direction];
		
		if (FA.GetSize() > frame)
		{			
			CFrame&	Frame = FA[frame];
			
			int sprite = Frame.GetSpriteID(),	//m_CreatureFPK[body][action][direction][frame].GetSpriteID(),
				cx		= Frame.GetCX(),	//m_CreatureFPK[body][action][direction][frame].GetCX(),
				cy		= Frame.GetCY();	//m_CreatureFPK[body][action][direction][frame].GetCY();
			
			CIndexSprite* pSprite = &m_CreatureSPK[ sprite ];
			
			//					if (pSprite->IsNotInit())
			//					{
			//						LoadFromFileCreatureActionSPK( body, action );
			//					}
			
			// ��ǥ ����
			pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
			pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();			
			
			//---------------------------------------- 		
			// ĳ���� ���� �簢�� ���� ����
			//---------------------------------------- 	
			rect.left	= pointTemp.x;
			rect.top	= pointTemp.y;
			rect.right	= rect.left + pSprite->GetWidth();
			rect.bottom = rect.top + pSprite->GetHeight();
			if(frameindex ==0 )
				pCreature->SetScreenRect( &rect );
			
			WORD colorSet = pCreature->GetAttachEffectColor();
			
			if( pCreature->GetCreatureType() == CREATURETYPE_BAT && pCreature->GetBatColor() != 0xFFFF)
				colorSet = pCreature->GetBatColor();
			
			//---------------------------------------- 
			// ĳ���� ��ü ������ �ٲ�� ���
			//---------------------------------------- 
			if (colorSet < MAX_COLORSET)
			{
				m_SOM.Add( pointTemp.x, pointTemp.y, pSprite, colorSet );
			}					
			//---------------------------------------- 
			// �������� ���
			//---------------------------------------- 										
			else
			{					
				int colorSet1 = pCreature->GetBodyColor1();
				int colorSet2 = pCreature->GetBodyColor2();
				
				if ( colorSet1 == UNIQUE_ITEM_COLOR || colorSet1 == QUEST_ITEM_COLOR )
					colorSet1 = MItem::GetSpecialColorItemColorset( colorSet1 );
				if ( colorSet2 == UNIQUE_ITEM_COLOR || colorSet2 == QUEST_ITEM_COLOR )
					colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
				
				CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
				
				m_SOM.Add( pointTemp.x, pointTemp.y, pSprite );
			}
			
			
			int shadowCount = pCreature->GetShadowCount();
			
			//----------------------------------------
			// Shadow���
			//----------------------------------------
			if (shadowCount)
			{
				// 0, 1, 2, 3, 4, 5
				const int darkbits[6] =
				{
					0, 1, 1, 2, 2, 3
				};
				
				POINT pointTemp2;
				
				// �̵��̸� ��ǥ�� �ٲ��
				int cxStep = 0, cyStep = 0, cxInc =0 , cyInc = 0;
				if (action==ACTION_MOVE)
				{
					cxInc = -pCreature->GetCX();
					cyInc = -pCreature->GetCY();
				}
				
				
				int faNum = FA.GetSize();
				for (int f=1; f<=shadowCount; f++)
				{
					int frame_f = frame-f;
					
					//---------------------------------------- 
					// f frame ��
					//---------------------------------------- 
					if (frame_f < 0)
					{
						frame_f += faNum;
					}
					
					CFrame &Frame_f = FA[frame_f];
					int sprite_f	= Frame_f.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
					
					CIndexSprite* pSprite_f = &m_CreatureSPK[ sprite_f ];
					
					//							if (pSprite_f->IsNotInit())
					//							{	
					//								LoadFromFileCreatureActionSPK(body, action);
					//							}
					
					int cx_f		= Frame_f.GetCX();
					int cy_f		= Frame_f.GetCY();
					
					pointTemp2.x = pPoint->x + cx_f + cxStep;
					pointTemp2.y = pPoint->y + cy_f + cyStep;
					cxStep += cxInc;
					cyStep += cyInc;
					
					m_pSurface->BltIndexSpriteDarkness(&pointTemp2, pSprite_f, darkbits[f]);																
				}
			}	// shadowcount			
		}
	}

	//----------------------------------------------------
	// �� ���
	//----------------------------------------------------
	if (bInCasket)
	{
		// �׸��� ������ *2�Ѵ�.
		int casketID = SPRITEID_CASKET_1 + pCreature->GetCasketType()*2;
		
		if (casketID < m_EtcSPK.GetSize())
		{
			CSprite* pSprite = &m_EtcSPK[casketID];
			
			if (pSprite!=NULL)
			{
				// tile�� �߽ɿ��� �����.
				pointTemp.x = pPoint->x + TILE_X_HALF - (pSprite->GetWidth()>>1);
				pointTemp.y = pPoint->y + TILE_Y - pSprite->GetHeight();
				
				//---------------------------------------- 
				// ĳ���� ���� �簢�� ���� ����
				//---------------------------------------- 	
				rect.left	= pointTemp.x;
				rect.top	= pointTemp.y;
				rect.right	= rect.left + pSprite->GetWidth();
				rect.bottom = rect.top + pSprite->GetHeight();
				if(frameindex ==0 )
					pCreature->SetScreenRect( &rect );
				
				//---------------------------------------- 	
				// ������ �� ���
				//---------------------------------------- 	
				m_SOM.Add( pointTemp.x, pointTemp.y, pSprite );						
			}
		}
	}
}

void	MTopView::DrawSelectedAdvancementVampireCreature( POINT* pPoint, MCreature* pCreature, int action, int direction, int frame, int body, int frameindex )
{
		//------------------------------------------------
	// �� �������
	//------------------------------------------------
	int casketValue = pCreature->GetCasketCount();
	bool bInCasket = pCreature->IsInCasket();
	bool bCasketOnly = (bInCasket && casketValue==0);

	action = GetAdvancementVampireActionFromVampireAction( action, pCreature );

	if( action == -1 )
		return;
	else
		action -= ADVANCEMENT_ACTION_START;

	CCreatureFramePack& advanceVampireFPK = pCreature->IsMale() ? m_AdvancementVampireManFPK : m_AdvancementVampireWomanFPK;
	CIndexSpritePack& advanceVampireSPK = pCreature->IsMale() ? m_AdvancementVampireManSPK : m_AdvancementVampireWomanSPK;	
	
	if (!bCasketOnly)
	{	
		for( int i = body; i <= body+1; ++i )
		{
			// 0:body 1: ���� ��Ż�� ���� ���߿� ���� 
			FRAME_ARRAY& FA = advanceVampireFPK[i][action][direction];
			
			if (FA.GetSize() > frame)
			{			
				CFrame&	Frame = FA[frame];
				
				int sprite = Frame.GetSpriteID(),	//m_CreatureFPK[body][action][direction][frame].GetSpriteID(),
					cx		= Frame.GetCX(),	//m_CreatureFPK[body][action][direction][frame].GetCX(),
					cy		= Frame.GetCY();	//m_CreatureFPK[body][action][direction][frame].GetCY();
				
				CIndexSprite* pSprite = &advanceVampireSPK[ sprite ];
				
				//					if (pSprite->IsNotInit())
				//					{
				//						LoadFromFileCreatureActionSPK( body, action );
				//					}
				
				// ��ǥ ����
				pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
				pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();			
				
				//---------------------------------------- 		
				// ĳ���� ���� �簢�� ���� ����
				//---------------------------------------- 	
				rect.left	= pointTemp.x;
				rect.top	= pointTemp.y;
				rect.right	= rect.left + pSprite->GetWidth();
				rect.bottom = rect.top + pSprite->GetHeight();
				if(frameindex ==0 && i == body)
					pCreature->SetScreenRect( &rect );
				
				WORD colorSet = pCreature->GetAttachEffectColor();
				
				if( pCreature->GetCreatureType() == CREATURETYPE_BAT && pCreature->GetBatColor() != 0xFFFF)
					colorSet = pCreature->GetBatColor();
				
				//---------------------------------------- 
				// ĳ���� ��ü ������ �ٲ�� ���
				//---------------------------------------- 
				if (colorSet < MAX_COLORSET)
				{
					m_SOM.Add( pointTemp.x, pointTemp.y, pSprite, colorSet );
				}					
				//---------------------------------------- 
				// �������� ���
				//---------------------------------------- 										
				else
				{					
					int colorSet1 = pCreature->GetBodyColor1();
					int colorSet2 = pCreature->GetBodyColor2();
					
					if ( colorSet1 == UNIQUE_ITEM_COLOR || colorSet1 == QUEST_ITEM_COLOR )
						colorSet1 = MItem::GetSpecialColorItemColorset( colorSet1 );
					if ( colorSet2 == UNIQUE_ITEM_COLOR || colorSet2 == QUEST_ITEM_COLOR )
						colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
					
					CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
					
					m_SOM.Add( pointTemp.x, pointTemp.y, pSprite );
				}
				
				
				int shadowCount = pCreature->GetShadowCount();
				
				//----------------------------------------
				// Shadow���
				//----------------------------------------
				if (shadowCount)
				{
					// 0, 1, 2, 3, 4, 5
					const int darkbits[6] =
					{
						0, 1, 1, 2, 2, 3
					};
					
					POINT pointTemp2;
					
					// �̵��̸� ��ǥ�� �ٲ��
					int cxStep = 0, cyStep = 0, cxInc =0 , cyInc = 0;
					if (action==ACTION_MOVE)
					{
						cxInc = -pCreature->GetCX();
						cyInc = -pCreature->GetCY();
					}
					
					
					int faNum = FA.GetSize();
					for (int f=1; f<=shadowCount; f++)
					{
						int frame_f = frame-f;
						
						//---------------------------------------- 
						// f frame ��
						//---------------------------------------- 
						if (frame_f < 0)
						{
							frame_f += faNum;
						}
						
						CFrame &Frame_f = FA[frame_f];
						int sprite_f	= Frame_f.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
						
						CIndexSprite* pSprite_f = &advanceVampireSPK[ sprite_f ];
						
						//							if (pSprite_f->IsNotInit())
						//							{	
						//								LoadFromFileCreatureActionSPK(body, action);
						//							}
						
						int cx_f		= Frame_f.GetCX();
						int cy_f		= Frame_f.GetCY();
						
						pointTemp2.x = pPoint->x + cx_f + cxStep;
						pointTemp2.y = pPoint->y + cy_f + cyStep;
						cxStep += cxInc;
						cyStep += cyInc;
						
						m_pSurface->BltIndexSpriteDarkness(&pointTemp2, pSprite_f, darkbits[f]);																
					}
				}	// shadowcount			
			}
		}
	}

	//----------------------------------------------------
	// �� ���
	//----------------------------------------------------
	if (bInCasket)
	{
		// �׸��� ������ *2�Ѵ�.
		int casketID = SPRITEID_CASKET_1 + pCreature->GetCasketType()*2;
		
		if (casketID < m_EtcSPK.GetSize())
		{
			CSprite* pSprite = &m_EtcSPK[casketID];
			
			if (pSprite!=NULL)
			{
				// tile�� �߽ɿ��� �����.
				pointTemp.x = pPoint->x + TILE_X_HALF - (pSprite->GetWidth()>>1);
				pointTemp.y = pPoint->y + TILE_Y - pSprite->GetHeight();
				
				//---------------------------------------- 
				// ĳ���� ���� �簢�� ���� ����
				//---------------------------------------- 	
				rect.left	= pointTemp.x;
				rect.top	= pointTemp.y;
				rect.right	= rect.left + pSprite->GetWidth();
				rect.bottom = rect.top + pSprite->GetHeight();
				if(frameindex ==0 )
					pCreature->SetScreenRect( &rect );
				
				//---------------------------------------- 	
				// ������ �� ���
				//---------------------------------------- 	
				m_SOM.Add( pointTemp.x, pointTemp.y, pSprite );						
			}
		}
	}
}

void	MTopView::DrawSelectedAdvancementSlayerCreature( POINT* pPoint, MCreature* pCreature, int action, int direction, int frame )
{
	action = ConvAdvancementSlayerActionFromSlayerAction( action, dynamic_cast< MCreatureWear* >(pCreature) );

	if( action == -1 )
		return;
	else
		action -= ADVANCEMENT_ACTION_START;

	MCreatureWear*	pCreatureWear = (MCreatureWear*)pCreature;
	// Creature�� Action�� �´� add-on�� ����Ѵ�.
	//action = pCreature->GetAction();	
	int clothes;
	BYTE clothesType;

	CCreatureFramePack& slayerFPK = pCreature->IsMale() ? m_AdvancementSlayerManFPK : m_AdvancementSlayerWomanFPK;
	CIndexSpritePack& addonISPK = pCreature->IsMale() ? m_AdvancementSlayerManSPK : m_AdvancementSlayerWomanSPK;
	
	for (int i=0; i<AC_ADDON_MAX; i++)
	{
		// Creature�� ���� ���⿡ ����...
		// ���� ������ִ� ������ �ٸ� �� �ִ�.
		clothesType = MCreatureWear::s_ACAddonOrder[ direction ][ i ];
		
		// i��° ������ ���� �԰� �ִٸ� ����� �ش�.
		const MCreatureWear::ADDON_INFO& addonInfo = pCreatureWear->GetACAddonInfo( clothesType );
		
		if (addonInfo.bAddon || i == AC_ADDON_BODY )
		{
			// ������ ��Ʈ �״�θ� ����Ѵ�. ���Ŀ� ���� �߰� �Ǿ����� ���� ������ ���� �ؼ� ����.
			// addonInfo.FrameID �� �� ������ �ְ� �����Ͽ� ����ȴ�.

			clothes = GetAdvancementPartFromItemClass( addonInfo.ItemClass , addonInfo.FrameID);

			if( clothes == -1 )
				continue;
			
			FRAME_ARRAY &FA = slayerFPK[clothes][action][direction];
			
			// �ִ� ������ ���
			if (FA.GetSize() > frame)
			{
				CFrame &Frame = FA[frame];					
				int sprite	= Frame.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
				int cx		= Frame.GetCX();	//m_AddonFPK[clothes][action][direction][frame].GetCX();
				int cy		= Frame.GetCY();	//m_AddonFPK[clothes][action][direction][frame].GetCY();
				
				pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
				pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
				
				CIndexSprite* pSprite = &addonISPK[ sprite ];
				
				// ����Sprite�� �ʱ�ȭ ���� ���� ���
				//						if (pSprite->IsNotInit())
				//						{
				//							LoadFromFileAddonSPK( clothes, action );
				//							//continue;
				//						}
				
				//---------------------------------------- 
				// ĳ���� ���� �簢�� ���� ����
				//---------------------------------------- 	
				rect.left	= pointTemp.x;
				rect.top	= pointTemp.y;
				rect.right	= rect.left + pSprite->GetWidth();
				rect.bottom = rect.top + pSprite->GetHeight();
				pCreature->AddScreenRect( &rect );
				
				// SpriteOutlineManager�� �߰�
				//CIndexSprite::SetUsingColorSet((pCreature->GetID()+3*(clothesType,1),7)%MAX_COLORSET, ((pCreature->GetID()*pCreature->GetID(),7*(clothesType+2)))%MAX_COLORSET);
				//CIndexSprite::SetUsingColorSet((c1+3*(clothesType+1)+7)%MAX_COLORSET, ((c2*c2+7*(clothesType+2)))%MAX_COLORSET);
				//---------------------------------------- 
				// ĳ���� �κ� ������ �ٲ�� ���
				//---------------------------------------- 
				if (addonInfo.bEffectColor)	//colorSet < MAX_COLORSET)
				{
					m_SOM.Add( pointTemp.x, pointTemp.y, pSprite, addonInfo.EffectColorSet );
				}
				//---------------------------------------- 
				// ���������..
				//---------------------------------------- 
				else
				{
					int colorSet1 = addonInfo.ColorSet1, colorSet2 = addonInfo.ColorSet2;
					if(colorSet2 == UNIQUE_ITEM_COLOR || colorSet2 == QUEST_ITEM_COLOR)
					{
						if(colorSet2 == QUEST_ITEM_COLOR || colorSet2 == UNIQUE_ITEM_COLOR )
							colorSet2 = MItem::GetSpecialColorItemColorset( colorSet2 );
						
						if(addonInfo.ItemClass != ITEM_CLASS_COAT && addonInfo.ItemClass != ITEM_CLASS_TROUSER)
							colorSet1 = colorSet2;
					}							
					
					CIndexSprite::SetUsingColorSet( colorSet1, colorSet2 );
					m_SOM.Add( pointTemp.x, pointTemp.y, pSprite );
				}
			}
		}
	}
}

void	MTopView::DrawSelectedAdvancementOustersCreature( POINT* pPoint, MCreature* pCreature, int action, int direction, int frame )
{
	MCreatureWear *pCreatureWear = (MCreatureWear *)pCreature;
	
	const MCreatureWear::ADDON_INFO& addonInfoChakram = pCreatureWear->GetAddonInfo(ADDON_RIGHTHAND);
	bool bChakram = addonInfoChakram.bAddon && addonInfoChakram.ItemClass == ITEM_CLASS_OUSTERS_CHAKRAM;

	int tempAction = ConvAdvancementOustersActionFromOusterAction( action, bChakram );

	if( tempAction == -1 )
		return;
	else
		tempAction -= ADVANCEMENT_ACTION_START;

	const MCreatureWear::ADDON_INFO& addonInfo = pCreatureWear->GetAddonInfo(ADDON_COAT);
	const MCreatureWear::ADDON_INFO& bootsAddonInfo = pCreatureWear->GetAddonInfo(ADDON_TROUSER);
	
	if (addonInfo.bAddon && !pCreatureWear->IsGhost(1))
	{
		int clothes = 1;		
		
		FRAME_ARRAY &FA = m_AdvancementOustersFPK[clothes][tempAction][direction];
		
		// �ִ� ������ ���
		if (FA.GetSize() > frame)
		{
			CFrame &Frame = FA[frame];					
			int sprite	= Frame.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
			int cx		= Frame.GetCX();	//m_AddonFPK[clothes][action][direction][frame].GetCX();
			int cy		= Frame.GetCY();	//m_AddonFPK[clothes][action][direction][frame].GetCY();
			
			CIndexSprite* pSprite = &m_AdvancementOustersSPK[ sprite ];					
			
			pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
			pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
			
			//---------------------------------------- 
			// ĳ���� ���� �簢�� ���� ����
			//---------------------------------------- 	
			rect.left	= pointTemp.x;
			rect.top	= pointTemp.y;
			rect.right	= rect.left + pSprite->GetWidth();
			rect.bottom = rect.top + pSprite->GetHeight();
			pCreature->AddScreenRect( &rect );
			
			//---------------------------------------- 
			// ĳ���� �κ� ������ �ٲ�� ���
			//---------------------------------------- 
			if (addonInfo.bEffectColor)	//colorSet < MAX_COLORSET)
			{
				m_SOM.Add( pointTemp.x, pointTemp.y, pSprite, addonInfo.EffectColorSet );
			}
			//---------------------------------------- 
			// �������� ĳ���� ���
			//---------------------------------------- 
			else
			{
				CIndexSprite::SetUsingColorSetOnly( 0, pCreature->GetBodyColor1() );	// �Ӹ���
				
				int coatColor = addonInfo.ColorSet2, Colorset;
				if( coatColor == QUEST_ITEM_COLOR || coatColor == UNIQUE_ITEM_COLOR )
					coatColor = MItem::GetSpecialColorItemColorset( coatColor );						
				CIndexSprite::SetUsingColorSetOnly( 1, coatColor );	// �ʻ�
				if(bChakram == false)	// ����Ʋ���� ���� ������
				{
					if(addonInfoChakram.bAddon)
					{
						Colorset = addonInfoChakram.ColorSet2;
						if( Colorset == QUEST_ITEM_COLOR || Colorset == UNIQUE_ITEM_COLOR )
							Colorset = MItem::GetSpecialColorItemColorset( Colorset );
						CIndexSprite::SetUsingColorSetOnly( 2, Colorset );	// ��								
					}
					else
					{
						Colorset = defaultCoatColor;								
						if( Colorset == QUEST_ITEM_COLOR || Colorset == UNIQUE_ITEM_COLOR )
							Colorset = MItem::GetSpecialColorItemColorset( Colorset );
						
						CIndexSprite::SetUsingColorSetOnly( 2, Colorset );	// ��
					}
				}
				else
				{
					Colorset = defaultCoatColor;
					if(addonInfoChakram.bAddon)
						Colorset = addonInfoChakram.ColorSet2;
					if( Colorset == QUEST_ITEM_COLOR || Colorset == UNIQUE_ITEM_COLOR )
						Colorset = MItem::GetSpecialColorItemColorset( Colorset );
					CIndexSprite::SetUsingColorSetOnly( 2, Colorset );	// ��
				}
				
				if(bootsAddonInfo.bAddon)
				{
					Colorset = bootsAddonInfo.ColorSet2;
					if( Colorset == QUEST_ITEM_COLOR || Colorset == UNIQUE_ITEM_COLOR )
						Colorset = MItem::GetSpecialColorItemColorset( Colorset );
					CIndexSprite::SetUsingColorSetOnly( 3, Colorset );	// ������
				}
				else
				{
					Colorset = defaultCoatColor;
					
					if( Colorset == QUEST_ITEM_COLOR || Colorset == UNIQUE_ITEM_COLOR )
						Colorset = MItem::GetSpecialColorItemColorset( Colorset );
					CIndexSprite::SetUsingColorSetOnly( 3, Colorset );	// ��
				}
				
				m_SOM.Add( pointTemp.x, pointTemp.y, pSprite );
			}						
			
		}
	}
	
	if (bChakram && !pCreatureWear->IsGhost(2))
	{
		int clothes = 0;
		
		FRAME_ARRAY &FA = m_AdvancementOustersFPK[clothes][tempAction][direction];
		
		// �ִ� ������ ���
		if (FA.GetSize() > frame)
		{
			CFrame &Frame = FA[frame];					
			int sprite	= Frame.GetSpriteID();	//m_AddonFPK[clothes][action][direction][frame].GetSpriteID();
			int cx		= Frame.GetCX();	//m_AddonFPK[clothes][action][direction][frame].GetCX();
			int cy		= Frame.GetCY();	//m_AddonFPK[clothes][action][direction][frame].GetCY();
			
			CIndexSprite* pSprite = &m_AdvancementOustersSPK[ sprite ];					
			
			pointTemp.x = pPoint->x + cx;// + pCreature->GetSX();
			pointTemp.y = pPoint->y + cy;// + pCreature->GetSY();
			
			//---------------------------------------- 
			// ĳ���� �κ� ������ �ٲ�� ���
			//---------------------------------------- 
			if (addonInfoChakram.bEffectColor)	//colorSet < MAX_COLORSET)
			{
				m_SOM.Add( pointTemp.x, pointTemp.y, pSprite, addonInfo.EffectColorSet );
			}
			//---------------------------------------- 
			// �������� ĳ���� ���
			//---------------------------------------- 
			else
			{
				int colorset1, colorset2;
				
				colorset1 = addonInfoChakram.ColorSet1;
				colorset2 = addonInfoChakram.ColorSet2;
				if( colorset1 == QUEST_ITEM_COLOR || colorset1 == UNIQUE_ITEM_COLOR )
					colorset1 = MItem::GetSpecialColorItemColorset( colorset1 );
				if( colorset2 == QUEST_ITEM_COLOR || colorset2 == UNIQUE_ITEM_COLOR )
					colorset2 = MItem::GetSpecialColorItemColorset( colorset2 );
				
				
				CIndexSprite::SetUsingColorSet(colorset1, colorset2);
				m_SOM.Add( pointTemp.x, pointTemp.y, pSprite );
			}						
			
		}
	}
}

/*
int	MTopView::GetAdvancementComboFrame(MCreature* pCreature,int &Frame , int &action , int &ComboActionCnt, int &MaxFrame)
{
	int	 frame = Frame	;
	int  iStartFrame	= 0	 ;
	int	 iCancelAction	= 0  ;
	WORD fAttect_Cancel_Type = 0 ; 
	WORD fWeaponType	= 0 ; 
	WORD fWeaponSpeed	= 0 ;
	WORD fCreatureType	= 0 ; 	
	BYTE byCurrenCombo	= 0 ;
	
	
	if(pCreature->IsSlayer())  // �����̾� 
	{
		if( ((action >= ACTION_SLAYER_SWORD) && (action <= ACTION_SLAYER_BLADE)) ||
			((action >= ACTION_SLAYER_SWORD_2) && (action <= ACTION_SLAYER_BLADE_2)) ||
			((action >= ACTION_SLAYER_SWORD_SLOW) && (action <= ACTION_SLAYER_BLADE_2_FAST)) ||
			((action >= ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_SWARD_SLOW) && (action <= ACTION_ADVANCEMENT_SLAYERN_COMBO_CANCEL_SWARD_FAST))
		)
		{
			//WORD fWeaponType = 3 ;  //(*g_pActionInfoTable)[action].GetWeaponType();
			
			// Į 
			if( (action == ACTION_SLAYER_SWORD) || (action == ACTION_SLAYER_SWORD_2) ||
				(action == ACTION_SLAYER_SWORD_SLOW) || (action == ACTION_SLAYER_SWORD_2_SLOW) ||
				(action == ACTION_SLAYER_SWORD_FAST) || (action == ACTION_SLAYER_SWORD_2_FAST) ||
				((action >= ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_SWARD_SLOW) && (action <= ACTION_ADVANCEMENT_SLAYERN_COMBO_CANCEL_SWARD_FAST)) 
			)
			{	
				//if(!(fWeaponType == FLAG_ACTIONINFO_WEAPON_SWORD || fWeaponType == FLAG_ACTIONINFO_WEAPON_BLADE))
				//	return frame;
				fWeaponType = 0 ; // Į 
				//if(fWeaponType == FLAG_ACTIONINFO_WEAPON_BLADE) fWeaponType = 3 ; // ��
			}
			// �� 
			else  // action >= ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_SWARD_SLOW) && (action <= ACTION_ADVANCEMENT_SLAYERN_COMBO_CANCEL_SWARD_FAST))
			{
				//fWeaponType = 0 ; // Į
				
				fWeaponType = 3 ; // ��
			}

			//fWeaponType = 0 ; // Į 
			//fWeaponSpeed = 1 ; 

			/*if(action == ACTION_SLAYER_SWORD_SLOW   || action == ACTION_SLAYER_BLADE_SLOW || 
               action == ACTION_SLAYER_SWORD_2_SLOW || action == ACTION_SLAYER_BLADE_2_SLOW ||   
			   action == ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_SWARD_SLOW || action == ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_BLADE_SLOW)   
				fWeaponSpeed = 0 ; 
			else if(action == ACTION_SLAYER_SWORD_FAST   || action == ACTION_SLAYER_BLADE_FAST || 
               action == ACTION_SLAYER_SWORD_2_FAST || action == ACTION_SLAYER_BLADE_2_FAST ||   
			   action == ACTION_ADVANCEMENT_SLAYERN_COMBO_CANCEL_SWARD_FAST || action == ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_BLADE_SLOW)   
				fWeaponSpeed = 2 ; 
			*/
			/*fWeaponSpeed = pCreature->GetWeaponSpeed() ;

			fCreatureType = 0  ;
			if(pCreature->IsMale()) 	fCreatureType = 1 ;

			if(fWeaponType == 3)	fCreatureType += 2 ; 
		
			
			//fCreatureType = 0 ; // �����̾� 
			
			if(!(action >= ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_SWARD_SLOW) && (action <= ACTION_ADVANCEMENT_SLAYERN_COMBO_CANCEL_SWARD_FAST))
			{
				fAttect_Cancel_Type = 1 ;
				if(ComboActionCnt >= 1 && ComboActionCnt <= 3)
				{
					iCancelAction = AdvanceComboNextActionTable[fWeaponSpeed + fWeaponType] ;
				}
			}
			else
			{
				fAttect_Cancel_Type = 2 ;
			}
		}
	}
	else if(pCreature->IsVampire()) // �����̾� 
	{
		if( (action == ACTION_ATTACK) ||
			((action >= ACTION_VAMPIRE_ATTACK_SLOW) && (action <= ACTION_VAMPIRE_SKILL_ATTACK_FAST)) ||
			((action >= ACTION_ADVANCEMENT_COMBO_CANCEL_SLOW) && (action <= ACTION_ADVANCEMENT_COMBO_CANCEL_FAST))
		)
		{
			fCreatureType = 5 ;
			if(pCreature->IsMale()) 	fCreatureType = 4 ;
			

			fWeaponSpeed = pCreature->GetWeaponSpeed() ;
			
			
			if(!(action >= ACTION_ADVANCEMENT_COMBO_CANCEL_SLOW) && (action <= ACTION_ADVANCEMENT_COMBO_CANCEL_FAST))
			{
				fAttect_Cancel_Type = 1 ;
				if(ComboActionCnt >= 1 && ComboActionCnt <= 3)
				{
					iCancelAction = AdvanceComboNextActionTable[ 6 + fWeaponSpeed + fWeaponType] ;
				}
			}
			else
			{
				fAttect_Cancel_Type = 2 ;
			}
		}
	}
	
	else if(pCreature->IsOusters()) // �ƿ콺�� 
	{
		if( (action == ACTION_ATTACK) ||
			(action == ACTION_OUSTERS_CHAKRAM) || 
			((action >= ACTION_OUSTERS_ATTACK_SLOW) && (action <= ACTION_OUSTERS_CHAKRAM_FAST)) ||
			((action >= ACTION_ADVANCEMENT_OUSTERS_COMBO_CANCEL_SLOW) && (action <= ACTION_ADVANCEMENT_OUSTERS_COMBO_CANCEL_FAST))
		)
		{
			fWeaponSpeed = pCreature->GetWeaponSpeed() ;
			fCreatureType = 6 ; // �ƿ콺�� 
			
			if(!(action >= ACTION_ADVANCEMENT_OUSTERS_COMBO_CANCEL_SLOW) && (action <= ACTION_ADVANCEMENT_OUSTERS_COMBO_CANCEL_FAST))
			{
				fAttect_Cancel_Type = 1 ;
				if(ComboActionCnt >= 1 && ComboActionCnt <= 3)
				{
					iCancelAction = AdvanceComboNextActionTable[ 9 + fWeaponSpeed + fWeaponType] ;
				}
			}
			else
			{
				fAttect_Cancel_Type = 2 ;
			}
		}
	}
	
	if(fAttect_Cancel_Type == 1)  // Attack ���� 
	{	
		if(ComboActionCnt < 1 || ComboActionCnt >4) return frame ; 

		if(ComboActionCnt < 4)
		{
			if(pCreature  == g_pPlayer)
			{
				if(g_pPlayer->IsRepeatAction())
					pCreature->SetActionCountMax(AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][ComboActionCnt - 1] + 2)  ; 
				else
				pCreature->SetActionCountMax(AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][ComboActionCnt - 1])  ; 
			}
		}

		//AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][3] = (MaxFrame - 1) ;
		frame = Frame % (AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][ComboActionCnt - 1] + 1)  ;
		
		//======================================================================================================
		// ���� �޺��� �������� 
		//======================================================================================================
		if(frame <= AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][0])
			byCurrenCombo = 1 ; 
		else if(frame <= AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][1] )
			byCurrenCombo = 2 ; 
		else if(frame <= AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][2] )
			byCurrenCombo = 3 ; 
		else
			byCurrenCombo = 4 ; 
		//======================================================================================================
		
		// ũ���İ� �׾����� �� Ÿ�� ����Ʈ ó��  Sjheon 2005.07.14 Add
		MCreature* TargetCreature = NULL;
		TargetCreature = g_pZone->GetCreature(pCreature->GetTraceID());
		
		if(TargetCreature)
		{
			if(TargetCreature->IsDead())	// ���� �޺� �����  ������ �� �޺� �������� �ٲ۴� 
			{
				ComboActionCnt	= byCurrenCombo ; 
			}
			else
			{
				//int originalSkill = g_pPlayer->GetUsedActionInfo() ; 
				if(byCurrenCombo && (frame >= (AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][byCurrenCombo - 1] - 2)))
				{
					int iCurAction = pCreature->GetCurrentCombo() ; 
					if(iCurAction != byCurrenCombo)
					{
						pCreature->UseSkill_Effect() ; 
						pCreature->SetCurrentCombo(byCurrenCombo);
					}
				}
			}
		}
		// ũ���İ� �׾����� �� Ÿ�� ����Ʈ ó��  Sjheon 2005.07.14 End 

		if(frame == AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][ComboActionCnt - 1] )
		{  
			if(ComboActionCnt != 4)
			{
				pCreature->SetAction(iCancelAction) ;  //  + iComboType) ;	
			}
			pCreature->SetCurrentCombo(0)	;
			//bSendAction[0] = bSendAction[1] = bSendAction[2] = bSendAction[3] = false  ; 
		}
	}
	
	else if(fAttect_Cancel_Type == 2 && ComboActionCnt != 4) // ��� ���� 
	{
		if(ComboActionCnt < 1 || ComboActionCnt >4) return frame ; 
		if(ComboActionCnt != 1)  iStartFrame = AdvanceComboCancelFrameTable[fCreatureType][fWeaponSpeed][ComboActionCnt - 2] +1 ;  
		frame = iStartFrame + Frame % (AdvanceComboCancelFrameTable[fCreatureType][fWeaponSpeed][ComboActionCnt - 1] + 1)  ;
		//pCreature->SetFrame(frame) ; 
		
		/*if(frame == (AdvanceComboCancelFrameTable[fCreatureType][fWeaponSpeed][ComboActionCnt - 1] - 1)  && !pCreature->GetComCencel())
		{
			pCreature->SetAction(pCreature->GetAction()) ;
			pCreature->SetComboCencel(TRUE) ;
			//Sleep(280) ;

		}
		else if(frame == (AdvanceComboCancelFrameTable[fCreatureType][fWeaponSpeed][ComboActionCnt - 1] - 1)  && !pCreature->GetComCencel1())
		{
			pCreature->SetAction(pCreature->GetAction()) ;
			pCreature->SetComboCencel1(TRUE) ;
			//Sleep(280) ;

		}

		else*//*	if(frame == AdvanceComboCancelFrameTable[fCreatureType][fWeaponSpeed][ComboActionCnt - 1])
		{	
			if(pCreature  == g_pPlayer)
			{
				if(g_pPlayer->IsRepeatAction())
				{
					pCreature->SetAction(AdvanceComboNextRepeatActionTable[fWeaponSpeed + fWeaponType]) ; //ACTION_STAND)	;
					//pCreature->SetCurrentCombo(ComboActionCnt)	;	// ���� Step�� �ʱ�ȭ ��
					pCreature->SetCurrentCombo(1)	;	// ���� Step�� �ʱ�ȭ ��
					//pCreature->SetCombo(0);
					//OutputDebugString("asdfsdf����\n") ; 
				}
				else
				{
					pCreature->SetActionCountMax(AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][ComboActionCnt - 1])  ; 
					pCreature->SetAction(ACTION_STAND)	;
					pCreature->SetCurrentCombo(0)	;	// ���� Step�� �ʱ�ȭ ��
				}	
			}
			else
			{
				pCreature->SetAction(ACTION_STAND)	;
				pCreature->SetCurrentCombo(0)	;	// ���� Step�� �ʱ�ȭ ��
			}
			//pCreature->SetCurrentCombo(0)	;	// ���� Step�� �ʱ�ȭ ��
			pCreature->SetCombo(0);
			//pCreature->SetComboCencel(FALSE) ;
			//pCreature->SetComboCencel1(FALSE) ;


			//pCreature->id
			//OutputDebugString("sdafasf"); 
			//pCreature->SetAction(ACTION_SLAYER_SWORD) ; //ACTION_STAND)	;
			//pCreature->SetCurrentCombo(1)	;	// ���� Step�� �ʱ�ȭ �Ѵ�.
			//if(pCreature == g_pPlayer)
			//{
			//	g_pPlayer->SetComboSkillSend(TRUE) ;
			//}
			
		}
		
	}
	return  frame;
}*/

/*
int	MTopView::GetAdvancementComboFrame(MCreature* pCreature,int &Frame , int &action , int &ComboActionCnt, int &MaxFrame)
{
	int	 frame = Frame	;
	int  iStartFrame	= 0	 ;
	int	 iCancelAction	= 0  ;
	WORD fAttect_Cancel_Type = 0 ; 
	WORD fWeaponType	= 0 ; 
	WORD fWeaponSpeed	= 0 ;
	WORD fCreatureType	= 0 ; 	
	BYTE byCurrenCombo	= 0 ;
	

	int iAdvanceAction = 0 ; 
	
//	if(ComboActionCnt < 4) return frame  ; 
	
//	if(ComboActionCnt >= 0) return frame  ; 

	if(pCreature->IsSlayer())  // �����̾� 
	{
		if(action >= ACTION_ADVANCEMENT_SLAYER_COMBO_SWARD_SLOW)
			iAdvanceAction = action ; 
		else 	
			iAdvanceAction = AdvancementSlayerActionConvTable[action];
		
		if(iAdvanceAction >= ACTION_ADVANCEMENT_SLAYER_COMBO_SWARD_SLOW)
		{
			int iComboIdx = iAdvanceAction - ACTION_ADVANCEMENT_SLAYER_COMBO_SWARD_SLOW ;
			iComboIdx = iComboIdx / 3 ; 
			if(iComboIdx == 0 || iComboIdx == 2)
			   fWeaponType = 0 ; // Į 	
			else if(iComboIdx == 1 || iComboIdx == 3)
			   fWeaponType = 3 ; // ��
			
			fWeaponSpeed = pCreature->GetWeaponSpeed() ;

			fCreatureType = 0  ;
			if(pCreature->IsMale()) 	fCreatureType = 1 ;

			if(fWeaponType == 3)	fCreatureType += 2 ; 
		
			
			//fCreatureType = 0 ; // �����̾� 
			
			if(!(iAdvanceAction >= ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_SWARD_SLOW) && (iAdvanceAction <= ACTION_ADVANCEMENT_SLAYER_COMBO_CANCEL_BLADE_FAST))
			{
				fAttect_Cancel_Type = 1 ;
				if(ComboActionCnt >= 1 && ComboActionCnt <= 3) 
				{
					iCancelAction = AdvanceComboNextActionTable[fWeaponSpeed + fWeaponType] ;
				}
			}
			else
			{
				//fAttect_Cancel_Type = 2 ;
			}
		}
		
	}		
	else if(pCreature->IsVampire()) // �����̾� 
	{	
		if(action >= ACTION_ADVANCEMENT_COMBO_SLOW)
			iAdvanceAction = action ; 
		else 		
			iAdvanceAction = AdvancementVampireActionConvTable[action];
			
		if(iAdvanceAction >= ACTION_ADVANCEMENT_COMBO_SLOW)
		{
			fCreatureType = 5 ;
			if(pCreature->IsMale()) 	fCreatureType = 4 ;
			

			fWeaponSpeed = pCreature->GetWeaponSpeed() ;
			
			
			if(!(iAdvanceAction >= ACTION_ADVANCEMENT_COMBO_CANCEL_SLOW) && (iAdvanceAction <= ACTION_ADVANCEMENT_COMBO_CANCEL_FAST))
			{
				fAttect_Cancel_Type = 1 ;
				if(ComboActionCnt >= 1 && ComboActionCnt <= 3)
				{
					iCancelAction = AdvanceComboNextActionTable[ 6 + fWeaponSpeed + fWeaponType] ;
				}
			}
			else
			{
				//fAttect_Cancel_Type = 2 ;
			}	
		}

	}		
	else if(pCreature->IsOusters()) // �ƿ콺�� 
	{
		if(action >= ACTION_ADVANCEMENT_OUSTERS_COMBO_SLOW)
			iAdvanceAction = action ; 
		else 		
			iAdvanceAction	= AdvancementOustersActionConvTable[ action ]; 
		
		if(iAdvanceAction >= ACTION_ADVANCEMENT_OUSTERS_COMBO_SLOW)
		{
			fWeaponSpeed = pCreature->GetWeaponSpeed() ;
			fCreatureType = 6 ; // �ƿ콺�� 
			
			if(!(iAdvanceAction >= ACTION_ADVANCEMENT_OUSTERS_COMBO_CANCEL_SLOW) && (iAdvanceAction <= ACTION_ADVANCEMENT_OUSTERS_COMBO_CANCEL_FAST))
			{
				fAttect_Cancel_Type = 1 ;
				if(ComboActionCnt >= 1 && ComboActionCnt <= 3)
				{
					iCancelAction = AdvanceComboNextActionTable[ 9 + fWeaponSpeed + fWeaponType] ;
				}
			}
			else
			{
				//fAttect_Cancel_Type = 2 ;
			}
		}
	}
	
	if(fAttect_Cancel_Type == 1)  // Attack ���� 
	{	
		
		
		//else
	///	{
		//if(ComboActionCnt < 1 || ComboActionCnt >4) return frame ; 
		if(ComboActionCnt < 4)
			pCreature->SetActionCountMax(AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][ComboActionCnt - 1]+2)  ; 
		else 
			pCreature->SetActionCountMax(AdvanceComboActionFrameTable[fCreatureType][fWeaponSpeed][3])  ; 
		// ũ���İ� �׾����� �� Ÿ�� ����Ʈ ó��  Sjheon 2005.07.14 Add
	
		//}
		
		MCreature* TargetCreature = NULL;
		TargetCreature = g_pZone->GetCreature(pCreature->GetTraceID());
		if(TargetCreature)
		{
			if(TargetCreature->IsDead())	// ���� �޺� �����  ������ �� �޺� �������� �ٲ۴� 
			{
				//pCreature->SetAction(ACTION_STAND)	;
				pCreature->SetCombo(1);
			}
		}
		
		if(action ==  ACTION_ATTACK  && 	ComboActionCnt == 0)
		{
			pCreature->SetCombo(1);
		}
		else if((action ==  ACTION_SLAYER_BLADE_2 || action == ACTION_SLAYER_BLADE_2_FAST || action == ACTION_SLAYER_SWORD_2_FAST)  && 	ComboActionCnt == 0)
		{
			pCreature->SetCombo(2);
		}
		//else if(action ==  ACTION_ATTACK && 	ComboActionCnt == 0)   
		//{
		//	pCreature->SetCombo(1);
		//}
	}
	return  frame;
}*/
