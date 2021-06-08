/*-----------------------------------------------------------------------------

	Typedef.h

	General type definition.
	`BOOL, TRUE, FALSE ������. C++ bool, true, false ���.

	19971226. KJTINC
	19991106.
	2000.8.5.
	
-----------------------------------------------------------------------------*/

#ifndef __TYPEDEF_H__
#define __TYPEDEF_H__

#define NULL						      0

#define NOT_SELECTED						-1

//
// type is all upper case and
// defined unsigned type
//
typedef unsigned char	BYTE;
typedef unsigned short	WORD;
typedef unsigned int	UINT;
typedef unsigned long   DWORD;

//
// id_t
//
// a identifier.
//
// Purpose:
//				General use.
//
typedef DWORD				id_t;

//
// Character type definition for DBCS(Double-Byte Character Set).
//
// (2000.10.4)
// Wide Chacter�� wchar_t�� ���� ������� �ʴ´�. ���� header �浹�� ���ϱ� ���ؼ� �ٸ� �̸���
// ����Ѵ�. �̰��� Unicode�� �����Ǹ� ������ wchar_t�� ��ü�Ǵ��� typedef wchar_t char_t��
// �ٲ� ���̴�.
//
typedef WORD char_t;

#endif
