#include <iostream>
using namespace std;
int main()
{
    /* Два массива А[M] и B[N] (размеры вводятся с клавиатуры)              */
    /* 1. Наполнить оба массива случайными числами, вывести оба массива     */
    /* 2. Соединить оба массива в результирующий третий массив C[M+N]       */
    int M = 0; int N = 0;

    cin >> M;
    cin >> N;

    int* A = new int[M];
    int* B = new int[N];

    for (int i = 0; i < M; ++i) {
        A[i] = rand() % 100;
        cout << A[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < N; ++i) {
        B[i] = rand() % 100;
        cout << B[i] << " ";
    }
    cout << endl;

    int* C = new int[M + N];

    int i = 0;
    for (; i < M; ++i) {
        C[i] = A[i];
    }

    for (int k = 0; k < N; ++k) {
        C[i++] = B[k];
    }

    for (int j = 0; j < M + N; ++j) {
        cout << C[j] << " ";
    }

    return 0;

    return 0;
}