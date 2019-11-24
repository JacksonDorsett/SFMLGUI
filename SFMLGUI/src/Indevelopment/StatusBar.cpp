#include "StatusBar.h"



StatusBar::StatusBar(sf::Vector2f size, sf::Vector2f pos) : mSize(size), mPosition(pos)
{
	bgRect.setSize(size);
	progressRect.setSize(size);
	bgRect.setPosition(pos);
	progressRect.setPosition(pos);
	
}


StatusBar::~StatusBar()
{
}


void StatusBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	/*states.transform *= bgRect.getTransform();
	if (progressRect.getTexture() != NULL)
	{
		states.texture = bgRect.getTexture();
	}*/
	target.draw(bgRect,states);

	/*states = states.Default;
	states.transform *= progressRect.getTransform();
	if (progressRect.getTexture() != NULL)
	{
		states.texture = progressRect.getTexture();
	}*/
	target.draw(progressRect, states);
}