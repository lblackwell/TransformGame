//
//  Magpie.h
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#ifndef MAGPIE_H
#define MAGPIE_H

#include "Form.h"
#include <string>

class Magpie: public Form
{
public:
	Magpie();

private:
	// Name of form
	std::string name;

	// Size (small/medium/large)
	std::string size;

	// Can this form swim underwater?
	bool canSwim;

	// Can this form fly?
	bool canFly;

	// Is this form strong enough to smash things?
	bool isStrong;

	// Is this form stealthy?
	bool isStealthy;

	// Can this form see in the dark?
	bool canSeeInDark;
};

#endif