//
//  DarkRoom.cpp is the DarkRoom class function implementation file.
//  DarkRoom is a subclass of the abstract class Room.
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#include "Room.h"
#include "DarkRoom.h"

DarkRoom::DarkRoom(int number)
{
	this->setRoomNumber(number);
	this->setNorth(NULL);
	this->setSouth(NULL);
	this->setEast(NULL);
	this->setWest(NULL);
	this->setDescription("This room is almost completely dark; barely any light filters in from the doorways.");
	this->setCanSeeDesc("The room is dark, but your current form's eyes see just fine.");
	this->setRoomType("dark");
}