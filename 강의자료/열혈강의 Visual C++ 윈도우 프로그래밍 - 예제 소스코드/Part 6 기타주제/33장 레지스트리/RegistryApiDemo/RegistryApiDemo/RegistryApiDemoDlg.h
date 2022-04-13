
// RegistryApiDemoDlg.h : 헤더 파일
//

#pragma once

typedef struct _TEST_DATA
{
	int			nType;
	DWORD		dwData;
	TCHAR		szData[64];
} TEST_DATA;


// CRegistryApiDemoDlg 대화 상자
class CRegistryApiDemoDlg : public CDialog
{
// 생성입니다.
public:
	CRegistryApiDemoDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_REGISTRYAPIDEMO_DIALOG };

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
	afx_msg void OnBnClickedButtonCreatekey();
	afx_msg void OnBnClickedButtonSetname();
	CString m_strName;
	DWORD m_dwNumber;
	afx_msg void OnBnClickedButtonSetnumber();
	afx_msg void OnBnClickedButtonSetdata();
	afx_msg void OnBnClickedButtonLoadall();
};
