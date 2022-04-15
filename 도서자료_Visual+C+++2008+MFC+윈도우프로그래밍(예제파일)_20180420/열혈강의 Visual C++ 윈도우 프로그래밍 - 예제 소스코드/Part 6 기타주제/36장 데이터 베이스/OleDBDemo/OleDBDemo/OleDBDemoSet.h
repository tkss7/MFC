
// OleDBDemoSet.h: COleDBDemoSet 클래스의 인터페이스
//


#pragma once

// code generated on 2008년 11월 9일 일요일, 오전 1:54

class COleDBDemoSetAccessor
{
public:
	LONG m_SeqNum;
	TCHAR m_Name[51];
	TCHAR m_PhoneNumber[51];
	TCHAR m_Address[51];
	LONG m_Age;

	// The following wizard-generated data members contain status
	// values for the corresponding fields in the column map. You
	// can use these values to hold NULL values that the database
	// returns or to hold error information when the compiler returns
	// errors. See Field Status Data Members in Wizard-Generated
	// Accessors in the Visual C++ documentation for more information
	// on using these fields.
	// NOTE: You must initialize these fields before setting/inserting data!

	DBSTATUS m_dwAddressStatus;
	DBSTATUS m_dwAgeStatus;
	DBSTATUS m_dwNameStatus;
	DBSTATUS m_dwPhoneNumberStatus;
	DBSTATUS m_dwSeqNumStatus;

	// The following wizard-generated data members contain length
	// values for the corresponding fields in the column map.
	// NOTE: For variable-length columns, you must initialize these
	//       fields before setting/inserting data!

	DBLENGTH m_dwAddressLength;
	DBLENGTH m_dwAgeLength;
	DBLENGTH m_dwNameLength;
	DBLENGTH m_dwPhoneNumberLength;
	DBLENGTH m_dwSeqNumLength;


	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL);
		pPropSet->AddProperty(DBPROP_UPDATABILITY,
								DBPROPVAL_UP_CHANGE | 
								DBPROPVAL_UP_INSERT | 
								DBPROPVAL_UP_DELETE);
	}

	HRESULT OpenDataSource()
	{
		CDataSource _db;
		HRESULT hr;
//#error Security Issue: The connection string may contain a password
// The connection string below may contain plain text passwords and/or
// other sensitive information. Please remove the #error after reviewing
// the connection string for any security related issues. You may want to
// store the password in some other form or use a different user authentication.
		hr = _db.OpenFromInitializationString(L"Provider=Microsoft.Jet.OLEDB.4.0;User ID=Admin;Data Source=C:\\Documents and Settings\\\xcd5c\xd638\xc131\\\xbc14\xd0d5 \xd654\xba74\\UserList.mdb;Mode=Share Deny None;Extended Properties=\"\";Jet OLEDB:System database=\"\";Jet OLEDB:Registry Path=\"\";Jet OLEDB:Database Password=\"\";Jet OLEDB:Engine Type=5;Jet OLEDB:Database Locking Mode=1;Jet OLEDB:Global Partial Bulk Ops=2;Jet OLEDB:Global Bulk Transactions=1;Jet OLEDB:New Database Password=\"\";Jet OLEDB:Create System Database=False;Jet OLEDB:Encrypt Database=False;Jet OLEDB:Don't Copy Locale on Compact=False;Jet OLEDB:Compact Without Replica Repair=False;Jet OLEDB:SFP=False");
		if (FAILED(hr))
		{
#ifdef _DEBUG
			AtlTraceErrorRecords(hr);
#endif
			return hr;
		}
		return m_session.Open(_db);
	}

	void CloseDataSource()
	{
		m_session.Close();
	}

	operator const CSession&()
	{
		return m_session;
	}

	CSession m_session;

	BEGIN_COLUMN_MAP(COleDBDemoSetAccessor)
		COLUMN_ENTRY_LENGTH_STATUS(4, m_Address, m_dwAddressLength, m_dwAddressStatus)
		COLUMN_ENTRY_LENGTH_STATUS(5, m_Age, m_dwAgeLength, m_dwAgeStatus)
		COLUMN_ENTRY_LENGTH_STATUS(2, m_Name, m_dwNameLength, m_dwNameStatus)
		COLUMN_ENTRY_LENGTH_STATUS(3, m_PhoneNumber, m_dwPhoneNumberLength, m_dwPhoneNumberStatus)
		COLUMN_ENTRY_LENGTH_STATUS(1, m_SeqNum, m_dwSeqNumLength, m_dwSeqNumStatus)
	END_COLUMN_MAP()
};

//class COleDBDemoSet : public CTable<CAccessor<COleDBDemoSetAccessor> >
class COleDBDemoSet : public CCommand<CAccessor<COleDBDemoSetAccessor> >
{
public:
	HRESULT OpenAll()
	{
		HRESULT hr;
		hr = OpenDataSource();
		if (FAILED(hr))
			return hr;
		__if_exists(GetRowsetProperties)
		{
			CDBPropSet propset(DBPROPSET_ROWSET);
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
					propset.AddProperty(DBPROP_IRowsetLocate, true);
			}
			GetRowsetProperties(&propset);
			return OpenRowset(&propset);
		}
		__if_not_exists(GetRowsetProperties)
		{
			__if_exists(HasBookmark)
			{
				if( HasBookmark() )
				{
					CDBPropSet propset(DBPROPSET_ROWSET);
					propset.AddProperty(DBPROP_IRowsetLocate, true);
					return OpenRowset(&propset);
				}
			}
		}
		return OpenRowset();
	}

	HRESULT OpenRowset(DBPROPSET *pPropSet = NULL)
	{
//		HRESULT hr = Open(m_session, L"UserData", pPropSet);
		CString strSQL = _T("SELECT * FROM UserData");
		HRESULT hr = Open(m_session, strSQL, pPropSet);
#ifdef _DEBUG
		if(FAILED(hr))
			AtlTraceErrorRecords(hr);
#endif
		return hr;
	}

	HRESULT RunSQL(CString strSQL, DBPROPSET *pPropSet = NULL)
	{
		Close();
		ReleaseCommand();
		HRESULT hr = Open(m_session, strSQL, pPropSet);
		return hr;
	}

	void CloseAll()
	{
		Close();
		CloseDataSource();
	}
};

