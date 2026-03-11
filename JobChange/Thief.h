#pragma once
#include "Player.h"

class Thief : public Player
{
public:
	Thief(std::string nickname);
	void attack();
	void attack(Monster* monster);
};

