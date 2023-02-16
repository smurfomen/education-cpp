#include <vector>
#include <iostream>
using namespace std;

void bubble_sort(vector<int> & v) {
    for (int i = 0; i < v.size()-1; i++) {
        for (int j = 0; j < v.size() - 1; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j+1]);
            }
        }
    }
}


int main() {
    vector<int> v {3,6,2,1,5,6};

    bubble_sort(v);

    for(auto it : v) {
        cout << it;
    }

    return 0;
}