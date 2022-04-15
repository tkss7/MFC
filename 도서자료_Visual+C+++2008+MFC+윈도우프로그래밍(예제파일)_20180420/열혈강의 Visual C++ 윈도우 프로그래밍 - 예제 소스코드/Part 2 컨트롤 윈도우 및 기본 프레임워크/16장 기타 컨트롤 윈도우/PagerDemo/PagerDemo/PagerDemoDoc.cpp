
// PagerDemoDoc.cpp : CPagerDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "PagerDemo.h"

#include "PagerDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPagerDemoDoc

IMPLEMENT_DYNCREATE(CPagerDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CPagerDemoDoc, CDocument)
END_MESSAGE_MAP()


// CPagerDemoDoc 생성/소멸

CPagerDemoDoc::CPagerDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CPagerDemoDoc::~CPagerDemoDoc()
{
}

BOOL CPagerDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CPagerDemoDoc serialization

void CPagerDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}


// CPagerDemoDoc 진단

#ifdef _DEBUG
void CPagerDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPagerDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPagerDemoDoc 명령
