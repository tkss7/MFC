
// StaticSplitDemoDoc.cpp : CStaticSplitDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "StaticSplitDemo.h"

#include "StaticSplitDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStaticSplitDemoDoc

IMPLEMENT_DYNCREATE(CStaticSplitDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CStaticSplitDemoDoc, CDocument)
END_MESSAGE_MAP()


// CStaticSplitDemoDoc 생성/소멸

CStaticSplitDemoDoc::CStaticSplitDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CStaticSplitDemoDoc::~CStaticSplitDemoDoc()
{
}

BOOL CStaticSplitDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CStaticSplitDemoDoc serialization

void CStaticSplitDemoDoc::Serialize(CArchive& ar)
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


// CStaticSplitDemoDoc 진단

#ifdef _DEBUG
void CStaticSplitDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStaticSplitDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CStaticSplitDemoDoc 명령
