
// SmartChargingStationDlg.h : 標頭檔
//

#pragma once
#include "explorer1.h"


// CSmartChargingStationDlg 對話方塊
class CSmartChargingStationDlg : public CDialogEx
{
// 建構
public:
	CSmartChargingStationDlg(CWnd* pParent = NULL);	// 標準建構函式

// 對話方塊資料
	enum { IDD = IDD_SMARTCHARGINGSTATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支援


// 程式碼實作
protected:
	HICON m_hIcon;

	// 產生的訊息對應函式
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
private:
	CExplorer1 m_WebBrowser;
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
