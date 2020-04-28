#include <iostream>

/* 
 * Component
 * defines an interface for objects that can have responsiblities
 * added them dynamiclly.
 */
class Component
{
public:
    Component() {}
    virtual ~Component() {}
    virtual void operation() = 0;
};

/* Concrete Component
 * defines an object to which additional responsiiblities 
 * can be attached.
 */

class ConcreteComponent : public Component
{
public:
    ConcreteComponent() {}
    ~ConcreteComponent() {}

    void operation()
    {
        std::cout << "ConcreteComponent opereation" << std::endl;
    }
};

/* Decorator
 * maintains a reference to Compenent objects and 
 * defines an interface that can comforms to Component's interface 
 */
class Decorator : public Component
{
public:
    Decorator(Component *c) : component_(c) {}
    ~Decorator() {}

    virtual void operation()
    {
        component_->operation();
    }

private:
    Component *component_;
};

/* Concrete Decorators
 * add responsiblities to the compoent(can extend the state
 * of the component)
 */
class ConcreteDecoratorA : public Decorator
{
public:
    ConcreteDecoratorA(Component *c) : Decorator(c) {}
    void operation()
    {
        Decorator::operation();
        std::cout << " Decorator A" << std::endl;
    }
};

class ConcreteDecoratorB : public Decorator
{
public:
    ConcreteDecoratorB(Component *c) : Decorator(c) {}
    void operation()
    {
        Decorator::operation();
        std::cout << " Decorator B" << std::endl;
    }
};

int main()
{
    ConcreteComponent *cc = new ConcreteComponent;
    ConcreteDecoratorA *da = new ConcreteDecoratorA(cc);
    ConcreteDecoratorB *db = new ConcreteDecoratorB(da);

    Component *component = db;
    component->operation();
    delete cc;
    delete da;
    delete db;
    return 0;
}