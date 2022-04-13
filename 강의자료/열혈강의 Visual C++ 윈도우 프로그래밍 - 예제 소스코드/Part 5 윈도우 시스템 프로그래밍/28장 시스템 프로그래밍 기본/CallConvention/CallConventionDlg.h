// CallConventionDlg.h : header file
//

#if !defined(AFX_CALLCONVENTIONDLG_H__EB12DF95_39F9_4B82_A0AF_12A62072A826__INCLUDED_)
#define AFX_CALLCONVENTIONDLG_H__EB12DF95_39F9_4B82_A0AF_12A62072A826__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCallConventionDlg dialog

class CCallConventionDlg : public CDialog
{
// Construction
public:
	CCallConventionDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCallConventionDlg)
	enum { IDD = IDD_CALLCONVENTION_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCallConventionDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCallConventionDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtoncdecl();
	afx_msg void OnButtonstdcall();
	afx_msg void OnButtonfastcall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALLCONVENTIONDLG_H__EB12DF95_39F9_4B82_A0AF_12A62072A826__INCLUDED_)
