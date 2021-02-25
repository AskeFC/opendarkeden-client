//-----------------------------------------------------------------------------
// CD3DObject.cpp
//-----------------------------------------------------------------------------

#include "CD3DObject.h"
//#include "d3dfile.h"

//-----------------------------------------------------------------------------
//
// contructor/destructor
//
//-----------------------------------------------------------------------------
CD3DObject::CD3DObject()
{
	SetOrigin();

	// Vertices
	m_nVertices = 0;
	m_pVertices = NULL;

	// Indices
	m_nIndices = 0;
	m_pIndices = NULL;

	// Material
	m_pMaterial = NULL;

	// Object Hierarchy
	m_pParent	= NULL;	

	// �޸𸮰� �����ִ� �����ΰ�?
	m_bNew = false;
}

CD3DObject::~CD3DObject()
{
	if (m_pMaterial!=NULL)
	{
		delete m_pMaterial;
	}

	// array�� �޸𸮿��� �����Ѵ�.
	Release();
}

//----------------------------------------------------------------------
//
// member functions
//
//----------------------------------------------------------------------

//----------------------------------------------------------------------
// Init
//----------------------------------------------------------------------
void
CD3DObject::Init(DWORD nVertices, DWORD nIndices)
{
	// ������ ���� ��� 
	if (nVertices==0 || nIndices==0) 
		return;

	// �ϴ� ����
	Release();

	// �޸� ���
	m_nVertices = nVertices;
	m_pVertices = new D3DVERTEX [m_nVertices];

	// �޸� ���
	m_nIndices = nIndices;
	m_pIndices = new WORD [m_nIndices];

	m_bNew = true;
}


//----------------------------------------------------------------------
// Release
//----------------------------------------------------------------------
void
CD3DObject::Release()
{
	if (m_bNew)
	{
		//-------------------------------------
		// Release Vertices
		//-------------------------------------
		if (m_pVertices != NULL)
		{
			// ��� CVertices�� �����.
			delete [] m_pVertices;

			m_pVertices = NULL;		
			m_nVertices = 0;
		}

		//-------------------------------------
		// Release Indices
		//-------------------------------------
		if (m_pIndices != NULL)
		{
			// ��� CIndices�� �����.
			delete [] m_pIndices;

			m_pIndices = NULL;		
			m_nIndices = 0;
		}

		m_bNew = false;
	}
}

//-----------------------------------------------------------------------------
// Add Child
//-----------------------------------------------------------------------------
void				
CD3DObject::AddChild(CD3DObject* pObject)
{
	// list�� �߰�
	m_listChild.push_back( pObject );

	// �߰��� �ڽ��� parent�� ����
	m_pParent = this;
}

//-----------------------------------------------------------------------------
// Release Child
//-----------------------------------------------------------------------------
// Child�� ���� ��� Child�鵵 ���ش�.
//-----------------------------------------------------------------------------
void				
CD3DObject::ReleaseChild()
{
	CD3DOBJECT_LIST::iterator iObject = m_listChild.begin();

	while (iObject != m_listChild.end())
	{
		// Child�� ���� ��� Child���� ���ش�.
		(*iObject)->ReleaseChild();

		// Child�� Parent�� ���ش�.
		(*iObject)->m_pParent = NULL;

		// Child�� ���ش�.
		delete *iObject;

		// ����..
		iObject++;
	}
}

//-----------------------------------------------------------------------------
// Set Origin
//-----------------------------------------------------------------------------
// �⺻ ��ǥ, �⺻ ����(ȸ��), �⺻ ũ��...������ �ʱ�ȭ�Ѵ�.
//-----------------------------------------------------------------------------
void
CD3DObject::SetOrigin()
{
	// ���� Matrix
	CD3DMath::GetIdentityMatrix( m_matStatus );

	// Position
	m_Position.x = 0;
	m_Position.y = 0;
	m_Position.z = 0;

	// Direction
	m_Direction.x = 0;
	m_Direction.y = 0;
	m_Direction.z = 0;

	// Size
	m_Scale.x = 1.0f;
	m_Scale.y = 1.0f;
	m_Scale.z = 1.0f;
}

