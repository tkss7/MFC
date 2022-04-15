
// GdiPlusDemoDoc.cpp : CGdiPlusDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "GdiPlusDemo.h"

#include "GdiPlusDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGdiPlusDemoDoc

IMPLEMENT_DYNCREATE(CGdiPlusDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CGdiPlusDemoDoc, CDocument)
END_MESSAGE_MAP()


// CGdiPlusDemoDoc 생성/소멸

CGdiPlusDemoDoc::CGdiPlusDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CGdiPlusDemoDoc::~CGdiPlusDemoDoc()
{
}

BOOL CGdiPlusDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CGdiPlusDemoDoc serialization

void CGdiPlusDemoDoc::Serialize(CArchive& ar)
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


// CGdiPlusDemoDoc 진단

#ifdef _DEBUG
void CGdiPlusDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGdiPlusDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CGdiPlusDemoDoc 명령
