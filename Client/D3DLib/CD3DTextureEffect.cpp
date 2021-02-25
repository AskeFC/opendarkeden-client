//----------------------------------------------------------------------
// CD3DTextureEffect.cpp
//----------------------------------------------------------------------

#include "CD3DTextureEffect.h"

//----------------------------------------------------------------------
//
// constructor / destructor
//
//----------------------------------------------------------------------
CD3DTextureEffect::CD3DTextureEffect()
{
	// �̰� �������� ������..
	// �̷��� �ϴϱ�.. � video card������ �ܰ� �κп� ���� ���ܼ�.. T_T;
	//m_TextureVertices[0] = D3DTLVERTEX(D3DVECTOR(0, 0, 0), 1, 0xffffffff, 0, 0.0f, 0.0f);
	//m_TextureVertices[1] = D3DTLVERTEX(D3DVECTOR(1, 0, 0), 1, 0xffffffff, 0, 1.0f, 0.0f);
	//m_TextureVertices[2] = D3DTLVERTEX(D3DVECTOR(0, 1, 0), 1, 0xffffffff, 0, 0.0f, 1.0f);
	//m_TextureVertices[3] = D3DTLVERTEX(D3DVECTOR(1, 1, 0), 1, 0xffffffff, 0, 1.0f, 1.0f);

	m_TextureVertices[0] = D3DTLVERTEX(D3DVECTOR(0, 0, 0), 1, 0xffffffff, 0, 0.005f, 0.005f);
	m_TextureVertices[1] = D3DTLVERTEX(D3DVECTOR(1, 0, 0), 1, 0xffffffff, 0, 1.0f, 0.005f);
	m_TextureVertices[2] = D3DTLVERTEX(D3DVECTOR(0, 1, 0), 1, 0xffffffff, 0, 0.005f, 1.0f);
	m_TextureVertices[3] = D3DTLVERTEX(D3DVECTOR(1, 1, 0), 1, 0xffffffff, 0, 1.0f, 1.0f);
}

CD3DTextureEffect::~CD3DTextureEffect()
{
}

//----------------------------------------------------------------------
//
// member functions
//
//----------------------------------------------------------------------
//----------------------------------------------------------------------
// Draw
//----------------------------------------------------------------------
void
CD3DTextureEffect::DrawEffect2D(RECT* pRect)
{
	//------------------------------------------------
	// ��ǥ ����
	//------------------------------------------------
	m_TextureVertices[0].sx = (float)pRect->left;
	m_TextureVertices[0].sy = (float)pRect->top;
	m_TextureVertices[1].sx = (float)pRect->right;
	m_TextureVertices[1].sy = (float)pRect->top;
	m_TextureVertices[2].sx = (float)pRect->left;
	m_TextureVertices[2].sy = (float)pRect->bottom;
	m_TextureVertices[3].sx = (float)pRect->right;
	m_TextureVertices[3].sy = (float)pRect->bottom;
	
	//------------------------------------------------
	// ���
	//------------------------------------------------
	CDirect3D::GetDevice()->DrawPrimitive(D3DPT_TRIANGLESTRIP, 
							D3DFVF_TLVERTEX, 
							m_TextureVertices, 
							4, 0);
}
