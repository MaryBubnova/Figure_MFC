#include "stdafx.h"
/*#include "Figure.h"


CFigure::CFigure(void)
{
}


CFigure::~CFigure(void)
{
}
*/
// #define PI

#include "StdAfx.h"
#include "Figure.h" 
#include <math.h>


 /*
CCircle::CCircle(double x, double y, double R)
{
	m_dCenterX = x;
	m_dCenterY= y;
	m_dRadius = R;
}
CCircle::~CCircle(void)
{
}

bool CCircle::IsInside(double x, double y)
	{
		return  (x - m_dCenterX)*(x - m_dCenterX) + (y - m_dCenterY)*(y - m_dCenterY) < m_dRadius*m_dRadius;
	}

void CCircle::Move(double dx, double dy)
	{
		m_dCenterX += dx;
		m_dCenterY += dy;
	}   

void CCircle::Draw(CDC &dc)
{
	
	dc.Ellipse(m_dCenterX-m_dRadius, m_dCenterY-m_dRadius, m_dCenterX+m_dRadius, m_dCenterX+m_dRadius);
}; 

#include "head.h"
 */


CMy2DPoint::CMy2DPoint() {}
CMy2DPoint::~CMy2DPoint() {}


CMy2DPoint CMy2DPoint::operator +(const CMy2DPoint& vector) {
	return CMy2DPoint(vector.m_x + m_x, vector.m_y + m_y);
}

CMy2DPoint CMy2DPoint::operator -(const CMy2DPoint& vector) {
	return CMy2DPoint(m_x - vector.m_x, m_y - vector.m_y);
}

double CMy2DPoint::operator *(const CMy2DPoint& vector) {
	return m_x*vector.m_x + m_y*vector.m_y;
}

CMy2DPoint CMy2DPoint::operator *(double v) {
	return CMy2DPoint(v*m_x, v*m_y);
}

CMy2DPoint CMy2DPoint::operator /(double v) {
	return CMy2DPoint(m_x / v, m_y / v);
}

bool CMy2DPoint::operator ==(const CMy2DPoint& vector) {
	return (m_x == vector.m_x && m_y == vector.m_y);
}

bool CMy2DPoint::operator !=(const CMy2DPoint& vector) {
	return (m_x != vector.m_x || m_y != vector.m_y);
}

CMy2DPoint operator *(double v, const CMy2DPoint& vector) {
	return CMy2DPoint(v*vector.m_x, v*vector.m_y);
}

ostream& operator <<(ostream& out, const CMy2DPoint& vector) {
	out << "(" << vector.m_x << " " << vector.m_y << ")";
	return out;
}

istream& operator >>(istream& in, CMy2DPoint& vector) {
	in >> vector.m_x;
	in >> vector.m_y;
	return in;
}



CMy2DObjectA4::CMy2DObjectA4() {}
CMy2DObjectA4::CMy2DObjectA4(double a, double a1, double a2, double a3, double x, double y, double ang) : A(abs(a)), A1(abs(a1)), A2(abs(a2)), A3(abs(a3)), m_centre(x, y), m_dAngle(ang) {
	//Set();
	SetA(a);
	SetA1(a1);
	SetA2(a2);
	SetA3(a3);
	SetCentre(x, y);
	SetDAngle(ang);

}
CMy2DObjectA4::~CMy2DObjectA4() {}


double CMy2DObjectA4::GetA() { //методы, возвращающие ј, ј1, ј2 и ј3
	return A;
}
double CMy2DObjectA4::GetA1() {
	return A1;
}
double CMy2DObjectA4::GetA2() {
	return A2;
}
double CMy2DObjectA4::GetA3() {
	return A3;
}

CMy2DPoint CMy2DObjectA4::GetCentre() { //метод, возвращающий координаты центра
	return m_centre;
}

double CMy2DObjectA4::GetAngle() { //метод, возвращающий угол поворота
	return m_dAngle;
}

//проверка корректности данных

