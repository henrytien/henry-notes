#include <iostream> 

/*
 * Target
 * defines specific interface that Client uses
 */
class Target
{
private:
    
public:
    Target(){}
    virtual ~Target(){};
    
    virtual void Request() = 0;
};


/*
 * Adaptee
 * all requests get delegated to the Adaptee which defines
 * an existing interface that needs appapting
 */
class Adaptee
{
private:
public:
    Adaptee(){};
    ~Adaptee(){};

    void SpecificRequest()
    {
        std::cout <<  "specific request" << std::endl;
    }
};

/*
 * Adapter
 * implements the Target interface and lets the Adaptee respond
 * to request on a Target by extending both classes 
 * ie. adapts the interfaces of Adaptee to the Target interface
 */

class Adapter : public Target, private Adaptee      
{
private:
    
public:
    Adapter(){};
    ~Adapter(){};

    virtual void Request()
    {
        SpecificRequest();
    }
    // ...
};

int main()
{
    Target *t = new Adapter();
    t->Request();
    delete t;
    return 0;
}

