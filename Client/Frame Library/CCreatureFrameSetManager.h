//----------------------------------------------------------------------
// CCreatureFrameSetManager.h
//----------------------------------------------------------------------
//
// CreatureFrameSet�� �����ϴ� class
//
//
//----------------------------------------------------------------------

#ifndef	__CCREATUREFRAMESETMANAGER_H__
#define	__CCREATUREFRAMESETMANAGER_H__

#include "CFrameSetManager.h"
#include "CFramePack.h"

class CCreatureFrameSetManager : public CFrameSetManager {
	public :
		CCreatureFrameSetManager();
		~CCreatureFrameSetManager();

	protected :
		//--------------------------------------------------------
		// CreatureFrameSet�� ���õ� SpriteID�� �����ؼ�
		// SpritePack IndexFile�κ��� SpriteSet IndexFile�� �����Ѵ�.
		//--------------------------------------------------------
		bool	SaveSpriteSetIndex(CCreatureFramePack* pCreatureFramePack, class ofstream& setIndex, class ifstream& packIndex);
};

#endif

