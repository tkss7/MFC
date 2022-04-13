
// DockingDemoDoc.cpp : CDockingDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "DockingDemo.h"

#include "DockingDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDockingDemoDoc

IMPLEMENT_DYNCREATE(CDockingDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDockingDemoDoc, CDocument)
END_MESSAGE_MAP()


// CDockingDemoDoc 생성/소멸

CDockingDemoDoc::CDockingDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CDockingDemoDoc::~CDockingDemoDoc()
{
}

BOOL CDockingDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CDockingDemoDoc serialization

void CDockingDemoDoc::Serialize(CArchive& ar)
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


// CDockingDemoDoc 진단

#ifdef _DEBUG
void CDockingDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDockingDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDockingDemoDoc 명령
