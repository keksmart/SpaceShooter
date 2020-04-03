#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
using namespace std;

class Game{		
	private:
		bool is_running = false;
		int speed=3; // unit: pixel
		SDL_Window *window;
		SDL_Renderer *renderer;
		SDL_Texture *spaceship; //our picture will store in this object	
		SDL_Texture *red_dot; 
		SDL_Rect destination1, destination2; //SDL_Rect create a rectangular 
		
	public:
		Game(){
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0){
			window = SDL_CreateWindow("SpaceShooter", 200,200, 900,650, false);
			cout << "Window is " << window << endl;
			if (window){ //this is gonna run if window created successfully
					cout << "Window created."<<endl;
				}
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer){ //same for renderer
				cout << "Renderer created." << endl;
			}
			SDL_SetRenderDrawColor(renderer, 204, 255, 255, 255); //set our colors and alpha
			is_running = true;
			}
		else{
			is_running = false;
		}
		spaceship = IMG_LoadTexture(renderer, "images/spaceship.png");
		red_dot = IMG_LoadTexture(renderer, "images/red_dot.png");
		//spaceship's size and location 
		destination1.h = 100;//height
		destination1.w = 100;//width
		destination1.x = 300; // x location
		destination1.y = 500;// y location
		//red_dot's size and location
		destination2.h = 50;//height
		destination2.w = 50;//width
		destination2.x = 600; // x location
		destination2.y = 520;// y location
		
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
				case SDL_KEYDOWN: // When someone clicked his keyboard's button
					if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT){
						if (destination1.x <= 800){
							destination1.x += speed;
							cout << "X location is now at: " << destination1.x << endl;
						}
						else{
							cout << "You are running out of the window at right!" << endl;
						}
						//move the spaceship to the right
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_LEFT){
						if (destination1.x >= 0){
							destination1.x -= speed;
							cout << "X location is now at: " << destination1.x << endl;
						}
						else{
							cout << "You are running out of the window at left!" << endl;
						}
						//move the spaceship to the right
					}
					
					if (destination1.x >= 500){ 
						speed = 10;
						cout << "The speed boosted!";
					}
					break;
				case SDL_KEYUP: //When someone done clicking and leave the button
					cout << "Someone left his hand off the keyboard"<< endl;
					break;
				default:
					break;
			}
		}
		
		void update(){ //update things on the screen
		
		}
		void render(){ //painter function
			SDL_RenderClear(renderer); //to draw on a new paper
			SDL_RenderCopy(renderer, red_dot, NULL, &destination2); //for red_dot
			SDL_RenderCopy(renderer, spaceship, NULL, &destination1); //This is to display an image 
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
		
		virtual ~Game(){
			cout << "Class Game has reached the end of its lifetime --- destructing..." << endl;
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
