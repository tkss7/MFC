﻿
// RedrawDemoView.h: CRedrawDemoView 클래스의 인터페이스
//

#pragma once


class CRedrawDemoView : public CView
{
protected: // serialization에서만 만들어집니다.
	CRedrawDemoView() noexcept;
	DECLARE_DYNCREATE(CRedrawDemoView)

// 특성입니다.
public:
	CRedrawDemoDoc* GetDocument() const;

// 작업입니다.
public:
	void CRedrawDemoView::Draw(int x, int y, CDC* pDc);



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
	virtual ~CRedrawDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnMButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // RedrawDemoView.cpp의 디버그 버전
inline CRedrawDemoDoc* CRedrawDemoView::GetDocument() const
   { return reinterpret_cast<CRedrawDemoDoc*>(m_pDocument); }
#endif

