//
//  Player.cpp is the Player class function implementation file.
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#include "Player.h"
#include "Form.h"
#include "Human.h"
#include "Otter.h"
#include "Magpie.h"
#include "Orangutan.h"
#include "SlowLoris.h"
#include "WolfSpider.h"
#include "Item.h"
#include "Room.h"
#include <vector>
#include <string>
#include <iostream>

// Constructor
Player::Player(Form startingForm)
{
	this->setForm(startingForm);
	this->setHumanAvail(true);
	this->setOtterAvail(false);
	this->setMagpieAvail(false);
	this->setOrangutanAvail(false);
	this->setSlowLorisAvail(false);
	this->setWolfSpiderAvail(false);
}


// Get functions
Form Player::getForm()
{
	return currentForm;
}

bool Player::getHumanAvail()
{
	return humanAvail;
}

bool Player::getOtterAvail()
{
	return otterAvail;
}

bool Player::getMagpieAvail()
{
	return magpieAvail;
}

bool Player::getOrangutanAvail()
{
	return orangutanAvail;
}

bool Player::getSlowLorisAvail()
{
	return slowLorisAvail;
}

bool Player::getWolfSpiderAvail()
{
	return wolfSpiderAvail;
}

std::vector<Item> Player::getInventory()
{
	return inventory;
}


// Set functions
void Player::setForm(Form newForm)
{
	currentForm = newForm;
}

void Player::setHumanAvail(bool isAvail)
{
	humanAvail = isAvail;
}

void Player::setOtterAvail(bool isAvail)
{
	otterAvail = isAvail;
}

void Player::setMagpieAvail(bool isAvail)
{
	magpieAvail = isAvail;
}

void Player::setOrangutanAvail(bool isAvail)
{
	orangutanAvail = isAvail;
}

void Player::setSlowLorisAvail(bool isAvail)
{
	slowLorisAvail = isAvail;
}

void Player::setWolfSpiderAvail(bool isAvail)
{
	wolfSpiderAvail = isAvail;
}


// Pick up junk item
void Player::pickUpItem(Item toPickUp)
{
	// If this item is the mysterious egg, display special message
	if(toPickUp.getName() == "Mysterious Egg")
	{
		std::cout << "You approach the egg and feel heat radiating off of it"
			<< " from several inches away. Odd, considering the temple has been"
			<< " submerged for centuries before now. You pick it up gently and"
			<< " the egg moves a little at your touch. Interesting."
			<< std::endl << std::endl;
	}

	// Add item to inventory vector
	inventory.push_back(toPickUp);
}

// Pick up token
void Player::pickUpToken(Item toPickUp)
{
	inventory.push_back(toPickUp);

	// Unlock appropriate animal form
	if(toPickUp.getAnimal() == "otter")
	{
		this->setOtterAvail(true);
		std::cout << "As you pick up the token, visions of mud slides and"
			<< " thick brown fur fill your mind. You can now transform"
			<< " into a river otter!" << std::endl;
	}
	else if(toPickUp.getAnimal() == "magpie")
	{
		this->setMagpieAvail(true);
		std::cout << "As you pick up the token, you become acutely aware of"
		 	<< " every shiny object in the vicinity. You can now transform"
		 	<< " into a magpie!" << std::endl;
	}
	else if(toPickUp.getAnimal() == "orangutan")
	{
		this->setOrangutanAvail(true);
		std::cout << "As you pick up the token, a flash of greenery and hot"
			<< ", sticky air runs through your mind. You can now transform"
			<< " into an orangutan!" << std::endl;
	}
	else if(toPickUp.getAnimal() == "slow loris")
	{
		this->setSlowLorisAvail(true);
		std::cout << "As you pick up the token, you immediately wonder what"
			<< " all the hurry was for, and have an odd hankering for some"
			<< " mealworms. You can now transform into a slow loris!"
			<< std::endl;
	}
	else if(toPickUp.getAnimal() == "wolf spider")
	{
		this->setWolfSpiderAvail(true);
		std::cout << "As you pick up the token, you suddenly feel very cool"
			<< ", confident, and stealthy -- and your arachnophobia"
			<< " eases a bit! You can now transform into a wolf spider!"
			<< std::endl;
	}
	else
	{
		std::cout << "You feel a little strange picking up this token, but"
			<< " you can't quite put a finger on why." << std::endl;
	}
}

