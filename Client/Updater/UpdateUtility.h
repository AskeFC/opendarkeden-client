//----------------------------------------------------------------------
// UpdateUtility.h
//----------------------------------------------------------------------

#ifndef	__UPDATEUTILITY_H__
#define	__UPDATEUTILITY_H__

//----------------------------------------------------------------------
// Update Utility Functions
//----------------------------------------------------------------------
//----------------------------------------------------------------------
// Permission üũ - �ٸ� directory���� ������ ���ϵ���
//----------------------------------------------------------------------
bool		UUFHasPermission(const char* filename);


//----------------------------------------------------------------------
// Directory ����/����
//----------------------------------------------------------------------
bool		UUFCreateDirectory(const char* dirName);
bool		UUFDeleteDirectory(const char* dirName);


//----------------------------------------------------------------------
// File		Copy / Move / Delete / Rename(Directory�� ����)
//----------------------------------------------------------------------
bool		UUFCopyFile(const char* FilenameSource, const char* FilenameTarget);
bool		UUFMoveFile(const char* FilenameSource, const char* FilenameTarget);
bool		UUFDeleteFile(const char* FilenameTarget);
bool		UUFDeleteFiles(const char *path, const char *fileext);
bool		UUFRenameFile(const char* FilenameSource, const char* FilenameTarget);


//----------------------------------------------------------------------
// Append Pack (with Index)
//----------------------------------------------------------------------
// IndexFile���� NULL�̸� Index�� �߰����� �ʴ´�.
//----------------------------------------------------------------------
bool		UUFAppendPack(const char* FilenameAdd, const char* FilenameOriginal,
						const char* FilenameIndexAdd=0, const char* FilenameIndexOriginal=0);

//----------------------------------------------------------------------
// Delete SpritePack
//----------------------------------------------------------------------
// SpritePack���� Ư���� Sprite���� �����Ѵ�.
//----------------------------------------------------------------------
//bool		UUFDeleteSpritePack(const char* FilenameID, const char* FilenameOriginal);

//----------------------------------------------------------------------
// Update SpritePack
//----------------------------------------------------------------------
// SpritePack���� Ư���� sprite�鸸 ��ü�Ѵ�.
//----------------------------------------------------------------------
//bool		UUFUpdateSpritePack(const char* FilenameNew, 
//								const char* FilenameID, 
//								const char* FilenameOriginal);

//----------------------------------------------------------------------
// Append Info
//----------------------------------------------------------------------
bool		UUFAppendInfo(const char* FilenameAdd, const char* FilenameOriginal);

//----------------------------------------------------------------------
// Make SpritePack Index
//----------------------------------------------------------------------
// SpritePack�� load�ؼ� index�� �����Ѵ�.
//----------------------------------------------------------------------
//bool		UUFMakeSpritePackIndex(const char* Filename);

#endif