
// MapModeDemoView.h : CMapModeDemoView 클래스의 인터페이스
//


#pragma once


class CMapModeDemoView : public CView
{
protected: // serialization에서만 만들어집니다.
	CMapModeDemoView();
	DECLARE_DYNCREATE(CMapModeDemoView)

// 특성입니다.
public:
	CMapModeDemoDoc* GetDocument() const;

	int		m_nZoomRate;		//확대/축소 비율

// 작업입니다.
public:

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
	virtual ~CMapModeDemoView();
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
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
};

#ifndef _DEBUG  // MapModeDemoView.cpp의 디버그 버전
inline CMapModeDemoDoc* CMapModeDemoView::GetDocument() const
   { return reinterpret_cast<CMapModeDemoDoc*>(m_pDocument); }
#endif

