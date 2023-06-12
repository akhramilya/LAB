﻿#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <typeinfo>

using namespace std;

class A {
public:
    string s;

    A() {
        cout << "Конструктор по умолчанию класса A" << endl;
    }

    A(const char* a) {
        s = a;
        cout << "Пользовательский Конструктор класса A" << endl;
        cout << s << endl;
    }

    virtual ~A() {
        cout << "Деструктор класса A" << endl;
        cout << typeid(*this).name() << endl;
    }
};

class B : public A {
public:
    B() {
        cout << "Конструктор класса B" << endl;
    }

    B(const char* a) : A(a) {
        cout << "Пользовательский Конструктор класса B" << endl;
        cout << a << endl;
    }

    ~B() {
        cout << "Деструктор класса B" << endl;
        cout << typeid(*this).name() << endl;
    }
};

void del(vector<A*>& v) {
    for (int i = 0; i < v.size(); i++) {
        delete v[i];
    }
    v.clear(); // Очистка вектора
}

int main() {
    list<A*> l;
    l.push_back(new A("first"));
    l.push_back(new B("second"));

    vector<A*> v(l.begin(), l.end()); // Копирование из списка в вектор

    del(v);

    return 0;
}

//Добавлен заголовочный файл <list> для использования списка и исправлены пропущенные точки с запятой в определении контейнеров v и l.
//Копирование из списка в вектор осуществляется с помощью конструктора vector и передачи итераторов, указывающих на начало и конец списка.
//В функции del после удаления объектов из вектора v, добавлен вызов v.clear(), который очищает вектор от указателей.
//Это предотвращает повторное удаление объектов в векторе при его уничтожении, поскольку они уже удалены ранее в цикле.