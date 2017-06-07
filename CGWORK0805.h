// CGWORK0805.h : main header file for the CGWORK0805 application
//

#if !defined(AFX_CGWORK0805_H__EF1B9CE8_559C_4E17_84B1_A7FF410EEA18__INCLUDED_)
#define AFX_CGWORK0805_H__EF1B9CE8_559C_4E17_84B1_A7FF410EEA18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0805App:
// See CGWORK0805.cpp for the implementation of this class
//

class CCGWORK0805App : public CWinApp
{
public:
	CCGWORK0805App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGWORK0805App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCGWORK0805App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGWORK0805_H__EF1B9CE8_559C_4E17_84B1_A7FF410EEA18__INCLUDED_)
