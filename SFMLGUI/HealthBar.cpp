#include "HealthBar.h"



HealthBar::HealthBar(int &currentHealth, int &maxHealth, sf::Vector2f position,bool textVisible, orientation orientation) : StatusBar(sf::Vector2f(400,40),position),
		curHealth(currentHealth),maxHealth(maxHealth), visibleText(textVisible)
{
	HealthRatio = (float)curHealth / this->maxHealth;
	bgRect.setFillColor(sf::Color::Red);
	bgRect.setOutlineColor(sf::Color::Black);
	bgRect.setOutlineThickness(1);
	progressRect.setFillColor(sf::Color::Green);
	if (orientation == orientation::Right) {
		progressRect.setOrigin(mSize.x, 0.0f);
		progressRect.setPosition(mPosition.x + mSize.x, mPosition.y);
	}
	//init text
	mFont.loadFromFile("Arial.ttf");
	mText.setFont(mFont);
	mText.setString(getHealthString());
	mText.setCharacterSize(mSize.y - 8);
	mText.setOrigin(1.0f,.5);
	mText.setPosition(sf::Vector2f(mPosition.x + mSize.x/3, mPosition.y));
	mText.setFillColor(sf::Color::Black);
}


HealthBar::~HealthBar()
{
}

void HealthBar::toggleText()
{
	visibleText = !visibleText;
}

void HealthBar::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	HealthRatio = (float)curHealth / maxHealth;
	if (HealthRatio < 0) HealthRatio = 0;
	std::string ret;
	if (curHealth >= 0)ret += std::to_string(curHealth);
	else ret += "0";
	ret += " / ";
	ret += std::to_string(maxHealth);
	mText.setString(ret);
	mText.setPosition(sf::Vector2f(mPosition.x + mSize.x / 3, mPosition.y));
	//progressRect.setSize(sf::Vector2f(mSize.x*HealthRatio, mSize.y));
	progressRect.setScale(HealthRatio, 1.0f);
	target.draw(bgRect);
	
	target.draw(progressRect);
	if(visibleText) target.draw(mText);
}
void HealthBar::UpdateHealth()
{
	HealthRatio = (float) curHealth / maxHealth;
	if (HealthRatio < 0) HealthRatio = 0;
	mText.setString(getHealthString());
	//mText.setOrigin(1.0f, .5);
	mText.setPosition(sf::Vector2f(mPosition.x + mSize.x / 3, mPosition.y));
	//progressRect.setSize(sf::Vector2f(mSize.x*HealthRatio, mSize.y));
	progressRect.setScale(HealthRatio, 1.0f);
}

std::string HealthBar::getHealthString()
{
	std::string ret;
	if(curHealth >= 0)ret += std::to_string(curHealth);
	else ret += "0";
	ret += " / ";
	ret += std::to_string(maxHealth);
	return ret;
}