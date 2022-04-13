
// TimerDemoView.cpp : CTimerDemoView 클래스의 구현
//

#include "stdafx.h"
#include "TimerDemo.h"

#include "TimerDemoDoc.h"
#include "TimerDemoView.h"

#include <atlimage.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTimerDemoView

IMPLEMENT_DYNCREATE(CTimerDemoView, CView)

BEGIN_MESSAGE_MAP(CTimerDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CTimerDemoView 생성/소멸

CTimerDemoView::CTimerDemoView()
{
	m_nImageX = 0;
	m_nImageY = 0;
}

CTimerDemoView::~CTimerDemoView()
{
}

BOOL CTimerDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTimerDemoView 그리기

void CTimerDemoView::OnDraw(CDC* /*pDC*/)
{
	CTimerDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CTimerDemoView 인쇄

BOOL CTimerDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTimerDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTimerDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CTimerDemoView 진단

#ifdef _DEBUG
void CTimerDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CTimerDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTimerDemoDoc* CTimerDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTimerDemoDoc)));
	return (CTimerDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CTimerDemoView 메시지 처리기

int CTimerDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	if(SetTimer(10, 1000, NULL) != 10)
	{
		AfxMessageBox(_T("ERROR: Failed to set timer!"));
	}

	srand( (unsigned)time( NULL ) );
	return 0;
}

void CTimerDemoView::OnClose()
{
	KillTimer(10);

	CView::OnClose();
}

void CTimerDemoView::OnTimer(UINT_PTR nIDEvent)
{
	if(nIDEvent == 10)
	{
		CRect Rect;
		GetClientRect(&Rect);

		if(Rect.Width() != 0 && Rect.Height() != 0)
		{
			m_nImageX = rand() % Rect.Width();
			m_nImageY = rand() % Rect.Height();
			RedrawWindow(NULL, NULL, RDW_INVALIDATE | RDW_UPDATENOW);
		}
	}

	CView::OnTimer(nIDEvent);
}

void CTimerDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CRect Rect;
	GetClientRect(&Rect);
	dc.FillSolidRect(&Rect, RGB(0, 0, 0));

	CImage Image;
	Image.LoadFromResource(AfxGetInstanceHandle(), IDB_WinXP);
	Image.BitBlt(dc.m_hDC, m_nImageX, m_nImageY, SRCCOPY);
}
