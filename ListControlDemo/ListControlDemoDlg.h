
// ListControlDemoDlg.h: 헤더 파일
//

#pragma once


// CListControlDemoDlg 대화 상자
class CListControlDemoDlg : public CDialog
{
// 생성입니다.
public:
	CListControlDemoDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LISTCONTROLDEMO_DIALOG };
#endif

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
	CImageList imageList;
	CImageList imageListSmall;
	CListCtrl m_listCtrl;
	CComboBox m_comboBox;
//	afx_msg void OnLvnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnLvnEndlabeleditList1(NMHDR* pNMHDR, LRESULT* pResult);
};
