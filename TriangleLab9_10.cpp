#include <math.h> 
#include <iostream> 
#include <cstring>
#include "Triangle.h"

using namespace std;

Triangle::Triangle(Point _v1, Point _v2, Point _v3, const char* ident):vl(_v1), v2(_v2), v3(_v3) 
{
char buf[16];
objID = new char[strlen(ident) + 1];
#pragma warning(suppress : 4996)
strcpy(objID, ident); 
count++; 
#pragma warning(suppress : 4996)
sprintf(buf, "Треугольник %d", count);

name = new char[strlen(buf) + 1]; 
#pragma warning(suppress : 4996)
strcpy(name, buf);
a = sqrt((vl.x - v2.x) * (vl.x - v2.x) + (vl.y - v2.y) * (vl.y - v2.y));
b = sqrt((v2.x - v3.x) * (v2.x - v3.x) + (v2.y - v3.y) * (v2.y - v3.y)); 
c = sqrt((vl.x - v3.x) * (vl.x - v3.x) + (vl.y - v3.y) * (vl.y - v3.y)); 
cout << "Constructor_1 for: " << objID << " (" << name << ")" << endl; //отладочный вывод 
}

Triangle::Triangle(const char* ident)
{
	char buf[16]; 
	objID = new char[strlen(ident) + 1]; 
	#pragma warning(suppress : 4996)
	strcpy(objID, ident);
	count++;
	#pragma warning(suppress : 4996)
	sprintf(buf, "Треугольник %d", count); 
	name = new char[strlen(buf) + 1]; 
	#pragma warning(suppress : 4996)
	strcpy(name, buf);
	a = b = c = 0; cout << "Constructor_2 for: " << objID << " (" << name << ")" << endl; //отладочный вывод 
}

Triangle::~Triangle() 
{ 
	cout << "Destructor for: " << objID << endl;
	delete[] objID; 
	delete[] name; 
}

void Triangle::Show() const
{
	cout << name << ":";
	vl.Show();
	v2.Show();
	v3.Show(); 
	cout << endl;
} // Показать стороны и площадь объекта 

void Triangle::ShowSideAndArea() const 
{ 
	double p = (a + b + c) / 2; 
	double s = sqrt(p * (p - a) * (p - b) * (p - c)); 
	cout << " " << endl; 
	cout << name << ":";
	cout.precision(4);
	cout << " a= " <<  a;
	cout << ", b= " <<  b;
	cout << ", c= " <<  c; 
	cout << ":\ts= " << s << endl; 
}
