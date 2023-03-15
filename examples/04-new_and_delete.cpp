#include <iostream>
using namespace std;

void new_int() {
    /* выделение динамической памяти */
    int* p = new int(2);

    /* изменение значения по адресу p на 10 */
    *p = 10;

    // ....
    delete p;

    p = new int(3);

    cout << *p << endl;

    delete p;
}

void new_array() {
    int size = 0;
    cin >> size;

    int* studs = new int[size];

    cout << "Allocated " << size * sizeof(int) << " bytes" << endl;

    srand(time(NULL));

    for (int i = 0; i < size; i++) {
        studs[i] = rand() % 100;
    }

    for (int i = 0; i < size; ++i) {
        cout << studs[i] << " ";
    }

    delete[] studs;
}

int main()
{
    return 0;
}