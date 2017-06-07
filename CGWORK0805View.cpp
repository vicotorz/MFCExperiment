// CGWORK0805View.cpp : implementation of the CCGWORK0805View class
//
#include"HelpDlg.h"
#include "stdafx.h"
#include "CGWORK0805.h"
#include"math.h"
#include"iostream"
using namespace std;
#include "CGWORK0805Doc.h"
#include "CGWORK0805View.h"
#include"SetColourDlg.h"
#include"SetColour2Dlg.h"
#define PI 3.1415927
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0805View

IMPLEMENT_DYNCREATE(CCGWORK0805View, CView)

BEGIN_MESSAGE_MAP(CCGWORK0805View, CView)
	//{{AFX_MSG_MAP(CCGWORK0805View)
	ON_COMMAND(IDR_DRAWCUB, OnDrawcub)
	ON_COMMAND(IDR_DRAWCIRCLE, OnDrawcircle)
	ON_COMMAND(IDR_DRAWDBX, OnDrawdbx)
	ON_COMMAND(IDR_SETDATA, OnSetdata)
	ON_COMMAND(IDR_MOVEX, OnMovex)
	ON_COMMAND(IDR_MOVEY, OnMovey)
	ON_COMMAND(IDR_MOVEZ, OnMovez)
	ON_COMMAND(IDR_ANGLEX, OnAnglex)
	ON_COMMAND(IDR_ANGLEY, OnAngley)
	ON_COMMAND(IDR_ANGLEZ, OnAnglez)
	ON_COMMAND(IDR_BEZIER, OnBezier)
	ON_COMMAND(IDR_CHANGE, OnChange)
	ON_COMMAND(IDR_DRAWB, OnDrawb)
	ON_COMMAND(IDR_DRAWJX, OnDrawjx)
	ON_COMMAND(IDR_SETCOLOUR, OnSetcolour)
ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_KEYDOWN()
	ON_WM_CANCELMODE()
	ON_COMMAND(IDR_SETCOLOUR2, OnSetcolour2)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0805View construction/destruction
CCGWORK0805View::~CCGWORK0805View()
{
}
BOOL CCGWORK0805View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0805View drawing

void CCGWORK0805View::OnDraw(CDC* pDC)
{
	CCGWORK0805Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	m_Cursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
	CClientDC cDC(this);
	Drawinto();
}

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0805View printing

BOOL CCGWORK0805View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CCGWORK0805View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CCGWORK0805View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0805View diagnostics

#ifdef _DEBUG
void CCGWORK0805View::AssertValid() const
{
	CView::AssertValid();
}

