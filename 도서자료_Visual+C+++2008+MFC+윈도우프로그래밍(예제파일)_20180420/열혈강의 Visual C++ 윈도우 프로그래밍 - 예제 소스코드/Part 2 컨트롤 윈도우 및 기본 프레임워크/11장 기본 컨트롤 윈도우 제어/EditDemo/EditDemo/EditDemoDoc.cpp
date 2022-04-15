
// EditDemoDoc.cpp : CEditDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "EditDemo.h"

#include "EditDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEditDemoDoc

IMPLEMENT_DYNCREATE(CEditDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CEditDemoDoc, CDocument)
END_MESSAGE_MAP()


// CEditDemoDoc 생성/소멸

CEditDemoDoc::CEditDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CEditDemoDoc::~CEditDemoDoc()
{
}

BOOL CEditDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CEditDemoDoc serialization

void CEditDemoDoc::Serialize(CArchive& ar)
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


// CEditDemoDoc 진단

#ifdef _DEBUG
void CEditDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CEditDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CEditDemoDoc 명령
