#ifndef MAZEFACTORY_H
#define MAZEFACTORY_H

#include "maze.h"

//抽象工厂方法创建普通迷宫，只有房子和门，墙
//3.5 Singeleton（单例模式）
class MazeFactory{
public:
	static MazeFactory* Instance();
public:
	virtual Maze* MakeMaze() const{
		return new Maze; 
	}
	virtual Wall* MakeWall() const{
		return new Wall;
	}
	virtual Room* MakeRoom(int n) const{
		return new Room(n); 
	}
	virtual Door* MakeDoor(Room* r1, Room* r2) const{
		return new Door(r1,r2);
	}
protected:   //单例模式
	MazeFactory(){
		cout << "MazeFactory : MazeFactory()" << endl;
	}
	~MazeFactory(){
		cout << "MazeFactory : ~MazeFactory()" << endl;
	}
private:
	static MazeFactory* _instance;

};



//创建魔法迷宫
class EnchantedMazeFactory : public MazeFactory
{
public:
	EnchantedMazeFactory(){
		cout << "EnchantedMazeFactory : EnchantedMazeFactory()" << endl;
	}
	~EnchantedMazeFactory(){
		cout << "EnchantedMazeFactory : ~EnchantedMazeFactory()" << endl;
	}

	virtual Room* MakeRoom(int n ) const{
		return new EnchantedRoom(n, CastSpell());
	}

	virtual Door* MakeDoor(Room* r1, Room* r2) const{
		return new DoorNeedingSpell(r1, r2);
	}

protected:
	Spell* CastSpell() const{
		return 0;
	}

};
//创建含有炸弹的迷宫
class BombedMazeFactory : public MazeFactory{

public:
	BombedMazeFactory(){
		cout << "BombedMazeFactory : BombedMazeFactory()" << endl;
	}
	~BombedMazeFactory(){
		cout << "BombedMazeFactory : ~BombedMazeFactory()" << endl;
	}

	virtual Room* MakeRoom(int rno ) const{
		return new RoomWithABomb(rno);
	}

	virtual Wall* MakeWall() const {
		return new BombedWall();
	}
};

//抽象工厂创建迷宫
class MazeGame_AbstractFactory {
public:
	MazeGame_AbstractFactory(){
		cout << "MazeGame : MazeGame()" << endl;
	}
	~MazeGame_AbstractFactory(){
		cout << "MazeGame : ~MazeGame()" << endl;
	}

	Maze* CreateMaze(MazeFactory& factory){
		Maze* aMaze = factory.MakeMaze();
		Room* r1	= factory.MakeRoom(1);
		Room* r2	= factory.MakeRoom(2);
		Door* aDoor	= factory.MakeDoor(r1,r2);

		aMaze->AddRoom(r1);
		aMaze->AddRoom(r2);

		r1->SetSide(North, factory.MakeWall());
		r1->SetSide(East,  aDoor);
		r1->SetSide(South, factory.MakeWall());
		r1->SetSide(West,  factory.MakeWall());

		
		r2->SetSide(North, factory.MakeWall());
		r2->SetSide(East,  factory.MakeWall());
		r2->SetSide(South, factory.MakeWall());
		r2->SetSide(West,  aDoor );

		return aMaze;

	}
};

//3.2 Builder (生成器)
class MazeBuilder{

public:
	virtual void BuildMaze() = 0;
	/*{
		_maze = new Maze();
		_factory = MazeFactory::Instance();
		cout << "MazeBuilder : BuildMaze()" << endl;
	}*/
	virtual void BuildRoom(int room) = 0;
	/*{
		cout << "MazeBuilder : BuildRoom()" << endl;
	}*/
	virtual void BuildDoor(int roomFrom, int roomTo) = 0;
	/*{
		cout << "MazeBuilder : BuildDoor()" << endl;
	}*/
	virtual Maze* GetMaze() = 0;
	/*{
		return _maze;
	}*/
protected:
	MazeBuilder(){
		//BuildMaze();
		cout << "MazeBuilder : MazeBuilder() " <<endl;
	}
	~MazeBuilder(){
		
		cout << "MazeBuilder : ~MazeBuilder() " <<endl;
	}
private:
	Maze* _maze;
	MazeFactory* _factory;
};


class StandardMazeBuilder : public MazeBuilder{
public:
	StandardMazeBuilder(){
		_currentMaze = 0;
		cout << "StandardMazeBuilder : StandardMazeBuilder()" << endl;
	}
	~StandardMazeBuilder(){
		cout << "StandardMazeBuilder : ~StandardMazeBuilder()" << endl;
	}

	virtual void BuildMaze(){
		_currentMaze = new Maze;
		cout << "StandardMazeBuilder : BuildMaze()" << endl;
	}
	virtual void BuildRoom(int n){
		//if(!_currentMaze->RoomNo(n))
		{
			Room* room = new Room(n);
			_currentMaze->AddRoom(room);

			room->SetSide(North,new Wall);
			room->SetSide(South,new Wall);
			room->SetSide(East ,new Wall);
			room->SetSide(West ,new Wall);
		}
		cout << "StandardMazeBuilder : BuildRoom()" << endl;
	}
	virtual void BuildDoor(int roomFrom, int roomTo){
		Room* r1 = _currentMaze->RoomNo(roomFrom);
		Room* r2 = _currentMaze->RoomNo(roomTo);
		Door* d  = new Door(r1,r2);

		r1->SetSide(CommonWall(r1,r2),d);
		r1->SetSide(CommonWall(r2,r1),d);

		cout << "StandardMazeBuilder : BuildDoor()" << endl;
	}
	virtual Maze* GetMaze(){
		return _currentMaze;
	} 
private:
	Direction CommonWall(Room* r1,Room* r2){
		int xs = _currentMaze->XSize();
        Direction dir;
        if(r1->ReturnRoomNo()+1 == r2->ReturnRoomNo())
            dir = East;
        if(r1->ReturnRoomNo()-1 == r2->ReturnRoomNo())
            dir = West;
        if(r1->ReturnRoomNo()-xs == r2->ReturnRoomNo())
            dir = North;
        if(r1->ReturnRoomNo()+xs == r2->ReturnRoomNo())
            dir = South;
        return dir;
	}
	Maze* _currentMaze;
};

//Builder创建迷宫
class MazeGame_Builder{
public:
	Maze* CreateMaze(MazeBuilder& builder){
		builder.BuildMaze();
		builder.BuildRoom(1);
		builder.BuildRoom(2);
		builder.BuildDoor(1,2);

		return builder.GetMaze();
	}

	Maze* CreateComplexMaze(MazeBuilder& builder){
		builder.BuildRoom(1);
		//....
		builder.BuildRoom(100);

		return builder.GetMaze();
	}
};

#endif