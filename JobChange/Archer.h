#pragma once
#include "Player.h"

class Archer : public Player
{
public:
	Archer(std::string nickname);
	void attack();
	void attack(Monster* monster) ;
};

