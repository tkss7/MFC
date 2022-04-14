
// RedrawDemoView.cpp: CRedrawDemoView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "RedrawDemo.h"
#endif

#include "RedrawDemoDoc.h"
#include "RedrawDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRedrawDemoView

IMPLEMENT_DYNCREATE(CRedrawDemoView, CView)

BEGIN_MESSAGE_MAP(CRedrawDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
//	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_MBUTTONUP()
END_MESSAGE_MAP()

// CRedrawDemoView 생성/소멸

CRedrawDemoView::CRedrawDemoView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CRedrawDemoView::~CRedrawDemoView()
{
}

BOOL CRedrawDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CRedrawDemoView 그리기

void CRedrawDemoView::OnDraw(CDC* pDC)
{
	CRedrawDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CPen pen(PS_SOLID, pDoc->Bold, pDoc->m_lineColor); //직선 10포인트 빨간색
	CPen* pOldPen = pDC->SelectObject(&pen);
	///////////////////////////////////////////////////////////////////////////////////////
	//for (const CPoint& pt : pDoc->m_array) {
	//	pDC->Rectangle(pt.x, pt.y, pt.x+100, pt.y+100);
	//}
	//pDC->Rectangle(100, 100, 200, 200);
	///////////////////////////////////////////////////////////////////////////////////////

	for (const CPoint& pt : pDoc->m_array) {
		pDC->Rectangle(pt.x, pt.y, pt.x+100, pt.y+100);
	}

	//CPen pen2(PS_SOLID, 10, RGB(255, 0, 0));
	//CPen* pOldPen2 = pDC->SelectObject(&pen2);

	//if (pDoc->m_array.size() > 0) {
	//	const CPoint& pt = pDoc->m_array[0];
	//	pDC->MoveTo(pt.x, pt.y);
	//	for (const CPoint& pt : pDoc->m_array) {
	//		pDC->LineTo(pt.x, pt.y);
	//	}
	//}

	pDC->SelectObject(pOldPen);
}


// CRedrawDemoView 인쇄

BOOL CRedrawDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CRedrawDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CRedrawDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CRedrawDemoView 진단

#ifdef _DEBUG
void CRedrawDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CRedrawDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRedrawDemoDoc* CRedrawDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRedrawDemoDoc)));
	return (CRedrawDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CRedrawDemoView 메시지 처리기

void CRedrawDemoView::Draw(int x, int y, CDC* pDc)
{
	pDc->TextOut(x, y, _T("안녕하세요"));
}

//void CRedrawDemoView::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting // 이 클래스를 가지고 DC를 얻는다
//					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
//					   // 그리기 메시지에 대해서는 CView::OnPaint()을(를) 호출하지 마십시오.
//	//dc.TextOut(100, 100, _T("안녕하세요"));
//	Draw(100, 100, &dc);
//}


void CRedrawDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CRedrawDemoDoc* pDoc = GetDocument();
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this); // DC는 장치에 관련된 정보를 갖고 있다. , CDC == 그림그리는 최상위 클래스
	// 이건 내가만든 뷰 영역을 가리킴
	//dc.TextOut(point.x, point.y, _T("Hello World"));

	//Draw(point.x, point.y, &dc);
	///////////////////////////////////////////////////////////////////////////////////////////
	CPen pen(PS_SOLID, 10, RGB(255, 0, 0)); //직선 10포인트 빨간색
	CPen* pOldPen = dc.SelectObject(&pen);
	dc.Rectangle(point.x, point.y, point.x+100, point.y+100);
	dc.SelectObject(pOldPen);
	pDoc->m_array.push_back(point);
	//Invalidate();
	/////////////////////////////////////////////////////////////////////////////////////////////

	pDoc->m_array.clear();
	pDoc->m_array.push_back(point);


	CView::OnLButtonDown(nFlags, point);
}


void CRedrawDemoView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	


	CView::OnMouseMove(nFlags, point);
}


void CRedrawDemoView::OnMButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CView::OnMButtonUp(nFlags, point);
}
