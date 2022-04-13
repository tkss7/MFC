// MySliderCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "RangeDemo.h"
#include "MySliderCtrl.h"


// CMySliderCtrl

IMPLEMENT_DYNAMIC(CMySliderCtrl, CSliderCtrl)

CMySliderCtrl::CMySliderCtrl()
{
	m_pProgress = NULL;
	m_bSelected = FALSE;
}

CMySliderCtrl::~CMySliderCtrl()
{
}


BEGIN_MESSAGE_MAP(CMySliderCtrl, CSliderCtrl)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()



// CMySliderCtrl message handlers



void CMySliderCtrl::OnMouseMove(UINT nFlags, CPoint point)
{
	CSliderCtrl::OnMouseMove(nFlags, point);

	if(m_bSelected && m_pProgress != NULL)
	{
		int nPos = GetPos() * 5;
		m_pProgress->SetPos(nPos);
	}
}

void CMySliderCtrl::SetProgress(CProgressCtrl* pProgress)
{
	m_pProgress = pProgress;
}

void CMySliderCtrl::OnLButtonDown(UINT nFlags, CPoint point)
{
	CRect Rect;
	GetThumbRect(&Rect);

	if(Rect.PtInRect(point))	m_bSelected = TRUE;
	else						m_bSelected = FALSE;

	CSliderCtrl::OnLButtonDown(nFlags, point);
}

void CMySliderCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
	m_bSelected = FALSE;
	CSliderCtrl::OnLButtonUp(nFlags, point);
}
