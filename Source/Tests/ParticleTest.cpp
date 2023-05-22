#include "ParticleTest.h"
#include "../Physics/Body.h"
#include "../Physics/Shapes/CircleShape.h"

void ParticleTest::Initialize()
{
	Test::Initialize();
}

void ParticleTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
		glm::vec2 velocity = randomUnitCircle() * randomf(0.1f, 5.0f);
		auto body = new Body(new CircleShape(randomf(0.05f, 0.1f), { randomf(), randomf(), randomf(), 1 }), position, velocity);
		body->damping = 1;
		body->gravityScale = 0;
		m_world->AddBody(body);
	}
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ParticleTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });
}
