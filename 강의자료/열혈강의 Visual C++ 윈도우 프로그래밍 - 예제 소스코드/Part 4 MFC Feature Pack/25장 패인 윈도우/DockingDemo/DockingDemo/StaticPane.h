#pragma once


// CStaticPane

class CStaticPane : public CDockablePane
{
	DECLARE_DYNAMIC(CStaticPane)

public:
	CStaticPane();
	virtual ~CStaticPane();

	CWnd		m_wndChild;

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


