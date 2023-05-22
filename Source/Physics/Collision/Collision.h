#pragma once
#include "Contact.h"
#include <vector>

namespace Collision
{
	Contact GenerateContactInfo(class Body* bodyA, class Body* bodyB);
	void CreateContacts(std::vector<class Body*> bodies, std::vector<Contact>& contacts);
	void SeparateContacts(std::vector<Contact>& contacts);
	//void ResolveContacts(std::vector<Contact>& contacts);
};