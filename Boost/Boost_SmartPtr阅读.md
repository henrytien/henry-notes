# [Boost.SmartPtr: The Smart Pointer Library](https://www.boost.org/doc/libs/1_67_0/libs/smart_ptr/doc/html/smart_ptr.html#shared_ptr)

## Introduction
Smart pointer are objects which store pointers to dynamicallly allocated(heap) objects. They behave much like built-in C++ pointers except that they automatically delete the object pointed to at the appropriate time. Smart pointers are particularly useful in the face of exceptions as they ensure destruction of dynamically allocated objects. They can also be used to keep track of dynamically allocated objects shared by multiple owners.


This library provides six smart pointer class templates:
- scoped_ptr, used to contain ownership of a dynamically allocated object to the current scope;
- scoped_array， which provides scoped ownership for a dynamically allocated array;
- shared_ptr, a versatile tool for managing shared ownership of an object or array.
- weak_ptr, a non-owning observer to a shared_ptr-managed object that can be promoted temporarily to shared_ptr;
- insrusive_ptr, a pointer to objects with an embedded reference count;
- local_shared_ptr, providing shared ownership within s single thread.




## scoped_ptr

[使用参考](http://www.cnblogs.com/TianFang/archive/2008/09/15/1291050.html)
1. 不能转换所有权
2. 不能共享所有权
3. 不能管理数组对象

[Boost 中的智能指针](http://www.cnblogs.com/sld666666/archive/2010/12/16/1908265.html)