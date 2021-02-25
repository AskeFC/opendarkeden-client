//----------------------------------------------------------------------
// CD3DTextureEffect.h
//----------------------------------------------------------------------
// CDirect3D�� �̿��ؼ�..
// 2D��ǥ���� �簢 ������ texture�� ������ ������� effect�� ǥ���Ѵ�.
//
// Draw..()�� ����ɶ���
// BeginScene()�� �Ǿ� �ִ� ���¾�� �ϰ�..
// ������ Texture�� �����Ǿ� �ִٰ� �����Ѵ�.
//----------------------------------------------------------------------

#ifndef __CD3DTEXTUREEFFECT_H__
#define __CD3DTEXTUREEFFECT_H__

#include "CDirect3D.h"

class CD3DTextureEffect {
	public :
		CD3DTextureEffect();
		~CD3DTextureEffect();

		void		DrawEffect2D(RECT* pRect);

	protected :
		D3DTLVERTEX					m_TextureVertices[4];
};

#endif


