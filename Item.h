//
//  Item.h
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/14/15
//

#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item
{
public:
	// Constructor
	Item(std::string itemName, int itemValue, std::string itemType, std::string animalType);

	// Get functions
	std::string getName();
	int getValue();
	std::string getType();
	std::string getAnimal();

	// Set functions
	void setName(std::string newName);
	void setValue(int setValue);
	void setType(std::string newType);
	void setAnimal(std::string animalForm);

private:
	std::string name;
	int value;
	std::string type;
	std::string animal;
};

#endif