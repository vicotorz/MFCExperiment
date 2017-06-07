// CGWORK0805Doc.h : interface of the CCGWORK0805Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CGWORK0805DOC_H__E22C49F0_EA6E_499B_B897_602763F42068__INCLUDED_)
#define AFX_CGWORK0805DOC_H__E22C49F0_EA6E_499B_B897_602763F42068__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCGWORK0805Doc : public CDocument
{
protected: // create from serialization only
	CCGWORK0805Doc();
	DECLARE_DYNCREATE(CCGWORK0805Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGWORK0805Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCGWORK0805Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCGWORK0805Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGWORK0805DOC_H__E22C49F0_EA6E_499B_B897_602763F42068__INCLUDED_)
