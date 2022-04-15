
// PrintDemoDoc.cpp : CPrintDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "PrintDemo.h"

#include "PrintDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPrintDemoDoc

IMPLEMENT_DYNCREATE(CPrintDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CPrintDemoDoc, CDocument)
END_MESSAGE_MAP()


// CPrintDemoDoc 생성/소멸

CPrintDemoDoc::CPrintDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CPrintDemoDoc::~CPrintDemoDoc()
{
}

BOOL CPrintDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CPrintDemoDoc serialization

void CPrintDemoDoc::Serialize(CArchive& ar)
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


// CPrintDemoDoc 진단

#ifdef _DEBUG
void CPrintDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPrintDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CPrintDemoDoc 명령
