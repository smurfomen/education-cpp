#include <iostream>
#include <string>

using namespace std;

struct Animal {
	string name;
	Animal(string n) : name(n) { } 
	virtual void speak() = 0;
};

struct Cat : public Animal {
	Cat(string n) : Animal(n) { }
	void speak() { cout << name <<" say meow-meow" << endl; }
};

struct Dog : public Animal {
	Dog(string n) : Animal(n) { }
	void speak() { cout << name <<" say gaw-gaw" << endl; }
};

struct Cow : public Animal {
	Cow(string n) : Animal(n) { }
	void speak() { cout << name <<" say moow" << endl; }
};

struct Lion : public Animal {
	Lion(string n) : Animal(n) { }
	void speak() { cout << name <<" say rrr-rrr" << endl; }
};

int main() {
    Animal* animals[4]= { 
                    new Dog("Bob"),
                    new Cat("Murka"),
                    new Cow("Murawushka"),
                    new Lion("King")
                    };

    for(int k=0; k < 4; ++k) 
        animals[k]->speak();

    return 0;
}