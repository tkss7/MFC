
// FrameRgnView.cpp : CFrameRgnView 클래스의 구현
//

#include "stdafx.h"
#include "FrameRgn.h"

#include "FrameRgnDoc.h"
#include "FrameRgnView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFrameRgnView

IMPLEMENT_DYNCREATE(CFrameRgnView, CView)

BEGIN_MESSAGE_MAP(CFrameRgnView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CFrameRgnView 생성/소멸

CFrameRgnView::CFrameRgnView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CFrameRgnView::~CFrameRgnView()
{
}

BOOL CFrameRgnView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CFrameRgnView 그리기

void CFrameRgnView::OnDraw(CDC* /*pDC*/)
{
	CFrameRgnDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CFrameRgnView 인쇄

BOOL CFrameRgnView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CFrameRgnView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CFrameRgnView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CFrameRgnView 진단

#ifdef _DEBUG
void CFrameRgnView::AssertValid() const
{
	CView::AssertValid();
}

void CFrameRgnView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFrameRgnDoc* CFrameRgnView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFrameRgnDoc)));
	return (CFrameRgnDoc*)m_pDocument;
}
#endif //_DEBUG


// CFrameRgnView 메시지 처리기
