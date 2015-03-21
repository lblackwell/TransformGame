/* **********************************************************************
 * Author:   Lucia Blackwell
 * Created:  March 13, 2015
 * Modified: March 14, 2015
 * Filename: game.cpp
 *
 * Overview: SUPER TRANSFORMING ISLAND DELUXE OF GREAT GOOD takes place
 *           in a mysterious sinking temple. The player moves from room
 *           to room, collecting items and searching for the temple's
 *           secret, most valuable item.
 *
 *           The player will encounter barriers which must be overcome
 *           by transforming into different animal forms. Forms are
 *           unlocked by picking up corresponding animal tokens.
 *
 * Input:    The player will input commands, generally a single digit
 *           or character at a time.
 *
 *           Example input: 'W' to move west
 *
 * Output:   The program will narrate the player's journey through
 *           the temple.
 *
 *           Example output: The temple feels unsteady. You estimate you
 *                           can take about 80 more actions until it
 *                           slips back into the sea.
 *
 *                           This room is mostly dry and well-lit. You
 *                           appear to be alone.
 *                           There are doors in the following directions:
 *                           South
 *                           East
 *                           West
 *
 *                           What will you do? (1 - search room, 2 -
 *                           move on, 3 - view inventory, 4 - drop item):
 *
 * *********************************************************************/

#include <iostream>
#include <string>
#include "Room.h"
#include "PlainRoom.h"
#include "SubmergedRoom.h"
#include "DarkRoom.h"
#include "GuardedRoom.h"
#include "Outside.h"
#include "Form.h"
#include "Human.h"
#include "Otter.h"
#include "Magpie.h"
#include "Orangutan.h"
#include "SlowLoris.h"
#include "WolfSpider.h"
#include "Player.h"
#include "Item.h"

/////////////////////////////////////////
// Function prototypes //////////////////
/////////////////////////////////////////

char getDirection();
void nextIsSubmerged();
char nextIsGuarded();
char nextIsOutside();

