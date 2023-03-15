#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
namespace hardware {
    namespace registers {
        void set_reg(int addr);
        uint8_t get_reg_value(int addr);
    }

    void led_on();
    void led_off();
}

int main()
{
    hardware::registers::set_reg(2);
    cout << hardware::registers::get_reg_value(2) << endl;

    using namespace hardware::registers;
    using namespace hardware;

    for (;;) {
        if (get_reg_value(2))
            led_on();
        else
            led_off();
    }

    return 0;
}