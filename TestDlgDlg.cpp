// TestDlgDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestDlg.h"
#include "TestDlgDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#define IsKeyToggled(nVirtKey) (GetKeyState(VK_CAPITAL) & 1 )==1 
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
	int width = 37;
	int height = 31;

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

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
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlgDlg dialog

CTestDlgDlg::CTestDlgDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestDlgDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestDlgDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestDlgDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestDlgDlg, CDialog)
	//{{AFX_MSG_MAP(CTestDlgDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestDlgDlg message handlers

BOOL CTestDlgDlg::OnInitDialog()
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
	
	// TODO: Add extra initialization here
	if( IsKeyToggled(VK_CONTROL) )
	{
		((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(TRUE);
	}
	else
		((CButton*)GetDlgItem(IDC_CHECK1))->SetCheck(FALSE);
		
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CTestDlgDlg::OnPaint() 
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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestDlgDlg::OnOK() 
{
	// TODO: Add extra validation here
	
//	CDialog::OnOK();


	typedef void (*lpFun)(void);
	HINSTANCE hDll;
	hDll=LoadLibrary("TestDll.dll");
	if(NULL==hDll)
	{
		MessageBox("加载失败");
	}
	lpFun addFun;
	lpFun pShowDlg=(lpFun)GetProcAddress(hDll,"ShowDlg");
	if(pShowDlg==NULL)
	{
		MessageBox("加载失败");
	}
	pShowDlg();

	CloseHandle(hDll);
}

void CTestDlgDlg::OnButton1() 
{

	int vk;
	vk = VK_CONTROL;

	int nRet = GetKeyState(VK_CAPITAL) & 0x8000;
	
	if(nRet== 1 )
	{
		AfxMessageBox("CAP按下去了");
	}
	else if(nRet==0)
	{
		AfxMessageBox("CAP没按下去了");

	}


}

void CTestDlgDlg::OnButton2() 
{
	int vk;
	vk = VK_CONTROL;

/*	int nRet = GetKeyState(VK_CAPITAL) & 1;
	
	if(nRet== 0)
	{
		AfxMessageBox("CAP没按下去了");
	}
	else if(nRet ==1)
	{
		AfxMessageBox("CAP按下去了");

	}	*/
	if( IsKeyToggled (VK_CONTROL) )
	{
		AfxMessageBox("CAP按下去了");
		
	}
	else
	{
		AfxMessageBox("CAP没按下去了");
		
	}
}

void CTestDlgDlg::OnButton3() 
{
	  keybd_event(VK_CAPITAL, NULL, KEYEVENTF_EXTENDEDKEY | 0, NULL);
	  keybd_event(VK_CAPITAL, NULL, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, NULL);					
	
}

void CTestDlgDlg::OnButton4() 
{
	GotoDlgCtrl(GetDlgItem(IDC_EDIT1));
	CString strShiftBuf = "~!@#$%^&*()_+{}|:\"<>?";
	int nLen =  strShiftBuf.GetLength();

	nLen =  strShiftBuf.Find('&',0) ;


	AfxMessageBox(strShiftBuf);
//keybd_event(VK_SHIFT, 0, 0, 0);
//keybd_event('&', 0, 0, 0);
//keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
//keybd_event('&',0,KEYEVENTF_KEYUP,0);

}

void CTestDlgDlg::OnButton5() 
{
	CClientDC dc(this);
	CRect client;
	GetClientRect(client);
	CRgn clipRgn;
	clipRgn.CreateRectRgnIndirect(&client);
	dc.SelectClipRgn(&clipRgn);
	dc.SelectObject(GetStockObject(DEFAULT_GUI_FONT));
	dc.SetBkMode(TRANSPARENT);

//	int width = 50;
//	int height = 50;
	int x = 0;
	int y = 0;
	int i = 0; //不支持循环内定义变量，需要放在循环外定义




	for ( i=0;i<=6;i++ )
	{
		CRect rc(x+i*width,y,x+i*width + width, y + height);
		if( i ==0 )
			rc.DeflateRect(1,1);
		else if( i==1 )
		{
			rc.DeflateRect(1,1);
			dc.FillSolidRect(rc,GetSysColor(COLOR_3DFACE));
			
		}
		else if(i==2 )
		{
			rc.DeflateRect(1,1);
			dc.FillSolidRect(rc,GetSysColor(COLOR_3DFACE));
					
		}
		else if(i==3 ) //还原
		{
			rc.DeflateRect(1,1);
			dc.FillSolidRect(rc,GetSysColor(COLOR_3DFACE));
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DSHADOW),GetSysColor(COLOR_3DDKSHADOW)); //COLOR_3DHIGHLIGHT
					
		}
		else if(i==4 )
		{
			rc.DeflateRect(1,1);
			dc.FillSolidRect(rc,GetSysColor(COLOR_3DFACE));
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DSHADOW),GetSysColor(COLOR_3DDKSHADOW)); //COLOR_3DHIGHLIGHT
			rc.DeflateRect(1,1);
					
		}		
		else if(i==5 )
		{
			rc.DeflateRect(1,1);
			dc.FillSolidRect(rc,GetSysColor(COLOR_3DFACE));
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DSHADOW),GetSysColor(COLOR_3DDKSHADOW)); //COLOR_3DHIGHLIGHT
			rc.DeflateRect(1,1);
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DLIGHT),GetSysColor(COLOR_3DSHADOW));
			dc.DrawText("C",CRect(rc.left,rc.top,rc.right,rc.bottom),DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_NOPREFIX );
					
		}		
		
	}

	x=0;
	y = height;
	
	for (  i=0;i<=6;i++ )
	{
		CRect rc(x+i*width,y,x+i*width + width, y + height);
		if( i ==0 )
			rc.DeflateRect(1,1);
		else if( i==1 )
		{
			rc.DeflateRect(1,1);
			dc.FillSolidRect(rc,GetSysColor(COLOR_3DLIGHT));
			
		}
		else if(i==2 )
		{
			rc.DeflateRect(1,1);
			dc.FillSolidRect(rc,GetSysColor(COLOR_3DLIGHT));
					
		}
		else if(i==3 ) //还原
		{
			rc.DeflateRect(1,1);	
			dc.FillSolidRect(rc,GetSysColor(COLOR_3DLIGHT));
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DLIGHT),GetSysColor(COLOR_3DSHADOW)); //COLOR_3DHIGHLIGHT
					
		}
		else if(i==4 )
		{
			rc.DeflateRect(1,1);
			dc.FillSolidRect(rc,GetSysColor(COLOR_3DLIGHT));
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DLIGHT),GetSysColor(COLOR_3DSHADOW)); //COLOR_3DHIGHLIGHT
			rc.DeflateRect(1,1);
					
		}		
		else if(i==5 )
		{
			rc.DeflateRect(1,1);
			dc.FillSolidRect(rc,GetSysColor(COLOR_3DLIGHT));
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DLIGHT),GetSysColor(COLOR_3DSHADOW)); //COLOR_3DHIGHLIGHT
			rc.DeflateRect(1,1);
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DSHADOW),GetSysColor(COLOR_3DDKSHADOW));
			dc.DrawText("d",CRect(rc.left,rc.top,rc.right,rc.bottom),DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_NOPREFIX );
					
		}		
		
	}


	
}

