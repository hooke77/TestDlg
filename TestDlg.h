// TestDlg.h : main header file for the TESTDLG application
//

#if !defined(AFX_TESTDLG_H__05AE2850_390D_4473_A094_76DFFC314F08__INCLUDED_)
#define AFX_TESTDLG_H__05AE2850_390D_4473_A094_76DFFC314F08__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestDlgApp:
// See TestDlg.cpp for the implementation of this class
//

class CTestDlgApp : public CWinApp
{
public:
	CTestDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTDLG_H__05AE2850_390D_4473_A094_76DFFC314F08__INCLUDED_)
