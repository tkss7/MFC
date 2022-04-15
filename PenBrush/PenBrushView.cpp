
// PenBrushView.cpp: CPenBrushView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "PenBrush.h"
#endif

#include "PenBrushDoc.h"
#include "PenBrushView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPenBrushView

IMPLEMENT_DYNCREATE(CPenBrushView, CView)

BEGIN_MESSAGE_MAP(CPenBrushView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPenBrushView 생성/소멸

CPenBrushView::CPenBrushView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPenBrushView::~CPenBrushView()
{
}

BOOL CPenBrushView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPenBrushView 그리기

void CPenBrushView::OnDraw(CDC* pDC)
{
	CPenBrushDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

	LOGBRUSH lb;
	lb.lbStyle = BS_SOLID;
	lb.lbColor = RGB(192, 192, 192);
	
	//CPen arNewPen[3];
	//CPen * pOldPen = NULL;
	//arNewPen[0].CreatePen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_ROUND, 20, &lb);
	//arNewPen[1].CreatePen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_SQUARE, 20, &lb);
	//arNewPen[2].CreatePen(PS_GEOMETRIC | PS_SOLID | PS_ENDCAP_FLAT, 20, &lb);

	//pOldPen = pDC->SelectObject(&arNewPen[0]);
	//pDC->MoveTo(40, 40); // 시작 좌표
	//pDC->LineTo(240, 40); //끝좌표
	//pDC->SelectObject(pOldPen); // 회색의 두꺼운 선
	//pDC->MoveTo(40, 40); // 시작 좌표
	//pDC->LineTo(240, 40); //끝좌표


	//pOldPen = pDC->SelectObject(&arNewPen[1]);
	//pDC->MoveTo(40, 140);
	//pDC->LineTo(240, 140);
	//pDC->SelectObject(pOldPen); // 회색의 두꺼운 선
	//pDC->MoveTo(40, 140); // 시작 좌표
	//pDC->LineTo(240, 140); //끝좌표


	//pOldPen = pDC->SelectObject(&arNewPen[2]);
	//pDC->MoveTo(40, 240);
	//pDC->LineTo(240, 240);
	//pDC->SelectObject(pOldPen); // 회색의 두꺼운 선
	//pDC->MoveTo(40, 240); // 시작 좌표
	//pDC->LineTo(240, 240); //끝좌표
	CBitmap Bmp;
	Bmp.LoadBitmap(IDB_BITMAP1); // 리소스 저장하면 에러표시 신경 안써도됨
	//CBrush brush(RGB(255, 0, 255));
	CBrush brush;

	brush.CreatePatternBrush(&Bmp); //로딩된 비트맵 리소스로 패턴 브러시 저장

	CBrush* pOldBrush = pDC->SelectObject(&brush);



	CRect rect;

	GetClientRect(rect);	//현재 클라이언트 영역을 얻는다.
	pDC->Rectangle(rect);

	pDC->Rectangle(100, 100, 200, 200); // 먼저 그려지고 그 위에 그려지므로 만약 네모칸 을 표시하고 싶으면 배경 설정코드 후에 작성하면 된다.

	pDC->SelectObject(pOldBrush);


	
}


// CPenBrushView 인쇄

BOOL CPenBrushView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPenBrushView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPenBrushView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPenBrushView 진단

#ifdef _DEBUG
void CPenBrushView::AssertValid() const
{
	CView::AssertValid();
}

void CPenBrushView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPenBrushDoc* CPenBrushView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPenBrushDoc)));
	return (CPenBrushDoc*)m_pDocument;
}
#endif //_DEBUG


// CPenBrushView 메시지 처리기
