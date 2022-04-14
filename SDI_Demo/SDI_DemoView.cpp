
// SDI_DemoView.cpp: CSDIDemoView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "SDI_Demo.h"
#endif

#include "SDI_DemoDoc.h"
#include "SDI_DemoView.h"
#include"MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSDIDemoView
// 
//
//View에서 g , h 선언후 메뉴 3개 만들어서 프레임, 문서, 윈App에서 읽기
IMPLEMENT_DYNCREATE(CSDIDemoView, CView)

BEGIN_MESSAGE_MAP(CSDIDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSDIDemoView 생성/소멸

CSDIDemoView::CSDIDemoView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_g = 5000;
	m_h = 8000;
}

CSDIDemoView::~CSDIDemoView()
{
}

BOOL CSDIDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CSDIDemoView 그리기

void CSDIDemoView::OnDraw(CDC* /*pDC*/)
{
	CSDIDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CSDIDemoApp* pApp = (CSDIDemoApp*)AfxGetApp();
	TRACE("CSDIDemoView::OnDraw()... a = %d , b = %d\n", pApp->m_a, pApp->m_b);

	//CSDIDemoApp의 변수 m_a , m_b 값을 읽어 출력
	//CSDIDemoDoc의 변수 m_c , m_d 값을 읽어 출력
	//CMainFrame의 변수 m_e , m_f 값을 읽어 출력

	CSDIDemoDoc* pDoc1 = (CSDIDemoDoc*)GetDocument();
	TRACE("CSDIDemoView::OnDraw()... c = %d , d = %d\n", pDoc1->m_c, pDoc1->m_d);

	CMainFrame* pMainFrame1 = (CMainFrame*)GetParentFrame();
	TRACE("CSDIDemoView::OnDraw()... e = %d , f = %d\n", pMainFrame1->m_e, pMainFrame1->m_f);



}


// CSDIDemoView 인쇄

BOOL CSDIDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CSDIDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CSDIDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CSDIDemoView 진단

#ifdef _DEBUG
void CSDIDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CSDIDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CSDIDemoDoc* CSDIDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSDIDemoDoc)));
	return (CSDIDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CSDIDemoView 메시지 처리기
