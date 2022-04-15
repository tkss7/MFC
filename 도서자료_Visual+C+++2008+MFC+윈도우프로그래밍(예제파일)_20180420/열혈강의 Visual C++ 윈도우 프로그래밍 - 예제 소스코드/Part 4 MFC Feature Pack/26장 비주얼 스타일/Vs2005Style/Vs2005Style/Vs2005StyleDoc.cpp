
// Vs2005StyleDoc.cpp : CVs2005StyleDoc 클래스의 구현
//

#include "stdafx.h"
#include "Vs2005Style.h"

#include "Vs2005StyleDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVs2005StyleDoc

IMPLEMENT_DYNCREATE(CVs2005StyleDoc, CDocument)

BEGIN_MESSAGE_MAP(CVs2005StyleDoc, CDocument)
END_MESSAGE_MAP()


// CVs2005StyleDoc 생성/소멸

CVs2005StyleDoc::CVs2005StyleDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CVs2005StyleDoc::~CVs2005StyleDoc()
{
}

BOOL CVs2005StyleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CVs2005StyleDoc serialization

void CVs2005StyleDoc::Serialize(CArchive& ar)
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


// CVs2005StyleDoc 진단

#ifdef _DEBUG
void CVs2005StyleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVs2005StyleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CVs2005StyleDoc 명령
