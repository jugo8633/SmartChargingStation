
// SmartChargingStationDlg.h : ���Y��
//

#pragma once
#include "explorer1.h"


// CSmartChargingStationDlg ��ܤ��
class CSmartChargingStationDlg : public CDialogEx
{
// �غc
public:
	CSmartChargingStationDlg(CWnd* pParent = NULL);	// �зǫغc�禡

// ��ܤ�����
	enum { IDD = IDD_SMARTCHARGINGSTATION_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �䴩


// �{���X��@
protected:
	HICON m_hIcon;

	// ���ͪ��T�������禡
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
