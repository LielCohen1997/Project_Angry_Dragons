#include "GameObject.h"



GameObject::GameObject()
{
}

GameObject::GameObject(b2World & world, int width, sf::Vector2i position, bool circle)
{
	b2FixtureDef fixtureDef;
	b2BodyDef bodyDef;
	b2CircleShape circleShape;
	b2PolygonShape boxShape;

	// sf::Vector2i i = mapCoordsToPixel(position);

	bodyDef.position = b2Vec2(position.x, position.y);
	bodyDef.type = b2_staticBody; //b2_dynamicBody;
	m_body = world.CreateBody(&bodyDef);

	if (circle)
		circleShape.m_radius = 30;
	else
		boxShape.SetAsBox(((50.f / 2)*width) / SCALE, (50.f / 2) / SCALE);

	fixtureDef.density = 1.f;
	fixtureDef.friction = 0.7f;

	if (circle)
		fixtureDef.shape = &circleShape;
	else
		fixtureDef.shape = &boxShape;

	m_body->CreateFixture(&fixtureDef);

	////circleShape.m_p.Set(0, 0); //position, relative to body position
	//// Shape.m_radius = 10;

	//if (circle)
	//	fixtureDef.shape = &circleShape;
	//else
	//	fixtureDef.shape = &boxShape;

	//m_body->CreateFixture(&fixtureDef);
	//m_sprite.setPosition(position);

}

GameObject::~GameObject()
{
}

void GameObject::print(const b2Vec2 position, float32 y)
{
	m_sprite.setPosition(position.x * 10, position.y * 10);
	m_sprite.setRotation(180 / b2_pi * y);
}
