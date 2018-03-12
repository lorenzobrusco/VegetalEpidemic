#ifndef GRAPHICCA_H
#define GRAPHICCA_H

#include <allegro5\allegro.h>
#include <allegro5\allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_primitives.h>
#include <stdio.h> 
#include "CellularAutomata.h"
class GraphicCA
{
public:
	GraphicCA(CellularAutomata*);
	~GraphicCA();
	void loop();
	
private:
	ALLEGRO_DISPLAY * display;
	ALLEGRO_FONT* font;
	ALLEGRO_EVENT_QUEUE* events;
	CellularAutomata* cellular_automata;
};

#endif