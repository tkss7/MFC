
// OdbcDemoDoc.cpp : COdbcDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "OdbcDemo.h"

#include "OdbcDemoSet.h"
#include "OdbcDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COdbcDemoDoc

IMPLEMENT_DYNCREATE(COdbcDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(COdbcDemoDoc, CDocument)
END_MESSAGE_MAP()


// COdbcDemoDoc 생성/소멸

COdbcDemoDoc::COdbcDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

COdbcDemoDoc::~COdbcDemoDoc()
{
}

BOOL COdbcDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// COdbcDemoDoc serialization

void COdbcDemoDoc::Serialize(CArchive& ar)
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


// COdbcDemoDoc 진단

#ifdef _DEBUG
void COdbcDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COdbcDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// COdbcDemoDoc 명령