void CMy2DObjectA4::Set() {

	// дл€ угла поворота
	while (m_dAngle > 2 * PI) {  
		m_dAngle -= 2 * PI;
	}
	while (m_dAngle < 0) {
		m_dAngle += 2 * PI;
	}

	while (1) {
		if (A1 > A) { //если круг ј1 слишком большой
			cout << "‘игура ";
			cout << *this;
			cout << " не может быть построена" << endl;
			cout << "—делайте A1 меньше" << endl;
			cout << "A1 = ";
			cin >> A1;
			cout << endl;
			continue;
		}
		if (A2 > A*(2*0.5)) {  //если круг ј2 слишком большой
			cout << "‘игура ";
			cout << *this;
			cout << " не может быть построена" << endl;
			cout << "—делайте ј2 меньше" << endl;
			cout << "A2 = ";
			cin >> A2;
			cout << endl;
			continue;
		}
		if (A3 > A) {  //если квадрат ј3 слишком большой
			cout << "‘игура ";
			cout << *this;
			cout << " не может быть построена" << endl;
			cout << "—делайте A3 меньше" << endl;
			cout << "A3 = ";
			cin >> A3;
			cout << endl;
			continue;
		}
		if ((A1 + A2) > A) {  //круги ј1 и ј2 пересекаютс€
			cout << "‘игура ";
			cout << *this;
			cout << " имеет самопересечение" << endl;
			cout << "—делайте A2 или A1 меньше" << endl;
			cout << "A1 = ";
			cin >> A1;
			cout << "A2 = ";
			cin >> A2;
			cout << endl;
			continue;
		}
		if (A1*A1 > ((A-A3)*(A-A3)) +(A1/2-A3)*(A1/2-A3)) {  //круг ј1 и квадрат ј3 пересекаютс€
			cout << "‘игура ";
			cout << *this;
			cout << " имеет самопересечение" << endl;
			cout << "—делайте A3 или A1 меньше" << endl;
			cout << "A1 = ";
			cin >> A1;
			cout << "A3 = ";
			cin >> A3;
			cout << endl;
			continue;
		}
		if ((A2 + A3) > A) {  //круг ј2 и квадрат ј3 пересекаютс€
			cout << "‘игура ";
			cout << *this;
			cout << " имеет само-пересечение" << endl;
			cout << "—делайте A3 или A2 меньше" << endl;
			cout << "A2 = ";
			cin >> A2;
			cout << "A3 = ";
			cin >> A3;
			cout << endl;
			continue;
		}
		break;
	}
}


void CMy2DObjectA4::SetA(double a) {
	if ((A2 + A3) < A) 
	{
		if ((A1 + A3) < A)
		{
			if ((A1 + A2) < 1.25*pow(a, 2))
			{
				A = a;
			}
			else
				cout << "(A1 + A2) < 1.25*A^2 не соблюдаетс€" << endl;
		}
		else
			cout << "(A1 + A3) < A не соблюдаетс€" << endl;
	}
	else
		cout << "(A2 + A3) < A не соблюдаетс€" << endl;
}

void CMy2DObjectA4::SetA1(double a1) {

	if ((a1 + A3) < A) 
	{
		if ((a1 + A3) < A)
		{
			if ((a1 + A2) < 1.25*pow(A, 2))
			{
				A1 = a1;
			}
			else
				cout << "(A1 + A2) < 1.25*A^2 не соблюдаетс€" << endl;
		}
		else
			cout << "(A1 + A3) < A не соблюдаетс€" << endl;
	}
	else
		cout << "(A2 + A3) < A не соблюдаетс€" << endl;
}

void CMy2DObjectA4::SetA2(double a2) {

	if ((a2 + A3) < A) 
	{
		if ((A1 + A3) < A)
		{
			if ((A1 + a2) < 1.25*pow(A, 2))
			{
				A2 = a2;
			}
			else
				cout << "(A1 + A2) < 1.25*A^2 не соблюдаетс€" << endl;
		}
		else
			cout << "(A1 + A3) < A не соблюдаетс€" << endl;
	}
	else
		cout << "(A2 + A3) < A не соблюдаетс€" << endl;
}

void CMy2DObjectA4::SetA3(double a3) {

	if ((A2 + a3) < A) 
	{
		if ((A1 + a3) < A)
		{
			if ((A1 + A2) < 1.25*pow(A, 2))
			{
				A3 = a3;
			}
			else
				cout << "(A1 + A2) < 1.25*A^2 не соблюдаетс€" << endl;
		}
		else
			cout << "(A1 + A3) < A не соблюдаетс€" << endl;
	}
	else
		cout << "(A2 + A3) < A не соблюдаетс€" << endl;
}


