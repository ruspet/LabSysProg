#include <iostream>
#include <string>
#include <assert.h>
#include "vectors.h"

using namespace std;

static int nomber = 0; // статическая переменная для нумерации массивов

template <class T>
class arrGeneric
{
private:

    
    int length;
    T* arrGen;
    string name;

public:
    // конструктор для пустого массива
    arrGeneric()
    {
        length = 0;
        arrGen = nullptr;

    }
    // конструктор для массива заданной длины
    arrGeneric(int leng)
    {
        length = leng;
        arrGen = new T[length];
        name = "array№ ";
        name += to_string(nomber);
        nomber++;
    }
    
    // конструктор для массива заданной длиной и именем
    arrGeneric(int leng, string name)
    {
        length = leng;
        arrGen = new T[length];
        this->name = name;
    }

    // конструктор копирования
    arrGeneric(const arrGeneric &arrG)
    {
        length = arrG.length;
        arrGen = new T[length];
        for (int i = 0; i < length; i++)
        {
            arrGen[i] = arrG.arrGen[i];
        }
        
    }

    //деструктор
    ~arrGeneric()
     {
    delete[] arrGen;
     }

    //перегрузка индексирования
    T& operator[](int index)
    {
        assert(index >= 0 && index < length);  // остановить работу программы в случае выхода за пределы массива
        return arrGen[index];  // вернуть элемент массива
    }
    
    //перегрузка умножения
    arrGeneric& operator* (arrGeneric ar2)
    {
        
        if (ar2.getLength() >= length)
        {
            for (int i = 0; i < length; i++)
            {
                arrGen[i] = arrGen[i] * ar2.arrGen[i];
            }
            return *this;
        }
        else
        {
            for (int i = 0; i < ar2.length; i++)
            {
                arrGen[i] = arrGen[i] * ar2.arrGen[i];
            }
            return *this;
        }
        
    }

    //перегрузка сложения
    arrGeneric& operator+ (arrGeneric ar2)
    {

        if (ar2.getLength() >= length)
        {
            for (int i = 0; i < length; i++)
            {
                arrGen[i] = arrGen[i] + ar2.arrGen[i];
            }
            return *this;
        }
        else
        {
            for (int i = 0; i < ar2.length; i++)
            {
                arrGen[i] = arrGen[i] + ar2.arrGen[i];
            }
            return *this;
        }

    }

    void Show()
    {
        cout << name << "\n";
        for (int i = 0; i < length; i++)
        {
            cout << i << ". " << arrGen[i] << "\n";
        }
        cout << "\n";
    }

    //геттер для получения длинны
    int getLength()
    {
        return length;
    }

};

int main()
{
    setlocale(LC_ALL, "rus");

    cout << "тест вывода \n";
    vectors v1(2, 5, "vect1");
    vectors v2(1, 3);
    vectors v3(5, 4);
    vectors v4(7, 2);
    vectors v5(0, 0);
    v1.show();
    v2.show();
    v3.show();
    v4.show();
   
    cout << "\nтест расчетов \n";
    cout <<"скалярное произведение 1 и 2 вектора ="<< v1.multScal(v2) << "\n";
    cout <<"угол между 1 и 2 вектором в радианах =" << v1.degree(v2, true) << "\n";
    cout << "угол между 1 и 2 вектором в градусах =" << v1.degree(v2, false) << "\n";
    
    cout << "\nтест перегрузок \n";
    v5 = v1 + v2;
    cout << "сумма 1 и 2 вектора =";
    v5.show();
    
    v5 = v1 - v2;
    cout <<"\n"<< "разность 1 и 2 вектора =";
    v5.show();
        
    cout << "\n" << "тест создания массива через шаблонный класс" << "\n";
    arrGeneric<vectors> arr1(3);
    arrGeneric<vectors> arr2(3);

    arr1[0] = vectors(1, 1);
    arr1[1] = vectors(2, 2);
    arr1[2] = vectors(3, 3);

    arr2[0] = vectors(4, 4);
    arr2[1] = vectors(5, 5);
    arr2[2] = vectors(6, 6);

    cout << "Выводим исходные вектора первого массива" << "\n";
    for (int i = 0; i < arr1.getLength(); i++)
    {
        arr1[i].show();
    }
    
    cout << "\n" << "Выводим исходные вектора второго массива" << "\n";
    for (int i = 0; i < arr2.getLength(); i++)
    {
        arr2[i].show();
    }

    cout << "\n" << "Выводим сумму двух массивов" << "\n";
    arr1 = arr1 + arr2;
    
    for (int i = 0; i < arr1.getLength(); i++)
    {
        arr1[i].show();
    }

}
