// CallConvention.h : main header file for the CALLCONVENTION application
//

#if !defined(AFX_CALLCONVENTION_H__C0C7CDA6_D68E_45EA_8D42_0A6A5525C345__INCLUDED_)
#define AFX_CALLCONVENTION_H__C0C7CDA6_D68E_45EA_8D42_0A6A5525C345__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCallConventionApp:
// See CallConvention.cpp for the implementation of this class
//

class CCallConventionApp : public CWinApp
{
public:
	CCallConventionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCallConventionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCallConventionApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALLCONVENTION_H__C0C7CDA6_D68E_45EA_8D42_0A6A5525C345__INCLUDED_)
