#pragma once


// CModalDlg dialog

class CModalDlg : public CDialog
{
	DECLARE_DYNAMIC(CModalDlg)

public:
	CModalDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CModalDlg();

// Dialog Data
	enum { IDD = IDD_Dialog_Modal };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
};
