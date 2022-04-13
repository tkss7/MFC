
// OdbcDemoView.h : COdbcDemoView 클래스의 인터페이스
//


#pragma once
#include "afxcmn.h"

class COdbcDemoSet;

class COdbcDemoView : public CRecordView
{
protected: // serialization에서만 만들어집니다.
	COdbcDemoView();
	DECLARE_DYNCREATE(COdbcDemoView)

public:
	enum{ IDD = IDD_ODBCDEMO_FORM };
	COdbcDemoSet* m_pSet;

// 특성입니다.
public:
	COdbcDemoDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~COdbcDemoView();
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
	CString m_strName;
	CString m_strPhoneNumber;
	CString m_strAddress;
	long m_lAge;
	void DisplayRecord(void);
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordLast();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordPrev();
	afx_msg void OnBnClickedButtonAddnew();
	afx_msg void OnBnClickedButtonUpdatecurrent();
	afx_msg void OnBnClickedButtonDeletecurrent();
	afx_msg void OnBnClickedButtonFindrecord();
};

#ifndef _DEBUG  // OdbcDemoView.cpp의 디버그 버전
inline COdbcDemoDoc* COdbcDemoView::GetDocument() const
   { return reinterpret_cast<COdbcDemoDoc*>(m_pDocument); }
#endif

