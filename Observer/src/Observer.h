#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <iostream>

class Subject;

/**
 * wird als allgemeine abstraktion / Basisklasse benötigt,
 * um sich am Subject anzumelden
 * abstract Observer pure virtual
 * Ctor meldet sich beim Subject an
 * dtor meldet sich beim Subject ab
*/
class Observer {
public:    
	Observer(Subject &subject);
  virtual void update(std::string& subjectName, int callCount)=0;
	virtual ~Observer();
protected:
	void addListener();
	void removeListener();
		
private:
	Subject* subject;
};

/*
	Ein Template, das den Kit zwischen dem Subject und seinen Clients
	realisiert, taugt für subjects, von denen man typischer weise nur 
	eines kennt und sich bei dem anmeldet, die operations-aufrufe sind 
	fest verdrahtet, es gibt keine möglichkeit sich bei verschiedenen 
	Subjects mit dem selben interface anzumelden und die subjects zu 
	unterscheiden
*/
template < typename C >
class Kit : public Observer {
public:
	Kit(C& implementation, Subject& subject):Observer(subject),
		implementation(implementation){
		
	}
	virtual ~Kit(){
		std::cout << "~Kit()" << std::endl;
	}
	
  void update(std::string& subjectName, int callCount){
      implementation.update(subjectName, callCount);
  }

private:    
    C& implementation;
};

/*
	Der Kit zwischen den Komponenten, ein Adapter der von einer Schnittstelle
	(Operation-Name) auf eine andere mappt, bei Ihm wird die Klasse bekannt gemacht
	die Implementierung und die Adressen der Operaions angemeldet.
	Dadurch ist es möglich, dass z.B. ein Dialog sich bei mehreren Buttons
	als Listener anmeldet, er muss lediglich die aktionPerformed() operations
	für die verschiedenen Buttons zur verfügung stellen
*/
template < typename C >
class AdapterTemplate : public Observer {
public:   
	AdapterTemplate(C& implementation, 
					void (C::*operation)(std::string&, int), 
					Subject& subject):
		Observer(subject),
		implementation(implementation), 
		operation(operation){ ; }
	virtual ~AdapterTemplate(){
		std::cout << "~AdapterTemplate()" << std::endl;
	}
	
  void update(std::string& subjectName, int callCount){
		(implementation.*operation)(subjectName, callCount);
  }

private:    
    C& implementation;
	void (C::*operation)(std::string&,int);
};

#endif //OBSERVER_H
