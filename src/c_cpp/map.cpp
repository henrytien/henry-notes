
#include "ac.h"

int main() {
    map<int,int> mp;
    mp.insert({2,3});
    mp.insert({3,4});
    mp.insert({6,2});


    for (map<int,int>::iterator it = mp.begin(); it!=mp.end();) {
        if (it->second == 2) {
            mp.erase(it++);
        } else {
            ++it;
        }
    }
}