
// TransparentDemoDoc.cpp : CTransparentDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "TransparentDemo.h"

#include "TransparentDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTransparentDemoDoc

IMPLEMENT_DYNCREATE(CTransparentDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CTransparentDemoDoc, CDocument)
END_MESSAGE_MAP()


// CTransparentDemoDoc 생성/소멸

CTransparentDemoDoc::CTransparentDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CTransparentDemoDoc::~CTransparentDemoDoc()
{
}

BOOL CTransparentDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CTransparentDemoDoc serialization

void CTransparentDemoDoc::Serialize(CArchive& ar)
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


// CTransparentDemoDoc 진단

#ifdef _DEBUG
void CTransparentDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTransparentDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTransparentDemoDoc 명령
