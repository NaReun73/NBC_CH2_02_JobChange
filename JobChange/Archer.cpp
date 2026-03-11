#include "Archer.h"
#include "Monster.h"
#include <iostream>

Archer::Archer(std::string nickname)
	:Player(nickname)
{
	job_name = "궁수";
	std::cout << "닉네임 " << nickname << " 이(가) 궁수로 전직합니다." << std::endl;
	level = 1;
	HP = 200;
	MP = 150;
	power = 25;
	defence = 20;
	accuracy = 9;
	speed = 9;
}

void Archer::attack()
{
	std::cout << "화살을 쏩니다." << std::endl;
}

void Archer::attack(Monster* monster)
{
	std::cout << monster->getName() << "에게 화살을 3발을 쏩니다." << std::endl;
	int damage = 0;
	damage = this->power - monster->getDefence();
	damage /= 3;
	if (damage <= 0)
	{
		damage = 1;
	}

	for (int i = 0; i < 3; ++i)
	{
		std::cout << monster->getName() << "에게 명중했습니다. " << damage << "의 피해를 입혔습니다." << std::endl;
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