#include <iostream>
using namespace std;

namespace study {
    void foo() {
        cout << "foo" << endl;
    }
}

namespace student {
    void execute() {
        cout << "student exec" << endl;
    }
}

namespace academy {
    void execute() {
        cout << "academy exec" << endl;
    }
}

void print(int num) {
    cout << num << endl;
}

void print(double d) {
    cout << d << endl;
}

int main() {

    student::execute();
    academy::execute();

    study::foo();
    print(2);
    print(3.4);

    return 0;
}