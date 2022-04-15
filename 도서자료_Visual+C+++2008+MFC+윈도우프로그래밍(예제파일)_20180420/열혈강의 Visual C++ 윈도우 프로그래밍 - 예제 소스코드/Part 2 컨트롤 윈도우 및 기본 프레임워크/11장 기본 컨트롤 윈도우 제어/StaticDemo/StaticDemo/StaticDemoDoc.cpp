
// StaticDemoDoc.cpp : CStaticDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "StaticDemo.h"

#include "StaticDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStaticDemoDoc

IMPLEMENT_DYNCREATE(CStaticDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CStaticDemoDoc, CDocument)
END_MESSAGE_MAP()


// CStaticDemoDoc 생성/소멸

CStaticDemoDoc::CStaticDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CStaticDemoDoc::~CStaticDemoDoc()
{
}

BOOL CStaticDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CStaticDemoDoc serialization

void CStaticDemoDoc::Serialize(CArchive& ar)
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


// CStaticDemoDoc 진단

#ifdef _DEBUG
void CStaticDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStaticDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CStaticDemoDoc 명령
