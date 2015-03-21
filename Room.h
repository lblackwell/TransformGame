//
//  Room.h
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <vector>
#include "Item.h"

class Room
{
public:
	// Get functions
	virtual int getRoomNumber() const;
	virtual Room* getNorth() const;
	virtual Room* getSouth() const;
	virtual Room* getEast() const;
	virtual Room* getWest() const;
	virtual std::string getDescription() const;
	virtual std::string getRoomType() const;
	virtual std::vector<Item> getItemsHere() const;
	virtual int getAirLeft() const;
	virtual std::string getCanSeeDesc() const;

	// Set functions
	virtual void setNorth(Room *toNorth);
	virtual void setSouth(Room *toSouth);
	virtual void setEast(Room *toEast);
	virtual void setWest(Room *toWest);
	virtual void setRoomNumber(int roomNum);
	virtual void setDescription(std::string desc);
	virtual void setRoomType(std::string rmType);
	virtual void setAirLeft(int newAirLeft);
	virtual void setCanSeeDesc(std::string seeDesc);

	// Add item to room
	virtual void addItem(Item toAdd);

	// Remove item from room
	virtual void removeItem(Item toRemove);
	
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

	// Air left
	int airLeft;

	// Description for low-light vision forms
	std::string canSeeDescription;
};

#endif