//-----------------------------------------------------------------------------
// Draw (bRestore)
//-----------------------------------------------------------------------------
// World��ǥ�踦 �߽�����
// Local��ǥ��(matStatus)�� ��~ ���缭 ����ؾ� �Ѵ�.
//
// Object�� Local��ǥ�踦 World��ǥ��� �ٲ㼭 ����Ѵ�.
// --> ����� World��ǥ�踦 Local��ǥ��� �ٲ㼭 ���� ȿ���� ���� �Ѵ�.
//-----------------------------------------------------------------------------
// bRestoreWorld�� ������ World��ǥ�踦 �ǻ���� �ϴ°�?�� ���� ���̴�.
//-----------------------------------------------------------------------------
void
CD3DObject::Draw(bool bRestoreWorld)
{	
	if (m_pMaterial!=NULL)
		CDirect3D::GetDevice()->SetMaterial( m_pMaterial );

	D3DMATRIX matWorld, matMyWorld;			

	// World��ǥ�踦 ��´�.
	D3DMATRIX worldTemp;
	CDirect3D::GetDevice()->GetTransform( D3DTRANSFORMSTATE_WORLD, &matWorld );		

	// Object�� Local��ǥ�踦 World��ǥ��� �ٲ۴�.		
	CD3DMath::MultiplyMatrix(matMyWorld, m_matStatus, matWorld);
	CDirect3D::GetDevice()->SetTransform( D3DTRANSFORMSTATE_WORLD, &matMyWorld );		

	// Object�� �׸���.
	if (m_pVertices)
	{		
		CDirect3D::GetDevice()->DrawIndexedPrimitive( 
									D3DPT_TRIANGLELIST, D3DFVF_VERTEX,
									m_pVertices, m_nVertices, 
									m_pIndices,  m_nIndices, 0 );
	}

	//-----------------------------------------------------------
	// Child���� ��� �׸���.
	//-----------------------------------------------------------
	CD3DOBJECT_LIST::iterator iObject = m_listChild.begin();

	while (iObject != m_listChild.end())
	{
		// Child�� ���� ��� Child���� �׸���.
		(*iObject)->Draw(matMyWorld, false);		

		// ����..
		iObject++;
	}

	//-----------------------------------------------------------
	// ������ ��ǥ�踦 �ǻ���� �ϴ� ���
	//-----------------------------------------------------------
	if (bRestoreWorld)		
	{	
		// ������ World��ǥ�� �ǵ�����.
		CDirect3D::GetDevice()->SetTransform( D3DTRANSFORMSTATE_WORLD, &matWorld );
	}
}

//-----------------------------------------------------------------------------
// Draw (ParentWorld, bRestore)
//-----------------------------------------------------------------------------
// �θ� ��ǥ��(matParentWorld)�� �߽�����
// Local��ǥ��(matStatus)�� ��~ ���缭 ����ؾ� �Ѵ�.
//
// Object�� Local��ǥ�踦 matParentWorld�� ���缭 ����Ѵ�.
// --> ����� matParentWorld�� Local��ǥ��� �ٲ㼭 ���� ȿ���� ���� �Ѵ�.
//-----------------------------------------------------------------------------
// bRestoreWorld�� ������ World��ǥ�踦 �ǻ���� �ϴ°�?�� ���� ���̴�.
//-----------------------------------------------------------------------------
void
CD3DObject::Draw(D3DMATRIX& matParentWorld, bool bRestoreWorld)
{	
	if (m_pMaterial!=NULL)
		CDirect3D::GetDevice()->SetMaterial( m_pMaterial );

	D3DMATRIX matMyWorld;			

	// Object�� Local��ǥ�踦 World��ǥ��� �ٲ۴�.		
	CD3DMath::MultiplyMatrix(matMyWorld, m_matStatus, matParentWorld);
	CDirect3D::GetDevice()->SetTransform( D3DTRANSFORMSTATE_WORLD, &matMyWorld );		

	// Object�� �׸���.
	if (m_pVertices)
	{
		CDirect3D::GetDevice()->DrawIndexedPrimitive( 
									D3DPT_TRIANGLELIST, D3DFVF_VERTEX,
									m_pVertices, m_nVertices, 
									m_pIndices,  m_nIndices, 0 );
	}

	//-----------------------------------------------------------
	// ������ ��ǥ�踦 �ǻ���� �ϴ� ���
	//-----------------------------------------------------------
	if (bRestoreWorld)		
	{	
		// ������ World��ǥ�� �ǵ�����.
		CDirect3D::GetDevice()->SetTransform( D3DTRANSFORMSTATE_WORLD, &matParentWorld );
	}
}

//-----------------------------------------------------------------------------
// Set Position
//-----------------------------------------------------------------------------
void				
CD3DObject::SetPosition(D3DVECTOR& position)		
{ 
	//-------------------------------------------------------
	// ������ ũ��
	//-------------------------------------------------------
	//if (m_Scale.x!=1 || m_Scale.y!=1 || m_Scale.z!=1)
		CD3DMath::GetScaleMatrix( m_matStatus, m_Scale );

	//-------------------------------------------------------
	// ������ ȸ�� ����
	//-------------------------------------------------------
	if (m_Direction.x!=0)
		CD3DMath::MultiplyRotateXMatrix( m_matStatus, m_Direction.x );

	if (m_Direction.y!=0)
		CD3DMath::MultiplyRotateYMatrix( m_matStatus, m_Direction.y );

	if (m_Direction.z!=0)
		CD3DMath::MultiplyRotateZMatrix( m_matStatus, m_Direction.z );

	//-------------------------------------------------------
	// ���� Matrix�� position���� �̵��Ѵ�.
	//-------------------------------------------------------
	CD3DMath::MultiplyTranslateMatrix( m_matStatus, position );

	// position���� �̵��Ѵ�.
	m_Position = position; 

}

