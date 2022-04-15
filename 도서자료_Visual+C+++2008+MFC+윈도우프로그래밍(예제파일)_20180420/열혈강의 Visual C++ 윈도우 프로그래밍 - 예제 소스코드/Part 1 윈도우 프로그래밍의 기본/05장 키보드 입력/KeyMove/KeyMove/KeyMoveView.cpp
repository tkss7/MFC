
// KeyMoveView.cpp : CKeyMoveView 클래스의 구현
//

#include "stdafx.h"
#include "KeyMove.h"

#include "KeyMoveDoc.h"
#include "KeyMoveView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CKeyMoveView

IMPLEMENT_DYNCREATE(CKeyMoveView, CView)

BEGIN_MESSAGE_MAP(CKeyMoveView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_KEYDOWN()
	ON_WM_SYSKEYDOWN()
	ON_WM_SYSCHAR()
	ON_WM_CHAR()
END_MESSAGE_MAP()

// CKeyMoveView 생성/소멸

CKeyMoveView::CKeyMoveView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CKeyMoveView::~CKeyMoveView()
{
}

BOOL CKeyMoveView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CKeyMoveView 그리기

void CKeyMoveView::OnDraw(CDC* /*pDC*/)
{
	CKeyMoveDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CKeyMoveView 인쇄

BOOL CKeyMoveView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CKeyMoveView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CKeyMoveView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CKeyMoveView 진단

#ifdef _DEBUG
void CKeyMoveView::AssertValid() const
{
	CView::AssertValid();
}

void CKeyMoveView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CKeyMoveDoc* CKeyMoveView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CKeyMoveDoc)));
	return (CKeyMoveDoc*)m_pDocument;
}
#endif //_DEBUG


// CKeyMoveView 메시지 처리기

int CKeyMoveView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	m_wndChild.Create(TEXT("STATIC"), TEXT("KeyMove"),
				WS_CHILD | WS_VISIBLE | WS_BORDER,
				CRect(100, 100, 200, 200), this, 1234);

	return 0;
}

void CKeyMoveView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CPoint ptChild;			//차일드 윈도우의 좌표.
	CRect Rect;				//차일드 윈도우의 좌표 및 크기.

	//차일드 윈도우의 두 좌표 정보(스크린 기준)를 알아온다.
	m_wndChild.GetWindowRect(&Rect);
	ptChild.x = Rect.left;
	ptChild.y = Rect.top;

	//스크린 기준좌표를 클라이언트 뷰 기준의 좌표로 환산한다.
	ScreenToClient(&ptChild);

	switch(nChar)
	{
	case VK_LEFT:			//왼쪽 화살표를 누른 경우.
		ptChild.x -= 10;	//10픽셀만큼 x좌표 값 감소.
		break;

	case VK_RIGHT:			//오른쪽 화살표를 누른 경우.
		ptChild.x += 10;	//10픽셀만큼 x좌표 값 증가.
		break;
	}

	//변경된 새 좌표로 차일드 윈도우를 이동시킨다.
	m_wndChild.SetWindowPos(&CWnd::wndTop, ptChild.x, ptChild.y, 0, 0,
						SWP_SHOWWINDOW | SWP_NOZORDER | SWP_NOSIZE);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CKeyMoveView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString strText = TEXT("");
	strText.Format(TEXT("%c"), nChar);

	//입력한 키가 Enter, Back space, ESC키가 아니면
	//해당 ASCII 문자로 차일드 윈도우 텍스트를 변경한다.
	if(nChar != VK_RETURN && nChar != VK_BACK && nChar != VK_ESCAPE)
	{
		m_wndChild.SetWindowText(strText);
	}

	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CKeyMoveView::OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	CString strMessage = TEXT("");		//메시지를 저장할 문자열 객체

	//Space키에 대한 상태정보를 수집.
	WORD wResult = ::GetKeyState(VK_SPACE);
	BYTE byHigh = HIBYTE(wResult);
	//상위 바이트의 1번 비트가 1이면 키가 눌려진 상태.
	if(byHigh & 0x01)
	{
		strMessage += TEXT("Alt + Space, ");

		//같은 방법으로 Caps lock 키의 상태를 검사.
		wResult = ::GetKeyState(VK_CAPITAL);
		//하위 바이트의 1번 비트가 1이면 토글키가 켜진 상태.
		BYTE byLow = LOBYTE(wResult);
		if(byLow & 0x01)		strMessage += TEXT("CAPS LOCK ON");
		else					strMessage += TEXT("CAPS LOCK OFF");

		AfxMessageBox(strMessage);
	}

	CView::OnSysKeyDown(nChar, nRepCnt, nFlags);
}

void CKeyMoveView::OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if(nChar == VK_RETURN)
						AfxMessageBox(TEXT("Alt + Enter"));
	else if(nChar == 's' || nChar == 'S')
						AfxMessageBox(TEXT("Alt + S"));
	else if(nChar == 'x' || nChar == 'X')
						AfxMessageBox(TEXT("Alt + X"));

	CView::OnSysChar(nChar, nRepCnt, nFlags);
}
