//============================================================================
// Name        : VegetalEpidemic.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Vegetal epidemic in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CellularAutomata.h"
#include "GraphicCA.h"
using namespace std;

const int width = 800;
const int height = 600;
const double probablity_of_rocks = 0.7f;
const int initial_infected_plants = 10;

int main() {
	GraphicCA graphic(new CellularAutomata(width, height, probablity_of_rocks, initial_infected_plants));
	graphic.loop();
 	return 0;
}