//-----------------------------------------------------------------------------
// Set Position
//-----------------------------------------------------------------------------
void				
CD3DObject::SetPosition(float x, float y, float z)	
{
	//-------------------------------------------------------
	// ������ ũ��
	//-------------------------------------------------------
	//if (m_Scale.x!=1 || m_Scale.y!=1 || m_Scale.z!=1)
		CD3DMath::GetScaleMatrix( m_matStatus, m_Scale );

	//-------------------------------------------------------
	// ������ ȸ�� ����
	//-------------------------------------------------------
	if (m_Direction.x!=0)
		CD3DMath::MultiplyRotateXMatrix( m_matStatus, m_Direction.x );

	if (m_Direction.y!=0)
		CD3DMath::MultiplyRotateYMatrix( m_matStatus, m_Direction.y );

	if (m_Direction.z!=0)
		CD3DMath::MultiplyRotateZMatrix( m_matStatus, m_Direction.z );

	//-------------------------------------------------------
	// ���� Matrix�� position���� �̵��Ѵ�.
	//-------------------------------------------------------
	CD3DMath::MultiplyTranslateMatrix( m_matStatus, x, y, z );

	// position���� �̵��Ѵ�.
	m_Position.x = x; 
	m_Position.y = y; 
	m_Position.z = z; 
}

//-----------------------------------------------------------------------------
// Set Direction
//-----------------------------------------------------------------------------
void			
CD3DObject::SetDirection(D3DVECTOR& direction)	
{	
	//-------------------------------------------------------
	// ������ ũ��
	//-------------------------------------------------------
	//if (m_Scale.x!=1 || m_Scale.y!=1 || m_Scale.z!=1)
		CD3DMath::GetScaleMatrix( m_matStatus, m_Scale );

	//-------------------------------------------------------
	// ���� Matrix�� ȸ���Ѵ�.
	//-------------------------------------------------------
	CD3DMath::MultiplyRotateXMatrix( m_matStatus, direction.x );
	CD3DMath::MultiplyRotateYMatrix( m_matStatus, direction.y );
	CD3DMath::MultiplyRotateZMatrix( m_matStatus, direction.z );

	// direction��ŭ ȸ���Ѵ�.
	m_Direction = direction; 

	//-------------------------------------------------------
	// ������ ��ġ
	//-------------------------------------------------------
	if (m_Position.x!=0 || m_Position.y!=0 || m_Position.z!=0)
		CD3DMath::MultiplyTranslateMatrix( m_matStatus, m_Position );
}

//-----------------------------------------------------------------------------
// Set Direction
//-----------------------------------------------------------------------------
void			
CD3DObject::SetDirection(float x, float y, float z)	
{ 
	//-------------------------------------------------------
	// ������ ũ��
	//-------------------------------------------------------
//	if (m_Scale.x!=1 || m_Scale.y!=1 || m_Scale.z!=1)
		CD3DMath::GetScaleMatrix( m_matStatus, m_Scale );

	//-------------------------------------------------------
	// ���� Matrix�� position���� �̵��Ѵ�.
	//-------------------------------------------------------
	CD3DMath::MultiplyRotateXMatrix( m_matStatus, x );
	CD3DMath::MultiplyRotateYMatrix( m_matStatus, y );
	CD3DMath::MultiplyRotateZMatrix( m_matStatus, z );

	// direction��ŭ ȸ���Ѵ�.
	m_Direction.x = x; 
	m_Direction.y = y; 
	m_Direction.z = z; 
	
	//-------------------------------------------------------
	// ������ ��ġ
	//-------------------------------------------------------
	if (m_Position.x!=0 || m_Position.y!=0 || m_Position.z!=0)
		CD3DMath::MultiplyTranslateMatrix( m_matStatus, m_Position );

}

//-----------------------------------------------------------------------------
// Set Scale
//-----------------------------------------------------------------------------
void			
CD3DObject::SetScale(D3DVECTOR& Scale)	
{	
	//-------------------------------------------------------
	// ���� Matrix�� scale�Ѵ�.
	//-------------------------------------------------------
	CD3DMath::GetScaleMatrix( m_matStatus, Scale );

	// Scale��ŭ Scale�Ѵ�.
	m_Scale = Scale; 

	//-------------------------------------------------------
	// ������ ȸ�� ����
	//-------------------------------------------------------
	if (m_Direction.x!=0)
		CD3DMath::MultiplyRotateXMatrix( m_matStatus, m_Direction.x );

	if (m_Direction.y!=0)
		CD3DMath::MultiplyRotateYMatrix( m_matStatus, m_Direction.y );

	if (m_Direction.z!=0)
		CD3DMath::MultiplyRotateZMatrix( m_matStatus, m_Direction.z );

	//-------------------------------------------------------
	// ������ ��ġ
	//-------------------------------------------------------
	if (m_Position.x!=0 || m_Position.y!=0 || m_Position.z!=0)
		CD3DMath::MultiplyTranslateMatrix( m_matStatus, m_Position );

}

