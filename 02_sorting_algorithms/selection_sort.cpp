#include <vector>
#include <iostream>
using namespace std;

void selection_sort(vector<int> & v) {
    for(int i = 0; i < v.size()-1; ++i)
    {
        int min = i;
        for(int j = i+1; j < v.size(); ++j)
        {
            if(v[j] < v[min])
                min = j;
        }

        if(min != i)
            swap(v[min], v[i]);
    }
}


int main() {
    vector<int> v {3,6,2,1,5,6};

    selection_sort(v);

    for(auto it : v) {
        cout << it;
    }

    return 0;
}