
// ComboExDemoDlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"


// CComboExDemoDlg 대화 상자
class CComboExDemoDlg : public CDialog
{
// 생성입니다.
public:
	CComboExDemoDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_COMBOEXDEMO_DIALOG };

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
	//확장 콤보 박스에 사용될 이미지 리스트
	CImageList		m_ImgList;
	//확장 콤보 박스
	CComboBoxEx		m_ComboEx;
	CString m_strInput;
};
