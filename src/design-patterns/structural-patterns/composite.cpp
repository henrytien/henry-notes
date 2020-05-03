#include <iostream>
#include <vector>

/*
 * Component
 * defines an interface for all objects in the composition
 * both the composite and the leaf nodes
 */
class Component
{
public:
    Component() {}
    virtual ~Component() {}
    virtual Component *GetChild(int)
    {
        return 0;
    }
    virtual void Add(Component *) {}
    virtual void Remove(int) {}
    virtual void Operation() = 0;
};

/*
 * Composite
 * defines behavior of the components having children 
 * and store child components
 */
class Composite : public Component
{
public:
    Composite() {}
    ~Composite()
    {
        for (unsigned int i = 0; i < children_.size(); ++i)
        {
            delete children_[i];
        }
    }

    void Add(Component *compoent)
    {
        children_.push_back(compoent);
    }

    void Remove(int index)
    {
        if (index < 0 || children_.size() < index)
        {
            std::cout << "index error" << std::endl;
            return;
        }
        Component *child = children_[index];
        children_.erase(children_.begin() + index);
        delete child;
    }

    void Operation()
    {
        for (unsigned int i = 0; i < children_.size(); i++)
        {
            children_[i]->Operation(); // pure virtual function
        }
    }

private:
    std::vector<Component *> children_;
};

/*
 * Leaf
 * defines the behavior for the elements in the composition,
 * it has no children
 */

class Leaf : public Component
{
public:
    Leaf(const int i) : id_(i) {}
    ~Leaf() {}
    void Operation(){
        std::cout << "Leaf " << id_ << " operation." << std::endl;
    }
private:
    int id_;
};

int main()
{
    Composite composite;
    for (unsigned int i = 0; i < 5; ++i)
    {
        composite.Add(new Leaf(i));
    }

    composite.Remove(0);
    composite.Operation();
    

    return 0;
}