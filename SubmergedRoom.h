//
//  SubmergedRoom.h
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#ifndef SUBMERGEDROOM_H
#define SUBMERGEDROOM_H

#include <string>
#include <cstdlib>

class SubmergedRoom: public Room
{
public:
	// Constructor
	SubmergedRoom(int number);
	
private:
	// Room number
	int roomNumber;

	// Room to the north
	Room *north;

	// Room to the south
	Room *south;

	// Room to the east
	Room *east;

	// Room to the west
	Room *west;

	// Description
	std::string description;

	// Type
	std::string roomType;

	// Items in room
	std::vector<Item> itemsHere;

	// Actions until drowning
	int airLeft;
};

#endif