//
//  Form.h
//
//  Created by Lucia Blackwell on 3/10/15
//  Modified by Lucia Blackwell on 3/13/15
//

#ifndef FORM_H
#define FORM_H

#include <string>

class Form
{
public:
	// Get functions
	virtual std::string getName() const;
	virtual std::string getSize() const;
	virtual bool getCanSwim() const;
	virtual bool getCanFly() const;
	virtual bool getIsStrong() const;
	virtual bool getIsStealthy() const;
	virtual bool getCanSeeInDark() const;

	// Set functions
	virtual void setName(std::string formName);
	virtual void setSize(std::string formSize);
	virtual void setCanSwim(bool swim);
	virtual void setCanFly(bool fly);
	virtual void setIsStrong(bool strong);
	virtual void setIsStealthy(bool stealthy);
	virtual void setCanSeeInDark(bool see);


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