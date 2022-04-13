#pragma once


// CLeftListView view

class CLeftListView : public CListView
{
	DECLARE_DYNCREATE(CLeftListView)

protected:
	CLeftListView();           // protected constructor used by dynamic creation
	virtual ~CLeftListView();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};