void CCGWORK0805View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCGWORK0805Doc* CCGWORK0805View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCGWORK0805Doc)));
	return (CCGWORK0805Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCGWORK0805View message handlers
void CCGWORK0805View::Draw(CClientDC *pDC,int x1,int y1,int x2,int y2)//
{
	
	int x,y;
	if(x1>x2)
	{
		x=x1;
		x1=x2;
		x2=x;
	}
	if(y1>y2)
	{
		y=y1;
		y1=y2;
		y2=y;
	}
	for(int i=x1;i<=x2;i++)
		pDC->SetPixel(i,y1,RGB(m_R,m_G,m_B));
	for(int j=y1;j<=y2;j++)
		pDC->SetPixel(x1,j,RGB(m_R,m_G,m_B));
	for(int k=x1;k<=x2;k++)
		pDC->SetPixel(k,y2,RGB(m_R,m_G,m_B));
	for(int l=y1;l<=y2;l++)
		pDC->SetPixel(x2,l,RGB(m_R,m_G,m_B));
}

void CCGWORK0805View::OnLButtonDown(UINT nFlags, CPoint point) //OnButtonDowm函数
{
	// TODO: Add your message handler code here and/or call default
	if (m_isDraw)
	{	this->DrawLButtonDown(nFlags,point);
	}
	CView::OnLButtonDown(nFlags, point);
}

void CCGWORK0805View::OnMouseMove(UINT nFlags, CPoint point)//OnMouseMove函数
{
	// TODO: Add your message handler code here and/or call default
	if (m_isDraw){

	this->DrawMouseMove(nFlags,point);
	}

	CView::OnMouseMove(nFlags, point);
}

void CCGWORK0805View::OnLButtonUp(UINT nFlags, CPoint point) //OnLButtonUp函数
{
	// TODO: Add your message handler code here and/or call default
	if (m_isDraw){
		this->DrawLButtonUp(nFlags,point);
	}
	CView::OnLButtonUp(nFlags, point);
	
}

void CCGWORK0805View::DrawLButtonDown(UINT nFlags, CPoint point)//DrawLButtonDown函数
{	CClientDC dc(this);
	//dc.LineTo(point);
	if(m_DrawType==1||m_DrawType==2||m_DrawType==3||m_DrawType==10||m_DrawType==11)
		SetCursor(m_Cursor);//设置使用光标资源
	
	this->SetCapture();//捕捉鼠标

	
	m_LButtonDown = true;//设置鼠标左键按下
	if(m_DrawType==3)//画多边形
	{
		if(m_count>0)
			this->Drawline(&dc,m_StartPoint.x,m_StartPoint.y,point.x,point.y);
		polypoint[m_count].x=point.x;
		polypoint[m_count].y=point.y;
		m_count++;
	}
	//设置开始点和终止点，此时为同一点
	if(m_DrawType!=11||m_count==0)
	{	m_StartPoint = point;
		m_EndPoint = point;
	}

	if(m_DrawType==10)//Bezier曲线
	{
		polypoint[m_count].x=point.x;
		polypoint[m_count].y=point.y;
	//	if(m_count>=0)
			for(int i=polypoint[m_count].x-2;i<=polypoint[m_count].x+2;i++)
				for(int j=polypoint[m_count].y-2;j<=polypoint[m_count].y+2;j++)
					dc.SetPixel(i,j,RGB(0,0,0));
		pointcontrol[m_count]=point.y;
		m_count++;
	}
	if(m_DrawType==11)//B样条曲线
	{
		if(m_count<=1)
		{
			polypoint[m_count].x=point.x;
			polypoint[m_count].y=point.y;
		}
		m_StartPoint=m_EndPoint;
		if(m_count>1)
		{
			polypoint[m_count].x=polypoint[m_count-1].x+m_deltu;
			polypoint[m_count].y=point.y;
		}
			for(int i=polypoint[m_count].x-2;i<=polypoint[m_count].x+2;i++)
				for(int j=polypoint[m_count].y-2;j<=polypoint[m_count].y+2;j++)
					dc.SetPixel(i,j,RGB(0,0,0));
		pointcontrol[m_count]=point.y;
		m_count++;
	}

	if(m_DrawType==12)//修改曲线
	{	for(int k=0;k<=m_size;k++)
			if((polypoint[k].x-2<=point.x&&point.x<=polypoint[k].x+2)&&(polypoint[k].y-2<=point.y&&point.y<=polypoint[k].y+2))
				m_count=k;
		if(!((polypoint[m_count].x-2<=point.x&&point.x<=polypoint[m_count].x+2)&&(polypoint[m_count].y-2<=point.y&&point.y<=polypoint[m_count].y+2)))
			m_LButtonDown=false;
		else if(m_cline==1)
		{	m_StartPoint.x=polypoint[m_count].x;
			m_StartPoint.y=polypoint[m_count].y;
			m_EndPoint.x=polypoint[m_count].x;
			m_EndPoint.y=polypoint[m_count].y;
		}
		else if(m_cline==2)
		{
			m_StartPoint.x=polypoint[m_count].x;
			m_StartPoint.y=polypoint[m_count].y;
			m_EndPoint.x=polypoint[m_count].x;
			m_EndPoint.y=polypoint[m_count].y;
		}
	}
}

void CCGWORK0805View::DrawMouseMove(UINT nFlags, CPoint point)//DrawMouseMove函数，主要包含橡皮线的实现
{
	if(m_DrawType==1||m_DrawType==2||m_DrawType==3||m_DrawType==10||m_DrawType==11)//矩形，圆，多边形，Bizer，B调用
		SetCursor(m_Cursor);//设置使用光标资源
	CClientDC dc(this);//构造设备环境对象
	//判断鼠标移动的同时鼠标左键按下，并且要绘制的是直线段
	if (m_LButtonDown && m_DrawType == 1)//------------------------------------------------------直线橡皮线
	{
		dc.SetROP2(R2_NOT);//设置绘图模式为R2_NOT
		//重新绘制前一个鼠标移动消息处理函数绘制的直线段
		//因为绘图模式的原因，结果是擦除了该线段
		if(nFlags & MK_CONTROL)
		{
			this->Draw(&dc,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y);
		//绘制新的矩形

			this->Draw(&dc,m_StartPoint.x,m_StartPoint.y,point.x,m_StartPoint.y+(point.x-m_StartPoint.x));
		//保存新的直线段终点
		m_EndPoint.x= point.x;
		m_EndPoint.y=m_StartPoint.y+(point.x-m_StartPoint.x);
		}
		else
		{	this->Draw(&dc,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y);
		//绘制新的直线段

			this->Draw(&dc,m_StartPoint.x,m_StartPoint.y,point.x,point.y);
		//保存新的直线段终点
			m_EndPoint= point;
		}
		
	}
	if (m_LButtonDown && m_DrawType == 2)//---------------------------------------圆的橡皮现
	{
		int R1,R2,z1,z2;
		int a1,b1,a2,b2;
		z1=abs(m_StartPoint.x-m_EndPoint.x)>abs(m_StartPoint.y-m_EndPoint.y)?abs(m_StartPoint.x-m_EndPoint.x):abs(m_StartPoint.y-m_EndPoint.y);
		z2=abs(m_StartPoint.x-point.x)>abs(m_StartPoint.y-point.y)?abs(m_StartPoint.x-point.x):abs(m_StartPoint.y-point.y);
		R1=z1/2;
		R2=z2/2;
		a1=m_StartPoint.x+R1;
		b1=m_StartPoint.y+R1;
		a2=m_StartPoint.x+R2;
		b2=m_StartPoint.y+R2;
		dc.SetROP2(R2_NOT);
		this->Draw2(&dc,a1,b1,R1);
		this->Draw2(&dc,a2,b2,R2);
		m_EndPoint=point;
	}
	if(m_LButtonDown&&(m_DrawType==3||m_DrawType==10))//---------------------------------------------------多边形
	{	dc.SetROP2(R2_NOT);//设置绘图模式为R2_NOT
		//重新绘制前一个鼠标移动消息处理函数绘制的直线段
		//因为绘图模式的原因，结果是擦除了该线段
		this->Drawline(&dc,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y);
		this->Drawline(&dc,m_StartPoint.x,m_StartPoint.y,point.x,point.y);
		m_EndPoint=point;
	}
	if(m_LButtonDown&&m_DrawType==11)//--------------------------------------------------------------------B样条
	{
		dc.SetROP2(R2_NOT);
		if(m_count<=1)
		{	this->Drawline(&dc,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y);
			this->Drawline(&dc,m_StartPoint.x,m_StartPoint.y,point.x,point.y);
			m_EndPoint=point;
		}
		else if(m_count>1)
		{
			this->Drawline(&dc,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y);
			this->Drawline(&dc,m_StartPoint.x,m_StartPoint.y,m_StartPoint.x+m_deltu,point.y);
			m_EndPoint.x=m_StartPoint.x+m_deltu;
			m_EndPoint.y=point.y;
		}
	}
		

	if(m_LButtonDown&&(m_DrawType==12))//------------------------------------------------------------------修改曲线
	{
		dc.SetROP2(R2_NOT);
		for(int i=m_EndPoint.x-2;i<=m_EndPoint.x+2;i++)
			for(int j=m_EndPoint.y-2;j<=m_EndPoint.y+2;j++)
				dc.SetPixel(i,j,RGB(0,0,0));
		if(m_count>0)
			this->Drawline(&dc,polypoint[m_count-1].x,polypoint[m_count-1].y,m_EndPoint.x,m_EndPoint.y);
		if(m_count<m_size)
			this->Drawline(&dc,m_EndPoint.x,m_EndPoint.y,polypoint[m_count+1].x,polypoint[m_count+1].y);
		if(m_cline==1)
		{
			for(i=point.x-2;i<=point.x+2;i++)
				for(int j=point.y-2;j<=point.y+2;j++)
					dc.SetPixel(i,j,RGB(0,0,0));
			if(m_count>0)
				this->Drawline(&dc,polypoint[m_count-1].x,polypoint[m_count-1].y,point.x,point.y);
			if(m_count<m_size)
				this->Drawline(&dc,point.x,point.y,polypoint[m_count+1].x,polypoint[m_count+1].y);
			m_EndPoint.x=point.x;
			m_EndPoint.y=point.y;
		}
		else if(m_cline==2)
		{
			for(i=m_EndPoint.x-2;i<=m_EndPoint.x+2;i++)
				for(int j=point.y-2;j<=point.y+2;j++)
					dc.SetPixel(i,j,RGB(0,0,0));
			if(m_count>0)
				this->Drawline(&dc,polypoint[m_count-1].x,polypoint[m_count-1].y,m_EndPoint.x,point.y);
			if(m_count<m_size)
				this->Drawline(&dc,m_EndPoint.x,point.y,polypoint[m_count+1].x,polypoint[m_count+1].y);
			m_EndPoint.y=point.y;
		}
	}
}


void CCGWORK0805View::DrawLButtonUp(UINT nFlags, CPoint point)//DrawLButtonUp函数
{		
		if(m_DrawType==1||m_DrawType==2||m_DrawType==3||m_DrawType==10||m_DrawType==11)//矩形，圆，多边形，Bizer，B调用
			SetCursor(m_Cursor);//设置使用光标资源
		ReleaseCapture();//释放鼠标
		CClientDC dc(this);//构造设备环境对象
		CDC*cdc=GetDC();
		//绘制的是直线段
		if (m_isDraw==1&&m_DrawType == 1)//---------------------------------------------------------绘制直线段
		{

			//绘制最终要绘制的直线段
			this->Draw(&dc,m_StartPoint.x,m_StartPoint.y,m_EndPoint.x,m_EndPoint.y);
			m_LButtonDown=false;

		}
		if(m_isDraw==1&&m_DrawType==2)//-----------------------------------------------------------绘制圆形
		{
			int z1=abs(m_StartPoint.x-m_EndPoint.x)>abs(m_StartPoint.y-m_EndPoint.y)?abs(m_StartPoint.x-m_EndPoint.x):abs(m_StartPoint.y-m_EndPoint.y);
			int R1=z1/2;
			int a1=m_StartPoint.x+R1;
			int b1=m_StartPoint.y+R1;
			this->Draw2(&dc,a1,b1,R1);
			m_LButtonDown=false;
		}
		if(m_isDraw==1&&m_DrawType==10)//--------------------------------Bezier
		{

			if(m_count>3)
			{
				bez_to_points(3,20,pointcontrol,pointn);
				m_isDraw=0;
				m_LButtonDown=false;
				//cdc.LineTo(100,200);
				m_size=m_count-1;
				m_count=0;
				m_cline=1;
			}
			if(m_count>1)
				this->Drawline(cdc,m_StartPoint.x,m_StartPoint.y,point.x,point.y);

		}
		if(m_DrawType==11)//------------------------------------------B
		{
			if(m_count==2)
			{	m_deltu=polypoint[1].x-polypoint[0].x;
			}
		}
		if(m_DrawType==12)//-------------------------------------------修改
		{
			if(m_LButtonDown!=false)
			{	
				polypoint[m_count].x=m_EndPoint.x;
				polypoint[m_count].y=m_EndPoint.y;
				pointcontrol[m_count]=m_EndPoint.y;
			}
			m_R2=(m_R2+102)%255;
			m_G2=(m_R2+51)%255;
			m_B2=(m_R2+102)%255;
			if(m_cline==1)
				this->bez_to_points(3,20,pointcontrol,pointn);
			else if(m_cline==2)
				this->b_to_points(10,pointcontrol,m_size,pointn);
			m_LButtonDown=false;
			m_count=0;

		}

}

void CCGWORK0805View::OnDrawjx() //-----------------------------------------------1
{
	// TODO: Add your command handler code here
	m_isDraw=true;
	m_DrawType=1;
}

 void CCGWORK0805View::OnSetcolour() //设置颜色-----------------------------------矩形圆形
 {
  	//TODO: Add your command handler code here
	dlg1.DoModal();
	m_R=dlg1.m_R;
	m_G=dlg1.m_G;
	m_B=dlg1.m_B;
 }



void CCGWORK0805View::OnDrawcircle()//2代表画圆--------------------------------------------2 
{
	// TODO: Add your command handler code here
	m_isDraw=true;
	m_DrawType=2;
}

void CCGWORK0805View::Draw2(CClientDC * cd, int x, int y, int R)//DRaw2函数
{
	int deltax,deltay,d;
	int xx,yy;
	xx=0,yy=R,d=1-R;
	deltax=3;
	deltay=5-R-R;
	cd->SetPixel(xx+x,yy+y,RGB(m_R,m_G,m_B));
	cd->SetPixel(-xx+x,yy+y,RGB(m_R,m_G,m_B));
	cd->SetPixel(yy+x,-xx+y,RGB(m_R,m_G,m_B));
	cd->SetPixel(yy+x,xx+y,RGB(m_R,m_G,m_B));
	cd->SetPixel(xx+x,-yy+y,RGB(m_R,m_G,m_B));
	cd->SetPixel(-xx+x,-yy+y,RGB(m_R,m_G,m_B));
	cd->SetPixel(-yy+x,-xx+y,RGB(m_R,m_G,m_B));
	cd->SetPixel(-yy+x,xx+y,RGB(m_R,m_G,m_B));
	while(xx<yy)
	{
		if(d<0)
		{
			d+=deltax;
			deltax+=2;
			xx++;
		}
		else
		{
			d+=(deltax+deltay);
			deltax+=2;
			deltay+=2;
			xx++;
			yy--;
		}
		cd->SetPixel(xx+x,yy+y,RGB(m_R,m_G,m_B));
		cd->SetPixel(-xx+x,yy+y,RGB(m_R,m_G,m_B));
		cd->SetPixel(-yy+x,xx+y,RGB(m_R,m_G,m_B));
		cd->SetPixel(yy+x,xx+y,RGB(m_R,m_G,m_B));
		cd->SetPixel(xx+x,-yy+y,RGB(m_R,m_G,m_B));
		cd->SetPixel(-xx+x,-yy+y,RGB(m_R,m_G,m_B));
		cd->SetPixel(-yy+x,-xx+y,RGB(m_R,m_G,m_B));
		cd->SetPixel(yy+x,-xx+y,RGB(m_R,m_G,m_B));
	}
}

void CCGWORK0805View::Draw3(CClientDC *cd, int x1, int y1, int x2, int y2)//Draw3函数------------------扫描多边形
{
	const int POINTNUM=m_count;      //多边形点数.

//定义结构体
    typedef struct XET
    {
        float x;
        float dx,ymax;
        XET* next;
    }AET,NET;
//计算最高点的y坐标
    int MaxY=0;
    int i;
    for(i=0;i<POINTNUM;i++)
        if(polypoint[i].y>MaxY)
            MaxY=polypoint[i].y;
        
//初始化AET表
        AET *pAET=new AET;
        pAET->next=NULL;
        
//初始化NET表
        NET *pNET[1024];
        for(i=0;i<=MaxY;i++)
        {
            pNET[i]=new NET;
            pNET[i]->next=NULL;
        }
//扫描并建立NET表
        for(i=0;i<=MaxY;i++)
        {
            for(int j=0;j<POINTNUM;j++)
                if(polypoint[j].y==i)
                {                    
                    if(polypoint[(j-1+POINTNUM)%POINTNUM].y>polypoint[j].y)
                    {
                        NET *p=new NET;
                        p->x=polypoint[j].x;
                        p->ymax=polypoint[(j-1+POINTNUM)%POINTNUM].y;
                        p->dx=(polypoint[(j-1+POINTNUM)%POINTNUM].x-polypoint[j].x)/(polypoint[(j-1+POINTNUM)%POINTNUM].y-polypoint[j].y);
                        p->next=pNET[i]->next;
                        pNET[i]->next=p;
                        
                    }
                    if(polypoint[(j+1+POINTNUM)%POINTNUM].y>polypoint[j].y)
                    {
                        NET *p=new NET;                        
                        p->x=polypoint[j].x;
                        p->ymax=polypoint[(j+1+POINTNUM)%POINTNUM].y;
                        p->dx=(polypoint[(j+1+POINTNUM)%POINTNUM].x-polypoint[j].x)/(polypoint[(j+1+POINTNUM)%POINTNUM].y-polypoint[j].y);
                        p->next=pNET[i]->next;
                        pNET[i]->next=p;
                    }
                }
        }
//建立并更新活性边表AET

        for(i=0;i<=MaxY;i++)
        {

            NET *p=pAET->next;
            while(p)
            {
                p->x=p->x + p->dx;
                p=p->next;
            }
            AET *tq=pAET;
            p=pAET->next;
            tq->next=NULL;
			
            while(p)
            {
                while(tq->next && p->x >= tq->next->x)
                    tq=tq->next;
                NET *s=p->next;
                p->next=tq->next;
                tq->next=p;
                p=s;
                tq=pAET;
            }
			
    //从AET表中删除ymax==i的结点
            AET *q=pAET;
            p=q->next;
            while(p)
            {
                if(p->ymax==i)
                {
                    q->next=p->next;
                    delete p;
                    p=q->next;
                }
                else
                {
                    q=q->next;
                    p=q->next;
                }
            }
    //将NET中的新点加入AET,按x值递增顺序插入到表中
            p=pNET[i]->next;
            q=pAET;
            while(p)
            {
                while(q->next && p->x >= q->next->x)
                    q=q->next;
                NET *s=p->next;
                p->next=q->next;
                q->next=p;
                p=s;
                q=pAET;
            }
//配对填充颜色
            p=pAET->next;
			
            while(p && p->next)
            {
                for(float j=p->x;j<=p->next->x;j++)//判断像素点显示与否
					if(pattern[(int)j%m_width][i%m_height]==1)
							cd->SetPixel(j,i,RGB(m_R3,m_G3,m_B3));
                p=p->next->next;
            }    
        }
}

void CCGWORK0805View::OnSetcolour2() //设置颜色函数--------------------多边形
{
	// TODO: Add your command handler code here
//	CSetColour2Dlg dlg;
	dlg2.DoModal();
	m_R2=dlg2.m_R2;
	m_G2=dlg2.m_G2;
	m_B2=dlg2.m_B2;
	m_R3=dlg2.m_R3;
	m_G3=dlg2.m_G3;
	m_B3=dlg2.m_B3;
	
}

void CCGWORK0805View::OnDrawdbx() //3代表画多边形----------------------------------------3
{
	// TODO: Add your command handler code here
	m_DrawType=3;
	m_isDraw=1;
	
	
}

void CCGWORK0805View::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_isDraw){

		this->DrawLButtonDblClk(nFlags,point);
	}

	CView::OnLButtonDblClk(nFlags, point);
}

