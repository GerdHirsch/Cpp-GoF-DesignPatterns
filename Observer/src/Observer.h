#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <iostream>

/**
 * wird als allgemeine abstraktion / Basisklasse benötigt,
 * um sich am Subject anzumelden
 * abstract Observer pure virtual
*/
class Observer {
public:    
	virtual void update(std::string const& subjectName, int callCount)=0;
	virtual ~Observer(){}
};
#endif //OBSERVER_H
