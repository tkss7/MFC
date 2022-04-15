
// MapModeDemoView.cpp : CMapModeDemoView 클래스의 구현
//

#include "stdafx.h"
#include "MapModeDemo.h"

#include "MapModeDemoDoc.h"
#include "MapModeDemoView.h"
#include <atlimage.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMapModeDemoView

IMPLEMENT_DYNCREATE(CMapModeDemoView, CView)

BEGIN_MESSAGE_MAP(CMapModeDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

// CMapModeDemoView 생성/소멸

CMapModeDemoView::CMapModeDemoView()
{
	m_nZoomRate = 100;
}

CMapModeDemoView::~CMapModeDemoView()
{
}

BOOL CMapModeDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMapModeDemoView 그리기

void CMapModeDemoView::OnDraw(CDC* /*pDC*/)
{
	CMapModeDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMapModeDemoView 인쇄

BOOL CMapModeDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMapModeDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMapModeDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMapModeDemoView 진단

#ifdef _DEBUG
void CMapModeDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CMapModeDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMapModeDemoDoc* CMapModeDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMapModeDemoDoc)));
	return (CMapModeDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CMapModeDemoView 메시지 처리기

void CMapModeDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	dc.SetMapMode(MM_ISOTROPIC);
	//논리적인 화면DC의 크기를 100*100으로 고정한다.
	dc.SetWindowExt(100, 100);
	//뷰포트의 크기를 변경한다.
	dc.SetViewportExt(m_nZoomRate, m_nZoomRate);
	//픽셀단위 좌표로 300, 300이 논리적 좌표0, 0이 되도록 한다.
	dc.SetViewportOrg(300, 300);

	//xy축을 교차하는 선을 그린다.
	CPen NewPen(PS_SOLID, 15, RGB(192, 0 , 0));
	CPen* pOldPen  = dc.SelectObject(&NewPen);
	dc.MoveTo(-100, 100);
	dc.LineTo(100, -100);
	dc.SelectObject(pOldPen);

	//x, y축에 대한 선을 그린다.
	dc.MoveTo(-1024, 0);
	dc.LineTo(1024, 0);
	dc.MoveTo(0, -1024);
	dc.LineTo(0, 1024);

	//비트맵을 20, 20 좌표에 출력한다.
	CImage Image;
	Image.LoadFromResource(AfxGetInstanceHandle(), IDB_Sample);
	Image.BitBlt(dc.m_hDC, 20, 20);

	//0, 0을 기준으로 각 분면에 문자열을 출력한다.
	dc.TextOut(20, 30, _T("Test1"));
	dc.TextOut(-50, 30, _T("Test2"));
	dc.TextOut(-50, -30, _T("Test3"));
	dc.TextOut(20, -30, _T("Test4"));
}

BOOL CMapModeDemoView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	if((nFlags & MK_CONTROL) != MK_CONTROL)
		return CView::OnMouseWheel(nFlags, zDelta, pt);

	if(zDelta < 0)
	{
		m_nZoomRate += 10;
		if(m_nZoomRate > 300)	m_nZoomRate = 300;
	}
	else
	{
		m_nZoomRate -= 10;
		if(m_nZoomRate < 10)		m_nZoomRate = 10;
	}

	RedrawWindow();

	return CView::OnMouseWheel(nFlags, zDelta, pt);
}
