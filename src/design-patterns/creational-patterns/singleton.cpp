#include <iostream>

/*
 * Singleton
 * has private static variable to hold one instance of the class 
 * and method which gives us a way to instantiate the class
 */

class Singleton
{
    // The copy constructor and assignment operator
    // are defined as deleted, which mean that you
    // can't make a copy of singleton.
    Singleton(Singleton const &) = delete;
    Singleton &operator=(Singleton const &) = delete;

private:
    Singleton() {}

public:
    static Singleton *getInstance()
    {
        if (_instance == NULL)
        {
            Singleton *instance = new Singleton;
            return instance;
        }
    }
    static void restart()
    {
        if (_instance)
        {
            delete _instance;
        }
    }

    void tell()
    {
        std::cout << " This is a singleton." << std::endl;
    }

private:
    static Singleton *_instance;
};

Singleton *Singleton::_instance = NULL;

int main()
{
    Singleton::getInstance()->tell();
    Singleton::restart();
    return 0;
}
