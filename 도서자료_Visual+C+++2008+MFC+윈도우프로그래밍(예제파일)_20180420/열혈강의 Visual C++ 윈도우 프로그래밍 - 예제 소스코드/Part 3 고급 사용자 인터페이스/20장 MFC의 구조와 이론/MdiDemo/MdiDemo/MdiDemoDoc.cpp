
// MdiDemoDoc.cpp : CMdiDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "MdiDemo.h"

#include "MdiDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMdiDemoDoc

IMPLEMENT_DYNCREATE(CMdiDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CMdiDemoDoc, CDocument)
END_MESSAGE_MAP()


// CMdiDemoDoc 생성/소멸

CMdiDemoDoc::CMdiDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CMdiDemoDoc::~CMdiDemoDoc()
{
}

BOOL CMdiDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CMdiDemoDoc serialization

void CMdiDemoDoc::Serialize(CArchive& ar)
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


// CMdiDemoDoc 진단

#ifdef _DEBUG
void CMdiDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMdiDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMdiDemoDoc 명령
