// TestData.cpp : implementation file
//

#include "stdafx.h"
#include "SerializeDemo.h"
#include "TestData.h"


// CTestData

IMPLEMENT_SERIAL(CTestData, CObject, VERSIONABLE_SCHEMA | 2)

CTestData::CTestData()
{
	m_nData = 0;
	m_nLine = 0;
}

CTestData::~CTestData()
{
}


// CTestData member functions

void CTestData::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << m_nData << m_nLine;
	}
	else
	{
		ar >> m_nData >> m_nLine;
	}
}
