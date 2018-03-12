/*
* World.h
*
*  Created on: 10 mar 2018
*      Author: Lorenzo
*/

#ifndef WORLD_H_
#define WORLD_H_

#include <iostream>
#include <random>
#include "Plant.h"
#include "InfectedPlant.h"
#include "HealtedPlant.h"
#include "Rock.h"

class World {
public:
	World(int, int, double, bool, int);
	~World();

	Individual* getIndividual(int, int) const;
	void setIndividual(int, int, Individual*);
	Individual*** create_dynamic_matrix();
	void swap_matrix();
	
	Individual*** getMatrix();
	Individual*** get_next_matrix();
	int getRows() const;
	void setRows(int rows);
	int getCols() const;
	void setCols(int cols);

private:

	void init_matrix();
	void delete_matrix(Individual***);
	Individual*** current_matrix;
	Individual*** next_matrix;
	int rows;
	int cols;
	double probability_rocks;
	int random_infect;
};

#endif /* WORLD_H_ */
