#include "Collision.h"
#include "../Body.h"
#include "../Shapes/CircleShape.h"
#include "../../Engine/Random.h"


namespace Collision
{
	void CreateContacts(std::vector<class Body*> bodies, std::vector<Contact>& contacts)
	{
		for (size_t i = 0; i < bodies.size() - 1; i++)
		{
			for (size_t j = i + 1; j < bodies.size(); j++)
			{
				Body* bodyA = bodies[i];
				Body* bodyB = bodies[j];

				if (bodyA->Intersects(bodyB))
				{
					Contact contact = Collision::GenerateContactInfo(bodyA, bodyB);
					contacts.push_back(contact);
				}
			}
		}
	}

	void SeparateContacts(std::vector<Contact>& contacts)
	{
		for (auto& contact : contacts)
		{
			float invMassA = (contact.bodyA->type == Body::DYNAMIC) ? contact.bodyA->invMass : 0;
			float invMassB = (contact.bodyB->type == Body::DYNAMIC) ? contact.bodyB->invMass : 0;

			float totalInverseMass = invMassA + invMassB;

			glm::vec2 separation = contact.normal * (contact.depth / totalInverseMass);
			contact.bodyA->position += separation * invMassA;
			contact.bodyB->position -= separation * invMassB;
		}
	}

	Contact GenerateContactInfo(Body* bodyA, Body* bodyB)
	{
		Contact contact;

		contact.bodyA = bodyA;
		contact.bodyB = bodyB;
		
		glm::vec2 direction = bodyA->position - bodyB->position;
		if (glm::length(direction) == 0)
		{
			direction = glm::vec2{ randomf(-0.1f, 0.1f), randomf(-0.1f, 0.1f) };
		}
		contact.normal = glm::normalize(direction);

		float radius = dynamic_cast<CircleShape*>(bodyA->shape)->radius + dynamic_cast<CircleShape*>(bodyB->shape)->radius;
		contact.depth = radius - glm::length(direction);

		return contact;
	}

	/*
	void ResolveContacts(std::vector<Contact>& contacts)
	{
		for (auto& contact : contacts)
		{
			glm::vec2 relativeVelocity = contact.bodyA->velocity - contact.bodyB->velocity;

			// check if bodies are moving in the same direction
			float normalVelocity = glm::dot(relativeVelocity, contact.normal);
			if (normalVelocity > 0) continue;

			// get inverse mass of dynamic objects
			float invMassA = (contact.bodyA->type == Body::DYNAMIC) ? contact.bodyA->invMass : 0;
			float invMassB = (contact.bodyB->type == Body::DYNAMIC) ? contact.bodyB->invMass : 0;
			float totalInverseMass = invMassA + invMassB;

			// compute magnitude of impulse
			float impulseMagnitude = -((1 + contact.restitution) * normalVelocity) / totalInverseMass;

			glm::vec2 impulse = contact.normal * impulseMagnitude;

			contact.bodyA->velocity += (impulse * ((invMassA != 0) ? contact.bodyA->mass : 0));
			contact.bodyB->velocity += -(impulse * ((invMassB != 0) ? contact.bodyB->mass : 0));

			//contact.bodyA->ApplyForce(contact.bodyA->velocity + (impulse * ((invMassA != 0) ? contact.bodyA->mass : 0)));
			//contact.bodyB->ApplyForce(contact.bodyB->velocity - (impulse * ((invMassB != 0) ? contact.bodyB->mass : 0)));

		}
	}
	*/
}