//-----------------------------------------------------------------------------
// Set Scale
//-----------------------------------------------------------------------------
void			
CD3DObject::SetScale(float x, float y, float z)	
{ 
	//-------------------------------------------------------
	// ���� Matrix�� scale�Ѵ�.
	//-------------------------------------------------------
	CD3DMath::GetScaleMatrix( m_matStatus, x, y, z );

	// Scale��ŭ Scale�Ѵ�.
	m_Scale.x = x; 
	m_Scale.y = y; 
	m_Scale.z = z; 

	//-------------------------------------------------------
	// ������ ȸ�� ����
	//-------------------------------------------------------
	if (m_Direction.x!=0)
		CD3DMath::MultiplyRotateXMatrix( m_matStatus, m_Direction.x );

	if (m_Direction.y!=0)
		CD3DMath::MultiplyRotateYMatrix( m_matStatus, m_Direction.y );

	if (m_Direction.z!=0)
		CD3DMath::MultiplyRotateZMatrix( m_matStatus, m_Direction.z );

	//-------------------------------------------------------
	// ������ ��ġ
	//-------------------------------------------------------
	if (m_Position.x!=0 || m_Position.y!=0 || m_Position.z!=0)
		CD3DMath::MultiplyTranslateMatrix( m_matStatus, m_Position );
}

//-----------------------------------------------------------------------------
// Move
//-----------------------------------------------------------------------------
// ���� ��ġ���� (x,y,z)��ŭ �̵��Ѵ�.
// ��� Vertices���� Move�Ѵ�.
// �������� �̵� --> Move --> ���� ��ǥ�� �̵�...
//-----------------------------------------------------------------------------
void
CD3DObject::Move(float x, float y, float z)
{
	//-------------------------------------------------------
	// ���� Matrix�� Scale�Ѵ�.
	//-------------------------------------------------------
	//if (m_Scale.x!=1 || m_Scale.y!=1 || m_Scale.z!=1)
		CD3DMath::GetScaleMatrix( m_matStatus, m_Scale );

	//-------------------------------------------------------
	// ���� Matrix�� ȸ���Ѵ�.		
	//-------------------------------------------------------
	if (m_Direction.x!=0)
		CD3DMath::MultiplyRotateXMatrix( m_matStatus, m_Direction.x );
	if (m_Direction.y!=0)
		CD3DMath::MultiplyRotateYMatrix( m_matStatus, m_Direction.y );
	if (m_Direction.z!=0)
		CD3DMath::MultiplyRotateZMatrix( m_matStatus, m_Direction.z );

	//-------------------------------------------------------
	// ���� Matrix�� position���� �̵��Ѵ�.
	//-------------------------------------------------------
	m_Position.x += x;
	m_Position.y += y;
	m_Position.z += z;

	CD3DMath::MultiplyTranslateMatrix( m_matStatus, m_Position );	
}

//-----------------------------------------------------------------------------
// Scale
//-----------------------------------------------------------------------------
// ���� ũ�⿡�� (x,y,z)��ŭ �� �������� ��� Vertices���� Scale�Ѵ�.
// �������� �̵� --> Scale --> ���� ��ǥ�� �̵�...
//-----------------------------------------------------------------------------
void
CD3DObject::Scale(float x, float y, float z)
{
	//-------------------------------------------------------
	// ���� Matrix�� Scale�Ѵ�.
	//-------------------------------------------------------
	// Scale��ŭ Scale�Ѵ�.
	m_Scale.x *= x; 
	m_Scale.y *= y; 
	m_Scale.z *= z; 	

	if (m_Scale.x < 0) m_Scale.x = 0.001f;
	if (m_Scale.y < 0) m_Scale.y = 0.001f;
	if (m_Scale.z < 0) m_Scale.z = 0.001f;

	CD3DMath::GetScaleMatrix( m_matStatus, m_Scale.x, m_Scale.y, m_Scale.z );
	

	//-------------------------------------------------------
	// ���� Matrix�� ȸ���Ѵ�.		
	//-------------------------------------------------------
	if (m_Direction.x!=0)
		CD3DMath::MultiplyRotateXMatrix( m_matStatus, m_Direction.x );
	if (m_Direction.y!=0)
		CD3DMath::MultiplyRotateYMatrix( m_matStatus, m_Direction.y );
	if (m_Direction.z!=0)
		CD3DMath::MultiplyRotateZMatrix( m_matStatus, m_Direction.z );

	//-------------------------------------------------------
	// ������ ��ġ
	//-------------------------------------------------------
	if (m_Position.x!=0 || m_Position.y!=0 || m_Position.z!=0)
		CD3DMath::MultiplyTranslateMatrix( m_matStatus, m_Position );
}

