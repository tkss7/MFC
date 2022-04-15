
// ImageRgnDoc.cpp : CImageRgnDoc 클래스의 구현
//

#include "stdafx.h"
#include "ImageRgn.h"

#include "ImageRgnDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageRgnDoc

IMPLEMENT_DYNCREATE(CImageRgnDoc, CDocument)

BEGIN_MESSAGE_MAP(CImageRgnDoc, CDocument)
END_MESSAGE_MAP()


// CImageRgnDoc 생성/소멸

CImageRgnDoc::CImageRgnDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CImageRgnDoc::~CImageRgnDoc()
{
}

BOOL CImageRgnDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CImageRgnDoc serialization

void CImageRgnDoc::Serialize(CArchive& ar)
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


// CImageRgnDoc 진단

#ifdef _DEBUG
void CImageRgnDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImageRgnDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CImageRgnDoc 명령
