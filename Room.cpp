//
//  Room.cpp is the Room class function implementation file.
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#include "Room.h"
#include "Item.h"
#include <vector>

// Get functions
int Room::getRoomNumber() const
{
	return roomNumber;
}

Room* Room::getNorth() const
{
	return north;
}

Room* Room::getSouth() const
{
	return south;
}

Room* Room::getEast() const
{
	return east;
}

Room* Room::getWest() const
{
	return west;
}

std::string Room::getDescription() const
{
	return description;
}

std::string Room::getRoomType() const
{
	return roomType;
}

std::vector<Item> Room::getItemsHere() const
{
	return itemsHere;
}

int Room::getAirLeft() const
{
	return airLeft;
}

std::string Room::getCanSeeDesc() const
{
	return canSeeDescription;
}


// Set functions
void Room::setNorth(Room *toNorth)
{
	north = toNorth;
}

void Room::setSouth(Room *toSouth)
{
	south = toSouth;
}

void Room::setEast(Room *toEast)
{
	east = toEast;
}

void Room::setWest(Room *toWest)
{
	west = toWest;
}

void Room::setRoomNumber(int roomNum)
{
	roomNumber = roomNum;
}

void Room::setDescription(std::string desc)
{
	description = desc;
}

void Room::setRoomType(std::string rmType)
{
	roomType = rmType;
}

void Room::setCanSeeDesc(std::string seeDesc)
{
	canSeeDescription = seeDesc;
}


// Add item to room
void Room::addItem(Item toAdd)
{
	itemsHere.push_back(toAdd);
}

// Remove item from room
void Room::removeItem(Item toRemove)
{
	for(size_t i = 0; i < itemsHere.size(); i)
	{
		if(itemsHere[i].getName() == toRemove.getName())
		{
			itemsHere.erase(itemsHere.begin() + i);
		}
		else
		{
			i++;
		}
	}
}

void Room::setAirLeft(int newAirLeft)
{
	airLeft = newAirLeft;
}