#include "Player.h"
#include <iostream>

Player::Player(std::string nickname)
{
    level = 1;
    this->nickname = nickname;
    HP = 100;
    MP = 50;
    power = 10;
    defence = 10;
    accuracy = 5;
    speed = 3;
}

void Player::printPlayerStatus() {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "---현재 능력치---" << std::endl;
    std::cout << "닉네임: " << nickname << std::endl;
    std::cout << "Lv. " << level << std::endl;
    std::cout << "HP: " << HP << std::endl;
    std::cout << "MP: " << MP << std::endl;
    std::cout << "공격력: " << power << std::endl;
    std::cout << "방어력: " << defence << std::endl;
    std::cout << "정확도: " << accuracy << std::endl;
    std::cout << "속도: " << speed << std::endl;
    std::cout << "------------------------------------" << std::endl;
}

std::string Player::getJobName()
{
    return job_name;
}

std::string Player::getNickname()
{
    return nickname;
}

int Player::getLevel()
{
    return level;
}

int Player::getHP()
{
    return HP;
}

int Player::getMP()
{
    return MP;
}

int Player::getPower()
{
    return power;
}

int Player::getDefence()
{
    return defence;
}

int Player::getAccuracy()
{
    return accuracy;
}

int Player::getSpeed()
{
    return speed;
}

void Player::setNickname(std::string nickname)
{
    this->nickname = nickname;
}

void Player::setHP(int HP)
{
    this->HP = HP;
}

void Player::setMP(int MP)
{
    this->MP = MP;
}

void Player::setPower(int power)
{
    this->power = power;
}

void Player::setDefence(int defence)
{
    this->defence = defence;
}

void Player::setAccuracy(int accuracy)
{
    this->accuracy = accuracy;
}

void Player::setSpeed(int speed)
{
    this->speed = speed;
}