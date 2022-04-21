﻿
// RangeDemoDlg.h: 헤더 파일
//

#pragma once


// CRangeDemoDlg 대화 상자
class CRangeDemoDlg : public CDialog
{
// 생성입니다.
public:
	CRangeDemoDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RANGEDEMO_DIALOG };
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
	CProgressCtrl m_progressCtrl;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CButton m_wndInc;
	CButton m_wndDec;
	int m_nPos;
	CSliderCtrl m_sliderCtrl;
	int m_nEditPos;
	afx_msg void OnTRBNThumbPosChangingSlider1(NMHDR* pNMHDR, LRESULT* pResult);
	CSpinButtonCtrl m_wndSpin;
	afx_msg void OnEnChangeEdit1();
};
