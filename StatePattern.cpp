#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

//state pattern
//we need to have a context that contain several state
//the context could have a lot of behaviors
//the context will behave differently in different state
//in order to avoid a lot of if-else
//the use case would be a vending machine, an ATM machine

class MachineState;
class OnState;
class OffState;

//machine "Has A" state
//another way of doing this would be have
//machine pre-store all the state
//so we are not creating and destroying them all the time
class Machine
{
public:
    Machine();
    shared_ptr<MachineState> state;
    void setState(shared_ptr<MachineState> s);
    //these are all the behavior of a machine
    //they are defined in all the state subclass
    void on();
    void off();
};

//super class State will define all the default behavior
class MachineState
{
public:
     virtual void on(Machine & machine)
    {
        cout << "Machine already on!" << endl;
    }

    virtual void off(Machine & machine)
    {
        cout << "Machine already off!" << endl;
    }
};

//OnState "Is A" State
//it will override the behavior that it needs to

//here we are passing in the machine
//we could have State store a pointer to the context(machine)
class OnState : public MachineState
{
public:
     virtual void off(Machine & machine);
};

class OffState : public MachineState
{
public:
      virtual void on(Machine & machine);
};

Machine::Machine()
{
    state = make_shared<OffState>();
}

void Machine::on()
{
    state.get()->on(*this);
}

void Machine::off()
{
    state.get()->off(*this);
}

void Machine::setState(shared_ptr<MachineState> s)
{
    state = s;
}

void OnState::off(Machine & machine)
{
    cout << "Turning machine off!" << endl;
    machine.setState(make_shared<OffState>());
}

void OffState::on(Machine & machine)
{
    cout << "Turning machine on!" << endl;
    machine.setState(make_shared<OnState>());
}

int main()
{
    cout << "Hello world!" << endl;

    Machine machine;
    machine.on();
    machine.on();
    machine.off();
    machine.off();
    machine.on();
    machine.off();
    machine.off();

    return 0;
}
