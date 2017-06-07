// CGWORK0805Doc.cpp : implementation of the CCGWORK0805Doc class
//

#include "stdafx.h"
#include "CGWORK0805.h"

#include "CGWORK0805Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0805Doc

IMPLEMENT_DYNCREATE(CCGWORK0805Doc, CDocument)

BEGIN_MESSAGE_MAP(CCGWORK0805Doc, CDocument)
	//{{AFX_MSG_MAP(CCGWORK0805Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0805Doc construction/destruction

CCGWORK0805Doc::CCGWORK0805Doc()
{
	// TODO: add one-time construction code here

}

CCGWORK0805Doc::~CCGWORK0805Doc()
{
}

BOOL CCGWORK0805Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CCGWORK0805Doc serialization

void CCGWORK0805Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0805Doc diagnostics

#ifdef _DEBUG
void CCGWORK0805Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCGWORK0805Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0805Doc commands
