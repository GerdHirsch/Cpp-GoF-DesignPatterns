#if !defined CONCRETESUBJECT_H
#define CONCRETESUBJECT_H

#include "Subject.h"

class ConcreteSubject : public Subject
{
public:
	ConcreteSubject(std::string name):Subject(name){}
	void changeState();
};//end of class ConcreteSubject
#endif // CONCRETESUBJECT_H