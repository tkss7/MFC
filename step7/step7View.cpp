
// step7View.cpp: Cstep7View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "step7.h"
#endif

#include "step7Doc.h"
#include "step7View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cstep7View

IMPLEMENT_DYNCREATE(Cstep7View, CView)

BEGIN_MESSAGE_MAP(Cstep7View, CView) // 메시지에 관한게 왔을때 처리할 함수가 누군지를 연결 해준다. == 커넥터
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint) // 키 :ID_FILE_PRINT
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
END_MESSAGE_MAP()

// Cstep7View 생성/소멸

Cstep7View::Cstep7View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	//m_hWnd // 윈도우가 생성되었다는 메시지를 받기 전까진 가짜다.
	//HWND hWnd::CreateWindow() 
	//WM_CREATE // 윈도우 성공의 실패여부가 전달됨 + 핸들에 대한 정보도 전달되어서 ㅈ

}

Cstep7View::~Cstep7View()
{
}

BOOL Cstep7View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cstep7View 그리기

void Cstep7View::OnDraw(CDC* /*pDC*/)
{
	Cstep7Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Cstep7View 인쇄

BOOL Cstep7View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cstep7View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cstep7View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// Cstep7View 진단

#ifdef _DEBUG
void Cstep7View::AssertValid() const
{
	CView::AssertValid();
}

void Cstep7View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cstep7Doc* Cstep7View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cstep7Doc)));
	return (Cstep7Doc*)m_pDocument;
}
#endif //_DEBUG


// Cstep7View 메시지 처리기


int Cstep7View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1) //실패
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	m_wndClient1.Create(TEXT("STATIC"), TEXT("DEMO"), // TEXT("EDIT") : 내용을 편집가능 , TEXT("BUTTON") : 버튼화
	WS_CHILD | WS_VISIBLE | WS_BORDER,
	CRect(30, 30, 180, 180), this, 1234);

	m_wndClient2.Create(TEXT("EDIT"), TEXT("DEMO"), // TEXT("EDIT") : 내용을 편집가능 , TEXT("BUTTON") : 버튼화
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		CRect(230, 30, 380, 180), this, 1);

	m_wndClient3.Create(TEXT("BUTTON"), TEXT("DEMO"), // TEXT("EDIT") : 내용을 편집가능 , TEXT("BUTTON") : 버튼화
		WS_CHILD | WS_VISIBLE | WS_BORDER,
		CRect(430, 30, 580, 180), GetDesktopWindow(), 2);

	return 0;
}
