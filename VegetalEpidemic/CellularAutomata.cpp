/*
* CellularAutomata.cpp
*
*  Created on: 10 mar 2018
*      Author: Lorenzo
*/

#include "CellularAutomata.h"

CellularAutomata::CellularAutomata(int rows, int cols,
	double probability_rocks, int random_infect) {
	this->world = new World(rows, cols, probability_rocks, true, random_infect);
	this->_pause = false;
	this->n_step = 0;
	this->initial_infected = random_infect;
	this->current_infected = random_infect;
}

CellularAutomata::~CellularAutomata() {
	delete this->world;
}


void CellularAutomata::step() {
	Individual*** tmp_matrix = this->world->get_next_matrix();
	for (int i = 0; i < this->world->getRows(); i++) {
		for (int j = 0; j < this->world->getCols(); j++) {
			tmp_matrix[i][j] = this->world->getIndividual(i, j);
			this->behavior(tmp_matrix, i, j);
		}
	}
	this->world->swap_matrix();
	this->n_step++;
}

void CellularAutomata::behavior(Individual*** tmp_matrix, int i, int j) {
	if (Helper::instanceof<Plant>(this->world->getIndividual(i, j))) {
		if (this->infect_neighbouring(i, j)) {
			tmp_matrix[i][j] = new InfectedPlant();
			this->current_infected++;
		}
	}
	else if (Helper::instanceof<InfectedPlant>(
		this->world->getIndividual(i, j))) {
		InfectedPlant* infected =dynamic_cast<InfectedPlant*>(this->world->getIndividual(i, j));
		infected->next_step();
		if (!infected->is_still_infected()) {
			tmp_matrix[i][j] = new HealtedPlant();
			this->current_infected--;
		}
	}
}

World * CellularAutomata::getWorld() const
{
	return this->world;
}

int CellularAutomata::get_n_step()const {
	return this->n_step;
}

int CellularAutomata::get_initial_infected()const {
	return this->initial_infected;
}
int CellularAutomata::get_current_infected()const {
	return this->current_infected;
}

bool CellularAutomata::infect_neighbouring(int i, int j) {
	if (i == 0 and j == 0) {
		if (this->is_infected(i, j + 1) or this->is_infected(i + 1, j)
			or this->is_infected(i + 1, j + 1))
			return true;
	}
	else if (i == 0 and j == this->world->getCols() - 1) {
		if (this->is_infected(i, j - 1) or this->is_infected(i + 1, j)
			or this->is_infected(i + 1, j - 1))
			return true;
	}
	else if (i == 0 and this->world->getCols() - 1 > j and j > 0) {
		if (this->is_infected(i, j + 1) or this->is_infected(i + 1, j)
			or this->is_infected(i + 1, j + 1)
			or this->is_infected(i, j - 1)
			or this->is_infected(i + 1, j - 1))
			return true;
	}
	else if (i == this->world->getRows() - 1 and j == 0) {
		if (this->is_infected(i, j + 1) or this->is_infected(i - 1, j)
			or this->is_infected(i - 1, j + 1))
			return true;
	}
	else if (i == this->world->getRows() - 1
		and j == this->world->getCols() - 1) {
		if (this->is_infected(i, j - 1) or this->is_infected(i - 1, j)
			or this->is_infected(i - 1, j - 1))
			return true;
	}
	else if (i == this->world->getRows() - 1
		and this->world->getCols() - 1 > j and j > 0) {
		if (this->is_infected(i, j + 1) or this->is_infected(i - 1, j)
			or this->is_infected(i - 1, j + 1)
			or this->is_infected(i, j - 1)
			or this->is_infected(i - 1, j - 1))
			return true;
	}
	else if (i > 0 and this->world->getRows() - 1 > i and j == 0) {
		if (this->is_infected(i, j + 1) or this->is_infected(i + 1, j)
			or this->is_infected(i + 1, j + 1)
			or this->is_infected(i - 1, j)
			or this->is_infected(i - 1, j + 1))
			return true;
	}
	else if (i > 0 and this->world->getRows() - 1 > i
		and j == this->world->getCols() - 1) {
		if (this->is_infected(i, j - 1) or this->is_infected(i + 1, j)
			or this->is_infected(i + 1, j - 1)
			or this->is_infected(i - 1, j)
			or this->is_infected(i - 1, j - 1))
			return true;
	}
	else {
		if (this->is_infected(i, j + 1) or this->is_infected(i + 1, j)
			or this->is_infected(i + 1, j + 1)
			or this->is_infected(i, j - 1)
			or this->is_infected(i + 1, j - 1)
			or this->is_infected(i - 1, j)
			or this->is_infected(i - 1, j + 1)
			or this->is_infected(i, j - 1)
			or this->is_infected(i - 1, j - 1))
			return true;
	}
	return false;
}

bool CellularAutomata::is_infected(int i, int j) {
	return Helper::instanceof<InfectedPlant>(this->world->getIndividual(i, j));
}