//-----------------------------------------------------------------------------
// Rotate
//-----------------------------------------------------------------------------
// ���� ȸ���� ��������... (x,y,z)��ŭ
// ��� Vertices���� Rotate�Ѵ�.
// �������� �̵� --> Rotate --> ���� ��ǥ�� �̵�...
//-----------------------------------------------------------------------------
void
CD3DObject::Rotate(float x, float y, float z)
{
	//-------------------------------------------------------
	// ������ ũ��
	//-------------------------------------------------------
	//if (m_Scale.x!=1 || m_Scale.y!=1 || m_Scale.z!=1)
		CD3DMath::GetScaleMatrix( m_matStatus, m_Scale );

	//-------------------------------------------------------
	// ���� Matrix�� ȸ���Ѵ�.		
	//-------------------------------------------------------
	m_Direction.x += x;
	m_Direction.y += y;
	m_Direction.z += z;
	CD3DMath::MultiplyRotateXMatrix( m_matStatus, m_Direction.x );
	CD3DMath::MultiplyRotateYMatrix( m_matStatus, m_Direction.y );
	CD3DMath::MultiplyRotateZMatrix( m_matStatus, m_Direction.z );

	//-------------------------------------------------------
	// ������ ��ġ
	//-------------------------------------------------------
	if (m_Position.x!=0 || m_Position.y!=0 || m_Position.z!=0)
		CD3DMath::MultiplyTranslateMatrix( m_matStatus, m_Position );
}

//-----------------------------------------------------------------------------
// Set Material
//-----------------------------------------------------------------------------
void				
CD3DObject::SetMaterial(D3DMATERIAL7& mtrl)	
{ 
	if (m_pMaterial==NULL)
	{
		m_pMaterial = new D3DMATERIAL7; 
	}

	*m_pMaterial = mtrl; 
}

