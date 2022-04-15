// MyHtmlView.cpp : implementation file
//

#include "stdafx.h"
#include "SwitchViewDemo.h"
#include "MyHtmlView.h"


// CMyHtmlView

IMPLEMENT_DYNCREATE(CMyHtmlView, CHtmlView)

CMyHtmlView::CMyHtmlView()
{

}

CMyHtmlView::~CMyHtmlView()
{
}

void CMyHtmlView::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMyHtmlView, CHtmlView)
END_MESSAGE_MAP()


// CMyHtmlView diagnostics

#ifdef _DEBUG
void CMyHtmlView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CMyHtmlView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG


// CMyHtmlView message handlers

void CMyHtmlView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("C:\\"));
}
