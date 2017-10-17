#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>
using namespace std;

class Animal
{
private:
    string name;
    int weight;

public:
    void setName(const string & newName) { name = newName; }
    const string & getName() const { return name; }


    //why here we need a setter not just .weight?
    //[Answer] this is called encapsulation, so you can add some checks
    //you dont allow certain value to be assigned when directly exposed
    //weight to user
    void setWeight (int newWeight)
    {
        if (newWeight > 0)
            weight = newWeight;
        else
            throw runtime_error("weight cannot be negitive!");
    }


    //pure virtual
    virtual void getSound() = 0;
};

//Dog is an Animal
class Dog : public Animal
{
public:
    void digAHole()
    {
        cout << "Dug a hole!" << endl;
    }

    void getSound()
    {
        cout << "Wong" << endl;
    }
};

//Cat is an Animal
class Cat : public Animal
{
public:
    void getSound()
    {
        cout << "Meow" << endl;
    }
};

int main()
{
    cout << "Hello world!" << endl;

    vector<shared_ptr<Animal>> vec(2);
    vec[0] = make_shared<Dog>();
    vec[1] = make_shared<Cat>();

    //here Cat and Dog will automatically call the correct GetSound() method
    //this is called polymorphism, in c++ this only work if you use pointers
    vec[0].get()->getSound();
    vec[1].get()->getSound();

    //this will not even compile
    //as animal doesnt know digAHole
    //vec[0].get()->digAHole();

    // this will work by casting
    ((Dog *)vec[0].get())->digAHole();

    return 0;
}
