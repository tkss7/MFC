
// OleDBDemoDoc.cpp : COleDBDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "OleDBDemo.h"

#include "OleDBDemoSet.h"
#include "OleDBDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COleDBDemoDoc

IMPLEMENT_DYNCREATE(COleDBDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(COleDBDemoDoc, CDocument)
END_MESSAGE_MAP()


// COleDBDemoDoc 생성/소멸

COleDBDemoDoc::COleDBDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

COleDBDemoDoc::~COleDBDemoDoc()
{
}

BOOL COleDBDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// COleDBDemoDoc serialization

void COleDBDemoDoc::Serialize(CArchive& ar)
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


// COleDBDemoDoc 진단

#ifdef _DEBUG
void COleDBDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COleDBDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// COleDBDemoDoc 명령
