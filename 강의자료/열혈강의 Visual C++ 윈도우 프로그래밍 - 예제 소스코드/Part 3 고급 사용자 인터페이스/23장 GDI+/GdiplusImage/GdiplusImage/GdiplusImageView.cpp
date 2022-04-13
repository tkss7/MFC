
// GdiplusImageView.cpp : CGdiplusImageView 클래스의 구현
//

#include "stdafx.h"
#include "GdiplusImage.h"

#include "GdiplusImageDoc.h"
#include "GdiplusImageView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiplusImageView

IMPLEMENT_DYNCREATE(CGdiplusImageView, CView)

BEGIN_MESSAGE_MAP(CGdiplusImageView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CGdiplusImageView 생성/소멸

CGdiplusImageView::CGdiplusImageView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CGdiplusImageView::~CGdiplusImageView()
{
}

BOOL CGdiplusImageView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CGdiplusImageView 그리기

void CGdiplusImageView::OnDraw(CDC* /*pDC*/)
{
	CGdiplusImageDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CGdiplusImageView 인쇄

BOOL CGdiplusImageView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CGdiplusImageView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CGdiplusImageView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CGdiplusImageView 진단

#ifdef _DEBUG
void CGdiplusImageView::AssertValid() const
{
	CView::AssertValid();
}

void CGdiplusImageView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGdiplusImageDoc* CGdiplusImageView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGdiplusImageDoc)));
	return (CGdiplusImageDoc*)m_pDocument;
}
#endif //_DEBUG


// CGdiplusImageView 메시지 처리기

void CGdiplusImageView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Bitmap bmp(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_Sample));
	CachedBitmap cachedbmp(&bmp, &graphics);

	CString strTmp = _T("");
	LARGE_INTEGER	lnFreq, lnStart, lnEnd, lnResult;
	::QueryPerformanceFrequency(&lnFreq);

	::QueryPerformanceCounter(&lnStart);
	graphics.DrawImage(&bmp, 10, 10);
	::QueryPerformanceCounter(&lnEnd);
	lnResult.QuadPart = (lnEnd.QuadPart - lnStart.QuadPart) * 1000000 / lnFreq.QuadPart;
	strTmp.Format(_T("DrawImage() counter %u"), lnResult.QuadPart);
	dc.TextOut(10, 10, strTmp);

	::QueryPerformanceCounter(&lnStart);
	graphics.DrawCachedBitmap(&cachedbmp, bmp.GetWidth() + 20, 10);
	::QueryPerformanceCounter(&lnEnd);
	lnResult.QuadPart = (lnEnd.QuadPart - lnStart.QuadPart) * 1000000 / lnFreq.QuadPart;
	strTmp.Format(_T("DrawCachedBitmap() counter %u"), lnResult.QuadPart);
	dc.TextOut(bmp.GetWidth() + 20, 10, strTmp);
}

/*
	Image image(_T("Woojin.jpg"));
	graphics.DrawImage(&image, 0, 0);
*/

/*
	graphics.DrawImage(&image, 0, 0);

	graphics.DrawImage(&image,
					100, 50,
					image.GetWidth() / 4,
					image.GetHeight() / 4);
*/

/*
	Image image(_T("Woojin.jpg"));

	Point points[] = {
		Point(200, 0),
		Point(image.GetWidth(), 0),
		Point(0, image.GetHeight())
	};

	graphics.DrawImage(&image, points, 3);
*/

/*
	Bitmap bmp(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_Sample));
	CachedBitmap cachedbmp(&bmp, &graphics);

	graphics.DrawImage(&bmp, 10, 10);
	graphics.DrawCachedBitmap(&cachedbmp, bmp.GetWidth() + 20, 10);
*/

/*
	Graphics graphics(dc);
	graphics.SetSmoothingMode(SmoothingModeHighQuality);

	Bitmap bmp(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_Sample));
	CachedBitmap cachedbmp(&bmp, &graphics);

	CString strTmp = _T("");
	LARGE_INTEGER	lnFreq, lnStart, lnEnd, lnResult;
	::QueryPerformanceFrequency(&lnFreq);

	::QueryPerformanceCounter(&lnStart);
	graphics.DrawImage(&bmp, 10, 10);
	::QueryPerformanceCounter(&lnEnd);
	lnResult.QuadPart = (lnEnd.QuadPart - lnStart.QuadPart) * 1000000 / lnFreq.QuadPart;
	strTmp.Format(_T("DrawImage() counter %u\n"), lnResult.QuadPart);
	OutputDebugString(strTmp);

	::QueryPerformanceCounter(&lnStart);
	graphics.DrawCachedBitmap(&cachedbmp, bmp.GetWidth() + 20, 10);
	::QueryPerformanceCounter(&lnEnd);
	lnResult.QuadPart = (lnEnd.QuadPart - lnStart.QuadPart) * 1000000 / lnFreq.QuadPart;
	strTmp.Format(_T("DrawCachedBitmap() counter %u\n"), lnResult.QuadPart);
*/