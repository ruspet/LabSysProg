#include "vectors.h"
#include <iostream>
#include <string>
#include <assert.h>
#include <math.h>

using namespace std;

static int a = 0;

vectors::vectors(int _x, int _y)
{
	vect.x = _x;								//присваиваем значения координат
	vect.y = _y;
	name = "vect №" + to_string(a);			//присваимвем сгенерированное имя
	a++;									//увиличиваем статическую переменную для генерации имен
	length = leng(vect);					//вычисляем длинну вектора
}

//конструктор для вектора без имени
vectors::vectors(float x, float y)
{
	vect.x = x;								//присваиваем значения координат
	vect.y = y;
	name = "vect №" + to_string(a);			//присваимвем сгенерированное имя
	a++;									//увиличиваем статическую переменную для генерации имен
	length = leng(vect);					//вычисляем длинну вектора
}

//конструктор для вектора с заданным именем
vectors::vectors(float x, float y, string name)
{
	vect.x = x;
	vect.y = y;
	this->name = name;
	length = leng(vect);
}

//метод для вычисления длинны вектора
float vectors::leng(coord x)
{
	float rezult = 0;								//переменная для результата		
	rezult = sqrt(pow(x.x, 2) + pow(x.y, 2));		//вычисление длины вектора
	return rezult;									//возвращаем значение
}

//скалярное произведение векторов
float vectors::multScal(vectors vect2)
{
	float rezult = 0;											//переменная для результата		
	rezult = (vect.x*vect2.vect.x)+(vect.y*vect2.vect.y);		//вычисление скалярного произведения векторов
	return rezult;												//возвращаем значение
}

//угол между векторами
float vectors::degree(vectors vect2, bool rad)
{
	float rezult = 0;											//переменная для результата
	float cosA = 0;												//переменная для промежуточных вычисленний
	cosA = (this->multScal(vect2))/(this->length*vect2.length);		//вычисление косинуса угла между векторами
	rezult = acos(cosA);										//вычисление угла между векторами
	
	if (rad)
		return rezult;												//возвращаем значение в радианах
	else
		return (rezult * 180) / 3.141;								//возвращаем значение в градусах
}

//вывод вектора
void vectors::show()
{
	cout << name << "   " << "(" << vect.x << ";" << vect.y << ")"<< "  Длинна вектора = "<<length<<"\n";
}

//перегрузка для сложения векторов
vectors vectors::operator+(vectors vect)
{
	return vectors(this->vect.x + vect.vect.x, this->vect.y + vect.vect.y);
}

//перегрузка для вычитания векторов
vectors vectors::operator-(vectors vect)
{
	return vectors(this->vect.x - vect.vect.x, this->vect.y - vect.vect.y);
}
