//
//  Outside.cpp is the Outside class function implementation file.
//  Outside is a subclass of the abstract class Room.
//
//  Created by Lucia Blackwell on 3/14/15
//  Modified by Lucia Blackwell on 3/14/15
//

#include "Room.h"
#include "Outside.h"

Outside::Outside(int number)
{
	this->setRoomNumber(number);
	this->setNorth(NULL);
	this->setSouth(NULL);
	this->setEast(NULL);
	this->setWest(NULL);
	this->setDescription("You've made it back outside!");
	this->setRoomType("outside");
}