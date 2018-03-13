/*
* CellularAutomata.h
*
*  Created on: 10 mar 2018
*      Author: Lorenzo
*/

#ifndef CELLULARAUTOMATA_H_
#define CELLULARAUTOMATA_H_

#include "World.h"
#include "Helper.h"

class CellularAutomata {
public:
	CellularAutomata(int, int, double, int);
	~CellularAutomata();
	void step();
	void behavior(Individual***, int, int);

	World* getWorld()const;
	int get_n_step()const;
	int get_initial_infected()const;
	int get_current_infected()const;
private:
	bool infect_neighbouring(int, int);
	bool is_infected(int, int);
	World* world;
	bool _pause;
	int n_step;
	int initial_infected;
	int current_infected;
};



#endif /* CELLULARAUTOMATA_H_ */
