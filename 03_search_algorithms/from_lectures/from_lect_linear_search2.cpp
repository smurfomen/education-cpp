#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10;
    int arr [SIZE] = {10,22,41,63,34,62,11,29,92,132};

    int target = 92;
    int result = -1;

    for(int index = 0; index < SIZE; ++index) {
        if(arr[index] == target) {
            result = index;
            break;
        }
    }

    cout << result << endl;
    return 0;
}