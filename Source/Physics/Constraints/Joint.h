#pragma once

class Joint
{
public:
	Joint(class Body* bodyA, class Body* bodyB, float stiffness, float restLength = 0);
	~Joint();

	void Step(float dt);
	void Draw(class Graphics* graphics);	

protected:
	class Body* m_bodyA;
	class Body* m_bodyB;

	float m_stiffness{ 0 };
	float m_restLength{ 0 };
};
