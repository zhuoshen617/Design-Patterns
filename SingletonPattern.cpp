#include <iostream>
#include <string>
#include <memory>
#include <stdlib.h>
#include <time.h>
using namespace std;

// when you want to eliminate the option of instantiating more than one instance
// good candidates are the Game class that manage the entire game
// it could be a solution to just wrap around a global var
// a lot of clients are sharing this resource in some kind


//Game is a singleton and it has some resources
class Game
{
public:
    //this is wrong, it will trigger disabled copy constructor
    //static Game getInstance()
    
    static Game & getInstance()
    {
	//this is thread safe
        static Game instance;
        return instance;
    }

    ~Game() {}

    void play()
    {
        int num = rand() % 10 + 1;
        cout << "Number " << num << endl;
        lastPlay = num;
    }

    //we can use this last play result in somewhere else
    //you can also create a player and store this in the Player class
    //then we will have Player as a member of Game class
    int getLastPlayResult() {return lastPlay;}
    int lastPlay;

private:
    Game():lastPlay(0) {}
    Game(const Game &);
    const Game & operator=(const Game &);
};


int main()
{
    cout << "Hello world!" << endl;
    srand (time(NULL));

    Game::getInstance().play();
    cout << "LastPlay is " << Game::getInstance().getLastPlayResult() << endl;
    Game::getInstance().play();
    cout << "LastPlay is " << Game::getInstance().getLastPlayResult() << endl;
    Game::getInstance().play();
    cout << "LastPlay is " << Game::getInstance().getLastPlayResult() << endl;

    return 0;
}
