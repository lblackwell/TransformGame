//
//  Item.cpp is the Item class function implementation file.
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/14/15
//

#include "Item.h"

// Constructor
Item::Item(std::string itemName, int itemValue, std::string itemType, std::string animalType)
{
	this->setName(itemName);
	this->setValue(itemValue);
	this->setType(itemType);
	this->setAnimal(animalType);
}

// Get functions
std::string Item::getName()
{
	return name;
}

int Item::getValue()
{
	return value;
}

std::string Item::getType()
{
	return type;
}

std::string Item::getAnimal()
{
	return animal;
}


// Set functions
void Item::setName(std::string newName)
{
	name = newName;
}

void Item::setValue(int newValue)
{
	value = newValue;
}

void Item::setType(std::string newType)
{
	type = newType;
}

void Item::setAnimal(std::string animalForm)
{
	animal = animalForm;
}