#pragma once


// CFormThird dialog

class CFormThird : public CDialog
{
	DECLARE_DYNAMIC(CFormThird)

public:
	CFormThird(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormThird();

// Dialog Data
	enum { IDD = IDD_Form_Third };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
