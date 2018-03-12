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
	InfectedPlant();
	int getTimeToInfect() const;
	void next_step();
	bool is_still_infected()const;

private:
	int time_to_infect;
};



#endif /* INFECTEDPLANT_H_ */
