
#include <string>
#include <algorithm>

using namespace std;

#include "Subject.h"
#include "Observer.h"

Subject::Subject(string& name):callCount(0), name(name) {}
Subject::~Subject(){
	cout << "~Subject()"<<endl;
}

void Subject::notify(){
	++callCount;
	cout << "notify() "<< observers.size() <<" Listener from " << name << endl;
    Observers::iterator it = observers.begin();
    Observers::iterator end = observers.end();
    while(it != end)
    {
        (*it)->update(name,callCount);
        ++it;
    }
}

void Subject::addListener(Observer& l){
	cout << "addListener to " << name<< endl;
    observers.push_back(&l);
}

void Subject::removeListener(Observer& l){
	cout << "removeListener from "<< name << endl;
    Observers::iterator end = remove(observers.begin(), observers.end(),&l);
    observers.erase(end, observers.end());
}
