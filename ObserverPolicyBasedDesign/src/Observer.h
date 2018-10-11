/*
 * Observer.h
 *
 *  Created on: 10.10.2018
 *      Author: Gerd
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

class Observer{
public:
	virtual void update(int state) = 0;
};

#endif /* OBSERVER_H_ */
