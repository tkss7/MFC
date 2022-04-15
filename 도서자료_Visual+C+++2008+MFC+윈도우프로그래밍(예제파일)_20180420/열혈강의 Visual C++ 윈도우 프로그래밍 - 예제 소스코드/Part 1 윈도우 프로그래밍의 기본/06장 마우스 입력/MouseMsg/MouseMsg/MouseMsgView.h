
// MouseMsgView.h : CMouseMsgView 클래스의 인터페이스
//


#pragma once


class CMouseMsgView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMouseMsgView();
	DECLARE_DYNCREATE(CMouseMsgView)

// 특성입니다.
public:
	CMouseMsgDoc* GetDocument() const;

// 작업입니다.
public:
	CPoint		m_ptMouse;		//마우스 포인터의 좌표
	CPoint		m_ptLeft;		//마우스 왼쪽 버튼이 눌린 좌표
	CPoint		m_ptRight;		//마우스 오른쪽 버튼이 눌린 좌표

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMouseMsgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

#ifndef _DEBUG  // MouseMsgView.cpp의 디버그 버전
inline CMouseMsgDoc* CMouseMsgView::GetDocument() const
   { return reinterpret_cast<CMouseMsgDoc*>(m_pDocument); }
#endif

