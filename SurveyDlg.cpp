// SurveyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Survey.h"
#include "SurveyDlg.h"

#include "Digistatic.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CSpreadSheet SS ("survey.xls", "Sheet1");
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();
	CXPButton	m_OK;
// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDOK, m_OK);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSurveyDlg dialog

CSurveyDlg::CSurveyDlg(CWnd* pParent /*=NULL*/)
	: CHMXDialog(CSurveyDlg::IDD, pParent)
{


	//{{AFX_DATA_INIT(CSurveyDlg)
		// NOTE: the ClassWizard will add member initialization here
	 
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSurveyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSurveyDlg)
	DDX_Control(pDX, IDC_Start, mstart);
	DDX_Control(pDX, IDC_Stop, mstop);
//	DDX_Control(pDX, IDC_DSTRING_STATIC, m_Digistring);
	DDX_Control(pDX, IDC_LUCKMAN, showluckman);
	DDX_Control(pDX, IDC_DSTRING_STATIC2, m_Digistring1);
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSurveyDlg, CDialog)
	//{{AFX_MSG_MAP(CSurveyDlg)
	ON_WM_TIMER()
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Start, OnStart)
	ON_BN_CLICKED(IDC_Stop, OnStop)
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSurveyDlg message handlers

BOOL CSurveyDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	//��ʼ������


	VoteTimer =NULL;//clean Vote timer to zero.

	// TODO: Add extra initialization here
	
	// ������Ӱ������ʾ��������Ӧ��ʾ�ؼ���ϵ����
    m_tooltip.Create(this);
	m_tooltip.AddTool(GetDlgItem(IDC_Start), _T("<b><ct=0x0000FF><al_c>��ʼ�齱</b><br><ct=0x00AA00><hr=100%></ct><br>�����������ȡ"),IDI_PINFORMATION);
	m_tooltip.AddTool(GetDlgItem(IDC_Stop), _T("<b><ct=0x0000FF><al_c>ֹͣ�齱</b><br><ct=0x00AA00><hr=100%></ct><br>�ý����붨��"),IDI_PINFORMATION);

	// ��ʾͼ���λͼ����������
	m_tooltip.SetNotify();
	m_tooltip.SetDefaultFont();
	// ���ñ���Ч��������ɫ
	m_tooltip.SetColor(CPPToolTip::PPTOOLTIP_COLOR_BK_BEGIN, RGB(255, 255, 223));
	m_tooltip.SetColor(CPPToolTip::PPTOOLTIP_COLOR_BK_MID,RGB(192, 192, 172));
	m_tooltip.SetColor(CPPToolTip::PPTOOLTIP_COLOR_BK_END, RGB(128, 128, 112));
	m_tooltip.SetEffectBk(13, 10);

	// ������ʾ��ʾ��Ϣ
	m_tooltip.SetBehaviour(PPTOOLTIP_MULTIPLE_SHOW);
//	AddSzControl(m_Digistring, mdResize, mdResize);
	//SetBitmap(IDB_SKY);
	//��Ҫ��ʾ�����ֽ���һЩ���趨
//	m_Digistring.SetColor(DARKRED, LIGHTRED);
	m_Digistring1.SetColor(DARKRED, LIGHTRED);
//	m_Digistring.SetTransparent(TRUE);
	m_Digistring1.SetTransparent(TRUE);
//	VERIFY(m_Digistring.ModifyDigiStyle(0, CDigiStatic::DS_STYLE14 | CDigiStatic::DS_SZ_PROP | CDigiStatic::DS_NO_OFF));
	VERIFY(m_Digistring1.ModifyDigiStyle(0, CDigiStatic::DS_STYLE14 | CDigiStatic::DS_SZ_PROP | CDigiStatic::DS_NO_OFF));
	//�趨ƽ��
//	m_Digistring.ModifyDigiStyle(0, CDigiStatic::DS_SMOOTH);
	m_Digistring1.ModifyDigiStyle(0, CDigiStatic::DS_SMOOTH);
	//�Ƿ���ʾ14λ
//    m_Digistring.ModifyDigiStyle(CDigiStatic::DS_STYLE14, 0);
	m_Digistring1.ModifyDigiStyle(CDigiStatic::DS_STYLE14, 0);
	//7λ������
	//m_Digistring.ModifyDigiStyle(0, CDigiStatic::DS_STYLE14);
	//������
//	m_Digistring.ModifyDigiStyle(0, CDigiStatic::DS_SZ_PROP);
	m_Digistring1.ModifyDigiStyle(0, CDigiStatic::DS_SZ_PROP);
	//��չŪ
	//m_Digistring.ModifyDigiStyle(CDigiStatic::DS_SZ_PROP, 0);

//	m_Digistring.SetColor(LIGHTBLUE, LIGHTBLUE);
	m_Digistring1.SetText("The exciting lucky draw is coming soon...");
	//��������
