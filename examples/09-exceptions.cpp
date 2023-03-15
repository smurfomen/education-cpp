#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/* обработка исключения ошибки открытия файла */
void file_exceptions() {
	ifstream fin;
	fin.exceptions(ifstream::badbit | ifstream::failbit);

	try
	{
		cout << "Попытка открыть файл..." << endl;
		fin.open("my_fi.txt");
		cout << "Файл открыт!" << endl;
	}
	catch (const ifstream::failure& e)
	{
		cout << "Ошибка открытия файла: " << e.what()
			<< "\n Код ошибки: " << e.code() << endl;
	}
}

/* Производный класс исключения для ситуаций выхода за границы */
struct OutOfRangeException : public exception {
	string cmsg;
	OutOfRangeException(const char* msg) : exception(msg)
	{
		stringstream ss;
		ss << "OutOfRange: " << msg << endl;
		cmsg = ss.str();
	}

	virtual const char* what() const override {
		return cmsg.c_str();
	}
};

/* Производный класс исключения для ситуаций некорректного деления */
struct InvalidDivideException : public exception {
	string cmsg;
	InvalidDivideException(const char* msg, const char* file, int line) : exception(msg)
	{
		stringstream ss;
		ss << "Invalid Divide: " << msg << " at file (" << file << ":" << line << ")" << endl;
		cmsg = ss.str();
	}

	virtual const char* what() const override {
		return cmsg.c_str();
	}
};


/* функция рассчета факториала */
int factorial(int N) {
	if (N < 0)
		throw OutOfRangeException("N lower 0");

	if (N == 0)
		return 0;

	if (N == 1)
		return 1;

	return N * factorial(N - 1);
}

/* функция деления */
int Divide(int a, int b) {
	if (b == 0)
		throw InvalidDivideException("Error Divide", __FILE__, __LINE__);

	return a / b;
}

/* функция получения элемента по индексу */
int GetElement(int* arr, int size, int index) {
	if (index >= size)
		throw OutOfRangeException("index greater size");

	return arr[index];
}

int main()
{
	setlocale(LC_ALL, "ru");

	try
	{
		Divide(2, 0);
	}
	catch (const OutOfRangeException& e)
	{
		cout << e.what() << endl;
	}
	catch (const InvalidDivideException& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}