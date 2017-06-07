#if !defined(AFX_SETCOLOURDLG_H__3929A9E5_97E7_4BE3_AF8B_B5FD5E49172B__INCLUDED_)
#define AFX_SETCOLOURDLG_H__3929A9E5_97E7_4BE3_AF8B_B5FD5E49172B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetColourDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetColourDlg dialog

class CSetColourDlg : public CDialog
{
// Construction
public:
	CSetColourDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetColourDlg)
	enum { IDD = IDD_SETCOLOUR };
	int		m_R;
	int		m_G;
	int		m_B;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetColourDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetColourDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETCOLOURDLG_H__3929A9E5_97E7_4BE3_AF8B_B5FD5E49172B__INCLUDED_)
