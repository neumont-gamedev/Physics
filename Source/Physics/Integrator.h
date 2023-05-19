#pragma once
#include "Body.h"

namespace Integrator
{
	inline void ExplicitEuler(Body& body, float dt)
	{
		body.position += body.velocity * dt;
		body.velocity += (body.force * body.invMass) * dt;
	}

	inline void SemiImplicitEuler(Body& body, float dt)
	{
		body.velocity += (body.force * body.invMass) * dt;
		body.position += body.velocity * dt;
	}
}
