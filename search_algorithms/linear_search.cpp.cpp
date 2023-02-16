#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void linear_search(vector<int> &v, int target, int *result) {
    for(int i = 0; i < v.size(); ++i) {
        if(v[i] == target)
        {
            *result = i;
            return;
        }
    }

    result = nullptr;
}

void linear_search_hack(vector<int> &v, int target, int * result) {
    auto it = find(v.begin(), v.end(), target);

    *result = it - v.begin();
}

int main() {
    vector<int> v{1, 2, 3};

    int result = 0;
    int *pr = &result;
    linear_search(v, 2, pr);

    if (pr)
        cout << result;
    else
        cout << "not found";

    return 0;
}