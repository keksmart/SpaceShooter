#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
using namespace std;



class Game{
	private:
		bool is_running = false;
		int speed=1; //pixel
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Texture *spaceship; //put an image on this spaceship object
		SDL_Rect source, destination;
		
	public:
		Game(){
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
			window = SDL_CreateWindow("SpaceShooter", 200,200, 600,600, false);
			if (window){ //this is gonna run if window created successfully
					cout << "Window created."<<endl;
				}
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer){ //same for renderer
				cout << "Renderer created." << endl;
			}
			SDL_SetRenderDrawColor(renderer, 204, 255, 255, 255); //you are not done yet
			is_running = true;
			}
		else{
			is_running = false;
		}
		spaceship = IMG_LoadTexture(renderer, "images/ricardo.png");
	}
		void handle_event(){ //handle any input of user, and respond
			SDL_Event event; //detect what you do to your computer
							 //example: moving your mouse, pressing a button on your keyboard
			if (SDL_PollEvent(&event)){
				
			}
			switch(event.type){
				case SDL_QUIT: //SDL_QUIT means someone click the "X" on top
					is_running = false;
					cout << "Quitting program..." << endl;
					break;
				default:
					break;
			}
		}
		
		void update(){ //update things on the screen
		
		}
		void render(){ //painter function
			SDL_RenderClear(renderer); //to draw on a new paper
			SDL_RenderCopy(renderer, spaceship, NULL, NULL);
			SDL_RenderPresent(renderer); //start painting!
		} 
		bool is_it_running(){
			return is_running;
		}
		void clean(){ //DrAzeem mentioned before, dynamic memory allocation
					  //To prevent Memory Leak
			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(renderer);
			SDL_Quit();
			
		}
};

int main(int argc, char *argv[]){ //command line arguments
		Game game;
		while (game.is_it_running()==true){
			game.render();
			game.update();
			game.handle_event();
			//run as long as is_running is true
		}
		game.clean();
		cout << "This happened!";
		
}
