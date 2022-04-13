
// VirtualButtonDoc.cpp : CVirtualButtonDoc 클래스의 구현
//

#include "stdafx.h"
#include "VirtualButton.h"

#include "VirtualButtonDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CVirtualButtonDoc

IMPLEMENT_DYNCREATE(CVirtualButtonDoc, CDocument)

BEGIN_MESSAGE_MAP(CVirtualButtonDoc, CDocument)
END_MESSAGE_MAP()


// CVirtualButtonDoc 생성/소멸

CVirtualButtonDoc::CVirtualButtonDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CVirtualButtonDoc::~CVirtualButtonDoc()
{
}

BOOL CVirtualButtonDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CVirtualButtonDoc serialization

void CVirtualButtonDoc::Serialize(CArchive& ar)
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


// CVirtualButtonDoc 진단

#ifdef _DEBUG
void CVirtualButtonDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CVirtualButtonDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CVirtualButtonDoc 명령
