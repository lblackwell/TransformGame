//
//  PlainRoom.cpp is the PlainRoom class function implementation file.
//  PlainRoom is a subclass of the abstract class Room.
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#include "Room.h"
#include "PlainRoom.h"

PlainRoom::PlainRoom(int number)
{
	this->setRoomNumber(number);
	this->setNorth(NULL);
	this->setSouth(NULL);
	this->setEast(NULL);
	this->setWest(NULL);
	this->setDescription("This room is mostly dry and well-lit. You appear to be alone.");
	this->setRoomType("plain");
}