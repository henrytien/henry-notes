<!-- TOC -->

- [Design Patterns](#design-patterns)
- [Creational pattern](#creational-pattern)
  - [Abstract factory](#abstract-factory)
    - [Usage](#usage)
  - [Builder](#builder)
    - [Applicability](#applicability)
  - [Factory Method](#factory-method)
    - [Applicability](#applicability-1)
    - [When to use](#when-to-use)
  - [Prototype](#prototype)
    - [Applicability](#applicability-2)
  - [Singleton](#singleton)
    - [Applicability](#applicability-3)
    - [HeadFirst](#headfirst)
- [Structural](#structural)
  - [Adapter pattern](#adapter-pattern)
    - [Definition](#definition)
    - [Applicability](#applicability-4)
  - [Decorator](#decorator)
    - [Applicability](#applicability-5)
  - [Bridge](#bridge)
    - [Applicability](#applicability-6)
    - [Consequences](#consequences)
  - [Composite](#composite)
    - [Applicability](#applicability-7)
    - [Consequences](#consequences-1)
  - [FACADE](#facade)
    - [Intent](#intent)
    - [Applicability](#applicability-8)
    - [Consequences](#consequences-2)
    - [Related Patterns](#related-patterns)
  - [Proxy](#proxy)
    - [Intent](#intent-1)
    - [Applicability](#applicability-9)
    - [Consequences](#consequences-3)
    - [Relate Pattrns](#relate-pattrns)
- [Behavioral Patterns](#behavioral-patterns)
  - [Obeserver](#obeserver)
    - [Applicability](#applicability-10)
  - [Strategy](#strategy)
    - [Intent](#intent-2)
    - [Applicability](#applicability-11)
    - [Consquences](#consquences)
- [Reference](#reference)

<!-- /TOC -->
# Design Patterns

> In software engineering, a software design pattern is a general, reusable solution to a commonly occurring problem within a given context in software design. It is not a finished design that can be transformed directly into source or machine code. Rather, it is a description or template for how to solve a problem that can be used in many different situations. Design patterns are formalized best practices that the programmer can use to solve common problems when designing an application or system.

# Creational pattern
> In software engineering, creational design patterns are design patterns that deal with object creation mechanisms, trying to create objects in a manner suitable to the situation. The basic form of object creation could result in design problems or in added complexity to the design. Creational design patterns solve this problem by somehow controlling this object creation.  

## Abstract factory

### Usage
> The client code has no knowledge whatsoever of the concrete type, not needing to include any header files or class declarations related to it. The client code deals only with the abstract type. Objects of a concrete type are indeed created by the factory, but the client code accesses such objects only through their abstract interface.[7]
Adding new concrete types is done by modifying the client code to use a different factory, a modification that is typically one line in one file. The different factory then creates objects of a different concrete type, but still returns a pointer of the same abstract type as before — thus insulating the client code from change. This is significantly easier than modifying the client code to instantiate a new type, which would require changing every location in the code where a new object is created (as well as making sure that all such code locations also have knowledge of the new concrete type, by including for instance a concrete class header file). If all factory objects are stored globally in a singleton object, and all client code goes through the singleton to access the proper factory for object creation, then changing factories is as easy as changing the singleton object.[7]

##  Builder

### Applicability
Use the Builder pattern when
- the algorithm for creating a complex object should be independent of the parts that make up the object and how they're assembled.
- the construction process must allow different representations for the object that's constructed.

## Factory Method
Define an interface for creating an object, but let subclasses decide which class to instantiate. Factory Method lets a class defer instantiation to subclasses.

### Applicability
Use the Factory Method pattern when
• aclasscan'tanticipatetheclassofobjectsitmustcreate.
• aclasswantsitssubclassestospecifytheobjectsitcreates.
• classes delegate responsibility to one of several helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate.

### When to use

* a class cant anticipate the class of objects it must create
* a class wants its subclasses to specify the objects it creates
* classes delegate responsibility to one of several helper subclasses, and you want to localize the knowledge of which helper subclass is the delegate


## Prototype

Specify the kinds of objects to create using a prototypical instance, and create 
new objects by copying this prototype. when the classes to instantiate are 
specified at run-time, for example, by dynamic loading;

### Applicability

• when the classes to instantiate are specified at run-time, for example, by dynamic loading; or
• to avoid building a class hierarchy off actories that parallels the class hierarchy of products; or
• when instances of a class can have one of only a few different combinations of state. It may be more convenient to install a corresponding number of prototypes and clone them rather than instantiating the class manually, each time with the appropriate state.

## Singleton
Ensure a class only has one instance, and provide a global point of access to it.

A better solution is to make the class itself responsible for keeping track of its sole instance. The class can ensure that no other instance can be created (by intercepting requests to create new objects), and it can provide a way to access the instance. This is the Singleton pattern.
### Applicability
• there must be exactly one instance of a class, and it must be accessible to clients from a well-known access point.
• when the sole instance should be extensible by subclassing, and clients should be able to use an extended instance without modifying their code.


• Singleton
- defines an Instance operation that lets clients access its unique instance. Instance is a class operation (that is, a class method in Smalltalk and a static member function in C++).
- may be responsible for creating its own unique instance.

More flexible than class operations. Another way to package a singleton's func- tionality is to use class operations (that is, static member functions in C++ or class methods in Smalltalk). But both of these language techniques make it hard to change a design to allow more than one instance of a class. Moreover, static member functions in C++ are never virtual, so subclasses can't override them polymorphically.

### HeadFirst
Well, here’s one example: if you assign an object to a global variable, then that object might be created when your application begins. Right? What if this object is resource intensive and your application never ends up using it? As you will see, with the Singleton Pattern, we can create our objects only when they are needed. p170

Singleton: Oh, I’m good for all kinds of things. Being single sometimes has its advantages you
know. I’m often used to manage pools of resources, like connection or thread pools.

Singleton: Of course not. The truth be told... well, this is getting kind of personal but... I have no public constructor.

So my class has a static method called getInstance(). 

The Singleton Pattern ensures a class has only one instance, and provides a global point of access to it.
 
# Structural
## Adapter pattern

In software engineering, the adapter pattern is a software design pattern (also known as wrapper, an alternative naming shared with the decorator pattern) that allows the interface of an existing class to be used as another interface.[1] It is often used to make existing classes work with others without modifying their source code.

### Definition
An adapter allows two incompatible interfaces to work together. This is the real-world definition for an adapter. Interfaces may be incompatible, but the inner functionality should suit the need. The adapter design pattern allows otherwise incompatible classes to work together by converting the interface of one class into an interface expected by the clients.


### Applicability
Use the Adapter pattern when
- you want to use an existing class, and its interface does not match the one you need.
-  youwanttocreateareusableclassthatcooperateswithunrelatedorunfore- seen classes, that is, classes that don't necessarily have compatible interfaces.
- (object adapter only) you need to use several existing subclasses, but it's un- practical to adapt their interface by subclassing every one. An object adapter can adapt the interface of its parent class.


## Decorator
Attach additional responsiblities to an object dynamiclly. Decorators provide a flexiable alternative to subclassing for extending functionality. 

The Decorator pattern has at least two key benefits and two liabilities:

### Applicability
• to add responsibilities to individual objects dynamically and transparently, that is, without affecting other objects.
• for responsibilities that canbe withdrawn.
• when extension by subclassing is impractical. Sometimes a large number of independent extensions are possible and would produce an explosion of subclasses to support every combination. Or a class definition maybe hidden or otherwise unavailable for subclassing.

## Bridge
Decouple an abstraction from its implementation so that the two can vary inde-pendently.

### Applicability
Use the Bridge pattern when
- when the implementation must be selected or switched at run-time.

- the Bridge pattern lets you combine the different abstractions and implementations and extend them independently.

- changes in the implementation of an abstraction should have no impact on clients; that is, their code should not have to be recompiled.

- you want to share an implementation among multiple objects(perhaps using reference counting)
### Consequences
1. Decoupling interface and implementation. 
2. Improved extensibility. 
3. Hiding implementation details from clients.

## Composite
Compose objects into tree structures to represent part-whole hierarchies. Com- posite lets clients treat individual objects and compositions of objects uniformly.

### Applicability
Use the Composite pattern when
• you want to represent part-whole hierarchies ofobjects.
• youwantclientstobeabletoignorethedifferencebetweencompositionsof objects and individual objects. Clients will treat all objects in the composite structure uniformly.

### Consequences
1. Defines class hierarchies consisting of primitive objects and composite ob- jects. 
2. Makes it easier to add new kinds of components. 
3. Can make your design overly general.

## FACADE
### Intent
Provide a unified interface to a set of interfaces in a subsystem. Facade defines a higher-level interface that makes the subsystem easier to use.

### Applicability
Use the Facade pattern when
- You want to provide a simple interface to a complex subsystem.
- You want to layer your subsystems.
  
### Consequences
The Facade pattern offers the following benefits:
1. It shields clients from subsystem components, thereby reducing the number of objects that clients deal with and making the subsystem easier to use. 
2. It promotes week compuling between the subsystem and its clients.
3. Reducing complition dependencies is vital in large software systems.
  
### Related Patterns
1. Abstract Factory can also be used as an alternative to Facade to hide platform-specific classes.
2. Mediator's purpose is to abstract arbitrary communication be- tween colleague objects.
3. Thus Facade objects are often singletons.

## Proxy

### Intent
Provide a surrogate or placeholder for another object to control access to it.

### Applicability
1. A remote proxy provides a local representative for an object in a different address space.
2. A virtual proxy creates expensive objects on demand.
3. A protection proxy controls access to the original object. Protection proxies are useful when objects should have different access rights. 
4. A smart reference is a replacement for a bare pointer that performs addtional actions when an object is accessed.

### Consequences
1. The proxy behaves just like a pointer.
2. Overloading the member access operator isn't a good solution for every kind of proxy.
3. A server creates proxies for remote objects when clients request them. On receiving a message, the proxy encodes it along with its arguments and then forwards the encoded message to the remote subject. 

### Relate Pattrns
1. Adapter: a proxy provides the same interface as its subject, In contrast, an adapter provides a different interface to the object it adates.
2. Decorator: a decorator adds one or more responsi- bilities to an object, whereas a proxy controls access to an object.


# Behavioral Patterns
Behavioral patterns are concerned with algorithms and the assignment of responsibili- ties between objects. Behavioral patterns describe not just patterns of objects or classes but also the patterns of communication between them.

## Obeserver 
Define a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically. like Dependents, Publish-Subscribe.

### Applicability
Use the Observer pattern in any of the following situations:
• When an abstraction has two aspects, one dependent on the other. Encapsu- lating these aspects in separate objects lets you vary and reuse them inde- pendently.
• When a change to one object requires changing others, and you don't know how many objects need to be changed.
• When an object should be able to notify other objects without making as- sumptions about who these objects are. In other words, you don't want these objects tightly coupled.

## Strategy
### Intent
Define a family of algorithms, encapsulate each one, and make them interchange- able. Strategy lets the algorithm vary independently from clients that use it.

### Applicability
- many related classes differ only in their behavior.
- you need different variants of an algorithm.

### Consquences
1. Families of related algorithms.
2. An alternative to subclassing.
3. Strategies eliminate conditional statements.
4. The pattern has a potential draw- back in that a client must understand how Strategies differ before it can select the appropriate one. 
5. A choice of implementations. 
6. Increased number of objects. 
7. Communication overhead between Strategy and Context. 





# Reference

- [C++ Design Patterns](https://github.com/JakubVojvoda/design-patterns-cpp)
- [Wikipedia](https://en.wikipedia.org/wiki/Design_Patterns)
- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)