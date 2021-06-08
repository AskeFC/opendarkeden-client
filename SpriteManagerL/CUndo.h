/********************************************************************
*	 CUndo template class											*
*																	*
*	!! class TYPE�� '=' operator�� ���ǵǾ� �־�� �Ѵ�.			*
*																	*
*																	*
********************************************************************/

///////////////////////////////////////////////////
//	���� Queue class
template<class TYPE, int arraylength> class CQueue
{
//--------------------------------------------------------
//
// Member Variables
//
private:
	TYPE				m_data[arraylength];
	int					m_iHead, m_iTail;	// Head => m_data�� ù��° data�� index,
											// Tail => m_data�� ������ data�� index+1
	bool				m_bEmpty;
//--------------------------------------------------------
//
// Member Functions
//
public:
	CQueue()
	{
		m_iHead = 0;
		m_iTail = 0;
		m_bEmpty = true;
	}

	int					GetSize() { return arraylength;}

	int					IsEmpty() { return GetItemCount() == 0;}

	int					IsFull() { return GetItemCount() == arraylength;}

	// ���� data�� ��ΰ�.
	int					GetItemCount()	
	{
		if( m_bEmpty)
			return 0;

		int iDataCount = m_iTail - m_iHead;

		if( iDataCount <= 0)
			iDataCount += arraylength;

		return iDataCount;
	}

	void 				Push( const TYPE& item)
	{
		// �����̸� �о��.
		if( IsFull())
		{
			m_iHead = (m_iHead+1)%arraylength;
		}

		m_iTail = (m_iTail+1)%arraylength;
		m_data[ m_iTail] = item;

		m_bEmpty = false;
	}
	bool				Pop( TYPE& item)
	{
		if( IsEmpty())
			return false;

		item = m_data[ m_iHead];
		m_iHead = (m_iHead+1)%arraylength;

		// pop�ÿ��� empty ���°� �ɼ� �ִ�.
		if( m_iTail == m_iHead)
			m_bEmpty = true;

		return true;
	}

	//////////////////////////////////////////////////
	// tail���� i��° ������ data�� ��´�.
	bool				GetByDepth( int i, TYPE& item)
	{
		if( IsEmpty() || i >= arraylength || i < 0) return false;

		int arrayIndex = (m_iTail-i)%arraylength;	// array������ index
		if( arrayIndex < 0) 
			arrayIndex += arraylength;

		item = m_data[ arrayIndex];
		return true;
/*
		// ������
		if( m_iHead < m_iTail)
		{
			if( arrayIndex < m_iHead) return false;
			item = m_data[ arrayIndex];
			return true;
		}
		// ������
		else //if( m_iHead > m_iTail)
		{
			if( arrayIndex > m_iHead) return false;
			item = m_data[ arrayIndex];
			return true;
		}
		*/
	}
};





/////////////////////////////////////////////////////////////
//
//	CUndo class
//
template<class TYPE, int undodepth> class CUndo
{

//------------------------------------------------------------
//
// Member Variables
//
private:
	CQueue<TYPE, undodepth+1>	m_dataQueue;	// +1�� ������¸� �����ϱ� ���� ������ Ȯ���ϱ� ����
	int							m_iCurrentDepth;	// ������ undo ���̻�Ȳ.
													// -1 �� ���, undo�� ���� ���� ����.
typedef void (CALLBACK* CUNDOCALLBACK)(void);
	CUNDOCALLBACK				m_ChangeCallback;					// ���º�ȭ�� ����� �ڵ� ȣ��� �Լ�������



//------------------------------------------------------------
//
// Member Functions
//
public:
	CUndo()
	{
		m_iCurrentDepth = -1;
		m_ChangeCallback = NULL;
	}

	~CUndo()
	{
	}

	void Clear() { m_iCurrentDepth = -1;}	// Undo�Ұ����ϰ� �����.

	void SetCallbackFunction( CUNDOCALLBACK ft) { m_ChangeCallback = ft;}

	// ���� ��ȭ�� ���涧���� ȣ��Ǿ� �ϴ� �Լ�.
	void SaveState( const TYPE& state)
	{
		m_iCurrentDepth = -1;
		m_dataQueue.Push( state);
	}

	//--------------------------------------------------------------------------------
	// !! ó�� undo�� �õ��� ���, ���� ���¸� parameter�� �Ѱ���� �Ѵ�.
	//	  �ֳ��ϸ� UNDO ���� ��ü�� ���� ��ȭ�� ����Ű�� �����̴�.
	//	  �̴� �ܺο��� ó���� ���� ������( �ܺο��� UNDO call������ SaveState�� ȣ��)
	//	  �ڵ� �ߺ��� �߻��� �� �����Ƿ� ...
	//	return : return false when failed
	//--------------------------------------------------------------------------------
	bool Undo( TYPE& state)
	{
		if( CanUndo() == false)
			return false;

		// ó�� undo�� �õ��� ���, ���͸� ���� ���� ���¸� ����.
		if( m_iCurrentDepth == -1)
		{
			SaveState( state);
			m_iCurrentDepth++;
		}

		bool ret = m_dataQueue.GetByDepth( ++m_iCurrentDepth, state);
		if( ret && m_ChangeCallback) 
			(*m_ChangeCallback)();

		return ret;
	}

	bool Redo( TYPE& state)
	{
		if( CanRedo() == false)
			return false;

		bool ret = m_dataQueue.GetByDepth( --m_iCurrentDepth, state);
		if( ret && m_ChangeCallback)
			(*m_ChangeCallback)();

		return ret;
	}

	bool IsFull()
	{
		return m_dataQueue.IsFull();
	}

	bool CanUndo()
	{
		return m_dataQueue.GetItemCount() > (m_iCurrentDepth+1);
	}

	bool CanRedo()
	{
		return m_iCurrentDepth > 0;
	}
};