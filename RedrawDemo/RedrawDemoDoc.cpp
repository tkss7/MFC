
// RedrawDemoDoc.cpp: CRedrawDemoDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "RedrawDemo.h"
#endif

#include "RedrawDemoDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CRedrawDemoDoc

IMPLEMENT_DYNCREATE(CRedrawDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CRedrawDemoDoc, CDocument)
	ON_COMMAND(IDM_COLOR_GREEN, &CRedrawDemoDoc::OnColorGreen)
END_MESSAGE_MAP()


// CRedrawDemoDoc 생성/소멸

CRedrawDemoDoc::CRedrawDemoDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.
	Bold = 10;
}

CRedrawDemoDoc::~CRedrawDemoDoc()
{
}

BOOL CRedrawDemoDoc::OnNewDocument() // 여기가 ㄹㅇ 초기화
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	m_lineColor = RGB(255, 0, 0);

	return TRUE;
}




// CRedrawDemoDoc serialization

void CRedrawDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
		//1. 배열의 크기 저장
		ar << m_array.size();
		for (const CPoint& pt : m_array) {
			ar << pt.x;
			ar << pt.y;
		}
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		int size;
		int x, y;
		ar >> size;
		for (int i = 0; i < size; i++) {
			ar >> x;
			ar >> y;

			m_array.push_back(CPoint(x, y));
		}
		
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CRedrawDemoDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CRedrawDemoDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CRedrawDemoDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CRedrawDemoDoc 진단

#ifdef _DEBUG
void CRedrawDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRedrawDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRedrawDemoDoc 명령


void CRedrawDemoDoc::DeleteContents() // 문서의 내용만 삭제시키는 것
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_array.clear();


	CDocument::DeleteContents();
}

#include"RedrawDemoView.h"
#include"MainFrm.h"
void CRedrawDemoDoc::OnColorGreen()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_lineColor = RGB(0, 255, 0);
	((CRedrawDemoView*)m_viewList.GetHead())->Invalidate();

	//((CMainFrame*)AfxGetMainWnd())->GetActiveView()->Invalidate(); // 위에 꺼랑 같다
	//UpdateAllViews(NULL); // 모든 뷰를 찾아서 업데이트를 해준다. // 이것도 결과는 같다
}
