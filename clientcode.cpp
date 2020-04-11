//clientcode
#include "SpaceShooter.cpp"


int main(int argc, char *argv[]){ //command line arguments
		Game game;
		while (game.is_it_running()==true){
			game.render();
			game.update();
			game.handle_event();
			game.spawn_alien();
			//run as long as is_running is true
		}
		game.clean();
		cout << "This happened!";
		
}
