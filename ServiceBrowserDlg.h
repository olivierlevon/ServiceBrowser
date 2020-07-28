//
// Copyright (c) 2011 Mark Nelson
//
// This software is licensed under the OSI MIT License, contained in
// the file license.txt included with this project.
//
// https://github.com/marknelson/ServiceBrowser
// https://marknelson.us/posts/2011/10/25/dns-service-discovery-on-windows.html

// Copyright (c) 2020 Olivier Levon
// https://github.com/olivierlevon/ServiceBrowser

//
// ServiceBrowserDlg.h : header file
//

#pragma once

#include "afxcmn.h"
#include <unordered_map>
#include <unordered_set>
#include <string>
#include "dns_sd.h"
#include "afxwin.h"


// CServiceBrowserDlg dialog
class CServiceBrowserDlg : public CDialogEx
{
// Construction
public:
	CServiceBrowserDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CServiceBrowserDlg();

// Dialog Data
	enum { IDD = IDD_SERVICEBROWSER_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	virtual void OnCancel();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
    static const int BROWSER_TIMER = 1001;
	CTreeCtrl m_Tree;
    CEdit m_Text;
	DNSServiceRef clientref = NULL;
	std::unordered_map<DNSServiceRef,SOCKET> m_ClientToFdMap;
    std::unordered_map<DNSServiceRef,HTREEITEM> m_TreeInsertionMap;
    std::unordered_set<std::string> m_ServiceTypes;
	//
	// DNS-SD browser items
	//
	void StartBrowser();
	void StopBrowser();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	static void DNSSD_API IterateServiceTypes( DNSServiceRef sdRef,
                                               DNSServiceFlags flags,
                                               uint32_t interfaceIndex,
											   DNSServiceErrorType errorCode,
                                               const char *serviceName,
                                               const char *regtype,
                                               const char *replyDomain,
                                               void *context );
	static void DNSSD_API IterateServiceInstances( DNSServiceRef sdRef,
                                                   DNSServiceFlags flags,
                                                   uint32_t interfaceIndex,
											       DNSServiceErrorType errorCode,
                                                   const char *serviceName,
                                                   const char *regtype,
                                                   const char *replyDomain,
                                                   void *context );
    static void DNSSD_API ResolveInstance(  DNSServiceRef sdRef,
                                            DNSServiceFlags flags,
                                            uint32_t interfaceIndex,
                                            DNSServiceErrorType errorCode,
                                            const char *fullname,
                                            const char *hosttarget,
                                            uint16_t port,
                                            uint16_t txtLen,
                                            const unsigned char *txtRecord,
                                            void *context );
    static void DNSSD_API GetAddress( DNSServiceRef sdRef,
                                      DNSServiceFlags flags,
                                      uint32_t interfaceIndex,
                                      DNSServiceErrorType errorCode,
                                      const char *hostname,
                                      const struct sockaddr *address,
                                      uint32_t ttl,
                                      void *context );
};
