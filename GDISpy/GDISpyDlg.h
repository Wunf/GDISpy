
// GDISpyDlg.h : header file
//

#pragma once


// CGDISpyDlg dialog
class CGDISpyDlg : public CDialogEx
{
// Construction
public:
	CGDISpyDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CGDISpyDlg();
// Dialog Data
	enum { IDD = IDD_GDISPY_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonStart();
	afx_msg BOOL OnCopyData(CWnd* pWnd, COPYDATASTRUCT* pCopyDataStruct);

private:
	LPTSTR m_data;
	static const int max_datal = 100; 

	void Receive();
};
