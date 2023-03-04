#include <iostream>
#include <string>

using namespace std;

/* ������ ������ s - ��� ' ' �� '\t' */
/*	��������� ������� ����� ���������������� � ��� ��������� �� ��� �������:

	���������: ������������_��� ���_������� (���� ����������)
			   void replace_v1(char*,char,char)

	��������� �� �������:
			   ������������_���(*���_���������)(���� ����������)
			   void(*���_���������)(char*,char,char) = replace_v1;
 */
void replace_v1(char* s, char c1, char c2) {
	for (int i = 0; s[i] != '\0'; ++i) {
		if (s[i] == c1) {
			s[i] = c2;
		}
	}
}

/* ���������� ����� ������ s - ��� ��� ' ' �������� �� '\t'
	replace_v2("Hello", 'l', 'v')
*/
char* replace_v2(const char* s, char c1, char c2) {
	char* result = new char[strlen(s) + 1];
	int i = 0;
	for (; s[i] != '\0'; ++i) {
		/*
			����(������� ������ == ' ')
				�������� '\t'
			�����
				����������� ������� ������
		*/
		if (s[i] == c1)
			result[i] = c2;
		else
			result[i] = s[i];
	}

	result[i] = '\0';
	return result;
}

/* ������� ���������� ���� � ������  */
int count_words(const char* s) {
	/* �� ������ ���� ����� ������ 0 - ���� ���� 0 */
	if (!strlen(s))
		return 0;

	/* ������� ������� � ������ */
	int counter = 0;
	for (int i = 0; s[i] != 0; ++i) {
		if (s[i] == ' ')
			counter++;
	}

	/*
	   ���� ��������� ������ ��� ������ - ������� ���������� ����������� ��������
	   ��������: "Hello " - ����� �������� 1, ����� ���� 1
	*/
	if (s[strlen(s) - 1] == ' ')
		return counter;

	/* ����� ���� ��������� ������ ��� ������ ����� - ���������� ���������� �������� + 1 */
	return counter + 1;
}

/* ���������� true � ������ ���� ������ ��� ���������("121", "nan", "�����", "tenet") */
bool is_palindrome(const char* s) {
	int len = strlen(s);
	if (len == 0)
		return false;
	if (len == 1)
		return true;

	/* ������ ������ ������ */
	int begin = 0;

	/* ������ ����� ������ */
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
		cout << "��� ������?"; cin >> c1;
		cout << endl << "�� ��� ������?"; cin >> c2;
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
