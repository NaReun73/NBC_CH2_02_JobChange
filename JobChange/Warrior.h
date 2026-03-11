#pragma once
#include "Player.h"
#include "Monster.h"

class Warrior : public Player
{
public:
    Warrior(std::string nickname);
    void attack();
    void attack(Monster* monster);
};