//-----------------------------------------------------------------------------
// Create Cube (size)
//-----------------------------------------------------------------------------
// Cube(����ü)�� ���� Vertices�� Indices���� �����Ѵ�.
//-----------------------------------------------------------------------------
void
CD3DObject::CreateCube(float sizeX, float sizeY, float sizeZ)
{
	//#define NUM_CUBE_VERTICES (6*4)
	//#define NUM_CUBE_INDICES  (6*2*3)
	//---------------------------------------------
	// memory ���
	//---------------------------------------------
	Init(24, 36);

    // Define the normals for the cube
    D3DVECTOR n0( 0.0f, 0.0f,-1.0f ); // Front face
    D3DVECTOR n1( 0.0f, 0.0f, 1.0f ); // Back face
    D3DVECTOR n2( 0.0f, 1.0f, 0.0f ); // Bottom face
    D3DVECTOR n3( 0.0f,-1.0f, 0.0f ); // Top face
    D3DVECTOR n4( 1.0f, 0.0f, 0.0f ); // Left face
    D3DVECTOR n5(-1.0f, 0.0f, 0.0f ); // Right face

	D3DVERTEX*	pVertices	= m_pVertices;
	WORD*		pIndices	= m_pIndices;

    // Front face
    *pVertices++ = D3DVERTEX( D3DVECTOR(-sizeX, sizeY,-sizeZ), n0, 0.01f, 0.01f ); 
    *pVertices++ = D3DVERTEX( D3DVECTOR( sizeX, sizeY,-sizeZ), n0, 0.99f, 0.01f );
    *pVertices++ = D3DVERTEX( D3DVECTOR( sizeX,-sizeY,-sizeZ), n0, 0.99f, 0.99f );
    *pVertices++ = D3DVERTEX( D3DVECTOR(-sizeX,-sizeY,-sizeZ), n0, 0.01f, 0.99f ); 

    // Back face
    *pVertices++ = D3DVERTEX( D3DVECTOR(-sizeX, sizeY, sizeZ), n1, 0.99f, 0.01f );
    *pVertices++ = D3DVERTEX( D3DVECTOR(-sizeX,-sizeY, sizeZ), n1, 0.99f, 0.99f );
    *pVertices++ = D3DVERTEX( D3DVECTOR( sizeX,-sizeY, sizeZ), n1, 0.01f, 0.99f );
    *pVertices++ = D3DVERTEX( D3DVECTOR( sizeX, sizeY, sizeZ), n1, 0.01f, 0.01f );

    // Top face
    *pVertices++ = D3DVERTEX( D3DVECTOR(-sizeX, sizeY, sizeZ), n2, 0.01f, 0.01f );
    *pVertices++ = D3DVERTEX( D3DVECTOR( sizeX, sizeY, sizeZ), n2, 0.99f, 0.01f );
    *pVertices++ = D3DVERTEX( D3DVECTOR( sizeX, sizeY,-sizeZ), n2, 0.99f, 0.99f );
    *pVertices++ = D3DVERTEX( D3DVECTOR(-sizeX, sizeY,-sizeZ), n2, 0.01f, 0.99f );

    // Bottom face
    *pVertices++ = D3DVERTEX( D3DVECTOR(-sizeX,-sizeY, sizeZ), n3, 0.01f, 0.99f );
    *pVertices++ = D3DVERTEX( D3DVECTOR(-sizeX,-sizeY,-sizeZ), n3, 0.01f, 0.01f );
    *pVertices++ = D3DVERTEX( D3DVECTOR( sizeX,-sizeY,-sizeZ), n3, 0.99f, 0.01f );
    *pVertices++ = D3DVERTEX( D3DVECTOR( sizeX,-sizeY, sizeZ), n3, 0.99f, 0.99f );

    // Right face
    *pVertices++ = D3DVERTEX( D3DVECTOR( sizeX, sizeY,-sizeZ), n4, 0.01f, 0.01f );
    *pVertices++ = D3DVERTEX( D3DVECTOR( sizeX, sizeY, sizeZ), n4, 0.99f, 0.01f );
    *pVertices++ = D3DVERTEX( D3DVECTOR( sizeX,-sizeY, sizeZ), n4, 0.99f, 0.99f );
    *pVertices++ = D3DVERTEX( D3DVECTOR( sizeX,-sizeY,-sizeZ), n4, 0.01f, 0.99f );

    // Left face
    *pVertices++ = D3DVERTEX( D3DVECTOR(-sizeX, sizeY,-sizeZ), n5, 0.99f, 0.01f );
    *pVertices++ = D3DVERTEX( D3DVECTOR(-sizeX,-sizeY,-sizeZ), n5, 0.99f, 0.99f );
    *pVertices++ = D3DVERTEX( D3DVECTOR(-sizeX,-sizeY, sizeZ), n5, 0.01f, 0.99f );
    *pVertices++ = D3DVERTEX( D3DVECTOR(-sizeX, sizeY, sizeZ), n5, 0.01f, 0.01f );

    // Set up the indices for the cube
    *pIndices++ =  0+0;   *pIndices++ =  0+1;   *pIndices++ =  0+2;
    *pIndices++ =  0+2;   *pIndices++ =  0+3;   *pIndices++ =  0+0;
    *pIndices++ =  4+0;   *pIndices++ =  4+1;   *pIndices++ =  4+2;
    *pIndices++ =  4+2;   *pIndices++ =  4+3;   *pIndices++ =  4+0;
    *pIndices++ =  8+0;   *pIndices++ =  8+1;   *pIndices++ =  8+2;
    *pIndices++ =  8+2;   *pIndices++ =  8+3;   *pIndices++ =  8+0;
    *pIndices++ = 12+0;   *pIndices++ = 12+1;   *pIndices++ = 12+2;
    *pIndices++ = 12+2;   *pIndices++ = 12+3;   *pIndices++ = 12+0;
    *pIndices++ = 16+0;   *pIndices++ = 16+1;   *pIndices++ = 16+2;
    *pIndices++ = 16+2;   *pIndices++ = 16+3;   *pIndices++ = 16+0;
    *pIndices++ = 20+0;   *pIndices++ = 20+1;   *pIndices++ = 20+2;
    *pIndices++ = 20+2;   *pIndices++ = 20+3;   *pIndices++ = 20+0;
}

//-----------------------------------------------------------------------------
// Create Plane (size)
//-----------------------------------------------------------------------------
// Plane(���)�� ���� Vertices�� Indices���� �����Ѵ�.
//-----------------------------------------------------------------------------
void
CD3DObject::CreatePlane(float size)
{
	//#define NUM_CUBE_VERTICES (2*4)
	//#define NUM_CUBE_INDICES  (2*2*3)
	//---------------------------------------------
	// memory ���
	//---------------------------------------------
	Init(8, 12);

    // Define the normals for the cube
    D3DVECTOR n0( 0.0f, 0.0f,-1.0f ); // Front face
    D3DVECTOR n1( 0.0f, 0.0f, 1.0f ); // Back face    

	D3DVERTEX*	pVertices	= m_pVertices;
	WORD*		pIndices	= m_pIndices;

    // Front face
    *pVertices++ = D3DVERTEX( D3DVECTOR(-size, size, 0), n0, 0.01f, 0.01f ); 
    *pVertices++ = D3DVERTEX( D3DVECTOR( size, size, 0), n0, 0.99f, 0.01f );
    *pVertices++ = D3DVERTEX( D3DVECTOR( size,-size, 0), n0, 0.99f, 0.99f );
    *pVertices++ = D3DVERTEX( D3DVECTOR(-size,-size, 0), n0, 0.01f, 0.99f ); 

    // Back face
    *pVertices++ = D3DVERTEX( D3DVECTOR(-size, size, 0), n1, 0.99f, 0.01f );
    *pVertices++ = D3DVERTEX( D3DVECTOR(-size,-size, 0), n1, 0.99f, 0.99f );
    *pVertices++ = D3DVERTEX( D3DVECTOR( size,-size, 0), n1, 0.01f, 0.99f );
    *pVertices++ = D3DVERTEX( D3DVECTOR( size, size, 0), n1, 0.01f, 0.01f );

    // Set up the indices for the cube
    *pIndices++ =  0+0;   *pIndices++ =  0+1;   *pIndices++ =  0+2;
    *pIndices++ =  0+2;   *pIndices++ =  0+3;   *pIndices++ =  0+0;
    *pIndices++ =  4+0;   *pIndices++ =  4+1;   *pIndices++ =  4+2;
    *pIndices++ =  4+2;   *pIndices++ =  4+3;   *pIndices++ =  4+0;  
}


