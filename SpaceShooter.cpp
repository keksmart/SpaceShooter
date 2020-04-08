//implementation
#include "SpaceShooter.h"
using namespace std;

Game::Game(){
		if (SDL_Init(SDL_INIT_EVERYTHING) == 0){ //Initialization is required
			window = SDL_CreateWindow("SpaceShooter", 100,100, 900,650, false);
			if (window ){ //this is gonna run if window created successfully
					cout << "Window created."<<endl;
				}
			renderer = SDL_CreateRenderer(window, -1, 0); 
			if (renderer){ //same for renderer
				cout << "Renderer created." << endl;
			}
			is_running = true; //if everything intialized successfully, we make this become true
							   //to let our program keep on running
			}
		else{
			is_running = false; //rare case, if not, set it to false and program will not keep on running
		}
		loadImages_setInfos(); //load all our images and set their attributes
		
	}
	
void Game::loadImages_setInfos(){
	
	spaceship = IMG_LoadTexture(renderer, "images/spaceship.png");
	space = IMG_LoadTexture(renderer, "images/space.jpg");
	planet = IMG_LoadTexture(renderer, "images/planet.png" );
	planet_big = IMG_LoadTexture(renderer, "images/planet.png" );
	laser1 = IMG_LoadTexture(renderer, "images/redline.png" );
	laser2 = IMG_LoadTexture(renderer, "images/redline.png" );
	laser3 = IMG_LoadTexture(renderer, "images/redline.png" );
	setDes(ship_des, 900/2 - 50, 500, 64, 64);
	setDes(space_des, 0, 0, 900, 650);
	setDes(planet_des, 100, 50, 50, 50);
	setDes(big_des, 600, 200, 100, 100);
	setDes(laser_des1, 0, 0, 0, 0); // LOGIC: set w and h to 0 first,
	setDes(laser_des2, 0, 0, 0, 0); // so it appears nothing initially,
	setDes(laser_des3, 0, 0, 0, 0); // when someone pressed spacebar, assign a w and h
	
}

void Game::setDes(SDL_Rect &rect, int hori, int vert, int width, int height){
			rect.x = hori;
			rect.y = vert;
			rect.w = width;
			rect.h = height;
		}
		
void Game::handle_event(){
	
	SDL_Event event; //detect what you do to your computer
					 //example: moving your mouse, pressing a button on your keyboard
	while(SDL_PollEvent(&event) != 0){ //when an event is detected, no matter what kind of event
	
			switch(event.type){ //more in-depth detection
			
				case SDL_QUIT: //SDL_QUIT means someone click the "X" on top-right
					is_running = false;
					cout << "Quitting program..." << endl;
					SDL_Quit();
					break;
				case SDL_KEYDOWN: // When someone clicked the keyboard's button
				
					if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT){
						motion_detect[MOVE_RIGHT] = true;
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_LEFT){
						motion_detect[MOVE_LEFT] = true;
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_SPACE){
						motion_detect[SHOOT] = true;
					break;
					
				case SDL_KEYUP: //When someone done clicking and leave the button
					if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT){
						motion_detect[MOVE_RIGHT] = false;
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_LEFT){
						motion_detect[MOVE_LEFT] = false;
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_SPACE){
						motion_detect[SHOOT] = false;
					}
					cout << "Someone left his hand off the keyboard"<< endl;
					break;
				
				default:
					break;
				}
			}
		
	}
}

void Game::update(){ //update things on the screen
			//planets keep moving at background
			planet_des.y += 1;
			big_des.y += 1;
			Sleep(10);
			if (planet_des.y == 650){
				planet_des.y = -50; //reset
			}
			if (big_des.y == 650){
				big_des.y = -100; //reset
			}
			
			if (motion_detect[MOVE_RIGHT]==true){
				if (ship_des.x <= 800){ //to limit someone move out of scope
					ship_des.x += speed;
					cout << "X location is now at: " << ship_des.x << endl;
				}
				else{
					cout << "You are running out of the window at right!" << endl;
				}
						//move the spaceship to the right
			}
			if (motion_detect[MOVE_LEFT]==true){
				if (ship_des.x >= 0){ //to limit someone move out of scope
					ship_des.x -= speed;
					cout << "X location is now at: " << ship_des.x << endl;
				}
				else{
					cout << "You are running out of the window at left!" << endl;
				}
				//move the spaceship to the left
			}
			if (motion_detect[SHOOT]==true){ 
					//Limit 3 lasers only
					//shoot
				cout << laser_count << endl;
				if (laser_count <3){
					if (laser_count == 0){
						setDes(laser_des1, ship_des.x + 64/2 - 10/2, ship_des.y, 10, 20);
						laser_count +=1;
					}
					else if (laser_count == 1 && laser_des1.y <= ship_des.y-50){
						setDes(laser_des2, ship_des.x + 64/2 - 10/2, ship_des.y, 10, 20);
						laser_count +=1;
					}
					else if (laser_count == 2 && laser_des2.y <= ship_des.y-50){
						setDes(laser_des3, ship_des.x + 64/2 - 10/2, ship_des.y, 10, 20);
						laser_count +=1;
						}
					}
				else{
					if(laser_des1.y <= -20 && laser_des3.y <= ship_des.y-50){
						laser_count -= 0;
						setDes(laser_des1, ship_des.x + 64/2 - 10/2, ship_des.y, 10, 20);
					}
					if(laser_des2.y <= -20 && laser_des1.y <= ship_des.y-50){
						laser_count -= 1;
						setDes(laser_des2, ship_des.x + 64/2 - 10/2, ship_des.y, 10, 20);
					}
					if(laser_des3.y <= -20 && laser_des2.y <= ship_des.y-50){
						laser_count -= 2;
						setDes(laser_des3, ship_des.x + 64/2 - 10/2, ship_des.y, 10, 20);
						}
					
					}
							
				}
		}
		
void Game::render(){ //painter function

			/* Important Note: Render has a 
			   hierarchy structure Whatever 
			   comes first will render at the bottom */
			   
			SDL_RenderClear(renderer);
			SDL_RenderCopy(renderer, space, NULL, &space_des); //paint my picture!
			SDL_RenderCopy(renderer, planet, NULL, &planet_des);
			SDL_RenderCopy(renderer, planet_big, NULL, &big_des);
			if (laser_count >= 1){
				
				SDL_RenderCopy(renderer, laser1, NULL, &laser_des1);
				SDL_RenderCopy(renderer, laser2, NULL, &laser_des2);
				SDL_RenderCopy(renderer, laser3, NULL, &laser_des3);
				laser_des1.y -= 3;	
				laser_des2.y -= 3;	
				laser_des3.y -= 3;	
			}
			SDL_RenderCopy(renderer, spaceship, NULL, &ship_des); //to draw on a new paper //This is to display an image 
			SDL_RenderPresent(renderer); //start painting!
		} 

bool Game:: is_it_running(){
			return is_running;
		}
void Game::clean(){ //DrAzeem mentioned before, dynamic memory allocation
			  //To prevent Memory Leak
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	
}

Game::~Game(){
			cout << "Class Game has reached the end of its lifetime --- destructing..." << endl;
}
