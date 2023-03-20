#include <iostream>
#include <future>
#include <chrono>
#include <queue>
#include <functional>
#include <atomic>
using namespace std;

struct ThreadPool {
    thread th;
    mutex mtx;
    queue<function<void()>> tasks;
    atomic<bool> rqexit = false;

    ThreadPool() : th([&]() {
            while (!rqexit.load())
            {
                unique_lock<mutex> lck(mtx);
                if (!tasks.empty()) {
                    auto task = move(tasks.front());
                    tasks.pop();
                    lck.unlock();

                    task();
                }
            }
        })
    { }

    ~ThreadPool() {
        if (!rqexit.load()) {
            exit();
        }

        th.join();
    }

    void add_task(function<void()>&& t) {
        lock_guard<mutex> lck(mtx);
        tasks.push(t);
    }

    void exit() {
        rqexit.store(true);
    }
};


int main()
{
    auto t1 = []() {
        cout << "t1 begin" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "t1 ended" << endl;
    };

    auto t2 = []() {
        cout << "t2 begin" << endl;
        this_thread::sleep_for(chrono::milliseconds(750));
        cout << "t2 ended" << endl;
    };

    auto t3 = []() {
        cout << "t3 begin" << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << "t3 ended" << endl;
    };

    auto f = async(launch::async, []() -> int {
        this_thread::sleep_for(chrono::milliseconds(250));
        return 1024;
        });
    ThreadPool p;
    p.add_task(t1);
    p.add_task(t2);
    t3();

    cout << "future is " << f.get() << endl;

    return 0;
}
