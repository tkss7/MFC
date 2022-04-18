﻿
// StaticDemoView.cpp: CStaticDemoView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "StaticDemo.h"
#endif

#include "StaticDemoDoc.h"
#include "StaticDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStaticDemoView

IMPLEMENT_DYNCREATE(CStaticDemoView, CView)

BEGIN_MESSAGE_MAP(CStaticDemoView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CStaticDemoView 생성/소멸

CStaticDemoView::CStaticDemoView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CStaticDemoView::~CStaticDemoView()
{
}

BOOL CStaticDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CStaticDemoView 그리기

void CStaticDemoView::OnDraw(CDC* /*pDC*/)
{
	CStaticDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CStaticDemoView 인쇄

BOOL CStaticDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CStaticDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CStaticDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CStaticDemoView 진단

#ifdef _DEBUG
void CStaticDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CStaticDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CStaticDemoDoc* CStaticDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStaticDemoDoc)));
	return (CStaticDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CStaticDemoView 메시지 처리기


int CStaticDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	m_wndStatic2.Create(_T("특수화된 작성"), WS_VISIBLE | SS_CENTER, CRect(100, 400, 400, 450), this, 1235);



	return 0;
}


void CStaticDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	m_wndStatic2.SetWindowText(_T("왼쪽 마우스 버튼 클릭 됨"));

	CView::OnLButtonDown(nFlags, point);
}


void CStaticDemoView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	m_wndStatic2.SetWindowText(_T("오른쪽 마우스 버튼 클릭 됨"));

	CView::OnRButtonDown(nFlags, point);
}
