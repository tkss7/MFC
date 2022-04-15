
// DynSplitDemoDoc.cpp : CDynSplitDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "DynSplitDemo.h"

#include "DynSplitDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDynSplitDemoDoc

IMPLEMENT_DYNCREATE(CDynSplitDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDynSplitDemoDoc, CDocument)
END_MESSAGE_MAP()


// CDynSplitDemoDoc 생성/소멸

CDynSplitDemoDoc::CDynSplitDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CDynSplitDemoDoc::~CDynSplitDemoDoc()
{
}

BOOL CDynSplitDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CDynSplitDemoDoc serialization

void CDynSplitDemoDoc::Serialize(CArchive& ar)
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


// CDynSplitDemoDoc 진단

#ifdef _DEBUG
void CDynSplitDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDynSplitDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDynSplitDemoDoc 명령
