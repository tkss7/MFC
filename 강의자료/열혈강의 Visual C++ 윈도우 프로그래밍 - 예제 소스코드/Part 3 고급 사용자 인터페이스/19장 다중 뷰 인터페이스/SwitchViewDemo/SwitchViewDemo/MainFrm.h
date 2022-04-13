
// MainFrm.h : CMainFrame 클래스의 인터페이스
//

#pragma once

#include "MyHtmlView.h"
#include "MyEditView.h"
#include "MyListView.h"

#define VIEWID_DEFAULT		AFX_IDW_PANE_FIRST
#define VIEWID_HTML			AFX_IDW_PANE_FIRST + 10
#define VIEWID_EDIT			AFX_IDW_PANE_FIRST + 20
#define VIEWID_LIST			AFX_IDW_PANE_FIRST + 30

class CMainFrame : public CFrameWnd
{
	
protected: // serialization에서만 만들어집니다.
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// 특성입니다.
public:
	CMyHtmlView*		m_pwndHtmlView;
	CMyEditView*		m_pwndEditView;
	CMyListView*		m_pwndListView;

// 작업입니다.
public:

// 재정의입니다.P
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// 구현입니다.
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 컨트롤 모음이 포함된 멤버입니다.
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

// 생성된 메시지 맵 함수
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()

	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	void SwitchView(int nID);
	afx_msg void OnMenuHtmlview();
	afx_msg void OnMenuEditview();
	afx_msg void OnMenuListview();
};