void CCGWORK0805View::DrawLButtonDblClk(UINT nFlags, CPoint point)
{

	CClientDC DC(this);
	if(m_DrawType==3)
	{
		this->Drawline(&DC,m_EndPoint.x,m_EndPoint.y,point.x,point.y);
		this->Drawline(&DC,point.x,point.y,polypoint[0].x,polypoint[0].y);
		m_LButtonDown=false;
		Draw3(&DC,0,0,0,0);
	}
	else if(m_DrawType==11)
	{
		m_LButtonDown=false;
		for(int i=polypoint[m_count-1].x-2;i<=polypoint[m_count-1].x+2;i++)
			for(int j=polypoint[m_count-1].y-2;j<=polypoint[m_count-1].y+2;j++)
				DC.SetPixel(i,j,RGB(0,0,0));
		pointcontrol[m_count]=point.y;
		DC.SetROP2(R2_WHITE);
		this->Drawline(&DC,polypoint[m_count-1].x+2,polypoint[m_count-1].y,polypoint[m_count-1].x+m_deltu,polypoint[m_count-1].y);
		b_to_points(10,pointcontrol,m_count-1,pointn);
		m_size=m_count-1;
		m_cline=2;
		m_isDraw=0;
	}
	m_count=0;

}

int** CCGWORK0805View::Drawinto()
{
CBitmap bmap;
	CDC*pDC1;
	pDC1=GetDC();
	CDC dcM;
	bmap.LoadBitmap(IDB_BITMAP1);
	BITMAP bmInfo;
	bmap.GetObject(sizeof(bmInfo),&bmInfo);
	dcM.CreateCompatibleDC(pDC1);
	dcM.SelectObject(&bmap);
	pDC1->BitBlt(0,0,bmInfo.bmWidth,bmInfo.bmHeight,&dcM,0,0,SRCCOPY);
	CPoint point;
	m_width=bmInfo.bmWidth;
	m_height=bmInfo.bmHeight;
	for(point.y=0;point.y<=bmInfo.bmHeight;point.y++)
		for(point.x=0;point.x<=bmInfo.bmWidth;point.x++)
		{	COLORREF color=pDC1->GetPixel(point);

			if(color!=RGB(255,255,255))
			{	pattern[point.x][point.y]=1;
				pDC1->SetPixel(point,RGB(255,255,255));
			}
			else
				pattern[point.x][point.y]=0;
		}

	ReleaseDC(pDC1);
	return pattern;	
}

