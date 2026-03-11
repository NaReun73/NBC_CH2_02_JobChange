#include "Monster.h"
#include <iostream>

Monster::Monster(std::string name)
{
	std::cout << "몬스터 " << name << "이(가) 나타났습니다." << std::endl;
	this->name = name;
	HP = 30;
	power = 30;
	defence = 10;
	speed = 10;
}

void Monster::attack(Player* player)
{
	std::cout << player->getNickname() << "을(를) 향해 공격합니다." << std::endl;
	int damage = 0;
	damage = this->power - player->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}

	std::cout << name << "의 공격을 " << player->getNickname() << "이(가) 맞았습니다. " << damage << "의 피해를 받았습니다." << std::endl;
	
	player->setHP((player->getHP() - damage));

	if (player->getHP() <= 0)
	{
		std::cout << player->getNickname() << "이(가) 쓰러졌습니다." << std::endl;
	}
	else
	{
		std::cout << player->getNickname() << "의 체력이 " << player->getHP() << " 남았습니다." << std::endl;
	}
	
}

std::string Monster::getName()
{
	return name;
}

int Monster::getHP()
{
	return HP;
}

int Monster::getPower()
{
	return power;
}

int Monster::getDefence()
{
	return defence;
}

int Monster::getSpeed()
{
	return speed;
}

void Monster::setName(std::string name)
{
	this->name = name;
}

void Monster::setHP(int HP)
{
	this->HP = HP;
}

void Monster::setPower(int power)
{
	this->power = power;
}

void Monster::setDefence(int defence)
{
	this->defence = defence;
}

void Monster::setSpeed(int speed)
{
	this->speed = speed;
}