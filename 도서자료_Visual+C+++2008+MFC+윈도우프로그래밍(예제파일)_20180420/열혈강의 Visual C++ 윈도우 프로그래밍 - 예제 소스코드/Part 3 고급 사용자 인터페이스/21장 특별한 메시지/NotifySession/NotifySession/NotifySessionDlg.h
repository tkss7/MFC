
// NotifySessionDlg.h : 헤더 파일
//

#pragma once
#include "afxwin.h"


// CNotifySessionDlg 대화 상자
class CNotifySessionDlg : public CDialog
{
// 생성입니다.
public:
	CNotifySessionDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_NOTIFYSESSION_DIALOG };

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
	CListBox m_List;
	afx_msg void OnDestroy();
	DWORD m_dwSessionID;
	afx_msg void OnSessionChange(UINT nSessionState, UINT nId);
	afx_msg void OnBnClickedButtonLogoff();
};
