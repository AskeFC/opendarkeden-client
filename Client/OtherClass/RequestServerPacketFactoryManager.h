//////////////////////////////////////////////////////////////////////
// 
// Filename    : RequestServerPacketFactoryManager.h 
// Written By  : reiot@ewestsoft.com
// Description :
// 
//////////////////////////////////////////////////////////////////////

#ifndef __REQUEST_SERVER_PACKET_FACTORY_MANAGER_H__
#define __REQUEST_SERVER_PACKET_FACTORY_MANAGER_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"


//////////////////////////////////////////////////////////////////////
//
// class RequestServerPacketFactoryManager
//
//////////////////////////////////////////////////////////////////////

class RequestServerPacketFactoryManager {

public :
	
	// constructor
	RequestServerPacketFactoryManager () throw ();
	
	// destructor
	~RequestServerPacketFactoryManager () throw ();

	// ��Ŷ���丮�Ŵ����� �ʱ�ȭ�Ѵ�.
	// ���Ӽ�����ü�� init()���� ȣ��ȴ�.
	void init () throw ( Error );
	
	// ���丮 ��ü�� Ư�� �ε����� �߰��Ѵ�.
	void addFactory ( PacketFactory * pFactory ) throw ( Error );
	
	// ��Ŷ���̵�� ��Ŷ��ü�� �����Ѵ�.
	Packet * createPacket ( PacketID_t packetID ) throw ( InvalidProtocolException , Error );

	#ifdef	__DEBUG_OUTPUT__
		// Ư�� ��Ŷ�� �ִ� ũ�⸦ �����Ѵ�.
		std::string getPacketName ( PacketID_t packetID ) throw ( InvalidProtocolException , Error );

		// get debug string
		std::string toString () const throw ();
	#endif

	// Ư�� ��Ŷ�� �ִ� ũ�⸦ �����Ѵ�.
	PacketSize_t getPacketMaxSize ( PacketID_t packetID ) throw ( InvalidProtocolException , Error );

	

private :
	
	// ��Ŷ���丮�� �迭
	PacketFactory ** m_Factories;
	
	// ��Ŷ���丮�迭�� ũ��
	ushort m_Size;

};

extern RequestServerPacketFactoryManager * g_pRequestServerPacketFactoryManager;

#endif
