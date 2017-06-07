// SetColourDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CGWORK0805.h"
#include "SetColourDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetColourDlg dialog


CSetColourDlg::CSetColourDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetColourDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetColourDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSetColourDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetColourDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetColourDlg, CDialog)
	//{{AFX_MSG_MAP(CSetColourDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetColourDlg message handlers
