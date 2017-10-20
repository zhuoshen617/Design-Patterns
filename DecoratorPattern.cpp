#include <iostream>
#include <string>
#include <memory>
#include <stdlib.h>
#include <vector>
using namespace std;

//Create a "lowest common denominator" that makes classes interchangeable
class View
{
public:
    View(string n) : name(n) {}
    string name;
    virtual void print() = 0;
};

//Create a second level "Core" base class for adding optional functionality
class RootView : public View
{
public:
    vector<string> columns;
    RootView(string name): View(name) {}
    void print()
    {
        cout << name << endl;
        cout << " has " << columns.size() << " columns" << endl;
    }
};

//"Core" class and "Decorator" class declare an "is a" relationship
class ViewDecorator : public View
{
public:
    //Decorator class "has a" instance of the "lowest common denominator"
    shared_ptr<View> view;
    ViewDecorator(shared_ptr<View> v, string name): View(name), view(v) {}

    //Decorator class delegates to the "has a" object
    void print()
    {
        cout << name << endl;
        view->print();
    }
};

//Create a Decorator derived class for each optional embellishment
class SortedView : public ViewDecorator
{
public:
    SortedView(shared_ptr<View> v, string name) : ViewDecorator(v, name) {}
    string sortingCriteria;

    void print()
    {
        //Decorator derived classes delegate to base class AND add extra stuff
        ViewDecorator::print();
        cout << "sortingCriteria: " << sortingCriteria << endl;
    }
};

//Create a Decorator derived class for each optional embellishment
class FilterView : public ViewDecorator
{
public:
    FilterView(shared_ptr<View> v, string name) : ViewDecorator(v, name) {}
    string filterCriteria;

    void print()
    {
        //Decorator derived classes delegate to base class AND add extra stuff
        ViewDecorator::print();
        cout << "filterCriteria: " << filterCriteria << endl;
    }
};


int main()
{
    cout << "Hello world!" << endl;

    //Client has the responsibility to compose desired configurations
    shared_ptr<View> rootView = make_shared<RootView>("myRootView");
    shared_ptr<View> sortedView = make_shared<SortedView>(rootView, "mySortedView");
    shared_ptr<View> filterView = make_shared<FilterView>(sortedView, "myfilterView");

    rootView.get()->print();
    cout << endl;
    sortedView.get()->print();
    cout << endl;
    filterView.get()->print();
    cout << endl;

    return 0;
}
