
// Office2003StyleDoc.cpp : COffice2003StyleDoc 클래스의 구현
//

#include "stdafx.h"
#include "Office2003Style.h"

#include "Office2003StyleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COffice2003StyleDoc

IMPLEMENT_DYNCREATE(COffice2003StyleDoc, CDocument)

BEGIN_MESSAGE_MAP(COffice2003StyleDoc, CDocument)
END_MESSAGE_MAP()


// COffice2003StyleDoc 생성/소멸

COffice2003StyleDoc::COffice2003StyleDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

COffice2003StyleDoc::~COffice2003StyleDoc()
{
}

BOOL COffice2003StyleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// COffice2003StyleDoc serialization

void COffice2003StyleDoc::Serialize(CArchive& ar)
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


// COffice2003StyleDoc 진단

#ifdef _DEBUG
void COffice2003StyleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COffice2003StyleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// COffice2003StyleDoc 명령
