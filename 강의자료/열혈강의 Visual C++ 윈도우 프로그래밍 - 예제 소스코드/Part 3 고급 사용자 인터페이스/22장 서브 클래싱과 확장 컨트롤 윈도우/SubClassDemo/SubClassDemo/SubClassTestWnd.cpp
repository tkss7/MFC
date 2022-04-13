// SubClassTestWnd.cpp : implementation file
//

#include "stdafx.h"
#include "SubClassDemo.h"
#include "SubClassTestWnd.h"


// CSubClassTestWnd

IMPLEMENT_DYNAMIC(CSubClassTestWnd, CWnd)

CSubClassTestWnd::CSubClassTestWnd()
{
	m_bFlag = TRUE;
}

CSubClassTestWnd::~CSubClassTestWnd()
{
}


BEGIN_MESSAGE_MAP(CSubClassTestWnd, CWnd)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_DESTROY()
END_MESSAGE_MAP()



// CSubClassTestWnd message handlers



void CSubClassTestWnd::OnPaint()
{
	CWnd::OnPaint();

	CClientDC dc(this);

	CRect Rect(3, 3, 16, 16);
	if(m_bFlag)		dc.FillSolidRect(&Rect, RGB(192, 0, 0));
	else			dc.FillSolidRect(&Rect, RGB(255, 255, 255));
}

void CSubClassTestWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	CWnd::OnLButtonDown(nFlags, point);

	CRect Rect(3, 3, 16, 16);
	if(PtInRect(&Rect, point))
	{
		m_bFlag = !m_bFlag;
		RedrawWindow();
	}
}

void CSubClassTestWnd::OnDestroy()
{
	UnsubclassWindow();

	CWnd::OnDestroy();
}
