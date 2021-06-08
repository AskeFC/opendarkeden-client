#ifndef __VS_UI_UIMESSAGE_H__
#define __VS_UI_UIMESSAGE_H__

// message
enum UI_MESSAGE
{
	INVALID_MESSAGE,

	UI_STORAGE_BUY,
	UI_SELECT_STORAGE_SLOT,
	UI_RUNNING_GAMEMENU,
	UI_FINISH_LEVELUP_BUTTON,
	UI_CLICK_BONUS_POINT,
	UI_INFO,

//	UI_MINIMAP_TOGGLE,
	UI_DROP_MONEY,
	UI_EXCHANGE_REQUEST_CANCEL,
	UI_EXCHANGE_ACCEPT,
	UI_EXCHANGE_MONEY,
	UI_WITHDRAW_MONEY,
	UI_ITEM_SELECT_EXCHANGE,	
	UI_DEPOSIT_MONEY,
	UI_CHECK_EXIST_ID,
	UI_RUN_NEWUSER_REGISTRATION,
	UI_INFO_CLOSE,
	UI_GAMEMENU_CONTINUE,
/*
	//
	// PDS
	//
	UI_CHANGE_PCS_CONNECTED_SLOT,		// �̹� ����� �ٸ� ����� click�Ͽ���.
	UI_PLEASE_PCS_CONNECT_ME,			// ����� �ִ� wait room�� click�Ͽ���.
	UI_PCS_CONNECTOR_GRANTED,			// wait room�� �ִ� connector�� ������ �³��Ͽ���.
	UI_QUIT_PCS_ONLINE_MODE,			// PCS online mode���� quit ��ư�� ������.
	UI_END_PCS,								// sending �ϰ� ���� ��, end�� ������.
	UI_SEND_PCS_NUMBER,
	UI_PDS_CLOSED,							// slayer pds�� ������. !���� ������ �����Ѵ�.

	UI_PLEASE_SET_SLAYER_VALUE,		// slayer pds���� gage menu�� �����Ͽ���.
*/
//	UI_LEARN_SLAYER_SKILL,				// skill tree���� ��� �� �ִ� skill�� �����Ͽ���.
//	UI_CLOSE_SKILL_TREE,
//	UI_CLOSE_SKILL_VIEW,

	UI_BACKGROUND_MOUSE_FOCUS,			// Mouse pointer�� UI Window���� �̵����� ���� ��, �� Window�� ����� ��� Client�� ����.
	UI_REMOVE_BACKGROUND_MOUSE_FOCUS,// Game Menu�� ���� topmost Window�� ��µǾ��� ���� background focus�� �����ϴ� ���� ����.

	//
	// ���� Message
	//
	UI_BUY_ITEM,

	UI_SELL_ITEM,
	UI_REPAIR_ITEM,
	UI_SILVERING_ITEM,
	UI_ITEM_SELL_FINISHED,
	UI_ITEM_REPAIR_FINISHED,
	UI_ITEM_SILVERING_FINISHED,

	UI_CLOSE_SHOP,
	UI_CLOSE_STORAGE,
	UI_CLOSE_EXCHANGE,
	UI_CANCEL_EXCHANGE,
	UI_OK_EXCHANGE,

	UI_CHARACTER_MANAGER_FINISHED,	// Characters Window���� �ʱ�ȭ������ �� �� �˷��ش�.
	UI_TERMINATION,						// ����
	UI_LOGIN,								// ����� login ��û
	UI_LOGOUT,								
//	UI_NEW_USER_REGISTRATION,			// �� ����� ��� ��û
	UI_CONNECT,							   // Game connection.
	UI_CHAT_RETURN,						// ä��â �Է�.
//	UI_CHAT_SELECT_NAME,				// ä��â���� ���� �ּ� by larosel
	UI_SELECT_SKILL,						// Skill selection.
	UI_CANCEL_SELECT_SKILL,				// Skill ������ ��ҵǾ���.

	//
	// Item message
	//

	// drop
	UI_ITEM_DROP_TO_CLIENT,				// Item�� �ٴڿ� ����߷ȴ�.
	UI_ITEM_DROP_TO_INVENTORY, 		// Inventory�� ���´�.
	//UI_ITEM_DROP_TO_TRADEGRID,			// ��ȯâ �׸��忡 ���´�.
	UI_ITEM_DROP_TO_GEAR,				// Gear�� ���´�.
	UI_ITEM_DROP_TO_QUICKSLOT,			// Quick Slot�� ���´�.

	// pick up
	// Client���� ���� ���� Client -> UI �̴�.
	//UI_ITEM_PICKUP_FROM_TRADEGRID,
	UI_ITEM_PICKUP_FROM_INVENTORY,
	UI_ITEM_PICKUP_FROM_GEAR,
	UI_ITEM_PICKUP_FROM_QUICKSLOT,

	// insert to other Item
	//UI_ITEM_INSERT_FROM_TRADEGRID,
	UI_ITEM_INSERT_FROM_INVENTORY,
	UI_ITEM_INSERT_FROM_GEAR,
	UI_ITEM_INSERT_FROM_QUICKSLOT,  // ���̴� ��� - ���� �������� -

	// use
	UI_ITEM_USE,							// Inventory���� ���.
	UI_ITEM_USE_QUICKSLOT,				// Quick Item Slot���� ���.

	//
	// Character management
	//
	UI_NEW_CHARACTER,
	UI_DELETE_CHARACTER,

	// etc
	UI_CLOSE_BBS,

	// game option
	UI_CHANGE_OPTION,
	UI_CLOSE_OPTION,

