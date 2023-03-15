#include <iostream>

using namespace std;

/*
    lambda
    functors
*/

void foo(int i) {
    cout << i << endl;
}

#include <functional>
#include <vector>
#include <string>
#include <algorithm>

/* вызов лямбда функции переданной в качестве аргумента */
void invokes(function<void()> f) {
    f();
}

/* вызов лямбда функции для каждого элемента коллекции */
void handle(vector<int> vec, function<void(int)> fn) {
    for (int it : vec)
        fn(it);
}

/* вызов лямбда функции для каждого элемента коллекции, которая изменяет эллемент */
void increment(vector<int>& vec, function<void(int&)> fn) {
    for (auto& it : vec)
        fn(it);
}

/* возврат функции из функции */
function<void(int)> get_func() {
    return foo;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    {
        vector<int> vec = { 1,2,3 };
        handle(vec, [](int i) {
            cout << "Элемент: " << i << endl;
            });

        increment(vec, [](int& i) {
            i++;
            });

        handle(vec, [](int i) {
            cout << "Элемент: " << i << endl;
            });
    }


    /* лямбда в лямбде, захват контекста по ссылке */
    {
        vector<int> vec = { 1,2,3 };
        int x = 100;
        auto inc = [&](int i) {
            auto print = [&](int a) {
                cout << a + x << endl;
            };

            print(i + x);
        };
        handle(vec, inc);
    }

    /* использования лямбда-функций в качестве предиката */
    {
        vector<int> vec = { 1,2,3 };
        {
            auto iterator = find_if(vec.begin(), vec.end(), [](int it) {
                return it == 2;
                });

            cout << *iterator << endl;
        }


        {
            /* reverse sort */
            sort(vec.begin(), vec.end(), [](int& a, int& b) {
                return a > b;
                });

            handle(vec, [](int i) {
                cout << i << endl;
                });
        }
    }

    /* создание задач к выполнению "на потом" */
    {
        vector<function<void()>> tasks;

        {
            tasks.push_back([]() {
                cout << "Hey" << endl;
                });

            /*.. some code ....... */
            tasks.push_back([]() {
                cout << "call my name" << endl;
                });

            /*.. some code ....... */

            tasks.push_back([]() {
                cout << "I'm Alex!" << endl;
                });
        }

        for (auto task : tasks) {
            task();
        }
    }

    return 0;
}