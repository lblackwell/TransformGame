//
//  WolfSpider.cpp is the WolfSpider class function implementation file.
//  WolfSpider is a sublclass of the class Form.
//
//  Created by Lucia Blackwell on 3/13/15
//  Modified by Lucia Blackwell on 3/13/15
//

#include "Form.h"
#include "WolfSpider.h"

WolfSpider::WolfSpider()
{
	this->setName("wolf spider");
	this->setSize("small");
	this->setCanSwim(false);
	this->setCanFly(false);
	this->setIsStrong(false);
	this->setIsStealthy(true);
	this->setCanSeeInDark(false);
}