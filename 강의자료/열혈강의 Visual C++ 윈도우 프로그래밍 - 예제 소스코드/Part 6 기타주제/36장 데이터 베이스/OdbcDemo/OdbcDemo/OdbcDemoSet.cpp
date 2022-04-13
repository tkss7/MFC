
// OdbcDemoSet.cpp : COdbcDemoSet 클래스의 구현
//

#include "stdafx.h"
#include "OdbcDemo.h"
#include "OdbcDemoSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COdbcDemoSet 구현

// code generated on 2008년 11월 7일 금요일, 오후 7:19

IMPLEMENT_DYNAMIC(COdbcDemoSet, CRecordset)

COdbcDemoSet::COdbcDemoSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_SeqNum = 0;
	m_Name = L"";
	m_PhoneNumber = L"";
	m_Address = L"";
	m_Age = 0;
	m_nFields = 5;
	m_nDefaultType = dynaset;
}
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
CString COdbcDemoSet::GetDefaultConnect()
{
	return _T("DSN=UserList Data;DBQ=C:\\DOCUMENTS AND SETTINGS\\\xcd5c\xd638\xc131\\\xbc14\xd0d5 \xd654\xba74\\UserList.mdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString COdbcDemoSet::GetDefaultSQL()
{
	return _T("[UserData]");
}

void COdbcDemoSet::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// Macros such as RFX_Text() and RFX_Int() are dependent on the
// type of the member variable, not the type of the field in the database.
// ODBC will try to automatically convert the column value to the requested type
	RFX_Long(pFX, _T("[SeqNum]"), m_SeqNum);
	RFX_Text(pFX, _T("[Name]"), m_Name);
	RFX_Text(pFX, _T("[PhoneNumber]"), m_PhoneNumber);
	RFX_Text(pFX, _T("[Address]"), m_Address);
	RFX_Long(pFX, _T("[Age]"), m_Age);

}
/////////////////////////////////////////////////////////////////////////////
// COdbcDemoSet diagnostics

#ifdef _DEBUG
void COdbcDemoSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void COdbcDemoSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

