#include <iostream>
#include <vector>
using namespace std;

int binary_search(vector<int> & v, int x) {
    int begin = 0;
    int end = v.size()-1;

    while(begin <= end) {
        int mid = (begin + end) / 2;

        /* x founded */
        if(v[mid] == x)
            return mid;

        /* x at the left side */
        else if(v[mid] > x)
            end = mid - 1;

        /* x at the right side */
        else
            begin = mid + 1;
    }

    return -1;
}


int main() {
    {
       vector<int> v {1,2,3,4,5,6,7};

        cout << binary_search(v, 4) << endl; // 3 index
    }
    
    {
        vector<int> v {1,5,6,6,7,10,14,15,22,25,42,67,92,994,2144,24125};
        cout << binary_search(v, 67) << endl; // 11 index
    }

    return 0;
}