#include <iostream>

/* Subsystems
 * Implement more complex subsystem functionablity
 * and have no knowlege of facade 
 */

class SubsystemA
{
public:
    SubsystemA() {}
    ~SubsystemA() {}
    void SubOperation()
    {
        std::cout << "Subsystem A Operation " << std::endl;
    }
};

class SubsystemB
{
public:
    SubsystemB() {}
    ~SubsystemB() {}
    void SubOperation()
    {
        std::cout << "Subsystem B Operation " << std::endl;
    }
};

class SubsystemC
{
public:
    SubsystemC() {}
    ~SubsystemC() {}
    void SubOperation()
    {
        std::cout << "Subsystem C Operation " << std::endl;
    }
};

/* Facade 
 * delegates client requires to approciate subsystem object
 * and unified interface that is easier to use.
 */
class Facade
{
public:
    Facade() : subsystem_a_(), subsystem_b_(), subsystem_c_() {}
    void Operation1()
    {
        subsystem_a_->SubOperation();
        subsystem_b_->SubOperation();
    }

    void Operation2()
    {
        subsystem_c_->SubOperation();
    }

private:
    SubsystemA *subsystem_a_;
    SubsystemB *subsystem_b_;
    SubsystemC *subsystem_c_;
};

int main()
{
    Facade *facade = new Facade;
    facade->Operation1();
    facade->Operation2();

    delete facade;
    return 0;
}