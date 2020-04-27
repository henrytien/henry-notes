#include <iostream>
#include <string>
using namespace std;

class Wheel
{
public:
    Wheel() {}
    ~Wheel() {}
    int size;
};

class Engine
{
public:
    Engine() {}
    ~Engine() {}
    int horsepower;
};

class Body
{
public:
    Body() {}
    ~Body() {}
    string shape;
};

class Car
{
public:
    Car() {}
    ~Car() {}

    Wheel *wheels[4];
    Engine *engine;
    Body *body;
    void specifications()
    {
        cout << "Body: " << body->shape << endl;
        cout << "Engine Horsepower: " << engine->horsepower << endl;
        cout << "Tire Size: " << wheels[0]->size << endl;
    }
};

class Builder
{
public:
    virtual Wheel *getWhell() = 0;
    virtual Engine *getEngine() = 0;
    virtual Body *getBody() = 0;
};

class JeepBuilder : public Builder
{
public:
    Wheel *getWhell()
    {
        Wheel *wheel = new Wheel();
        wheel->size = 20;
        return wheel;
    }

    Engine *getEngine()
    {
        Engine *engine = new Engine();
        engine->horsepower = 520;
        return engine;
    }

    Body *getBody()
    {
        Body *body = new Body();
        body->shape = "SUV";
        return body;
    }
};

class Ferrari : public Builder
{
public:
    Wheel *getWhell()
    {
        Wheel *wheel = new Wheel();
        wheel->size = 20;
        return wheel;
    }

    Engine *getEngine()
    {
        Engine *engine = new Engine();
        engine->horsepower = 5200;
        return engine;
    }

    Body *getBody()
    {
        Body *body = new Body();
        body->shape = "Supper Car";
        return body;
    }
};

class Director
{
public:
    void setBuilder(Builder *newBuilder)
    {
        builder = newBuilder;
    }

    Car *getCar()
    {
        Car *new_car = new Car();
        new_car->body = builder->getBody();
        new_car->engine = builder->getEngine();
        new_car->wheels[0] = builder->getWhell();
        new_car->wheels[1] = builder->getWhell();
        new_car->wheels[2] = builder->getWhell();
        new_car->wheels[3] = builder->getWhell();

        return new_car;
    }

public:
    Builder *builder;
};

int main()
{
    Car *car;
    Director director;
    JeepBuilder jeepBuilder;
    Ferrari ferrari;

    cout << "Jeep" << endl;
    director.setBuilder(&jeepBuilder);
    car = director.getCar();
    car->specifications();

    cout << "Ferrari" << endl;
    director.setBuilder(&ferrari);
    car = director.getCar();
    car->specifications();

    delete car;
    return 0;
}