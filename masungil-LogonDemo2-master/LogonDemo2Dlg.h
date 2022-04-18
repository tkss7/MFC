﻿
// LogonDemo2Dlg.h: 헤더 파일
//

#pragma once


// CLogonDemo2Dlg 대화 상자
class CLogonDemo2Dlg : public CDialog
{
// 생성입니다.
public:
	CLogonDemo2Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGONDEMO2_DIALOG };
#endif

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
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	CString m_strId;
	CString m_strPwd;
	afx_msg void OnEnChangeEdit3();
	CString m_strLinkAddress;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnNMClickSyslink1(NMHDR* pNMHDR, LRESULT* pResult);
	CLinkCtrl m_linkCtrl;
};
