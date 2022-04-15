
// SubClassDemoDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "SubClassTestWnd.h"


// CSubClassDemoDlg 대화 상자
class CSubClassDemoDlg : public CDialog
{
// 생성입니다.
public:
	CSubClassDemoDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

	CSubClassTestWnd	m_wndTest;

// 대화 상자 데이터입니다.
	enum { IDD = IDD_SUBCLASSDEMO_DIALOG };

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
	CListCtrl m_List;
};