void CCGWORK0805View::Drawline(CDC *dc,int x1, int y1, int x2, int y2)//画直线函数
{
	 double dx,dy,e,x,y;
	// CDC *cd=GetDC();
     dx=x2-x1;
     dy=y2-y1;
     e=(fabs(dx)>fabs(dy))?fabs(dx):fabs(dy);
     dx/=e;       
	 dy/=e;
     x=x1;         
	 y=y1;
     for(int i=1;i<=e;i++)
     {
        dc->SetPixel((int)(x+0.5), (int)(y+0.5),RGB(m_R2,m_G2,m_B2));
		x+=dx;     
		y+=dy;
	 }
}

void CCGWORK0805View::SetDp(CDC*dc,int x, int y, int z)
{

	int x0=200,y0=200,d=300;
	int x2,y2;
	x2=x0+d*(x-x0)/(z+d);
	y2=y0+d*(y-y0)/(z+d);
	dc->SetPixel(200+x2,200-y2,RGB(0,0,0));
}

void CCGWORK0805View::Drawcub(CDC*dc,int x0,int y0,int z0)//画立方体函数
{
	int s=100;
	int q=0;
	m_LastDp[q].x=x0,m_LastDp[q].y=y0+0,m_LastDp[q].z=z0+0;
	q++;
	m_LastDp[q].x=x0+s,m_LastDp[q].y=y0+0,m_LastDp[q].z=z0+0;
	q++;
	m_LastDp[q].x=x0+s,m_LastDp[q].y=y0+0,m_LastDp[q].z=z0+s;
	q++;
	m_LastDp[q].x=x0,m_LastDp[q].y=y0+0,m_LastDp[q].z=z0+s;
	q++;
	m_LastDp[q].x=x0,m_LastDp[q].y=y0+s,m_LastDp[q].z=z0+s;
	q++;
	m_LastDp[q].x=x0,m_LastDp[q].y=y0+s,m_LastDp[q].z=z0+0;
	q++;
	m_LastDp[q].x=x0+s,m_LastDp[q].y=y0+s,m_LastDp[q].z=z0+0;
	q++;
	m_LastDp[q].x=x0+s,m_LastDp[q].y=y0+s,m_LastDp[q].z=z0+s;
	this->Drawrecub(dc);
}

