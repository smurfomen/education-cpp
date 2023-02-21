#include <iostream>
using namespace std;

const int SIZE = 10;

int linear_search(int arr[SIZE], int target) {
    int result = -1;

    for(int index = 0; index < SIZE; ++index) {
        if(arr[index] == target) {
            result = index;
            break;
        }
    }

    return result;
}

int main() {
    const int SIZE = 10;
    int arr [SIZE] = {10,22,41,63,34,62,11,29,92,132};

    int target = 92;
    
    cout << linear_search(arr, target) << endl;
    return 0;
}