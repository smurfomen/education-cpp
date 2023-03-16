#include <iostream>
using namespace std;
#include <bitset>
#include <string>
template <typename T>
string to_bin(T v) {
    return bitset<sizeof(T) * 8>(v).to_string();
}

#if 0
// десятичные числа
// 32 = 3*10 + 2*1 = 32
// 132 = 1*10*10 + 3*10 * 2*1 = 1*100 + 3*10 * 2*1

// двоичные числа
// 1        [1]     = 2^0
// 10       [2]     = 2^1
// 11       [3]     = 2^1 + 2^0
// 111      [7]     = 2^2 + 2^1 + 2^0
// 1111     [15]    = 2^3(8) + 2^2(4) + 2^1(2) + 2^0(1)
// 100010   [34]    = 2^5(32) + 2^1(2)
// 11110000 [240]   = 2^7(128) + 2^6(64) + 2^5(32) + 2^4(16)
// 11111111 [255] (11110000 + 00001111) т.е. 240 + 15

// шестнадцатиричная система
// 0123456789ABCDEF
// 15  - 00001111   - 0x0F
// 240 - 11110000   - 0xF0
// 255 - 1111 1111  - 0xFF
// 0100 1100 0101   - 0x4С5 


/*
    двоичные операторы 
    & - побитовое И      (AND)
    | - побитовое ИЛИ    (OR)
    ^ - побитовое ИЛИ НЕ (XOR)
    ~ - побитовая инверсия
*/

/*
    Побитовое И (&)
     1 & 11 = 1
     00000001   - 1
     00000011   - 3
     --------
     00000001   - 1

     RAW DATA:          00000111
     MASK STATUS:       00000001
     MASK KEY:          00000010

     if(STATUS_IS_OK:   00000001 - 1 - true) {
        ...
     }
*/

/*
    Побитовое ИЛИ OR (|)
    1 | 11 = 1
    00000001    - 1
    00000011    - 3
    --------
    00000011    - 3


    STATUS_IS_OK:       00000001
    KEY_IS_OPEN:        00000010
    TESTS_IS_OK:        00000100
                        --------
                        00000111

    RAW DATA:          STATUS_IS_OK | KEY_IS_OPEN | TESTS_IS_OK : 00000111

    MASK STATE:        00000001
    if(STATE_IS_OK:    00000001 - 1 - true) {
        ...
    }
*/


/*
    XOR (ИЛИ НЕ) ^

    1 ^ 11 = 1
    00000001    - 1
    00000011    - 3
    --------
    00000010    - 2

    1001 ^ 1011 - 0010
*/

/*
    Инверсия (~) (НЕ)
    00001011
    --------
    11110100 


*/

/*
    Операторы сдвига ( << и >> )
    1 << 1 =    - 2
    00000001    - 1
    --------
    00000010    - 2

    0111 (7) << 1  = 1110 (14)
    7 << 1 = 14

    129 << 1    =
    10000001    - 129
    --------
    00000010    - 2
*/

/*
    функция, которая снимает(обнуляет) первый бит числа value,
    сохраняя остальные биты 
    Например: value -   00101101 
                        11111110
              output -  00101100
*/
uint8_t off_first_bit(uint8_t value) {
    return value & 0b11111110;
}

/* 
    функция, которая обнуляет биты числа value, выставленные 1 в mask,
    сохраняя остальные биты
    Например: value 00101101, mask 00100100, output - 00001001
                                  ~11011011

                                   00101101
                                   11011011
                                   --------
                                   00001001 - 9
    */
uint8_t off_bits(uint8_t value, uint8_t mask) {
    return value & ~mask;
}

uint8_t on_bits(uint8_t value, uint8_t mask) {
    return value | mask;
}



enum {
    STATUS_IS_OK = 1 << 0, // 0b001
    KEY_IS_OPEN  = 1 << 1, // 0b010
    TESTS_IS_OK  = 1 << 2, // 0b100
};

int main()
{
    cout << to_bin(off_bits(0b00101101, 0b00100100)) << endl;
    cout << to_bin(off_bits(0b00101101, STATUS_IS_OK | TESTS_IS_OK /*0b101*/)) << endl;
    return 0;
}

#endif

#if 0 
union UDigit {
    uint32_t value;
    uint8_t arr[4];
};

/*
    arr
    \
     |0|1|2|3|
    /
    value

    value = 0xff
    
    |0|0|0|255|
*/


int main() {
    cout << "size of UDigit " << sizeof(UDigit) << endl;
    UDigit d;
    d.value = 0; // 00000000000000000000000000000000
    d.arr[3] = 0b10000000; // 10000000 00000000 00000000 00000000
    cout << d.value << endl;
    for (int i = 0; i < 4; ++i) {
        cout << (int)d.arr[i] << endl;
    }

    return 0;
}
#endif


#if 0
union Byte {
    uint8_t value;
    struct BitField {
        uint8_t flags  : 3;  // = 0..7
        uint8_t ops    : 1;  // = 0..1
        uint8_t other  : 4;  // = 0..15
    } field;
} b;

void print() {
    cout << "Byte::value\t\t" << to_bin(b.value) << endl;
    cout << "Byte::BitField::flags\t" << to_bin(b.field.flags) << endl;
    cout << "Byte::BitField::ops\t" << to_bin(b.field.ops) << endl;
    cout << "Byte::BitField::other\t" << to_bin(b.field.other) << endl;
    cout << "-----------------------------" << endl;
}

int main() {  
    b.value = numeric_limits<uint8_t>::max();
    print();
    b.field.ops = 0;
    print();
    b.field.other = 0b0101;
    print();
    
    return 0;
}
#endif

