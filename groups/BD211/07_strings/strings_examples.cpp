#include <iostream>
using namespace std;

#if 0
/* Название k-го месяца */
const char* month_name(int k) {
	/* массив строк (массив указателей на char. Поскольку строка - указатель на char, то массив строк - массив char*) */
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
/* получение длины строки (strlen возвращает количество символов в строке до \0)*/
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
	char* str1 = new char[10];
	const char* str2 = "hello";

	/* копировать str2 в str1*/
	strcpy_s(str1, 10, str2);
	cout << str1 << endl;
	return 0;
}
#endif

#if 0
int main() {
	char original[128] = "Hello";
	const char* str2 = " everybody!";

	/* добавить строку str2 к строке original */
	cout << strcat_s(original, str2) << endl;
	return 0;
}
#endif

#if 0
int main() {
	char c1[128] = "Hello";
	const char* c2 = " everybody";
	const char* c3 = " in the World!";

	/* добавить строку c2 к строке c1 (" everybody" к "Hello") */
	strcat_s(c1, c2);

	/* добавить строку c3 к строке c1 (" in the World!" к "Hello everybody") */
	strcat_s(c1, c3);

	/* c1: Hello everybody in the World! */
	cout << c1 << endl;
	return 0;
}
#endif

#if 0
// конкатенация строк - в Windows-1251 работает только с английскими символами 
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

	/* размер результирующей строки - длина имени фамилии и отчества + 2 пробела + 1 терминирующий ноль (\0) */
	int result_size = strlen(surname) + strlen(name)
		+ strlen(pname) + 3;

	char* result = new char[result_size];

	/* скопировать в результирующий массив фамилию */
	strcpy_s(result, result_size, surname);

	/* добавить пробел */
	strcat_s(result, result_size, " "); // фамилия + пробел

	/* скопировать в результирующий массив имя */
	strcat_s(result, result_size, name); // фамилия + пробел + имя

	/* добавить пробел */
	strcat_s(result, result_size, " "); // фамилия + пробел + имя + пробел

	/* скопировать в результирующий массив отчество */
	strcat_s(result, result_size, pname); // фамилия + пробел + имя + пробел + отчество

	cout << result << endl;

	return 0;
}
#endif

#if 0
// поиск символа в строке
int main() {
	char* filename = new char[128];
	cin.getline(filename, 128);

	/* поиск '.' в строке filename  */
	char* substring = strchr(filename, '.'); // my_file.txt\0

	/* если точка найдена - у введенного имени файла есть расширение  */
	if (substring) // char * -> int -> bool 
	{
		cout << "File has extension!" << endl;
	}

	/* иначе добавить расширение .TXT к строке filename  */
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

#if 1
#include <string.h>
int main() {
	char* filename = new char[128];
	cin.getline(filename, 128);

	/* поиск строки ".txt" в строке filename  */
	char* substring = strstr(filename, ".txt"); // my_file.txt\0

	/* eсли .txt найдено в строке filename - substring содержит указатель на подстроку .txt из строки filename  */
	if (substring) // char * -> int -> bool 
	{
		cout << "File has extension!" << endl;
	}

	/* иначе заменить расширение введенного имени файла в строке filename на .txt */
	else
	{
		// my_file\0.mp3

		/* найти символ точки и заменить его на терминирующий ноль - таким образом передвинув конец строки на найденную точку (обрезка my_file.mp3\0 до my_file\0) */
		/* если точки не найдено - заменять ничего не надо */
		substring = strchr(filename, '.');
		if (substring)
			*substring = '\0'; // удалить любое другое расширение

		cout << "Cutted string " << filename << endl;

		/* добавить к filename строку .txt */
		strcat_s(filename, 128, ".txt");
	}

	cout << "File name is " << filename << endl;
	cout << "Substring " << substring << endl;
	delete[] filename;
	return 0;
}
#endif


