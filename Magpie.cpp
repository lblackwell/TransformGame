//
//  Magpie.cpp is the Magpie class function implementation file.
//  Magpie is a sublclass of the class Form.
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#include "Form.h"
#include "Magpie.h"

Magpie::Magpie()
{
	this->setName("magpie");
	this->setSize("small");
	this->setCanSwim(false);
	this->setCanFly(true);
	this->setIsStrong(false);
	this->setIsStealthy(false);
	this->setCanSeeInDark(false);
}