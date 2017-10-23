#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

//template method pattern
//to create a group of subclass that have to execute a similar group of methods
//we create a abstract super class that has a template method doing the algorithm
//the template method call a series of method that the subclass choose to override or not

//builder pattern also have a good example to illustrate this again

class SubwaySandwich
{
protected:
    string name;
public:
    SubwaySandwich(const string & n) : name(n) {}
    //this is the template method
    void makeSandwich()
    {
        makeBun();
        //makeCheese();
        makeProtein();
        makeVeggie();
        makeDressing();
        wrapSandwich();
    }

    //we need to declare/define all the steps here and allow subclass to override with its own version

    //this is must override step
    virtual void makeBun() = 0;

    //these are optional steps
    virtual void makeCheese() {}
    //virtual void makeProtein() {}
    virtual void makeVeggie() {}
    virtual void makeDressing() {}
    void wrapSandwich()
    {
        cout << name << " has been wrapped and ready to serve!" << endl;
    }
};

// "Is A"
class VeggieDelite : public SubwaySandwich
{
public:
    VeggieDelite() : SubwaySandwich("Veggie Delite") {}
    void makeBun()
    {
        cout << name << " has 9-grain wheat bread." << endl;
    }

    void makeProtein()
    {
        cout << name << " has premium veggie patty." << endl;
    }

    void makeVeggie()
    {
        vector<string>  veggies({"lettuce", "tomatoes", "onions", "green peppers", "cucumbers"});
        cout << name << " has ";

        for (auto veggie : veggies)
            cout << veggie << ", ";

        cout << endl;
    }
};

// "Is A"
class ItalianBMT : public SubwaySandwich
{
public:
    ItalianBMT() : SubwaySandwich("Italian B.M.T.") {}
    void makeBun()
    {
        cout << name << " has Italian bread." << endl;
    }

    void makeProtein()
    {
        vector<string> proteins({"genoa salami", "spicy pepperoni", "black forest ham"});
        cout << name << " has ";

        for (auto protein : proteins)
            cout << protein << ", ";
        cout << endl;
    }

    void makeVeggie()
    {
        vector<string>  veggies({"lettuce", "tomatoes", "cucumbers"});
        cout << name << " has ";

        for (auto veggie : veggies)
            cout << veggie << ", ";

        cout << endl;
    }

    void makeDressing()
    {
        cout << name << " has light mayonnaise." << endl;
    }
};



int main()
{
    cout << "Hello world!" << endl;

    ItalianBMT sandwich;
    sandwich.makeSandwich();

    cout << endl;

    VeggieDelite sandwich2;
    sandwich2.makeSandwich();



    return 0;
}