void CTestDlgDlg::OnButton6() 
{
	CClientDC dc(this);
	CRect client;
	GetClientRect(client);
	CRgn clipRgn;
	clipRgn.CreateRectRgnIndirect(&client);
	dc.SelectClipRgn(&clipRgn);
	dc.SelectObject(GetStockObject(DEFAULT_GUI_FONT));
	dc.SetBkMode(TRANSPARENT);

	CRect client1;
    CRect lpRect;
//	GetDlgItem(IDC_BUTTON5)->GetClientRect(client1);
 //  GetDlgItem(IDC_BUTTON5)->GetWindowRect(&lpRect);
//	ClientToScreen(client1);
//	ClientToScreen(lpRect);
	GetDlgItem(IDC_BUTTON5)->GetWindowRect(client1);
	ScreenToClient(&client1);
//	int width = 50;
//	int height = 50;

	int x=0;
	int y = client1.top -   height;
	CRect rc(x,y,x+ width, y + height);
			rc.DeflateRect(1,1);
			dc.FillSolidRect(rc,GetSysColor(COLOR_3DFACE));
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DSHADOW),GetSysColor(COLOR_3DDKSHADOW)); //COLOR_3DHIGHLIGHT
			rc.DeflateRect(1,1);
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DLIGHT),GetSysColor(COLOR_3DSHADOW));
			dc.DrawText("C",CRect(rc.left,rc.top,rc.right,rc.bottom),DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_NOPREFIX );

}

void CTestDlgDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	CRect client;
	GetClientRect(client);
	CRgn clipRgn;
	clipRgn.CreateRectRgnIndirect(&client);
	dc.SelectClipRgn(&clipRgn);
	dc.SelectObject(GetStockObject(DEFAULT_GUI_FONT));
	dc.SetBkMode(TRANSPARENT);

	CRect client1;
	GetDlgItem(IDC_BUTTON5)->GetWindowRect(client1);
	ScreenToClient(&client1);

	int x=0;
	int y = client1.top -   height;
	CRect rc(x,y,x+ width, y + height);
	if(rc.PtInRect(point))
	{
	//	::SetCursor(AfxGetApp()->LoadCursor(IDC_CURSOR1));
	//		rc.DeflateRect(1,1);
	//		dc.FillSolidRect(rc,GetSysColor(COLOR_3DLIGHT));
	//		dc.Draw3dRect(rc,GetSysColor(COLOR_3DLIGHT),GetSysColor(COLOR_3DSHADOW)); //COLOR_3DHIGHLIGHT
	//		rc.DeflateRect(1,1);
	//		dc.Draw3dRect(rc,GetSysColor(COLOR_3DSHADOW),GetSysColor(COLOR_3DDKSHADOW));
	//		dc.DrawText("d",CRect(rc.left,rc.top,rc.right,rc.bottom),DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_NOPREFIX );
	//	return;
						//将新选中的用深色填充一遍
				CPen pen;
				pen.CreatePen(PS_SOLID,1,RGB(250,0,0));
				dc.SelectObject(&pen);
				dc.MoveTo(x,y);
				dc.LineTo(x + width-1,y);
				dc.LineTo(x + width-1,y + height-1);
				dc.LineTo(x,y + height-1);
				dc.LineTo(x,y);
					pen.DeleteObject();
	}
	else
	{
//			rc.DeflateRect(1,1);
//			dc.FillSolidRect(rc,GetSysColor(COLOR_3DFACE));
//			dc.Draw3dRect(rc,GetSysColor(COLOR_3DSHADOW),GetSysColor(COLOR_3DDKSHADOW)); //COLOR_3DHIGHLIGHT
//			rc.DeflateRect(1,1);
//			dc.Draw3dRect(rc,GetSysColor(COLOR_3DLIGHT),GetSysColor(COLOR_3DSHADOW));
//			dc.DrawText("d",CRect(rc.left,rc.top,rc.right,rc.bottom),DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_NOPREFIX );
			
		
		
				CPen pen1;
				pen1.CreatePen(PS_SOLID,1,RGB(250,235,255) );
				dc.SelectObject(&pen1);
				dc.MoveTo(x,y);
				dc.LineTo(x + width-1,y);
				dc.LineTo(x + width-1,y + height-1);
				dc.LineTo(x,y + height-1);
				dc.LineTo(x,y);

					pen1.DeleteObject();
	
	}
	

	
	CDialog::OnMouseMove(nFlags, point);
}

void CTestDlgDlg::OnLButtonDown(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	CRect client;
	GetClientRect(client);
	CRgn clipRgn;
	clipRgn.CreateRectRgnIndirect(&client);
	dc.SelectClipRgn(&clipRgn);
	dc.SelectObject(GetStockObject(DEFAULT_GUI_FONT));
	dc.SetBkMode(TRANSPARENT);

	CRect client1;
	GetDlgItem(IDC_BUTTON5)->GetWindowRect(client1);
	ScreenToClient(&client1);
//	int width = 50;
//	int height = 50;

	int x=0;
	int y = client1.top -   height;
	CRect rc(x,y,x+ width, y + height);
	if(rc.PtInRect(point))
	{
			rc.DeflateRect(1,1);
			dc.FillSolidRect(rc,GetSysColor(COLOR_3DLIGHT));
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DLIGHT),GetSysColor(COLOR_3DSHADOW)); //COLOR_3DHIGHLIGHT
			rc.DeflateRect(1,1);
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DSHADOW),GetSysColor(COLOR_3DDKSHADOW));
			dc.DrawText("C",CRect(rc.left,rc.top,rc.right,rc.bottom),DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_NOPREFIX );

	}
	else
	{
		
	}

	CDialog::OnLButtonDown(nFlags, point);
}

void CTestDlgDlg::OnLButtonUp(UINT nFlags, CPoint point) 
{
	CClientDC dc(this);
	CRect client;
	GetClientRect(client);
	CRgn clipRgn;
	clipRgn.CreateRectRgnIndirect(&client);
	dc.SelectClipRgn(&clipRgn);
	dc.SelectObject(GetStockObject(DEFAULT_GUI_FONT));
	dc.SetBkMode(TRANSPARENT);

	CRect client1;
	GetDlgItem(IDC_BUTTON5)->GetWindowRect(client1);
	ScreenToClient(&client1);
//	int width = 50;
//	int height = 50;

	int x=0;
	int y = client1.top -   height;
	CRect rc(x,y,x+ width, y + height);
	if(rc.PtInRect(point))
	{
			rc.DeflateRect(1,1);
			dc.FillSolidRect(rc,GetSysColor(COLOR_3DFACE));
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DSHADOW),GetSysColor(COLOR_3DDKSHADOW)); //COLOR_3DHIGHLIGHT
			rc.DeflateRect(1,1);
			dc.Draw3dRect(rc,GetSysColor(COLOR_3DLIGHT),GetSysColor(COLOR_3DSHADOW));
			dc.DrawText("C",CRect(rc.left,rc.top,rc.right,rc.bottom),DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_NOPREFIX );

	}	
	CDialog::OnLButtonUp(nFlags, point);
}
