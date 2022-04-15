
// TriangleDemoDoc.cpp : CTriangleDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "TriangleDemo.h"

#include "TriangleDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTriangleDemoDoc

IMPLEMENT_DYNCREATE(CTriangleDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CTriangleDemoDoc, CDocument)
END_MESSAGE_MAP()


// CTriangleDemoDoc 생성/소멸

CTriangleDemoDoc::CTriangleDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CTriangleDemoDoc::~CTriangleDemoDoc()
{
}

BOOL CTriangleDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CTriangleDemoDoc serialization

void CTriangleDemoDoc::Serialize(CArchive& ar)
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


// CTriangleDemoDoc 진단

#ifdef _DEBUG
void CTriangleDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTriangleDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTriangleDemoDoc 명령
