//header file
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <windows.h>
using namespace std; 
//header file
#ifndef SPACESHOOTER
#define SPACESHOOTER

class Game{
	private:
		bool is_running = false;
		bool shoot_laser = false;
		int speed=5, laser_speed = 10, laser_count = 0; 
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Texture *spaceship, *space, *planet, *planet_big;
		SDL_Rect ship_des, space_des, planet_des, big_des;
		SDL_Texture  *laser1, *laser2, *laser3; // Only allow 3 users per screen
		SDL_Rect laser_des1, laser_des2, laser_des3;
	public:                      
		Game();
		void loadImages_setInfos(); 
		void setDes(SDL_Rect &rect, int hori, int vert, int width, int height);
		void handle_event();
		void update();
		void render();
		bool is_it_running();
		void clean();
                          
		~Game();
}; 

#endif