void CCGWORK0805View::OnDrawcub() 
{
	// TODO: Add your command handler code here
	CDC*dc=GetDC();
	dc->SetROP2(R2_WHITE);
	this->Drawrecub(dc);
	dc->SetROP2(R2_BLACK);		
	this->Drawcub(dc,0,0,0);
	m_isDraw=0;
}

void CCGWORK0805View::OnSetdata()//立方体设置数据
{
	// TODO: Add your command handler code here
	dlg3.DoModal();
	m_move=dlg3.m_move;
	m_angle=dlg3.m_angle*PI/180.00;	
}

void CCGWORK0805View::OnMovex() //延x轴移动------------------------------------------------4
{
	// TODO: Add your command handler code here
	m_isDraw=1;
	m_DrawType=4;	
}

void CCGWORK0805View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) //移动函数
{
	// TODO: Add your message handler code here and/or call default
	CDC*dc=GetDC();
	if(nChar=='A')
	{	m_Dest=1;
		if(m_isDraw==1)
		{
		
			dc->SetROP2(R2_WHITE);
			this->Drawrecub(dc);
			dc->SetROP2(R2_BLACK);	
			this->Drawanglecub(dc);
		}	
		
	}
	else if(nChar=='L')
	{	m_Dest=0;
		if(m_isDraw==1)
		{
			dc->SetROP2(R2_WHITE);
			this->Drawrecub(dc);//,m_LastDp.x,m_LastDp.y,m_LastDp.z);
			dc->SetROP2(R2_BLACK);
			this->Drawanglecub(dc);//,m_LastDp.x-m_move,m_LastDp.y,m_LastDp.z);
		}
		
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CCGWORK0805View::OnCancelMode() 
{
	CView::OnCancelMode();
	// TODO: Add your message handler code here
}



void CCGWORK0805View::OnMovey() //延y轴移动---------------------------------------------5
{
	// TODO: Add your command handler code here
	m_isDraw=1;
	m_DrawType=5;
}

void CCGWORK0805View::OnMovez() //延z轴移动---------------------------------------------6
{
	// TODO: Add your command handler code here
	m_isDraw=1;
	m_DrawType=6;
}

void CCGWORK0805View::OnAnglex()//绕x轴旋转 ---------------------------------------------7
{
	// TODO: Add your command handler code here
	m_isDraw=1;
	m_DrawType=7;
}

void CCGWORK0805View::Drawanglecub(CDC *dc)//
{
	int i,s=100;
	int x,y,z;
	if(m_DrawType==4&&m_Dest==1)
	{	for(i=0;i<=8;i++)
			m_LastDp[i].x+=m_move;
		this->Drawrecub(dc);	
	}
	else if(m_DrawType==4&&m_Dest==0)
	{	for(i=0;i<=8;i++)
			m_LastDp[i].x-=m_move;
		this->Drawrecub(dc);	
	}
	else if(m_DrawType==5&&m_Dest==1)
	{	for(i=0;i<=8;i++)
			m_LastDp[i].y+=m_move;
		this->Drawrecub(dc);	
	}
	else if(m_DrawType==5&&m_Dest==0)
	{	for(i=0;i<=8;i++)
			m_LastDp[i].y-=m_move;
		this->Drawrecub(dc);	
	}
	else if(m_DrawType==6&&m_Dest==1)
	{	for(i=0;i<=8;i++)
			m_LastDp[i].z+=m_move;
		this->Drawrecub(dc);	
	}
	else if(m_DrawType==6&&m_Dest==0)
	{	for(i=0;i<=8;i++)
			m_LastDp[i].z-=m_move;
		this->Drawrecub(dc);	
	}
	else if(m_DrawType==7&&m_Dest==1)
	{	m_angle=fabs(m_angle);
		for(i=0;i<8;i++)
		{	y=Caly7(m_LastDp[i].y,m_LastDp[i].z);
			z=Calz7(m_LastDp[i].y,m_LastDp[i].z);
			m_LastDp[i].y=y;
			m_LastDp[i].z=z;
			dc->MoveTo(0,0);
		}
		
		this->Drawrecub(dc);
	}
	else if(m_DrawType==7&&m_Dest==0)
	{	m_angle=-fabs(m_angle);
	
		for(i=0;i<8;i++)
		{	
			y=Caly7(m_LastDp[i].y,m_LastDp[i].z);
			z=Calz7(m_LastDp[i].y,m_LastDp[i].z);
			m_LastDp[i].y=y;
			m_LastDp[i].z=z;
		}
		this->Drawrecub(dc);
	}
	else if(m_DrawType==8&&m_Dest==1)
	{	m_angle=fabs(m_angle);
		for(i=0;i<8;i++)
		{	x=Calx8(m_LastDp[i].x,m_LastDp[i].z);
			z=Calz8(m_LastDp[i].x,m_LastDp[i].z);
			m_LastDp[i].x=x;
			m_LastDp[i].z=z;
		}
		this->Drawrecub(dc);
	}
	else if(m_DrawType==8&&m_Dest==0)
	{	m_angle=-fabs(m_angle);
		for(i=0;i<8;i++)
		{	x=Calx8(m_LastDp[i].x,m_LastDp[i].z);
			z=Calz8(m_LastDp[i].x,m_LastDp[i].z);
			m_LastDp[i].x=x;
			m_LastDp[i].z=z;
		}
		this->Drawrecub(dc);
	}
	else if(m_DrawType==9&&m_Dest==1)
	{	m_angle=fabs(m_angle);
		for(i=0;i<8;i++)
		{	x=Calx9(m_LastDp[i].x,m_LastDp[i].y);
			y=Caly9(m_LastDp[i].x,m_LastDp[i].y);
			m_LastDp[i].x=x;
			m_LastDp[i].y=y;
		}
		this->Drawrecub(dc);
	}
	else if(m_DrawType==9&&m_Dest==0)
	{	
		m_angle=-fabs(m_angle);
		for(i=0;i<8;i++)
		{	x=Calx9(m_LastDp[i].x,m_LastDp[i].y);
			y=Caly9(m_LastDp[i].x,m_LastDp[i].y);
			m_LastDp[i].x=x;
			m_LastDp[i].y=y;
		}
		this->Drawrecub(dc);
	}
}

int CCGWORK0805View::Caly7(int y, int z)
{
	float yy=y*cos(m_angle)+z*sin(m_angle);
	int yyy;
	yyy=yy>0?(int)(yy+0.5):(int)(yy-0.5);
	return yyy;
}

int CCGWORK0805View::Calz7(int y, int z)
{
	float zz=-y*sin(m_angle)+z*cos(m_angle);
	int zzz;
	zzz=zz>0?(int)(zz+0.5):(int)(zz-0.5);
	return zzz;
}

void CCGWORK0805View::Drawrecub(CDC *dc)
{
	for(int i=0;i<7;i++)
		this->DrawDLine(dc,m_LastDp[i].x,m_LastDp[i].y,m_LastDp[i].z,m_LastDp[i+1].x,m_LastDp[i+1].y,m_LastDp[i+1].z);
	for( i=0;i<3;i++)
		this->DrawDLine(dc,m_LastDp[i].x,m_LastDp[i].y,m_LastDp[i].z,m_LastDp[i+5].x,m_LastDp[i+5].y,m_LastDp[i+5].z);
	this->DrawDLine(dc,m_LastDp[4].x,m_LastDp[4].y,m_LastDp[4].z,m_LastDp[7].x,m_LastDp[7].y,m_LastDp[7].z);
	this->DrawDLine(dc,m_LastDp[0].x,m_LastDp[0].y,m_LastDp[0].z,m_LastDp[3].x,m_LastDp[3].y,m_LastDp[3].z);
}

void CCGWORK0805View::DrawDLine(CDC*dc,int x1, int y1, int z1, int x2, int y2, int z2)
{

	float x0=200,y0=200;
	float d=300.0;
	int xx1,xx2,yy1,yy2;

	xx1=int(x0+d*(x1-x0)/(z1+d)+0.5);
	yy1=int(y0+d*(y1-y0)/(z1+d)+0.5);
	xx2=int(x0+d*(x2-x0)/(z2+d)+0.5);
	yy2=int(y0+d*(y2-y0)/(z2+d)+0.5);

	this->Drawline(dc,200+xx1,200-yy1,200+xx2,200-yy2);

}

int CCGWORK0805View::Calx8(int x, int z)
{
	float xx=x*cos(m_angle)-z*sin(m_angle);
	int xxx;

	xxx=xx>0?(int)(xx+0.5):(int)(xx-0.5);
	return xxx;
}

int CCGWORK0805View::Calz8(int x, int z)
{
	float zz=x*sin(m_angle)+z*cos(m_angle);
	int zzz;
	zzz=zz>0?(int)(zz+0.5):(int)(zz-0.5);
	
	return zzz;
}

int CCGWORK0805View::Calx9(int x, int y)
{
	float xx=x*cos(m_angle)+y*sin(m_angle);
	int xxx;
	
	xxx=xx>0?(int)(xx+0.5):(int)(xx-0.5);
	return xxx;
}

int CCGWORK0805View::Caly9(int x, int y)
{
	float yy=-x*sin(m_angle)+y*cos(m_angle);
	int yyy;
	yyy=yy>0?(int)(yy+0.5):(int)(yy-0.5);
	return yyy;
}

void CCGWORK0805View::OnAngley()//绕y轴旋转---------------------------------8
{
	// TODO: Add your command handler code here
	m_isDraw=true;
	m_DrawType=8;
	
}

void CCGWORK0805View::OnAnglez() //绕z轴旋转---------------------------------9
{
	// TODO: Add your command handler code here
	m_isDraw=true;
	m_DrawType=9;
}

void CCGWORK0805View::bez_to_points(int degree, int npoints, double coeff[], double points[])
/*  degree:阶数;npoints+1:计算的曲线上的点的个数;coeff:控制点;points:曲线上的点   */
{   
	CDC*dc=GetDC();

	double t, delt;
    delt=1.0/(double)npoints;//将参数t   npoints等分
    t=0.0;
	for(int i=0;i<=npoints;i++)
	{   points[i]=decas(degree, coeff, t); //分别求出npoints+1个离散点points的坐标
		if(i!=0)
			this->Drawline(dc,polypoint[0].x+(polypoint[3].x-polypoint[0].x)*delt*i,points[i],polypoint[0].x+(polypoint[3].x-polypoint[0].x)*delt*(i-1),points[i-1]);
		//dc->SetPixel(coeff[0]+delt*i,points[i],RGB(255,0,0));
	    t+=delt;
	}
}

double CCGWORK0805View::decas(int degree, double coeff[], double t)
{
	int r,i;
    double *coeffa,coeffa0;
    coeffa = new double[degree +1];
    for(i=0;i<=degree;i++)
	   coeffa[i]= coeff[i]; 	 //将控制点坐标coeff[i]保存于coeffa[i]=中，需要作n次外方能产生最终Bezier曲线在点t的值
    for(r=1;r<=degree;r++)
	{ 
		for(i=0;i<= degree-r;i++) //n次Bezier曲线在点t的值，可由两条n-1次Bezier曲线在点t的值通过线性组合而求得
        {                          
			coeffa[i]= coeffa[i]+t*(coeffa[i+1]- coeffa[i]);                             
		}
    }
    coeffa0=coeffa[0];
    delete coeffa;
    return (coeffa0);
}

void CCGWORK0805View::OnBezier() //画Bezier曲线---------------------------------------10
{
	// TODO: Add your command handler code here
	m_isDraw=1;
	m_DrawType=10;
}

void CCGWORK0805View::OnChange()//修改曲线---------------------------------------------12
{
	// TODO: Add your command handler code here
	m_isDraw=1;
	m_DrawType=12;

	
}

void CCGWORK0805View::b_to_points(int npoints, double coeff[], int n, double points[])
{

	double yy,cp,lp=coeff[0];
	double cooff[25];
	cooff[0]=coeff[0]-(coeff[1]-coeff[0]);
	for(int i=1;i<=n+1;i++)
	{	cooff[i]=coeff[i-1];
	}
	cooff[n+2]=coeff[n]+(coeff[n]-coeff[n-1]);
	n=n+2;
	int d=npoints;
	double u=0,lx=polypoint[0].x+m_deltu*1.0/d;
	CDC* dc=GetDC();
	for(int j=0;j<=n-3;j++)
	{
		while(u<=1)
		{
			u+=1.0/d;
			yy=1.0/6*pow(u,3);
			cp=yy*cooff[j+3];
			yy=1.0/6*(-3*pow(u,3)+3*pow(u,2)+3*u+1);
			cp+=yy*cooff[j+2];
			yy=1.0/6*(3*pow(u,3)-6*pow(u,2)+4);
			cp+=yy*cooff[j+1];
			yy=1.0/6*pow(1-u,3);
			cp+=yy*cooff[j];
			if(!(j==0&&u==1.0/d))
			{
				this->Drawline(dc,lx,lp,polypoint[j].x+m_deltu*u,cp);
			}
			lp=cp;
			lx=polypoint[j].x+m_deltu*u;
		}
		u=0;
	}
}

void CCGWORK0805View::OnDrawb() //画B样条曲线-----------------------------------------------------------11
{
	// TODO: Add your command handler code here
	m_isDraw=1;
	m_DrawType=11;
	m_count=0;
	
}

void CCGWORK0805View::OnHelp() 
{
}
