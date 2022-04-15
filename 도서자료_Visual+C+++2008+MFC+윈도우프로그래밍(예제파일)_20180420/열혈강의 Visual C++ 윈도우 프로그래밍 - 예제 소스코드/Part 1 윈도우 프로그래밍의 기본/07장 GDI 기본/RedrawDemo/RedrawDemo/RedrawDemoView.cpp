
// RedrawDemoView.cpp : CRedrawDemoView 클래스의 구현
//

#include "stdafx.h"
#include "RedrawDemo.h"

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
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CRedrawDemoView 생성/소멸

CRedrawDemoView::CRedrawDemoView()
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

void CRedrawDemoView::OnDraw(CDC* /*pDC*/)
{
	CRedrawDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
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

void CRedrawDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//DC를 얻는다.
	CDC* pDC = GetDC();
	//주어진 좌표에 네모를 그린다.
	pDC->Rectangle(10, 10, 110, 110);
	//DC를 반환한다.
	ReleaseDC(pDC);

	CView::OnLButtonDown(nFlags, point);
}

void CRedrawDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	//두께가 3픽셀인 붉은 색 펜을 생성한다.
	CPen NewPen(PS_SOLID, 3, RGB(192, 0, 0));
	//생성한 펜을 DC의 현재 펜으로 변경하고 기존 펜 객체에 대한
	//포인터를 별도로 저장해둔다.
	CPen* pOldPen = dc.SelectObject(&NewPen);

	//새로운 브러시를 생성하여 선택한다.
	CBrush NewBrush(RGB(192, 192, 192));
	CBrush* pOldBrush = dc.SelectObject(&NewBrush);

	//그리기 작업을 수행한다.
	dc.Rectangle(120, 10, 220, 110);

	//예전 펜을 현재 펜으로 바꾼다.
	dc.SelectObject(pOldPen);
	//예전 브러시로 현재 브러시를 바꾼다.
	dc.SelectObject(pOldBrush);
}