void CMy2DObjectA4::SetCentre(const CMy2DPoint& centre)  {
	m_centre = centre;
}

void CMy2DObjectA4::SetCentre(double x, double y)  {
	m_centre.m_x = x;
	m_centre.m_y = y;
}

void CMy2DObjectA4::SetDAngle(double dAngle){
	m_dAngle = dAngle;
}

void CMy2DObjectA4::Rotate(double dAngle) { //метод поворота фигуры на угол
	m_dAngle += dAngle;
	while (m_dAngle > 2 * PI) {  
		m_dAngle -= 2 * PI;
	}
	while (m_dAngle < 0) {
		m_dAngle += 2 * PI;
	}
}

void CMy2DObjectA4::Move(double dX, double dY, double dAngle) { //2 метода смещени€ объекта с разными аргументами     //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	m_centre.m_x += dX;
	m_centre.m_y += dY;
	Rotate(dAngle);
}

void CMy2DObjectA4::Move(const CMy2DPoint& delta, double dAngle) {
	Move(delta.m_x, delta.m_y, dAngle);
}

bool CMy2DObjectA4::IsInside(double x, double y) { //метод определени€, лежит ли точка в плоскости                 //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	double x1, y1, x2, y2;

	x1 = x - m_centre.m_x;
	y1 = y - m_centre.m_y;

	//из матрицы поворота
	x2 = x1*cos(m_dAngle) + y1*sin(m_dAngle); //изменила знаки на такие, потому что рисую перевернутую фигуру и поворачиваю по часовой стрелке
	y2 = x1*sin(m_dAngle) - y1*cos(m_dAngle);

	if (abs(x2) > A / 2 || abs(y2) > A / 2) {  
		cout << "“очка не содержитс€ в квадрате A" << endl;
		return false;
	}

	if (y2 < ((-1)*(A / 2) + A3)) { 
		if (x2 < ((-1)*(A / 2) + A3))  {
			cout << "“очка содержитс€ в квадрате A3" << endl;
			return false;
		}
	}                                        

	if (((x2 - (A / 2))*(x2 - (A / 2))) + y2*y2 < A1*A1) { 
		cout << "“очка содержитс€ в круге A1" << endl;
		return false;
	}

	if ((((x2 + (A / 2))*(x2 + (A / 2))) + (y2 - (A / 2))*(y2 - (A / 2))) < A2*A2) {
		cout << "“очка принадлежит A2" << endl;
		return false;
	}
	return true;
}
//проверка точки на принадлежность фигуре
//
bool CMy2DObjectA4::IsInside(const CMy2DPoint& point) {
	return IsInside(point.m_x, point.m_y);
}
//вывод информации о фигуре
//
/*void Figur(CMy2DObjectA4& Obj) {
	cout << "<" << Obj.GetA() << " " << Obj.GetA1() << " " << Obj.GetA2() << " " << Obj.GetA3() << " " << Obj.GetCentre() << " " << Obj.GetAngle() << ">";
}*/



ostream& operator <<(ostream& out, const CMy2DObjectA4& vector) {
	out << "{" << vector.A << ", " << vector.A1 << ", " <<  vector.A2 << ", " << vector.A3 << ", " << vector.m_centre << ", " << vector.m_dAngle << "} ";
	return out;
}

istream& operator >>(istream& in, CMy2DObjectA4& vector) {
	in >> vector.A >> vector.A1 >> vector.A2 >> vector.A3 >> vector.m_centre >> vector.m_dAngle;
	return in;
}

