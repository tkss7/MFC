
// SDI_DemoView.h: CSDIDemoView 클래스의 인터페이스
//

#pragma once


class CSDIDemoView : public CView
{
protected: // serialization에서만 만들어집니다.
	CSDIDemoView() noexcept;
	DECLARE_DYNCREATE(CSDIDemoView)

// 특성입니다.
public:
	CSDIDemoDoc* GetDocument() const;

// 작업입니다.
public:
	int m_g;
	int m_h;
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
	virtual ~CSDIDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // SDI_DemoView.cpp의 디버그 버전
inline CSDIDemoDoc* CSDIDemoView::GetDocument() const
   { return reinterpret_cast<CSDIDemoDoc*>(m_pDocument); }
#endif

