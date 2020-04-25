#include <iostream>

class ProductA
{
public:
    virtual ~ProductA() {}
    virtual const char *getName() = 0;
    // ...
};

class ConcreteProductAX : public ProductA
{
private:
    /* data */
public:
    ConcreteProductAX() {}
    ~ConcreteProductAX() {}
    const char *getName()
    {
        return "A-X";
    }
};

class ConcreteProductAY : public ProductA
{
private:
    /* data */
public:
    ConcreteProductAY() {}
    ~ConcreteProductAY() {}
    const char *getName()
    {
        return "A-Y";
    }
};

/*
 * Product B
 * same as Product A, Product B declares interface for concrete products
 * where each can produce an entire set of products
 */
class ProductB
{
public:
    virtual ~ProductB() {}

    virtual const char *getName() = 0;
    // ...
};

/*
 * ConcreteProductBX and ConcreteProductBY
 * same as previous concrete product classes
 */
class ConcreteProductBX : public ProductB
{
public:
    ~ConcreteProductBX() {}

    const char *getName()
    {
        return "B-X";
    }
    // ...
};

class ConcreteProductBY : public ProductB
{
public:
    ~ConcreteProductBY() {}

    const char *getName()
    {
        return "B-Y";
    }
    // ...
};

/*
 * Abstract Factory
 * provides an abstract interface for creating a family of products
 */
class AbstractFactory
{
private:
    /* data */
public:
    virtual ~AbstractFactory(){};

    virtual ProductA *createProductA() = 0;
    virtual ProductB *createProductB() = 0;
};

/*
 * Concrete Factory X and Y
 * each concrete factory create a family of products and client uses
 * one of these factories so it never has to instantiate a product object
 */

class ConcreteFactoryX : public AbstractFactory
{
private:
    /* data */
public:
    ConcreteFactoryX(/* args */){}
    ~ConcreteFactoryX(){};
    ProductA *createProductA()
    {
        return new ConcreteProductAX();
    }
    ProductB *createProductB()
    {
        return new ConcreteProductBX();
    }
};

class ConcreteFactoryY : public AbstractFactory
{
private:
    /* data */
public:
    ConcreteFactoryY(/* args */){}
    ~ConcreteFactoryY(){};
    ProductA *createProductA()
    {
        return new ConcreteProductAY();
    }
    ProductB *createProductB()
    {
        return new ConcreteProductBY();
    }
};

int main()
{
    ConcreteFactoryX *factoryX = new ConcreteFactoryX();
    ConcreteFactoryY *factoryY = new ConcreteFactoryY();

    ProductA *p1 = factoryX->createProductA();
    std::cout << "Product: " << p1->getName() << std::endl;

    ProductA *p2 = factoryY->createProductA();
    std::cout << "Product: " << p2->getName() << std::endl;

    delete p1;
    delete p2;

    delete factoryX;
    delete factoryY;

    return 0;
}
