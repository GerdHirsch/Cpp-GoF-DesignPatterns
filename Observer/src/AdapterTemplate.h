/*
 * AdapterTemplate.h
 *
 *  Created on: 18.03.2018
 *      Author: Gerd
 */

#ifndef ADAPTERTEMPLATE_H_
#define ADAPTERTEMPLATE_H_
#include "Observer.h"
#include <string>
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
	using Operation = void (C::*)(std::string const&, int);
public:
	AdapterTemplate(C& implementation, Operation operation)
	:
		implementation(implementation),
		operation(operation){ ; }

	virtual ~AdapterTemplate(){
		std::cout << "~AdapterTemplate()" << std::endl;
	}

  void update(std::string const& subjectName, int callCount){
		(implementation.*operation)(subjectName, callCount);
  }

private:
    C& implementation;
    Operation operation;
};
#endif /* ADAPTERTEMPLATE_H_ */
