#include <iostream>
#include <stdexcept>
#include <vector>
#include <queue>
#include <memory>
#include <algorithm>
using namespace std;

//Observer Design Pattern
//When you need many other objects to receive
//an update when anther object changes

class StockObserver;

class StockPublisher
{
private:
    vector<StockObserver> vec;
    double ibmPrice;

public:
    void registerF(StockObserver o);

    void unregister(StockObserver o);

    void notifyObservers();

    void setIbmPrice(double newPrice)
    {
        ibmPrice = newPrice;
        notifyObservers();
    }
};

class StockObserver
{
private:
    static int observerIDTracker;
    int observerId;
    double ibmPrice;

public:
    StockObserver(StockPublisher & stockPublisher);

    void update(double newIbmPrice);

    bool operator == (const StockObserver& so) const
    {
        return so.observerId == observerId;
    }
};

void StockPublisher::registerF(StockObserver o)
{
    vec.push_back(o);
}

void StockPublisher::unregister(StockObserver o)
{
    auto it = find(vec.begin(), vec.end(), o);
    vec.erase(it);
}

void StockPublisher::notifyObservers()
{
    for (int i = 0; i < vec.size(); i++)
        vec[i].update(ibmPrice);
}

int StockObserver::observerIDTracker = 0;

StockObserver::StockObserver(StockPublisher & stockPublisher)
{
    observerId = ++observerIDTracker;
    stockPublisher.registerF(*this);
}

void StockObserver::update(double newIbmPrice)
{
    ibmPrice = newIbmPrice;
    cout << "Observer " << observerId << " get notified by ibmPrice " << newIbmPrice << endl;
}

int main()
{
    cout << "Hello world!" << endl;

    StockPublisher stockPublisher;
    StockObserver so1(stockPublisher);
    stockPublisher.setIbmPrice(110);

    cout << endl;
    StockObserver so2(stockPublisher);
    stockPublisher.setIbmPrice(120);

    stockPublisher.unregister(so1);

    cout << endl;
    stockPublisher.setIbmPrice(130);
    return 0;
}
