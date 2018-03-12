/*
* World.cpp
*
*  Created on: 10 mar 2018
*      Author: Lorenzo
*/

#include "World.h"

World::World(int rows, int cols, double probability_rocks, bool init, int random_infect) {
	this->rows = rows;
	this->cols = cols;
	this->current_matrix = create_dynamic_matrix();
	this->next_matrix = create_dynamic_matrix();
	this->probability_rocks = probability_rocks;
	this->random_infect = random_infect;
	if (init)
		this->init_matrix();
}

World::~World() {
	this->delete_matrix(this->current_matrix);
	this->delete_matrix(this->next_matrix);
}

void World::delete_matrix(Individual*** matrix) {
	for (int i = 0; i < this->rows; ++i)
		delete[] matrix[i];
	delete[] matrix;
}

Individual* World::getIndividual(int i, int j) const {
	return this->current_matrix[i][j];
}

void World::setIndividual(int i, int j, Individual* individual) {
	this->current_matrix[i][j] = individual;
}

Individual*** World::create_dynamic_matrix() {
	Individual*** matrix = new Individual**[this->rows];
	for (int i = 0; i < this->rows; ++i)
		matrix[i] = new Individual*[this->cols];
	return matrix;
}

void World::init_matrix() {
	std::default_random_engine generator (std::random_device{}());
	std::uniform_real_distribution<double> distribution(0.0, 1.0);
	std::uniform_int_distribution<int> random_i(0, this->rows);
	std::uniform_int_distribution<int> random_j(0, this->cols);
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->cols; j++) {
			double number = distribution(generator);
			if (number > this->probability_rocks) {
				this->setIndividual(i, j, new Plant());
			}
			else {
				this->setIndividual(i, j, new Rock());
			}

		}
	}
	for (int i = 0; i < this->random_infect; i++) {
		this->setIndividual(random_i(generator), random_j(generator), new InfectedPlant());
	}
	
}


void World::swap_matrix()
{
	Individual*** tmp = this->current_matrix;
	this->current_matrix = this->next_matrix;
	this->next_matrix = tmp;
}

/** Getter and setter **/

Individual*** World::getMatrix() {
	return current_matrix;
}

Individual*** World::get_next_matrix() {
	return next_matrix;
}

int World::getRows() const {
	return rows;
}

void World::setRows(int rows) {
	this->rows = rows;
}

int World::getCols() const {
	return cols;
}

void World::setCols(int cols) {
	this->cols = cols;
}
