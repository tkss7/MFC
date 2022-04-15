#pragma once


// CFormOne dialog

class CFormOne : public CDialog
{
	DECLARE_DYNAMIC(CFormOne)

public:
	CFormOne(CWnd* pParent = NULL);   // standard constructor
	virtual ~CFormOne();

// Dialog Data
	enum { IDD = IDD_Form_One };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
