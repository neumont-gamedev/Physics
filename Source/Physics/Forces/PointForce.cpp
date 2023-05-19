#include "PointForce.h"
#include "../Body.h"
#include <glm/glm.hpp>

void PointForce::Apply(std::vector<class Body*> bodies)
{
	for (auto body : bodies)
	{
		if (!m_body->Intersects(body)) continue;

		glm::vec2 direction = body->position - m_body->position;
		glm::vec2 force = glm::normalize(direction);

		body->ApplyForce(force * m_forceMagnitude);







		//float distance = glm::length(direction);
		//float radius = dynamic_cast<CircleShape*>(m_body->shape)->radius;
		//float t = distance / radius;

		//switch (m_mode
		//	) {
		//case PointForce::CONSTANT:
		//	body->ApplyForce(force * m_forceMagnitude);
		//	break;
		//case PointForce::INVERSE_LINEAR:
		//	body->ApplyForce(force * (1 - t) * m_forceMagnitude);
		//	break;
		//case PointForce::INVERSE_SQUARED:
		//	body->ApplyForce(force * ((1 - t) * (1 - t)) * m_forceMagnitude);
		//	break;
		//default:
		//	break;
		//}
	}

}
