
// PenBrushDemoView.cpp : CPenBrushDemoView 클래스의 구현
//

#include "stdafx.h"
#include "PenBrushDemo.h"

#include "PenBrushDemoDoc.h"
#include "PenBrushDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPenBrushDemoView

IMPLEMENT_DYNCREATE(CPenBrushDemoView, CView)

BEGIN_MESSAGE_MAP(CPenBrushDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CPenBrushDemoView 생성/소멸

CPenBrushDemoView::CPenBrushDemoView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPenBrushDemoView::~CPenBrushDemoView()
{
}

BOOL CPenBrushDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPenBrushDemoView 그리기

void CPenBrushDemoView::OnDraw(CDC* /*pDC*/)
{
	CPenBrushDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPenBrushDemoView 인쇄

BOOL CPenBrushDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPenBrushDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPenBrushDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPenBrushDemoView 진단

#ifdef _DEBUG
void CPenBrushDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CPenBrushDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPenBrushDemoDoc* CPenBrushDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPenBrushDemoDoc)));
	return (CPenBrushDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CPenBrushDemoView 메시지 처리기

void CPenBrushDemoView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CBrush NewBrush;
	//비트맵 클래스 객체를 선언하여 비트맵 리소스 로딩.
	CBitmap Bmp;
	Bmp.LoadBitmap(IDB_BITMAP1);
	//로딩된 비트맵 리소스로 패턴 브러시 생성.
	NewBrush.CreatePatternBrush(&Bmp);
	CBrush* pOldBrush = dc.SelectObject(&NewBrush);

	//클라이언트 뷰 클래스의 클라이언트 영역 크기를 알아내고
	//그 크기에 해당하는 네모를 그림.
	CRect Rect;
	GetClientRect(&Rect);
	dc.Rectangle(&Rect);

	dc.SelectObject(pOldBrush);

	DWORD style[] = {6, 3};
	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(255, 0, 0);

	CPen NewPen;
	NewPen.CreatePen(PS_GEOMETRIC | PS_USERSTYLE | PS_ENDCAP_FLAT,
						10, &lb, 2, style);
	CPen* pOldPen = dc.SelectObject(&NewPen);

	//두께가 20픽셀인 선을 긋는다.
	dc.MoveTo(40, 40);		//시작 좌표
	dc.LineTo(240, 40);		//끝 좌표

	dc.SelectObject(pOldPen);
}

/*
	CPen NewPen(PS_SOLID, 20, RGB(192, 192, 192);
	CPen* pOldPen = dc.SelectObject(&NewPen);

	//두께가 20픽셀인 선을 긋는다.
	dc.MoveTo(40, 40);		//시작 좌표
	dc.LineTo(240, 40);		//끝 좌표

	dc.SelectObject(pOldPen);

	//본래의 펜(두께 1, 검정)으로 동일한 선을 겺쳐 긋는다.
	dc.MoveTo(40, 40);		//시작 좌표
	dc.LineTo(240, 40);		//끝 좌표
*/

/*
	CBrush NewBrush;
	//비트맵 클래스 객체를 선언하여 비트맵 리소스 로딩.
	CBitmap Bmp;
	Bmp.LoadBitmap(IDB_BITMAP1);
	//로딩된 비트맵 리소스로 패턴 브러시 생성.
	NewBrush.CreatePatternBrush(&Bmp);
	CBrush* pOldBrush = dc.SelectObject(&NewBrush);

	//클라이언트 뷰 클래스의 클라이언트 영역 크기를 알아내고
	//그 크기에 해당하는 네모를 그림.
	CRect Rect;
	GetClientRect(&Rect);
	dc.Rectangle(&Rect);

	dc.SelectObject(pOldBrush);
*/

/*	//해치 브러시 예
	CBrush NewBrush(HS_CROSS, RGB(192, 0, 0));
	CBrush* pOldBrush = dc.SelectObject(&NewBrush);

	dc.Rectangle(20, 20, 140, 140);

	dc.SelectObject(pOldBrush);
*/

/*	//PS_USERSTYLE 예
	DWORD style[] = {6, 3};
	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(255, 0, 0);

	CPen NewPen;
	NewPen.CreatePen(PS_GEOMETRIC | PS_USERSTYLE | PS_ENDCAP_FLAT,
						10, &lb, 2, style);
	CPen* pOldPen = dc.SelectObject(&NewPen);

	//두께가 20픽셀인 선을 긋는다.
	dc.MoveTo(40, 40);		//시작 좌표
	dc.LineTo(240, 40);		//끝 좌표

	dc.SelectObject(pOldPen);
*/

/*	//시작/끝 부분처리 예
	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(192, 192, 192);

	CPen arNewPen[3];
	CPen* pOldPen = NULL;
	arNewPen[0].CreatePen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_ROUND, 20, &lb);
	arNewPen[1].CreatePen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_SQUARE, 20, &lb);
	arNewPen[2].CreatePen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT, 20, &lb);

	for(int i = 0; i < 3; ++i)
	{
		pOldPen = dc.SelectObject(&arNewPen[i]);
		dc.MoveTo(40, 40 * (i + 1));		//시작 좌표
		dc.LineTo(240, 40 * (i + 1));		//끝 좌표

		dc.SelectObject(pOldPen);
//		dc.MoveTo(40, 40 * (i + 1));		//시작 좌표
//		dc.LineTo(240, 40 * (i + 1));		//끝 좌표

		arNewPen[i].DeleteObject();
	}
*/