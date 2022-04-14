
// MouseMsgView.cpp: CMouseMsgView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MouseMsg.h"
#endif

#include "MouseMsgDoc.h"
#include "MouseMsgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMouseMsgView

IMPLEMENT_DYNCREATE(CMouseMsgView, CView)

BEGIN_MESSAGE_MAP(CMouseMsgView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CMouseMsgView 생성/소멸

CMouseMsgView::CMouseMsgView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_bMouseDown = false;
}

CMouseMsgView::~CMouseMsgView()
{
}

BOOL CMouseMsgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMouseMsgView 그리기

void CMouseMsgView::OnDraw(CDC* pDC)//DC : 출력 최상위 클래스
 // 윈도우는 변경될 때 마다 리사이즈 해주는 OnReDraw 함수와 WM_PAINT 메시지가 있다
{
	CMouseMsgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->TextOut(pDoc->m_x,pDoc->m_y,pDoc->m_strText); // 여기서 데이터 3개 있고 이것들은 Document에 정의하는게 정석이다.

	
}


// CMouseMsgView 인쇄

BOOL CMouseMsgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMouseMsgView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMouseMsgView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMouseMsgView 진단

#ifdef _DEBUG
void CMouseMsgView::AssertValid() const
{
	CView::AssertValid();
}

void CMouseMsgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMouseMsgDoc* CMouseMsgView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMouseMsgDoc)));
	return (CMouseMsgDoc*)m_pDocument;
}
#endif //_DEBUG


// CMouseMsgView 메시지 처리기


void CMouseMsgView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	CMouseMsgDoc* pDoc = GetDocument();
	pDoc->m_x = point.x;
	pDoc->m_y = point.y;

	pDoc->SetModifiedFlag(); //문서가 수정되었다고 알림

	m_bMouseDown = true;
	SetCapture();
	Invalidate(); // 현재 화면이 의미가 없으니 다시 그려라 == WM_PAINT 메시지가 현재 나의 윈도우에 전달됨
	// -> 그러면 자동으로 OnDraw가 호출이 된다.
	
	CView::OnLButtonDown(nFlags, point);
}


void CMouseMsgView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//if ((nFlags & MK_LBUTTON) == MK_LBUTTON) // 각 특수키들이 눌릴때 값이 정해져 있어서  앤드 연산자를 통해 맞는게 확인되면  동작
	if(m_bMouseDown)
		// 좌클릭 : 0X01과 우클릭 : 0X03이면 00001 , 00011 의 앤드연산자 = 00001 = 좌클릭이라 같음
	{
		CMouseMsgDoc* pDoc = GetDocument();
		pDoc->m_x = point.x;
		pDoc->m_y = point.y;

		
		pDoc->SetModifiedFlag(); //문서가 수정되었다고 알림

		Invalidate(); // 현재 화면이 의미가 없으니 다시 그려라 == WM_PAINT 메시지가 현재 나의 윈도우에 전달됨
		// -> 그러면 자동으로 OnDraw가 호출이 된다.
	}
	TRACE("%d %d\n", point.x, point.y);
	CView::OnMouseMove(nFlags, point);
}


void CMouseMsgView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bMouseDown = false;
	ReleaseCapture();
	CView::OnLButtonUp(nFlags, point);
}
