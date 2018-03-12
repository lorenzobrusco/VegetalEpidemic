/*
* Individual.cpp
*
*  Created on: 10 mar 2018
*      Author: Lorenzo
*/

#include "Individual.h"

Individual::Individual() {
}

Individual::~Individual() {

}

int Individual::getSymbol() {
	return symbol;
}

void Individual::setSymbol(int symbol) {
	this->symbol = symbol;
}

Individual& Individual::operator =(const Individual& individual) {
	symbol = individual.symbol;
	return *this;
}
