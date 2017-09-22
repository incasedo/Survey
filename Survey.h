// Survey.h : main header file for the SURVEY application
//

#if !defined(AFX_SURVEY_H__F4B07F74_E582_4AE1_BA32_3446A5976B72__INCLUDED_)
#define AFX_SURVEY_H__F4B07F74_E582_4AE1_BA32_3446A5976B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSurveyApp:
// See Survey.cpp for the implementation of this class
//

class CSurveyApp : public CWinApp
{
public:
	CSurveyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSurveyApp)
	public:
	virtual BOOL InitInstance();

	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSurveyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SURVEY_H__F4B07F74_E582_4AE1_BA32_3446A5976B72__INCLUDED_)
