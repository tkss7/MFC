
// MouseCombiView.cpp : CMouseCombiView 클래스의 구현
//

#include "stdafx.h"
#include "MouseCombi.h"

#include "MouseCombiDoc.h"
#include "MouseCombiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMouseCombiView

IMPLEMENT_DYNCREATE(CMouseCombiView, CView)

BEGIN_MESSAGE_MAP(CMouseCombiView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_PAINT()
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CMouseCombiView 생성/소멸

CMouseCombiView::CMouseCombiView()
{
	m_ptItemText = CPoint(10, 30);
	m_bDragFlag = false;			//드래그 중이 아님.
}

CMouseCombiView::~CMouseCombiView()
{
}

BOOL CMouseCombiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CMouseCombiView 그리기

void CMouseCombiView::OnDraw(CDC* /*pDC*/)
{
	CMouseCombiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CMouseCombiView 인쇄

BOOL CMouseCombiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMouseCombiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMouseCombiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMouseCombiView 진단

#ifdef _DEBUG
void CMouseCombiView::AssertValid() const
{
	CView::AssertValid();
}

void CMouseCombiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMouseCombiDoc* CMouseCombiView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMouseCombiDoc)));
	return (CMouseCombiDoc*)m_pDocument;
}
#endif //_DEBUG


// CMouseCombiView 메시지 처리기

void CMouseCombiView::OnLButtonDown(UINT nFlags, CPoint point)
{
	//m_ptItemText 값을 기준으로 64픽셀 내에서
	//마우스 왼쪽 버튼이 클릭된 것인가?
	if(point.x >= m_ptItemText.x - 32 &&
		point.x <= m_ptItemText.x + 32 &&
		point.y >= m_ptItemText.y - 32 &&
		point.y <= m_ptItemText.y + 32)
	{
		//드래그가 시작되었으므로 마우스를 캡쳐함.
		SetCapture();
		m_bDragFlag = true;
		RedrawWindow();
	}

	CView::OnLButtonDown(nFlags, point);
}

void CMouseCombiView::OnLButtonUp(UINT nFlags, CPoint point)
{
	//드래그 중이었는가?
	if(m_bDragFlag)
	{
		//버튼에서 손을 뗐으므로 드래그가 끝났다고 판단한다.
		m_bDragFlag = false;
		//드래그가 끝난 이 좌표가 드롭된 좌표이다.
		m_ptItemText = point;
		RedrawWindow();
		//캡쳐한 마우스를 풀어준다.
		ReleaseCapture();
	}

	CView::OnLButtonUp(nFlags, point);
}

void CMouseCombiView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnLButtonDblClk(nFlags, point);
}

void CMouseCombiView::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	if(m_bDragFlag)		dc.TextOutW(10, 10, TEXT("DRAG"));
	else				dc.TextOutW(10, 10, TEXT("----"));

	dc.TextOutW(m_ptItemText.x, m_ptItemText.y, TEXT("내 컴퓨터"));
}

void CMouseCombiView::OnMouseMove(UINT nFlags, CPoint point)
{
	if(m_bDragFlag)
	{
		//드래그 중인 좌표로 아이템 텍스트를 이동시켜 출력한다.
		m_ptItemText = point;
		RedrawWindow();
	}

	CView::OnMouseMove(nFlags, point);
}

int CMouseCombiView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	//스태틱 윈도우가 메시지를 수신할 수 있도록 반드시
	//SS_NOTIFY 스타일을 추가한다.
	m_wndTrack.Create(TEXT("STATIC"), TEXT("TRACK TEST"),
		WS_CHILD | WS_VISIBLE | WS_BORDER | SS_NOTIFY,
		CRect(100, 10, 250, 160), this, 1234);

	return 0;
}