//-----------------------------------------------------------------------------
// Create Cylinder (size)
//-----------------------------------------------------------------------------
// Cylinder(��~���)�� ���� Vertices�� Indices���� �����Ѵ�.
//
// r : ������ 
// l : ����� ���� 
// n : ���� �̷�� �ﰢ�� ����
//-----------------------------------------------------------------------------
void
CD3DObject::CreateCylinder(float r, float l, int n)
{
	// �ּ��� �ﰢ���� �Ǿ�� �Ѵ�.
	if (n<3) n=3;

	//#define NUM_CUBE_VERTICES (6*4)
	//#define NUM_CUBE_INDICES  (6*2*3)
	//---------------------------------------------
	// memory ���
	//---------------------------------------------
	Init(6*n+2, 12*n);
	//Init(6*n+2, 6*n);

    // Define the normals for the cube
    D3DVECTOR n0( 0.0f, 1.0f, 0.0f ); // Top face
    D3DVECTOR n1( 0.0f,-1.0f, 0.0f ); // Bottom face
	D3DVECTOR n2( 0.0f, 0.0f, 0.0f );
    
	float l2 = l / 2;

	// Top face
	float	x=0.0f,
			z=0.0f, 
			xo, zo;

	float t = 0.0f;
	float degree = 360.0f / n;
	float tu = 0.0f;
	float tv = 0.0f;
	float tdeg = 1.0f / n;
	float rad;

	int iV = 0, iI = 0;
	m_pVertices[iV++] = D3DVERTEX( D3DVECTOR(0, l2, 0), n0, 0, 0 );	// 0
	m_pVertices[iV++] = D3DVERTEX( D3DVECTOR(0, -l2, 0), n1, 0, 0 );	// 1

	for (int i=0; i<=n; t+=degree, tu+=tdeg, tv+=tdeg, i++)
	{	
		xo = x; 
		zo = z;
		rad = t * g_DEGTORAD;
		z = r * (float)sin( rad );
		x = r * (float)cos( rad );
	
		if (i!=n)
		{
			m_pVertices[iV++] = D3DVERTEX( D3DVECTOR(x, l2, z), n0, 1, 1);		// 2
			m_pVertices[iV++] = D3DVERTEX( D3DVECTOR(x, -l2, z), n1, 1, 1);	// 3
		}		

		if (i!=0)
		{
			n2.x = xo + x;
			n2.y = 0;
			n2.z = zo + z;
			CD3DMath::NormalizeVector( n2 );			
			m_pVertices[iV++] = D3DVERTEX( D3DVECTOR(xo, l2, zo), n2, tu, 0 );	// 4
			m_pVertices[iV++] = D3DVERTEX( D3DVECTOR(x, l2, z), n2, tu+tdeg, 0 );		// 5
			m_pVertices[iV++] = D3DVERTEX( D3DVECTOR(x, -l2, z), n2, tu+tdeg, 1 );	// 6
			m_pVertices[iV++] = D3DVERTEX( D3DVECTOR(xo, -l2, zo), n2, tu, 1 );	// 7
		
			if (i==1)
			{
				// Top face
				m_pIndices[iI++] = 0;
				m_pIndices[iI++] = iV-6;
				m_pIndices[iI++] = iV-8;

				// Bottom face
				m_pIndices[iI++] = 1;
				m_pIndices[iI++] = iV-7;
				m_pIndices[iI++] = iV-5;
			}
			else if (i==n)
			{
				// Top face
				m_pIndices[iI++] = 0;
				m_pIndices[iI++] = 2;
				m_pIndices[iI++] = iV-10;

				// Bottom face
				m_pIndices[iI++] = 1;
				m_pIndices[iI++] = iV-9;
				m_pIndices[iI++] = 3;
			}	
			else
			{
				// Top face
				m_pIndices[iI++] = 0;
				m_pIndices[iI++] = iV-6;
				m_pIndices[iI++] = iV-12;

				// Bottom face
				m_pIndices[iI++] = 1;
				m_pIndices[iI++] = iV-11;
				m_pIndices[iI++] = iV-5;
			}

			// Side face
			m_pIndices[iI++] = iV-4;
			m_pIndices[iI++] = iV-3;
			m_pIndices[iI++] = iV-2;

			m_pIndices[iI++] = iV-2;
			m_pIndices[iI++] = iV-1;
			m_pIndices[iI++] = iV-4;		
		}
	}
}

