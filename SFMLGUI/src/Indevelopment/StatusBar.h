#pragma once
#include "SFML/Graphics.hpp"
//Base class for various Status Bars such as: Health, Loading, chargeMeter
class StatusBar : public sf::Drawable
{
public:
	StatusBar(sf::Vector2f size, sf::Vector2f pos);
	virtual ~StatusBar();
	
protected:
	sf::Vector2f mSize;
	sf::Vector2f mPosition;
	sf::RectangleShape bgRect;
	mutable sf::RectangleShape progressRect;
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

