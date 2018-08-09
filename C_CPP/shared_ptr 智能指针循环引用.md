
## 智能指针的循环引用
[shared_ptr and weak_ptr differences](https://stackoverflow.com/questions/4984381/shared-ptr-and-weak-ptr-differences)

“循环引用”简单来说就是：两个对象互相使用一个shared_ptr成员变量指向对方的会造成循环引用。导致引用计数失效。下面给段代码来说明循环引用：
```
#include<iostream>
#include <memory>
using namespace std;
class B;
class A
{
public:// 为了省去一些步骤这里 数据成员也声明为public
    //weak_ptr<B> pb;
    shared_ptr<B> pb;
    void doSomthing()
    {
//        if(pb.lock())
//        {
//
//        }
    }

    ~A()
    {
        cout << "kill A\n";
    }
};

class B
{
public:
    //weak_ptr<A> pa;
    shared_ptr<A> pa;
    ~B()
    {
        cout <<"kill B\n";
    }
};

int main(int argc, char** argv)
{
    shared_ptr<A> sa(new A());
    shared_ptr<B> sb(new B());

    if(sa && sb)
    {
        sa->pb=sb;
        sb->pa=sa;
    }
    cout<<"sa use count:"<<sa.use_count()<<endl;
    return 0;
}

```

上面的代码运行结果为：sa use count:2， 注意此时sa,sb都没有释放，产生了内存泄露问题！！！
即A内部有指向B，B内部有指向A，这样对于A，B必定是在A析构后B才析构，对于B，A必定是在B析构后才析构A，这就是循环引用问题，违反常规，导致内存泄露。

一般来讲，解除这种循环引用有下面有三种可行的方法[参考](http://www.cnblogs.com/TianFang/archive/2008/09/20/1294590.html)

1. 当只剩下最后一个引用的时候需要手动打破循环引用释放对象。
2. 当A的生存期超过B的生存期的时候，B改为使用一个普通指针指向A。
3. 使用弱引用的智能指针打破这种循环引用。
虽然这三种方法都可行，但方法1和方法2都需要程序员手动控制，麻烦且容易出错。我们一般使用第三种方法：弱引用的智能指针weak_ptr。

**强引用和弱引用**
一个强引用当被引用的对象活着的话，这个引用也存在（就是说，当至少有一个强引用，那么这个对象就不能被释放）。share_ptr就是强引用。相对而言，弱引用当引用的对象活着的时候不一定存在。仅仅是当它存在的时候的一个引用。弱引用并不修改该对象的引用计数，这意味这弱引用它并不对对象的内存进行管理，在功能上类似于普通指针，然而一个比较大的区别是，弱引用能检测到所管理的对象是否已经被释放，从而避免访问非法内存。

## 使用weak_ptr来打破循环引用

```
#include <iostream>
#include <memory>
using namespace std;

class B;
class A
{
public:// 为了省去一些步骤这里 数据成员也声明为public
    weak_ptr<B> pb;
    //shared_ptr<B> pb;
    void doSomthing()
    {
        shared_ptr<B> pp = pb.lock();
        if(pp)//通过lock()方法来判断它所管理的资源是否被释放
        {
            cout<<"sb use count:"<<pp.use_count()<<endl;
        }
    }

    ~A()
    {
        cout << "kill A\n";
    }
};

class B
{
public:
    //weak_ptr<A> pa;
    shared_ptr<A> pa;
    ~B()
    {
        cout <<"kill B\n";
    }
};

int main(int argc, char** argv)
{
    shared_ptr<A> sa(new A());
    shared_ptr<B> sb(new B());
    if(sa && sb)
    {
        sa->pb=sb;
        sb->pa=sa;
    }
    sa->doSomthing();
    cout<<"sb use count:"<<sb.use_count()<<endl;
    return 0;
}

```
输出 
sb use count:2  
sb use count:1  
kill B  
kill A  

**补充**
weak_ptr除了对所管理对象的基本访问功能（通过get()函数）外，还有两个常用的功能函数：expired()用于检测所管理的对象是否已经释放；lock()用于获取所管理的对象的强引用指针。不能直接通过weak_ptr来访问资源。那么如何通过weak_ptr来间接访问资源呢？答案是：在需要访问资源的时候weak_ptr为你生成一个shared_ptr，shared_ptr能够保证在shared_ptr没有被释放之前，其所管理的资源是不会被释放的。创建shared_ptr的方法就是lock()方法。


