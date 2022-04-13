
// step7View.h: Cstep7View 클래스의 인터페이스
//

#pragma once


class Cstep7View : public CView
{
protected: // serialization에서만 만들어집니다.
	Cstep7View() noexcept;
	DECLARE_DYNCREATE(Cstep7View)

// 특성입니다.
public:
	Cstep7Doc* GetDocument() const;

// 작업입니다.
public:
	CWnd m_wndClient1;
	CWnd m_wndClient2;
	CWnd m_wndClient3;//m_hWnd 이 들어있다. 윈도우가 아니다????

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
	virtual ~Cstep7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // step7View.cpp의 디버그 버전
inline Cstep7Doc* Cstep7View::GetDocument() const
   { return reinterpret_cast<Cstep7Doc*>(m_pDocument); }
#endif

