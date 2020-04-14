//clientcode
#include "SpaceShooter.h"  		//this is for VisualStudio
//for DevC++ change to “SpaceShooter.cpp”


int main(int argc, char* argv[]) { //command line arguments

	Game game;
	while (game.is_it_running() == false) { //main menu
		game.renderMenu(); //run main menu
		game.handle_event(); //mouse position and click detection
	}

	while (game.is_it_running() == true) {
			game.handle_event();
			game.render();
			game.update();
			game.spawn_alien();
			
			//run as long as is_running is true
		
	}
	game.clean();

	return 0;
}


