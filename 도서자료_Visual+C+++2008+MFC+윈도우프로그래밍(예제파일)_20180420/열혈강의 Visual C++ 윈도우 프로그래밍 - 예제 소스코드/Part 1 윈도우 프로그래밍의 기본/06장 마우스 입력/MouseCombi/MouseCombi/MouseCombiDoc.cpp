
// MouseCombiDoc.cpp : CMouseCombiDoc 클래스의 구현
//

#include "stdafx.h"
#include "MouseCombi.h"

#include "MouseCombiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMouseCombiDoc

IMPLEMENT_DYNCREATE(CMouseCombiDoc, CDocument)

BEGIN_MESSAGE_MAP(CMouseCombiDoc, CDocument)
END_MESSAGE_MAP()


// CMouseCombiDoc 생성/소멸

CMouseCombiDoc::CMouseCombiDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CMouseCombiDoc::~CMouseCombiDoc()
{
}

BOOL CMouseCombiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CMouseCombiDoc serialization

void CMouseCombiDoc::Serialize(CArchive& ar)
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


// CMouseCombiDoc 진단

#ifdef _DEBUG
void CMouseCombiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMouseCombiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMouseCombiDoc 명령
