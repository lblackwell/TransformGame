//
//  PlainRoom.h
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#ifndef PLAINROOM_H
#define PLAINROOM_H

#include <string>
#include <cstdlib>

class PlainRoom: public Room
{
public:
	// Constructor
	PlainRoom(int number);
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
};

#endif