#include "Magician.h"
#include "Monster.h"
#include <iostream>

Magician::Magician(std::string nickname)
	:Player(nickname)
{
	job_name = "마법사";
	std::cout << "닉네임 " << nickname << " 이(가) 마법사로 전직합니다." << std::endl;
	level = 1;
	HP = 150;
	MP = 300;
	power = 50;
	defence = 10;
	accuracy = 10;
	speed = 4;
}

void Magician::attack()
{
	std::cout << "마법 구체를 날립니다." << std::endl;
}

void Magician::attack(Monster* monster)
{
	std::cout << monster->getName() << "에게 마법 구체를 날립니다." << std::endl;
	
	int damage = 0;
	damage = this->power - monster->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}

	std::cout << monster->getName() << "을(를) 맞췄습니다. " << damage << "의 피해를 입혔습니다." << std::endl;

	monster->setHP((monster->getHP() - damage));

	if (monster->getHP() <= 0)
	{
		std::cout << monster->getName() << "이(가) 쓰러졌습니다." << std::endl;
		std::cout << nickname << "이(가) 경험치를 얻었습니다." << std::endl;
	}
	else
	{
		std::cout << monster->getName() << "의 체력이 " << monster->getHP() << " 남았습니다." << std::endl;
	}
	
}