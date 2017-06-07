#if !defined(AFX_SETCOLOUR2DLG_H__9C5A5376_21F4_462C_9547_7FB2963E057A__INCLUDED_)
#define AFX_SETCOLOUR2DLG_H__9C5A5376_21F4_462C_9547_7FB2963E057A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SetColour2Dlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSetColour2Dlg dialog

class CSetColour2Dlg : public CDialog
{
// Construction
public:
	CSetColour2Dlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetColour2Dlg)
		//{{AFX_DATA(CSetColour2Dlg)
	enum { IDD = IDD_SETCOLOUR2 };
	int		m_R2;
	int		m_R3;
	int		m_G2;
	int		m_G3;
	int		m_B2;
	int		m_B3;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetColour2Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetColour2Dlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETCOLOUR2DLG_H__9C5A5376_21F4_462C_9547_7FB2963E057A__INCLUDED_)
