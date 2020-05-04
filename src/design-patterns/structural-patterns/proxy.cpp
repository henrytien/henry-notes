#include <iostream>
/*
 * Subject
 * defines the common interface for RealSubject and Proxy
 * so that a Proxy can be used anywhere a RealSubject is expected
 */
class Subject
{
public:
    virtual ~Subject() {}

    virtual void Request() = 0;
};

/* Real Subject
 * defines the real object that the proxy represents
 */

class RealSubject : public Subject
{
public:
    void Request()
    {
        std::cout << "Real Subject request" << std::endl;
    }
};

/* Proxy 
 * maintains a reference that lets the proxy access the real subject.
 */

class Proxy : public Subject
{
public:
    Proxy()
    {
        real_subject_ = new RealSubject;
    }
    void Request()
    {
        real_subject_->Request();
    }

    ~Proxy()
    {
        delete real_subject_;
    }

private:
    RealSubject *real_subject_;
};

int main()
{
    Proxy *proxy = new Proxy;
    proxy->Request();

    delete proxy;
    return 0;
}