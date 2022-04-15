
// HelloSdiDoc.cpp : CHelloSdiDoc 클래스의 구현
//

#include "stdafx.h"
#include "HelloSdi.h"

#include "HelloSdiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CHelloSdiDoc

IMPLEMENT_DYNCREATE(CHelloSdiDoc, CDocument)

BEGIN_MESSAGE_MAP(CHelloSdiDoc, CDocument)
END_MESSAGE_MAP()


// CHelloSdiDoc 생성/소멸

CHelloSdiDoc::CHelloSdiDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CHelloSdiDoc::~CHelloSdiDoc()
{
}

BOOL CHelloSdiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	reinterpret_cast<CEditView*>(m_viewList.GetHead())->SetWindowText(NULL);

//	AfxMessageBox(TEXT("새로운 빈 문서를 열었습니다."));
	SetModifiedFlag(TRUE);

	return TRUE;
}




// CHelloSdiDoc serialization

void CHelloSdiDoc::Serialize(CArchive& ar)
{
	// CEditView에는 모든 serialization을 처리하는 edit 컨트롤이 들어 있습니다.
	reinterpret_cast<CEditView*>(m_viewList.GetHead())->SerializeRaw(ar);
}


// CHelloSdiDoc 진단

#ifdef _DEBUG
void CHelloSdiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHelloSdiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHelloSdiDoc 명령

BOOL CHelloSdiDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	AfxMessageBox(TEXT("사용자가 문서를 열었습니다."));

	return TRUE;
}
