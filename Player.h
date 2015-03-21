//
//  Player.h
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#ifndef PLAYER_H
#define PLAYER_H

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

class Player
{
public:
	// Constructor
	Player(Form startingForm);

	// Get functions
	Form getForm();
	bool getHumanAvail();
	bool getOtterAvail();
	bool getMagpieAvail();
	bool getOrangutanAvail();
	bool getSlowLorisAvail();
	bool getWolfSpiderAvail();
	std::vector<Item> getInventory();

	// Set functions
	void setForm(Form newForm);
	void setHumanAvail(bool isAvail);
	void setOtterAvail(bool isAvail);
	void setMagpieAvail(bool isAvail);
	void setOrangutanAvail(bool isAvail);
	void setSlowLorisAvail(bool isAvail);
	void setWolfSpiderAvail(bool isAvail);

	// Pick up item
	void pickUpItem(Item toPickUp);

	// Pick up token
	void pickUpToken(Item toPickUp);

	// Drop item
	void dropItem(Item toDrop);

	// Drop token
	void dropToken(Item toDrop);

	// Change form
	void changeForm(std::string formName, Human human, Otter otter, Magpie magpie,
		Orangutan orangutan, SlowLoris slowLoris, WolfSpider wolfSpider);

	// Search room
	bool searchRoom(Room thisRoom);

private:
	// Current form
	Form currentForm;

	// Inventory of items
	std::vector<Item> inventory;

	// Forms available
	bool humanAvail;
	bool otterAvail;
	bool magpieAvail;
	bool orangutanAvail;
	bool slowLorisAvail;
	bool wolfSpiderAvail;
};

#endif