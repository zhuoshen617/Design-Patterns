#include <iostream>
#include <string>
#include <memory>
using namespace std;

class EnemyShip
{
    string name;
    double amtDamage;

public:
    const string & getName() {return name;}
    void setName(const string & newName) {name = newName;}

    double getDamage() {return amtDamage;}
    void setDamage(double newDamage) {amtDamage = newDamage;}

    void followHeroShip()
    {
        cout << getName() << " is following hero." << endl;
    }

    void displayOnScreen()
    {
        cout << getName() << " is on the screen." << endl;
    }

    void shoot()
    {
        cout << getName() << " does " << getDamage() << " damage." << endl;
    }
};

class UFOEnemyShip : public EnemyShip
{
public:
    UFOEnemyShip()
    {
        setName("UFO Enemy Ship");
        setDamage(40.0);
    }
};

class RocketEnemyShip : public EnemyShip
{
public:
    RocketEnemyShip()
    {
        setName("Rocket Enemy Ship");
        setDamage(20.0);
    }
};

//this is the factory class encapsulate the the enemy ship creation
class EnemyShipFactory
{
public:
    shared_ptr<EnemyShip> makeEnemyShip(const string & enemyShipType)
    {
        if (enemyShipType == "U")
            return make_shared<UFOEnemyShip>();
        else /*if (enemyShipType == "R")*/
            return make_shared<RocketEnemyShip>();
    }
};

int main()
{
    cout << "Hello world!" << endl;

    EnemyShipFactory enemyShipFactory;

    shared_ptr<EnemyShip> enemyShip = enemyShipFactory.makeEnemyShip("U");
    enemyShip.get()->followHeroShip();
    enemyShip.get()->displayOnScreen();
    enemyShip.get()->shoot();

    enemyShip = enemyShipFactory.makeEnemyShip("R");
    enemyShip.get()->followHeroShip();
    enemyShip.get()->displayOnScreen();
    enemyShip.get()->shoot();

    return 0;
}
