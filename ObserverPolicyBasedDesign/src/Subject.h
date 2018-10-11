/*
 * Subject.h
 *
 *  Created on: 10.10.2018
 *      Author: Gerd
 */

#ifndef SUBJECT_H_
#define SUBJECT_H_

template<class Strategy>
class Subject : public Strategy {
public:
	void setState(int state){
		this->state = state;
		this->notify(state);
	}
	int getState(){ return state;}
private:
	int state{0};
};
#endif /* SUBJECT_H_ */
