#include <iostream>
#include <string>
using namespace std;

#if 0
/* 1. передача по ссылке */
void foo(int& x) {
    x = 1;
}
#endif

#if 1
/* 2. передача по значению */
void foo(int y) {
    y = 3;
}
#endif

/* 3. передача по указателю */
void foo(int* x) {
    *x = 2;
}

typedef string(*function)();
string GetInfoFromImage() {
    return "Hello From Image";
}

string GetInfoFromNetwork() {
    return "Hello From Network";
}

string GetInfoFromDataBase() {
    return "Hello From DB";
}

void ShowInfo(function foo) {
    cout << foo() << endl;
}

int main()
{
    function array[3] = {
        GetInfoFromDataBase,
        GetInfoFromNetwork,
        GetInfoFromNetwork
    }; 

    for(int i = 0; i < 3; ++i)
        ShowInfo(array[i]);

    return 0;
}