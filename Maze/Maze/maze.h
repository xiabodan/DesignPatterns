#ifndef PART_H
#define PART_H

#include <iostream>
using namespace std;

enum Direction {North, South , East ,West};
//char c_Direction[4][10] = {"North", "South" , "East" ,"West"};

class MapSite{
public:
	virtual void Enter() = 0;
};

class Room :public MapSite{

public:
	Room(int rno){
		_roomNumber = rno;

		for(int i=0; i<4; ++i){
            _sides[i] = 0;
		}

		cout << "Room : This Room NO is : " << _roomNumber<< endl;
	}
	~Room(){
		cout << "Room : ~Room() " << endl;
	}


	MapSite* GetSide (Direction d) const{
		return _sides[d];
		//cout << "Room : This Room Direction is : " << c_Direction[d] << endl;
	}

	void SetSide(Direction d, MapSite* ms){

		if(_sides[d] != 0){
            delete _sides[d];
		}
        _sides[d] = ms;

		//cout << "Room : This Room Direction is : " << c_Direction[d] << endl;
	}

	virtual void Enter(){
		cout << "Room : Enter Room " << endl;
	}

	int ReturnRoomNo() const
    {
        return _roomNumber;
    }

private:
	MapSite* _sides[4];
	int _roomNumber;
};

class Wall : public MapSite{

public:
	Wall(){
		cout << "Wall : This is a Wall " << endl;
	}
	~Wall(){
		cout << "Wall : ~Wall() " << endl;
	}
	virtual void Enter(){
		cout << "Wall : Enter Room " << endl;
	}

};

class Door :public MapSite{

public:
	Door(Room* r1= 0, Room* r2=0){
		_room1 = r1;
		_room2 = r2;
		_isopen = false;
		cout << "Door :This Door is connect r1 and r2  " << endl;
	}
	~Door(){
		cout << "Door : ~Door() " << endl;
	}
	Room* OtherSideFrom(Room* r){
		
		if(r == _room1)
			return _room2;
		else if(r = _room2)
			return _room1;
	}
	virtual void Enter(){
		cout << "Door : Enter Room " << endl;
	}

private:
	Room* _room1;
	Room* _room2;
	bool _isopen;
};

class Maze{

public:
	Maze(){
		_roomList =  new Room*;
		cout << "Maze : Maze() " << endl;
	}

	~Maze(){
		cout << "Maze : ~Maze() " << endl;
	}
	void AddRoom(Room* r){
		int rno = r->ReturnRoomNo();
        _roomList[rno] = r;
	}

	Room* RoomNo(int rno) const{
        if(_roomList[rno] == NULL)
            return 0;
        if(_roomList[rno]->ReturnRoomNo() == rno)
            return _roomList[rno];

        return 0;
	}
	int XSize() const
    {
        return _xsize;
    }
    int YSzie() const
    {
        return _ysize;
    }
    int Size() const
    {
        return _xsize*_ysize;
    }

private:
	int _xsize;
    int _ysize;
	Room** _roomList;
	//...
};


//施魔法实例类
class Spell{

public:
	Spell(){
		cout <<  "Spell : I am Spell ! " << endl;
	}

	~Spell(){
		cout <<  "Spell : ~Spell() ! " << endl;
	}
};

class EnchantedRoom : public Room
{
public:
	EnchantedRoom(int rno,Spell* spell)
		:Room(rno)
	{
		cout << "EnchantedRoom : EnchantedRoom() " << endl;
		_spell = spell;
	}
	~EnchantedRoom(){
		cout << "EnchantedRoom : ~EnchantedRoom() " << endl;
	}

	virtual void Enter(){

	}

private:
	Spell* _spell;
};

class DoorNeedingSpell:public Door
{
public:
    DoorNeedingSpell(Room* r1, Room* r2)
		:Door(r1, r2)
	{
		cout << "DoorNeedingSpell : DoorNeedingSpell()" <<endl;
    }
	~DoorNeedingSpell(){
		cout << "DoorNeedingSpell : ~DoorNeedingSpell()" <<endl;
    }
    virtual void Enter(){
    
    }

};

//添加炸弹类
class RoomWithABomb: public Room
{
public:
    RoomWithABomb(int rno)
		:Room(rno)
	{
		cout << "RoomWithABomb : RoomWithABomb()" << endl;
    }
	~RoomWithABomb(){
		cout << "RoomWithABomb : ~RoomWithABomb()" << endl;
    }
    virtual void Enter(){
    
    }
};

class BombedWall:public Wall
{
public:
    BombedWall(){
		cout << "BombedWall : BombedWall()" << endl;
    }
	~BombedWall(){
		cout << "BombedWall : ~BombedWall()" << endl;
    }
    virtual void Enter(){
    
    }

};

//原始方法创建普通迷宫
class MazeGame_Original {

public:
	Maze* CreateMaze(){
		Maze* aMaze = new Maze;
		Room* r1 = new Room(1);
		Room* r2 = new Room(2);
		Door* theDoor  = new Door(r1,r2);

		aMaze->AddRoom(r1);
		aMaze->AddRoom(r2);

		r1->SetSide(North, new Wall);
		r1->SetSide(East, theDoor);
		r1->SetSide(South, new Wall);
		r1->SetSide(West, new Wall);

		
		r2->SetSide(North, new Wall);
		r2->SetSide(East, new Wall);
		r2->SetSide(South, new Wall);
		r2->SetSide(West, theDoor );

		return aMaze;
	}

};

#endif