/*
	char *pbuff=new char[255];
	GetCurrentDirectory(pbuff, 255);
	szCurrent=pbuff; //��ǰĿ¼
	delete []pbuff;
*/

	//ȡ����ֵ��������

	VoteCount = SS.GetTotalRows();



	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSurveyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSurveyDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this); // device context for painting
		CBitmap bmp; 
		bmp.LoadBitmap(IDB_SKY); 
		//�õ�ͼƬ��Ϣ 
		BITMAP bmpInfo; 
		bmp.GetBitmap(&bmpInfo); 
		//���ڴ��д���һ��λͼ�����豸 
		CDC dcMemory; 
		dcMemory.CreateCompatibleDC(&dc); 
		//��ͼƬѡ������豸 
		CBitmap *pOldBmp=dcMemory.SelectObject(&bmp); 
		//�������豸������copy����Ļ�豸�У�ʵ��������Paint 
		dc.BitBlt(0, 0, bmpInfo.bmWidth, bmpInfo.bmHeight, &dcMemory, 0, 0, SRCCOPY); 
		//���豸��ԭ 
		dcMemory.SelectObject(pOldBmp); 
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSurveyDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSurveyDlg::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

void CSurveyDlg::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

//////////////////////////////////////////////////////////////////////////////
//���ƣ�OnCtlColor
//���ܣ����ø��ؼ�ǰ��������ɫ

/////////////////////////////////////////////////////////////////////////////
HBRUSH CSurveyDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{	
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	if(nCtlColor==CTLCOLOR_LISTBOX)
	{
		//pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0,0,0));
		pDC->SetBkColor(RGB(233,233,220));
		HBRUSH b=CreateSolidBrush(RGB(233,233,220));
		return b;
	}
	else if(nCtlColor==CTLCOLOR_SCROLLBAR)
	{
		
	
	}
	else if(nCtlColor==CTLCOLOR_EDIT)
	{
		
		
	}
	else if(nCtlColor==CTLCOLOR_STATIC)
	{
	
		
	}
	else if(nCtlColor==CTLCOLOR_DLG)
	{
		
		
	}
	
	return hbr;
}

//////////////////////////////////////////////////////////////////////////////
//���ƣ�PreTranslateMessage
//���ܣ���Ӱ������ʾ����Ϣ����
/////////////////////////////////////////////////////////////////////////////
BOOL CSurveyDlg::PreTranslateMessage(MSG* pMsg) 
{
	// Ϊ��Ӱ������ʾ��������¼�����
	m_tooltip.RelayEvent(pMsg);	

	return CDialog::PreTranslateMessage(pMsg);
}


void CSurveyDlg::OnStart() 
{
	// TODO: Add your control notification handler code here

	//��ʼ����

	if (VoteTimer != NULL)
		StopTimer (VoteTimer);

	VoteTimer = NULL;

	VoteTimer = StartTimer (5);
	VoteState = 0;
}

void CSurveyDlg::OnStop() 
{
	// TODO: Add your control notification handler code here
	if (VoteTimer != NULL)
		StopTimer (VoteTimer);

	//SetCurrentIcon (IDI_Net0);

	VoteState = 0;
	VoteTimer = NULL;
	
}

UINT CSurveyDlg::StartTimer (UINT TimerDuration)
{
     UINT    TimerVal;

	 TimerVal = SetTimer (IDT_TIMER_0, TimerDuration, NULL);

     if (TimerVal == 0)
     {
		 MessageBox ("���ܻ�ü�����","IDT_TIMER_0",MB_OK|MB_SYSTEMMODAL);
     }
	 



	 return TimerVal;

}// end StartTimer

//
///////////////////////////////////////////////////////////////////////////////////
//
//		StopTimer - Stops the timer specified
//
//			Returns TRUE if successful, else FALSE
//
///////////////////////////////////////////////////////////////////////////////////
//

BOOL CSurveyDlg::StopTimer (UINT TimerVal)
{
	if (!KillTimer (TimerVal))
	{
		CString Message;
		Message.Format("�������������: %u", TimerVal);
		MessageBox (Message, "StopTimer", MB_OK|MB_SYSTEMMODAL);

		return FALSE;
	}

	//ֹͣ��ʾ�����

//	SetCurrentIcon (IDI_Net0);

	return TRUE;

}

//
///////////////////////////////////////////////////////////////////////////////////
//
//				OnTimer - Timer Input Message Processor
//
//		TimerVal contains the system timer number causing the message.
//
//		This method is used to cycle through each of 4 different icon
//		images to provide a rough animated appearance, but mostly to
//		illustrate how to process timer messages.
//
////////////////////////////////////////////////////////////////////////////////////
//

void CSurveyDlg::OnTimer (UINT TimerVal)
{

	CString	m_LedEdit;

    srand(GetTickCount());
	int a;
	if (VoteCount<=0) VoteCount=1;
	a = rand()%VoteCount;

	if(a<=0) a=1;


	if(!SS.ReadCell(m_LedEdit, 2, a))
	{
		return;
	}



   Split.SetSplitFlag(".");
   Split.SetSequenceAsOne(TRUE);
   Split.SetData(m_LedEdit);
   CStringArray array;
   Split.GetSplitStrArray(array);

	if(array[0]!="F2" && array[0]!="FF") 
		   m_Digistring1.SetText(array[0]);


}

