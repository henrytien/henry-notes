#include <iostream>
#include <vector>

/* 
 * Observer
 * defines an updating interface for objects that should be notified 
 * of changes in a subject.
 */
class Subject;
class Observer
{
public:
    Observer() {}
    virtual ~Observer() {}
    virtual int GetState() = 0;
    virtual void Update(Subject *subject) = 0;
};

/* 
 * Concrete Observer
 * stores state of the ConcreteObserver objects and sends 
 * a notifacation to its observers when its state changes
 */
class ConcreteObserver : public Observer
{
public:
    ConcreteObserver(const int state) : concrete_state_(state) {}
    ~ConcreteObserver() {}

    int GetState()
    {
        return concrete_state_;
    }
    void Update(Subject *subject);

private:
    int concrete_state_;
};

/* 
 * Subject
 * knows it's observers and provides an interface for attaching and 
 * detaching observers.
 */

class Subject
{
public:
    Subject() {}
    virtual ~Subject() {}
    void Attach(Observer *ob)
    {
        observers_.push_back(ob);
    }

    void Detach(const int index)
    {
        if (index < 0 || index > observers_.size())
        {
            return;
        }
        observers_.erase(observers_.begin() + index);
    }

    void Notify()
    {
        for (size_t i = 0; i < observers_.size(); ++i)
        {
            observers_.at(i)->Update(this);
        }
    }

    virtual int GetState() = 0;
    virtual void SetState(const int s) = 0;

private:
    std::vector<Observer *> observers_;
};

void ConcreteObserver::Update(Subject *subject)
{
    if (NULL == subject)
    {
        return;
    }
    concrete_state_ = subject->GetState();
    std::cout << "Observer state updated." << std::endl;
}

/*
 * Concrete Subject 
 * stores state that should stay consistent with the subject's
 */

class ConcreteSubject : public Subject
{
public:
    ConcreteSubject() {}
    ~ConcreteSubject() {}
    void SetState(const int s)
    {
        subject_state_ = s;
    }

    int GetState()
    {
        return subject_state_;
    }

private:
    int subject_state_;
};

int main()
{
    ConcreteObserver observer1(1);
    ConcreteObserver observer2(2);

    std::cout << "Observer1's state: " << observer1.GetState() << std::endl;
    std::cout << "Observer2's state: " << observer2.GetState() << std::endl;

    Subject *subject = new ConcreteSubject;
    subject->Attach(&observer1);
    subject->Attach(&observer2);
    subject->SetState(20);
    subject->Notify();

    std::cout << "Observer1's state: " << observer1.GetState() << std::endl;
    std::cout << "Observer2's state: " << observer2.GetState() << std::endl;

    delete subject;
    return 0;
}