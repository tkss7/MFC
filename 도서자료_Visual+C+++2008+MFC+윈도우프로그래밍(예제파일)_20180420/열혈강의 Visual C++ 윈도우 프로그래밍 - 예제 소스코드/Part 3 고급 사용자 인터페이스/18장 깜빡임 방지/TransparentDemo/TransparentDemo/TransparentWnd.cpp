// TransparentWnd.cpp : implementation file
//

#include "stdafx.h"
#include "TransparentDemo.h"
#include "TransparentWnd.h"


// CTransparentWnd

IMPLEMENT_DYNAMIC(CTransparentWnd, CWnd)

CTransparentWnd::CTransparentWnd()
{
	WNDCLASS wndcls;
	HINSTANCE hInst = AfxGetInstanceHandle();

	wndcls.style            = CS_DBLCLKS | CS_HREDRAW | CS_VREDRAW;
	wndcls.lpfnWndProc      = ::DefWindowProc;
	wndcls.cbClsExtra       = wndcls.cbWndExtra = 0;
	wndcls.hInstance        = hInst;
	wndcls.hIcon            = NULL;
	wndcls.hCursor          = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
	wndcls.hbrBackground    = (HBRUSH) (COLOR_3DFACE + 1);
	wndcls.lpszMenuName     = NULL;
	wndcls.lpszClassName    = TEXT("TRANSPARENT_WINDOW_DEOM");

	AfxRegisterClass(&wndcls);
}

CTransparentWnd::~CTransparentWnd()
{
}


BEGIN_MESSAGE_MAP(CTransparentWnd, CWnd)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CTransparentWnd message handlers



BOOL CTransparentWnd::OnEraseBkgnd(CDC* pDC)
{
	CRect Rect, ParentRect;
	GetClientRect(&Rect);
	GetParent()->GetClientRect(&ParentRect);

	CPoint ptLeftTop = CPoint(0, 0);
	ClientToScreen(&ptLeftTop);
	GetParent()->ScreenToClient(&ptLeftTop);

	CDC MemDC;
	CBitmap Bmp;

	MemDC.CreateCompatibleDC(NULL);
	Bmp.CreateBitmap(ParentRect.Width(), ParentRect.Height(),
						MemDC.GetDeviceCaps(PLANES),
						MemDC.GetDeviceCaps(BITSPIXEL), NULL);
	CBitmap* pOldBmp = MemDC.SelectObject(&Bmp);

	GetParent()->SendMessage(WM_ERASEBKGND, (WPARAM)MemDC.m_hDC);
	pDC->BitBlt(0, 0, Rect.Width(), Rect.Height(),
						&MemDC, ptLeftTop.x, ptLeftTop.y, SRCCOPY);

	MemDC.SelectObject(pOldBmp);

	return TRUE;
//	return CWnd::OnEraseBkgnd(pDC);
}

void CTransparentWnd::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(192, 0, 0));
	dc.TextOut(10, 10, _T("TEST STRING!"));
}
