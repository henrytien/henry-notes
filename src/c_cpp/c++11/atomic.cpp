//
// Created by Henry on 2020-08-26.
//

#include "ac.h"
#include <atomic>
#include <thread>
struct AtomicCounter {
    std::atomic<int> value;

    AtomicCounter() : value(0) {}
    void increment(){
        ++value;
    }

    void decrement(){
        --value;
    }

    int get(){
        return value.load();
    }
};


int main() {
    AtomicCounter counter;
    counter.increment();
    cout << counter.get() << endl;

    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.push_back(std::thread([&counter](){
            for (int i = 0; i < 500; ++i) {
                counter.increment();
            }
        }));
    }

    for(auto& thread : threads) {
        thread.join();
    }

    std::cout << counter.get() << std::endl;
    return  0;
}