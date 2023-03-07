#include <iostream>
#include <string>
using namespace std;

#if 0
struct Iron {
	string manufactor = "none_manufactor";
	string model = "none_model";
	double min_temp = 0.0, max_temp = 0.0;
	bool with_fog = false;
	int power = 0;

	void print() {
		cout << manufactor << '\n'
			<< model << '\n'
			<< min_temp << ',' << max_temp << '\n'
			<< (with_fog ? "fogged" : "no fogged") << '\n'
			<< power << '\n'
			<< endl;
	}
};


int main() {
	Iron i;
	i.manufactor = "Samsung";
	i.model = "AX3000";
	i.min_temp = 35.00;
	i.max_temp = 190.5;
	i.with_fog = true;
	i.power = 1000;
	i.print();

	return 0;
}
#endif

#if 0
struct WashingMachine {
	string manufactor;
	string color;
	int wide;
	int length;
	int height;
	int speed;
	double temp;

	void print() {
		cout << manufactor << '\n'
			<< color << '\n'
			<< wide << ',' << length << ',' << height << '\n'
			<< speed << '\n'
			<< temp << '\n'
			<< endl;
	}
};

int main() {
	WashingMachine wm;
	wm.manufactor = "Samsung";
	wm.color = "white";
	wm.wide = 100;
	wm.length = 100;
	wm.height = 90;
	wm.speed = 1500;
	wm.temp = 65.7;

	wm.print();

	return 0;
}
#endif


#if 0
struct Student {
	int age;
	string name;
	int course;

	void print_many(int count) {
		for (int x = 0; x < count; ++x)
			print();
	}

	void print() {
		cout << "Возраст: " << age
			<< " Имя: " << name
			<< " Курс: " << course << endl;
	}
};



void print(Student s) {
	cout << "Возраст: " << s.age
		<< " Имя: " << s.name
		<< " Курс: " << s.course << endl;
}

int main() {
	setlocale(LC_ALL, "Rus");
	{
		Student s1{ 19, "Mike", 2 };
		Student s2{ 19, "Alex", 2 };

		s1.print();
		s2.print();
	}

	return 0;
}

#endif