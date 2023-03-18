#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#include <string>
using namespace std;

/*
    + size
    + array
    + copy
    + fill
    + random_shuffle
    + sort
    + reverse
    + accumulate
    numeric_limits
    min
    max
    swap
    min_element
    max_element
    any_of
    find
    find_if
    set
*/

struct A {
    array<int, 10> arr;
};

void foo(A a) {
    auto& arr = a.arr;
    arr[0];
}


/* перегрузка функций */
void bar() {
    cout << "bar()" << endl;
}

void bar(int i) {
    cout << "bar(int) " << i << endl;
}


int main()
{
    /* вывод массива на экран */
    auto print = [](auto arr) {
        for (auto i : arr) {
            cout << i << " ";
        }
        cout << endl;
    };

    {
        int arr[10] = { 1, 2, 3 };
        for (int i = 0; i < size(arr); ++i) {
            arr[i] = i;
        }
    }

    {
        array<int, 10> arr;    // int arr[10];

        /* заполнить массив от 0 до 9 */
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = i;
        }

        print(arr);

        /* заполнить все элементы числом 55 */
        arr.fill(55);

        print(arr);
    }

    {
        srand(time(NULL));
        array<int, 10> arr;

        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = rand() % 100;
        }
        // or
        for (auto& i : arr) {
            i = rand() % 100;
        }
        

        /* перетасовать элементы */
        random_shuffle(arr.begin(), arr.end());

        print(arr);

        fill(arr.begin(), arr.end(), 0);
        // or
        arr.fill(0);

        print(arr);
    }

    {
        srand(time(NULL));
        array<int, 10> arr1;
        for (auto& i : arr1) i = rand() % 100;

        array<int, 20> arr2;
        arr2.fill(0);

        /* копирует эллементы из arr1 в начало arr2 */
        auto it = copy(arr1.begin(), arr1.end(), arr2.begin());
        /* it - место, где копирование остановилось */
        /* копирование эллементов из arr1 в it */
        copy(arr1.begin(), arr1.end(), it);


        /* bad C analog to copy */
        memcpy(arr2.data(), arr1.data(), arr1.size());

        print(arr2);
    }

    {
        srand(time(NULL));
        array<int, 10> arr;
        for (auto& i : arr) i = rand() % 100;

        cout << "Randomized: ";
        print(arr);

        sort(arr.begin(), arr.end());

        cout << "Sorted: ";
        print(arr);

        reverse(arr.begin(), arr.end());
        cout << "Revese: ";
        print(arr);

        {
            /* C-style */
            int carr[10];
            for (int i = 0; i < 10; ++i)
                carr[i] = rand() % 100;

            sort(begin(carr), end(carr));

            cout << "C-style ";
            for (int i = 0; i < size(carr); ++i) {
                cout << carr[i] << " ";
            }
            cout << endl;
        }
    }

    {
        srand(time(NULL));
        array<int, 10> arr1;
        for (auto& i : arr1) i = rand() % 10;
        print(arr1);

        array<int, 20> arr2;
        for (auto& i : arr2) i = rand() % 10;
        print(arr2);


        int sum = accumulate(arr2.begin(), arr2.end(), 0);
        sum += accumulate(arr1.begin(), arr1.end(), 0);

        cout << "Sum arr1 and arr2: " << sum << endl;
    }



    return 0;
}
