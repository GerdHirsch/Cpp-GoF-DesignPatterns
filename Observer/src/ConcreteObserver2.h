/*
 * ConcreteObserver2.h
 *
 *  Created on: 18.03.2018
 *      Author: Gerd
 */

#ifndef CONCRETEOBSERVER2_H_
#define CONCRETEOBSERVER2_H_

#include "Observer.h"

class ConcreteObserver2 : public Observer{
public:
	ConcreteObserver2(std::string name);
	virtual ~ConcreteObserver2();
	void update(std::string const& subjectName, int callCount);
private:

	std::string name;
	static int objectCount;
};



#endif /* CONCRETEOBSERVER2_H_ */
