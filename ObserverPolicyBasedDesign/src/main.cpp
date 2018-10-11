/*
 * main.cpp
 *
 *  Created on: 10.10.2018
 *      Author: Gerd
 */

#include "SingleRawPointerStrategy.h"
#include "Subject.h"
#include "SpreadSheet.h"

#include <iostream>
using namespace std;

void demoSingleRawPointer(){
	cout << "demoSingleRawPointer" << endl;
	using Strategy = SingleRawPointerStrategy;
	using Subject = Subject<Strategy>;

	Subject subject;
	SpreadSheet sheet;

	subject.attach(&sheet);

	subject.setState(42);
}

int main(){
	cout << "ObserverPolicyBasedDesign" << endl;
	demoSingleRawPointer();
}

