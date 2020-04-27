#include <iostream>
#include <string>

/* 
 * Product 
 * product implement the same interface so that class can refer
 * to the interface not the concerete product
 */
class Product
{
public:
    virtual ~Product() {}
    virtual std::string GetName() = 0;
};

/*
 * Concrete Product 
 * define product to be created
 */

class ConcereteProductA : public Product
{
    virtual ~ConcereteProductA() {}
    std::string GetName()
    {
        return "type A";
    }
};

/*
 * Concrete Product
 * define product to be created
 */
class ConcreteProductB : public Product
{
public:
    virtual ~ConcreteProductB() {}

    std::string GetName()
    {
        return "type B";
    }
    // ...
};

/*
 * Creator
 * contains the implementation for all of the methods 
 * to manipulate products except for the factory method
 */
class Creator
{
private:
public:
    Creator(){};
    virtual ~Creator() {}
    virtual Product *CreateProductA() = 0;
    virtual Product *CreateProductB() = 0;
    virtual void RemoveProduct(Product *product) = 0;
};

/*
 * Concrete Creator 
 * implements factory method that is responsible for creating 
 * one or more concrete products.
 */

class ConcreteCrator : public Creator
{
public:
    ConcreteCrator(){};
    ~ConcreteCrator(){};

    Product *CreateProductA()
    {
        return new ConcereteProductA();
    }

    Product *CreateProductB()
    {
        return new ConcreteProductB();
    }

    void RemoveProduct(Product *product)
    {
        delete product;
    }
};

int main()
{
    Creator *creator = new ConcreteCrator();
    Product *p1 = creator->CreateProductA();

    std::cout << "Product: " << p1->GetName() << std::endl;
    Product *p2 = creator->CreateProductB();

    std::cout << "Product: " << p2->GetName() << std::endl;
    creator->RemoveProduct(p2);

    delete creator;
    return 0;
}
