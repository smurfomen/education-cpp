#include <iostream>
#include <string>

using namespace std;

/* Меняем строку s - все ' ' на '\t' */
/*	Сигнатура функции легко трансформируется в тип указателя на эту функцию:

	Сигнатура: возвращаемый_тип имя_функции (типы аргументов)
			   void replace_v1(char*,char,char)

	Указатель на функцию:
			   возвращаемый_тип(*имя_указателя)(типы аргументов)
			   void(*имя_указателя)(char*,char,char) = replace_v1;
 */
void replace_v1(char* s, char c1, char c2) {
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == c1) {
			s[i] = c2;
		}
	}
}

/* Возвращаем новую строку s - где все ' ' заменены на '\t'
	replace_v2("Hello", 'l', 'v')
*/
char* replace_v2(const char* s, char c1, char c2) {
	char* result = new char[strlen(s) + 1];
	int i = 0;
	for (; s[i] != '\0'; ++i) {
		/*
			если(текущий символ == ' ')
				добавить '\t'
			иначе
				скопировать текущий символ
		*/
		if (s[i] == c1)
			result[i] = c2;
		else
			result[i] = s[i];
	}

	result[i] = '\0';
	return result;
}

/* подсчет количества слов в строке  */
int count_words(const char* s) {
	/* на случай если длина строки 0 - слов тоже 0 */
	if (!strlen(s))
		return 0;

	/* считаем пробелы в строке */
	int counter = 0;
	for (int i = 0; s[i] != 0; ++i) {
		if (s[i] == ' ')
			counter++;
	}

	/*
	   если последний символ это пробел - вернуть количество посчитанных пробелов
	   Например: "Hello " - колво пробелов 1, колво слов 1
	*/
	if (s[strlen(s) - 1] == ' ')
		return counter;

	/* иначе если последний символ был частью слова - возвращаем количество пробелов + 1 */
	return counter + 1;
}

/* Возвращает true в случае если строка это палиндром("121", "nan", "довод", "tenet") */
bool is_palindrome(const char* s) {
	int len = strlen(s);
	if (len == 0)
		return false;
	if (len == 1)
		return true;

	/* индекс начала строки */
	int begin = 0;

	/* индекс конца строки */
	int end = strlen(s) - 1;

	while (begin <= end) {
		if (s[begin++] != s[end--])
			return false;
	}

	return true;
}


#include <cassert>
int main()
{
#if 0
	setlocale(LC_ALL, "Rus");
	{
		char str[] = "hello dude";
		cout << str << " | replaced all d to p: ";
		replace_v1(str, 'd', 'p');
		cout << str << endl;
	}

	{
		char str[] = "hello dude";
		cout << str << endl;
		char c1, c2;
		cout << "Что меняем?"; cin >> c1;
		cout << endl << "На что меняем?"; cin >> c2;
		cout << endl;
		char* ptr = replace_v2(str, c1, c2);
		cout << ptr << endl;

		delete[] ptr;
	}
#endif

	{
		/* true cases */
		assert(is_palindrome("121"));
		assert(is_palindrome("nan"));
		assert(is_palindrome("tenet"));
		assert(is_palindrome(" 121 "));
		assert(is_palindrome("2"));

		/* false cases */
		assert(!is_palindrome("123"));
		assert(!is_palindrome("abs"));
		assert(!is_palindrome("abbbas"));

		cout << "Tests passed!" << endl;
	}

	return 0;
}
