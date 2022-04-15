#pragma once


// CFormSecond dialog

class CFormSecond : public CDialog
{
	DECLARE_DYNAMIC(CFormSecond)

public:
	CFormSecond(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormSecond();

// Dialog Data
	enum { IDD = IDD_Form_Second };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
