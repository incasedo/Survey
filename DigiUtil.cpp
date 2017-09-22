// DigiUtil.cpp: implementation of the CDigiClock class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "DigiUtil.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDigiClock::CDigiClock()
{
	m_bAlarm  = FALSE;
	m_style	  = XDC_SECOND;
	m_strText = _T("--:--:--");
	m_nCount  = 0;
}

BEGIN_MESSAGE_MAP(CDigiClock, CDigiStatic)
	//{{AFX_MSG_MAP(CDigiClock)
	ON_WM_TIMER()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDigiClock message handlers

void CDigiClock::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	m_nTimer = SetTimer(1, 1000, NULL);
	ASSERT(m_nTimer);
	
	CDigiStatic::PreSubclassWindow();
}

void CDigiClock::OnDestroy() 
{
	CDigiStatic::OnDestroy();
	
	// TODO: Add your message handler code here
	KillTimer(m_nTimer);	
}

void CDigiClock::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == m_nTimer)
	{
		m_nCount++;
		CTime time = CTime::GetCurrentTime();
		int nh = time.GetHour();
		int nm = time.GetMinute();
		int ns = time.GetSecond();

		switch(m_style) {
			case XDC_SECOND:
			{
				if (m_bAlarm && m_nCount%2)
					m_strText = _T("  :  :  ");
				else
					m_strText.Format(_T("%02d:%02d:%02d"), nh, nm, ns);
			}
			break;
			case XDC_NOSECOND:
			default:
				if (m_bAlarm && m_nCount%2)
					m_strText = _T("  :  ");
				else
					m_strText.Format(_T("%02d:%02d:"), nh, nm);
				break;
		};
		if (m_bAlarm)
			MessageBeep(MB_OK);
		m_Modified = TRUE;
		DoInvalidate();
	}

	CDigiStatic::OnTimer(nIDEvent);
}

BOOL CDigiClock::SetAlarm(BOOL bAlarm /*= TRUE*/)
{
	BOOL temp = m_bAlarm;
	m_bAlarm = bAlarm;
	return temp;
}

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDigiScroll::CDigiScroll() 
{ 
	m_iTextLength = 12; 
	m_lSpeed = 200l; 
	m_CurrText = m_strTextToScroll = "This is an example scrolling display ";
	m_Flash = -1;
} 

BEGIN_MESSAGE_MAP(CDigiScroll, CDigiStatic) 
//{{AFX_MSG_MAP(CDigiScroll) 
ON_WM_TIMER() 
//}}AFX_MSG_MAP 
END_MESSAGE_MAP() 


///////////////////////////////////////////////////////////////////////////// 
// CDigiClock message handlers 

void CDigiScroll::PreSubclassWindow() 
{ 
	SetTimer(1, m_lSpeed, NULL); 
	SetTimer(2, 100, NULL); 
	CDigiStatic::PreSubclassWindow(); 
} 

void CDigiScroll::SetScrollText(LPCTSTR lpszFormat) 
{ 
	m_CurrText = m_strTextToScroll = lpszFormat;
	if (!m_strTextToScroll.IsEmpty())
	{
	  if (m_strTextToScroll[m_strTextToScroll.GetLength()-1] != ' ')
		  m_strTextToScroll += " ";
	}
	m_ScrollPos = 0;
	ContentToSize();
} 

void CDigiScroll::Flash(BOOL f)
{ 
	if (f) 
		m_Flash = 0;
	else 
	{
		m_Flash = -1;
	}
}

void CDigiScroll::SetSpeed(long lSpeed) 
{
	if (lSpeed < 50)
		lSpeed = 50;
	
	m_lSpeed = lSpeed;
	
	SetTimer(1,m_lSpeed,NULL);
} 

void CDigiScroll::SetTextLength(int iMaxLength) 
{ 
	if (iMaxLength < 0)
		return;

	m_iTextLength = iMaxLength;
	ContentToSize();
} 

void CDigiScroll::OnDestroy() 
{
	Scroll(FALSE);
	CDigiStatic::OnDestroy();
}

void CDigiScroll::OnTimer(UINT nIDEvent) 
{ 
	if (nIDEvent == 1)
	{
		if (m_Flash >= 20)
		{
			m_Flash = (m_Flash + 1) % 2;
			if (m_Flash)
			{
				CString f;
				for (int i = 0; i<m_iTextLength; i++)
					if (i < m_strText.GetLength() && (m_strText[i] == ':' || m_strText[i] == '.'))
						f += ";";
					else
						f += " ";
				SetText(f);
				return;
			}
		}

		if (m_bScroll)
		{
			ScrollText();
		}
	}
} 

void CDigiScroll::ScrollText(int nPlaces)
{
	for (int i = 0; i < abs(nPlaces); i++)
	{
		CString strTemp; 
		CString strNewString; 

		if (nPlaces > 0)
		{
			strTemp = m_strTextToScroll[0]; 
			strNewString = m_strTextToScroll.Mid(1); 
			strNewString += strTemp;
		}
		else
		{
			strTemp = m_strTextToScroll[m_strTextToScroll.GetLength()-1]; 
			strNewString = m_strTextToScroll.Left(m_strTextToScroll.GetLength()-1); 
			strTemp += strNewString;
			strNewString = strTemp;
		}
		
		m_strTextToScroll = strNewString; 

		if (m_strTextToScroll.Left(m_CurrText.GetLength()) == m_CurrText)
			m_ScrollPos = 0;
		else
			m_ScrollPos+=(nPlaces/abs(nPlaces));

		SetText(m_strTextToScroll.Mid(0,GetTextLength()));
	}
}

void CDigiScroll::Scroll(BOOL s) 
{ 
	m_bScroll = s;
} 

void CDigiScroll::ContentToSize()
{
	CString temp(m_CurrText);
	if (m_CurrText.GetLength() < GetTextLength())
	{
		for (int i = m_CurrText.GetLength(); i < GetTextLength(); i++)
			temp += _T(" ");

		m_strTextToScroll = temp;
	}
	else
	{
		temp = temp.Left(GetTextLength());
	}
	
	ASSERT(temp.GetLength() == GetTextLength());
	SetText(temp);
}

