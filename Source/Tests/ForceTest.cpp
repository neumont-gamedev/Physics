#include "ForceTest.h"
#include "../Physics/Body.h"
#include "../Physics/Shapes/CircleShape.h"
#include "../Physics/Forces/PointForce.h"
#include "../Physics/Forces/AreaForce.h"
#include "../Physics/Forces/DragForce.h"
#include "../Physics/Forces/GravitationalForce.h"

#define POINT_FORCE
//#define AREA_FORCE
//#define DRAG_FORCE

void ForceTest::Initialize()
{
	Test::Initialize();


#if defined(POINT_FORCE)
	auto body = new Body(new CircleShape(3, { 1, 1, 1, 0.2f }), { 0, 0 }, { 0, 0 }, 0, Body::STATIC);
	ForceGenerator* forceGenerator = new PointForce(body, 5);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(AREA_FORCE)
	auto body = new Body(new CircleShape(3, { 1, 1, 1, 0.2f }), { 0, 0 }, { 0, 0 }, 0, Body::STATIC);
	ForceGenerator* forceGenerator = new AreaForce(body, 5, 90);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(DRAG_FORCE)
	auto body = new Body(new CircleShape(3, { 1, 1, 1, 0.2f }), { 0, 0 }, { 0, 0 }, 0, Body::STATIC);
	ForceGenerator* forceGenerator = new DragForce(body, 0.5f);
	m_world->AddForceGenerator(forceGenerator);
#endif
}

void ForceTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
		glm::vec2 velocity = { 0, 0 };// randomUnitCircle()* randomf(100, 200);

		float size = randomf(0.1f, 0.5f);
		auto body = new Body(new CircleShape(size, { randomf(), randomf(), randomf(), 1 }), position, velocity, size);
		body->damping = 1;

		m_world->AddBody(body);
	}
}

void ForceTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void ForceTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });
}


// add "planet"
//auto body = new Body(new CircleShape(100, { 1, 1, 1, 1 }), { 400, 300 }, { 0, 0 }, 500, Body::STATIC);
//m_world->AddBody(body);

//ForceGenerator* forceGenerator = nullptr;
//forceGenerator = new GravitationalForce(100);
//m_world->AddForceGenerator(forceGenerator);