//-----------------------------------------------------------------------------
// Create TilePlane (size)
//-----------------------------------------------------------------------------
// TilePlane�� ���� Vertices�� Indices���� �����Ѵ�.
// Texture�� �ϴ�... �׽�Ʈ��..
// 256*256�� (64*32)Tile�� 4*8�� ��µǾ� �ִ°� ����ߴ�.
//-----------------------------------------------------------------------------
void
CD3DObject::CreateTilePlane(int width, int height, float firstX, float firstY, float size)
{
	//---------------------------------------------
	// memory ���
	//---------------------------------------------
	Init(4*width*height, 6*width*height);
	
	// Define the normals for the cube
	D3DVERTEX*	pVertices	= m_pVertices;
	WORD*		pIndices	= m_pIndices;    
	
	D3DVECTOR n0( 0.0f, 0.0f,-1.0f ); // Front face   	
	
	int i, j;
	float x,y;

	float lenX = 1.0f/4.0f;
	float lenY = 1.0f/8.0f;
	float left, right, up, down;

	y = firstY * size;
	int n = 0;
	for (i=0; i<height; i++)
	{		
		x = firstX * size;
		for (j=0; j<width; j++)
		{	
			// Texture�� ����
			up = (float)(rand()%8)/8.0f;
			down = up + lenY;
			left = (float)(rand()%4)/4.0f;
			right = left + lenX;		
				
			// Front face
			*pVertices++ = D3DVERTEX( D3DVECTOR( x,		y, 0),		n0, left,	up ); 
			*pVertices++ = D3DVERTEX( D3DVECTOR( x+size,y, 0),		n0, right,	up );
			*pVertices++ = D3DVERTEX( D3DVECTOR( x+size,y-size, 0), n0, right,	down );
			*pVertices++ = D3DVERTEX( D3DVECTOR( x,		y-size, 0), n0, left,	down );
    
			// Set up the indices for the cube
			*pIndices++ =  n+0;   *pIndices++ =  n+1;   *pIndices++ =  n+2;
			*pIndices++ =  n+2;   *pIndices++ =  n+3;   *pIndices++ =  n+0;   

			x += size;		

			n += 4;
		}
		y -= size;
	}
}

//-----------------------------------------------------------------------------
// Load X
//-----------------------------------------------------------------------------
/*
bool
CD3DObject::LoadX(char *filename)
{	
	// ���� �����ִ� �޸𸮸� �����Ѵ�.
	Release();	

	m_pFile = new CD3DFile();

	HRESULT hr1 = m_pFile->Load( filename );
    HRESULT hr2 = m_pFile->GetMeshVertices( "", &m_pVertices,
                                                  &m_nVertices );
    HRESULT hr3 = m_pFile->GetMeshIndices( "", &m_pIndices,
                                                 &m_nIndices );

    if( FAILED(hr1|hr2|hr3) )
    {
        MessageBox( NULL, TEXT("Could not load X file."),
                    NULL, MB_OK|MB_ICONERROR );
        return false;//E_FAIL;
    }   

    return true;//S_OK;
}
*/


//-----------------------------------------------------------------------------
// Apply ShpereMap
//-----------------------------------------------------------------------------
void
CD3DObject::ApplySphereMap()
{
    // Get the current world-view matrix
    D3DMATRIX matWorld, matView, matWV;
	CDirect3D::GetDevice()->GetTransform( D3DTRANSFORMSTATE_VIEW,  &matView );
    CDirect3D::GetDevice()->GetTransform( D3DTRANSFORMSTATE_WORLD, &matWorld );
	//CD3DMath::MultiplyMatrix( matWV, matWorld, matView );
	CD3DMath::MultiplyMatrix( matWV, matWorld, matView );
	CD3DMath::MultiplyMatrix( matWV, m_matStatus, matWV );	

    // Extract world-view matrix elements for speed
    float m11 = matWV._11,   m21 = matWV._21,   m31 = matWV._31;
    float m12 = matWV._12,   m22 = matWV._22,   m32 = matWV._32;
    float m13 = matWV._13,   m23 = matWV._23,   m33 = matWV._33;

    // Loop through the vertices, transforming each one and calculating
    // the correct texture coordinates.
    for( int i = 0; i < m_nVertices; i++ )
    {
        float nx = m_pVertices[i].nx;
        float ny = m_pVertices[i].ny;
        float nz = m_pVertices[i].nz;

        // Check the z-component, to skip any vertices that face backwards
        if( nx*m13 + ny*m23 + nz*m33 > 0.0f )
            continue;

        // Assign the spheremap's texture coordinates
        m_pVertices[i].tu = 0.5f * ( 1.0f + ( nx*m11 + ny*m21 + nz*m31 ) );
        m_pVertices[i].tv = 0.5f * ( 1.0f - ( nx*m12 + ny*m22 + nz*m32 ) );
    }
}
