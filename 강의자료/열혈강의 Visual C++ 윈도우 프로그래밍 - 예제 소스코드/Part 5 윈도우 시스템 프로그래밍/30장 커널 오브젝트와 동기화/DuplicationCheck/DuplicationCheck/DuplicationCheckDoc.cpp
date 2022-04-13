
// DuplicationCheckDoc.cpp : CDuplicationCheckDoc 클래스의 구현
//

#include "stdafx.h"
#include "DuplicationCheck.h"

#include "DuplicationCheckDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDuplicationCheckDoc

IMPLEMENT_DYNCREATE(CDuplicationCheckDoc, CDocument)

BEGIN_MESSAGE_MAP(CDuplicationCheckDoc, CDocument)
END_MESSAGE_MAP()


// CDuplicationCheckDoc 생성/소멸

CDuplicationCheckDoc::CDuplicationCheckDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CDuplicationCheckDoc::~CDuplicationCheckDoc()
{
}

BOOL CDuplicationCheckDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CDuplicationCheckDoc serialization

void CDuplicationCheckDoc::Serialize(CArchive& ar)
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


// CDuplicationCheckDoc 진단

#ifdef _DEBUG
void CDuplicationCheckDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDuplicationCheckDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDuplicationCheckDoc 명령
