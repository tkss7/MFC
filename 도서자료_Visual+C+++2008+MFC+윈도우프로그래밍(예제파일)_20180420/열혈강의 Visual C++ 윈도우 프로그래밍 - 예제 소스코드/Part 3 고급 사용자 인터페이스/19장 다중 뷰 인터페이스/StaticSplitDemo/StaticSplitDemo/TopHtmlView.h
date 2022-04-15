#pragma once

#ifdef _WIN32_WCE
#error "CHtmlView is not supported for Windows CE."
#endif 

// CTopHtmlView html view

class CTopHtmlView : public CHtmlView
{
	DECLARE_DYNCREATE(CTopHtmlView)

protected:
	CTopHtmlView();           // protected constructor used by dynamic creation
	virtual ~CTopHtmlView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
};


