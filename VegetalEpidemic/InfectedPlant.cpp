/*
* InfectedPlant.cpp
*
*  Created on: 11 mar 2018
*      Author: Lorenzo
*/

#include "InfectedPlant.h"

InfectedPlant::InfectedPlant() :
	Individual(3) {
	this->time_to_infect = 1;
}

int InfectedPlant::getTimeToInfect() const {
	return this->time_to_infect;
}

void InfectedPlant::next_step() {
	this->time_to_infect--;
}

bool InfectedPlant::is_still_infected() const {
	return this->time_to_infect > 0;
}
