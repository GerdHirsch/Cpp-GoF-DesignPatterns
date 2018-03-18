
#include <string>
#include <algorithm>

using namespace std;

#include "Subject.h"
#include "Observer.h"

Subject::Subject(string& name):callCount(0), name(name) {}
Subject::~Subject(){
	cout << name <<".~Subject() " <<endl;
}

void Subject::notify(){
	++callCount;
	cout << name << ".notify() numObservers: "<< observers.size() << endl;
	for(auto observer : observers)
		observer->update(name, callCount);

//    Observers::iterator it = observers.begin();
//    Observers::iterator end = observers.end();
//    while(it != end)
//    {
//        (*it)->update(name,callCount);
//        ++it;
//    }
}

void Subject::addListener(Observer& l){
	cout << name <<".addListener" << endl;
    observers.push_back(&l);
}

void Subject::removeListener(Observer& l){
	cout << name << ".removeListener" << endl;
    Observers::iterator end = remove(observers.begin(), observers.end(),&l);
    observers.erase(end, observers.end());
}
