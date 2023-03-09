#include <iostream>
#include <unordered_map>

using namespace std;

int count_uniq(const unordered_map<int, int>& m1, const unordered_map<int, int>& m2) {
	int size = 0;
	for (auto it : m1) {
		int element = it.first;
		int repeats = it.second;
		if (m2.count(element)) {
			if (repeats == 0 && m2.at(element) == 0)
				size++;
		}
	}

	return size;
}

unordered_map<int, int> count_elements(int* arr, int size) {
	unordered_map<int, int> m;
	for (int i = 0; i < size; ++i)
	{
		if (m.count(arr[i]))
			m[arr[i]]++;
		else
			m.insert({ arr[i], 0 });
	}

	return m;
}

void randomize(int* ptr, int size) {
	for (int i = 0; i < size; ++i)
		ptr[i] = rand() % 50;
}

int main() {
	srand(time(NULL));
	int M = 15;
	int N = 15;

	int* A = new int[M];
	int* B = new int[N];

	randomize(A, M);
	for (int i = 0; i < M; ++i) {
		cout << A[i] << " ";
	}
	cout << endl;

	randomize(B, N);
	for (int i = 0; i < N; ++i) {
		cout << B[i] << " ";
	}
	cout << endl;

	unordered_map<int, int> m1 = count_elements(A, M);
	unordered_map<int, int> m2 = count_elements(B, N);

	int size = count_uniq(m1, m2);

	int* C = new int[size] {};
	int i = 0;
	for (pair<int, int> it : m1) {
		if (m2.count(it.first)) {
			if (it.second == 0 && m2.at(it.first) == 0) {
				C[i++] = it.first;
			}
		}
	}

	for (int i = 0; i < size; ++i) {
		cout << C[i] << " ";
	}
	cout << endl;

	return 0;
}

