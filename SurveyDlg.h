// SurveyDlg.h : header file
//

#if !defined(AFX_SURVEYDLG_H__740EDF7A_5B43_45B6_AC35_EB6A71060EB8__INCLUDED_)
#define AFX_SURVEYDLG_H__740EDF7A_5B43_45B6_AC35_EB6A71060EB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "xpbutton.h"					// XP风格按钮
#include "HoverEdit.h"                  // XP风格编辑框
#include "PPToolTip.h"					// 加入阴影工具提示
#include "cdxCDynamicDialog.h"
//#include "BkDialogST.h"
#include "HMXDialog.h"
#include "HMXStatic.h"
#include "HMXCheckBox.h"
#include "SplitStr.h"

#include "Digiutil.h"
#include "CSpreadSheet.h"

#define IDT_TIMER_0		WM_USER + 200
#define TimerInterval	100				// 500 mSec.

/////////////////////////////////////////////////////////////////////////////
// CSurveyDlg dialog

class CSurveyDlg : public CHMXDialog
{
// Construction
public:
	CSurveyDlg(CWnd* pParent = NULL);	// standard constructor
    
	CStringArray SurveyA;//投票数据

	int VoteCount;//总投票人数
	CXPButton mstart;
	CXPButton mstop;
	UINT		VoteTimer;
	int VoteState;//计数状态
//	CDigiStatic	m_Digistring;//数字时显示
	CDigiStatic	m_Digistring1;//数字时显示
	CStatic showluckman;

	CSplitStr Split;//切分字符

public:

	BOOL StopTimer (UINT TimerVal);
	UINT StartTimer (UINT TimerDuration);
// Dialog Data
	//{{AFX_DATA(CSurveyDlg)
	enum { IDD = IDD_SURVEY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSurveyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CPPToolTip m_tooltip;         // 定义阴影工具提示变量
	// Generated message map functions
	//{{AFX_MSG(CSurveyDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT);
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnStart();
	afx_msg void OnStop();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SURVEYDLG_H__740EDF7A_5B43_45B6_AC35_EB6A71060EB8__INCLUDED_)
