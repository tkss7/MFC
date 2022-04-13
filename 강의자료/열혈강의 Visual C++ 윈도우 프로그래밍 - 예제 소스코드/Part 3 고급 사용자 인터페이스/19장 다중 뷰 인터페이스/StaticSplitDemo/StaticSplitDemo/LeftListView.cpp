// LeftListView.cpp : implementation file
//

#include "stdafx.h"
#include "StaticSplitDemo.h"
#include "LeftListView.h"


// CLeftListView

IMPLEMENT_DYNCREATE(CLeftListView, CListView)

CLeftListView::CLeftListView()
{

}

CLeftListView::~CLeftListView()
{
}

BEGIN_MESSAGE_MAP(CLeftListView, CListView)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CLeftListView diagnostics

#ifdef _DEBUG
void CLeftListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftListView message handlers

int CLeftListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CListCtrl& List = GetListCtrl();

	List.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 200);
	List.InsertItem(0, _T("Ho-sung Choi"));

	List.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);

	return 0;
}
