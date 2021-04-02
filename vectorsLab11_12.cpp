#include "vectors.h"
#include <iostream>
#include <string>
#include <assert.h>
#include <math.h>

using namespace std;

static int a = 0;

vectors::vectors(int _x, int _y)
{
	vect.x = _x;								//����������� �������� ���������
	vect.y = _y;
	name = "vect �" + to_string(a);			//����������� ��������������� ���
	a++;									//����������� ����������� ���������� ��� ��������� ����
	length = leng(vect);					//��������� ������ �������
}

//����������� ��� ������� ��� �����
vectors::vectors(float x, float y)
{
	vect.x = x;								//����������� �������� ���������
	vect.y = y;
	name = "vect �" + to_string(a);			//����������� ��������������� ���
	a++;									//����������� ����������� ���������� ��� ��������� ����
	length = leng(vect);					//��������� ������ �������
}

//����������� ��� ������� � �������� ������
vectors::vectors(float x, float y, string name)
{
	vect.x = x;
	vect.y = y;
	this->name = name;
	length = leng(vect);
}

//����� ��� ���������� ������ �������
float vectors::leng(coord x)
{
	float rezult = 0;								//���������� ��� ����������		
	rezult = sqrt(pow(x.x, 2) + pow(x.y, 2));		//���������� ����� �������
	return rezult;									//���������� ��������
}

//��������� ������������ ��������
float vectors::multScal(vectors vect2)
{
	float rezult = 0;											//���������� ��� ����������		
	rezult = (vect.x*vect2.vect.x)+(vect.y*vect2.vect.y);		//���������� ���������� ������������ ��������
	return rezult;												//���������� ��������
}

//���� ����� ���������
float vectors::degree(vectors vect2, bool rad)
{
	float rezult = 0;											//���������� ��� ����������
	float cosA = 0;												//���������� ��� ������������� �����������
	cosA = (this->multScal(vect2))/(this->length*vect2.length);		//���������� �������� ���� ����� ���������
	rezult = acos(cosA);										//���������� ���� ����� ���������
	
	if (rad)
		return rezult;												//���������� �������� � ��������
	else
		return (rezult * 180) / 3.141;								//���������� �������� � ��������
}

//����� �������
void vectors::show()
{
	cout << name << "   " << "(" << vect.x << ";" << vect.y << ")"<< "  ������ ������� = "<<length<<"\n";
}

//���������� ��� �������� ��������
vectors vectors::operator+(vectors vect)
{
	return vectors(this->vect.x + vect.vect.x, this->vect.y + vect.vect.y);
}

//���������� ��� ��������� ��������
vectors vectors::operator-(vectors vect)
{
	return vectors(this->vect.x - vect.vect.x, this->vect.y - vect.vect.y);
}
