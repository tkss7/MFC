
// MemberMgrDlg.h: 헤더 파일
//

#pragma once

//class CMember {
//public:
//	~CMember() {
//		TRACE("소멸자\n");
//	}
//
//	CString m_strId;
//	CString m_strName;
//	int     m_nPostCode;
//	CString m_strAddress;
//	BOOL    m_bSex;
//	CString m_strPhone1;
//	CString m_strPhone2;
//	CString m_strPhone3;
//	int     m_nAge;
//	int		m_nHobby;
//};
//
//using CMemberPtr = shared_ptr<CMember>;

#include "ModalDemoDoc.h"

// CMemberMgrDlg 대화 상자
class CMemberMgrDlg : public CDialogEx
{
// 생성입니다.
public:
	CMemberMgrDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

//	vector<CMemberPtr> m_array;
public:
	CMemberPtr GetMemberPtr() {
		CMemberPtr pMember = make_shared<CMember>();

		pMember->m_strId = m_strID;
		pMember->m_strName = m_strName;
		pMember->m_nPostCode = m_nPostCode;
		pMember->m_strAddress = m_strAddress;
		pMember->m_bSex = m_bMale ? TRUE : FALSE;
		pMember->m_strPhone1 = m_strPhone1;
		pMember->m_strPhone2 = m_strPhone2;
		pMember->m_strPhone3 = m_strPhone3;
		pMember->m_nAge = m_nAge;
		pMember->m_nHobby = m_nHobby;

		return pMember;
	}

	void SetMemberPtr(const CMemberPtr pMember) {
		m_strID = pMember->m_strId;
		m_strName = pMember->m_strName;
		m_nPostCode = pMember->m_nPostCode;
		m_strAddress = pMember->m_strAddress;
		m_bMale = pMember->m_bSex;
		m_bFemale = !pMember->m_bSex;
		m_strPhone1 = pMember->m_strPhone1;
		m_strPhone2 = pMember->m_strPhone2;
		m_strPhone3 = pMember->m_strPhone3;
		m_nAge = pMember->m_nAge;
		m_nHobby = pMember->m_nHobby;
}

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MEMBERMGR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

private:
	bool IsEmpty(const CString& strText, LPCTSTR lpszMsg, UINT id) const;

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
	// 아이디
	CString m_strID;
	// 이름
	CString m_strName;
	// 우편번호
	int m_nPostCode;
	// 주소
	CString m_strAddress;
	BOOL m_bMale;
	BOOL m_bFemale;
	// 전화번호
	CString m_strPhone1;
	CString m_strPhone2;
	CString m_strPhone3;
	// 나이
	int m_nAge;
	int m_nHobby;

	afx_msg void OnBnClickedButtonNew();
	afx_msg void OnBnClickedCheckMale();
	CEdit m_wndId;
	afx_msg void OnBnClickedBtnFind();
	afx_msg void OnBnClickedBtnAdd();
	afx_msg void OnBnClickedBtnUpdate();
	afx_msg void OnBnClickedBtnDelete();
	afx_msg void OnBnClickedOk();
};
