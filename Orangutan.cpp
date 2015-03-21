//
//  Orangutan.cpp is the Orangutan class function implementation file.
//  Orangutan is a sublclass of the class Form.
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#include "Form.h"
#include "Orangutan.h"

Orangutan::Orangutan()
{
	this->setName("orangutan");
	this->setSize("medium");
	this->setCanSwim(false);
	this->setCanFly(false);
	this->setIsStrong(true);
	this->setIsStealthy(false);
	this->setCanSeeInDark(false);
}