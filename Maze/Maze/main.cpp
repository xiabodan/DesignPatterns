#include <iostream>
#include "mazefactory.h"

int main()
{
	////原始方法创建迷宫
	//MazeGame_Original* Maze = new MazeGame_Original();
	//Maze->CreateMaze();
	
	////抽象工厂方法创建迷宫
	//MazeFactory factory;
	//MazeGame_AbstractFactory* Maze = new MazeGame_AbstractFactory();
	//Maze->CreateMaze(factory);
	//delete Maze;

	////抽象工厂方法创建含有炸弹的迷宫
	//BombedMazeFactory bombfactory;
	//MazeGame_AbstractFactory bobgame;
	//bobgame.CreateMaze(bombfactory);

	////抽象工厂方法创建含有魔法的迷宫
	//EnchantedMazeFactory* enchantedfactory = new EnchantedMazeFactory;
	//MazeGame_AbstractFactory* enchantedgame = new MazeGame_AbstractFactory;
	//enchantedgame->CreateMaze(*enchantedfactory);
	//delete enchantedfactory;
	//delete enchantedgame;

	////单例创建迷宫 
	//MazeFactory* m = MazeFactory::Instance();
	//MazeGame_AbstractFactory SingletonMazeGame;
	//SingletonMazeGame.CreateMaze(*m);

	//Builder创建迷宫
	Maze* maze;
	cout << "1、MazeGame_Builder buildgame" << endl;
	MazeGame_Builder buildgame;
	cout << "2、StandardMazeBuilder builder" << endl;
	StandardMazeBuilder builder ;
	cout << "3、buildgame.CreateMaze(builder)" << endl;
	buildgame.CreateMaze(builder);
	cout << "4、maze = builder.GetMaze();" << endl;
	maze = builder.GetMaze();

	getchar();
	return 0;
}