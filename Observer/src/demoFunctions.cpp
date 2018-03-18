/*
 * demoFunctions.cpp
 *
 *  Created on: 18.03.2018
 *      Author: Gerd
 */

#include "ConcreteSubject.h"
#include "ConcreteObserver.h"
#include "ConcreteObserver2.h"
#include "AdapterTemplate.h"

#include <iostream>
using namespace std;

void demoAdapterTemplate(){
	cout << "demoAdapterTemplate"<<endl;

	ConcreteSubject s1("Subject1");
	ConcreteSubject s2("Subject2");

	ConcreteObserver1 observer1("observer1");
	ConcreteObserver2 observer2("observer2");

	AdapterTemplate< ConcreteObserver1> adapter1(observer1, &ConcreteObserver1::operation1);
	AdapterTemplate< ConcreteObserver1> adapter2(observer1, &ConcreteObserver1::operation2);

	s1.addListener(adapter1);
	s2.addListener(adapter2);
	s1.addListener(observer2);

	s1.changeState();
	s2.changeState();

	s1.removeListener(adapter1);
	s2.removeListener(adapter2);
	s1.removeListener(observer2);

	s1.changeState();
}

