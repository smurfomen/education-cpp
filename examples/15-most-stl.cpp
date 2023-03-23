#include <iostream>
#include <algorithm>
#include <numeric>
#include <array>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cassert>
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
    + numeric_limits
    + min
    + max
    + swap
    + min_element
    + max_element
    + any_of
    + find
    + find_if
    + set
    + map
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

#if 0
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


    /* 
        sort - сортировка коллекции
        reverse - изменение коллекции задом наперед
    */
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
    /* accumulate - сумма эллементов в коллекции */
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

        sum = accumulate(   
                            arr2.begin(),                           // откуда
                            arr2.end(),                             // до куда
                            accumulate(arr1.begin(), arr1.end(), 0) // добавить к результату
                        );
    }

    /* лимиты */
    {
        cout << "int: "     << numeric_limits<int>::min() << "\t"
                            << numeric_limits<int>::max() << endl;

        cout << "usnigned int: "    << numeric_limits<unsigned int>::min() << "\t"
                                    << numeric_limits<unsigned int>::max() << endl;

        cout << "char: "    << static_cast<int>(numeric_limits<char>::min()) << "\t"
                            << (int)numeric_limits<char>::max() << endl;

        cout << "unsigned char: "   << (uint32_t)numeric_limits<unsigned char>::min() << "\t"
                                    << (uint32_t)numeric_limits<unsigned char>::max() << endl;

        cout << "uint64_t: "    << numeric_limits<uint64_t>::min() << "\t"
                                << numeric_limits<uint64_t>::max() << endl;
    }

    /* min - возвращает минимальное значение из двух */
    /* max - возвращает максимальное значение из двух */
    {
        {
            int a = 5, b = 10;

            /* нахождение максимального числа среди a и b. max должна принимать 2 аргумента одинакового типа */
            int m = max(a, b);
            cout << "a and b max: " << m << endl;
            assert(m == 10);
        }

        {
            int a = 5;

            /* b будет переполнен */
            int b = numeric_limits<int>::max() + 1;
            cout << "overflowed b and a max : " << "b " << b << " a "<< a << " max: " << max(a, b) << endl;
        }

        {
            int a = 5;
            /* b не будет переполнено, т.к. его максимальное значение существенно больше максимума int */
            unsigned int b = a + numeric_limits<int>::max();

            /* явное указание типа сравниваемых значений с помощью шаблонного параметра */
            int m = max<unsigned int>(a, b);
            cout << "overflowed b and a max : " << "b " << b << " a " << a << " max: " << m << endl;
        }

        {
            int x = 10;
            auto y = x + 0.2;
            cout << x + 0.2 << endl; // когда как (10 или 10.2)
            cout << static_cast<double>(x + 0.2) << endl; // гарантированно 10.2
        }
    }

    /* swap - меняет местами значения */
    {
        {
            int a = 5, b = 10;
            swap(a, b);

            cout << "swap a and b: [a " << a << " b: " << b << "]" << endl;

            assert(a == 10 && b == 5);
        }

        {
            string a = "Hello", b = "World";
            cout << a << b << endl;

            /* обмен значениями */
            swap(a, b);

            assert(a == "World");
            assert(a == "Hello");

            cout << a << b << endl;
        }
    }

    /* min_element - возвращает наименьший элемент в коллекции */
    /* max_element - возвращает наибольший элемент в коллекции */
    {
        {
            array<int, 10> arr = { 4,5,6,7,8,9,8,7,2,5 };

            /* it - итератор, который лежит внутри диапазона массива если эллемент найден */
            auto it = min_element(arr.begin(), arr.end());

            /* исользование итератора без проверки может привести к разыменованию недоступной памяти за пределами массива */
            cout << *it << endl;
        }

        {
            array<int, 10> arr = { 4,5,6,7,8,9,8,7,2,5 };

            /* it - итератор, который лежит внутри диапазона массива если эллемент найден */
            auto it = max_element(arr.begin(), arr.end());

            /* исользование итератора без проверки может привести к разыменованию недоступной памяти за пределами массива */
            cout << *it << endl;
        }

        {
            vector<int> arr;
            
            /* it - итератор, который лежит внутри диапазона массива если эллемент найден */
            auto it = min_element(arr.begin(), arr.end());

            /* перед использованием итератора нужно проверять его на нахождение внутри диапазона границ массива */
            (it != arr.end() ? cout << *it : cout << "not found");
            cout << endl;

            /* то же самое */
            if (it != arr.end())
                cout << *it << endl;
            else
                cout << "min element not found" << endl;
        }
    }

    {
        {
            array<int, 10> arr = { 4,5,6,7,8,9,8,7,2,5 };

            /* exists будет равен true в случае если в массиве есть хоть один эллемент равный 5 */
            bool exists = any_of(arr.begin(), arr.end(), [](int i) { return i == 5; });

            cout << exists << endl;
        }

        {
            array<int, 10> arr = { 4,5,6,7,8,9,8,7,2,5 };

            /* exists будет равен true в случае если в массиве есть хоть один эллемент больше 10 */
            bool exists = any_of(arr.begin(), arr.end(), [](int i) { return i > 10; });

            cout << exists << endl;
        }
    }

    {
        array<int, 10> arr = { 4,3,6,7,8,9,8,7,2,5 };

        /* поиск первого вхождения числа 5 */
        auto it = find(arr.begin(), arr.end(), 5);

        /* используем только если итератор внутри диапазона массива */
        if (it != arr.end())
        {
            cout << *it << endl;

            /* икрементируем итератор */
            it++;

            /* проверка на то, что инкремент итератора не вывел его за границы массива */
            if (it != arr.end())
            {
                cout << *it << endl;
            }
        }
    }

    {
        array<int, 10> arr = { 4,3,6,5,8,9,8,7,2,3 };

        /* поиск первого вхождения элемента больше 5 */
        auto it = find_if(arr.begin(), arr.end(), [](auto i) { return i > 5; });

        /* используем только если итератор не вышел за границы диапазона */
        if (it != arr.end())
        {
            /* превращаем итератор в числовой индекс */
            int index_element = it - arr.begin();

            cout << *it << " index is " << index_element << endl;
            
            /* икрементируем итератор */
            it++;

            /* проверка на то, что инкремент итератора не вывел его за границы массива */
            if (it != arr.end())
            {
                cout << *it << endl;
            }
        }
    }

    /* set - набор уникальных элементов переменной длинны */
    {
        set<int> s;
        /* вставка элементов */
        s.insert(5);
        s.insert(10);
        s.insert(5);
        
        /* количество уникальных элементов - 2 */
        cout << "size is " << s.size() << endl;
        assert(s.size() == 2);

        for (auto it : s)
            cout << it << endl;
    }
