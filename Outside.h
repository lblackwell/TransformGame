//
//  Outside.h
//
//  Created by Lucia Blackwell on 3/14/15
//  Modified by Lucia Blackwell on 3/14/15
//

#ifndef OUTSIDE_H
#define OUTSIDE_H

#include <string>
#include <cstdlib>

class Outside: public Room
{
public:
	// Constructor
	Outside(int number);
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