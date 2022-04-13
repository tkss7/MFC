
// MapModeDemoDoc.cpp : CMapModeDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "MapModeDemo.h"

#include "MapModeDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMapModeDemoDoc

IMPLEMENT_DYNCREATE(CMapModeDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CMapModeDemoDoc, CDocument)
END_MESSAGE_MAP()


// CMapModeDemoDoc 생성/소멸

CMapModeDemoDoc::CMapModeDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CMapModeDemoDoc::~CMapModeDemoDoc()
{
}

BOOL CMapModeDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CMapModeDemoDoc serialization

void CMapModeDemoDoc::Serialize(CArchive& ar)
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


// CMapModeDemoDoc 진단

#ifdef _DEBUG
void CMapModeDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMapModeDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMapModeDemoDoc 명령
