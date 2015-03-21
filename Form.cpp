//
//  Form.cpp is the Form class function implementation file.
//
//  Created by Lucia Blackwell on 3/10/15
//  Modified by Lucia Blackwell on 3/13/15
//

#include "Form.h"

// Get functions
std::string Form::getName() const
{
	return name;
}

std::string Form::getSize() const
{
	return size;
}

bool Form::getCanSwim() const
{
	return canSwim;
}

bool Form::getCanFly() const
{
	return canFly;
}

bool Form::getIsStrong() const
{
	return isStrong;
}

bool Form::getIsStealthy() const
{
	return isStealthy;
}

bool Form::getCanSeeInDark() const
{
	return canSeeInDark;
}

// Set functions
void Form::setName(std::string formName)
{
	name = formName;
}

void Form::setSize(std::string formSize)
{
	size = formSize;
}

void Form::setCanSwim(bool swim)
{
	canSwim = swim;
}

void Form::setCanFly(bool fly)
{
	canFly = fly;
}

void Form::setIsStrong(bool strong)
{
	isStrong = strong;
}

void Form::setIsStealthy(bool stealthy)
{
	isStealthy = stealthy;
}

void Form::setCanSeeInDark(bool see)
{
	canSeeInDark = see;
}