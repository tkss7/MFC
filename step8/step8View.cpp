
// step8View.cpp: Cstep8View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "step8.h"
#endif

#include "step8Doc.h"
#include "step8View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cstep8View

IMPLEMENT_DYNCREATE(Cstep8View, CView)

BEGIN_MESSAGE_MAP(Cstep8View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cstep8View 생성/소멸

Cstep8View::Cstep8View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
}

Cstep8View::~Cstep8View()
{
}

BOOL Cstep8View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cstep8View 그리기

void Cstep8View::OnDraw(CDC* /*pDC*/)
{
	Cstep8Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Cstep8View 인쇄

BOOL Cstep8View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cstep8View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cstep8View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// Cstep8View 진단

#ifdef _DEBUG
void Cstep8View::AssertValid() const
{
	CView::AssertValid();
}

void Cstep8View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cstep8Doc* Cstep8View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cstep8Doc)));
	return (Cstep8Doc*)m_pDocument;
}
#endif //_DEBUG


// Cstep8View 메시지 처리기


void Cstep8View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) // 컨트롤키 == 플래그를 사용
{
	
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//m_wndChild.MoveWindow(CRect(200, 200, 300, 240));
	CRect rect;
	CPoint pt;
/*
	VK_CONTROL = 0000100
	0001010
&    AND게이트 생각하면 될꺼 같다....
	0000100

==  0000100 or 0000000
*/
	if ((nFlags & VK_CONTROL) == VK_CONTROL) {
		m_wndChild.SetWindowText(_T("Hello World")); // 버튼안의 글자가 바뀜 // 즉 누를때 마다 바뀐다.
		TRACE("%d called\n", i++);
	}

	

	m_wndChild.GetWindowRect(rect);
	pt = rect.TopLeft();
	rect.Width();
	rect.Height();


	//AfxGetMainWnd()->SetWindowText(_T("Hello World")); // 메인 프레임의 제목부분이 바뀜


	switch(nChar) {
		case VK_LEFT:
			pt.x -= 10;
			break;
		case VK_RIGHT:
			pt.x += 10;
			break;
		case VK_UP:
			pt.y -= 10;
			break;
		case VK_DOWN:
			pt.y += 10;
			break;


	}
	ScreenToClient(&pt);
	//pt.x += 10;

	m_wndChild.SetWindowPos(&CWnd::wndTop, pt.x, pt.y, 0, 0, SWP_SHOWWINDOW | SWP_NOZORDER | SWP_NOSIZE);
	 // 사이즈를 변경하고 싶으면  0, 0부분 변경 및 SWP_NOSIZE를 빼야한다.
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


int Cstep8View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	m_wndChild.Create(_T("BUTTON"), _T("안녕~~"), WS_CHILD | WS_VISIBLE | WS_BORDER,
		CRect(100, 100, 200, 140), this, 1);

	return 0;
}


void Cstep8View::OnLButtonDown(UINT nFlags, CPoint point)// point == x,y좌표
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	TRACE("마우스 좌표 = %d, %d\n", point.x, point.y);
	CClientDC dc(this);

	dc.SetPixel(point, RGB(255, 0, 0)); //빨간색으로 그리기
	CView::OnLButtonDown(nFlags, point);
}
