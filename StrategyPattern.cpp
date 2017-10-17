#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
#include <memory>
using namespace std;

//Strategy Design Pattern
//you have a list of BEHAVIORS that are similar
//these behaviors are likely to change dynamically

//Class fields are objects and we use composition here

class Strategy
{
public:
    virtual void play() = 0;
};

class PlayRock : public Strategy
{
public:
    void play()
    {
        cout << "Rock" << endl;
    }
};

class PlayPaper : public Strategy
{
public:
    void play()
    {
        cout << "Paper" << endl;
    }
};

class PlayScissor : public Strategy
{
public:
    void play()
    {
        cout << "Scissor" << endl;
    }
};

class Player
{
public:

    void setStrategies(vector<shared_ptr<Strategy>> & newStrategies)
    {
    }

    void initDefaultStrategy()
    {
        strategyPool.push(make_shared<PlayRock>());
        strategyPool.push(make_shared<PlayPaper>());
        strategyPool.push(make_shared<PlayScissor>());
    }

    //class fields are objects and we use composition here
    queue<shared_ptr<Strategy>> strategyPool;

    void play()
    {
        strategyPool.front().get()->play();
        strategyPool.push(strategyPool.front());
        strategyPool.pop();
    }
};

int main()
{
    cout << "Hello world!" << endl;

    Player p;
    p.initDefaultStrategy();
    p.play();
    p.play();
    p.play();

    return 0;
}
