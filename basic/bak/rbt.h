/*-----------------------------------------------------------------------------

	rbt.h

	RBT (RaBbiT).
	Data Base file format.

	2000.6.8. KJTINC

-----------------------------------------------------------------------------*/

#ifndef __RBT_H__
#define __RBT_H__

#include "typedef.h"
#include <fstream.h>
#include <windows.h> // for MAX_PATH & file search

typedef DWORD data_id_t, data_count_t;
typedef int rbt_result_t;

//----------------------------------------------------------------------------
// Class RBT (RaBbiT)
// �ϳ��� RBT file�̴�.
//
// `���� ū �뷮�� RBT file�̶��, ���� ��� 1GB¥���� ��� open�ؼ� ���θ�
//  read�Ѵٸ�, 1GB�� Memory�� �ʿ�� �� ���̴�. ���� �ƹ��� ū RBT file��
//  �б� ���ؼ� header�� �ΰ�, header���� data id�� �˻��Ͽ� �ʿ�� �ϴ� data��
//	 read�Ѵ�. ���� RBT file�� ������ ������ ����.
//
//	 RBT:
//			| header(DATA_UNITs) | data 1 | data 2 | data 3| ... |
//
//
//  �� ������ header�ν� data�� �⺻���� ������ ������ ���� �� �ִ� ������ �ִ�.
//	 ���� header�� node���� ���� ��캸�� �����ϸ�, �� ������ data�� ���� �� �ִ�.
//
// `file�� RBT�� �߰��� �� �ִ�.
//----------------------------------------------------------------------------
#define RBT_OK									-1
#define RBT_FILE_EMPTY						0
#define RBT_OPEN_FAILED						1
#define RBT_MEMALLOC_FAILED				2
#define RBT_FILE_NOT_EXIST					3
#define RBT_NO_DATA							4
#define RBT_SIZE_ZERO						5
#define RBT_ARG_SIZE_ZERO					6
#define RBT_ARG_PTR_NULL					7
#define RBT_DATA_ID_NOT_FOUNT				8
#define RBT_SIZE_NOT_MATCH					9
#define RBT_ARG_TOO_BIG						10
#define RBT_READ_SIZE_BAD					11
#define RBT_ALREADY_EXIST					12

class RBT
{
private:
	struct FILE_LIST
	{
		char			file[MAX_PATH];
	};

	FILE_LIST *		m_p_file_list;
	int				m_file_list_size;

public:
	// �ϳ��� data�� ���� ����.
	struct DATA_HEAD
	{
		//
		// id
		//
		// id�� unique�ؾ� �ϸ�, (0 ~ 0xFFFFFFFF)�� ������ ���̴�. ���� �ִ� 0xFFFFFFFF����
		// data�� ������ �� ������, ũ�Ⱑ 0�� ���� �������� �����Ƿ� OS���� �����ϴ� file size��
		// �������Ѵ�.
		//
		// � id�� data�� �����ߴٸ�, �� data�� header�� DATA_HEAD�� �����Ǹ�, ������ id��
		// �ִ밪�� ���� ���Ŀ� ���� �� �ִ�. �׷��� replace�� data�� �ٲ۴�.
		//
		data_id_t	id;
		long	start_pos;
		size_t		size;

		//
		// pathfile
		//
		// file�ν� add�� ��� head�� file name(+path)�� ���´�. file name�� �����Ƿν�
		// ����� ������ ������ ����.
		//   
		// (1) ���� file�� ���� �ʰ� �� �� �ִ�.
		//	(2) �� file�� ������ �� �ִ�.
		//	(3) data id�� �ƴ� file�ν� data�� ã�� �� �ִ�.
		//
		size_t		file_len;
		char *		pathfile;
	};

private:
	data_count_t	m_count; // data�� �� ����
	DATA_HEAD *		m_p_header;

	char *			m_pathrbt; // this rbt file when open or save.

private:
	void	FreeFileList();
	void	FreeHeader();
	data_id_t GetDataID() const;

public:
	RBT(const char * sz_pathfile = NULL);
	~RBT();

//----------------------------------------------------------------------------
// Open/Save
//----------------------------------------------------------------------------
	rbt_result_t	Open(const char * sz_pathfile);
	rbt_result_t	Save(const char * sz_pathfile);

//----------------------------------------------------------------------------
// Add
//----------------------------------------------------------------------------
	rbt_result_t	AddFile(const char * sz_pathfile, data_id_t data_id);
	rbt_result_t	AddFile(const char * sz_pathfile);

//----------------------------------------------------------------------------
// Delete
//----------------------------------------------------------------------------
	rbt_result_t	Delete(data_id_t data_id);
	rbt_result_t	Delete(const char * sz_pathfile);

//----------------------------------------------------------------------------
// Replace/Update
//----------------------------------------------------------------------------
	rbt_result_t	Replace(data_id_t data_id, const char * sz_pathfile);
	rbt_result_t	Update(const char * sz_pathfile);

//----------------------------------------------------------------------------
// Read
//----------------------------------------------------------------------------
	rbt_result_t	Read(data_id_t data_id, char * &p_data, size_t size) const;
	rbt_result_t	ReadSequence(data_id_t sequence, char * &p_data, size_t size) const;

//----------------------------------------------------------------------------
// Get
//----------------------------------------------------------------------------
	size_t			GetDataSize(data_id_t data_id) const;
	size_t			GetDataSizeBySequence(data_id_t sequence) const;
	rbt_result_t	GetDataHead(data_id_t sequence, DATA_HEAD &head) const;
	data_count_t	Size() const;

//----------------------------------------------------------------------------
// Restore
//----------------------------------------------------------------------------
	rbt_result_t	Restore(data_id_t sequence) const;
	rbt_result_t	Restore() const;

//----------------------------------------------------------------------------
// Misc
//----------------------------------------------------------------------------
	rbt_result_t	MakeReport(const char * sz_pathfile) const;
	rbt_result_t	MakeFileList(const char * sz_pathfile) const;
	rbt_result_t	ExistFile(const char * sz_pathfile, data_id_t &data_id) const;
};

#endif