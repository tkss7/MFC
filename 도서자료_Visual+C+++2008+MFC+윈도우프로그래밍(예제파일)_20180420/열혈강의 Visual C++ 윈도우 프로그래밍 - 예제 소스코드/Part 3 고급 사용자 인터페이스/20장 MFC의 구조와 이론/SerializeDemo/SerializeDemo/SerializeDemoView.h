
// SerializeDemoView.h : CSerializeDemoView 클래스의 인터페이스
//


#pragma once


class CSerializeDemoView : public CEditView
{
protected: // serialization에서만 만들어집니다.
	CSerializeDemoView();
	DECLARE_DYNCREATE(CSerializeDemoView)

// 특성입니다.
public:
	CSerializeDemoDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CSerializeDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void Serialize(CArchive& ar);
};

#ifndef _DEBUG  // SerializeDemoView.cpp의 디버그 버전
inline CSerializeDemoDoc* CSerializeDemoView::GetDocument() const
   { return reinterpret_cast<CSerializeDemoDoc*>(m_pDocument); }
#endif

