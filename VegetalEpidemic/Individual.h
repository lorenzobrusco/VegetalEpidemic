/*
* Individual.h
*
*  Created on: 10 mar 2018
*      Author: Lorenzo
*/

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <iostream>

class Individual {
public:
	Individual();
	Individual(int);
	virtual ~Individual();
	int getSymbol();
	void setSymbol(int symbol);

	Individual& operator = (const Individual &a);
private:
	int symbol;
};

#endif

