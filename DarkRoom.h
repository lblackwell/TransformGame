//
//  DarkRoom.h
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#ifndef DARKROOM_H
#define DARKROOM_H

#include <string>
#include <cstdlib>

class DarkRoom: public Room
{
public:
	// Constructor
	DarkRoom(int number);

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

	// Description for low-light vision forms
	std::string canSeeDescription;

	// Type
	std::string roomType;

	// Items in room
	std::vector<Item> itemsHere;
};

#endif