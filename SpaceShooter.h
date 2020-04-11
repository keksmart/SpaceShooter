//header file
#include <iostream>
#include <SDL.h> //SDL library
#include <SDL_image.h> //SDL library for image
#include <windows.h> //Sleep
#include <thread> // time
#include <stdlib.h>  //rand and srand function
using namespace std; 
//header file
#ifndef SPACESHOOTER
#define SPACESHOOTER

class Game{
	private:
		enum motion{
			MOVE_RIGHT=0,
			MOVE_LEFT=1,
			SHOOT=2
		};
		
		bool motion_detect[3] = {false,false,false};
		bool is_running = false;
		bool shoot_laser = false;
		int speed=5, laser_speed = 10, laser_count = 0; 
		int mouse_x, mouse_y;
		int limit = 10;
		int alien_speed = 3;
		int alien_count = 0;
		bool clicked = false;
		bool aliens_coordinate[7][14] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
										  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
										 };
		
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Texture *spaceship, *space, *white_stars, *planet, *planet_big;
		SDL_Rect ship_des, space_des, star_des, planet_des, big_des;
		SDL_Texture  *laser1, *laser2, *laser3; // Only allow 3 users per screen
		SDL_Rect laser_des1, laser_des2, laser_des3;
		SDL_Texture  *sButton, *sButtonHover, *sButtonClick;
		SDL_Rect sb_des;
		SDL_Texture *alien;
		SDL_Rect alien_des;
		
	public:                      
		Game();
		void loadImages_setInfos(); 
		void setDes(SDL_Rect &rect, int hori, int vert, int width, int height);
		void handle_event();
		void update();
		void render();
		void spawn_alien();
		bool is_it_running();
		void clean();
                          
		~Game();
}; 

#endif
