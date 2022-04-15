// MyListView.cpp : implementation file
//

#include "stdafx.h"
#include "SwitchViewDemo.h"
#include "MyListView.h"


// CMyListView

IMPLEMENT_DYNCREATE(CMyListView, CListView)

CMyListView::CMyListView()
{

}

CMyListView::~CMyListView()
{
}

BEGIN_MESSAGE_MAP(CMyListView, CListView)
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CMyListView diagnostics

#ifdef _DEBUG
void CMyListView::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyListView::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyListView message handlers

int CMyListView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListView::OnCreate(lpCreateStruct) == -1)
		return -1;

	CListCtrl& List = GetListCtrl();

	List.InsertColumn(0, _T("Name"), LVCFMT_LEFT, 200);
	List.InsertItem(0, _T("Ho-sung Choi"));

	List.ModifyStyle(LVS_TYPEMASK, LVS_REPORT);

	return 0;
}