#endif

    /* map - набор уникальных ключей и их соотношений */
    {
        /* map<тип_ключа, тип_значения> имя; */
        map<int, string> m = {
            {0, "nighmare"},
            {1, "flex111"},
            {2, "lion228"}
        };

        /* распечатать */
        auto print_map = [](auto & m) {
            cout << "----------------------------------" << endl;
            cout << "size: " << m.size() << endl;
            for (auto it : m)
                cout << "User id: " << it.first << "\tUser nickname: " << it.second << endl;
            cout << endl;
        };

        /* размер может динамически меняться во время выполнения */
        assert(m.size() == 3);

        print_map(m);

        /* добавление нового элемента с ключом 3 и значением popit */
        m.insert({ 3, "popit" });

        /* попытка добавления элемента с существующим ключом через insert не изменит существующее значение */
        m.insert({ 0, "uxi" }); // fail, not inserted
        
        assert(m.size() == 4);

        print_map(m);

        /* проверка на существование элемента с ключом 0 */
        if (m.count(0)) {
            /* изменение значения элемента под ключом 0 */
            m[0] = "uxi";
        }

        print_map(m);

        /* если значения с ключом 5 не найдено, то он будет добавлен со значением geraldt */
        m[5] = "geraldt";

        print_map(m);
    }

    /* наивная реализация конвертации римской нотации в десятичную */
    {
        map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10}
        };

        string r("XVI"); // 16
        int d = 0;
        for (char ch : r)
        {
            if (m.count(ch))
                d += m[ch];
        }

        cout << d << endl;

        d = 0;
        r = "III";
        for (char ch : r)
        {
            if (m.count(ch))
                d += m[ch];
        }

        cout << d << endl;
    }


    /* более осмысленная реализация римской нотации в десятичную */
    {
        /* таблица соответствий римских чисел десятичным */
        map<char, int> m = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        /* интерпретация римских чисел как десятичные */
        string s ("MCMXCIV");

        /* отразить задом наперед */
        reverse(s.begin(), s.end()); // VICXMCM

        int result = 0;
        int prev = 0;
        for (auto ch : s)
        {
            /* обрабатываем только существующие в "алфавите римских цифр" буквы */
            if (m.count(ch))
            {
                int cur = m[ch];

                /* если текущее значение меньше чем предыдущее - отнять от результата текущее */
                if (cur < prev)
                {
                    result -= cur;
                }

                /* иначе прибавить к результату текущее и запомнить его в предыдущее prev */
                else {
                    prev = cur;
                    result += cur;
                }
            }
        }

        cout << result << endl;
    }


    return 0;
}
