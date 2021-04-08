/*
 * SingleRawPointerStrategy.h
 *
 *  Created on: 10.10.2018
 *      Author: Gerd
 */
#ifndef SINGLERAWPOINTERSTRATEGY_H_
#define SINGLERAWPOINTERSTRATEGY_H_

#include "Observer.h"

class SingleRawPointerStrategy{
public:
	void attach(std::weak_ptr<Observer> observer);
	void attach(Observer* observer){
		this->observer = observer;
	}
	void detach(){
		observer = nullptr;
	}
protected:
	void notify(int state){
		if(observer) observer->update(state);
	}
private:
	Observer* observer;
};
#endif /* SINGLERAWPOINTERSTRATEGY_H_ */
