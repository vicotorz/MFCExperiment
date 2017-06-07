// CGWORK0805View.h : interface of the CCGWORK0805View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CGWORK0805VIEW_H__6F677894_D181_415C_8931_D2214F56E94E__INCLUDED_)
#define AFX_CGWORK0805VIEW_H__6F677894_D181_415C_8931_D2214F56E94E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include"SetDataDlg.h"
#include"SetColour2Dlg.h"
#include"SetColourDlg.h"


class CCGWORK0805View : public CView
{
protected: // create from serialization only
	CCGWORK0805View(){
		m_LButtonDown = false;
		m_Cursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
		m_isDraw=false;
		m_R=0;
		m_G=0;
		m_B=0;
		m_R2=0;
		m_G2=0;
		m_B2=0;
		m_R3=0;
		m_G3=0;
		m_B3=0;
		m_move=1;
		m_angle=10.00/180*3.1415;
		m_count=0;
		m_width=100;
		m_height=100;
		pattern=new int*[m_width+3];
		for(int i=0;i<=m_width;i++)
			pattern[i]=new int[m_height+3];
	}
	DECLARE_DYNCREATE(CCGWORK0805View)

// Attributes
public:
	CCGWORK0805Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCGWORK0805View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	int m_cline;
	int m_deltu;
	void b_to_points(int npoints,double coeff[],int n,double points[]);
	double decas(int degree,double coeff[],double t);
	void bez_to_points(int degree, int npoints, double coeff[], double points[]);
	int Caly9(int x,int y);
	int Calx9(int x,int y);
	int Calz8(int x,int z);
	int Calx8(int x,int z);
	int m_Dest;
	void Drawrecub(CDC*dc);
	
	int Calz7(int y,int z);
	int Caly7(int y,int z);
	void Drawanglecub(CDC*dc);

	double m_angle;
	int m_move;
	void Drawcub(CDC*dc,int x0,int y0,int z0);
	void SetDp(CDC *dc,int x,int y,int z);
	int** pattern;
	int m_height;
	int m_width;
	int **Drawinto();
	CPoint m_pointitem;
	int m_count;
	void DrawLButtonDblClk(UINT nFlags,CPoint point);
	int m_B3;
	int m_G3;
	int m_R3;
	int m_B2;
	int m_G2;
	int m_R2;
	void Draw3(CClientDC*cd,int x1,int y1,int x2,int y2);
	void Draw2(CClientDC *cd,int x,int y,int R);
	int m_B;
	int m_G;
	int m_R;
	int m_size;
	double pointn[200];
	double pointcontrol[5];
	CSetDataDlg dlg3;
	CSetColour2Dlg dlg2;
	CSetColourDlg dlg1;
	void DrawDLine(CDC*dc,int x1,int y1,int z1,int x2,int y2,int z2);
	struct point
    {
        float x;
        float y;


    }polypoint[20];
	struct Dpoint
	{
		int x;
		int y;
		int z;
	}m_LastDp[10];
	void Drawline(CDC *dc,int x1,int y1,int x2,int y2);
	void DrawLButtonUp(UINT nFlags, CPoint point);
	void DrawMouseMove(UINT nFlags, CPoint point);
	void DrawLButtonDown(UINT nFlags, CPoint point);
	bool m_isDraw;
	int m_DrawType;
	bool m_LButtonDown;
	CPoint m_EndPoint;
	CPoint m_StartPoint;
	HCURSOR m_Cursor;
	void Draw(CClientDC*pDC,int x1,int y1,int x2,int y2);

    void OnLButtonDown(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnLButtonDblClk(UINT nFlags, CPoint point);
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void OnCancelMode();
	void OnHelp();
	virtual ~CCGWORK0805View();


#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCGWORK0805View)
	afx_msg void OnDrawcub();
	afx_msg void OnDrawcircle();
	afx_msg void OnDrawdbx();
	afx_msg void OnSetdata();
	afx_msg void OnMovex();
	afx_msg void OnMovey();
	afx_msg void OnMovez();
	afx_msg void OnAnglex();
	afx_msg void OnAngley();
	afx_msg void OnAnglez();
	afx_msg void OnBezier();
	afx_msg void OnChange();
	afx_msg void OnDrawb();
	afx_msg void OnDrawjx();
	afx_msg void OnSetcolour();
	afx_msg void OnSetcolour2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CGWORK0805View.cpp
inline CCGWORK0805Doc* CCGWORK0805View::GetDocument()
   { return (CCGWORK0805Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGWORK0805VIEW_H__6F677894_D181_415C_8931_D2214F56E94E__INCLUDED_)
