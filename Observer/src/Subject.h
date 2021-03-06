#ifndef	SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <string>
#include <vector>

class Observer;

class Subject {
public:
		Subject(std::string& name);
		~Subject();
    void addListener(Observer& l);
	void removeListener(Observer& l);
	std::string const& getName()const{return name;}
protected:
	void notify();
private:  
    typedef std::vector<Observer*> Observers;
    Observers observers;
	
	int callCount;
	std::string name;

};
#endif //SUBJECT_H
