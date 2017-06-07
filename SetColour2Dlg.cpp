// SetColour2Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "CGWORK0805.h"
#include "SetColour2Dlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSetColour2Dlg dialog


CSetColour2Dlg::CSetColour2Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetColour2Dlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetColour2Dlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSetColour2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetColour2Dlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetColour2Dlg, CDialog)
	//{{AFX_MSG_MAP(CSetColour2Dlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetColour2Dlg message handlers
