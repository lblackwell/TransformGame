//
//  Human.cpp is the Human class function implementation file.
//  Human is a sublclass of the class Form.
//
//  Created by Lucia Blackwell on 3/10/15
//  Modified by Lucia Blackwell on 3/13/15
//

#include "Form.h"
#include "Human.h"

Human::Human()
{
	this->setName("human");
	this->setSize("medium");
	this->setCanSwim(false);
	this->setCanFly(false);
	this->setIsStrong(false);
	this->setIsStealthy(false);
	this->setCanSeeInDark(false);
}