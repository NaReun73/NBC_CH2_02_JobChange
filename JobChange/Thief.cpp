#include "Thief.h"
#include <iostream>

Thief::Thief(std::string nickname)
	:Player(nickname)
{
	job_name = "도적";
	std::cout << "닉네임 " << nickname << " 이(가) 도적으로 전직합니다." << std::endl;
	level = 1;
	HP = 200;
	MP = 180;
	power = 20;
	defence = 20;
	accuracy = 8;
	speed = 10;
}

void Thief::attack()
{
	std::cout << "단검으로 찌릅니다." << std::endl;
}

void Thief::attack(Monster* monster)
{
	std::cout << monster->getName() << "에게 단검을 5회 찌릅니다." << std::endl;
	int damage = 0;
	damage = this->power - monster->getDefence();
	damage /= 5;
	if (damage <= 0)
	{
		damage = 1;
	}

	for (int i = 0; i < 5; ++i)
	{
		std::cout << monster->getName() << "에게 찔렀습니다. " << damage << "의 피해를 입혔습니다." << std::endl;
		monster->setHP((monster->getHP() - damage));

		if (monster->getHP() <= 0)
		{
			std::cout << monster->getName() << "이(가) 쓰러졌습니다." << std::endl;
			std::cout << nickname << "이(가) 경험치를 얻었습니다." << std::endl;
			break;
		}
		else
		{
			std::cout << monster->getName() << "의 체력이 " << monster->getHP() << " 남았습니다." << std::endl;
		}
	}
}