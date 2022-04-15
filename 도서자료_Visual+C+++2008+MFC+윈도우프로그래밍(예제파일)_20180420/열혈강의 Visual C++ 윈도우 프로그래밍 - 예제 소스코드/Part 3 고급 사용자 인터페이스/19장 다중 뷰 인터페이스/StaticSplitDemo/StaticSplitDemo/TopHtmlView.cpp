// TopHtmlView.cpp : implementation file
//

#include "stdafx.h"
#include "StaticSplitDemo.h"
#include "TopHtmlView.h"


// CTopHtmlView

IMPLEMENT_DYNCREATE(CTopHtmlView, CHtmlView)

CTopHtmlView::CTopHtmlView()
{

}

CTopHtmlView::~CTopHtmlView()
{
}

void CTopHtmlView::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTopHtmlView, CHtmlView)
END_MESSAGE_MAP()


// CTopHtmlView diagnostics

#ifdef _DEBUG
void CTopHtmlView::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CTopHtmlView::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG


// CTopHtmlView message handlers

void CTopHtmlView::OnInitialUpdate()
{
	CHtmlView::OnInitialUpdate();

	Navigate2(_T("C:\\"));
}
