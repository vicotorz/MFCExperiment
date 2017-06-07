// SetDataDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CGWORK0805.h"
#include "SetDataDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetDataDlg dialog


CSetDataDlg::CSetDataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetDataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetDataDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSetDataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetDataDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetDataDlg, CDialog)
	//{{AFX_MSG_MAP(CSetDataDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetDataDlg message handlers
