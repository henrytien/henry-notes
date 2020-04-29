#include <iostream>
/* 
 * Implementor
 * defines the interface for implementation classes
 */

class Implementor
{
public:
    Implementor() {}
    virtual ~Implementor() {}
    virtual void Action() = 0;
};

/* 
 * Concrete Implementors
 * implement the Implementor interface and define concrete implementations
 */
class ConcreteImplementorA : public Implementor
{
public:
    ConcreteImplementorA() {}
    ~ConcreteImplementorA() {}

    void Action()
    {
        std::cout << "Concrete ImplementorA " << std::endl;
    }
};

class ConcreteImplementorB : public Implementor
{
public:
    ConcreteImplementorB() {}
    ~ConcreteImplementorB() {}

    void Action()
    {
        std::cout << "Concrete ImplementorB " << std::endl;
    }
};

/*
 * Abstraction
 * defines an abstraction's interface
 */
class Abstraction
{
public:
    Abstraction() {}
    virtual ~Abstraction() {}
    virtual void Operation() = 0;
};

/* 
 * RefinedAbstraction
 * extends the interface defined by Abstraction
 */
class RefinedAbstraction : public Abstraction
{
public:
    RefinedAbstraction(Implementor *impl) : implementor_(impl) {}
    ~RefinedAbstraction() {}
    void Operation()
    {
        implementor_->Action();
    }

private:
    Implementor *implementor_;
};

int main()
{
    Implementor *ia = new ConcreteImplementorA;
    Implementor *ib = new ConcreteImplementorB;

    Abstraction *abstract1 = new RefinedAbstraction(ia);
    abstract1->Operation();

    Abstraction *abstract2 = new RefinedAbstraction(ib);
    abstract2->Operation();
ß
    delete abstract1;
    delete abstract2;
    delete ia;
    delete ib;

    return 0;
}