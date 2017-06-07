#if !defined(AFX_SETDATADLG_H__12CEE03B_DDF5_44CB_B00E_A4FF3D456D68__INCLUDED_)
#define AFX_SETDATADLG_H__12CEE03B_DDF5_44CB_B00E_A4FF3D456D68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetDataDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetDataDlg dialog

class CSetDataDlg : public CDialog
{
// Construction
public:
	CSetDataDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetDataDlg)
	enum { IDD = IDD_SETCUB };
	int		m_move;
	float	m_angle;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetDataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetDataDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETDATADLG_H__12CEE03B_DDF5_44CB_B00E_A4FF3D456D68__INCLUDED_)
