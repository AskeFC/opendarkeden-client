//----------------------------------------------------------------------
// CThingFrameSetManager.h
//----------------------------------------------------------------------
//
// AnimationFrameSet�� �����ϴ� class
//
//
//----------------------------------------------------------------------

#ifndef	__CANIMATIONFRAMESETMANAGER_H__
#define	__CANIMATIONFRAMESETMANAGER_H__

#include "CFrameSetManager.h"
#include "CFramePack.h"

class CAnimationFrameSetManager : public CFrameSetManager {
	public :
		CAnimationFrameSetManager();
		~CAnimationFrameSetManager();

	protected :
		//--------------------------------------------------------
		// AnimationFrameSet�� ���õ� SpriteID�� �����ؼ�
		// SpritePack IndexFile�κ��� SpriteSet IndexFile�� �����Ѵ�.
		//--------------------------------------------------------
		bool	SaveSpriteSetIndex(CAnimationFramePack* pAnimationFramePack, class ofstream& setIndex, class ifstream& packIndex);
};

#endif

