//
//  GuardedRoom.cpp is the GuardedRoom class function implementation file.
//  GuardedRoom is a subclass of the abstract class Room.
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#include "Room.h"
#include "GuardedRoom.h"

GuardedRoom::GuardedRoom(int number)
{
	this->setRoomNumber(number);
	this->setNorth(NULL);
	this->setSouth(NULL);
	this->setEast(NULL);
	this->setWest(NULL);
	this->setDescription("Huge living statues fidget near the walls. You wonder how bored they must be. Luckily, they don't seem to notice you.");
	this->setRoomType("guarded");
}