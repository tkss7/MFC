
// ImageScrollDemoDoc.cpp : CImageScrollDemoDoc 클래스의 구현
//

#include "stdafx.h"
#include "ImageScrollDemo.h"

#include "ImageScrollDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageScrollDemoDoc

IMPLEMENT_DYNCREATE(CImageScrollDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageScrollDemoDoc, CDocument)
END_MESSAGE_MAP()


// CImageScrollDemoDoc 생성/소멸

CImageScrollDemoDoc::CImageScrollDemoDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CImageScrollDemoDoc::~CImageScrollDemoDoc()
{
}

BOOL CImageScrollDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CImageScrollDemoDoc serialization

void CImageScrollDemoDoc::Serialize(CArchive& ar)
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


// CImageScrollDemoDoc 진단

#ifdef _DEBUG
void CImageScrollDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageScrollDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageScrollDemoDoc 명령
