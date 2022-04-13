
// CreateDemoDoc.cpp : CCreateDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "CreateDemo.h"

#include "CreateDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCreateDemoDoc

IMPLEMENT_DYNCREATE(CCreateDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CCreateDemoDoc, CDocument)
END_MESSAGE_MAP()


// CCreateDemoDoc 생성/소멸

CCreateDemoDoc::CCreateDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CCreateDemoDoc::~CCreateDemoDoc()
{
}

BOOL CCreateDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CCreateDemoDoc serialization

void CCreateDemoDoc::Serialize(CArchive& ar)
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


// CCreateDemoDoc 진단

#ifdef _DEBUG
void CCreateDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCreateDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CCreateDemoDoc 명령
