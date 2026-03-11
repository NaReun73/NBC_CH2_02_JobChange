#pragma once
#include <iostream>
#include "Player.h"
#include "Warrior.h"
#include "Magician.h"
#include "Thief.h"
#include "Archer.h"
#include "Monster.h"

// 메인 함수
int main() {
    std::string jobs[] = { "전사", "마법사", "도적", "궁수" };
    int job_choice = 0;
    std::string nickname;

    Player* player = nullptr;

    std::cout << "* 닉네임을 입력해주세요: ";
    std::cin >> nickname;

    std::cout << "<전직 시스템>" << std::endl;
    std::cout << nickname << "님, 환영합니다!" << std::endl;
    std::cout << "* 원하시는 직업을 선택해주세요." << std::endl;

    for (int i = 0; i < 4; i++) {
        std::cout << (i + 1) << ". " << jobs[i] << std::endl;
    }

    std::cout << "선택: ";
    std::cin >> job_choice;

    switch (job_choice) {
    case 1:
        player = new Warrior(nickname);
        break;
    case 2:
        player = new Magician(nickname);
        break;
    case 3:
        player = new Thief(nickname);
        break;
    case 4:
        player = new Archer(nickname);
        break;
    default:
        std::cout << "잘못된 입력입니다." << std::endl;
        return 1;
    }
    player->printPlayerStatus();

    Monster* Slime = new Monster("슬라임");

    Slime->attack(player);
    player->attack(Slime);
    
    if (Slime->getHP() > 0)
    {
        Slime->attack(player);
        player->attack(Slime);
    }

    player->printPlayerStatus();

    if (player != nullptr)
        delete player;

    if (Slime != nullptr)
    {
        delete Slime;
    }

    return 0;
}