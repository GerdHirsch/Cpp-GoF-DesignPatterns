#include "Observer.h"
#include "Subject.h"	

using namespace std;

Observer::Observer(Subject& s):subject(&s){
	subject->addListener(*this);
}
Observer::~Observer(){
	cout << "~Observer()"<<endl;
	if(subject)
		subject->removeListener(*this);
}
void Observer::addListener(){
	subject->addListener(*this);
}
void Observer::removeListener(){
	subject->removeListener(*this);
}

