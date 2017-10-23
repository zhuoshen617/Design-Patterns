#include <iostream>
#include <string>
#include <memory>
using namespace std;


//Builder Pattern (Has A)
//when you want to build an object which is made up from other set of objects
//this pattern usually are used together with template pattern as shown below
//we are building a Robot here
//the Robot is composed of a list of object(Head, body, Arms, Legs)
//we are clearly making use of "Has A" rules
//builder class encapsulate all the details of how to build a robot
//only builder knows how to build and no one else knows

class Robot
{
public:
    string head;
    string body;
    /*
    string arms;
    string legs;
    */
    Robot() {}

    void setHead(string h) {head = h;}
    void setBody(string b) {body = b;}

    void print()
    {
        cout << "My Head: " << head << endl;
        cout << "My Body: " << body << endl;
    }
};

class RobotBuilder
{
protected:
    Robot robot;
public:
    //template method here
    void buildRobot()
    {
        buildRobotHead();
        buildRobotBody();
        //buildRobotArms();
        //buildRobotLegs();
    }
    virtual void buildRobotHead() = 0;
    virtual void buildRobotBody() = 0;
    //void buildRobotArms();
    //void buildRobotLegs();

    Robot getRobot() { return robot;}
};

//"Is A"
//this is using the template pattern
//we can just build one type of robot here
//but there is no point to use builder pattern anyway
class LegacyRobotBuilder : public RobotBuilder
{
public:
    void buildRobotHead()
    {
        robot.setHead("Tin Head");
    }
    void buildRobotBody()
    {
        robot.setBody("Tin Body");
    }
};

//"Is A"
class ModernRobotBuilder : public RobotBuilder
{
public:
    void buildRobotHead()
    {
        robot.setHead("Electronic Head");
    }
    void buildRobotBody()
    {
        robot.setBody("Electronic Body");
    }
};

int main()
{
    cout << "Hello world!" << endl;

    shared_ptr<RobotBuilder> robotBuilder = make_shared<LegacyRobotBuilder>();
    robotBuilder.get()->buildRobot();
    Robot aRobot = robotBuilder.get()->getRobot();
    aRobot.print();

    cout << endl;

    robotBuilder = make_shared<ModernRobotBuilder>();
    robotBuilder.get()->buildRobot();
    Robot anotherRobot = robotBuilder.get()->getRobot();
    anotherRobot.print();

    return 0;
}
