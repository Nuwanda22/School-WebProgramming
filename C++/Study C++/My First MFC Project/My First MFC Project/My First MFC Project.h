
// My First MFC Project.h : My First MFC Project ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMyFirstMFCProjectApp:
// �� Ŭ������ ������ ���ؼ��� My First MFC Project.cpp�� �����Ͻʽÿ�.
//

class CMyFirstMFCProjectApp : public CWinAppEx
{
public:
	CMyFirstMFCProjectApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// �����Դϴ�.
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMyFirstMFCProjectApp theApp;
