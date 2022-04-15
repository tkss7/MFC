
// ImageOverView.cpp : CImageOverView 클래스의 구현
//

#include "stdafx.h"
#include "ImageOver.h"

#include "ImageOverDoc.h"
#include "ImageOverView.h"

#include <atlimage.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageOverView

IMPLEMENT_DYNCREATE(CImageOverView, CView)

BEGIN_MESSAGE_MAP(CImageOverView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CImageOverView 생성/소멸

CImageOverView::CImageOverView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageOverView::~CImageOverView()
{
}

BOOL CImageOverView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CImageOverView 그리기

void CImageOverView::OnDraw(CDC* /*pDC*/)
{
	CImageOverDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CImageOverView 인쇄

BOOL CImageOverView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageOverView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageOverView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CImageOverView 진단

#ifdef _DEBUG
void CImageOverView::AssertValid() const
{
	CView::AssertValid();
}

void CImageOverView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageOverDoc* CImageOverView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageOverDoc)));
	return (CImageOverDoc*)m_pDocument;
}
#endif //_DEBUG


// CImageOverView 메시지 처리기

void CImageOverView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	CImage ImgFront, ImgBack;
	ImgFront.LoadFromResource(AfxGetInstanceHandle(), IDB_Front);
	ImgBack.LoadFromResource(AfxGetInstanceHandle(), IDB_Background);

	CDC* pDC = CDC::FromHandle(ImgFront.GetDC());
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 72;
	wsprintf(lf.lfFaceName, _T("%s"), _T("Arial Black"));
	CFont NewFont;
	NewFont.CreateFontIndirect(&lf);
	CFont* pOldFont = pDC->SelectObject(&NewFont);

	pDC->SetTextColor(RGB(0, 0, 0));
	pDC->SetBkMode(TRANSPARENT);
	pDC->TextOut(10, 170, _T("IMAGE OVER")); 
	pDC->TextOut(10, 200, _T("IMAGE OVER")); 

	pDC->SelectObject(pOldFont);
	ImgFront.ReleaseDC();

	ImgBack.BitBlt(dc.m_hDC, 0, 150);
	ImgFront.TransparentBlt(dc.m_hDC, 50, 0, ImgFront.GetWidth(), ImgFront.GetHeight(), RGB(0, 0, 0));
}
