// Laba7.cpp односвязный список, реализация
//
#include <iostream>
#include <string>
#include <ctime>
using namespace std;





template<typename T>
class List
{
public:
    List();
    ~List();

    void pop_front();
    void push_back(T data);          // добавляет элемент в конец списка
    void clear();
    int GetSize() { return Size; }   // метод, возвращающий количество элементов списка

    T& operator[](const int index); //перегрузка оператора [], возвращает данные из списка по указанному нами индексу

private:


    template<typename T>
    class Node  
    {
    public:
        Node *pNext;
        T data;

        Node(T data=(T), Node* pNext = nullptr) 
        {
            this->data = data;       //поле класса = аргумент
            this->pNext = pNext;
        }
    };
    int Size;
    Node<T> *head;
};


template<typename T>
List<T>::List()                     //конструктор
{
    Size = 0;
    head = nullptr;
}


template<typename T>
List<T>::~List()                   //деструктор    
{
    clear();                       //удаляет все элементы списка, очищает память
}

template<typename T>                
void List<T>::pop_front()          // блок удаления первого элемента списка   
{
    Node<T> *temp = head;

    head = head->pNext;

    delete temp;

    Size--;
}

template<typename T>
void List<T>::push_back(T data)   //блок добавления нового элемента в конец списка
{
    if (head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T> *current = this->head;

        while (current->pNext !=nullptr)
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }

    Size++;
}

template<typename T>
void List<T>::clear()   //удаление поочередно, начиная с первого, всех элементов списка
{
    while (Size)
    {
        pop_front();
    }

}


template<typename T>
T& List<T>::operator[](const int index) //поиск элемента по индексу и возвращение его значения
{
    int counter = 0;
    Node<T>* current = this->head;
    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
}
    


int main()
{

    setlocale(LC_ALL, "ru");
    srand(time(NULL));

    List<int> lst; 



    int numbersCount;
    cout << "Введите количество элементов списка: "; 
    cin >> numbersCount;
    for(int i=0; i<numbersCount; i++)  // заполняем список случайными значениями в диапазоне от 0 до 10
    {
        lst.push_back(rand() % 10);
    }


    for (int i = 0; i < lst.GetSize(); i++)  //выводим список на экран
    {
        cout << lst[i] << endl;
    }

    cout << "Всего элементов в списке: " << lst.GetSize() << endl;

    int number;
    cout << "Введите номер элемента списка, значение которого вы хотите увидеть: ";
    cin >> number;

    try 
    {
        if (number<0 || number>numbersCount) 
        {
            throw "You are out of the list";
        }
    }
    catch (const char* exception) 
    {
        cerr << "Error!!! " << exception << endl;
    }
    


    cout << lst[number - 1] << endl;                        //вывод значения элемента списка по индексу

    return 0;

}























































































/*

#include <iostream>

using namespace std;
struct Node
{
    int data;
    Node* next;
};

class List
{
private:
    Node* head; //"голова" связанного списка

public:
    List() //конструктор класса без параметров
    {
        head = NULL; //первого элемента пока нет
    }

    //метод, добавляющий новый узел в список
    void addNode(int d)
    {
        Node* nd = new Node; //динамически создаем новый узел

        nd->data = d;        //задаем узлу данные
        nd->next = NULL;     //новый узел в конце, поэтому NULL

        if (head == NULL)     //если создаем первый узел
            head = nd;
        else                 //если узел уже не первый
        {
            Node* current = head;

            //ищем в цикле предшествующий последнему узел
            while (current->next != NULL)
                current = current->next;

            //предшествующий указывает на последний
            current->next = nd;
        }
    }

    //метод, выводящий связанный список на экран
    void printList()
    {
        Node* current = head;

        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main()
{
    List myList;

    myList.addNode(5);
    myList.addNode(11);
    myList.addNode(27);
    myList.addNode(35);
    myList.addNode(50);

    myList.printList();

    return 0;
}

 
*/
















































// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
