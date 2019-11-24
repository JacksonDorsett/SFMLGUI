#pragma once
#include "Indevelopment/StatusBar.h"
class HealthBar : public StatusBar
{
public:
	static enum orientation {Left,Right};
	//can change to another datatype for health depending on later implementation
	HealthBar(int &currentHealth, int &maxHealth, sf::Vector2f position, bool textVisible = true, orientation orientation = orientation::Left);
	~HealthBar();

	void toggleText();
	void UpdateHealth();
	
private:
	int &maxHealth;
	int &curHealth;
	mutable float HealthRatio;
	bool visibleText;

	mutable sf::Text mText;
	sf::Font mFont;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	std::string getHealthString() ;

};

