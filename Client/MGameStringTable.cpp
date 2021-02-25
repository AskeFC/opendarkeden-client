//----------------------------------------------------------------------
// MGameStringTable.cpp
//----------------------------------------------------------------------
#include "Client_PCH.h"
#include "MGameStringTable.h"


//----------------------------------------------------------------------
// Global
//----------------------------------------------------------------------
MStringArray*		g_pGameStringTable = NULL;
//2004, 6, 18, sobeit add start - about nick name string table
MStringArray*		g_pNickNameStringTable = NULL;
//2004, 6, 18, sobeit add end - about nick name string table


#ifndef __GAME_CLIENT__

void				
InitGameStringTable()
{	
	(*g_pGameStringTable).Init( MAX_GAME_STRING );


	(*g_pGameStringTable)[STRING_NETWORK_CONDITION_BAD] = "ȸ�� ���°� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_RESURRECTION_AFTER_SECONDS] = "%d�� �Ŀ� �ǻ�Ƴ� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_DRAW_ZONE_NAME] = "%s (%d,%d)";
	(*g_pGameStringTable)[STRING_DRAW_GAME_DATE] = "%d/%d/%d";
	(*g_pGameStringTable)[STRING_DRAW_GAME_TIME] = "%02d:%02d:%02d";
	(*g_pGameStringTable)[STRING_DRAW_ITEM_NAME_MONEY] = "%s(%d)";

	(*g_pGameStringTable)[STRING_USER_REGISTER_DENY] = "�� ����� ����� �Ұ����մϴ�.";
	(*g_pGameStringTable)[STRING_USER_REGISTER_HOMEPAGE] = "Ȩ���������� ����� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_USER_REGISTER_EMPTY_FIELD] = "�ʼ��׸��� �Էµ��� �ʾҽ��ϴ�.";
	(*g_pGameStringTable)[STRING_USER_REGISTER_INVALID_ID] = "�߸��� ���̵�(ID)�Դϴ�.";
	(*g_pGameStringTable)[STRING_USER_REGISTER_ID_LENGTH] = "���̵�(ID)�� %d~%d���Դϴ�";
	(*g_pGameStringTable)[STRING_USER_REGISTER_ID_SPECIAL] = "���̵�(ID)���� Ư�����ڸ� ���ּ���.";
	(*g_pGameStringTable)[STRING_USER_REGISTER_PASSWORD_LENGTH] = "�н������ %d~%d���Դϴ�";
	(*g_pGameStringTable)[STRING_USER_REGISTER_PASSWORD_SPECIAL] = "�н����忡�� Ư�����ڸ� ���ּ���.";
	(*g_pGameStringTable)[STRING_USER_REGISTER_PASSWORD_NUMBER] = "�н������ ���ڸ� ����� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_USER_REGISTER_NAME_LENGTH] = "�̸��� %d�ڱ����Դϴ�";
	(*g_pGameStringTable)[STRING_USER_REGISTER_INVALID_SSN] = "�߸��� �ֹε�Ϲ�ȣ�Դϴ�.";
	(*g_pGameStringTable)[STRING_USER_REGISTER_SSN_FORMAT] = "�ֹε�Ϲ�ȣ ���� : 123456-1234567";

	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_BUY_NO_SPACE] = "�� �ڸ��� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_BUY_NO_MONEY] = "���� �����մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_BUY_NO_ITEM] = "�������� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_SELL] = "�� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_REPAIR] = "������ �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_SILVERING] = "������ �� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_BUY_MORE] = "�� �̻� �� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_STORAGE] = "�����Կ� ������ �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_STORAGE_BUY] = "�������� ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NO_STORAGE] = "�������� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_TRADE_REJECTED] = "�ŷ��� �źεǾ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_TRADE_NOBODY] = "�ŷ��� ����� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_TRADE_CANNOT_ON_MOTORCYCLE] = "������̸� Ÿ�� �ŷ��� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_TRADE_SAFETY_ZONE_ONLY] = "�������뿡���� �ŷ��� �� �ֽ��ϴ�.";	
	(*g_pGameStringTable)[STRING_MESSAGE_TRADE_BUSY] = "��ȯ�� �� ���� �����Դϴ�.";	
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_TRADE] = "�ŷ��� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_TRADE_ALREADY_TRADING] = "�̹� �ŷ����Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_TRADE_NO_SPACE] = "��ȯ�� ������ �����մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_SKILL_DIFFER_DOMAIN] = "��� �������� �ٸ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_SKILL_EXCEED_LEVEL] = "��� ������ �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_SKILL_CANNOT_LEARN] = "���� ��� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_SKILL_NOT_SUPPORT] = "���� �������� �ʴ� ����Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_FIND_MOTOR_NO_WHERE] = "����ִ��� �𸣰ڱ���.";
	(*g_pGameStringTable)[STRING_MESSAGE_FIND_MOTOR_NO_KEY] = "������� ���谡 ������";
	(*g_pGameStringTable)[STRING_MESSAGE_FIND_MOTOR_OK] = "%s�� (%d, %d)�� �ֱ���.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_USE_BONUS_POINT] = "���ʽ� ����Ʈ�� ����� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_WHAT_SKILL_TO_LEARN] = "%s ����� �߿��� ���� ����� ���ڽ��ϱ�?";
	(*g_pGameStringTable)[STRING_MESSAGE_NO_SKILL_TO_LEARN] = "����� ��� �� �ִ� ����� ������.";
	(*g_pGameStringTable)[STRING_MESSAGE_NEW_SKILL_AVAILABLE] = "���ο� ����� ��� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NEW_DOMAIN_LEVEL_1] = "%s ������ ������ %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NEW_DOMAIN_LEVEL_2] = "%s ������ ������ %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_MOVE_SAFETY_ZONE_RELIC] = "������ ��� ������ �ڱ����� �������뿡�� �� �� �����ϴ�!";

	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_REGIST_FAIL_ALREADY_JOIN] = "��� �ѹ� ����? �ڳ״� �̹� �ٸ��� �Ҽ��̶�� ���� �ֱ�";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_REGIST_FAIL_QUIT_TIMEOUT] = "�ڳ״� �ٸ� ���� Ż������ �� ���� �ʾұ�. ���� �� �����ϰ� �����ϰ� �ൿ�ϰ�";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_REGIST_FAIL_CANCEL_TIMEOUT] = "�ڳ״� ���� ��� ���� �� �� ���� �ʾұ�. ��� ���ǿ� �����ϵ��� �ڽ��� �� �� �⸣�� ����. �� �� �����ϰ� ��ȸ�� �������� �ϰ�";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_REGIST_FAIL_LEVEL] = "�Ǹ������� �����ν��� ������ �� ������ �� ����. �Ƿ��� �۰� ���Գ�";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_REGIST_FAIL_MONEY] = "���� ������� ���� ���� �ʿ��ϴٳ�. �ڳ״� ���� ���� ���̴±�...";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_REGIST_FAIL_FAME] = "%s�̶�.. �� ���� �׷� �̸��� ������ ���ߴٳ�. �װ� �ڳװ� ǲ������ ���� �ǹ�����. �Ƿ��� �۰� �ٽ� ã�ƿ��Գ�";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_REGIST_FAIL_NAME] = "�� �̸��� �̹� ���̰� �ֱ�, �ٸ� �̸��� ������ ����";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_REGIST_FAIL_DENY] = "���Խ�û�� �źεǾ����ϴ�";

	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_STARTING_FAIL_ALREADY_JOIN] = "����� �̹� �ٸ� ���� ���ԵǾ� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_STARTING_FAIL_QUIT_TIMEOUT] = "�ڳ״� �ٸ� ���� Ż������ �� ���� �ʾұ�. ���� �� �����ϰ� �����ϰ� �ൿ�ϰ�";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_STARTING_FAIL_CANCEL_TIMEOUT] = "�ڳ״� ���� ��� ���� �� �� ���� �ʾұ�. ���ǿ� �����ϵ��� �ڽ��� �� �� �⸣�� ����. �� �� �����ϰ� ��ȸ�� �������� �ϰ�";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_STARTING_FAIL_LEVEL] = "�ڳ״� ���� ������ ���� ���� ���̴±���. ���� �� �Ƿ��� �۰� ã�Գ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_STARTING_FAIL_MONEY] = "%s, �� ����� ���ؼ��� ���� �� �ʿ��ϴٳ�";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_STARTING_FAIL_FAME] = "%s�̶�.. �� ���� �׷� �̸��� ������ ���ߴٳ�. �װ� �ڳװ� ǲ������ ���� �ǹ�����. �Ƿ��� �۰� �ٽ� ã�ƿ��Գ�";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_STARTING_FAIL_DENY] = "���Խ�û�� �źεǾ����ϴ�";

	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_REGIST_FAIL_ALREADY_JOIN] = "��� �ѹ� ����? �ڳ״� �̹� �ٸ�Ŭ���� ������ ���� ���¶�� ���� �ֱ�";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_REGIST_FAIL_QUIT_TIMEOUT] = "�ڳ״� �ٸ� Ŭ���� Ż������ �󸶵��� �ʾұ�. �ʹ� �̸����� �Ű� �ٴϴ� ���� ���� ����. ������ ���ϰ�";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_REGIST_FAIL_CANCEL_TIMEOUT] = "�ڳ״� Ŭ���� ��� ���� �� �� ���� �ʾұ�. �� �� �����ϰ� ��ȸ�� �������� �ϰ�";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_REGIST_FAIL_LEVEL] = "�Ǹ������� ��θӸ��ν��� ������ �� ������ �� ����. �Ƿ��� �۰� ���Գ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_REGIST_FAIL_MONEY] = "Ŭ���� ����Ϸ��� ���� ���� �ʿ��ϴٳ�. �ڳ״� ���� ����̴±�...";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_REGIST_FAIL_FAME] = "%s�̶�.. ���� � �����̾��ΰ�����. �� ���� �Ǹ� ���ð� �ٽ� ã�ƿ��Գ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_REGIST_FAIL_NAME] = "Ŭ�� �̸��� �̹� ���̰� �ֱ�, �ٸ� �̸��� ������ ����";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_REGIST_FAIL_DENY] = "���Խ�û�� �źεǾ����ϴ�";

	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_STARTING_FAIL_ALREADY_JOIN] = "����� �̹� �ٸ� Ŭ���� ���ԵǾ� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_STARTING_FAIL_QUIT_TIMEOUT] = "�ڳ״� �ٸ� Ŭ���� Ż������ �󸶵��� �ʾұ�. �ʹ� �̸����� �Ű� �ٴϴ� ���� ���� ����. ������ ���ϰ�";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_STARTING_FAIL_CANCEL_TIMEOUT] = "�ڳ״� Ŭ���� ��� ���� �� �� ���� �ʾұ�. �� �� �����ϰ� ��ȸ�� �������� �ϰ�";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_STARTING_FAIL_LEVEL] = "�Ǹ��� �����ڰ� �Ǳ⿡�� ������ �� ������ �� ����. ���� ���� ������ �ϰ� ���Գ�";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_STARTING_FAIL_MONEY] = "����� �����ص� Ŭ���� ������ �� �ִ� ���� �����ϸ� �� Ŭ���� �������� ��������";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_STARTING_FAIL_FAME] = "%s�̶�.. �� ���� �׷� �̸��� ������ ���ߴٳ�. �װ� �ڳװ� ǲ������ ���� �ǹ�����. �Ƿ��� �۰� �ٽ� ã�ƿ��Գ�";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_STARTING_FAIL_DENY] = "���Խ�û�� �źεǾ����ϴ�";

	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_REGIST_FAIL_INTRO] = "�Էµ��� ���� �׸��� �ֽ��ϴ�.";

	(*g_pGameStringTable)[STRING_STATUS_HP_MAX_1] = "�����(HP) �ִ�ġ�� %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_STATUS_HP_MAX_2] = "�����(HP) �ִ�ġ�� %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_STATUS_MP_MAX_1] = "������(MP) �ִ�ġ�� %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_STATUS_MP_MAX_2] = "������(MP) �ִ�ġ�� %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_STATUS_STR_1] = "��(STR)�� %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_STATUS_STR_2] = "��(STR)�� %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_STATUS_DEX_1] = "��ø��(DEX)�� %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_STATUS_DEX_2] = "��ø��(DEX)�� %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_STATUS_INT_1] = "����(INT)�� %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_STATUS_INT_2] = "����(INT)�� %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_STATUS_LEVEL] = "%d ����(Level)�� �Ǿ����ϴ�.";

	(*g_pGameStringTable)[STRING_LEARN_SKILL] = "[%s] ����� ������ϴ�.";
	(*g_pGameStringTable)[STRING_CHANGE_ALIGNMENT] = "������ %s���� �ٲ�����ϴ�.";
	(*g_pGameStringTable)[STRING_CHANGE_ALIGNMENT2] = "������ %s�� �ٲ�����ϴ�.";
	(*g_pGameStringTable)[STRING_CHANGE_TO_BAD_ALIGNMENT] = "������ ���������ϴ�.";
	(*g_pGameStringTable)[STRING_CHANGE_TO_GOOD_ALIGNMENT] = "������ ���������ϴ�.";

	(*g_pGameStringTable)[STRING_ERROR_INVALID_ID_PASSWORD] = "���̵�(ID)�� ��ȣ(Password)�� Ʋ�Ƚ��ϴ�."; 
	(*g_pGameStringTable)[STRING_ERROR_ALREADY_CONNECTED] = "�̹� ���� �Ǿ� �ֽ��ϴ�."; 
	(*g_pGameStringTable)[STRING_ERROR_ALREADY_REGISTER_ID] = "�̹� ��ϵ� ���̵�(ID)�Դϴ�."; 
	(*g_pGameStringTable)[STRING_ERROR_ALREADY_REGISTER_SSN] = "�̹� ��ϵ� �ֹε�Ϲ�ȣ�Դϴ�."; 
	(*g_pGameStringTable)[STRING_ERROR_EMPTY_ID] = "���̵�(ID)�� �����ϴ�."; 
	(*g_pGameStringTable)[STRING_ERROR_SMALL_ID_LENGTH] = "���̵�(ID)���̰� ª���ϴ�."; 
	(*g_pGameStringTable)[STRING_ERROR_EMPTY_PASSWORD] = "��ȣ(Password)�� �����ϴ�."; 
	(*g_pGameStringTable)[STRING_ERROR_SMALL_PASSWORD_LENGTH] = "��ȣ(Password) ���̰� ª���ϴ�"; 
	(*g_pGameStringTable)[STRING_ERROR_EMPTY_NAME] = "�̸��� �����ϴ�."; 
	(*g_pGameStringTable)[STRING_ERROR_EMPTY_SSN] = "�ֹε�Ϲ�ȣ�� �����ϴ�."; 
	(*g_pGameStringTable)[STRING_ERROR_INVALID_SSN] = "�ֹε�Ϲ�ȣ�� Ʋ�Ƚ��ϴ�."; 
	(*g_pGameStringTable)[STRING_ERROR_NOT_FOUND_PLAYER] = "�÷��̾ �����ϴ�."; 
	(*g_pGameStringTable)[STRING_ERROR_NOT_FOUND_ID] = "���̵� �����ϴ�."; 
	(*g_pGameStringTable)[STRING_ERROR_LOGIN_DENY] = "�� ������ ���������� �����Դϴ�. ����������(darkeden@darkeden.com)�� �������ּ���.";
	(*g_pGameStringTable)[STRING_ERROR_ETC_ERROR] = "�߸��Ǿ����ϴ�."; 
	(*g_pGameStringTable)[STRING_ERROR_NOT_ALLOW_ACCOUNT] = "�� ������ ���������� �����Դϴ�. ����������(darkeden@darkeden.com)�� �������ּ���.";
	(*g_pGameStringTable)[STRING_ERROR_NOT_PAY_ACCOUNT] = "���Ⱓ�� ����Ǿ����ϴ�. ����������(darkeden@darkeden.com)�� �������ּ���.";

	(*g_pGameStringTable)[STRING_MESSAGE_ITEM_BROKEN] = "�������� �μ������ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_WHISPER_FAILED] = "�ӼӸ��� �������� �ʾҽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_WHISPER_SELF] = "�ڽſ��Դ� �ӼӸ��� �� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CHAT_IGNORE] = "%s�԰��� ��ȭ�� �ź��մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CHAT_ACCEPT] = "%s�԰��� ��ȭ�� ����մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CHAT_IGNORE_ALL] = "��ȭ�� ��� �ź��մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CHAT_ACCEPT_ALL] = "��ȭ�� ��� ����մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CHAT_BE_GOOD] = "�ٸ��� ��� ���� ����սô�. :)";
	(*g_pGameStringTable)[STRING_MESSAGE_CHAT_ACCEPT_CURSE] = "��� ���� �״�� �� ����մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CHAT_FILTER_CURSE] = "���� ���� ���� �����ϰ� ����մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_LOGOUT_DIED] = "���� ���¿����� �α׾ƿ�(Logout)�� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_GLOBAL_SAY] = "������ ��ġ�⸦ �� �� �����ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_WAIT] = "��� ��ٷ� �ּ���.";
	(*g_pGameStringTable)[STRING_MESSAGE_CONNECTING_SERVER] = "������ �����ϴ� ���Դϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_DONATION_OK] = "����߽��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_DONATION_FAIL] = "��� �� �� �����ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_PARTY_REJECTED] = "�ʴ밡 �źεǾ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PARTY_NOBODY] = "�ʴ��� ����� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PARTY_SAFETY_ZONE_ONLY] = "�������뿡���� �� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PARTY_BUSY] = "�ʴ븦 �� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_RACE_DIFFER] = "������ �ٸ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NOT_NORMAL_FORM] = "���� ���¿����� �� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NO_AUTHORITY] = "��Ƽ ������ �� �ð��� �����ߵ˴ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_ERROR_PARTY] = "��Ƽ�� �� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_KICK_PARTY_MEMBER_OK] = "%s ���� ��Ƽ���� �߹��߽��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_KICKED_FROM_PARTY] = "%s �Կ��� �߹���߽��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_KICK_PARTY_MEMBER] = "%s ���� %s ���� ��Ƽ���� �߹��߽��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_REMOVE_PARTY] = "��Ƽ�� ��ü�Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_REMOVE_PARTY_HIMSELF] = "%s ���� ��Ƽ���� �������ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_REMOVE_PARTY_MYSELF] = "��Ƽ���� �������ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_IN_ANOTHER_PARTY] = "�̹� �ٸ� ��Ƽ�� ���� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PARTY_FULL] = "��Ƽ �ο��� �� á���ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_SOMEONE_JOINED_PARTY] = "%s ���� ��Ƽ�� ���Խ��ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_LOGOUT_AFTER_SECOND] = "%d�� �Ŀ� �α׾ƿ� �˴ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_BUY_NO_STAR] = "���� �����մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_BUY] = "�� �� �����ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_CAN_REGISTER_NAME] = "����Ͻ� �� �ֽ��ϴ�.";

	// 2002.3.20 �߰�
	(*g_pGameStringTable)[STRING_MESSAGE_HELP_KEY] = "������ CTRL+H�Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_HOW_TO_GET_BASIC_WEAPON] = "������ɺ��� ��ũ���Լ� �⺻ ���⸦ ���� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_WAIT_FOR_CHARACTER_SELECT_MODE] = "   ĳ���� ����â���� ���� ���Դϴ�.     ��� ��ٷ��ּ���.";	

	(*g_pGameStringTable)[STRING_MESSAGE_ITEM_TO_ITEM_IMPOSIBLE] = "��æƮ(Enchant)�� �� �����ϴ�.";	

	// UI �߰�	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_ENCHANT]= "��æƮ(Enchant) �� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ONLY_PICK_UP_ITEM_ONE]= "�� ���� ��� �ϼž� �մϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_SELL_CONFIRM] = "�� �������� �Ľðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ALL_SELL_CONFIRM] = "�Ľðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ALL_PRICE]= "��� $%s �Դϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REPAIR_CONFIRM] = "��ġ�ðڽ��ϱ�?";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLICK_TRADE_ITEM] = "�ŷ��� �������� Ŭ���ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLICK_REPAIR_ITEM] = "��ĥ �������� Ŭ���ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLICK_OK_BUTTON_TO_END] = "�����÷��� Ȯ�� ��ư�� Ŭ���ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLICK_SILVERING_ITEM] = "������ �� �������� Ŭ���ϼ���.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_THIS_ITEM_REPAIR_CONFIRM] = "�� �������� ��ĥ���?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_THIS_ITEM_CHARGE_CONFIRM] = "�� �������� ���� �ұ��?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_THIS_ITEM_SILVERING_CONFIRM] = "�� �������� ������ �ұ��?";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_ALPHA_WINDOW] ="â�� ���������� ����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_NO_ALPHA_WINDOW] = "â�� ���������� ������� �ʽ��ϴ�";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_EQUIP] = "���� �� �� �ֽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_EQUIP] = "���� �� �� �����ϴ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_THROW_MONEY] = "���� �����ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_ITEM_DESCRIPTION] = "������ ������ ���ϴ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_DEPOSIT_MONEY] = "���� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INVITE_PARTY] =	"��Ƽ ������û �޼����� ���� �ֽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUEST_PARTY] = "��Ƽ ���Խ�û �޼����� ���� �ֽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RESURRECTION] = "���� ��ġ���� ��Ȱ�Ѵ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EVACUATION]	= "���� ��ġ�� �ļ۵ȴ�";		
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_UP_LEVEL] = "���̻� �������� ���� �ʽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_UP_STAT]= "���̻� �ɷ�ġ�� �ö��� �ʽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_JOIN] = "�����մϴ�";
	
	
	// UI_TIP
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TIP_SELL_ALL_VAMPIRE_HEAD]="�� : �����̾��� �Ӹ����� �Ѳ����� �ȷ��� ������ Ŭ���� �ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TIP_REPAIR_ALL_ITEM] = "�� : ������ �Ѳ����� ��ġ���� ������ Ŭ���� �ϼ���.";

	// UI ����â Description	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_AUTO_HIDE_ON] = "�ڵ����� ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_AUTO_HIDE_OFF] = "�ڵ����� ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GAME_MENU] = "���Ӹ޴�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MENU] = "�޴�(Menu)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EXP] = "����ġ(Exp)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM] = "��(Team)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MESSAGE] = "�޼���(Message)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HELP] = "����(Help)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INVENTORY] = "������â(Inventory)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GEAR_WINDOW] = "����â(Gear Window)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INFO_WINDOW] = "����â(Info Window)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PARTY_WINDOW] = "��Ƽâ(Party Window)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_WINDOW] = "����Ʈ(Quest Window)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO] = "�� ����(Team Info)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_MEMBER_LIST] = "���� ����Ʈ(Team Member List)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BASIC_HELP] = "�⺻ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHATTING_HELP] = "ä�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_WAR_HELP] = "���� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SKILL_HELP] = "��� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_HELP] = "�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLAN] = "Ŭ��(Clan)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLAN_INFO] = "Ŭ�� ����(Clan Info)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLAN_MEMBER_LIST] = "Ŭ���� ����Ʈ(Clan Member List)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLAN_HELP] = "Ŭ�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MAGIC_HELP] = "���� ����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CURRENT_EXP] = "���� ����ġ : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NEXT_LEVEL] =  "����   ���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_LEFT_EXP] = "���� ����ġ : ";	

	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_HELM] = "���ڸ� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_NECKLACE] = "����̸� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_ARMOR] = "������ �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_SHIELD] = "���и� �����մϴ�";	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_WEAPON] = "���⸦ �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_GLOVE] = "�尩�� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_BELT]	= "��Ʈ�� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_TROUSER] = "������ �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_BRACELET]	= "��� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_RING]	= "������ �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_SHOES] = "�Ź��� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_VAMPIRE_COAT] = "���� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_EARRING] = "�Ͱ��̸� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_AMULET] =	"�ƹķ��� �����մϴ�";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FIRST_GEAR_SET] = "ù��° �����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SECOND_GEAR_SET] = "�ι�° �����";

	// ä��
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SPECIAL_CHARACTER] = "Ư������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SET_LETTER_COLOR] = "�۾�������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHANGE_INPUT_LANGUAGE] ="��/�� ��ȯ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_WHISPER_ID] ="�ӼӸ� �ߴ� ���̵� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NORMAL_CHATING]	= "�Ϲ�ä�� �ϱ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ZONE_CHATTING]	= "��ä�� �ϱ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_WHISPER_CHATTING] =	"�ӼӸ� �ϱ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PARTY_CHATTING]	= "��Ƽä�� �ϱ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_CHATTING] = "��ä�� �ϱ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_NORMAL_CHATTING] = "�Ϲ�ä�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_ZONE_CHATTING]	= 	"��ä�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_WHISPER_CHATTING] = "�ӼӸ� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_PARTY_CHATTING] = "��Ƽä�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_TEAM_CHATTING]	= "��ä�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_SHOW_NORMAL_CHATTING] = "�Ϲ�ä�� �Ⱥ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_SHOW_ZONE_CHATTING]	= "��ä�� �Ⱥ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_SHOW_WHISPER_CHATTING] = "�ӼӸ� �Ⱥ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_SHOW_PARTY_CHATTING] = "��Ƽä�� �Ⱥ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_SHOW_TEAM_CHATTING]	= "��ä�� �Ⱥ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_SHOW_CLAN_CHATTING]	= "Ŭ��ä�� �Ⱥ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_CLAN_CHATTING]	= "Ŭ��ä�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLAN_CHATTING] = "Ŭ��ä�� �ϱ�";

	// Party Window
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EXPEL] = "Ż��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SECEDE] = "�߹�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SET_INVITE_DENY_MODE] = "��û �źθ�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANCEL_INVITE_DENY_MODE] = "��û �źθ�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SET_JOIN_DENY_MODE] = "���� �źθ�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANCEL_JOIN_DENY_MODE] = "���� �źθ�� ����";
		
	// Level Up
	(*g_pGameStringTable)[UI_STRING_MESSAGE_UP_STR] = "���� �ø��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_UP_DEX]	= "��ø���� �ø��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_UP_INT]	= "������ �ø��ϴ�";

	// INFO WINDOW
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_BLADE_INFO] = "���迭�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_SWORD_INFO] = "�˰迭�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_GUN_INFO] = "�Ѱ迭�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_HEAL_INFO] = "ȸ���迭�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_ENCHANT_INFO] = "�ູ�迭�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_ALL_INFO] = "��ü�迭�� ������ ���ϴ�";	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_POISON_INFO] =	"���迭�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_ACID_INFO]	= "��迭�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_CURSE_INFO] = "���ְ迭�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_SUMMON_INFO] = "��ȯ�迭�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_BLOOD_INFO] = "���迭�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_ESSENCE_INFO] = "�����迭�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_SKILL_INFO_WINDOW]	= "��ų ����â�� ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_CHARACTER_INFO_WINDOW]	= "ĳ���� ����â�� ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_MAGIC_INFO_WINDOW]	= "���� ����â�� ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_ADVANTE_INFO_WINODW] = "���� ����â�� ���ϴ�";
	
	// SHOW HELP WINDOW
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_HELP_INVENTORY_WINDOW] = "�κ��丮(Inventory)â�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_HELP_GEAR_WINDOW] = "����(Gear)â�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_HELP_CHARACTER_INFO_WINDOW]= "ĳ���� ����â�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_HELP_MAGIC_INFO_WINDOW]= "���� ����â�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_HELP_SKILL_INFO_WINDOW]= "��ų ����â�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_HELP_PARTY_MANAGER] = "��Ƽ(PartyManager)â�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_HELP_SHOP_WINDOW] ="����(Shop)â�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_HELP_STORAGE_WINDOW]="������(Storage)â�� ������ ���ϴ�";
	
	// Close Window
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_MAGIC_INFO_WINDOW] = "���� ����â�� �ݽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_SKILL_INFO_WINDOW] = "��ų ����â�� �ݽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_PARTY_MANAGER] = "��Ƽ(PartyManager)â�� �ݽ��ϴ�";	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_CHARACTER_INFO_WINDOW] = "ĳ���� ����â�� �ݽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_INVENTORY_WINDOW] = "�κ��丮(Inventory)â�� �ݽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_GEAR_WINDOW] = "����(Gear) â�� �ݽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_DESC_WINDOW] ="����â�� �ݽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_WINDOW]="â�� �ݽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_SHOP_WINDOW] ="����(Shop)â�� �ݽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_STORAGE_WINDOW]="������(Storage)â�� �ݽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_BOOKCASE]= "å���� �ݽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_BOOK] = "å�� �ݽ��ϴ�";
	
	// ��Ÿ
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_JOIN_ANY_TEAM] ="��ϵ� �� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_JOIN_ANY_CLAN] ="��ϵ� Ŭ�� ����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_INFRA_RED_HELMET]="�����󷹵� ��ĳ�� ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INFRA_HELMET]="������ ��ĳ�� ���";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUIT_COMPUTER] ="��ǻ�͸� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_NEXT_PAGE]="���� �������� ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_PREV_PAGE] = "���� �������� ���ϴ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_STR] = "STR ";						// STR
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DEX] = "DEX ";						// DEX
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_INT] = "INT ";				// INT

	(*g_pGameStringTable)[UI_STRING_MESSAGE_MASTER_NAME] = "GM";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_LIMIT_STRING_COUNT] = "�������� ������!!!";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HELP_MESSAGE] = "����";	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_STR]= "��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DEX]= "��ø��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INT]= "����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HP]	= "�����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MP] = "������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCURACY] = "���߷�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DAMAGE]	= "������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_AVOID]	= "ȸ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DEFENCE]= "�����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ALIGNMENT] = "����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_ALIGN_VERY_BAD]="�ſ� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ALIGN_BAD] ="����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ALIGN_NORMAL] ="�߸�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ALIGN_GOOD]	 ="����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ALIGN_VERY_GOOD] ="�ſ� ����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_STR_PURE] =	"��   ��   �� : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DEX_PURE] =	"����  ��ø�� : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INT_PURE] =	"�� ��  �� �� : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_STATUS_SUM_PURE] =	"�����ɷ�ġ�� : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_STATUS_SUM]	="�� �� ġ  �� : %d";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_SPEED_SLOW] ="����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SPEED_NORMAL] =	"����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SPEED_FAST]	="����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ATTACK_SPEED] =	"���ݼӵ� : %s[%d]";

	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PASSIVE]= "Passive";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HAN_PASSIVE] ="�нú�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_LEVEL_DESCRIPTION] ="���� :%d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_EXP_DESCRIPTION] ="����ġ(EXP):%s/%s (���� ����ġ:%s)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_MP_DESCRIPTION] =	"������(MP):%d/%d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_HP_DESCRIPTION_WITH_SILVERING] = "�����(HP):%d/%d(S:%d)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_HP_DESCRIPTION] =	"�����(HP):%d/%d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_CHANGE_VAMPIRE_DAY] =	"%d�� %d�ð� %d�� �Ŀ� �����̾�� ���մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_CHANGE_VAMPIRE_HOUR] ="%d�ð� %d�� �Ŀ� �����̾�� ���մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_CHANGE_VAMPIRE_MINUTE] ="%d�� �Ŀ� �����̾�� ���մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_CHANGE_VAMPIRE_SOON]	="�� �����̾�� ���մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_SET_LARGE] ="�����(HP) â�� ���η� ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_SET_SMALL] ="�����(HP) â�� �۰� ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_SET_WIDTH] ="�����(HP) â�� ���η� ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_SET_HEIGHT] = "�����(HP) â�� ũ�� ���ϴ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_WIDTH] ="���η� ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_HEIGHT] ="���η� ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_HELP]=	"������ ���ϴ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_REGIST]	="����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_LIST_UP]="�����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_LIST_DOWN]	="�Ʒ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REFRESH_LIST]="����� �ٽ� �޾ƿɴϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SORT_TEAM_NAME]	="���̸����� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SORT_LEADER_NAME]	="�����̸����� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SORT_EXPIRE_DATE]="�����Ϸ� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SORT_NUMBER_MEMBER]="������� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SORT_RANKING]="������ �����մϴ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHANGE_FIND_MODE]="�˻� ��� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FIND]="�˻��ϱ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_GRADE_MASTER]="������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_GRADE_SUB_MASTER]="���� ������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_GRADE_WAIT]="��� �����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_GRADE_MEMBER]="ȸ��";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_GRADE] = "���(Grade) : %s";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_NAME] = "�̸�(Name) : %s";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_LEADER] = "����(Leader) : %s";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_REG_FEE] = "���Ժ�(Reg. Fee) : $%s";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_MEMBERS] = "ȸ��(Members) : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_INTRODUCTION] = "�Ұ�(Introduction) : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_CLAN_INTRODUCTION] = "Ŭ�� �Ұ�(Clan Introduction) : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_TEAM_INTRODUCTION] = "�� �Ұ�(Team Introduction) : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_RANKING]="����(Ranking) : %d";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_TEAM_NAME] = "�� �̸�(Team Name) : %s";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_CLAN_NAME] = "Ŭ�� �̸�(Clan Name) : %s";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_REGISTRATION_FEE] = "���Ժ�(Registration Fee) : $%s";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_SELF_INTRODUCTION]= "�ڱ� �Ұ�(Self Introduction) : ";


	(*g_pGameStringTable)[UI_STRING_MESSAGE_UP] = "����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DOWN] = "�Ʒ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_EXPEL] = "�߹��մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_JOIN_ACCEPT]="�����㰡";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_JOIN_DENY] = "���԰ź�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANCEL]="���";

	
	// Zone Name

	(*g_pGameStringTable)[UI_STRING_MESSAGE_LIMBOLAIR]="������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ESLANIA]="������Ͼ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RODIN]=	"�ε��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DROBETA]="��κ�Ÿ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PERONA]="��γ�����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TIMORE]="Ƽ�� ȣ��";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_ZONEINFO_XY] = "X:%d Y:%d";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_ESLANIA_NE]	="������Ͼ� NE"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_ESLANIA_NW]	="������Ͼ� NW"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_ESLANIA_SE]	="������Ͼ� SE"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_ESLANIA_SW]	="������Ͼ� SW";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_LIMBOLAIR_NE]="������ NE"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_LIMBOLAIR_NW]="������ NW"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_LIMBOLAIR_SE]="������ SE"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_LIMBOLAIR_SW]="������ SW";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_DROBETA_NE]	="��κ�Ÿ NE"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_DROBETA_NW]	="��κ�Ÿ NW"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_DROBETA_SE]	="��κ�Ÿ SE"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_DROBETA_SW]	="��κ�Ÿ SW";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_RODIN_NE]="�ε�� NE"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_RODIN_NW]="�ε�� NW"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_RODIN_SE]="�ε�� SE"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_RODIN_SW]="�ε�� SW";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_TIMORE_NE]="Ƽ�� ȣ�� NE"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_TIMORE_NW]="Ƽ�� ȣ�� NW"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_TIMORE_SE]="Ƽ�� ȣ�� SE"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_TIMORE_SW]="Ƽ�� ȣ�� SW";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_PERONA_NE]="��γ� NE"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_PERONA_NW]="��γ� NW"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_PERONA_SE]="��γ� SE"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_PERONA_SW]="��γ� SW";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_UNDERGROUND_WATERWAY]="���� ����"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_ESLANIA_DUNGEON]="������Ͼ� ����"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_IN_LIMBOLAIR]="������ ����";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_LIMBOLAIR_DEONGEON]	="������ ����"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_EVENTOX]="�̺�Ʈ OX"; 		
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_EVENT_STADIUM]	="�̺�Ʈ �����"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_IN_RASENCASTLE]	="�󼾼� ����"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_KALI_CAVE]	="Į�� ����"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_RASEN_TRAINING]	="�� ���̳���"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_PEIAC_TUNNEL]="���̾� �ͳ�";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_BATHORY_B1]	="���丮 ���� B1"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_BATHORY_B2]	="���丮 ���� B2"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_BATHORY_B3]	="���丮 ���� B3"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_BATHORY_B4]	="���丮 ���� B4"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_BATHORY_LAIR]	="���丮 ����"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GHORGOBA_TUNNEL]="����� �ͳ�";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_RASEN_YARD]	="�� �ܼ� 1F"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_CASTLE_RASEN_1F]="�� ���� 1F"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_CASTLE_RASEN_2F]="�� ���� 2F"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEPES_LAIR]	="������ ����";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_SLAYER_BATTLEZONE1]="��� ����";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_SLAYER_BATTLEZONE2]="�׸޸��� ����"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_BATHORY_BATTLEZONE]	="����� ����"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_RASEN_BATTLEZONE]="���̼� ����";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_ARMY_B1]="���� ��� B1"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_ARMY_1F]="���� ��� 1F"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_ARMY_2F]="���� ��� 2F"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_ARMY_3F]="���� ��� 3F"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_ARMY_4F]="���� ��� ����";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_CELRIC_B1]="������ ��� B1"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_CELRIC_1F]="������ ��� 1F"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_CELRIC_2F]="������ ��� 2F"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_CELRIC_3F]="������ ��� 3F"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_CELRIC_4F]="������ ��� ����";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_KNIGHT_B1]="���� ��� B1";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_KNIGHT_1F]="���� ��� 1F";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_KNIGHT_2F]="���� ��� 2F";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_KNIGHT_3F]="���� ��� 3F"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_KNIGHT_4F]="���� ��� ����";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_TUTORIAL_N]	="������ɺ�"; 
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_TUTORIAL_S]	="�� �ܰ�����";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_HOUSE]="��� ����Ʈ";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLAN_HOUSE]	="Ŭ�� ����Ʈ";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_LOST_TAIYAN_B1]	="�ν�Ʈ Ÿ�̾� B1";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_LOST_TAIYAN_B2]	="�ν�Ʈ Ÿ�̾� B2";	
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_ASYLION_DUNGEON]="�ƽǸ��� ����";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_TAKE_HELICOPTER]="��� ž��";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_TAKE_ELIVATOR]=	"����������";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_UNKNOW]	= "�� �� ����";

	// Accelerator Name
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_NULL]	="AcceleratorNULL";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_F1]	="F1";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_F2]	="F2";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_F3]	="F3";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_F4]	="F4";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_F5]	="F5";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_F6]	="F6";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_F7]	="F7";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_F8]	="F8";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_F9]	="F9";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_F10]="F10";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_F11]="F11";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_F12]="F12";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_ESC]="ESC";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_SKILL]="SKILL";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_INVENTORY]=	"INVENTORY";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_GEAR]="GEAR";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_CHARINFO]="CHARINFO";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_SKILLINFO]=	"SKILLINFO";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_MINIMAP]="MINIMAP";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_PARTY]="PARTY";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_MARK]="MARK";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_HELP]="HELP";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_QUICKITEM_SLOT]="QUICKITEM_SLOT";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_EXTEND_CHAT]="EXTEND_CHAT";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_CHAR]="CHAT";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_GUILD_CHAT]="GUILD_CHAT";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_ZONE_CHAT]=	"ZONE_CHAT";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_WHISPER]="WHISPER";

	// Item Class Name
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_CLASS_SWORD]="��(SWORD)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_CLASS_BLADE]="��(BLADE)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_CLASS_CROSS]="���ڰ�(CROSS)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_CLASS_MACE]="���̽�(MACE)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_CLASS_MINE]="����(MINE)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_CLASS_BOMB]="��ź(BOMB)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_CLASS_MINE_MATERIAL]="���� ���(MINE MATERIAL)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_CLASS_BOMB_MATERIAL]=	"��ź ���(BOMB MATERIAL)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_CLASS_SG]=	"��ź��(SG)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_CLASS_SMG]="�ڵ�����(SMG)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_CLASS_AR]=	"����(AR)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_CLASS_SR]="������(SR)";
	
	// Description Dialog
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_CLASS]="�迭 : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DURABILITY]="������ : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_SILVERING]="������ : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DAMAGE]="������ : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_CRITICALHIT]="ũ��Ƽ�� ��Ʈ : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DEFENSE]	="ȸ���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_PROTECTION]="����� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_ACCURACY]="���߷� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_HP]="�����(HP) : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_MP]="������(MP) : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_RANGE]	="�����Ÿ� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_MAGAZINE_NUM]	="źȯ�� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_POCKET_NUM]	="�ָӴ� ���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_ITEM_NUM]	="������ ���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_LEFT_NUM]	="���� ���ȸ�� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_ARRIVAL_LOCATION]	="������ġ : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_NOT_EXIST]	="����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_NUMBER] = "��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_MAGAZINE_COUNT]= "��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_TILE_PIECE] = "ĭ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_PARTY_NAME] = "��Ƽ";		
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_OPTION] ="�ɼ� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_REQUIRE] = "�䱸���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_REQUIRE_STAT] = "%d �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_ONLY_MALE] = "������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_ONLY_FEMALE] = "������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_ONLY_SLAYER] = "�����̾� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_ONLY_VAMPIRE] = "�����̾� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_ALL_STAT_SUM] = "�ɷ�ġ ���� ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_LEVEL]="���� ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_PRICE] = "���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_SILVERING_PRICE] ="������ ���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_CHARGE_PRICE] = "�������� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_REPAIR_PRICE] = "�������� : ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CONSUME_HP]	= "�����(HP)�Ҹ� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CONSUME_MP] = "������(MP)�Ҹ� : ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_LEVEL] = "�䱸 ���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_EXP]="����ġ : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_LIMIT_LEVEL]="�������ѷ��� : ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_CANNOT_LEARN_SKILL]= "\"���� ��� �� �����ϴ�.\"";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_CAN_LEARN_SKILL] ="\"��� �� �ֽ��ϴ�.\"";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_MOVE] ="�̵��մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANCEL_MOVE] = "�̵��� ����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MOVE_F1] = "1������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MOVE_F2] = "2������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MOVE_F3] = "3������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MOVE_F4] = "4������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MOVE_B1] = "����1������ ���ϴ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_CLICK_EXCHANGE] =	"��ȯ�Ͻ÷��� �����ּ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_CANCEL_OK_BUTTON] = "OK�Ѱ��� ����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_CANCEL_EXCHANGE] = "��ȯ�ϱ�� �� �� ����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_SHOW_EXCHANGE_WINDOW] ="��ȯ(Exchange)â�� ������ ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_BRING_MONEY] =	"��ȯ�ϱ�� �� ���� ��ã���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_EXCHANGE_MONEY] ="���� ��ȯ�մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_EXCHANGE_YOUR_MONEY] ="������ ��ȯ�ϱ�� �� ��";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_LEFT_MONEY_AFTER_EXCHANGE] ="��ȯ�ϰ� ���� ���� �ݾ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_WILL_EXCHANGE_MONEY] = "��ȯ�� �ݾ�";


	(*g_pGameStringTable)[UI_STRING_MESSAGE_TRHOW_MONEY_IN_DIALOG] = "���� �ݾ��� �Է��ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SAVE_MONEY_IN_DIALOG] = "������ �ݾ��� �Է��ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BRING_MONEY_IN_DIALOG] = "ã�� �ݾ��� �Է��ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TRADE_MONEY_IN_DIALOG] = "�ŷ��� �ݾ��� �Է��ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DIVIDE_MONEY_IN_DIALOG] = "���� �ݾ��� �Է��ϼ���.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_BUY_ITEM] ="�� �������� ��ðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BUY_ITEM_NUM] = "�� ������            ���� ��ðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ASK_DIALOG_BUY_STORAGE] = "�������� $%d�� ��ðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ASK_DIALOG_TRADE_OTHER_PLAYER]= "%s �԰� �ŷ��ϰڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ASK_DIALOG_WAIT_OTHER_PLAYER]= "%s ���� ������ ��ٸ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ASK_DIALOG_CANCEL]	="����Ͻ÷��� ��ҹ�ư�� ��������.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ASK_DIALOG_REQUEST_JOIN]= "%s ���� ����� %s�� ������ ��û�ϰ� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ASK_DIALOG_INVITE]= "%s ���� ����� %s�� ��û�ϼ̽��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_FIND_RESULT]= "�˻� ����� ã�� �� �����ϴ�." ;
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENCHANT_CONFIRM]= "�� �������� ��æƮ(Enchant)�Ͻðڽ��ϱ�?";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_ITEM_CLASS_SG] = "\t�迭 : SG";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_ITEM_CLASS_SMG] = "\t�迭 : SMG";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_ITEM_CLASS_AR] = "\t�迭 : AR";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_ITEM_CLASS_SR] = "\t�迭 : SR";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_DURABILITY]="\t������ : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_SILVERING]= "\t������ : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_DAMAGE]= "\t������ : %d~%d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_CRITICALHIT]= "\tũ��Ƽ�� ��Ʈ : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_DEFENSE]= "\tȸ���� : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_PROTECTION]= "\t����� : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_ACCURACY]= "\t���߷� : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_HP]= "\tHP : +%d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_MP]= "\tMP : +%d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_RANGE]= "\t�����Ÿ� : %d ĭ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_MAGAZINE_NUM]= "\tźȯ�� : %d ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_POCKET_NUM]= "\t�ָӴ� ���� : %d ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_OPTION]="\t�ɼ� : %s +%d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_OPTION2]="\t�ɼ� : %s";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_OPTION_EMPTY]="\t       %s +%d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_OPTION_EMPTY2]="\t       %s";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_REQUIRE_EMPTY]= "\t           ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_REQUIRE]="\t�䱸���� : ";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_REQUIRE_STR]= "STR %d �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_REQUIRE_DEX] ="DEX %d �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_REQUIRE_INT]  ="INT %d �̻�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_REQUIRE_ALL_STAT_SUM] = "�ɷ�ġ ���� %d �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_REQUIRE_LEVEL] ="���� %d �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DIALOG_PRICE] = "\t���� : %s";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_FILE_DIALOG_SELECT_PROFILE_PICTURE]="�����ʿ� ���� ������ �����ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FILE_DIALOG_SELECT_FILE]="������ ���ϵ��� �����ϼ���(��������CTRL).";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FILE_DIALOG_SELECT_FILE_OK]="�ش� ������ �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FILE_DIALOG_CANCEL]="����ϰ� â�� �ݽ��ϴ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DOMAIN_BLADE]="BLADE";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DOMAIN_SWORD]="SWORD";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DOMAIN_ENCHANT]="ENCHANT";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DOMAIN_GUN]	="GUN";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DOMAIN_HEAL]="HEAL";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_SUPPORT_MENU]    ="���� �������� �ʴ� �޴��Դϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_INPUT_ID_OR_PASSWORD]    ="���̵�(ID) �Ǵ� ��ȣ(Password)�� �Է����� �ʾҽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_WRONG_SSN]="�ֹε�Ϲ�ȣ�Է��� �ٸ��� �ʽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INPUT_NAME] ="�̸��� �Է��ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_CONNECT_SERVER]    ="������ ������ �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SELECT_CHARACTER] ="ĳ���͸� �����ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DELETE_CHARACTER] ="ĳ���Ͱ� �����Ǿ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ALL_SLOT_EMPTY] ="ĳ���͸� ���� �����, ������� ĳ���͸� �����ϼž� �մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NO_MORE_CREATE_CHARACTER] ="ĳ���͸� �� �̻� ���� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FAIL_CREATE_CHARACTER] ="ĳ���� ������ �����Ͽ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NO_INPUT_NEED_INFO] ="�ʼ��׸��� ��� �Էµ��� �ʾҽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ALREADY_USE_ID] ="������� ���̵�(ID) �Դϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_USE_ID] ="����Ͻ� �� �ִ� ���̵�(ID) �Դϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RE_INPUT_PASSWORD] ="��й�ȣ�� �ٽ� �Է��ϼ���.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_TNDEAD] ="�ʹ׵���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_ARKHAN] ="��ĭ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_ESTROIDER] ="����Ʈ���̴�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_GOLEMER] =	"�񷹸�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_DARKSCREAMER] ="��ũ��ũ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_DEADBODY] ="����ٵ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_MODERAS] =	"�𵥶�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_VANDALIZER] ="���������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_DIRTYSTRIDER] ="��Ƽ��Ʈ���̴�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_HELLWIZARD] ="�����ڵ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_TNSOUL] ="�ʹ׼ҿ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_IRONTEETH] ="���̾�Ƽ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_REDEYE] ="�������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_CRIMSONSLAUGTHER] ="ũ����������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_HELLGUARDIAN] ="�ﰡ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_SOLDIER] =	"����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_RIPPER] ="����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_BIGFANG] =	"����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_LORDCHAOS] ="�ε�ī����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_CHAOSGUARDIAN] ="ī���������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_HOBBLE] ="ȣ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_CHAOSNIGHT] ="ī��������Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_WIDOWS] ="�����콺";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_KID] ="Ű��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_NAME_SHADOWWING] ="��������";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_SERVER_STATUS_VERY_GOOD]="�ſ� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SERVER_STATUS_GOOD]	="����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SERVER_STATUS_NORMAL]="��Ȱ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SERVER_STATUS_BAD]="����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SERVER_STATUS_VERY_BAD]	="Ÿ���� �̿����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SERVER_STATUS_DOWN]	="���� �ٿ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SERVER_STATUS_OPEN]	="����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SERVER_STATUS_CLOSE]="����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_TYPE_NORMAL] ="�Ϲ� ������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_TYPE_SPECIAL] ="Ư�� ������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_TYPE_MISTERIOUS] ="�˼����� ������";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_STORAGE_FIRST]="ù��° ������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_STORAGE_SECOND]="�ι�° ������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_STORAGE_THIRD]="����° ������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_STORAGE_FOURTH]="�׹�° ������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_STORAGE_FIVE]="�ټ���° ������";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_BRING_MONEY_FROM_STORAGE]="���� ã���ϴ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_DELETE]="�����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_CANCEL]="����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_DELETE_CONFIRM]="�� ĳ���͸� ���� �����Ͻðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RE_INPUT_CORRECT_SSN]="�ֹε�Ϲ�ȣ�� ��Ȯ�� �Է��ϼ���.";	

	// ĳ���� ���� ȭ��
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_NAME]="�̸� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_LEVEL]="���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_STR_PURE]="������ : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_DEX_PURE]="������ø�� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_INT_PURE]="�������� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_SWORD_LEVEL]="�� ������ ���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_BLADE_LEVEL]="�� ������ ���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_GUN_LEVEL]="�� ������ ���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_HEAL_LEVEL]="ȸ�� ������ ���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_ENCHANT_LEVEL]="�ູ ������ ���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_FAME]="�� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_CREATEMSG1]="����⸦ �����ø� �� ĳ���͸�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_CREATEMSG2]="����� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_GRADE] = "��� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHAR_MANAGER_GRADE_EXP] = "��� ����ġ : ";

	// Title Version
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLIENT_VERSION]="����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NETMARBLE_CLIENT_VERSION]="�ݸ��� ����";


	// Option Menu
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_3D_ACCEL]="3D ���� ����ϱ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_ALPHA_HPBAR]="������ HP(MP)��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_SHED_BLOOD]="(HP 30% ������ ��) ���긮��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_HIDE_SOFT]=	"â �ڵ����� �ε巴��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_GAME_BRIGHT]="���� ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_CHATTING_TALK]=	"ä�� ��ǳ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_PUT_FPS]="FPS���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_WINDOW_ALPHA]="�⺻â �������ϱ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_DENSITY_ALPHA]=	"������ ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_SOUND_VOLUME]="ȿ���� ũ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_MUSIC_VOLUME]="������� ũ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_SHOW_BASIC_HELP]="�ʺ��ڿ� ���� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_NO_LISTEN_BAD_TALK]="���۸� ���� �ʱ�",
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_LOAD_ALL_IMAGE]	="���̵��� �� ���� �̹��� �ҷ�����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_CHATTING_COLOR_WHITE]="ä�� ��� ������� ����",
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_RUN_TEEN_VERSION]="ƾ�������� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_OPEN_WINDOW_WHEN_WHISPER]="�ӼӸ� ������ ä��â ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_NOT_SEND_MY_INFO]= "�� ĳ���� ���� �����";

	// Grade
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_PIVATE] =	"�Ǻ���Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_SERENT] =	"����Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_FEACEL] =	"�Ǽ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_LITENA] =	"���׳�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_KAINEL] =	"���̳�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_GENEAL] =	"���Ͼ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_FORE_GENEAL] = "���� ���Ͼ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_MAJORIS_GENEAL] =	"���������� ���Ͼ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_CLOEL_GENEAL] = "Ŭ�ο� ���Ͼ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_MARSHAL] = "����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_RITTER]="����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_REICHSRITTER]	="����������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_BARONET]="�ٷγ�Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_PREYHER]="�������츣";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_GRAF]	="�׶���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_MARKGRAF]	="����ũ�׶���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_PFALZGRAF]="�����׶���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_FURST]="Ƕ����Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_HERZOG]="�츣��ũ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_LANDESHER]="�������츣";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_MSG1]= "���� ������ ����Ű�� �Է��ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_MSG2]= "����ϰ� �����ø� ESCŰ�� ��������.";

	// OTHER INFO
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OTHER_INFO_STR_PURE]="������ : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OTHER_INFO_DEX_PURE]="������ø�� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OTHER_INFO_INT_PURE]="��������  : ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_OTHER_INFO_STR_CUR]="������ : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OTHER_INFO_DEX_CUR]="�����ø�� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OTHER_INFO_INT_CUR]="��������  : ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_OTHER_INFO_FAME] = "��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OTHER_INFO_TEAM_NAME] = "�� �̸� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OTHER_INFO_CLAN_NAME] = "Ŭ�� �̸� : ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_TIP_CHANGE_PICTURE_CLICK_HERE] = "������ �ٲ� �� �ֽ��ϴ�";


	(*g_pGameStringTable)[STRING_MESSAGE_UP_TO_GRADE] = "����� �±��߽��ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_NAME] ="��� �̸� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_LEVEL] ="��� ���� : ";
	

	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DOMAIN_BLADE2]="Blade";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DOMAIN_SWORD2]="Sword";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DOMAIN_ENCHANT2]="Enchant";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DOMAIN_GUN2]	="Gun";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DOMAIN_HEAL2]="Heal";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_CLASS2]="�迭";

	(*g_pGameStringTable)[STRING_MESSAGE_ITEM_TO_ITEM_FAIL_NO_PREMIUM_SLAYER] =  "�����̾� ������̾�� �ϰų�, ��峻���� ����� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_ITEM_TO_ITEM_FAIL_NO_PREMIUM_VAMPIRE] = "�����̾� ������̾�� �ϰų�, ���������� ����� �� �����ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_DISMISS_AFTER_SECOND] = "%d�� �Ŀ� �Ѱܳ��ϴ�.";
	
    (*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_ENTER_CHATTING]= "����ä��";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_MENU_NORMAL_CHATTING]="�Ϲ�ä��";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_MODIFY_INFO] = "�Ұ� ���� �����մϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_START_TRACE] = "���� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANCEL_TRACE] ="���� ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TRACE] = "%s ĳ���� ������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_TRACE] = "%s ĳ���� ���� ����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_DO_NOT_WAR_MSG] ="������� �޽��� ���� �ʱ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_DO_NOT_LAIR_MSG] = "������Ͱ��� �޽��� ���� �ʱ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_GRADE1_INFO_WINDOW] = "���� ��� ��ųâ�� ���ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_GRADE2_INFO_WINDOW] = "���� ��� ��ųâ�� ���ϴ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_CRITICAL_10]="ũ��Ƽ��(Critical) ���ݷ� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_DEFENSE_5]="ȸ����(Defense) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_TOHIT_5]="���߷�(To hit) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_HP_10]="�����(HP) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_MP_15]="������(MP) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_DAMAGE_3]="������(Damage) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_ATTACKSPEED_15]="���ݼӵ� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_HP_20]="�����(HP) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_DEFENSE_10]="ȸ����(Defense) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_PROTECTION_10]="�����(Protection) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DECREASE_HP_EXHAUSTION_10_PERCENT]="��ų ���� �����(HP) �Ҹ� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_ENCHANT_DAMAGE_10_PERCENT]="��æƮ(Enchant) �迭 ���ݱ�� ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_HEAL_DAMAGE_10_PERCENT]="��(Heal) �迭 ���ݱ�� ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_NEAR_ATTACK_DAMAGE_10_PERCENT]="���� ���� �迭 ��ų ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_HP_RESTORE_SPEED_15_PERCENT]="�����(HP) ȸ���ӵ� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_RESISTANCE_ACID_15_PERCENT]="�ֽõ�(Acid) ���� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_RESISTANCE_BLOODY_15_PERCENT]="����(Blood) ���� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_RESISTANCE_CURSE_15_PERCENT]="Ŀ��(Curse) ���� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_RESISTANCE_POISON_15_PERCENT]="������(Poison) ���� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_DAMAGE_STORM_20_PERCENT]="����(Storm) �迭 ��ų ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_RANGE_STORM_5_BY_5]="����(Storm) �迭 ��ų ���� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_SUCCESS_RATIO_POISON_10_PERCENT]="��(Poison) �迭 ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_SUCCESS_RATIO_ACID_10_PERCENT]="��(Acid) �迭 ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_SUCCESS_RATIO_CURSE_10_PERCENT]="Ŀ��(Curse) �迭 ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_SUCCESS_RATIO_BLOODY_10_PERCENT]="��(Blood) �迭 ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_SUCCESS_RATIO_INNATE_10_PERCENT]="����(Innate) �迭 ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_SUCCESS_RATIO_SUMMON_10_PERCENT]="��ȯ(Summon) �迭 ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DECREASE_MP_EXHAUSTION_10_PERCENT]="��ų ���� MP �Ҹ� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_HP_STEAL_2_PERCENT]="�����(HP) ��ƿ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_MP_STEAL_2_PERCENT]="������(MP) ��ƿ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_LUCKY_2]="���(Lucky) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_KEEP_TIME_ACID_SWAMP_20_PERCENT]="�ֽõ� ������(Acid Swamp) ���ӽð� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_KEEP_TIME_PARALYZE_20_PERCENT]="�з�������(Paralyze) ���ӽð� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_KEEP_TIME_DARKNESS_30_PERCENT]="��ũ�Ͻ�(Darkness) ���ӽð� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INCREASE_RANGE_DARKNESS_5_BY_5]="��ũ�Ͻ�(Darkness) ���� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_UP_GRADE]="���̻� ����� ������ �ʽ��ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_SELECT_PC_CANNOT_PLAY] = "��������� �ƴ϶� ������ �� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_SELECT_PC_NOT_BILLING_CHECK] = "���� ���� ������ Ȯ�ε��� �ʾҽ��ϴ�. ��ø� ��ٷ��ּ���.";
	(*g_pGameStringTable)[STRING_MESSAGE_SELECT_PC_CANNOT_PLAY_BY_ATTR] = "ĳ���� �ɷ�ġ�� ���� ���� ���ѿ� �����ؼ� ���� ���񽺸� ����ϼž߸� ������ �� �ֽ��ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_NEVER_CANNOT_LEARN_SKILL] = "\"��� �� ���� ��ų�Դϴ�.\"";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ALREADY_LEARNED_SKILL] =    "\"�̹� ��� ��ų�Դϴ�.\"   ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_LEARN_SKILL_YET] =   "\"���� ��� �� �����ϴ�.\"  ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_LEARN_SKILL_NOW]=       "\"���� ��� �� �ֽ��ϴ�.\"  ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_GRADE1]="GRADE1";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ACCELERATOR_GRADE2]="GRADE2";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_LEARN_GRADE_SKILL_CONFIRM]= "�� ��ų�� ���� ���� ����� �ٸ� ��� ��ų�� ��� �� �����ϴ�. ������ ���ðڽ��ϱ�?";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_TREE_OK] = "Ʈ���� ����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TREE_CANCEL] = "Ʈ�� ����� ����մϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_TRADE_GIFT_BOX_OK] = "�޸� ũ��������~*";
	(*g_pGameStringTable)[STRING_MESSAGE_TRADE_GIFT_BOX_NO_ITEM] = "ģ���鿡�Լ� ������ �޾Ƽ� �ٽ� ���Գ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_TRADE_GIFT_BOX_ALREADY_TRADE] = "������� �����϶��, �� ������ ����!";

	(*g_pGameStringTable)[STRING_MESSAGE_XMAS_TREE_CANNOT_USE] = "������ �ٸ� Ʈ���� �ʹ� �������ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_XMAS_CARD_CANNOT_USE] = "�� �׸��� �ֽ��ϴ�. ��� �׸��� ä���ּ���.";
	(*g_pGameStringTable)[STRING_MESSAGE_NOT_USE_SAFETY_POSITION] = "�������뿡���� ����Ҽ� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NOT_USE_SAFETY_ZONE] = "�������̳� ���ȿ����� ����Ҽ� �����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENCHANT_CONFIRM_2] = "���� �ϸ� �������� �μ��� �� �ֽ��ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_DEPOSIT_LIMIT] = "�����Կ� 20�� �̻� ������ �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_WITHDRAW_LIMIT] = "20�� �̻� ������ �� �����ϴ�.";

	// 2003.1.14
	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_PREMIUM_HALF_SLAYER] = "���� �������� ������ ���� �������� �����Ͻ� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_PREMIUM_HALF_VAMPIRE] = "���� �������� ��û�� ���� �������� �����Ͻ� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_PREMIUM_HALF_SLAYER_END] = "������ ���� �������� ������ �� �ִ� �̺�Ʈ�� ����Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_PREMIUM_HALF_VAMPIRE_END] = "��û�� ���� �������� ������ �� �ִ� �̺�Ʈ�� ����Ǿ����ϴ�.";

	// 2003.1.15
	(*g_pGameStringTable)[STRING_MESSAGE_REWARD_OK] = "������ �޾ҽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_REWARD_FAIL] = "������ ���� �� �����ϴ�.";
    (*g_pGameStringTable)[STRING_MESSAGE_NO_EMPTY_SLOT] = "�� �ڸ��� �����ϴ�.";

	// 2003.1.20
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OPTION_DO_NOT_HOLY_LAND_MSG]= "�ƴ��� �������� �޽��� ���� �ʱ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HOLY_LAND_TOTAL_FEE] = "�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HOLY_LAND_CAN_BRING_FEE] = "������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HOLY_LAND_TOTAL_FEE_DESC] = "������ �� �ִ� �� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HOLY_LAND_CLICK_INPUT_FEE] = "Ŭ���Ͻø� ������ ������ �Է��մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HOLY_LAND_OK] ="�Է��� ������ �����ɴϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HOLY_LAND_INPUT_BRING_FEE] = "������ ������ �Է��ϼ���";

	(*g_pGameStringTable)[STRING_MESSAGE_NO_TEAM] = "���� �ҼӵǾ� ���� �ʽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NO_CLAN] = "Ŭ���� �ҼӵǾ� ���� �ʽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NOT_TEAM_MASTER] = "�� �����Ͱ� �ƴմϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NOT_CLAN_MASTER] = "Ŭ�� �����Ͱ� �ƴմϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_HAS_NO_CASTLE] = "���� ���� ���� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_HAS_NO_CASTLE] = "Ŭ���� ���� ���� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_TEAM_NOT_YOUR_CASTLE] = "���� ������ ���� �ƴմϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CLAN_NOT_YOUR_CASTLE] = "Ŭ���� ������ ���� �ƴմϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_SUCCESS_BRING_FEE] = "������ ã�ҽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_FAIL_BRING_FEE] = "������ ã�µ� �����Ͽ����ϴ�.";	

	(*g_pGameStringTable)[UI_STRING_MESSAGE_BRING_FEE_MSG] = " ���� ������ ���̳� Ŭ�� �����ʹ� �� ������ ���� ������ ������ �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BRING_FEE_LIMIT] = "������ ���ݰ� ���� �������� ���� ���� 20���� ���� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RACE_WAR]= "������ ����";

	(*g_pGameStringTable)[STRING_MESSAGE_WAR_SCHEDULE_FULL] = "���� �������� �� á���ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_WAR_ALREADY_REGISTERED] = "�̹� ���� ��û�� �߽��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_WAR_NOT_ENOUGH_MONEY] = "���� �����մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_WAR_REGISTRATION_OK] = "���� �����쿡 ��� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_MOVE_SAFETY_ZONE_BLOOD_BIBLE] = "���Ǽ����� ��� ������, �ڱ����� �������뿡�� �� �� �����ϴ�!";
	(*g_pGameStringTable)[STRING_MESSAGE_ALREADY_HAS_CASTLE] = "�̹� ���� ������ �ֽ��ϴ�.";
	//(*g_pGameStringTable)[STRING_MESSAGE_WAR_UNAVAILABLE] = "������ ���� ��û�� ���� �ʽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_WAR_UNAVAILABLE] = "���� ��û�� �� �� �����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_STATUS_TIME_FORMAT] = "%d�ð� %d��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_STATUS_LEFT_TIME] = "���� �ð�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_WAR] = "������ ����";

	(*g_pGameStringTable)[STRING_MESSAGE_BLOOD_BIBLE_BONUS_ARMEGA] = "��� ���� ������(MP) Ȥ�� �����(HP) �Ҹ� 50% ����";  
	(*g_pGameStringTable)[STRING_MESSAGE_BLOOD_BIBLE_BONUS_MIHOLE] = "��� +10";  
	(*g_pGameStringTable)[STRING_MESSAGE_BLOOD_BIBLE_BONUS_KIRO] = "���� +7, ��ø�� +7";  
	(*g_pGameStringTable)[STRING_MESSAGE_BLOOD_BIBLE_BONUS_INI] = "�������� ������ +10";  
	(*g_pGameStringTable)[STRING_MESSAGE_BLOOD_BIBLE_BONUS_GREGORI] = "�þ� +5, ��� �ɷ�ġ +4";  
	(*g_pGameStringTable)[STRING_MESSAGE_BLOOD_BIBLE_BONUS_CONCILIA] = "��� ���׷� +9";  
	(*g_pGameStringTable)[STRING_MESSAGE_BLOOD_BIBLE_BONUS_LEGIOS] = "�������ݵ����� +10";  
	(*g_pGameStringTable)[STRING_MESSAGE_BLOOD_BIBLE_BONUS_HILLEL] = "Ÿ������ ��� �뿪";  
	(*g_pGameStringTable)[STRING_MESSAGE_BLOOD_BIBLE_BONUS_JAVE] = "�׺��� 50% ����";  
	(*g_pGameStringTable)[STRING_MESSAGE_BLOOD_BIBLE_BONUS_NEMA] = "���ప 50% ����";  
	(*g_pGameStringTable)[STRING_MESSAGE_BLOOD_BIBLE_BONUS_AROSA] = "�����(HP) +50";  
	(*g_pGameStringTable)[STRING_MESSAGE_BLOOD_BIBLE_BONUS_CHASPA] = "�� +7, ���� +7";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_ARMEGA] = "�Ƹ��ް�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_MIHOLE] = "��ȣ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_KIRO] = "Ű��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_LEGIOS] = "��������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_HILLEL] = "����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_JAVE] = "���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_INI] = "���̴�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_GREGORI] = "�׷���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_CONCILIA] = "��ĥ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_NEMA] = "�׸�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_AROSA] = "�Ʒλ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_CHASPA] = "������";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_ARMEGA_ENG] = "ARMEGA";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_MIHOLE_ENG] = "MIHOLE";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_KIRO_ENG] = "KIRO";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_INI_ENG] = "INI";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_GREGORI_ENG] = "GREGORI";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_CONCILIA_ENG] = "CONCILIA";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_LEGIOS_ENG] = "LEGIOS";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_HILLEL_ENG] = "HILLEL";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_JAVE_ENG] = "JAVE";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_NEMA_ENG] = "NEMA";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_AROSA_ENG] = "AROSA";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_CHASPA_ENG] = "CHASPA";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_STATUS_DROP] = "���� ������ �ֽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_STATUS_HAS_SLAYER] = "�����̾ ������ �ֽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_STATUS_HAS_VAMPIRE] = "�����̾ ������ �ֽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_STATUS_NONE] = "������ �� �� �����ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_STATUS_SLAYER] = "�����̾��� ��ȣ���ܿ� �ֽ��ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_STATUS_VAMPIRE] = "�����̾��� ��ȣ���ܿ� �ֽ��ϴ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_DESC_POSITION] = "��ġ : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_DESC_STATUS] = "���� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_DESC_PLAYER] = "������ : ";	

	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_STATUS_ATTACK_GUILD] = "����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_STATUS_DEFENSE_GUILD] = "���";

	(*g_pGameStringTable)[STRING_MESSAGE_RACE_WAR_JOIN_FAILED] = "%s�� �������� ���� ���� ��û�ο��� �� á���ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_RACE_WAR_JOIN_OK] = "���� ���� ���� ��û�� �߽��ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_DESC_SHRINE_RACE] = "���� ���� : ";

	(*g_pGameStringTable)[STRING_MESSAGE_SLAYER] = "�����̾�";
	(*g_pGameStringTable)[STRING_MESSAGE_VAMPIRE] = "�����̾�";

	(*g_pGameStringTable)[STRING_MESSAGE_RACE_WAR_GO_FIRST_SERVER] = "���� ������ �� ������ ù��° ���������� ��û �� ������ �����մϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_GIVE_EVENT_ITEM_FAIL_NOW] = "������ �̺�Ʈ �������� ���� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_GIVE_EVENT_ITEM_FAIL] = "�̺�Ʈ �������� ���� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_GIVE_EVENT_ITEM_OK] = "�̺�Ʈ�� ���� �������� �޾ҽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_GIVE_PREMIUM_USER_ONLY] = "�����̾����� ����ڸ� ���� �� �ֽ��ϴ�.";

