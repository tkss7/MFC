// StaticPane.cpp : implementation file
//

#include "stdafx.h"
#include "DockingDemo.h"
#include "StaticPane.h"


// CStaticPane

IMPLEMENT_DYNAMIC(CStaticPane, CDockablePane)

CStaticPane::CStaticPane()
{

}

CStaticPane::~CStaticPane()
{
}


BEGIN_MESSAGE_MAP(CStaticPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CStaticPane message handlers



int CStaticPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_wndChild.Create(_T("STATIC"), _T("Dockable pane window"),
					WS_CHILD | WS_VISIBLE, CRect(0, 0, 0, 0), this, 1234);

	return 0;
}

void CStaticPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	if(m_wndChild.GetSafeHwnd())
	{
		m_wndChild.SetWindowPos(NULL, 0, 0, cx, cy, SWP_NOZORDER);
	}
}
