
// TabDemoDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"

#include "FormOne.h"
#include "FormSecond.h"
#include "FormThird.h"


// CTabDemoDlg 대화 상자
class CTabDemoDlg : public CDialog
{
// 생성입니다.
public:
	CTabDemoDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

	CFormOne		m_formOne;
	CFormSecond		m_formSecond;
	CFormThird		m_formThird;
	CWnd*			m_pwndShow;

// 대화 상자 데이터입니다.
	enum { IDD = IDD_TABDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_Tab;
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
};
