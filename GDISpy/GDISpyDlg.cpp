
// GDISpyDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GDISpy.h"
#include "GDISpyDlg.h"
#include "afxdialogex.h"
#include "LibInject.h"
//#include "..\GDISpyhook\GDISpyhook.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGDISpyDlg dialog




CGDISpyDlg::CGDISpyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CGDISpyDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

CGDISpyDlg::~CGDISpyDlg()
{
}

void CGDISpyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGDISpyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CGDISpyDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON_START, &CGDISpyDlg::OnBnClickedButtonStart)
	ON_WM_COPYDATA()
	ON_BN_CLICKED(IDC_BUTTON_TSS, &CGDISpyDlg::OnBnClickedButtonTss)
	ON_BN_CLICKED(IDC_BUTTON_CAM, &CGDISpyDlg::OnBnClickedButtonCam)
END_MESSAGE_MAP()


// CGDISpyDlg message handlers

BOOL CGDISpyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	IDCUR[OBJ_BITMAP] = IDC_STATIC_BITMAP;
	IDCUR[OBJ_BRUSH] = IDC_STATIC_BRUSH;
	IDCUR[OBJ_DC] = IDC_STATIC_DC;
	IDCUR[OBJ_PEN] = IDC_STATIC_PEN;
	IDCUR[OBJ_MEMDC] = IDC_STATIC_MEMDC;
	IDCUR[OBJ_FONT] = IDC_STATIC_FONT;
	IDCUR[OBJ_REGION] = IDC_STATIC_REGION;
	IDCUR[OBJ_PAL] = IDC_STATIC_PALETTE;
	IDCUR[OBJ_METAFILE] = IDC_STATIC_METAFILE;
	IDCUR[OBJ_ENHMETAFILE] = IDC_STATIC_ENHMF;
	IDCUR[OBJ_METADC] = IDC_STATIC_MFDC;
	IDCUR[OBJ_ENHMETADC] = IDC_STATIC_ENHMFDC;

	IDNEW[OBJ_BITMAP] = IDC_STATIC_BITMAP2;
	IDNEW[OBJ_BRUSH] = IDC_STATIC_BRUSH2;
	IDNEW[OBJ_DC] = IDC_STATIC_DC2;
	IDNEW[OBJ_PEN] = IDC_STATIC_PEN2;
	IDNEW[OBJ_MEMDC] = IDC_STATIC_MEMDC2;
	IDNEW[OBJ_FONT] = IDC_STATIC_FONT2;
	IDNEW[OBJ_REGION] = IDC_STATIC_REGION2;
	IDNEW[OBJ_PAL] = IDC_STATIC_PALETTE2;
	IDNEW[OBJ_METAFILE] = IDC_STATIC_METAFILE2;
	IDNEW[OBJ_ENHMETAFILE] = IDC_STATIC_ENHMF2;
	IDNEW[OBJ_METADC] = IDC_STATIC_MFDC2;
	IDNEW[OBJ_ENHMETADC] = IDC_STATIC_ENHMFDC2;

	IDSAME[OBJ_BITMAP] = IDC_STATIC_BITMAP3;
	IDSAME[OBJ_BRUSH] = IDC_STATIC_BRUSH3;
	IDSAME[OBJ_DC] = IDC_STATIC_DC3;
	IDSAME[OBJ_PEN] = IDC_STATIC_PEN3;
	IDSAME[OBJ_MEMDC] = IDC_STATIC_MEMDC3;
	IDSAME[OBJ_FONT] = IDC_STATIC_FONT3;
	IDSAME[OBJ_REGION] = IDC_STATIC_REGION3;
	IDSAME[OBJ_PAL] = IDC_STATIC_PALETTE3;
	IDSAME[OBJ_METAFILE] = IDC_STATIC_METAFILE3;
	IDSAME[OBJ_ENHMETAFILE] = IDC_STATIC_ENHMF3;
	IDSAME[OBJ_METADC] = IDC_STATIC_MFDC3;
	IDSAME[OBJ_ENHMETADC] = IDC_STATIC_ENHMFDC3;

	IDFREE[OBJ_BITMAP] = IDC_STATIC_BITMAP4;
	IDFREE[OBJ_BRUSH] = IDC_STATIC_BRUSH4;
	IDFREE[OBJ_DC] = IDC_STATIC_DC4;
	IDFREE[OBJ_PEN] = IDC_STATIC_PEN4;
	IDFREE[OBJ_MEMDC] = IDC_STATIC_MEMDC4;
	IDFREE[OBJ_FONT] = IDC_STATIC_FONT4;
	IDFREE[OBJ_REGION] = IDC_STATIC_REGION4;
	IDFREE[OBJ_PAL] = IDC_STATIC_PALETTE4;
	IDFREE[OBJ_METAFILE] = IDC_STATIC_METAFILE4;
	IDFREE[OBJ_ENHMETAFILE] = IDC_STATIC_ENHMF4;
	IDFREE[OBJ_METADC] = IDC_STATIC_MFDC4;
	IDFREE[OBJ_ENHMETADC] = IDC_STATIC_ENHMFDC4;

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGDISpyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGDISpyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGDISpyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGDISpyDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnCancel();
}


