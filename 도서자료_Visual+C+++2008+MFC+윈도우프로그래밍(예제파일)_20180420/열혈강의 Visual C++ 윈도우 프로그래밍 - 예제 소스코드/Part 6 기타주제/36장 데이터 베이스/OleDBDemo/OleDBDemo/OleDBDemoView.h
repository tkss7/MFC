
// OleDBDemoView.h : COleDBDemoView 클래스의 인터페이스
//


#pragma once
#include "afxcmn.h"

class COleDBDemoSet;

class COleDBDemoView : public COleDBRecordView
{
protected: // serialization에서만 만들어집니다.
	COleDBDemoView();
	DECLARE_DYNCREATE(COleDBDemoView)

public:
	enum{ IDD = IDD_OLEDBDEMO_FORM };
	COleDBDemoSet* m_pSet;

// 특성입니다.
public:
	COleDBDemoDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual CRowset<>* OnGetRowset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~COleDBDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_List;
	void ListupAllRecords(void);
	afx_msg void OnBnClickedButtonAddnew();
	afx_msg void OnBnClickedButtonModifyrecord();
	afx_msg void OnBnClickedButtonDeleterecord();
};

#ifndef _DEBUG  // OleDBDemoView.cpp의 디버그 버전
inline COleDBDemoDoc* COleDBDemoView::GetDocument() const
   { return reinterpret_cast<COleDBDemoDoc*>(m_pDocument); }
#endif

