// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

// Office2007StyleView.cpp : COffice2007StyleView 클래스의 구현
//

#include "stdafx.h"
#include "Office2007Style.h"

#include "Office2007StyleDoc.h"
#include "Office2007StyleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COffice2007StyleView

IMPLEMENT_DYNCREATE(COffice2007StyleView, CView)

BEGIN_MESSAGE_MAP(COffice2007StyleView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &COffice2007StyleView::OnFilePrintPreview)
END_MESSAGE_MAP()

// COffice2007StyleView 생성/소멸

COffice2007StyleView::COffice2007StyleView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

COffice2007StyleView::~COffice2007StyleView()
{
}

BOOL COffice2007StyleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// COffice2007StyleView 그리기

void COffice2007StyleView::OnDraw(CDC* /*pDC*/)
{
	COffice2007StyleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// COffice2007StyleView 인쇄


void COffice2007StyleView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL COffice2007StyleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void COffice2007StyleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void COffice2007StyleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void COffice2007StyleView::OnRButtonUp(UINT nFlags, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void COffice2007StyleView::OnContextMenu(CWnd* pWnd, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}


// COffice2007StyleView 진단

#ifdef _DEBUG
void COffice2007StyleView::AssertValid() const
{
	CView::AssertValid();
}

void COffice2007StyleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COffice2007StyleDoc* COffice2007StyleView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COffice2007StyleDoc)));
	return (COffice2007StyleDoc*)m_pDocument;
}
#endif //_DEBUG


// COffice2007StyleView 메시지 처리기
