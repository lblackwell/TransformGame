//
//  Otter.cpp is the Otter class function implementation file.
//  Otter is a sublclass of the class Form.
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#include "Form.h"
#include "Otter.h"

Otter::Otter()
{
	this->setName("river otter");
	this->setSize("small");
	this->setCanSwim(true);
	this->setCanFly(false);
	this->setIsStrong(false);
	this->setIsStealthy(false);
	this->setCanSeeInDark(false);
}