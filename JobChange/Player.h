#pragma once
#include <string>
#include "Monster.h"

class Monster;

class Player {
public:
    Player(std::string nickname);

    virtual void attack() = 0;
    virtual void attack(Monster* monster) = 0;
    void printPlayerStatus();

    // getter 함수
    std::string getJobName();
    std::string getNickname();
    int getLevel();
    int getHP();
    int getMP();
    int getPower();
    int getDefence();
    int getAccuracy();
    int getSpeed();

    // setter 함수
    void setNickname(std::string nickname);
    void setHP(int HP);
    void setMP(int MP);
    void setPower(int power);
    void setDefence(int defence);
    void setAccuracy(int accuracy);
    void setSpeed(int speed);

protected:
    std::string job_name;
    std::string nickname;
    int level;
    int HP;
    int MP;
    int power;
    int defence;
    int accuracy;
    int speed;
};