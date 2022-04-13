// TrackWnd.cpp : implementation file
//

#include "stdafx.h"
#include "MouseCombi.h"
#include "TrackWnd.h"


// CTrackWnd

IMPLEMENT_DYNAMIC(CTrackWnd, CWnd)

CTrackWnd::CTrackWnd()
{
	m_bTrack = FALSE;
}

CTrackWnd::~CTrackWnd()
{
}


BEGIN_MESSAGE_MAP(CTrackWnd, CWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_MOUSELEAVE()
END_MESSAGE_MAP()



// CTrackWnd message handlers



void CTrackWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_bTrack == FALSE)
	{
		TRACKMOUSEEVENT MouseEvent;
		::ZeroMemory(&MouseEvent, sizeof(MouseEvent));

		MouseEvent.cbSize		= sizeof(MouseEvent);
		MouseEvent.dwFlags		= TME_LEAVE;
		MouseEvent.hwndTrack	= m_hWnd;
		MouseEvent.dwHoverTime	= 0;

		m_bTrack = ::_TrackMouseEvent(&MouseEvent);
		if(m_bTrack)
		{
			SetWindowText(TEXT("Tracking!"));
		}
	}

	CWnd::OnMouseMove(nFlags, point);
}

void CTrackWnd::OnMouseLeave()
{
	TRACKMOUSEEVENT MouseEvent;
	::ZeroMemory(&MouseEvent, sizeof(MouseEvent));

	MouseEvent.cbSize		= sizeof(MouseEvent);
	MouseEvent.dwFlags		= TME_CANCEL;
	MouseEvent.hwndTrack	= m_hWnd;

	::_TrackMouseEvent(&MouseEvent);

	m_bTrack = FALSE;
	SetWindowText(TEXT("WM_MOUSELEAVE"));

	CWnd::OnMouseLeave();
}

