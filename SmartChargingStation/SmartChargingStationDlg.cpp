
// SmartChargingStationDlg.cpp : ��@��
//

#include "stdafx.h"
#include "SmartChargingStation.h"
#include "SmartChargingStationDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSmartChargingStationDlg ��ܤ��



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


// CSmartChargingStationDlg �T���B�z�`��

BOOL CSmartChargingStationDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �]�w����ܤ�����ϥܡC�����ε{�����D�������O��ܤ���ɡA
	// �ج[�|�۰ʱq�Ʀ��@�~
	SetIcon(m_hIcon, TRUE);			// �]�w�j�ϥ�
	SetIcon(m_hIcon, FALSE);		// �]�w�p�ϥ�

	// TODO:  �b���[�J�B�~����l�]�w
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
	return TRUE;  // �Ǧ^ TRUE�A���D�z�ﱱ��]�w�J�I
}

// �p�G�N�̤p�ƫ��s�[�J�z����ܤ���A�z�ݭn�U�C���{���X�A
// �H�Kø�s�ϥܡC���ϥΤ��/�˵��Ҧ��� MFC ���ε{���A
// �ج[�|�۰ʧ������@�~�C

void CSmartChargingStationDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ø�s���˸m���e

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N�ϥܸm����Τ�ݯx��
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �yø�ϥ�
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ��ϥΪ̩즲�̤p�Ƶ����ɡA
// �t�ΩI�s�o�ӥ\����o�����ܡC
HCURSOR CSmartChargingStationDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSmartChargingStationDlg::OnBnClickedOk()
{
	// TODO:  �b���[�J����i���B�z�`���{���X
	CDialogEx::OnOK();
}


void CSmartChargingStationDlg::OnBnClickedCancel()
{
	// TODO:  �b���[�J����i���B�z�`���{���X
	CDialogEx::OnCancel();
}


BOOL CSmartChargingStationDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  �b���[�J�S�w���{���X�M (��) �I�s�����O
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
