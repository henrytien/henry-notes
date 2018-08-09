1. new分配内存按照数据类型进行分配，malloc分配内存按照大小分配；  

2. new不仅分配一段内存，而且会调用构造函数，但是malloc则不会。new的实现原理？但是还需要注意的是，之前看到过一个题说int* p = new int与int* p = new int()的区别，因为int属于C++内置对象，不会默认初始化，必须显示调用默认构造函数，但是对于自定义对象都会默认调用构造函数初始化。

	```
	#include<iostream>
	using namespace std;
	
	int main()
	{
	   int *p  = new int();
	   cout << *p << endl; // 输出0 默认构造函数
	
	   int *q = new int;
	   cout << *q << endl; //输出一个很大的数
	
	   delete p;
	   delete q;
	   return 0;
	}
	
	```
  
3. new返回的是指定对象的指针，而malloc返回的是void*，因此malloc的返回值一般都需要进行类型转化；  
4. new是一个操作符可以重载，malloc是一个库函数；  
5. new分配的内存要用delete销毁，malloc要用free来销毁；delete销毁的时候会调用对象的析构函数，而free则不会；  
6. malloc分配的内存不够的时候，可以用realloc扩容。扩容的原理？new没用这样操作；  
7. new如果分配失败了会抛出bad_malloc的异常，而malloc失败了会返回NULL。因此对于new，正确的姿势是采用try…catch语法，而malloc则应该判断指针的返回值。为了兼容很多c程序员的习惯，C++也可以采用new nothrow的方法禁止抛出异常而返回NULL；  
8. new和new[]的区别，new[]一次分配所有内存，多次调用构造函数，分别搭配使用delete和delete[]，同理，delete[]多次调用析构函数，销毁数组中的每个对象。而malloc则只能sizeof(int) * n；  
9. 如果不够可以继续谈new和malloc的实现，空闲链表，分配方法(首次适配原则，最佳适配原则，最差适配原则，快速适配原则)。delete和free的实现原理，free为什么直到销毁多大的空间？ 

