
// SmartChargingStationDlg.cpp : 實作檔
//

#include "stdafx.h"
#include "SmartChargingStation.h"
#include "SmartChargingStationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSmartChargingStationDlg 對話方塊



CSmartChargingStationDlg::CSmartChargingStationDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSmartChargingStationDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSmartChargingStationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EXPLORER1, m_WebBrowser);
}

BEGIN_MESSAGE_MAP(CSmartChargingStationDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CSmartChargingStationDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSmartChargingStationDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CSmartChargingStationDlg 訊息處理常式

BOOL CSmartChargingStationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 設定此對話方塊的圖示。當應用程式的主視窗不是對話方塊時，
	// 框架會自動從事此作業
	SetIcon(m_hIcon, TRUE);			// 設定大圖示
	SetIcon(m_hIcon, FALSE);		// 設定小圖示

	// TODO:  在此加入額外的初始設定
	CRect m_FullScreenRect;
	int nFullWidth = GetSystemMetrics(SM_CXSCREEN);
	int nFullHeight = GetSystemMetrics(SM_CYSCREEN);
	m_FullScreenRect.left = 0;
	m_FullScreenRect.top = 0;
	m_FullScreenRect.right = m_FullScreenRect.left + nFullWidth;
	m_FullScreenRect.bottom = m_FullScreenRect.top + nFullHeight;
	MoveWindow(0, 0, m_FullScreenRect.Width(), m_FullScreenRect.Height(), 1);

	::SetWindowPos(this->m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	ModifyStyle(WS_CAPTION, 0);

	m_WebBrowser.MoveWindow(0, 0, m_FullScreenRect.Width(), m_FullScreenRect.Height(), 1);

	//m_WebBrowser.Navigate(_T("http://140.92.142.101:8080/charging/authentication.jsp"),NULL,NULL,NULL,NULL);
	m_WebBrowser.Navigate(_T("http://localhost:8080/charging/authentication.jsp"), NULL, NULL, NULL, NULL);
	return TRUE;  // 傳回 TRUE，除非您對控制項設定焦點
}

// 如果將最小化按鈕加入您的對話方塊，您需要下列的程式碼，
// 以便繪製圖示。對於使用文件/檢視模式的 MFC 應用程式，
// 框架會自動完成此作業。

void CSmartChargingStationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 繪製的裝置內容

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 將圖示置中於用戶端矩形
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 描繪圖示
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 當使用者拖曳最小化視窗時，
// 系統呼叫這個功能取得游標顯示。
HCURSOR CSmartChargingStationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSmartChargingStationDlg::OnBnClickedOk()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CDialogEx::OnOK();
}


void CSmartChargingStationDlg::OnBnClickedCancel()
{
	// TODO:  在此加入控制項告知處理常式程式碼
	CDialogEx::OnCancel();
}


BOOL CSmartChargingStationDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此加入特定的程式碼和 (或) 呼叫基底類別
	if (pMsg->message == WM_KEYDOWN)
	{
//		CString strKey;
//		strKey.Format(_T("key:%d"), pMsg->wParam);
//		MessageBox(strKey);
		if (pMsg->wParam == VK_LWIN || pMsg->wParam == VK_RWIN)
		{
			MessageBox(_T("windows key"));
			pMsg->wParam = VK_NONAME;
			return TRUE;
		}
			
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