/////////////////////////////////////////
// Main function ////////////////////////
/////////////////////////////////////////
int main()
{
	// Create rooms
	SubmergedRoom room1(1);
	PlainRoom room2(2);
	PlainRoom room3(3);
	PlainRoom room4(4);
	PlainRoom room5(5);
	PlainRoom room6(6);
	GuardedRoom room7(7);
	PlainRoom room8(8);
	DarkRoom room9(9);
	PlainRoom room10(10);
	Outside room11(11);

	// Set links
	room1.setSouth(&room3);
	room2.setEast(&room3);
	room2.setSouth(&room6);
	room3.setNorth(&room1);
	room3.setSouth(&room7);
	room3.setEast(&room4);
	room3.setWest(&room2);
	room4.setSouth(&room8);
	room4.setEast(&room11);
	room4.setWest(&room3);
	room5.setEast(&room6);
	room6.setNorth(&room2);
	room6.setSouth(&room9);
	room6.setWest(&room5);
	room7.setNorth(&room3);
	room7.setEast(&room8);
	room8.setNorth(&room4);
	room8.setWest(&room7);
	room9.setNorth(&room6);
	room9.setEast(&room10);
	room10.setWest(&room9);
	room11.setWest(&room4);

	// Create forms
	Human human;
	Otter otter;
	Magpie magpie;
	Orangutan orangutan;
	SlowLoris slowloris;
	WolfSpider wolfspider;

	// Create tokens
	Item otterToken("River Otter Token", 0, "token", "otter");
	Item magpieToken("Magpie Token", 0, "token", "magpie");
	Item orangutanToken("Orangutan Token", 0, "token", "orangutan");
	Item slowLorisToken("Slow Loris Token", 0, "token", "slow loris");
	Item wolfSpiderToken("Wolf Spider Token", 0, "token", "wolf spider");

	// Create trinkets
	Item urn("Porcelain Urn", 225, "trinket", "no");
	Item ancientPants("Torn Pants", 5, "trinket", "no");
	Item doll("Doll", 25, "trinket", "no");
	Item sapphire("Cut Sapphire", 300, "trinket", "no");
	Item seaweed("Soggy Seaweed", 1, "trinket", "no");
	Item crown("Jeweled Crown", 500, "trinket", "no");
	Item statuette("Carved Statuette", 150, "trinket", "no");
	Item mysteriousEgg("Mysterious Egg", 0, "trinket", "no");

	// Place tokens in rooms
	room7.addItem(otterToken);
	room9.addItem(magpieToken);
	room8.addItem(orangutanToken);
	room1.addItem(slowLorisToken);
	room2.addItem(wolfSpiderToken);

	// Place trinkets in rooms
	room10.addItem(urn);
	room10.addItem(crown);
	room7.addItem(statuette);
	room7.addItem(ancientPants);
	room1.addItem(seaweed);
	room9.addItem(doll);
	room9.addItem(sapphire);
	room5.addItem(mysteriousEgg);

	// Create player
	Player player(human);

	// Direction player has chosen to move
	char goThisWay;

	// Keep going? (used for guarded room)
	char keepGoing = 'x';

	// What will the player do now?
	int whatNow = 0;

	// Did the player find items in the room?
	bool itemsHere = false;

	// Has the player found an alternate form yet?
	bool newForm = false;

	// Items to pick up and drop
	std::string pickThisUp;
	std::string dropThis;

	// Form to take
	int formChoice = 0;

	// Choose whether to display room numbers
	bool showNums = false;

	// Trigger game over and exit game loop
	bool gameOver = false;

	// Did the player die a horrible death?
	bool playerDied = false;

	// Turns until temple sinks
	int turnsUntilGameOver = 80;

	// Barrier
	bool room6Barrier = true;

	// Current location -- start in room four
	Room currentLocation = room4;

	int mainMenuOpt = 0;

	// Main menu
	std::cout << "SUPER TRANSFORMING ISLAND DELUXE OF GREAT GOOD" << std::endl << std::endl;
	while(mainMenuOpt != 3)
	{
		if(!showNums)
		{
			std::cout << "1 - Turn on room numbers" << std::endl;
		}
		else
		{
			std::cout << "1 - Turn off room numbers" << std::endl;
		}

		std::cout << "2 - Game spoilers" << std::endl;
		std::cout << "3 - Start game" << std::endl;

		std::cin >> mainMenuOpt;
		std::cin.clear();
		std::cin.ignore(999, '\n');
		std::cout << std::endl;

		if(mainMenuOpt == 1 && !showNums)
		{
			showNums = true;
		}

		else if(mainMenuOpt == 1 && showNums)
		{
			showNums = false;
		}

		else if(mainMenuOpt == 2)
		{
			std::cout << "The objective of the game is to get out of the temple"
				<< " before the island sinks back into the ocean. You have 80 "
				<< "actions to do so. You will find tokens which allow you to "
				<< "change into different animals in order to solve problems."
				<< std::endl << std::endl;
			std::cout << "You will need:" << std::endl;
			std::cout << "Submerged room: river otter" << std::endl;
			std::cout << "Guarded room: wolf spider" << std::endl;
			std::cout << "Dark room: slow loris" << std::endl;
			std::cout << "High door: magpie" << std::endl;
			std::cout << "Barrier: orangutan" << std::endl;
			std::cout << "Small door: small creature (anything but human and orangutan)"
				<< std::endl << std::endl;
			std::cout << "There is a dragon egg in room 5: it's the game's main prize."
				<< " Other items can be collected and their values will be totaled"
				<< " when the player exits the temple successfully." << std::endl;
			std::cout << std::endl << "Thanks for playing!" << std::endl << std::endl;
		}
	}


	// Starting text
	std::cout << std::endl;
	std::cout << "You are entering an ancient temple on a previously undiscovered"
		<< " island which recently appeared suddenly and mysteriously just offshore"
		<< " of a small jungle nation." << std::endl << std::endl;
	std::cout << "The island appears ready to re-submerge at any moment, but markings"
		<< " on the outside of the temple indicate something valuable may be inside."
		<< std::endl << std::endl;

	// Game loop: continue until the exit is reached
	while(gameOver == false && currentLocation.getRoomType() != "outside")
	{
		// If the player has entered a guarded room and isn't stealthy, trigger game over
		if(currentLocation.getRoomType() == "guarded" && !player.getForm().getIsStealthy())
		{
			gameOver = true;
			playerDied = true;

			std::cout << "The living statues notice you immediately."
				<< " Turns out they're very effective guardians. It isn't pretty."
				<< std::endl << std::endl;

			break;
		}

		// If player is underwater:
		if(currentLocation.getRoomType() == "submerged")
		{
			// Decrement air left by one
			currentLocation.setAirLeft(currentLocation.getAirLeft() - 1);

			// If player is out of air, they drown. Game over.
			if(currentLocation.getAirLeft() <= 0)
			{
				std::cout << "Even your aquatic form can't stay underwater forever."
					<< " Unfortunately, you've learned that the hard way."
					<< std::endl << std::endl;
					
				gameOver = true;
				playerDied = true;

				break;
			}

			else
			{
				//Let them know how much air they have left
				std::cout << "You're holding your breath. You have enough air left"
					<< " for " << currentLocation.getAirLeft() << " more actions."
					<< std::endl << std::endl;
			}
		}

		// Reset variables
		keepGoing = 'x';
		whatNow = 0;

		// Report actions left until temple sinks
		std::cout << "The temple feels unsteady. You estimate you can take "
			<< turnsUntilGameOver << " more actions until it slips back into"
			<< " the sea." << std::endl;

		// Tell player where they are, if they have chosen to display numbers
		if(showNums)
		{
			std::cout << "You are in room " << currentLocation.getRoomNumber()
				<< ". " << std::endl;
		}

		// Display the room's description
		std::cout << std::endl;
		// If room is dark and form can still see, display special description
		if(currentLocation.getRoomType() == "dark" && player.getForm().getCanSeeInDark())
		{
			std::cout << currentLocation.getCanSeeDesc() << std::endl;
		}
		// Otherwise, display normal description
		else
		{
			std::cout << currentLocation.getDescription() << std::endl;
		}

		// Display current form, after first token is discovered
		if(newForm)
		{
			std::cout << "Current form: " << player.getForm().getName()
				<< std::endl << std::endl;
		}
		
		// Tell the player where the doors are
		std::cout << "There are doors in the following directions:" << std::endl;

		if(currentLocation.getNorth() != NULL)
		{
			// If player is in room 6, this door is small
			if(currentLocation.getRoomNumber() == 6)
			{
				std::cout << "North... but it is too small for a human!" << std::endl;
			}
			else
			{
				std::cout << "North" << std::endl;
			}
		}

		if(currentLocation.getSouth() != NULL)
		{
			// If player is in room 2, this door is small
			if(currentLocation.getRoomNumber() == 2)
			{
				std::cout << "South... but it is too small for a human!" << std::endl;
			}
			
			// If player is in room 6, this door is barricaded
			else if(currentLocation.getRoomNumber() == 6)
			{
				std::cout << "South... but the door is blockaded with thick wooden beams."
					<< std::endl;
			}

			else
			{
				std::cout << "South" << std::endl;
			}
		}

		if(currentLocation.getEast() != NULL)
		{
			// If player is in room 5, it's a long way down
			if(currentLocation.getRoomNumber() == 5)
			{
				std::cout << "East... but it's a long way down.'" << std::endl;
			}
			else
			{
				std::cout << "East" << std::endl;
			}
		}

		if(currentLocation.getWest() != NULL)
		{
			// If player is in room 6, this door is up high
			if(currentLocation.getRoomNumber() == 6)
			{
				std::cout << "West... but it is about twenty feet up the very smooth wall!" << std::endl;
			}
			else
			{
				std::cout << "West" << std::endl;
			}
		}

		std::cout << std::endl;

		// Give player options: search room or move on
		while(whatNow != 1 && whatNow != 2 && whatNow != 3 && whatNow != 4 && whatNow != 5 && whatNow != 6)
		{
			// If player has not found items here, don't give pick up option
			// If player has not found an animal token, don't give transform option
			if(!itemsHere && !newForm)
			{
				std::cout << "What will you do? (1 - search room, 2 - move on, 3 - view inventory, 4 - drop item): ";
			}
			// If player has searched but has no alternate forms:
			else if(itemsHere && !newForm)
			{
				std::cout << "What will you do?"
					<< " (1 - search room, 2 - move on, 3 - view inventory, 4 - drop item, 5 - pick up item): ";
			}
			// If player has not searched and does have alternate forms:
			else if(!itemsHere && newForm)
			{
				std::cout << "What will you do? (1 - search room, 2 - move on, 3 - view inventory, 4 - drop item, 6 - transform): ";
			}

			// If player has searchand and has alternate forms:
			else
			{
				std::cout << "What will you do?"
					<< " (1 - search room, 2 - move on, 3 - view inventory, 4 - drop item, 5 - pick up item, 6 - transform): ";
			}

			std::cin >> whatNow;
			std::cin.clear();
			std::cin.ignore(999, '\n');
			std::cout << std::endl;
		}

		// Search room option
		if(whatNow == 1)
		{
			// If room is dark, require low light vision to search
			if(currentLocation.getRoomType() == "dark" && !player.getForm().getCanSeeInDark())
			{
				std::cout << "It's too dark for you to search in your current form."
					<< std::endl;
			}

			// Otherwise, allow search
			else
			{
				itemsHere = player.searchRoom(currentLocation);
				std::cout << std::endl;
			}
		}

		// Move option
		else if(whatNow == 2)
		{
			// Get movement
			goThisWay = getDirection();
			
			std::cout << std::endl;

			// Clear items found in room
			itemsHere = false;

			// Move player
			if(goThisWay == 'N' && currentLocation.getNorth() != NULL)
			{
				// If player is using north door in room 6, form must be small
				if(currentLocation.getRoomNumber() == 6 && player.getForm().getSize() != "small")
				{
					std::cout << "You are too big to use that door!" << std::endl
						<< std::endl;
				}

				else
				{
					// If the next room is submerged, tell the player and don't move
					Room nextRoom = *(currentLocation.getNorth());
					if(nextRoom.getRoomType() == "submerged"
							&& !player.getForm().getCanSwim())
					{
						nextIsSubmerged();
					}

					// Otherwise, move normally
					else
					{
					std::cout << "You enter the door to the north." << std::endl << std::endl;
					currentLocation = *(currentLocation.getNorth());
					}
				}
			}
			else if(goThisWay == 'S' && currentLocation.getSouth() != NULL)
			{
				// If player is using south door in room 2, form must be small
				if(currentLocation.getRoomNumber() == 2 && player.getForm().getSize() != "small")
				{
					std::cout << "You are too big to use that door!" << std::endl
						<< std::endl;
				}

				// If player is using south door in room 6, must first smash barrier
				else if(currentLocation.getRoomNumber() == 6 && room6Barrier)
				{
					// Strong form may smash barrier
					if(player.getForm().getIsStrong())
					{
						std::cout << "You smash through the wooden barrier like"
							<< " it's made of toothpicks! The way is now clear."
							<< " You enter the door to the south." << std::endl
							<< std::endl;
						room6Barrier = false;
						currentLocation = *(currentLocation.getSouth());
					}
					// Weak form is stuck here
					else
					{
						std::cout << "Your current form is too weak to contend"
							<< " with the barrier." << std::endl << std::endl;
					}
				}

				else
				{
					// If player is exiting submerged room, reset air left
					if(currentLocation.getRoomType() == "submerged")
					{
						currentLocation.setAirLeft(4);
					}

					// If the next room is guarded, warn the player
					Room nextRoom = *(currentLocation.getSouth());
					if(nextRoom.getRoomType() == "guarded")
					{
						keepGoing = nextIsGuarded();
					}

					// Enter the room unless player has decided not to
					if(keepGoing != 'N')
					{
						std::cout << "You enter the door to the south." << std::endl << std::endl;
						currentLocation = *(currentLocation.getSouth());
					}
				}				
			}
			else if(goThisWay == 'E' && currentLocation.getEast() != NULL)
			{
				// If player is using east door in room 5, form must be able to fly
				if(currentLocation.getRoomNumber() == 5 && !player.getForm().getCanFly())
				{
					std::cout << "That's an awfully long fall. Better not jump."
						<< std::endl << std::endl;
				}

				else
				{
					// If the next room is outside, warn the player this will end game
					Room nextRoom = *(currentLocation.getEast());
					if(nextRoom.getRoomType() == "outside")
					{
						keepGoing = nextIsOutside();
					}

					// Enter the room unless player has decided not to
					if(keepGoing != 'N')
					{
						std::cout << "You enter the door to the east." << std::endl << std::endl;
						currentLocation = *(currentLocation.getEast());
					}
				}
			}
			else if(goThisWay == 'W' && currentLocation.getWest() != NULL)
			{
				// If player is using west door in room 6, form must be able to fly
				if(currentLocation.getRoomNumber() == 6 && !player.getForm().getCanFly())
				{
					std::cout << "The door is too high up to get to." << std::endl
						<< std::endl;
				}

				else
				{
					// If the next room is guarded, warn the player
					Room nextRoom = *(currentLocation.getWest());
					if(nextRoom.getRoomType() == "guarded")
					{
						keepGoing = nextIsGuarded();
					}

					// Enter the room unless player has decided not to
					if(keepGoing != 'N')
					{
						std::cout << "You enter the door to the west." << std::endl << std::endl;
						currentLocation = *(currentLocation.getWest());
					}
				}
				
			}
			else
			{
				std::cout << "You cannot go that way." << std::endl;
			}
		}

		// View inventory option
		else if(whatNow == 3)
		{
			// If inventory is empty, let player know
			if(player.getInventory().empty())
			{
				std::cout << "Your bag is empty." << std::endl;
			}

			// If inventory isn't empty, list contents
			else
			{
				std::cout << "You are carrying the following items:" << std::endl;
				for(int i = 0; i < player.getInventory().size(); i++)
				{
					std::cout << player.getInventory()[i].getName() << std::endl;
				}

				std::cout << std::endl;
				
				// Tell player how much more space they have
				std::cout << "Your bag can hold " << 10 - player.getInventory().size()
					<< " more items." << std::endl << std::endl;
			}
		}

		// Drop item option
		else if(whatNow == 4)
		{
			// If inventory is empty, let player know
			if(player.getInventory().empty())
			{
				std::cout << "Your bag is empty." << std::endl << std::endl;
			}

			// Otherwise, ask player which item to drop
			else
			{
				bool itemFound = false;

				std::cout << "Drop which item?: ";
				getline(std::cin, dropThis);

				// Compare item name to items in inventory
				for(int i = 0; i < player.getInventory().size(); i)
				{
					if(player.getInventory()[i].getName() == dropThis)
					{
						// Flag item was found
						itemFound = true;
						
						// Add item to room
						currentLocation.addItem(player.getInventory()[i]);

						// Remove item from player's inventory

						// If item is a token:
						if(player.getInventory()[i].getType() == "token")
						{
							player.dropToken(player.getInventory()[i]);
						}

						// Other items:
						else
						{
							player.dropItem(player.getInventory()[i]);
						}

						std::cout << "Dropped " << dropThis << "." << std::endl
							<< std::endl;
					}
					else
					{
						i++;
					}
					
					// If item was not found, let player know
					if(!itemFound)
					{
						std::cout << "There doesn't seem to be an item of that name here."
							<< std::endl << std::endl;
					}
				}
			}

		}

		// Pick up item option: no items found
		else if(whatNow == 5 && !itemsHere)
		{
			std::cout << "You have not found any items here." << std::endl << std::endl;
		}

		// Pick up item option: found items
		else if(whatNow == 5 && itemsHere)
		{
			// If inventory is full, let player know
			if(player.getInventory().size() >= 10)
			{
				std::cout << "Inventory is full. You can only fit 10 items in your bag."
					<< std::endl << std::endl;
			}

			// Otherwise, allow pickup
			else
			{
				bool itemFound = false;

				std::cout << "Pick up which item?: ";
				getline(std::cin, pickThisUp);

				// Compare item name to items in room
				for(int i = 0; i < currentLocation.getItemsHere().size(); i)
				{
					if(currentLocation.getItemsHere()[i].getName() == pickThisUp)
					{
						// Flag item was found
						itemFound = true;

						// If this is the first token player has found, flip newForm
						if(currentLocation.getItemsHere()[i].getType() == "token"
								&& !newForm)
						{
								std::cout << "You examine the token more carefully."
								<< "It appears to be a carving of an animal."
								<< " It glitters with ancient magic, and you feel"
								<< " the magic flow into you as you hold the token."
								<< std::endl << std::endl;

							newForm = true;
						}

						// If item is a token:
						if(currentLocation.getItemsHere()[i].getType() == "token")
						{
							// Add item to player's inventory
							player.pickUpToken(currentLocation.getItemsHere()[i]);
						}

						// Other items:
						else
						{
							// Add item to player's inventory
							player.pickUpItem(currentLocation.getItemsHere()[i]);
						}
						
						// Remove item from room
						currentLocation.removeItem(currentLocation.getItemsHere()[i]);

						std::cout << "Picked up " << pickThisUp << "." << std::endl
							<< std::endl;
					}
					else
					{
						i++;
					}
					
					// If item was not found, let player know
					if(!itemFound)
					{
						std::cout << "There doesn't seem to be an item of that name here."
							<< std::endl << std::endl;
					}
				}
			}
			
		}

		// Transform: no alternate forms
		else if(whatNow == 6 && !newForm)
		{
			std::cout << "You daydream about turning into animals, but nothing happens."
				<< std::endl << std::endl;
		}

		// Disallow transformation while underwater
		else if(whatNow == 6 && currentLocation.getRoomType() == "submerged")
		{
			std::cout << "Better not do that now. You're underwater!" << std::endl
				<< std::endl;
		}

		// Transform
		else if(whatNow == 6 && newForm)
		{
			std::cout << "You have the following forms available:" << std::endl;
			if(player.getHumanAvail())
			{
				std::cout << "1 - Human" << std::endl;
			}
			if(player.getOtterAvail())
			{
				std::cout << "2 - River Otter" << std::endl;
			}
			if(player.getMagpieAvail())
			{
				std::cout << "3 - Magpie" << std::endl;
			}
			if(player.getOrangutanAvail())
			{
				std::cout << "4 - Orangutan" << std::endl;
			}
			if(player.getSlowLorisAvail())
			{
				std::cout << "5 - Slow Loris" << std::endl;
			}
			if(player.getWolfSpiderAvail())
			{
				std::cout << "6 - Wolf Spider" << std::endl;
			}

			while(formChoice < 1 || formChoice > 6)
			{
				std::cout << "Take which form?: ";
				std::cin >> formChoice;
				std::cin.clear();
				std::cin.ignore(999, '\n');
				std::cout << std::endl;
			}
			
			if(formChoice == 1)
			{
				player.changeForm("human", human, otter, magpie, orangutan,
					slowloris, wolfspider);
			}
			else if(formChoice == 2)
			{
				player.changeForm("river otter", human, otter, magpie, orangutan,
					slowloris, wolfspider);
			}
			else if(formChoice == 3)
			{
				player.changeForm("magpie", human, otter, magpie, orangutan,
					slowloris, wolfspider);
			}
			else if(formChoice == 4)
			{
				player.changeForm("orangutan", human, otter, magpie, orangutan,
					slowloris, wolfspider);
			}
			else if(formChoice == 5)
			{
				player.changeForm("slow loris", human, otter, magpie, orangutan,
					slowloris, wolfspider);
			}
			else if(formChoice == 6)
			{
				player.changeForm("wolf spider", human, otter, magpie, orangutan,
					slowloris, wolfspider);
			}

			// Reset form choice
			formChoice = 0;
		}



		// Decrement turn counter
		turnsUntilGameOver--;

		// If turn counter hits zero, game over
		if(turnsUntilGameOver <= 0)
		{
			gameOver = true;
		}
		
	}

	// End text if the player died
	if(playerDied)
	{
		std::cout << "Those super-cool animal tokens weren't enough to get you through"
			<< " the sinking temple. Better luck next life!" << std::endl;
	}

	// End text if temple sank
	else if(gameOver)
	{
		std::cout << "With a thunderous sound, the temple sinks back into the ocean,"
			<< " with you trapped inside it! Too bad you never found a fish token."
			<< " Maybe next life!" << std::endl;
	}

	// Ending if player lived
	else
	{
		// Total inventory items and check for mysterious egg
		int swagTotal = 0;
		bool gotEgg = false;

		for(int i = 0; i < player.getInventory().size(); i++)
		{
			// Check for egg
			if(player.getInventory()[i].getName() == "Mysterious Egg")
			{
				gotEgg = true;
			}

			// Add value to total
			swagTotal += player.getInventory()[i].getValue();
		}

		// Ending if player got egg
		if(gotEgg)
		{
			std::cout << "You escaped the sinking temple in time, and with the"
				<< " mysterious ancient egg, no less! What's inside? Only time"
				<< " will tell. Though the egg is REALLY warm. And is that a scaly"
				<< " pattern on the shell...?" << std::endl;
			std::cout << "You also collected $" << swagTotal << " worth of artifacts."
				<< " Well done, adventurer!" << std::endl;
		}

		// Ending if player has no egg and no valuables
		else if(!gotEgg && swagTotal <= 0)
		{
			std::cout << "Well, that was... exciting? You didn't get any artifacts"
				<< " you're willing to part with, and you feel like you may have"
				<< " missed out on something big. Maybe next millenium!" << std::endl;
		}
		
		// Ending if player escaped with valuables but without egg
		else
		{
			std::cout << "You escape the sinking temple, but you feel like you"
				<< " missed out on something big. Oh, well. You did manage to"
				<< " collect $" << swagTotal << " in artifacts! Well done!"
				<< std::endl;
		}
	}

	// End program
	return 0;
}