//	(*g_pGameStringTable)[STRING_MESSAGE_WAIT_FOR_MEET_COUPLE] = "Ŀ�� ��û �� ����� �̸��� �Է��ϼ���.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_MEET_SUCCESS] = "Ŀ���� ����Ǿ����ϴ�. �κ��丮�� Ŀ�þ������� �߰��Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_CANNOT_MEET] = "Ŀ���� ����� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_MEET_WAIT_TIME_EXPIRED] = "�ð��� ������ ��û�� ��ҵǾ����ϴ�.";

//	(*g_pGameStringTable)[STRING_MESSAGE_WAIT_FOR_APART_COUPLE] = "����� ����� �̸��� �Է��ϼ���.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_APART_SUCCESS] = "��������ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NOT_COUPLE] = "������ ����� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_APART_WAIT_TIME_EXPIRED] = "�ð��� ������ ��û�� ��ҵǾ����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_HOPE_COUPLE_MSG] = "Ŀ���� ���ΰ��� ���� �Ͽ� �̷������ �մϴ�. \n��û �����, Ŀ���� �Ǳ� ���ϴ� ������ �̸��� �Է��� �� ��û ���� ������ 1�� �ȿ� ������ �ͼ� ���� �Ͻø�, Ŀ���� �����˴ϴ�. �� ���׵��� ����Ͻʽÿ�.\n�׷�, ������ �Ǳ� ���Ͻô� ���� �̸��� �Է��Ͽ� �ֽʽÿ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BREAK_UP_COUPLE_MSG] = "���� �Ằ�� ���ΰ��� ���� �Ͽ� �̷�� ���� �ϸ�, ���� ��������� �ϴ� ������ �̸��� �Է��� �� ������ 1�� �ȿ� ������ �ͼ� ���� �Ͻø�, �Ằ�� �����˴ϴ�. ������� �Բ� �� ����� ����� ��ǥ�� Ŀ�ø��� ������ϴ�. �� ���׵��� ����Ͻʽÿ�.\n�׷�, ������ �̸��� �Է��Ͽ� �ֽʽÿ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPLETE] = "�Ϸ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OTHER_PLAYER_NAME] = "������ ĳ���� �̸�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_FORCE_BREAK_UP_COUPLE] = "�Ϲ����� ������� ������ ���� ���� �Ằ�� �����ϳ�, �ڽ��� ���⿡�� ��緮�� �����մϴ�. ���� �ڽ��� ������ �̸��� �Է��Ͻø�, �Ằ�� �����˴ϴ�. �Ằ ������ �Բ� �� ����� ����� ��ǥ�� Ŀ�ø��� ������ϴ�.  �� ���׵��� ����Ͻʽÿ�.\n�׷�, ������ �̸��� �Է��Ͽ� �ֽʽÿ�.";
	
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE] = "Ŀ��";
	(*g_pGameStringTable)[STRING_MESSAGE_MOVE_DELAY_SEC] = "%d�� �Ŀ� �̵��մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_MOVE_START] = "Ŀ�� ĳ���͸� ã�� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_CAN_NOT_FIND] = "Ŀ�� ĳ���͸� ã�� �� �����ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_NOT_EVENT_TERM] = "Ŀ�� �̺�Ʈ �Ⱓ�� �ƴմϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_ALREADY_WAITING] = "�̹� ��븦 ��ٸ��� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_LOGOFF] = "������ �α��� ���� �ʾҽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_DIFFERENT_RACE] = "���� �ٸ� �����Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_SAME_SEX] = "���� ���̿��� Ŀ���� �����˴ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_NOT_PAY_PLAYER] = "���� ����ڰ� �ƴմϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_ALREADY_COUPLE] = "�̹� Ŀ���Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_WAS_COUPLE] = "Ŀ���� ���� ���� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_NOT_ENOUGH_GOLD] = "�������� �����մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_NOT_ENOUGH_ATTR] = "�ɷ�ġ�� �����մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_NOT_ENOUGH_LEVEL] = "������ �����մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_INVENTORY_FULL] = "Ŀ�ø��� ���� ������ �����մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_NO_WAITING] = "����� ��ٸ��� ��Ʈ�ʰ� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_COUPLE_NOT_COUPLE] = "Ŀ���� �ƴմϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_LOVE_CHAIN] = "Ŀ���� �ִ°����� �̵��� �� �ִ� ��ų�Դϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_WILL_YOU_GO_BILING_PAGE] = "���� �������� �̵��Ͻðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GO_BILING_PAGE] = "���� �������� �̵��մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_LOGOUT_BY_PAYTIME] = "���� ���ð��� ����Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_LOGOUT_BY_FREEPLAY_LEVEL] = "�ɷ�ġ�� ���� ���� ���ѿ� �����߽��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_LOGOUT_BY_LEVEL] = "������ ���� ���� ���ѿ� �����߽��ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_UP_LEVEL_BY_FAME] = "���� �����Ͽ� �������� �� �� �����ϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NEED_FAME] = "�ʿ� ��ġ";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_HAN] = "����Ƽ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_ENG] = "Limited";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DAY] = "%d��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HOUR] = "%d�ð�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MINUTE] = "%d��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SECOND] = "%d��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_LEFT_TIME] = "���� ��� �ð� :";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EXPIRED_ITEM] = "�α׾ƿ��Ͻø� ������ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SELECT_QUEST_SLAYER] = "�̹� �ӹ��� E.V.E���� ���� �Ƿ� �� ��������, �ް��� �þ�� �����̾ ȿ�������� ��ġ�ϱ� ���ؼ� ���ο� ������ �����Ͽ����ϴ�. �̸� ���� �����̾ �����ϰ�� �־����� ������ ��ġ�ϴ� ���Դϴ�. ����Ʈ�� �ѹ��� �ϳ��� �����Ͽ� �����ϼž� �ϸ�, ����Ʈ ���� �α� �ƿ� �ÿ��� ����Ʈ�� ��ҵ˴ϴ�. �����̾� ������ ������ ������ ���� ���̰� �ֽ��ϴ�. �� �ӹ��� �����Ͻ� ��쿡�� E.V.E���� Ư���� ������ �־����ϴ�. ���Ͻô� ����Ʈ�� ������ �ּ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SELECT_QUEST_VAMPIRE] = "���� ���ϴ� ���� �þ��ֽ� �� �ְڽ��ϱ�? ����..�� ��� ��Ȱ ���������� ���� �Ƹ����� ���� �͵��� �ص��� ���� �Ѵ�ϴ�. �츮�� �����̾��� �����ϰ� ����� ������ ���Ͽ�, ��ó�� �� �� ���� �ϱ� �� �͵��� ������ �ʿ䰡 �ִٰ� �����ϴµ�������.. ��ʴϱ�? ���� �����Ͽ� ��õ�� ������ ������ �ֽñ� �����ðڽ��ϱ�? ����Ʈ�� �ѹ��� �ϳ��� �����Ͽ� �����ϼž� �ϸ�, ����Ʈ ���� �α� �ƿ� �ÿ��� ����Ʈ�� ��ҵ˴ϴ�. ���� ������ ������ ���� ������ ���� ���̰� ������, ����� �ؿ��ø� �˴ϴ�. ��� �Ͻðڽ��ϱ�? �밡�� Ȯ���� �帮�ڽ��ϴ�. ���Ͻô� ����Ʈ�� ������ �ֽʽÿ�.";	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANCEL_SELECT_QUEST] = "���� ��ȸ�� ��������.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANCEL_LEARN_SKILL] = "������ ���ڽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NUMBER_OF_ANIMALS]= "����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_FINISH_MONSTER_KILL_QUEST] = "���� ��� ����Ʈ�� �ð��� ����Ǿ����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_EXPIRED_TIME_MONSTER_KILL_QUEST] = "���� ��� ����Ʈ�� �ð��� ����Ǿ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FINISH_MONSTER_KILL_QUEST] = "���� ��� ����Ʈ ��ǥ�� �޼��Ǿ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_REQUITAL_FROM_NPC] = "���� NPC���� ������ ���� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_START_MONSTER_KILL_QUEST] = "���� ��� ����Ʈ�� ���۵Ǿ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FAIL_ALREADY_START_MONSTER_KILL_QUEST] = "�̹� ����Ʈ�� �������Դϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FAIL_MONSTER_KILL_QUEST_BY_STATUS] = "�ɷ�ġ�� ���� �ʾ� ����Ʈ�� �����Ҽ� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SUCCESS_MONSTER_KILL_QUEST] = "���� ��� ����Ʈ�� �����Ͽ����ϴ�. �κ��丮�� ����Ʈ �������� �߰��Ǿ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_YET_COMPLETE_MONSTER_KILL_QUEST] = "���� ��� ����Ʈ�� ���� �Ϸ���� �ʾҽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_INVENTORY_FULL_MONSTER_KILL_QUEST] = "�κ��丮�� ������ �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_IN_QUEST] = "����Ʈ���� �ƴմϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FAIL_QUEST_EXPIRED_TIME] = "���ѽð��� �ʰ��Ǿ� ����Ʈ�� �����߽��ϴ�.";	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TIME_LIMIT] = "���ѽð� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_APPLY_QUEST] = "������ ����Ʈ�� ��û�� �� �����ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPLETE_QUEST] = "����Ʈ ��ǥ �޼�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FAIL_TIME_OVER_QUEST] = "���ѽð� �ʰ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MEET_NPC] = "%s ������";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_FAIL_INVALID_NPC] = "�ش� NPC ���� ���� ���� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FAIL_BUG] = "������ �߻��Ͽ����ϴ�. �ٽ� �õ��ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GATHER_ITEM] = "%s ã��";

	(*g_pGameStringTable)[STRING_MESSAGE_MONSTER_KILL_QUEST_STRING_SET] = "�׷� %s %d������ %s ���� ��ƿ����� �ϰ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_MONSTER_KILL_QUEST_STRING_SET_VAMPIRE] = "�׷� %s %d������ %s ���� ��ƿ����� �Ͻʽÿ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANCEL_MONSTER_KILL_QUEST] = "��� ������ �Ŀ� �ٽ� ���ƿ��ڽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_YES_I_SEE] = "��, �˰ڽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_MONSTER_KILL] = "���� ��� ����Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_MEET_NPC] = "NPC ������ ����Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_GATHER_ITEM] = "������ ���ϱ� ����Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_DESCRIPTION_TIME_TOTAL] = "�� ���ѽð� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_DESCRIPTION_TIME_ELAPSE] = "�� �� �� �� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_DESCRIPTION_TIME_REMAIN] = "�� �� �� �� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_DESCRIPTION_TIME_NO_REMAIN] = "����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FAIL_QUEST] = "����Ʈ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SELECT_EVENT_GIFT] = "%d�ܰ� �̺�Ʈ ��ǰ�� �ϳ��� ������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PLEASE_SCRATCH_IMAGE] = "����� �̹����� �ܾ� �ּ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_WIN_A_PRIZE_SAME_IMAGE] = "���� �׸��� 3���� ��÷�Դϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CONGRATULATIONS] = "�����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_WIN_A_PRIZE] = "�� ��÷ �Ǽ̽��ϴ�.";
	
	(*g_pGameStringTable)[STRING_MESSAGE_MEET_NPC_SLAYER] = "�ƿ콺����� �����Ǵ� �⹦�� ������� ����� ���Ҵٴ� �ֹ��� ������Ͼ� �αٿ� �����ϴ� ������ ����Ǿ���. �˰����� ���� ���� ����ڸ� ã�� �ִ��� ���� ������ ��������.";
	(*g_pGameStringTable)[STRING_MESSAGE_MEET_NPC_VAMPIRE] ="�ƿ콺����� �����Ǵ� �⹦�� ������� ����� ���Ҵٴ� �ֹ� ���� ������ �α��� �̵� ���� ���ƴٴϰ� �ִٰ� �ϳ׿�. ���� ���� �׵��� ã�� �ִ��� ���� ������ �������� �ϼ���.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANCEL_QUEST_VAMPIRE] = "������ ������ �� �ٽ� ���ƿ��ڽ��ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_FAIL_LOTTERY] = "�ƽ��Ե� ��÷���� �����̽��ϴ�.\\n���� ��ȸ�� �̿����ּ���.\\n�̺�Ʈ ����Ʈ�� �ٽ� �����Ͻø� ������ ������ �� �ִ� ��ȸ�� �帳�ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_WIN_A_PRIZE2] = "��ǰ�� ��÷ �Ǽ̽��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_USER_1] = "�Բ���";

	(*g_pGameStringTable)[STRING_MESSAGE_RIPATY_SCRIPT_1] = "����� �������� ���ɼ��� ī���罺���� ��ȥ�� ������ ���迡�� �ع�����־����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_RIPATY_SCRIPT_2] = "��, ���ʽÿ�. ��Ȱ�� �츮���� ���������� �� ��� ��� �����Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_RIPATY_SCRIPT_3] = "13��° ���� ��������? ȣȣȣȣȣȣȣȪ�� ";
	(*g_pGameStringTable)[STRING_MESSAGE_RIPATY_SCRIPT_4] = "���� �ΰ����̶� ������ ����� ¦�� ������.";
	(*g_pGameStringTable)[STRING_MESSAGE_RIPATY_SCRIPT_5] = "�װ��� �������� ��ŵ��� �տ� ���⿡�� �ʹ� ������ �����Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_RIPATY_SCRIPT_6] = "�츮 �������� �װ��� ��Ű�� ���� ��� ���Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_RIPATY_SCRIPT_7] = "���� �̰��� �� ���ķδ� �ƴ��� ������ ��Ű�� �־�����.";
	(*g_pGameStringTable)[STRING_MESSAGE_RIPATY_SCRIPT_8] = "�װ� �׷��� ����� �ʹ� ���� ����� �˾ƹ��Ƚ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_RIPATY_SCRIPT_9] = "�׷��� ���� ������ ��� �ӿ��� ħ���� �����ּ����� ���ڽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_AMATA_SCRIPT_1] = "����� �������� ���ɼ��� ī���罺���� ��ȥ�� ������ ���迡�� �ع�����־����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_AMATA_SCRIPT_2] = "��, ���ʽÿ�. ��Ȱ�� �츮���� ���������� �� ��� ��� �����Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_AMATA_SCRIPT_3] = "13��° ���� ��������? ȣȣȣȣȣȣȣȪ�� ";
	(*g_pGameStringTable)[STRING_MESSAGE_AMATA_SCRIPT_4] = "�� ������ ����� 500���� ������ ������ ������.";
	(*g_pGameStringTable)[STRING_MESSAGE_AMATA_SCRIPT_5] = "�װ��� �� �ǿ� ���� ��ư��� ��ŵ��� �տ� ���⿡�� �ʹ� ������ �����Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_AMATA_SCRIPT_6] = "�츮 �������� �װ��� ��Ű�� ���� ��� ���Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_AMATA_SCRIPT_7] = "���� �̰��� �� ���ķδ� �ƴ��� ������ ��Ű�� �־�����.";
	(*g_pGameStringTable)[STRING_MESSAGE_AMATA_SCRIPT_8] = "�װ� �׷��� ����� �ʹ� ���� ����� �˾ƹ��Ƚ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_AMATA_SCRIPT_9] = "�׷��� ���� ������ ��� �ӿ��� ħ���� �����ּ����� ���ڽ��ϴ�.";	
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_NAME_FIND_ANCIENT_DOCUMENT] = "��� ���� ã�� ����Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_NAME_FIND_ANCIENT_MAP] = "��� ���� ã�� ����Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_NAME_FIND_SOUL_STONE] = "���ɼ� ã�� ����Ʈ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_IN_QUEST2] = "���� �������� ����Ʈ�� �����ϴ�.";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_EVENT_QUEST_1] = "1.�ƿ콺������ ����\\n����:���� Killing";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_EVENT_QUEST_2] = "2.��������� �׸���\\n����:���������� NPC ã��";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_EVENT_QUEST_3] = "3.������ ������ ����  ����:��� ���� ���� ����";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_EVENT_QUEST_4] = "4.�����븦 ã�Ƽ�\\n����:����Ʈ ���� Killing & ���� ȹ��";
//	(*g_pGameStringTable)[UI_STRING_MESSAGE_EVENT_QUEST_5] = "5.�ƿ콺������� ����\\n����:�ƿ콺��� ��Ȱ��ų ���ɼ� ã��";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_TAKE_OUT_OK] = "�������� �κ��丮�� �����Խ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TAKE_OUT_FAIL] = "�������� �κ��丮�� �������� ���߽��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_TAKE_OUT_ITEM_FROM_SHOP] = "������ ������ �������� ã�� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CONFIRM_SELECT_ITEM_FROM_SHOP] = "�����Ͻ� �������� �������ðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_SHOP] = "������ �̸��� Ŭ���Ͻø� ������ �������� �����ɴϴ�.";
	
	(*g_pGameStringTable)[STRING_MESSAGE_CLEAR_RANK_BONUS_OK] = "�����Ͻ� ����� ��ų�� ���� �Ǿ����ϴ�.";
    (*g_pGameStringTable)[STRING_MESSAGE_NO_RANK_BONUS] = "�ش� �ڰ��� �����ϴ�.";
    (*g_pGameStringTable)[STRING_MESSAGE_ALREADY_CLEAR_RANK_BONUS] = "�����Ͻ� ��� ��ų�� ������ ���� �ֽ��ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BULLETIN_BOARD_OK] = "�Խ����� ����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BULLETIN_BOARD_CANCEL] = "�Խ��� ����� ����մϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_BULLETIN_BOARD_CANNOT_USE] = "������ �ٸ� �Խ��ǰ� �ʹ� �������ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_TRANS] = "�������� �������� ������ ��ȯ�� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TRANS_ITEM] = "�� �������� �������� ������ ��ȯ�Ͻðڽ��ϱ�?";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_RESURRECT_BY_ELIXIR] = "�������� ����Ͽ� ��Ȱ�մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RESURRECT_BY_SCROLL] = "��Ȱ ��ũ���� ����Ͽ� ��Ȱ�մϴ�.";
	(*g_pGameStringTable)[UI_STRING_CANNOT_USE] = "����� �� �����ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MIXING_FORGE_OK] = "�ͽ������� ����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MIXING_FORGE_CANCEL] = "�ͽ����� ����� ����մϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPLETE_MERGE_ITEM] = "�� �������� ���������� ���������ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FAIL_MERGE_ITEM] = "�������� ��ġ�µ� �����Ͽ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_USE_GUILD_MEMBER_ONLY] = "���� ������ ������ ��� �����մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_USE_RIDE_MOTORCYCLE] = "������̸� Ÿ�� ����� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_MIXING_SPECIAL_ITEM]= "����ũ �������̳� ����Ƽ�� �������� �ͽ��� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_MIXING_OPTION_COUNT] = "�ɼ��� �Ѱ��� �����۸� �ͽ��� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_MIXING_ITEM_CLASS] = "������ ������ �޶� ������ �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_MIXING_ITEM_TYPE] = "������ Ÿ���� �޶� ������ �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_MIXING_ITEM_OPTION] = "�� �������� �ɼ��� ���Ƽ� ������ �� �����ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_WHAT_OPTION_REMOVE] = "� �ɼ��� �����Ͻðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CONFIRM_REMOVE_OPTION] = "�����Ͻ� �ɼ��� ������ �����Ͻðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_REMOVE_OPTION] = "�������� �ɼ��� ������ �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSGAE_CANNOT_REMOVE_OPTION] = "�������� �ɼ��� ������ �� �����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_SELECT_OPTION] = "%s �ɼ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUESTION_REMOVE_OPTION] = "���� �Ͻðڽ��ϱ�?";
	(*g_pGameStringTable)[STRING_MESSAGE_FAILED_REMOVE_OPTION] = "�ɼ��� ����µ� �����Ͽ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_SUCCESS_REMOVE_OPTION] = "������ �ɼ��� ���ŵǾ����ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_OTHER_TRIBE] = "Ÿ���� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CONSUME_EP] = "EP�Ҹ� : ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_OUSTERS_CIRCLET] = "��Ŭ���� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_OUSTERS_COAT] = "���� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_OUSTERS_WEAPON] = "íũ��/����Ʋ���� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_OUSTERS_BOOTS] = "������ �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_OUSTERS_ARMSBAND] = "�Ͻ������ �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_OUSTERS_RING] = "������ �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_OUSTERS_PENDENT] = "����̸� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_OUSTERS_STONE] = "���ɼ��� �����մϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_OUSTERS_STONE] = "%s�� ���� ���� : ";

	// �ƿ콺���� ���
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_MALCHUT] =	"������Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_YESOD] =	"���ҵ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_HOD] =	"ȣ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_NETRETH] =	"����ũ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_TIPHRETH] =	"Ƽ�ķ�Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_GEBURAH] =	"�Ժ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_CHESED] = "�Ǽ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_BINAH] =	"���̳�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_CHOKMA] = "ȣũ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_KEATHER] = "���׸�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_SKILL_LEVEL] = "��ų ���� : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_ELEMENTAL_LEVEL] = "�䱸 �Ӽ� ���� (%s)(%d)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_LEARN_SKILL] = "�� ��ų�� ���ðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_LEARN_SKILL2] = "�� ��ų�� �����ø� �迭�� �����˴ϴ�. ���� ��ų���ʹ� �� �迭�� �ش�Ǵ� ��ų�� ��� �� �ְ� �˴ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SKILL_LEVEL_UP] = "�� ��ų�� ������ �ø��ðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_SKILL_POINT] = "�ʿ� ��ų ����Ʈ : %d ����Ʈ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_ELEMENTAL_FIRE] = "��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ELEMENTAL_WATER] = "��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ELEMENTAL_EARTH] = "����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ELEMENTAL_WIND] = "�ٶ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ELEMENTAL_SUM] = "��";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EP] = "����";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_SHOW_GUILD_CHATTING] = "���ä�� �Ⱥ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_GUILD_CHATTING] = "���ä�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_CHATTING] = "���ä�� �ϱ�";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_WOOD_SKIN] = "�����(Protection) ����";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_WIND_SENSE] = "ȸ����(Defense) ����";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_HOMING_EYE] = "���߷�(To Hit) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_LIFE_ENERGY] = "�����(HP) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_SOUL_ENERGY] = "����(EP) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_STONE_MAUL] = "������� �迭 ������(Damage) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_SWIFT_ARM] = "���ݼӵ� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_FIRE_ENDOW] = "��(Fire) �迭 ���ݸ��� ������(Damage) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_WATER_ENDOW] = "��(Water) �迭 ���ݸ��� ������(Damage) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_EARTH_ENDOW] = "����(Earth) �迭 ���ݸ��� ������(Damage) ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_ANTI_ACID_SKIN] = "��(Acid) ���׷� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_ANTI_BLOODY_SKIN] = "��(Bloody) ���׷� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_ANTI_CURSE_SKIN] = "����(Curse) ���׷� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_ANTI_POISON_SKIN] = "��(Poison) ���׷� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_ANTI_SILVER_DAMAGE_SKIN] = "�� ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_BLESS_OF_NATURE] = "��ų���� ����(EP) �Ҹ� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_LIFE_ABSORB] = "�����(HP) ��ƿ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_SOUL_ABSORB] = "����(EP) ��ƿ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_MYSTIC_RULE] = "���(Lucky) ����";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_EP_DESCRIPTION] = "����(EP):%d/%d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_LEFT_BONUS_POINT] = "���ʽ� ����Ʈ�� �й��ϼž� �մϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD] = "���(Guild)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_INFO] = "��� ����(Guild Info)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_MEMBER_LIST] = "���� ����Ʈ(Guild Member List)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_HELP] = "��� ����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_ELEMENTAL_FIRE_DESCRIPTION] =  "Fire :%d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ELEMENTAL_WATER_DESCRIPTION] = "Water:%d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ELEMENTAL_EARTH_DESCRIPTION] = "Earth:%d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ELEMENTAL_WIND_DESCRIPTION] =  "Wind :%d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_EP]="EP : ";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PREV_MAP] = "���� ���� ���ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NEXT_MAP] = "���� ���� ���ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_HORN] = "���� ������ ���� ����մϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_ATTACK_SPEED] = "���ݼӵ� : ";

	(*g_pGameStringTable)[STRING_STATUS_EP_MAX_1] = "����(EP) �ִ�ġ�� %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_STATUS_EP_MAX_2] = "����(EP) �ִ�ġ�� %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_MAGIC_DAMAGE] = "���� ������ : ";
	
	(*g_pGameStringTable)[STRING_MESSAGE_OPEN_LAIR]	= "%s�� ���Ƚ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CLOSED_LAIR]= "%s�� �������ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_LEFT_TIME_LAIR]= "%s�� ���� ���� �ð��� %d�� ���ҽ��ϴ�.";	
	
	(*g_pGameStringTable)[STRING_MESSAGE_CONTRACT_GNOMES_HORN]="�ÿ������� ���� ����� �����ž� ����Ͻ� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CONTRACT_GNOMES_HORN_OK] = "���� ������ ���� ����ϱ� ���� ����� �ξ����ϴ�.";
	
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_DOWN_SKILL] = "��ų������ ���� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NOT_ENOUGH_MONEY_FOR_DOWN_SKILL] = "�������� �����Ͽ� ��ų������ ���� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CONFIRM_DOWN_SKILL] = "%s ��ų�� ��ų ������ %d ���� %d�� ����˴ϴ�. �ҿ����� $%s �Դϴ�. �����Ͻðڽ��ϱ�?";
	(*g_pGameStringTable)[STRING_MESSAGE_SUCCESS_CHANGE] = "���������� ����Ǿ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_WITHDRAW_POINT] = "ȸ�� ��ų ����Ʈ : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_DOWN_SKILL] = "�� ��ų�� ������ ���߽ðڽ��ϱ�?";

	(*g_pGameStringTable)[STRING_MESSAGE_NOT_OUSTERS] = "�ƿ콺��� �ƴմϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_TOO_LOW_SKILL_LEVEL] = "��ų������ �ʹ� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_TOO_HIGH_SKILL_LEVEL] = "��ų������ �ʹ� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_INVALID_SKILL] = "�߸��� ��ų�Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NOT_LEARNED_SKILL] = "���� ����� ���� ��ų�Դϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CONFIRM_UP_TO_LAST_SKILL_LEVEL] = "��ų������ �ְ�ܰ��� 30���� �ø� ��� �̸� ȸ���� �� �����ϴ�. 30������ ��½�Ű���� �ϰڽ��ϱ�?";

	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_USE_OUSTERS] = "�ƿ콺����� ����� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_MIXING_FORGE_FAILED_SAME_OPTION_GROUP]= "�������� �ɼ� �׷��� ���Ƽ� ���� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CONFIRM_CHANGE_SEX]= "������ ������ ��ȯ�Ͻðڽ��ϱ�?";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_CHANGE_SEX_BY_WEAR] = "���� �������¿����� ������ ��ȯ�� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_CHANGE_SEX_BY_COUPLE] = "Ŀ���� �ִ� ĳ���ʹ� ������ ��ȯ�� �� �����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_EVENT_QUEST2_1] = "1.������ ����\\n����:�־��� ���� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EVENT_QUEST2_2] = "2.����� ����\\n����:������ ���� ������ ���� ����(8��)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EVENT_QUEST2_3] = "3.������ �ʴ� ��\\n����:�̷θ� ����Ͽ� ���ǴϿ� ȹ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EVENT_QUEST2_4] = "4.���ϴ� ����\\n������ �������� ���� ������ ã�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EVENT_QUEST2_5] = "5.�̷��� ���¹�\\nƯ�� Ŭ������ ���͵鿡�Լ� ������ ã�� �ڵ�ǥ ����";	

	(*g_pGameStringTable)[STRING_MESSAGE_SELECT_MINI_GAME] = "�� ���� ������ ���õǾ� �ֽ��ϴ�. ���� �Ѱ����� �����Ͻʽÿ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_SELECT_ARROW_TILES] = "Arrow Tiles. ȭ��ǥ�� ���� �� �������� ������ �̵��ϴ� �����Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_SELECT_CRAZY_MINE] = "Crazy Mine. ���� �߱��� ���� ã�Ⱑ ������ ��������Դϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_GET_RIFINIUM] = "���ǴϿ��� ȹ���Ͽ����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_STATUS_ARROW_TILES] = "Arrow Tiles";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_QUEST_STATUS_CRAZY_MINE] = "Crazy Mine";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SUCCESS_MINIGAME] ="All Stage Clear!";

	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_REGIST_FAIL_ALREADY_JOIN] = "��� �ѹ� ����? �ڳ״� �̹� %s ��� �Ҽ��̶�� ���� �ֱ�";
	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_REGIST_FAIL_QUIT_TIMEOUT] = "�ڳ״� �ٸ� ��带 Ż������ �� ���� �ʾұ�. ���� �� �����ϰ� �����ϰ� �ൿ�ϰ�";
	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_REGIST_FAIL_CANCEL_TIMEOUT] = "�ڳ״� ��带 ��� ���� �� �� ���� �ʾұ�. ��� ���ǿ� �����ϵ��� �ڽ��� �� �� �⸣�� ����. �� �� �����ϰ� ��ȸ�� �������� �ϰ�";
	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_REGIST_FAIL_LEVEL] = "�Ǹ������� �����ν��� ������ �� ������ �� ����. �Ƿ��� �۰� ���Գ�";
	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_REGIST_FAIL_MONEY] = "��带 ������� ���� ���� �ʿ��ϴٳ�. �ڳ״� ���� ���� ���̴±�...";
	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_REGIST_FAIL_FAME] = "%s�̶�.. �� ���� �׷� �̸��� ������ ���ߴٳ�. �װ� �ڳװ� ǲ������ ���� �ǹ�����. �Ƿ��� �۰� �ٽ� ã�ƿ��Գ�";
	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_REGIST_FAIL_NAME] = "��� �̸��� �̹� ���̰� �ֱ�, �ٸ� �̸��� ������ ����";
	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_REGIST_FAIL_DENY] = "�źεǾ����ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_STARTING_FAIL_ALREADY_JOIN] = "����� �̹� �ٸ� ��忡 ���ԵǾ� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_STARTING_FAIL_QUIT_TIMEOUT] = "�ڳ״� �ٸ� ��带 Ż������ �� ���� �ʾұ�. ���� �� �����ϰ� �����ϰ� �ൿ�ϰ�";
	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_STARTING_FAIL_CANCEL_TIMEOUT] = "�ڳ״� ��带 ��� ���� �� �� ���� �ʾұ�. ���ǿ� �����ϵ��� �ڽ��� �� �� �⸣�� ����. �� �� �����ϰ� ��ȸ�� �������� �ϰ�";
	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_STARTING_FAIL_LEVEL] = "�ڳ״� ���� ������ ���� ���� ���̴±���. ���� �� �Ƿ��� �۰� ã�Գ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_STARTING_FAIL_MONEY] = "%s, ��� ����� ���ؼ��� ���� �� �ʿ��ϴٳ�";
	(*g_pGameStringTable)[STRING_MESSAGE_GUILD_STARTING_FAIL_FAME] = "%s�̶�.. �� ���� �׷� �̸��� ������ ���ߴٳ�. �װ� �ڳװ� ǲ������ ���� �ǹ�����. �Ƿ��� �۰� �ٽ� ã�ƿ��Գ�";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLICK_TO_SHOW_DETIAL] = "Ŭ���Ͻø� ���� ������ ���� �� �ֽ��ϴ�.";
	
	(*g_pGameStringTable)[STRING_MESSAGE_OUSTERS] = "�ƿ콺����";

	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_FLAG_WAR_READY] = "5�еڿ� Capture the Flag! �̺�Ʈ�� �ǽ��մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_FLAG_WAR_START] = "Capture the Flag! �̺�Ʈ�� ���۵Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_FLAG_WAR_FINISH] = "Capture the Flag! �̺�Ʈ�� ����Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_FLAG_WAR_WINNER] = "%s ������ %d���� ����� ��Ƽ� �¸��Ͽ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_FLAG_WILL_POUR_ITEM_AFTER_3MIN] = "3���Ŀ� ����������� �������� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_FLAG_POURED_ITEM] = "Capture the Flag �̺�Ʈ �������� ���Խ��ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_GET_EVENT_FLAG_STATUS] = "ȹ���� ��߼� : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MUTE] = "��ڿ� ���ؼ� ä���� �����Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_MOVE_SAFETY_ZONE_FLAG] = "����� ��� ��������� �� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_DROP_ITEM_BY_FLAG] = "��� �ֺ����� �������� ���� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_POUR_ITEM_AFTER_SECOND] = "%d �� �Ŀ� ����������� �������� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_ACTION_MOTORCYCLE_FLAG] = "��� �ֺ������� ������̸� Ÿ�ų� ���� �� �����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_GUILD_NAME] = "��� �̸� : %s";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_INFO_GUILD_INTRODUCTION] = "��� �Ұ� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_OTHER_INFO_GUILD_NAME] = "��� �̸� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_JOIN_ANY_GUILD] = "��ϵ� ��� ����";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_USE_ETERNITY_FOR_RESURRECT] = "���ʹ�Ƽ ��ų�� ����Ͽ� ��Ƴ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_RELOAD_BY_VIVID_MAGAZINE]= "���� �Ű��� ��ų�� ����� ����� �� �ֽ��ϴ�.";
	
	(*g_pGameStringTable)[STRING_MESSAGE_RESURRECT_AFTER_SECONDS] = "%d �� �Ŀ� ��Ȱ�մϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_TRADE_SUMMON_SYLPH] = "�ٶ��� ������ ź ���¿����� �ŷ��� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_USE_SUMMON_SYLPH] = "�ٶ��� ������ ź ���¿��� ����� �� �����ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_MODIFY_SKILL_LEVEL_1] = "%s ��ų ������ %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_MODIFY_SKILL_LEVEL_2] = "%s ��ų ������ %d�� �Ǿ����ϴ�.";

	// 2003.09.29
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GO_TO_BEGINNER_ZONE] = "�ʺ� ���� ����ͷ� �̵��մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_LEFT_PREMIUM_DAYS] = "�����̾� ���� ���Ⱓ�� %d�� ���ҽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_PREMIUM_USER] = "���� ����ڰ� �ƴմϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EXPIRE_PREMIUM_SERVICE_TODAY] = "�����̾� ���񽺴� ���ñ��� �Դϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_EXPIRE_PREMIUM_SERVICE_MESSAGE_1] = "�����̾� ���� �Ⱓ�� ������ ���� ���Ӱ����� �� ��� �ٵ� ���ϸ�����";
	(*g_pGameStringTable)[STRING_MESSAGE_EXPIRE_PREMIUM_SERVICE_MESSAGE_2] = "������ ���ǵ� �پ��� ������ ������ �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_EXPIRE_PREMIUM_SERVICE_MESSAGE_3] = "�ڼ��� ������ ��ũ���� Ȩ������(www.darkeden.com)���� Ȯ���Ͻ� �� �ֽ��ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_LEVEL_WAR_ZONE_NAME] = "Į���� %d��";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWEEPER_BONUS_1] = "��� �ɷ�ġ + 2";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWEEPER_BONUS_2] = "ü��(HP) + 20";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWEEPER_BONUS_3] = "������ + 3";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWEEPER_BONUS_4] = "���� + 7, ��ø�� + 7";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWEEPER_BONUS_5] = "ü��(HP) + 50";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWEEPER_BONUS_6] = "��� + 7";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWEEPER_BONUS_7] = "���� ���� ������ + 10";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWEEPER_BONUS_8] = "���� + 7, �� + 7";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWEEPER_BONUS_9] = "ü��(HP) ��� + 15";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWEEPER_BONUS_10] = "���� ���� ������ + 10";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWEEPER_BONUS_11] = "��� ���׷� + 7";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWEEPER_BONUS_12] = "�þ� + 5, ��� �ɷ�ġ + 4";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_JOIN_LEVEL_WAR] = "���￡ �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLICK_TO_WARP_REGEN_TOWER] = "Ŭ���Ͻø� �ش� ���� �� Ÿ���� �̵��մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_STATUS_HAS_OUSTERS] = "�ƿ콺��� ������ �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BIBLE_STATUS_OUSTERS] = "�ƿ콺������ ��ȣ���ܿ� �ֽ��ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MAILBOX] = "������(Mail Box)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_MAILBOX] = "�������� �ݽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MAILBOX_TAB_MAIL] = "������ Ȯ���մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MAILBOX_TAB_HELP] = "������ Ȯ���մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MAILBOX_TAB_MEMO] = "���� �������� �ʽ��ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_SUCCESS_CHANGED_BAT_COLOR] = "������� ����Ǿ����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_LEVEL_WAR] = "���� ����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_LEFT_FAMILY_DAYS] = "�йи� ���� ���Ⱓ�� %d�� ���ҽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EXPIRE_FAMILY_TODAY] = "�йи� ���񽺴� ���ñ��� �Դϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOO_FAR] = "�� ������ ���ž� �մϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_DESC_DURABILITY] = "���� ���̾� : ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_ATTR] = "�Ӽ� : ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_PET_INFO_WINDOW] = "�ֿϵ��� ����â�� ���ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_ENCHANT_FAIL] = "��þƮ�� �����Ͽ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_DESC_DURABILITY_2] = "���� ���̾�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_RESSURECT] = "�ֿϵ����� ��Ȱ ��Ű�ðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLOSE_PET_INFO] = "�ֿϵ��� ����â�� �ݽ��ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_ENCHANT_PET] = "2�� �ɷ��� �ο��� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_ENCHANT_PET] = "������ 2�� �ɷ��� �ο��� �� �����ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_NEW_PET_LEVEL_1] = "%s�� ������ %d�� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NEW_PET_LEVEL_2] = "%s�� ������ %d�� �Ǿ����ϴ�.";
	
	(*g_pGameStringTable)[STRING_MESSAGE_OPTION_NAME_LUCK_3] = "��Ű";
	(*g_pGameStringTable)[STRING_MESSAGE_OPTION_NAME_LUCK_4] = "�̴Ͽ�";

	(*g_pGameStringTable)[STRING_MESSAGE_OPTION_NAME_ATTR_3] = "��Ʈ";
	(*g_pGameStringTable)[STRING_MESSAGE_OPTION_NAME_ATTR_4] = "ũ��ġ";

	(*g_pGameStringTable)[STRING_MESSAGE_PET_DIE_WARNING] = "%s�� ���̰� %s �з��ۿ� ���� �ʾҽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PET_REQUEST_REFILL] = "���̸� �����Ͻñ� �ٶ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PET_DIE] = "%s�� ����Ͽ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PET_SUMMON] = "%s�� ��ȯ�Ͽ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PET_CAN_GET_ATTR] = "�Ӽ��� �ο��Ͻ� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PET_GAMBLE_OK] = "%s���� 2�� �ɷ��� �ο��ϼ̽��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PET_GAMBLE_DESC] = "�����۰� ���Ҿ� ������ �Ӹ��� �Բ� ������ �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PET_GAMBLE_DESC_TEEN] = "�����۰� ���Ҿ� �ҿ� ���浵 �Բ� ������ �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PET_CAN_GET_OPTION] = "%s���� �ɼ��� �ο��Ͻ� �� �ֽ��ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HPBAR_EXP_DESCRIPTION_NEW] = "���� ����ġ : %s (%s%%)";
	(*g_pGameStringTable)[STRING_MESSAGE_PET_GAMBLE_FAIL] = "2�� �ɷ� �ο��� �����Ͽ����ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_OPTION_ENAME_LUCK_3] = "Lucky";
	(*g_pGameStringTable)[STRING_MESSAGE_OPTION_ENAME_LUCK_4] = "Minion";

	(*g_pGameStringTable)[STRING_MESSAGE_OPTION_ENAME_ATTR_3] = "Nut";
	(*g_pGameStringTable)[STRING_MESSAGE_OPTION_ENAME_ATTR_4] = "Crunch";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_PET_REVIVAL] = "��Ȱ��ų �� �ֽ��ϴ�.";	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_PET_REVIVAL]= "���� ��쿡�� ����� �� �ֽ��ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_CAN_CUT_HEAD] = "2���ɷ� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_CANNOT_CUT_HEAD] = "2���ɷ� ����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_REMOVE_PET_OPTION] = "�ֿϵ����� �ɼ��� ����ðڽ��ϱ�?";

	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_EVENT_GIFT_BOX] = "���� ��� �������ڰ� �־�� ��ȯ�� �� �ֽ��ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_NETMARBLE_1] = "�����մϴ�! �б��� ���� �̺�Ʈ�� ������ �ڰ��� �����̽��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_NETMARBLE_2] = "99���� �ݸ��� ī��� ������Դϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_NETMARBLE_3] = "�̺�Ʈ�� ����� ������ �� �����ϰ� ��ñ� �ٶ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_EVENT_NETMARBLE_4] = "���� ī�尡 ���� ��� �̺�Ʈ�� �����Ͻ� �� �����ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_USE_PET_FOOD] = "������ ��ư�� Ŭ���Ͻø� �ֿϵ������� ���̸� �� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DETACH_PET_FOOD] = "������ ��ư�� Ŭ���Ͻø� �������� �и��Ͻ� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_USE_PET_FOOD] = "�ֿϵ������� ���̸� ���̽ðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_DETACH] = "�������� �и��Ϸ��� �ֿϵ����� ��ȯ���� ���� ���¿����� �����մϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_0] = "��&��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_1] = "��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_2] = "��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_3] = "��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_4] = "SMG";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_5] = "AR";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_6] = "SG";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_7] = "SR";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_8] = "���ڰ�&���̽�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_9] = "���ڰ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_10] = "���̽�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_11] = "��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_12] = "���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_13] = "����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_14] = "����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_15] = "����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_16] = "�尩";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_17] = "��Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_18] = "�Ź�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_19] = "�Ǽ�����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_20] = "�����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_21] = "����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_22] = "����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_23] = "��Ÿ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_24] = "����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_25] = "����&����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_26] = "źâ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_27] = "��ź&����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_28] = "������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_COMPUTER_STRING_29] = "��Ÿ������";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_0] = "�������� ������ �� �����̾�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_1] = "������ ����- ��������� ������ ����� �Ǹ� ���Ƹ�����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_2] = "�縶�Ͼƿ� ü�ڽ��ι�Ű���� ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_3] = "�縶�Ͼ��� ���� ���佺";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_4] = "�߽��ڿ� �ƶ����� ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_5] = "�����̾� A to Z";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_6] = "�����̾��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_7] = "�����̾��� �ɷ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_8] = "�����̾��� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_9] = "�����̾��� ������ ��ġ���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_10] = "�����̾��� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_11] = "���ε��� �����׽þ��� ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_12] = "����å������ �����̾�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_13] = "����� �ΰ��ž� �� �����Ϳ� ���� �̾߱��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_14] = "�Ϻ��� �����̹ݵ��� ������ ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_15] = "Ǫ�������� �糪�̶�� �������� ���α� - �� �� ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_16] = "�밡���� ���� ������- ����ü��Ʈ ���丮";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_17] = "�������� ����å";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_18] = "�������� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_19] = "�������� Ư¡";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BOOK_NAME_20] = "��������� �����ΰ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_TNDEAD] ="TNDEAD";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_ARKHAN] ="ARKHAN";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_ESTROIDER] ="ESTROIDER";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_GOLEMER] =	"GOLEMER";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_DARKSCREAMER] ="DARKSCREAMER";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_DEADBODY] ="DEADBODY";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_MODERAS] =	"MODERAS";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_VANDALIZER] ="VANDALIZER";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_DIRTYSTRIDER] ="DIRTYSTRIDER";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_HELLWIZARD] ="HELLWIZARD";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_TNSOUL] ="TNSOUL";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_IRONTEETH] ="IRONTEETH";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_REDEYE] ="REDEYE";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_CRIMSONSLAUGTHER] ="CRIMSONSLAUGTHER";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_HELLGUARDIAN] ="HELLGUARDIAN";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_SOLDIER] =	"SOLDIER";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_RIPPER] ="RIPPER";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_BIGFANG] =	"BIGFANG";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_LORDCHAOS] ="LORDCHAOS";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_CHAOSGUARDIAN] ="CHAOSGUARDIAN";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_HOBBLE] ="HOBBLE";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_CHAOSNIGHT] ="CHAOSNIGHT";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_WIDOWS] ="WIDOWS";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_KID] ="KID";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MONSTER_ENAME_SHADOWWING] ="SHADOWWING";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_HAN_DOMAIN_BLADE]="��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HAN_DOMAIN_SWORD]="��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HAN_DOMAIN_ENCHANT]="��æƮ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HAN_DOMAIN_GUN]	="��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HAN_DOMAIN_HEAL]="��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HAN_DOMAIN_ETC]="��Ÿ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HAN_DOMAIN_VAMPIRE]="�����̾�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_HAN_DOMAIN_OUSTERS]="�ƿ콺����";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DOMAIN_ETC]="Etc";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DOMAIN_VAMPIRE]="Vampire";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ENG_DOMAIN_OUSTERS]="Ousters";

	(*g_pGameStringTable)[STRING_MESSAGE_SOUL_STONE]="�ҿ� ����";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_PET_MUTANT] = "���� ��ų �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_PET_MUTANT] = "���� ��ų �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_MUTANT] = "���� ��������� ���� ��Ű�ðڽ��ϱ�?";
	
	// 2004, 03, 26 sobeit add start
	(*g_pGameStringTable)[STRING_ERROR_CANNOT_AUTHORIZE_BILLING] = "���� ������ ã�� �� �����ϴ�.";
    (*g_pGameStringTable)[STRING_ERROR_CANNOT_CREATE_PC_BILLING] = "���� ����ڰ� �ƴ϶� ĳ���͸� �� ����ϴ�.";
	// 2004, 03, 26 sobeit add end
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_PET_DEAD_DAY] = "������ %d�� �������ϴ�.";

	// 2004, 04, 3 sobeit add start
	(*g_pGameStringTable)[UI_STRING_MESSAGE_DESC_LUCKY] = "��� : ";
	// 2004, 04, 3 sobeit add end

	// 2004, 4, 13 sobeit add start
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_QUEST_NPC_SLAYER] = "�׷��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_QUEST_NPC_VAMPIRE] = "ī��Ƽ��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_QUEST_NPC_OUSTERS] = "�Ƹ�Ÿ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_QUEST_SLAYER] = "���Ϳ�� ����Ʈ\\n����: %d�е���\\n{%s} {%d}������ ��ƶ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_QUEST_VAMPIRE] = "������ ����Ʈ\\n����: %d�е���\\n{%s} {%d}������ ��ƶ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_QUEST_OUSTERS] = "�Ƚ� ����Ʈ\\n����: %d�е���\\n{%s} {%d}������ ��ƶ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_QUEST_CLEAR] = "���� ���ư��ʽÿ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_3RD_ENCHANT_PET] = "3�� �ɷ��� �ο��� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_3RD_ENCHANT_PET] = "������ 3�� �ɷ��� �ο��� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PET_3RD_GAMBLE_FAIL] = "3�� �ɷ� �ο��� �����Ͽ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_PET_3RD_GAMBLE_OK] = "%s���� 3�� �ɷ��� �ο��ϼ̽��ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_SUMMON_2ND_PET] = "���� 40 ���ϴ� 2�� ���� ��ȯ�� �� �����ϴ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_SEARCHING_MINE] = "ã�ƾ��� ���ڼ� : %d üũ�� ���� �� : %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_MIXING_GRADE_VALUE] = "�����۰� ������� 2����� ������ �ͽ��� �� �����ϴ�.";
		
	// 2004, 4, 13 sobeit add end
	
	(*g_pGameStringTable)[STRING_MESSAGE_MINIGAME_GAME_OVER] = "game over";
	(*g_pGameStringTable)[STRING_MESSAGE_MINIGAME_ALL_STAGE_CLEAR] = "All stage clear";

	// 2004, 5, 6, sobeit add start
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SELECT_QUEST_OUSTERS] = "�� �ٷ� ���� ���� �����ϰ� �ֽ��ϴ�. �� ���͵�� ���ؼ� ����� ���� ���� �������� �ֽ��ϴ�. �츮 ������ ��Ȱ�� ���ؼ��� �� ���͵��� ó���ϰ� ��踦 ���ѳ��� �ؾ� �մϴ�. �� �ӹ��� �ߵ��� ������ �����ϰ� �Ǹ� ��ȿ�� �Ǵ� �����ؾ� �ϸ�, ����Ʈ�� �ش��ϴ� ���� ����ŭ ����ϰ� �ǰ� ���� ���Ŵٸ� ���� ���� ������ �帮���� �ϰڽ��ϴ�. ��, �׷� � ����Ʈ�� ���� �ϽǷ���?";
	// 2004, 5, 6, sobeit add end

	// 2004, 6, 22 By Csm 
	(*g_pGameStringTable)[STRING_ERROR_CHILDGUARD_DENYED] = "User who age under 18 will not able to play after 22.00 O'clock.";
	// end 

	//2004, 5, 11 sobeit add start - �� ������
	(*g_pGameStringTable)[STRING_MESSAGE_KEEP_PETITEM] = "���� ���� �Ͻðڽ��ϱ�?";
	(*g_pGameStringTable)[STRING_MESSAGE_GET_KEEP_PETITEM] = "���� ã���ðڽ��ϱ�?";
	//2004, 5, 11 sobeit add end - �� ������

	//2004, 5, 13 sobeit add start
	(*g_pGameStringTable)[STRING_MESSAGE_EXIST_ITEM_ALREADY] = "�̹� �ٸ� �������� �ֽ��ϴ�.";
	//2004, 5, 13 sobeit add end

	// 2004, 5, 17 sobeit add start
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_GRADE] = "  ��������������������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_GRADE_DESC] = "��� :";
	// 2004, 5, 17 sobeit add end

	// 2004, 6, 4, sobeit add start - sms ����
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SMS_SEND_OK] = "�޼����� ���������� ���½��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SMS_SEND_FAIL] = "�޼����� �����µ� �����߽��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SMS_ADD_FAIL] = "����Ʈ�� �߰��ϴµ� �����߽��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SMS_DELETE_FAIL] = "����Ʈ���� �����ϴµ� �����߽��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SMS_FAIL_MAX_NUM_EXCEEDED] = "���� ���� ��ȣ�� �ʰ��Ǿ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SMS_FAIL_INVALID_DATA] = "�߸��� ���� �Դϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SMS_FAIL_NO_SUCH_EID] = "������ ã�� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SMS_FAIL_NOT_ENOUGH_CHARGE] = "�������� ���ڶ��ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SMS_WINDOW] = "SMSâ(SMS Window)";
	// 2004, 6, 4, sobeit add end - sms ����
	// 2004, 6, 8, sobeit add start - sms ����
	(*g_pGameStringTable)[UI_STRING_HELP_SMS_SEND] = "�޼����� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_HELP_SMS_VIEW_LIST] = "��ȭ ��ȣ�θ� ���ϴ�.";
	(*g_pGameStringTable)[UI_STRING_HELP_SMS_WINDOW] = "Ư�� ���ڸ� ���� �մϴ�.";

	(*g_pGameStringTable)[UI_STRING_HELP_SMS_ADDSEND] = "������ ��ȣ�� ������ ��Ͽ� �߰� �մϴ�.";
	(*g_pGameStringTable)[UI_STRING_HELP_SMS_DELETE] = "������ ��ȣ�� ���� �մϴ�.";
	(*g_pGameStringTable)[UI_STRING_HELP_SMS_NEW] = "�ű� ��ȣ�� ��� �մϴ�.";
	// 2004, 6, 8, sobeit add end - sms ����

	// 2004, 6, 14 sobeit add start use sms item
	(*g_pGameStringTable)[UI_STRING_MESSAGE_USE_SMSITEM] = "SMS �������� ����Ͻðڽ��ϱ�?";
	// 2004, 6, 14 sobeit add end

	// 2004, 6, 15 sobeit add start - nameinge window help
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NAMING_WINDOW] = "�г���â(NickName Window)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHANGE_PET_NICKNAME] = "���� �г����� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHANGE_PLAYER_NICKNAME] = "���� ���� �г����� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADD_PLAYER_NICKNAME] = "�г����� �߰� �մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SELECT_PLAYER_NICKNAME] = "���õ� �г������� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NICKNAME_CHANGE_OK] = "�г����� ����Ǿ����ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NICKNAME_SELECT_FAIL_FORCED] = "��ڰ� ���� ������ �г����� ������ �� �����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_USE_NAMINGITEM] = "���̹� �������� ����Ͻðڽ��ϱ�?";
	// 2004, 6, 15 sobeit add end
 
	// 2004, 6, 25 sobeit add start
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_NAMING_SUMMON] = "���� ��ȯ�� �϶��� �г����� ������ �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_NAMING_WOLVERINE] = "������� �� ������ ���� �г����� ������ �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_FAIL_SEARCH_ITEM] = "�������� ã�� �� �����ϴ�.";
	// 2004, 6, 25 sobeit add end

	// 2004, 7,1 sobeit add start
	(*g_pGameStringTable)[UI_STRING_CORE_ZAP_BLACK] = "���� ���ݷ� +%d";
	(*g_pGameStringTable)[UI_STRING_CORE_ZAP_RED] = "���� ���ݷ� +%d";
	(*g_pGameStringTable)[UI_STRING_CORE_ZAP_BLUE] = "���� ���� +%d";
	(*g_pGameStringTable)[UI_STRING_CORE_ZAP_GREEN] = "���� ���� +%d";

	(*g_pGameStringTable)[UI_STRING_CORE_ZAP_REWARD_ALL_STAT] = "��� �ɷ�ġ +%d(4Set)";
	(*g_pGameStringTable)[UI_STRING_CORE_ZAP_REWARD_ALL_REG] = "��� ���׷� +%d(4Set)";

	// 2004, 7,1 sobeit add end

	// 2004, 7,10 sobeit add start
	(*g_pGameStringTable)[UI_STRING_GQUEST_CAN_NOT] = "����Ұ�";
	(*g_pGameStringTable)[UI_STRING_GQUEST_CAN_ACCEPT] = "���డ��";
	(*g_pGameStringTable)[UI_STRING_GQUEST_DOING] = "������";
	(*g_pGameStringTable)[UI_STRING_GQUEST_SUCCESS] = "����";
	(*g_pGameStringTable)[UI_STRING_GQUEST_COMPLETE] = "�Ϸ�";
	(*g_pGameStringTable)[UI_STRING_GQUEST_FAIL] = "����";
	(*g_pGameStringTable)[UI_STRING_GQUEST_CAN_REPLAY] = "����డ";
	(*g_pGameStringTable)[UI_STRING_GQUEST_MISSION] = "�ӹ�%d:%s";

	(*g_pGameStringTable)[UI_STRING_GQUEST_BUTTON_ACCEPT] = "����Ʈ�� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_GQUEST_BUTTON_GIVEUP] = "����Ʈ�� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_GQUEST_TAB_PROCESS] = "�������� ����� ���ϴ�.";
	(*g_pGameStringTable)[UI_STRING_GQUEST_TAB_COMPLETE] = "�Ϸ�� ����� ���ϴ�.";
	// 2004, 7,10 sobeit add end

	// 2004, 7, 15 sobeit add start
	(*g_pGameStringTable)[UI_STRING_NOTICE_EVENT_GOLD_MEDALS] = "�ݸ޴��� %d�� ��ҽ��ϴ�.";
	// 2004, 7, 15 sobeit add start

	// 2004, 7, 19 sobeit add start
	(*g_pGameStringTable)[STRING_ERROR_KEY_EXPIRED] = "����Ű ��ȿ �ð��� �������ϴ�. �ٽ� ���� ���ֽýʿ�.";
	(*g_pGameStringTable)[STRING_ERROR_NOT_FOUND_KEY] = "����Ű�� ���ų� �߸��Ǿ����ϴ�. �ٽ� ���� ���ֽýʿ�.";
	// 2004, 7, 19 sobeit add end

	// 2004, 7, 23 sobeit add start
	(*g_pGameStringTable)[UI_STRING_GQUEST_UPDATE] = "����Ʈ ������ ������Ʈ �Ǿ����ϴ�.";
	// 2004, 7, 23 sobeit add start

	// 2004, 8, 5 sobeit add start
	(*g_pGameStringTable)[UI_STRING_CHANGE_EVENTITEM_PRICE] = "�̺�Ʈ �������� %d���� �Ľ� �� �ֽ��ϴ�.";
	// 2004, 8, 5 sobeit add start
	
	// 2004, 8, 26, sobeit add start
	(*g_pGameStringTable)[STRING_MESSAGE_TOO_MANY_GUILD_REGISTERED] = "���� ��û�� ��尡 �ʹ� ���Ƽ� ��û�� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_REINFORCE_DENYED] = "������ ���� ��û�� �̹� �źδ��ؼ� ���û �� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_ALREADY_REINFORCE_ACCEPTED] = "������ ���� ��û�� �㰡�� ��尡 �̹� �־ ��û�� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_NO_WAR_REGISTERED] = "���� ��û�� ��尡 ��� ������ ���� ��û�� �� �� �����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_ACCEPT] = "������ ���� ��û�� ������ �� �����ϴ�";
	(*g_pGameStringTable)[STRING_MESSAGE_ACCEPT_OK] = "���� ��û�� �����Ͽ����ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_DENY] =	"������ ���� ��û�� �ź��� �� �����ϴ�.";
    (*g_pGameStringTable)[STRING_MESSAGE_DENY_OK] = "���� ��û�� �ź��Ͽ����ϴ�.";
	// 2004, 8, 26, sobeit add end

	(*g_pGameStringTable)[STRING_MESSAGE_SIEGE_POTAL_200] = "Ʈ�������� �̵�";
	(*g_pGameStringTable)[STRING_MESSAGE_SIEGE_POTAL_201] = "������ ������ �̵�";
	(*g_pGameStringTable)[STRING_MESSAGE_SIEGE_POTAL_202] = "���� ������ �̵�";
	(*g_pGameStringTable)[STRING_MESSAGE_SIEGE_POTAL_203] = "���� ������ �̵�";

	(*g_pGameStringTable)[STRING_MESSAGE_LOGIN_ERROR_NONPK] = "ĳ������ ������ ���� ������ �� �����ϴ�. �ٸ� ������ �̿��� �ֽʽÿ�.";

	(*g_pGameStringTable)[STRING_MESSAGE_DAUM_EVENT_1] = "��ũ������ �غ��� �ʺ��� �̺�Ʈ! ���ӿ� �ͼ����� ���� �ʺ������� ���Ͽ� ��ũ�������� ���׸��� ������ �Բ� ������ �帳�ϴ�. �̺�Ʈ�� �Ϸ��ϰ� ���� �������� �پ��ϰ� �غ�� ������ ������ �� �� �ֽ��ϴ�. ���� ���� ������ �����Ͻø� ���� �پ��� ������ �غ�Ǿ� �ֽ��ϴ�. �̺�Ʈ �������� ��� ��� ������ �������� �������ñ� �ٶ��ϴ�. �̺�Ʈ�� 8���� �̺�Ʈ�� �̷���� ������ �� ������ ���� ���޵˴ϴ�. ����Ʈ ���� â ����Ű�� Ctrl + Q �Դϴ�. ��ũ������ ���迡�� ��ſ� �ð��� �ǽñ� �ٶ�� ������ ĳ���͵� Ű��� ������ ���� �� �ִ� ��ȸ�� ��ġ�� ������.";
	(*g_pGameStringTable)[STRING_MESSAGE_DAUM_EVENT_2] = "��ũ������ �غ��� �ʺ��� �̺�Ʈ! %d ������ �����ϼ̱���. %s ���ڸ� �־��Ƚ��ϴ�. Ctrl + Q �� ���� Ȯ���� ������. ������ �����Ͻ� ���ڰ� �ִٸ� �������� �����Ͻ� �� �ֽ��ϴ�. �� �����е鲲 �帰 �������� �ð������� �ɷ��ִ� �������Դϴ�. ���� ���� ������ �ִ� �����۵� ���� ���� ������ ���������ν� �̺�Ʈ�� ���� ���޵� �̺�Ʈ �������� ����� �ŷ��� ��ȯ�� �Ұ����ϴ�ϴ�. ���� ���� �� ���� �������� ���Ͻø� NPC�� ���Ͽ� �ǸŸ� �Ͻ� �� �ֽ��ϴ�. ������ �ϴܿ� ���ø� ������ ���� �ִ� �ð��� ǥ�õ˴ϴ�. ���� �� �ð��� �����е��� ��ũ���� ���带 ���� ��ŵ� �ǽð����� ����Ǳ� ������ �� �ð��� �����ϰ� ����Ͻñ� �ٶ��ϴ�. �׷� ����ؼ� ��ſ� �ð��ǽñ� �ٶ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_DAUM_EVENT_3] = "%d ������ �����ϼ̱���. Ctrl + Q �� ���� Ȯ���� ������. ������ �����Ͻ� ���ڰ� �ִٸ� �������� �����Ͻ� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[STRING_MESSAGE_DAUM_EVENT_BOX1] = "������";
	(*g_pGameStringTable)[STRING_MESSAGE_DAUM_EVENT_BOX2] = "��Ȳ��";
	(*g_pGameStringTable)[STRING_MESSAGE_DAUM_EVENT_BOX3] = "�����";
	(*g_pGameStringTable)[STRING_MESSAGE_DAUM_EVENT_BOX4] = "�ʷϻ�";
	(*g_pGameStringTable)[STRING_MESSAGE_DAUM_EVENT_BOX5] = "�Ķ���";
	(*g_pGameStringTable)[STRING_MESSAGE_DAUM_EVENT_BOX6] = "����";
	(*g_pGameStringTable)[STRING_MESSAGE_DAUM_EVENT_BOX7] = "�����";
	(*g_pGameStringTable)[STRING_MESSAGE_DAUM_EVENT_BOX8] = "������";


	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_PERCEPTION] = "��� +2";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_STONE_OF_SAGE] = "����(INT) +5";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_FOOT_OF_RANGER] = "��ø��(DEX) +5";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_WARRIORS_FIST] = "��(STR) +5";

    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_ACID_INQUIRY] = "�ֽõ�(Acid) ���� +10%";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_BLOODY_INQUIRY] = "����(Blood) ���� +10%";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_CURSE_INQUIRY] = "Ŀ��(Curse) ����+10%";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_POISON_INQUIRY] = "������(Poison) ���� +10%";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_INQUIRY_MASTERY] = "��� ���� +3%";

    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_POWER_OF_SPIRIT] = "�����(Protection) 5%����";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_WIND_OF_SPIRIT] = "ȸ����(Defense) 5%����";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_PIXIES_EYES] = "���߷�(To hit) 5%����";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_GROUND_OF_SPIRIT] = "������(MP) 5%����";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_FIRE_OF_SPIRIT] = "ũ��Ƽ��(Critical) ���ݷ� 5%����";

    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_EVOLUTION_IMMORTAL_HEART] = "�����(HP) 5% ����";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_BEHEMOTH_ARMOR_2] = "ȸ����(Defense) 5%���� ";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_DRAGON_EYE_2] = "���߷�(To hit) 5%����";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_EVOLUTION_RELIANCE_BRAIN] = "������(MP) 5%����";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_HEAT_CONTROL] = "ũ��Ƽ��(Critical) ���ݷ� 5%����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_ACID_MASTERY] = "���� �ֽõ�(Acid) ���� 10% ����";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_BLOODY_MASTERY] = "���� ����(Blood) ���� 10% ����";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_CURSE_MASTERY] = "���� Ŀ��(Curse) ���� 10%����";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_POISON_MASTERY] = "���� ������(Poison) ���� 10%����";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_SKILL_MASTERY] = "���� ��� ���� 3% ����";

    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_SALAMANDERS_KNOWLEDGE] = "�Ұ迭 ���� +1";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_UNDINES_KNOWLEDGE] = "���迭 ���� +1";
    (*g_pGameStringTable)[UI_STRING_MESSAGE_RANK_BONUS_GNOMES_KNOWLEDGE] = "�����迭 ���� +1";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SIEGE_ATTACK] = "(������)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SIEGE_DEFENSE] = "(������)";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_LOGINED] = "(��������)";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_LIST_ID] = "���̵�(ID)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_LIST_SERVER] = "���� ����(SERVER)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_LIST_GRADE] = "���(GRADE)";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_COMMAND_WINDOW] = "�� ���(Team Command)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_LIST_WINDOW] = "�� ���(Team List)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_WAIT_LIST_WINDOW] = "��� �� ���(Wait Team List)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TEAM_UNION_WINDOW] = "�� ����(Team Union)";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLAN_COMMAND_WINDOW] = "Ŭ�� ���(Clan Command)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLAN_LIST_WINDOW] = "Ŭ�� ���(Clan List)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLAN_WAIT_LIST_WINDOW] = "��� Ŭ�� ���(Wait Clan List)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CLAN_UNION_WINDOW] = "Ŭ�� ����(Clan Union)";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_COMMAND_WINDOW] = "��� ���(Guild Command)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_LIST_WINDOW] = "��� ���(Guild List)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_WAIT_LIST_WINDOW] = "��� ��� ���(Wait Guild List)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GUILD_UNION_WINDOW] = "��� ����(Guild Union)";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_DESC1] = "������ ���ձ�带 �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_DESC2] = "������ ���ձ�带 Ż���մϴ�. ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_DESC3] = "������ ���ձ�带 �߹��մϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_ALREADY_IN_UNION] = "�̹� ��忡 ������ �߽��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_ALREADY_OFFER_SOMETHING] = "�̹� ���ձ�忡 ��û�Ǿ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_TARGET_IS_NOT_MASTER] = "������ �����Ͱ� �ƴմϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_NOT_IN_UNION] = "���տ� ���Ե� ���°� �ƴմϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_MASTER_CANNOT_QUIT] = "������ ������ ���� ������ Ż���� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_NO_TARGET_UNION] = "�ش��ϴ� ������ �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_NOT_YOUR_UNION] = "�ش� ���� �Ҽ��� �ƴմϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_SOURCE_IS_NOT_MASTER] = "��û�� ����� �����Ͱ� �ƴմϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_JOIN_ASK] = "�� ���ձ�忡 �ҼӵǸ� �ٸ� ���ձ�忡 ���� ������ �� �����ϴ�.   �����Ͻðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_MESSAGE_OK] = "���������� ó���Ǿ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_MESSAGE_REFUSE] = "���� ��帶���Ͱ� ���� �ϼ̽��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_MESSAGE_SUCCESS] = "���������� ���ձ�尡 â���Ǿ����ϴ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_LEAVE_ASK] = "���� Ż�� �Ͻðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_LEAVE_MSG] = "��帶������ ������ ��û�Ѵ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_LEAVE_MSG2] = "���� ��� Ż���Ѵ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_LEAVE_OK] = "Ż�� ��û�Ͻð� ��帶���Ͱ� ������ ��� ���Ƽ�� �����ϴ�. ��û�Ͻðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_LEAVE_CANCEL] = "���� ��� Ż�� ģû�Ͻø� �ٷ� Ż�� ���������� ���Ƽ�� �ֽ��ϴ�. �ٷ� Ż���Ͻðڽ��ϱ�?";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_DEPORT_ASK] = "������ �߹��� ����Ͻʴϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_DEPORT_OK] =  "%S ���� ������ �߹�Ǿ����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_UNION_JOIN_MSG] =  "%s ��尡 ���ձ�� ������ ��û�մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_UNION_DEPORT_MSG] =  "%s ��尡 ���ձ�� Ż�� ��û�մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_UNION_PENALTY] =  "���ձ�忡 ������ Ż���� ����� �ֽ��ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ASKING_RECALL] =  "%s ���� ȣ���Ͻðڽ��ϱ�?";
	
	(*g_pGameStringTable)[UI_STRING_LEARN_SKILL_LEVEL] =  "��ų ��� ���� : %d ����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_LEAVE_ACCEPT] =  "���� Ż�� �����մϴ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOTAL_GUILD_LEAVE_DENY] =  "���� Ż�� �����մϴ�.";


	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUEST_UNION_ERROR_1] =  "��� �����͸��� ���ս�û�� �� �� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUEST_UNION_ERROR_2] =  "�̹� ���տ� ���ԵǾ� �ֽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUEST_UNION_ERROR_3] =  "������ �����Ͱ� �ƴմϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_UNION_ERROR_NO_SLOT] =  "������ �� �ڸ��� �����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_BLOOD_BIBLE] = "���� ���� ¡ǥ�� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RENT_BLOOD_BIBLE] = "���� ���� ¡ǥ�� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RENT_BLOOD_BIBLE2] = "%s�� ¡ǥ�� �����ϴ�. (%s)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RENT_LATER_BLOOD_BIBLE] = "������ �����ڽ��ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANGER_SAY] = "Ranger/";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MODIFY_TAX_OK] = "������ ���������� ���� �Ǿ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MODIFY_TAX_FAIL] = "���� ���濡 ���� �Ͽ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MODIFY_TAX] = "������ ������ �Է��մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_RANGER_SAY2] = "������";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_REMOVE_CURSE_1] = "��";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REMOVE_CURSE_2] = "���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REMOVE_CURSE_3] = "�����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REMOVE_CURSE_4] = "����ؿ�";

	(*g_pGameStringTable)[STRING_MESSAGE_RACE_WAR_STARTED_IN_OTHER_SERVER] = "1�� �������� ������ ���۵Ǿ����ϴ�. ���￡ �����Ͻ÷��� 1�������� �̵��Ͻø� �˴ϴ�.  �������� ���￡�� ���� ���� ������ Ȯ���ؾ��մϴ�.";


	(*g_pGameStringTable)[UI_STRING_MESSAGE_APPOINT_SUBMASTER] =  "���� �����ͷ� �Ӹ��մϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_SKILL_DELETE] =  "��ų ��� ����Ʈ ȸ�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_SKILL_DELETE] =  "��ų ��� ����Ʈ ȸ�� �Ұ���";

	(*g_pGameStringTable)[STRING_MESSAGE_CANNOT_SKILLTREE_DELETE] =  "����Ʈ�� ȸ���� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOO_MANY_MEMBER] =  "����� 50���� �Ѿ� ������ �� �����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CONFIRM_DOWN_SKILL2] =  "%s ��ų�� ��ų ��� ����Ʈ�� ȸ�� �մϴ�. �Ҹ� ����� $%s�Դϴ�. �����Ͻðڽ��ϱ�?";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_UNION_CHATTING] =  "����ä�� �ϱ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SHOW_UNION_CHATTING] =  "����ä�� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_SHOW_UNION_CHATTING] =  "����ä�� �Ⱥ���";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_USE_SIEGE_FOR_RESURRECT] = "������ �տ��� ��Ȱ�մϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_GET_POINT] = "�Ŀ�¯ ����Ʈ ��������";
	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_POINT] = "�� �Ŀ�¯ ���� ����Ʈ";
	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_AVAILABLE] = "��ȯ ������ ����Ʈ";
	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_NUMBER_1] = "�ڵ���";
	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_NUMBER_2] = "��ȣ";
	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_GET_POINT_HELP] = "�Ŀ�¯ ����Ʈ�� �����ɴϴ�.";
	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_EXCHANGE_HELP] = "�Ŀ�¯ ����Ʈ�� �������� ��ȯ�մϴ�.";
	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_REQUEST_OK] = "�Ŀ�¯ ����Ʈ�� ���������� ����Ǿ����ϴ�. ���۵� ����Ʈ : %d ��";


	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_ERROR_NO_MEMBER] = "�Ŀ�¯ ȸ���� �ƴմϴ�. www.powerzzang.com ���� Ȯ���Ͻñ� �ٶ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_ERROR_SERVER_ERROR] = "�Ŀ�¯ ������ �̻��� �ֽ��ϴ�.�ٽ� �ѹ� �õ��غ��ð� �ȵǸ� www.powerzzang.com ���� Ȯ���Ͻñ� �ٶ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_ERROR_PROCESS_ERROR] = "�Ŀ�¯ DB�� �̻��� �ֽ��ϴ�.�ٽ� �ѹ� �õ��غ��ð� �ȵǸ� www.powerzzang.com ���� Ȯ���Ͻñ� �ٶ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_ERROR_NO_POINT] = "������ �Ŀ�¯ ����Ʈ�� ���ڶ��ϴ�. www.powerzzang.com ���� Ȯ���Ͻñ� �ٶ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_ERROR_NO_MATCHING] = "��ġ�� ������ ã�� �� �����ϴ�. www.powerzzang.com ���� Ȯ���Ͻñ� �ٶ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_POWER_JJANG_ERROR_CONNECT] = "�Ŀ�¯ ������ ���ῡ �̻��� �ֽ��ϴ�.";


	(*g_pGameStringTable)[UI_STRING_MESSAGE_UTIL] = "���(Utility)";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PERSONAL_STORE] = "���� ����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_POWER_JJANG] = "�Ŀ�¯";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_SELL_MONEY_IN_DIALOG] = "������ �� ������ �Է��ϼ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PERSNALSHOP_MESSAGE]  = "���λ��� ���� �޼����� �Է��ϼ���!!";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PERSNALSHOP_OK] = "���λ����� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PERSNALSHOP_CANCEL] = "���λ����� �ݽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PERSNALSHOP_WRITE_MESSAGE] = "���λ��� ����޼��� �ۼ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_FIND_STORE] = "�ش� �Ǹ��ڸ� ã�� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_STORE_CLOSED] = "������ �̹� �������ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_NOT_FOUND] = "�ش� �������� �̹� �ǸŵǾ��ų� �Ǹ��ڿ� ���� öȸ�Ǿ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_TOO_MUCH_MONEY] = "�Ǹ��ڰ� �ʹ� ���� ���� ������ �־ �� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ALREADY_DISPLAYED] = "�̹� ������ �������Դϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PERSNAL_DEFAULT_MESSGE] = "�پ��� ��ǰ�� �ֽ��ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GAMEMONEY_WITH_HANGUL] = "���� �Ӵ� �ѱ� ���� ǥ��";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANTE_0] = "ȣ�罺 %d���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANTE_1] = "��Ʈ %d���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANTE_2] = "����Ʈ %d���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANTE_3] = "���ø��� %d���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANTE_4] = "��Ʈ %d���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANTE_5] = "��Ʈ %d���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANTE_6] = "�Ժ� %d���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANTE_7] = "�� %d���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANTE_8] = "�� %d���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANTE_9] = "��Ÿ %d���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANTE_10] = "�� %d���";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_PDA] = "ĳ�� ���ù��� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_SHOULDER] = "����ƸӸ� �����մϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_DERMIS] = "������ �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_PERSONA] = "������ �����մϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_FASCIA] = "�㸮����� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EQUIP_MITTEN] = "�尩�� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHINGHO] = "Īȣ";
	
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWAP_ADVANCEMENT_ITEM] =	"���� ���������� ��ȯ�Ͻ� �������� Ŭ�����ּ���.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWAP_CONFIRM] = "���� ���������� ��ȯ �Ͻðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWAP_ERROR] = "�������� �ʾƼ� ������ ��ȯ�� �ȵ˴ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SWAP_ADVANCEMENT_ITEM_ERROR] = "���� ���������� ��ȯ�� �� �����ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAMPAIGN_HELP_REQUEST] = "��� �Ͻ� �ݾ��� �Է��� �ֽʽÿ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAMPAIGN_HELP_THANKS] = "����� �ֽ� �ݾ��� ������ �ձ��� �ʿ��� �ҿ��� �̿��� ���� �����ϰ� ������ ���Դϴ�. ��ݿ� ������ �ּż� �����մϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAMPAIGN_HELP_UNITS_SLAYER] = "����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAMPAIGN_HELP_UNITS_VAMPIRE] = "�ֵ�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAMPAIGN_HELP_UNITS_OUSTERS] = "�ڵ�";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_ADVANCEMENT_LEVEL_0] = "ȣ�罺 %d��� �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_ADVANCEMENT_LEVEL_1] = "��Ʈ %d��� �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_ADVANCEMENT_LEVEL_2] = "����Ʈ %d��� �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_ADVANCEMENT_LEVEL_3] = "���ø��� %d��� �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_ADVANCEMENT_LEVEL_4] = "��Ʈ %d��� �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_ADVANCEMENT_LEVEL_5] = "��Ʈ %d��� �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_ADVANCEMENT_LEVEL_6] = "�Ժ� %d��� �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_ADVANCEMENT_LEVEL_7] = "�� %d��� �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_ADVANCEMENT_LEVEL_8] = "�� %d��� �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_ADVANCEMENT_LEVEL_9] = "��Ÿ %d��� �̻�";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUIRE_ADVANCEMENT_LEVEL_10] = "�� %d��� �̻�";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANCEMENT_JOB_BLADE] = "���ø���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANCEMENT_JOB_SWORD] = "�����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANCEMENT_JOB_SOLDER] = "�����";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANCEMENT_JOB_HEAL] = "������Ʈ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANCEMENT_JOB_ENCHANT] = "�׷���";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANCEMENT_JOB_VAMPIRE] = "�������";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANCEMENT_JOB_COMBAT] = "���佺";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANCEMENT_JOB_EARTH] = "�̱״ϼ� ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANCEMENT_JOB_FIRE] = "����� ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADVANCEMENT_JOB_WATER] = "�׶�뽺 ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_DO_NOT_SHOW_PERSNALSHOP_MSG] = "���� ���� �޼��� �� ����";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_REQUEST_GET_EVENT_ITEM] = "���� ĳ���ͷ� �Ĺ� �̺�Ʈ �������� �����ðڽ��ϱ�?";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_GET_EVENT_ITEM_RECEIVE_OK] = "�Ĺ� �̺�Ʈ �������� �޾ҽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GET_EVENT_ITEM_RECEIVE_ALREADY] = "�̹� �Ĺ� �̺�Ʈ �������� �����ϼ̽��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GET_EVENT_ITEM_RECEIVE_FAIL] = "�Ĺ� �̺�Ʈ ������ �ޱ⿡ �����Ͽ����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GET_EVENT_ITEM_NOT_EVENT_USER] = "�Ĺ� �̺�Ʈ �ش� ������ �ƴմϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_GET_EVENT_ITEM_NOTICE] = "�����մϴ�! Come back, 2005 �̺�Ʈ ������̽ʴϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_FAIL_OPEN_WEBPAGE] = "�� �������� �� �� �����ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_USE_ADVANCEMENTCLASS] = "������ ������ ����� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_USE_HIGH_GRADE] = "6�� �̻� �������� ��æƮ �� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_USE_ADVANCEMENT_ITEM] = "���� ���� �������� ��æƮ �� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CANNOT_USE_OVER_TWO_OPTION] = "�ɼ��� 2�� �̻��� �������� ��æƮ �� �� �����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_WEDDING_CONTRIBUTION_REQUEST] = "���Ǳ� �ݾ��� ���� �־��ּ���.\n(�ݾ� 10,000 ���� / �ּ� 10,000 ~ �ִ� 100,000 ).";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_WEDDING_CONTRIBUTION_THANKS] = "�����մϴ�. �� ������ �帮�ڽ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_WEDDING_CONTRIBUTION_FAIL] = "����� ��ܿ� �ֱ���. �ߺ��Ͽ� ��ε��� �ʽ��ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NETMARBLE_AGREEMENT] = "��  �������� ��3�� ������ ���� ����\n\nCJ���ͳ�(��)�� �̿����� ���������� �̺�Ʈ ��� �� ���� Ȯ�ν�, ���� ������ ���� Ȯ���� �ʿ��� ��, ȸ���� ������ ������ ó���� �ʿ��� �ú� ������ ���߻��� (��)������  �������θ�Ʈ�� �����˴ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_I_AGREE] = "�� ���뿡 �����մϴ�.";	

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CAN_NOT_CONNECT_AGREEMENT] = "����� ����� �������� �ʾұ� ������ ������ �� �� �����ϴ�.";
	
	(*g_pGameStringTable)[UI_STRING_MESSAGE_USE_ADVANCEMENTCLASS] = "�������� ���� ĳ���ʹ� ����� �� �����ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_USE_NOTADVANCEMENTCLASS] = "99���ϳ� ĳ���ͳ� ����ĳ���ʹ� ����� �� �����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_ADD_COLOR] = "�̹� ����� ���� �Դϴ�. ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_EFFECT_APPLY] = "ȿ���� ����Ǿ����ϴ�. ";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_SCROLL_EFFECT_ITEMDEL] = "���� ��ũ�� ȿ���� ����� �� �̿� �����մϴ�. ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_USE_ITEM_DEL] = "�ѹ� ����ϸ� �ش� �������� ������� �˴ϴ�.����Ͻðڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOTUSE_ITEM] = "����� �� ���� ������ �������Դϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_PORTAL_ITEM_DESC] = "����� �� ���� ���� �ֵ尡 �Һ�˴ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_PORTAL_ITEM_NOUSE] = "�ֵ尡 �����ؼ� ��(Seal)�� ����� �� �����ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHARGE_DESC] = "������ ���� ��������� �ٸ��ϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHARGE_ITEM_NOUSE] = "�����Ͽ� ����� �� �ֽ��ϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_SUMMER_COMEBACK_LOGIN_AFTER] = "�����մϴ�! Summer COME BACK, 2005 �̺�Ʈ ������̽ʴϴ�.\n\n�̺�Ʈ�Ⱓ �� �α��� �������� 5�ϰ� �����̾� ������ ���� �� �ִ�ϴ�.\n\n���� �̺�Ʈ ��� �����۵� ȹ���Ͻ� �� ������ �ش� ������NPC�� ã�ư��ñ� �ٶ��ϴ�.\n\n(��, �̺�Ʈ �������� �� ������ ��ĳ���Ϳ� ���ؼ��� ���� �� �ֽ��ϴ�.)\n\n*�̺�ƮNPC\n\n�����̾�: ũ����ƾ (�����ڱ��1��)\n\n�����̾�: �꾲 (����������)\n\n�ƿ콺����: ȣ�� (�ƿ콺���� ��������)\n\n";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SUMMER_COMEBACK_SETTLEMENT_AFTER] = "������ ���������� �̷�������ϴ�. ���� �����̾� ������ �����ø鼭 ��ũ������ ���� ����ְ� ���� �� �ְ� �Ǿ����ϴ�.\n\n�̹� �̺�Ʈ�� ���� ���ʽ� �������� �ٵ����Ͽ��� �Ǹ��ϰ� �ִ� ������Ʈ�� ������ �帮�� �ֽ��ϴ�.\n\n(��, �̺�Ʈ �������� �� ������ ��ĳ���Ϳ� ���ؼ��� ���� �� �ֽ��ϴ�.)\n\n*�̺�ƮNPC\n\n�����̾�: ũ����ƾ (�����ڱ��1��)\n\n�����̾�: �꾲 (����������)\n\n�ƿ콺����: ȣ�� (�ƿ콺���� ��������)\n\n�׷� ������Ʈ �������� �԰� ��ũ������ 200% ��ܺ�����.\n\n";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_SUMMER_COMEBACK_RECOMMENDER] = "�����մϴ�. Summer COME BACK, 2005 �̺�Ʈ ����ڷκ��� ��õ �����̽��ϴ�.\n\n��õ�ο��Դ� ������ ������ �־����� �̺�Ʈ NPC�� ã�ư��� �����ñ� �ٶ��ϴ�.\n\n(��, �̺�Ʈ �������� �� ������ ��ĳ���Ϳ� ���ؼ��� ���� �� �ֽ��ϴ�.)\n\n*�̺�ƮNPC\n\n�����̾�: ũ����ƾ (�����ڱ��1��)\n\n�����̾�: �꾲 (����������)\n\n�ƿ콺����: ȣ�� (�ƿ콺���� ��������)\n\n�����մϴ�.";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BURST_ATTACK] = "������ ���� %d / %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BURST_DEFENSE] = "����� ���� %d / %d";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_BLOOD_BURST_PARTY] = "��Ƽ�� ���� %d / %d";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_PET_ATTRIBUTE_CLEANER_POTION] = "�� �Ӽ��� �ʱ�ȭ �ϰڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_PET_ATTRIBUTE_CLEANER_POTION] = "�Ӽ��� �ʱ�ȭ �� �� ���� �����Դϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MASK_OF_MONSTER] = "� ���ͷ� ������ �� �𸨴ϴ�. ���Ž�ų���?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MAGICAL_PET_CHANGER] = "���� �����ϰڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_ORNAMENTS_ITEM] = "���⸦ ��ȭ�ϰڽ��ϱ�? ";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_GRADE_SKILL_CLEANER_POTION] = "��޽�ų�� �ʱ�ȭ �ϰڽ��ϱ�?";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_NOT_ADD_MULTIPACK4X6] = "�̹� 2x4 ���� ������ �ִ� ĳ�����Դϴ�.";
	(*g_pGameStringTable)[UI_STRING_MESSAGE_MAGICAL_PET_CHANGER_ACTIVE] = "������ �� Ȱ��ȭ :";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_ITEM_STRENGTHENING] = "�� �������� ��ȭ�ϰڽ��ϱ�?";

	(*g_pGameStringTable)[UI_STRING_MESSAGE_CHILDGUARD_DENYED_NOTUSE] = "�� ���ӹ��� 18�� �̿밡 ���ӹ��� û�ҳ��� �̿��� �� �����ϴ�";

	

}

#endif