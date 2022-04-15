
// HomeWorkViewDoc.cpp: CHomeWorkViewDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "HomeWorkView.h"
#endif

#include "HomeWorkViewDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CHomeWorkViewDoc

IMPLEMENT_DYNCREATE(CHomeWorkViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CHomeWorkViewDoc, CDocument)
END_MESSAGE_MAP()


// CHomeWorkViewDoc 생성/소멸

CHomeWorkViewDoc::CHomeWorkViewDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CHomeWorkViewDoc::~CHomeWorkViewDoc()
{
}

BOOL CHomeWorkViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CHomeWorkViewDoc serialization

void CHomeWorkViewDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
		//1. 라인의 갯수, 2. 라인들의 점들 저장
		ar << m_lines.size();
		for (const vector<CPoint>& array : m_lines) {
			ar << array.size();
			for (const CPoint pt : array) {
				ar << pt.x;
				ar << pt.y;
			}
		}
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
		int line_size;
		int array_size;
		CPoint pt;
		ar >> line_size;
		for (int i = 0; i < line_size;i++) {
			ar >> array_size;
			m_array.clear(); // 필수
			for (int j = 0; j < array_size;j++) {
				ar >> pt.x;
				ar >> pt.y;
				m_array.push_back(pt);
			}
			m_lines.push_back(m_array);
		}
		
	}
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CHomeWorkViewDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
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
void CHomeWorkViewDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CHomeWorkViewDoc::SetSearchContent(const CString& value)
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

// CHomeWorkViewDoc 진단

#ifdef _DEBUG
void CHomeWorkViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CHomeWorkViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CHomeWorkViewDoc 명령


void CHomeWorkViewDoc::DeleteContents() // 데이터 제거하여 정리
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_array.clear();
	m_lines.clear();
	CDocument::DeleteContents();
}
