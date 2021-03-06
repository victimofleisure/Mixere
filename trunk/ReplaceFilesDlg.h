// Copyleft 2004 Chris Korda
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or any later version.
/*
        chris korda
 
		revision history:
		rev		date	comments
        00      21nov03 initial version

        replace files dialog
 
*/

#if !defined(AFX_REPLACEFILESDLG_H__720FB107_3B4A_4119_9E1C_0DF38BA9D53E__INCLUDED_)
#define AFX_REPLACEFILESDLG_H__720FB107_3B4A_4119_9E1C_0DF38BA9D53E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReplaceFilesDlg.h : header file
//

#include <afxtempl.h>
#include "FileSearchDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CReplaceFilesDlg dialog

class CReplaceFilesDlg : public CDialog
{
public:
// Construction
	CReplaceFilesDlg(CStringArray& Path, LPCSTR Filter, CWnd* pParent = NULL);

// Operations
	bool	Search();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReplaceFilesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:
// Dialog data
	//{{AFX_DATA(CReplaceFilesDlg)
	enum { IDD = IDD_REPLACE_FILES_DLG };
	CListCtrl	m_List;
	//}}AFX_DATA

// Generated message map functions
	//{{AFX_MSG(CReplaceFilesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnBrowse();
	afx_msg void OnSearchAll();
	afx_msg void OnSearchFolder();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Nested classes
	class CMissing {
	public:
		CMissing(LPCSTR FileName, int Item, int Chan);
		CMissing();
		CMissing(const CMissing& Missing);
		CString	m_FileName;
		int		m_Item;
		int		m_Chan;
	};
	class CMyFileSearchDlg : public CFileSearchDlg {
	public:
		CMyFileSearchDlg(LPCSTR Folder, CReplaceFilesDlg *rfd);
		bool	OnFile(LPCSTR Path);
	private:
		CReplaceFilesDlg *m_rfd;
	};

// Member data
	CArray<CMissing, CMissing&>	m_Missing;
	CStringArray& m_Path;
	CString	m_Folder;
	LPCSTR	m_Filter;

// Helpers
	bool	Search(LPCSTR Folder);
	void	InitMissing();
	bool	OnFile(LPCSTR Path);

// Friends
	friend	CMyFileSearchDlg;
	NOCOPIES(CReplaceFilesDlg);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REPLACEFILESDLG_H__720FB107_3B4A_4119_9E1C_0DF38BA9D53E__INCLUDED_)
