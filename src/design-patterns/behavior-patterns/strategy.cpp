#include <iostream>

/*
 * Strategy
 * declares an interface common to all supported algorithms
 */
class Strategy
{
public:
    virtual ~Strategy() {}
    virtual void AlgorithmInterface() = 0;
};

/*
 * Concrete Strategies
 * implement the algorithm using the Strategy interface
 */
class ConcreteStrategyA : public Strategy
{
public:
    ~ConcreteStrategyA() {}

    void AlgorithmInterface()
    {
        std::cout << "Concrete Strategy A" << std::endl;
    }
};

class ConcreteStrategyB : public Strategy
{
public:
    ~ConcreteStrategyB() {}

    void AlgorithmInterface()
    {
        std::cout << "Concrete Strategy B" << std::endl;
    }
};

class ConcreteStrategyC : public Strategy
{
public:
    ~ConcreteStrategyC() {}

    void AlgorithmInterface()
    {
        std::cout << "Concrete Strategy C" << std::endl;
    }
};

/*
 * Context
 * maintains a reference to a Strategy object
 */
class Context
{
public:
    Context(Strategy *const s) : strategy_(s) {}

    ~Context()
    {
        delete strategy_;
    }

    void ContextInterface()
    {
        strategy_->AlgorithmInterface();
    }

private:
    Strategy *strategy_;
};

int main(){
    Context context = new ConcreteStrategyA();
    context.ContextInterface();
    return 0;
}


