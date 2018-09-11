# c++ 11 review

## associate container

### unorder_map 

```cpp
#include <iostream>
#include <unordered_map>
#include <string>
using  namespace  std;

void foo()
{
	// Create an unordered_map of three strings (that map to strings)
	std::unordered_map<std::string, std::string> u = {
		{ "RED","#FF0000" },
		{ "GREEN","#00FF00" },
		{ "BLUE","#0000FF" }
	};

	// Iterate and print keys and values of unordered_map
	for (const auto& n : u) {
		std::cout << "Key:[" << n.first << "] Value:[" << n.second << "]\n";
	}

	// Add two new entries to the unordered_map
	u["BLACK"] = "#000000";
	u["WHITE"] = "#FFFFFF";

	// Output values by key
	std::cout << "The HEX of color RED is:[" << u["RED"] << "]\n";
	std::cout << "The HEX of color BLACK is:[" << u["BLACK"] << "]\n";

}

int main()
{
	foo();
	getchar();
	return 0;
}
```


## API

- insert_itrator
```cpp

void foo()
{
	vector<int> vec1 = { 4,5 };
	vector<int> vec2 = { 23,4,5,18 };
	vector<int>::iterator it = find(vec2.begin(), vec2.end(), 18);
	const insert_iterator<vector<int>> it1(vec2, it);
	copy(vec1.begin(), vec1.end(), it1);
	for (auto item : vec2)
		cout << item << endl;
}
```