void CGDISpyDlg::OnBnClickedButtonStart()
{
	TCHAR childProcess[100];
	GetDlgItemText(IDC_EDIT1, childProcess, 100);
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	if(!CreateProcess(NULL,   // No module name (use command line)
		childProcess,      // Command line
		NULL,           // Process handle not inheritable
		NULL,           // Thread handle not inheritable
		FALSE,          // Set handle inheritance to FALSE
		0,              // No creation flags
		NULL,           // Use parent's environment block
		NULL,           // Use parent's starting directory
		&si,            // Pointer to STARTUPINFO structure
		&pi )           // Pointer to PROCESS_INFORMATION structure
		)
	{
		MessageBox(NULL, L"CreateProcess failed.", MB_OK);
		return;
	}
	WaitForSingleObject(pi.hProcess, 0);
	/*DWORD pid;
	std::wstringstream wsstr;
	wsstr << childProcess;
	wsstr >> pid;*/
	//while(!(pid = FindProcessId(L"LootHoarder.exe", 3)));
	LPTSTR dir = new TCHAR[100];
	GetCurrentDirectory(100, dir);
	std::wstring lib = dir;
	lib += L"\\GDISpyhook.dll";
	if(!InjectLib(pi.dwProcessId, lib.c_str()))
	//if(!InjectLib(pid, L"E:\\Windows Via C-C++\\Debug\\22-ImgWalk.dll"))	
	{
		MessageBox(NULL, L"Injection failed.", MB_OK);
		return;
	}
	m_processId = pi.dwProcessId;
}


BOOL CGDISpyDlg::OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct)
{
	// TODO: Add your message handler code here and/or call default
	/*SetDlgItemText(IDC_STATIC_BITMAP, (LPCTSTR)pCopyDataStruct->lpData);*/
	return CDialogEx::OnCopyData(pWnd, pCopyDataStruct);
}

void CGDISpyDlg::Receive()
{
	if(OpenClipboard())
	{
		if(IsClipboardFormatAvailable(CF_TEXT))
		{
			HANDLE hClip;
			LPTSTR pBuf = NULL;
			hClip = GetClipboardData(CF_TEXT);
			pBuf = (LPTSTR)GlobalLock(hClip);
			std::wstringstream wsstr;
			wsstr << pBuf;
			PVOID handle;
			int type;
			for(int i = 1; i < 15; ++i) 
			{
				m_old_table[i] = m_handle_table[i];
				m_handle_table[i].clear();
			}
			while(wsstr >> handle >> type)
			{
				m_handle_table[type].insert(handle); 
			}
			GlobalUnlock(hClip);
		}
		CloseClipboard();
	}
}

void CGDISpyDlg::OnBnClickedButtonTss()
{
	//fnGDISpyhook();
	Receive();
	for(int i = 1; i < 15; ++i)
	{
		if(m_handle_table[i].empty())
			continue;
		std::wstringstream wsstr;
		std::wstring text;
		int n = m_handle_table[i].size();
		wsstr << n;
		wsstr >> text;
		GetDlgItem(IDCUR[i])->SetWindowTextW(text.c_str());
	}
}


void CGDISpyDlg::OnBnClickedButtonCam()
{	
	for(int i = 1; i < 15; ++i)
	{
		if(m_handle_table[i].empty())
			continue;
		int inew = 0, isame = 0, ifree = 0;
		for(std::set<PVOID>::iterator iter = m_handle_table[i].begin(); iter != m_handle_table[i].end(); ++iter) 
		{
			if(m_old_table[i].find(*iter) == m_old_table[i].end()) 
				++inew;
			else 
				++isame;
		}
		ifree = m_old_table[i].size() - isame;
		std::wstringstream wsstr;
		wsstr << inew;
		GetDlgItem(IDNEW[i])->SetWindowTextW(wsstr.str().c_str());
		wsstr.str(L"");
		wsstr << isame;
		GetDlgItem(IDSAME[i])->SetWindowTextW(wsstr.str().c_str());
		wsstr.str(L"");
		wsstr << ifree;
		GetDlgItem(IDFREE[i])->SetWindowTextW(wsstr.str().c_str());
	}
}
