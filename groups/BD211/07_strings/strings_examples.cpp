#include <iostream>
using namespace std;

#if 0
/* Название k-го месяца */
const char* month_name(int k) {
	static const char* name[] = {
		"none","January","February","March",
		"April","May","June","July","August",
		"September","October","November","December"
	};
	return (k < 0 || k > 12) ? name[0] : name[k];
}

void main() {
	for (int i = 1; i <= 12; i++)
		cout << "Month " << i << " - " << month_name(i) << "\n";
}
#endif

#if 0
#include <stdlib.h>
void main() {
	int digit = atoi("1231241241");
	cout << digit << endl;
}
#endif

#if 0
#include <stdlib.h>
int main() {
	char str[] = "Hello";
	cout << strlen(str) << endl;

	// or

	char* p = "Hello";
	cout << strlen(p) << endl;

	return 0;
}
#endif

#if 0
#include <stdio.h>
const int MAXLEN = 256;
int main() {
	char string[MAXLEN];
	cout << "Input string: ";
	gets_s(string);
	cout << endl;
	cout << "String: " << string << endl;
	cout << "Length = " << strlen(string) << endl;
	return 0;
}
#endif

#if 0
#include <string.h>
int main() {
	char * str1 = new char[10];
	const char* str2 = "hello";

	strcpy_s(str1, 10, str2);
	cout << str1 << endl;
	return 0;
}
#endif

#if 0
int main() {
	char original[128] = "Hello";
	const char* str2 = " everybody!";
	cout << strcat_s(original, str2) << endl;
	return 0;
}
#endif

#if 0
int main() {
	char c1[128] = "Hello";
	const char* c2 = " everybody";
	const char* c3 = " in the World!";
	strcat_s(c1, c2);
	strcat_s(c1, c3);

	cout << c1 << endl;
	return 0;
}
#endif

#if 0
#include <stdio.h>
int main() {
	setlocale(LC_ALL, "ru");

	char surname[128];
	char name[128];
	char pname[128];

	cout << "Фамилия: ";
	cin.getline(surname, 128);
	cout << endl;

	cout << "Имя: ";
	cin.getline(name, 128);
	cout << endl;

	cout << "Отчество: ";
	cin.getline(pname, 128);
	cout << endl;

	int result_size = strlen(surname) + strlen(name)
					+ strlen(pname) + 10;

	char* result = new char[result_size];

	strcpy_s(result, result_size, surname);
	strcat_s(result, result_size, " "); // фамилия + пробел

	strcat_s(result, result_size, name); // фамилия + пробел + имя
	strcat_s(result, result_size, " "); // фамилия + пробел + имя + пробел

	strcat_s(result, result_size, pname); // фамилия + пробел + имя + пробел + отчество

	cout << result << endl;

	return 0;
}
#endif

#if 0
int main() {
	char * filename = new char[128];
	cin.getline(filename, 128);
	char* substring = strchr(filename, '.'); // my_file.txt\0
	if (substring) // char * -> int -> bool 
	{
		cout << "File has extension!" << endl;
	}
	else 
	{
		strcat_s(filename, 128, ".TXT");
	}

	cout << "File name is " << filename << endl;
	cout << "Substring " << substring << endl;
	delete[] filename;
	return 0;
}
#endif

#if 0
#include <string.h>
int main() {
	char* filename = new char[128];
	cin.getline(filename, 128);
	char* substring = strstr(filename, ".txt"); // my_file.txt\0
	if (substring) // char * -> int -> bool 
	{
		cout << "File has extension!" << endl;
	}
	else
	{
		// my_file\0.mp3
		substring = strchr(filename, '.');
		if (substring)
			*substring = '\0'; // удалить любое другое расширение
		
		cout << "Cutted string " << filename << endl;
		strcat_s(filename, 128, ".txt");
	}

	cout << "File name is " << filename << endl;
	cout << "Substring " << substring << endl;
	delete[] filename;
	return 0;
}
#endif


