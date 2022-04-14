// RedrawDemoView.cpp: CRedrawDemoView Ŭ������ ����
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "RedrawDemo.h"
#endif

#include "RedrawDemoDoc.h"
#include "RedrawDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRedrawDemoView

IMPLEMENT_DYNCREATE(CRedrawDemoView, CView)

BEGIN_MESSAGE_MAP(CRedrawDemoView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	//	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CRedrawDemoView ����/�Ҹ�

CRedrawDemoView::CRedrawDemoView() noexcept
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CRedrawDemoView::~CRedrawDemoView()
{
}

BOOL CRedrawDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CRedrawDemoView �׸���

void CRedrawDemoView::OnDraw(CDC* pDC)
{
	CRedrawDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	CPen pen(PS_SOLID, 10, RGB(255, 0, 0));
	CPen* pOldPen = pDC->SelectObject(&pen);

	if (pDoc->m_array.size() > 0) {
		const CPoint& pt = pDoc->m_array[0];
		pDC->MoveTo(pt.x, pt.y);
		for (const CPoint& pt : pDoc->m_array) {
			pDC->LineTo(pt.x, pt.y);
		}
	}

	pDC->SelectObject(pOldPen);

}


// CRedrawDemoView �μ�

BOOL CRedrawDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CRedrawDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CRedrawDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CRedrawDemoView ����

#ifdef _DEBUG
void CRedrawDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CRedrawDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRedrawDemoDoc* CRedrawDemoView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRedrawDemoDoc)));
	return (CRedrawDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CRedrawDemoView �޽��� ó����

//void CRedrawDemoView::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//}

void CRedrawDemoView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);

	//CPen pen(PS_SOLID, 10, RGB(255, 0, 0));
	//CPen* pOldPen = dc.SelectObject(&pen);
	//dc.Rectangle(point.x, point.y, point.x+100, point.y+100);
	//dc.SelectObject(pOldPen);

	CRedrawDemoDoc* pDoc = GetDocument();
	pDoc->m_array.clear();
	pDoc->m_array.push_back(point);
	//	RedrawWindow();
	Invalidate();

	SetCapture();

	CView::OnLButtonDown(nFlags, point);
}


void CRedrawDemoView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	ReleaseCapture();

	CView::OnLButtonUp(nFlags, point);
}


void CRedrawDemoView::OnMouseMove(UINT nFlags, CPoint point)
{
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON) {
		CRedrawDemoDoc* pDoc = GetDocument();

		const CPoint& pt = pDoc->m_array[pDoc->m_array.size() - 1];

		CClientDC dc(this);

		CPen pen(PS_SOLID, 10, RGB(255, 0, 0));
		CPen* pOldPen = dc.SelectObject(&pen);

		dc.MoveTo(pt.x, pt.y);
		dc.LineTo(point.x, point.y);

		dc.SelectObject(pOldPen);

		pDoc->m_array.push_back(point);
		//Invalidate();
	}

	CView::OnMouseMove(nFlags, point);
}