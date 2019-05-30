#include "Viserion.h"



Viserion::Viserion()
{
}

Viserion::Viserion(b2World & world, int width, sf::Vector2i postion, bool circle)
	: Dragons(world, width, postion, circle)
{
	m_sprite.setTexture(*Graphics::getInstance().getTexture(6));
	m_sprite.setScale(50.f / m_sprite.getGlobalBounds().width, 50.f / m_sprite.getGlobalBounds().height); // set correct scale
}


Viserion::~Viserion()
{
}
