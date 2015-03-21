//
//  SlowLoris.cpp is the SlowLoris class function implementation file.
//  SlowLoris is a sublclass of the class Form.
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#include "Form.h"
#include "SlowLoris.h"

SlowLoris::SlowLoris()
{
	this->setName("slow loris");
	this->setSize("small");
	this->setCanSwim(false);
	this->setCanFly(false);
	this->setIsStrong(false);
	this->setIsStealthy(false);
	this->setCanSeeInDark(true);
}