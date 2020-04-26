#include <iostream>
#include <map>
using namespace std;

//Problem with std::map::iterator after calling erase()
//https://stackoverflow.com/questions/4636182/problem-with-stdmapiterator-after-calling-erase

int main() {

    std::map<int,int> test_map;
    test_map.insert(pair<int,int>(2,4));
    test_map.insert(pair<int, int>(3, 60));
    test_map.insert(pair<int, int>(4, 20));
    test_map.insert(pair<int, int>(5, 50));
    test_map.insert(pair<int, int>(6, 50));
    test_map.insert(pair<int, int>(7, 10));

    std::cout << "Hello, World!" << std::endl;
    for (auto itc = test_map.begin(); itc != test_map.end();) {//todo.thy.? delete iter
        if (itc->second == 50) {
            test_map.erase(++itc);
        }
        ++itc;
    }
    return 0;
}