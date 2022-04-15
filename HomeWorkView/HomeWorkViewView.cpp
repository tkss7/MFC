
// HomeWorkViewView.cpp: CHomeWorkViewView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HomeWorkView.h"
#endif

#include "HomeWorkViewDoc.h"
#include "HomeWorkViewView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHomeWorkViewView

IMPLEMENT_DYNCREATE(CHomeWorkViewView, CView)

BEGIN_MESSAGE_MAP(CHomeWorkViewView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CHomeWorkViewView 생성/소멸

CHomeWorkViewView::CHomeWorkViewView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CHomeWorkViewView::~CHomeWorkViewView()
{
}

BOOL CHomeWorkViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CHomeWorkViewView 그리기

void CHomeWorkViewView::OnDraw(CDC* pDC)
{
	CHomeWorkViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	for (const vector<CPoint>& array : pDoc->m_lines) {


		if (pDoc->m_array.size() >= 1) { // 0은 지워도 됨
			//pDC->MoveTo(pDoc->m_array[0]); 이거쓰면 결과 다름
			pDC->MoveTo(array[0]);
			for (const CPoint& pt : array) {
				pDC->LineTo(pt);
			}
		}
	}
}


// CHomeWorkViewView 인쇄

BOOL CHomeWorkViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CHomeWorkViewView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CHomeWorkViewView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CHomeWorkViewView 진단

#ifdef _DEBUG
void CHomeWorkViewView::AssertValid() const
{
	CView::AssertValid();
}

void CHomeWorkViewView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CHomeWorkViewDoc* CHomeWorkViewView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CHomeWorkViewDoc)));
	return (CHomeWorkViewDoc*)m_pDocument;
}
#endif //_DEBUG


// CHomeWorkViewView 메시지 처리기


void CHomeWorkViewView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CHomeWorkViewDoc* pDoc = GetDocument();
	ReleaseCapture();
	pDoc->m_lines.push_back(pDoc->m_array);//? 이건 주소값 아닌가?...
	pDoc->SetModifiedFlag(); //이거하면 변경사항 저장할지 물어봄

	CView::OnLButtonUp(nFlags, point);
}


void CHomeWorkViewView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CHomeWorkViewDoc* pDoc = GetDocument();
	SetCapture();
	pDoc->m_array.clear();
	pDoc->m_array.push_back(point);

	CView::OnLButtonDown(nFlags, point);
}


void CHomeWorkViewView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON){


	CHomeWorkViewDoc* pDoc = GetDocument();
	CClientDC dc(this);
	dc.MoveTo(pDoc->m_array[pDoc->m_array.size()-1]);
	dc.LineTo(point);


	pDoc->m_array.push_back(point);
	}
	CView::OnMouseMove(nFlags, point);
}
