### vector::emplace_back in C++ STL

emplace_back() vs push_back()
When we use push_back(), we create an object and then insert it into the vector. With emplace_back(), the object is constructed in-place and saves an unnecessary copy. Please see emplace vs insert in C++ STL for details.

```cpp
// C++ code to demonstrate difference between 
// emplace_back and insert_back 
#include<bits/stdc++.h> 
using namespace std; 
    
int main() 
{ 
    // declaring priority queue 
    vector<pair<char, int>> vect; 
        
    // using emplace() to insert pair in-place 
    vect.emplace_back('a', 24); 
        
    // Below line would not compile 
    // vect.push_back('b', 25);     
        
    // using push_back() to insert 
    vect.push_back(make_pair('b', 25));     
        
    // printing the vector 
    for (int i=0; i<vect.size(); i++) 
        cout << vect[i].first << " " << vect[i].second 
             << endl; 
   
    return 0; 
} 
```
[emplace_back](https://www.geeksforgeeks.org/vectoremplace_back-c-stl/)
