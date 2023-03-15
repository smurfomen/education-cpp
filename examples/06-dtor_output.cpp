#include <iostream>

using namespace std;

struct A {
	virtual void print() { cout << "I'm A object" << endl; }
	virtual ~A() { cout << "A::dtor" << endl; }
};

struct B : public A {
	void print() override { cout << "I'm B object" << endl; }
	virtual ~B() { cout << "B::dtor" << endl; }
};


int main() {
    B b;
    b.print();
    return 0;
}