// Drop item
void Player::dropItem(Item toDrop)
{
	for(size_t i = 0; i < inventory.size(); i)
	{
		if(inventory[i].getName() == toDrop.getName())
		{
			inventory.erase(inventory.begin() + i);
		}
		else
		{
			i++;
		}
	}
}

// Drop token
void Player::dropToken(Item toDrop)
{
	for(size_t i = 0; i < inventory.size(); i)
	{
		if(inventory[i].getName() == toDrop.getName())
		{
			inventory.erase(inventory.begin() + i);
		}
		else
		{
			i++;
		}
	}

	// Lock appropriate form
	if(toDrop.getAnimal() == "otter")
	{
		this->setOtterAvail(false);
		std::cout << "You can no longer transform into a river otter." << std::endl;
	}
	else if(toDrop.getAnimal() == "magpie")
	{
		this->setMagpieAvail(false);
		std::cout << "You can no longer transform into a magpie." << std::endl;
	}
	else if(toDrop.getAnimal() == "orangutan")
	{
		this->setOrangutanAvail(false);
		std::cout << "You can no longer transform into an orangutan." << std::endl;
	}
	else if(toDrop.getAnimal() == "slow loris")
	{
		this->setSlowLorisAvail(false);
		std::cout << "You can no longer transform into a slow loris." << std::endl;
	}
	else if(toDrop.getAnimal() == "wolf spider")
	{
		this->setWolfSpiderAvail(false);
		std::cout << "You can no longer transform into a wolf spider." << std::endl;
	}
	else
	{
		std::cout << "You feel a little strange dropping this token, but"
			<< " you can't quite put a finger on why." << std::endl;
	}
}

// Change form
void Player::changeForm(std::string formName, Human human, Otter otter, Magpie magpie,
		Orangutan orangutan, SlowLoris slowLoris, WolfSpider wolfSpider)
{
	// If player is already in that form, let them know
	if(formName == this->getForm().getName())
	{
		std::cout << "You are already in " << formName << " form." << std::endl
			<< std::endl;
	}

	// Make sure form is available, then set current form to new form
	else if(formName == "human" && this->getHumanAvail())
	{
		std::cout << "You transform back into a human, feeling strangely squishy"
			<< " and vulnerable." << std::endl << std::endl;
		this->setForm(human);
	}
	else if(formName == "river otter" && this->getOtterAvail())
	{
		std::cout << "You sprout thick brown fur and streeeetch like a weasel."
			<< " You've transformed into a river otter!"
			<< std::endl << std::endl;
		this->setForm(otter);
	}
	else if(formName == "magpie" && this->getMagpieAvail())
	{
		std::cout << "Suddenly, you're covered in black and white feathers"
			<< " and stand about a foot high. You have transformed into"
			<< " a magpie!" << std::endl << std::endl;
		this->setForm(magpie);
	}
	else if(formName == "orangutan" && this->getOrangutanAvail())
	{
		std::cout << "You grow to the size of a large human, but much stronger"
			<< " and covered in long orange hair. You are now an orangutan!"
			<< std::endl << std::endl;
		this->setForm(orangutan);
	}
	else if(formName == "slow loris" && this->getSlowLorisAvail())
	{
		std::cout << "Your eyes are suddenly huge! Your new form feels familiar,"
			<< " like a very small, very furry, very slowwww humanoid. You have"
			<< " transformed into a slow loris!" << std::endl << std::endl;
		this->setForm(slowLoris);
	}
	else if(formName == "wolf spider" && this->getWolfSpiderAvail())
	{
		std::cout << "You're furry, but not many people would call you cute."
			<< " You shrink down to a tiny size, but feel the cool confidence"
			<< " of an apex predator. You are now a wolf spider!" << std::endl
			<< std::endl;
		this->setForm(wolfSpider);
	}
	else
	{
		std::cout << "You concentrate really really hard... but nothing happens."
			<< std::endl << std::endl;
	}
}

bool Player::searchRoom(Room thisRoom)
{
	// If room's item vector is empty, let player know
	if(thisRoom.getItemsHere().empty())
	{
		std::cout << "You find no items of value in the room." << std::endl;
		return false;
	}

	// Otherwise, list items in the room
	else
	{
		std::cout << "You search the room and spot the following items: " << std::endl;
		for(size_t i = 0; i < thisRoom.getItemsHere().size(); i++)
		{
			std::cout << thisRoom.getItemsHere()[i].getName() << std::endl;
		}

		return true;
	}
}