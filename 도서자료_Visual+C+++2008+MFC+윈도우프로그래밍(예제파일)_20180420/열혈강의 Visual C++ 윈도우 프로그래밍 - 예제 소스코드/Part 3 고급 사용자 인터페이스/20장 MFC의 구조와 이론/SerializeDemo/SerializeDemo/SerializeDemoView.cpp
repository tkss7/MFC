
// SerializeDemoView.cpp : CSerializeDemoView 클래스의 구현
//

#include "stdafx.h"
#include "SerializeDemo.h"

#include "SerializeDemoDoc.h"
#include "SerializeDemoView.h"

#include "TestData.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSerializeDemoView

IMPLEMENT_DYNCREATE(CSerializeDemoView, CEditView)

BEGIN_MESSAGE_MAP(CSerializeDemoView, CEditView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CSerializeDemoView 생성/소멸

CSerializeDemoView::CSerializeDemoView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CSerializeDemoView::~CSerializeDemoView()
{
}

BOOL CSerializeDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// 자동 줄바꿈을 사용합니다.

	return bPreCreated;
}


// CSerializeDemoView 인쇄

BOOL CSerializeDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 CEditView 준비
	return CEditView::OnPreparePrinting(pInfo);
}

void CSerializeDemoView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 기본 CEditView 시작 인쇄
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CSerializeDemoView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// 기본 CEditView 종료 인쇄
	CEditView::OnEndPrinting(pDC, pInfo);
}


// CSerializeDemoView 진단

#ifdef _DEBUG
void CSerializeDemoView::AssertValid() const
{
	CEditView::AssertValid();
}

void CSerializeDemoView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CSerializeDemoDoc* CSerializeDemoView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSerializeDemoDoc)));
	return (CSerializeDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CSerializeDemoView 메시지 처리기

void CSerializeDemoView::Serialize(CArchive& ar)
{
	CString strTmp = _T("");
	CEdit& theEdit = GetEditCtrl();

	if(ar.IsStoring())		//SAVE
	{
		CTestData	TestData;
		TCHAR		szBuffer[512];
		TestData.m_nLine = theEdit.GetLineCount();

		ar << &TestData;

		for(int i = 0; i < TestData.m_nLine; i++)
		{
			::ZeroMemory(szBuffer, sizeof(szBuffer));
			if(theEdit.GetLine(i, szBuffer, 512) > 0)
				ar.WriteString(szBuffer);

			if(i + 1 < TestData.m_nLine)
				ar.WriteString(_T("\r\n"));
		}
	}
	else					//LOAD
	{
		CString strText = _T("");

		CTestData* pTestData = NULL;
		ar >> pTestData;

		while(ar.ReadString(strTmp))
		{
			strText += strTmp;
			strText += "\r\n";
		}

		theEdit.SetWindowText(strText);

		strTmp.Format(_T("%d Lines"), pTestData->m_nLine);
		AfxMessageBox(strTmp);

		delete pTestData;
	}
}
