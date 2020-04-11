[boost coroutine2](https://github.com/boostorg/coroutine2/blob/develop/example/fibonacci.cpp)

```
#include<cstdlib>
#include<iostream>
#include<boost/coroutine2/all.hpp>

int main()
{
    boost::coroutines2::coroutine<int>::pull_type source(
        [](boost::coroutines2::coroutine<int>::push_type &sink){
            int first = 1,second = 1;
            sink(first);
            sink(second);
            for(int i = 0; i < 8; ++i){
                int third = first + second;
                second = third;
                sink(third);
            }
        });
    for(auto i : source){
        std::cout << i << " ";
    }

    std::cout << "\nDone" << std::endl;
    return EXIT_SUCCESS;
}
```
> 协程与例程相对，从抽象的角度来说，例程只能进入一次并返回一次，而协程可能进入多次并返回多次。

**参考**  
[Boost coroutine 协程](https://blog.csdn.net/yhcfly/article/details/18368405)
