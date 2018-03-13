#include "GraphicCA.h"


GraphicCA::GraphicCA(CellularAutomata* cellular_automata)
{
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_init_image_addon();
	this->cellular_automata = cellular_automata;
	this->display = al_create_display(cellular_automata->getWorld()->getRows(), cellular_automata->getWorld()->getCols()+20);
	this->font = al_load_ttf_font("stan0751.ttf", 12, 0);
	this->events = al_create_event_queue();
	this->icon = al_load_bitmap("leaf.png");
	if (!display) {
		fprintf(stderr, "Failed to create display.\n");
		exit(-1);
	}
	if (!font) {
		fprintf(stderr, "Could not load 'pirulen.ttf'.\n");
		exit(-1);
	}
	if (!events) {
		fprintf(stderr, "failed to create event_queue!\n");
		exit(-1);
	}
	if (!icon) {
		fprintf(stderr, "Could not load 'leaf.png'.\n");
		exit(-1);
	}
	al_set_display_icon(display, icon);
	al_register_event_source(events, al_get_display_event_source(display));
	al_set_window_title(this->display, "Vegetal Epidemic");
}


GraphicCA::~GraphicCA()
{
	al_destroy_display(this->display);
	al_destroy_font(this->font);
	delete this->cellular_automata;
}


void GraphicCA::loop()
{
	al_init_primitives_addon();

	while (true) {
		ALLEGRO_EVENT ev;
		ALLEGRO_TIMEOUT timeout;
		al_init_timeout(&timeout, 0.06);

		bool get_event = al_wait_for_event_until(events, &ev, &timeout);

		if (get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			break;
		}
		al_clear_to_color(al_map_rgb(0, 0, 0));
		for (int i = 0; i < this->cellular_automata->getWorld()->getRows(); i++) {
			for (int j = 0; j < this->cellular_automata->getWorld()->getCols(); j++) {
				if (Helper::instanceof<Plant>(this->cellular_automata->getWorld()->getIndividual(i, j))) {
					al_draw_pixel(i, j, al_map_rgb(0, 128, 0));
				}
				else if (Helper::instanceof<InfectedPlant>(this->cellular_automata->getWorld()->getIndividual(i, j))) {
					al_draw_pixel(i, j, al_map_rgb(150, 0, 0));
				}
				else if (Helper::instanceof<HealtedPlant>(this->cellular_automata->getWorld()->getIndividual(i, j))) {
					al_draw_pixel(i, j, al_map_rgb(50, 200, 50));
				}
				else if (Helper::instanceof<Rock>(this->cellular_automata->getWorld()->getIndividual(i, j))) {
					al_draw_pixel(i, j, al_map_rgb(100, 100, 100));
				}
			}
		}
		char* steps = new char[50];
		sprintf_s(steps, 50, "Steps: %d", this->cellular_automata->get_n_step());
		al_draw_text(this->font, al_map_rgb(255, 255, 255), 5, this->cellular_automata->getWorld()->getCols(), ALLEGRO_ALIGN_LEFT, steps);
		sprintf_s(steps, 50, "Infected plants: %d", this->cellular_automata->get_initial_infected());
		al_draw_text(this->font, al_map_rgb(255, 255, 255), this->cellular_automata->getWorld()->getRows()/3, this->cellular_automata->getWorld()->getCols(), ALLEGRO_ALIGN_LEFT, steps);
		sprintf_s(steps, 50, "Initial infected plants: %d", this->cellular_automata->get_current_infected());
		al_draw_text(this->font, al_map_rgb(255, 255, 255), (this->cellular_automata->getWorld()->getRows()-230), this->cellular_automata->getWorld()->getCols(), ALLEGRO_ALIGN_LEFT, steps);
		al_flip_display();
		delete[] steps;
		this->cellular_automata->step();
	}
}