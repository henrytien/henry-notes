
# Design Patterns

> In software engineering, a software design pattern is a general, reusable solution to a commonly occurring problem within a given context in software design. It is not a finished design that can be transformed directly into source or machine code. Rather, it is a description or template for how to solve a problem that can be used in many different situations. Design patterns are formalized best practices that the programmer can use to solve common problems when designing an application or system.

# Creational pattern
> In software engineering, creational design patterns are design patterns that deal with object creation mechanisms, trying to create objects in a manner suitable to the situation. The basic form of object creation could result in design problems or in added complexity to the design. Creational design patterns solve this problem by somehow controlling this object creation.  

## Abstract factory

### Usage
> The client code has no knowledge whatsoever of the concrete type, not needing to include any header files or class declarations related to it. The client code deals only with the abstract type. Objects of a concrete type are indeed created by the factory, but the client code accesses such objects only through their abstract interface.[7]
Adding new concrete types is done by modifying the client code to use a different factory, a modification that is typically one line in one file. The different factory then creates objects of a different concrete type, but still returns a pointer of the same abstract type as before — thus insulating the client code from change. This is significantly easier than modifying the client code to instantiate a new type, which would require changing every location in the code where a new object is created (as well as making sure that all such code locations also have knowledge of the new concrete type, by including for instance a concrete class header file). If all factory objects are stored globally in a singleton object, and all client code goes through the singleton to access the proper factory for object creation, then changing factories is as easy as changing the singleton object.[7]





# Reference

- [C++ Design Patterns](https://github.com/JakubVojvoda/design-patterns-cpp)
- [Wikipedia](https://en.wikipedia.org/wiki/Design_Patterns)
- 