/////////////////////////////////////////
// Get movement direction ///////////////
/////////////////////////////////////////

// Get the player's chosen movement direction
char getDirection()
{
	char goThisWay = 'x';

	while(goThisWay != 'N' && goThisWay != 'S' && goThisWay != 'E' && goThisWay != 'W')
	{
		std::cout << "Which direction will you move? (Use N/S/E/W): ";
		std::cin.get(goThisWay);
		std::cin.clear();
		std::cin.ignore(999, '\n');
		goThisWay = toupper(goThisWay);
	}

	// Return direction player has chosen
	return goThisWay;
}

// Tell the player the next room is submerged
void nextIsSubmerged()
{
	std::cout << "Through that doorway, the floor slopes sharply downward and most"
		<< " of the next room is submerged. Only an aquatic creature could explore"
		<< " it safely. You scoot back up the steep passageway into the previous chamber."
		<< std::endl << std::endl;
}

char nextIsGuarded()
{
	char enterRoom = 'x';

	// Describe the room
	std::cout << "You peer into the next room. It's mostly dry and well-lit."
		<< " Huge humanoid statues line the walls, armed with various stone cluds"
		<< " and bludgeons. Oh, and they're moving." << std::endl;

	// Ask whether player still wants to enter
	while(enterRoom != 'Y' && enterRoom != 'N')
	{
		std::cout << "A stealthy creature might be able to sneak through the room undetected."
			<< " Enter the room? (y/n) ";
		std::cin.get(enterRoom);
		std::cin.clear();
		std::cin.ignore(999, '\n');
		enterRoom = toupper(enterRoom);
	}

	return enterRoom;
}

char nextIsOutside()
{
	char enterRoom = 'x';

	// Describe the room
	std::cout << "This door exits the temple." << std::endl;

	// Ask whether player still wants to enter
	while(enterRoom != 'Y' && enterRoom != 'N')
	{
		std::cout << "Are you ready to leave? (y/n) ";
		std::cin.get(enterRoom);
		std::cin.clear();
		std::cin.ignore(999, '\n');
		enterRoom = toupper(enterRoom);
	}

	return enterRoom;
}