void CMy2DObjectA4::Draw(CDC &dc)
{
	//double x1, y1, x2, y2;
	//double x = 350, y = 350;
	//x1 = x - m_centre.m_x;
	//y1 = y - m_centre.m_y;

	//из матрицы поворота
	//x2 = x1*cos(m_dAngle) - y1*sin(m_dAngle); 
	//y2 = x1*sin(m_dAngle) + y1*cos(m_dAngle);
	double x_1, x_2, x_3, x_4, x_5, x_6, x_7, x_8, x_9, y_1, y_2, y_3, y_4, y_5, y_6, y_7, y_8, y_9, x_45, y_45, x_78, y_78;
	x_1 = m_centre.m_x - A/2 + A3;
	y_1 = m_centre.m_y - A/2 + A3;

	x_2 = m_centre.m_x - A/2 + A3;
	y_2 = m_centre.m_y - A/2;

	x_3 = m_centre.m_x - A/2;
	y_3 = m_centre.m_y - A/2 + A3;

	x_4 = m_centre.m_x - A/2;
	y_4 = m_centre.m_y + A/2 - A2;

	x_45 = m_centre.m_x - A/2;
	y_45 = m_centre.m_y + A/2;

	x_5 = m_centre.m_x - A/2 +A2;
	y_5 = m_centre.m_y + A/2;

	x_6 = m_centre.m_x + A/2;
	y_6 = m_centre.m_y + A/2;

	x_7 = m_centre.m_x + A/2;
	y_7 = m_centre.m_y + A1;

	x_78 = m_centre.m_x + A/2;
	y_78 = m_centre.m_y;

	x_8 = m_centre.m_x + A/2;
	y_8 = m_centre.m_y - A1;

	x_9 = m_centre.m_x + A/2;
	y_9 = m_centre.m_y - A/2;

	double x1, x2, x3, x4, x5, x6, x7, x8, x9, y1, y2, y3, y4, y5, y6, y7, y8, y9, x45, y45, x78, y78;
	x1 = x_1*cos(m_dAngle) - y_1*sin(m_dAngle); 
	y1 = x_1*sin(m_dAngle) + y_1*cos(m_dAngle);

	x2 = x_2*cos(m_dAngle) - y_2*sin(m_dAngle); 
	y2 = x_2*sin(m_dAngle) + y_2*cos(m_dAngle);
	
	x3 = x_3*cos(m_dAngle) - y_3*sin(m_dAngle); 
	y3 = x_3*sin(m_dAngle) + y_3*cos(m_dAngle);

	x4 = x_4*cos(m_dAngle) - y_4*sin(m_dAngle); 
	y4 = x_4*sin(m_dAngle) + y_4*cos(m_dAngle);

	x5 = x_5*cos(m_dAngle) - y_5*sin(m_dAngle); 
	y5 = x_5*sin(m_dAngle) + y_5*cos(m_dAngle);

	x6 = x_6*cos(m_dAngle) - y_6*sin(m_dAngle); 
	y6 = x_6*sin(m_dAngle) + y_6*cos(m_dAngle);

	x7 = x_7*cos(m_dAngle) - y_7*sin(m_dAngle); 
	y7 = x_7*sin(m_dAngle) + y_7*cos(m_dAngle);

	x8 = x_8*cos(m_dAngle) - y_8*sin(m_dAngle); 
	y8 = x_8*sin(m_dAngle) + y_8*cos(m_dAngle);

	x9 = x_9*cos(m_dAngle) - y_9*sin(m_dAngle); 
	y9 = x_9*sin(m_dAngle) + y_9*cos(m_dAngle);

	x45 = x_45*cos(m_dAngle) - y_45*sin(m_dAngle); 
	y45 = x_45*sin(m_dAngle) + y_45*cos(m_dAngle);

	x78 = x_78*cos(m_dAngle) - y_78*sin(m_dAngle); 
	y78 = x_78*sin(m_dAngle) + y_78*cos(m_dAngle);



	dc.MoveTo(x1, y1);
	dc.LineTo(x2, y2);
	dc.MoveTo(x1, y1);
	dc.LineTo(x3, y3);
	dc.LineTo(x4, y4);
	dc.AngleArc(x45, y45, A2, 90 - m_dAngle*180/PI, -90);
	dc.LineTo(x6, y6);
	dc.LineTo(x7, y7);
	dc.MoveTo(x8, y8);
	dc.AngleArc(x78, y78, A1, 90 - m_dAngle*180/PI, 180);
	dc.MoveTo(x8, y8);
	dc.LineTo(x9, y9);
	dc.LineTo(x2, y2);


}; 

