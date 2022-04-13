
// PrintDemoView.cpp : CPrintDemoView 클래스의 구현
//

#include "stdafx.h"
#include "PrintDemo.h"

#include "PrintDemoDoc.h"
#include "PrintDemoView.h"
#include <atlimage.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPrintDemoView

IMPLEMENT_DYNCREATE(CPrintDemoView, CView)

BEGIN_MESSAGE_MAP(CPrintDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CPrintDemoView 생성/소멸

CPrintDemoView::CPrintDemoView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPrintDemoView::~CPrintDemoView()
{
}

BOOL CPrintDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPrintDemoView 그리기

void CPrintDemoView::OnDraw(CDC* pDC)
{
	CPrintDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	//화면 정보출력
	CString strtmp = _T("");
	strtmp.Format(_T("Pixel (HORZRES:%d VERTRES:%d), mm(HORZSIZE:%d VERTSIZE:%d)"),
		pDC->GetDeviceCaps(HORZRES),	//픽셀단위 수평 해상도
		pDC->GetDeviceCaps(VERTRES),	//픽셀단위 수직 해상도
		pDC->GetDeviceCaps(HORZSIZE),	//mm단위 수평 길이
		pDC->GetDeviceCaps(VERTSIZE));	//mm단위 수직 길이

	//프린터 출력인가?
	if(pDC->IsPrinting())
	{
		//6배 확대하여 출력한다.
		pDC->SetMapMode(MM_ISOTROPIC);
		pDC->SetWindowExt(100, 100);
		pDC->SetViewportExt(600, 600);
	}

	CFont NewFont;
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 24;
	wsprintf(lf.lfFaceName, _T("%s"), _T("Arial"));
	NewFont.CreateFontIndirect(&lf);
	CFont* pOldFont = pDC->SelectObject(&NewFont);

	pDC->TextOut(10, 10, strtmp);
	pDC->MoveTo(0, 130);
	pDC->LineTo(pDC->GetDeviceCaps(HORZRES), 130);

	pDC->SelectObject(pOldFont);
}


// CPrintDemoView 인쇄

BOOL CPrintDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	pInfo->SetMaxPage(3);

	return DoPreparePrinting(pInfo);
}

void CPrintDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPrintDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPrintDemoView 진단

#ifdef _DEBUG
void CPrintDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CPrintDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPrintDemoDoc* CPrintDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPrintDemoDoc)));
	return (CPrintDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CPrintDemoView 메시지 처리기

void CPrintDemoView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	CString strtmp = _T("");

	//6배 확대하여 출력한다.
	pDC->SetMapMode(MM_ISOTROPIC);
	pDC->SetWindowExt(100, 100);
	pDC->SetViewportExt(600, 600);

	//1.머리글 출력

	//2.본문 출력
	strtmp.Format(_T("Current page %d"), pInfo->m_nCurPage);
	CFont NewFont;
	LOGFONT lf;
	::ZeroMemory(&lf, sizeof(lf));
	lf.lfHeight = 36;
	wsprintf(lf.lfFaceName, _T("%s"), _T("Arial"));
	NewFont.CreateFontIndirect(&lf);
	CFont* pOldFont = pDC->SelectObject(&NewFont);

	pDC->TextOut(10, 90, strtmp);
	pDC->SelectObject(pOldFont);

	//샘플 이미지 출력
	CImage Image;
	Image.LoadFromResource(AfxGetInstanceHandle(), IDB_Sample);
	Image.BitBlt(pDC->m_hDC, 10, 150);

	//3. 바닥글 출력

	CView::OnPrint(pDC, pInfo);
}
