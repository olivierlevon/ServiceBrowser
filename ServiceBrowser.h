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
// ServiceBrowser.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CServiceBrowserApp:
// See ServiceBrowser.cpp for the implementation of this class
//

class CServiceBrowserApp : public CWinApp
{
public:
	CServiceBrowserApp();
	virtual ~CServiceBrowserApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CServiceBrowserApp theApp;