
// DragDemoDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"


// CDragDemoDlg 대화 상자
class CDragDemoDlg : public CDialog
{
// 생성입니다.
public:
	CDragDemoDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DRAGDEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	CListCtrl m_List_Left;
	CListCtrl m_List_Right;

	CImageList*		m_pImgListDrag;
	int				m_nIndexLeftSel;

	afx_msg void OnLvnBegindragListLeft(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);

	afx_msg void OnBnClickedRstRightlist();
};
