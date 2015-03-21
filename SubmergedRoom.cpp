//
//  SubmergedRoom.cpp is the SubmergedRoom class function implementation file.
//  SubmergedRoom is a subclass of the abstract class Room.
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#include "Room.h"
#include "SubmergedRoom.h"

SubmergedRoom::SubmergedRoom(int number)
{
	this->setRoomNumber(number);
	this->setNorth(NULL);
	this->setSouth(NULL);
	this->setEast(NULL);
	this->setWest(NULL);
	this->setDescription("The entire room is submerged. You hold your breath and dive, at ease in the water in your current form.");
	this->setRoomType("submerged");
	this->setAirLeft(4);
}