	// title option
//	UI_CHANGE_TITLE_OPTION,
//	UI_CLOSE_TITLE_OPTION,	

	// repleace	
	//UI_CHANGE_ITEM_IN_INVENTORY,	// Inventory���� Item�� ��ü�Ǿ���.
	//UI_REMOVE_ITEM_FROM_GEAR,		// Gear���� Item�� ������.

	//tutorial by larosel
	UI_CLOSE_BOOKCASE,
	UI_CLOSE_BRIEFING,
	UI_CLOSE_COMPUTER,
	//UI_CONFIRM_TUTORIAL_EXIT,		// �ּ� by sigi
	UI_CLOSE_TUTORIAL_EXIT,
	//UI_TUTORIAL_EXIT_ACCEPT,		// �ּ� by sigi
	//UI_TUTORIAL_EXIT_SELECT,		// �ּ� by sigi

	UI_CLOSE_DESC_DIALOG,
	UI_CLOSE_ELEVATOR,
	UI_SELECT_ELEVATOR,

	UI_SELL_ALL_ITEM,	//�ذ� ��� �ȱ�
	
//	UI_USE_SERUM,	// ��û����ϱ�

	UI_ITEM_TO_QUICKITEMSLOT, // focus_grid_x, focus_grid_y, (MItem *)p_item

	UI_CLOSE_SLAYER_PORTAL,//�����̾� ��Ż ���
	UI_SLAYER_PORTAL, //�������� left = zoneid right's hiword = x right's LOWORD = y

	UI_FINISH_REQUEST_PARTY_BUTTON,	// ��Ƽ��û �ݱ� left == TRUE : timeout
	UI_PARTY_REQUEST_CANCEL, 
	UI_PARTY_ACCEPT,

	UI_CLOSE_PARTY_MANAGER,
	UI_AWAY_PARTY, // ��Ƽ Ż�� �߹� left :: -1 : Ż�� 0~4 : �߹�

	UI_FINISH_REQUEST_DIE_BUTTON,	// ����-_-��û �ݱ� left == TRUE : timeout

	UI_CLOSE_TEAM_LIST,
	UI_CLOSE_TEAM_INFO,
	UI_CLOSE_TEAM_MEMBER_INFO,
	UI_CLOSE_TEAM_REGIST,
	UI_CLOSE_TEAM_MEMBER_LIST,
	
	UI_REQUEST_GUILD_INFO,
	UI_REQUEST_GUILD_MEMBER_LIST,
	UI_MODIFY_GUILD_MEMBER,

	UI_SELECT_TEAM_MEMBER_LIST,			// void_ptr = CHAR_NAME
	UI_SELECT_READY_TEAM_LIST,		// void_ptr = TEAM_NAME
	UI_SELECT_REGIST_TEAM_LIST,		// void_ptr = TEAM_NAME

	UI_JOIN_READY_TEAM,				// void_ptr = TEAM_NAME
	UI_JOIN_REGIST_TEAM,			// void_ptr = TEAM_NAME

	UI_REGIST_GUILD_MEMBER,			// void_ptr = introduction max:150byte â �ݾ��ٰ�!
	UI_REGIST_GUILD_TEAM,			// left = TEAM_NAME, void_ptr = introduction max:150byte â �ݾ��ٰ�!

	UI_CLOSE_FILE_DIALOG,			// left = mode, void_ptr = file_name

	UI_CONNECT_SERVER,				// left == true : group false : server right : id
									// request_server_list �Ⱥ����Ƿ� �����ϸ� list�����ٰ�
	UI_CLOSE_SERVER_SELECT,			// left == true : group false : server

	UI_NEWCHARACTER_CHECK,				// void_ptr : name

	UI_ENCHANT_ACCEPT,
	UI_ENCHANT_CANCEL,
	
	UI_MESSAGE_BOX,					// left = �޽��� ����  STRING_MESSAGE_CANNOT_REPAIR

	//UI_OTHER_INFO,					// Other Player Info Box
	UI_CLOSE_OTHER_INFO,			//            //
	UI_MODIFY_TEAM_INFO,			// �Ұ��� ����  left = guild id, ptr = intro
	UI_MODIFY_GUILD_MEMBER_INTRO,	// �� �Ұ� �� ���� left = , ptr = intro

	UI_CLOSE_TRACE_WINDOW,			// TRACE â �ݱ�.
	UI_SEND_NAME_FOR_SOUL_CHAIN,	// TRACE �̸� ������ ptr ��

	// �ݸ���� ����
	UI_RUN_CONNECT,
	UI_SELECT_GRADE_SKILL,			// Grade Skill ����. left = id

	UI_USE_XMAS_TREE,				// left = ItemPointer, void_ptr = message
	UI_CLOSE_XMAS_CARD_WINDOW,
	UI_SEND_BRING_FEE,				// left = money				to client
	UI_CLOSE_BRING_FEE_WINDOW,		// close window

	UI_CLOSE_WAR_LIST_WINDOW,

	UI_CLOSE_BLOOD_BIBLE_STATUS,

	UI_SEND_NAME_FOR_COUPLE,		// left = type(Ŀ�� ��û, ����) void_ptr = name
	UI_CLOSE_INPUT_NAME,
	
	UI_ITEM_USE_GEAR,							// Gear���� ���.	left : focus slot    void_ptr : item_ptr
	UI_GO_BILING_PAGE,						// ������������ ����!

	UI_CLOSE_POPUP_MESSAGE,

	MAX_UI_MESSAGE
};

#endif