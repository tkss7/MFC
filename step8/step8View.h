
// step8View.h: Cstep8View 클래스의 인터페이스
//

#pragma once


class Cstep8View : public CView
{
protected: // serialization에서만 만들어집니다.
	Cstep8View() noexcept;
	DECLARE_DYNCREATE(Cstep8View)
	int i=0;
// 특성입니다.
public:
	Cstep8Doc* GetDocument() const;

// 작업입니다.
public:
	CWnd m_wndChild; // 버튼 객체
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
	virtual ~Cstep8View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // step8View.cpp의 디버그 버전
inline Cstep8Doc* Cstep8View::GetDocument() const
   { return reinterpret_cast<Cstep8Doc*>(m_pDocument); }
#endif

