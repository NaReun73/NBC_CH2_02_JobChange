#include "Warrior.h"
#include <iostream>

Warrior::Warrior(std::string nickname)
	: Player(nickname)
{
	job_name = "전사";
	std::cout << "닉네임 " << nickname << " 이(가) 전사로 전직합니다." << std::endl;
	level = 1;
	HP = 300;
	MP = 100;
	power = 30;
	defence = 30;
	accuracy = 7;
	speed = 7;
}

void Warrior::attack()
{
	std::cout << "검을 휘두릅니다." << std::endl;
}

void Warrior::attack(Monster* monster)
{
	std::cout << monster->getName() << "에게 검을 휘두릅니다." << std::endl;
	int damage = 0;
	damage = this->power - monster->getDefence();
	if (damage <= 0)
	{
		damage = 1;
	}

	std::cout << monster->getName() << "을(를) 베었습니다. " << damage << "의 피해를 입혔습니다." << std::endl;

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