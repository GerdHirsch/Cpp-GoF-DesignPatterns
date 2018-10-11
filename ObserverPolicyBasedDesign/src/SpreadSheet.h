/*
 * SpreadSheet.h
 *
 *  Created on: 10.10.2018
 *      Author: Gerd
 */

#ifndef SPREADSHEET_H_
#define SPREADSHEET_H_

#include "Observer.h"

#include <iostream>

class SpreadSheet: public Observer {
public:
	void update(int state){
		std::cout
		<< "SpreadSheet.update("
		<< state << ")"
		<< std::endl;
	}
};
#endif /* SPREADSHEET_H_ */
