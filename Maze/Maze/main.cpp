#include <iostream>
#include "mazefactory.h"

int main()
{
	////ԭʼ���������Թ�
	//MazeGame_Original* Maze = new MazeGame_Original();
	//Maze->CreateMaze();
	
	////���󹤳����������Թ�
	//MazeFactory factory;
	//MazeGame_AbstractFactory* Maze = new MazeGame_AbstractFactory();
	//Maze->CreateMaze(factory);
	//delete Maze;

	////���󹤳�������������ը�����Թ�
	//BombedMazeFactory bombfactory;
	//MazeGame_AbstractFactory bobgame;
	//bobgame.CreateMaze(bombfactory);

	////���󹤳�������������ħ�����Թ�
	//EnchantedMazeFactory* enchantedfactory = new EnchantedMazeFactory;
	//MazeGame_AbstractFactory* enchantedgame = new MazeGame_AbstractFactory;
	//enchantedgame->CreateMaze(*enchantedfactory);
	//delete enchantedfactory;
	//delete enchantedgame;

	////���������Թ� 
	//MazeFactory* m = MazeFactory::Instance();
	//MazeGame_AbstractFactory SingletonMazeGame;
	//SingletonMazeGame.CreateMaze(*m);

	//Builder�����Թ�
	Maze* maze;
	cout << "1��MazeGame_Builder buildgame" << endl;
	MazeGame_Builder buildgame;
	cout << "2��StandardMazeBuilder builder" << endl;
	StandardMazeBuilder builder ;
	cout << "3��buildgame.CreateMaze(builder)" << endl;
	buildgame.CreateMaze(builder);
	cout << "4��maze = builder.GetMaze();" << endl;
	maze = builder.GetMaze();

	getchar();
	return 0;
}