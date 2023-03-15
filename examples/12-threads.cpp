
#include <thread>
#include <chrono>
#include <mutex>
mutex mtx;
void work_lock_guard() {
    for (int i = 0; i < 10; ++i) {
        {
            lock_guard<mutex> lck(mtx);
            cout << "WORK LG " << this_thread::get_id() << " " << i << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void work_uniq_lock() {
    unique_lock<mutex> lck(mtx);
    for (int i = 0; i < 10; ++i) {
        cout << "WORK UL " << this_thread::get_id() << " " << i << endl;
        if (i == 5)
            lck.unlock();
        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void work_raw_mutex() {
    for (int i = 0; i < 10; ++i) {
        mtx.lock();
        cout << "WORK RAW " << this_thread::get_id() << " " << i << endl;
        mtx.unlock();

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

void work_raw_mutex_try_lock() {
    if (mtx.try_lock())
    {
        for (int i = 0; i < 10; ++i) {
            cout << "WORK TL " << this_thread::get_id() << " " << i << endl;
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        mtx.unlock();
    }
}

int main() {
    auto t1 = chrono::system_clock::now();
    cout << thread::hardware_concurrency() << endl;
    thread th(work_uniq_lock);
    work_lock_guard();

    th.join();

    auto t2 = chrono::system_clock::now();

    cout << chrono::duration_cast<chrono::milliseconds>(t2 - t1).count() << endl;

    return 0;
}