#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
const char* my_file = "file.txt";


#if 0

/* распечатать файл */
void print_file(const char* str) {
    FILE* f = fopen(str, "r");
    if (f)
    {
        char line[128];
        while (!feof(f)) {
            fgets(line, 128, f);
            cout << line;
        }
        cout << endl;
        fclose(f);
    }
}

int main()
{
    FILE* f = fopen(my_file, "r");
    if (f) {
        cout << "File is open" << endl;
#if 0
        /* посимвольное чтение */
        while (!feof(f)) {
            cout << (char)fgetc(f);
        }
        cout << endl;
#endif

#if 0
        char line[128];
        /* построчное чтение */
        while (!feof(f)) {
            fgets(line, 128, f);
            cout << line;
        }
        cout << endl;

        fclose(f);
#endif
    }
    else
        cout << "File not open!" << endl;

    return 0;
}
#endif


#if 0
int main() {
#if 0
    /* w - перезапись содержимого */
    FILE* f = fopen(my_file, "w");
    if (f) {
        cout << "File is open" << endl;

        /* запись буфера в файл */
        char buf[] = "Hello";
        fwrite(buf, sizeof(char), sizeof(buf), f);

        fclose(f);
    }
#endif

#if 0
    /* а - дополнение к содержимому */
    FILE* f = fopen(my_file, "a");

    if (f) {
        cout << "File is open" << endl;

        char buf[] = "\nHello";
        fwrite(buf, 1, 7, f);

        fclose(f);

        print_file(my_file);
    }

#endif

    return 0;
}

#endif


#if 1
#include <fstream>
#include <string>

/* чтение из файла */
void read_file(const char * filepath) {
    ifstream f;
    f.open(filepath, ios::in);
    if (f.is_open()) {
        while (!f.eof()) {
            string s;
            f >> s;
            cout << s;
        }
        cout << endl;

        f.close();
    }
}

/* запись в файл */
void write_to_file(const char* filepath, string str) {
    ofstream f;
    f.open(filepath, ios::app);
    if (f.is_open()) {
        f << str;
        f.close();
    }
}

int main() {
    read_file(my_file);
    write_to_file(my_file, "Hi\n");
    read_file(my_file);

    return 0;
}

#endif
