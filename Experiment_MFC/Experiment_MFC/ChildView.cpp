
// ChildView.cpp : реализация класса CChildView
//

#include "stdafx.h"
#include "Experiment_MFC.h"
#include "ChildView.h"
#include "Figure.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

//CChildView::CChildView():m_Circle(100, 100, 100){ } 

CChildView::CChildView():figure(200, 50, 50, 50, 350, 350, PI){ }

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
//	ON_WM_LBUTTONUP()
ON_WM_LBUTTONDOWN()
ON_WM_LBUTTONUP()
ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// обработчики сообщений CChildView

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // контекст устройства для рисования
	
	// TODO: Добавьте код обработки сообщений
	
	// Не вызывайте CWnd::OnPaint() для сообщений рисования
	//dc.SetMapMode(MM_LOENGLISH);
	
	//CCircle circle(200, 200, 100);
	//circle.Draw(dc); 
	//m_Circle.Draw(dc); 
	figure.Draw(dc);
}



//void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
//{
//	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
//
//	CWnd::OnLButtonUp(nFlags, point);
//}


void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
//	if(m_Circle.IsInside(point.x, point.y))

	double x_mouse = point.x*cos(figure.m_dAngle) + point.y*sin(figure.m_dAngle); //такие знаки, потому что поворот по часовой стрелке
	double y_mouse = point.x*sin(figure.m_dAngle) - point.y*cos(figure.m_dAngle);
	point.x = x_mouse;
	point.y = y_mouse;
	if(figure.IsInside(point.x, point.y))
	{
		m_bCatched = true;
		m_MousePos = point;
		SetCapture();  
	}
	CWnd::OnLButtonDown(nFlags, point);
}


void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	double x_mouse = point.x*cos(figure.m_dAngle) + point.y*sin(figure.m_dAngle); 
	double y_mouse = point.x*sin(figure.m_dAngle) - point.y*cos(figure.m_dAngle);
	point.x = x_mouse;
	point.y = y_mouse;
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	m_bCatched = false;
	ReleaseCapture();
	CWnd::OnLButtonUp(nFlags, point);
}


void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	if(m_bCatched)
	{
		double x_mouse = point.x*cos(figure.m_dAngle) + point.y*sin(figure.m_dAngle); 
		double y_mouse = point.x*sin(figure.m_dAngle) - point.y*cos(figure.m_dAngle);
		point.x = x_mouse;
		point.y = y_mouse;
		CRect rect;
		GetClientRect(&rect);
		point.x = min(rect.right, max(rect.left, point.x));
		point.y = min(rect.bottom, max(rect.top, point.y)); 
		CPoint Delta = point - m_MousePos;
//		m_Circle.Move(Delta.x, Delta.y);
		figure.Move(Delta.x, Delta.y);
		m_MousePos = point;
		Invalidate();
	}  
	CWnd::OnMouseMove(nFlags, point);
}
