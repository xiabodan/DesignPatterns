#include "mazefactory.h"

//MazeFactory Singleton mode
MazeFactory* MazeFactory::_instance = 0;//∂®“Â
MazeFactory* MazeFactory::Instance(){
	if(NULL == _instance){
		//const char* mazeStyle = getenv("MAZESTYLE");
		const char* mazeStyle = "bombed";
		if(strcmp(mazeStyle,"bombed") == 0){
			_instance = new BombedMazeFactory;
		}
		else if(strcmp(mazeStyle,"enchanted") == 0){
			_instance = new EnchantedMazeFactory;
		}
		// other possible subclass
		else{
			_instance = new MazeFactory;
		}
	}

	return _instance;
}