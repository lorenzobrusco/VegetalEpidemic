/*
* InfectedPlant.h
*
*  Created on: 10 mar 2018
*      Author: Lorenzo
*/

#ifndef INFECTEDPLANT_H_
#define INFECTEDPLANT_H_

#include "Individual.h"

class InfectedPlant : public Individual {
public:
	InfectedPlant(){ this->time_to_infect = 24; }
	int getTimeToInfect() const{ return this->time_to_infect; }
	void next_step() { this->time_to_infect--; }
	bool is_still_infected()const { return this->time_to_infect > 0; }

private:
	int time_to_infect;
};



#endif /* INFECTEDPLANT_H_ */
