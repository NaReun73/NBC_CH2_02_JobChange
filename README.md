# NBC_CH2_02_JobChange

<aside>

### 필수 구현 기능

-  **전체적인 게임 구조 확인하기**
    
    ```less
    📁JobChange/
    │
    ├── main.cpp               // 메인 실행 파일
    ├── Player.h               // Player 클래스 정의
    ├── Player.cpp             // Player 클래스 구현
    ├── Warrior.h              // Warrior 클래스 정의
    ├── Warrior.cpp            // Warrior 클래스 구현
    ├── Magician.h             // Magician 클래스 정의
    ├── Magician.cpp           // Magician 클래스 구현
    ├── Thief.h                // Thief 클래스 정의
    ├── Thief.cpp              // Thief 클래스 구현
    ├── Archer.h               // Archer 클래스 정의
    ├── Archer.cpp             // Archer 클래스 구현
    ```
    

---

1. **기본 클래스(설계도) 정의**
    - [x]  **Player 클래스 선언**
        - 모든 직업의 부모가 되는 기본 클래스 `Player`를 만듭니다.
    - [x]  **순수 가상 함수 attack() 포함**
        - `virtual void attack() = 0;` 을 선언하여, 이 클래스를 상속받는 자식들은 **무조건** 이 함수를 구현하도록 해야 합니다.
            - 이 함수는 단순히 무기를 휘두르는 동작의 '이름'만 정해준 것입니다.

---

1. **직업 클래스 생성 (상속과 재정의)**
    - [x]  **4가지 직업 클래스 만들기**
        - Warrior(전사), Magician(마법사), Thief(도적), Archer(궁수) 클래스를 생성합니다.
        - 각 클래스는 `Player`를 상속 받습니다.
    - [x]  **직업별 공격 기능 구현 (오버라이딩)**
        - 각 직업에서 `attack()` 함수를 다시 정의하세요.
        - **전사:** "검을 휘두릅니다!" 출력
        - **마법사:** "마법 화살을 쏩니다!" 출력
        - **도적/궁수 등:** 각 직업에 어울리는 공격 메시지를 출력하도록 만들어보세요!

---

1. **메인 로직 구현 (다형성 활용)**
    - [x]  **부모 타입 포인터 선언**
        - `Player* player = nullptr;` 처럼 부모 클래스의 포인터를 먼저 준비합니다.
    - [x]  **직업 선택 메뉴판 만들기**
        - 유저에게 번호를 입력받습니다. (`1.전사 / 2.마법사 / 3.도적 / 4.궁수`)
    - [x]  **번호에 맞는 객체 할당 (동적 할당)**
        - `switch`나 `if`문을 작성해서 선택한 번호에 맞게 직업이 선택되도록 합니다.
        - 예 ) 유저가 1번을 누르면 `player = new Warrior();`가 실행됩니다.
    - [x]  **다형성 공격 실행**
        - 할당이 완료된 후 `player->attack();`을 호출합니다.
        - **확인 :** 내가 선택한 직업에 맞는 공격 메시지가 제대로 나오나요?
</aside>

<aside>
💡

**주의사항**

- **포인터 초기화:** 처음에 포인터를 `nullptr`로 초기화하는 습관을 들이면 예기치 못한 에러를 방지할 수 있습니다.
- **메모리 해제:** `new`로 만든 객체는 프로그램 종료 전에 반드시 `delete player;`로 지워주어야 메모리가 깨끗해집니다.
- **가상 소멸자:** 부모 클래스(`Player`)의 소멸자에 `virtual` 키워드를 붙였는지 확인해 보세요! (자식 객체가 안전하게 사라지기 위해 필수입니다.)
</aside>

<aside>

- **[코드스니펫] Player 클래스**
    - `player.h`
    
    ```cpp
    #pragma once
    #include <string>
    using namespace std;
    
    class Player {
    public:
        Player(string nickname);
    
        virtual void attack() = 0;
        void printPlayerStatus();
    		
    		// getter 함수
        string getJobName();
        string getNickname();
        int getLevel();
        int getHP();
        int getMP();
        int getPower();
        int getDefence();
        int getAccuracy();
        int getSpeed();
    		
    		// setter 함수
        void setNickname(string nickname);
        void setHP(int HP);
        void setMP(int MP);
        void setPower(int power);
        void setDefence(int defence);
        void setAccuracy(int accuracy);
        void setSpeed(int speed);
    
    protected:
        string job_name;
        string nickname;
        int level;
        int HP;
        int MP;
        int power;
        int defence;
        int accuracy;
        int speed;
    };
    ```
    
    - `void Player::printPlayerStatus()`
    
    ```cpp
    void Player::printPlayerStatus() {
        cout << "------------------------------------" << endl;
        cout << "* 현재 능력치" << endl;
        cout << "닉네임: " << nickname << endl;
        cout << "Lv. " << level << endl;
        cout << "HP: " << HP << endl;
        cout << "MP: " << MP << endl;
        cout << "공격력: " << power << endl;
        cout << "방어력: " << defence << endl;
        cout << "정확도: " << accuracy << endl;
        cout << "속도: " << speed << endl;
        cout << "------------------------------------" << endl;
    }
    ```
    
- **[코드스니펫] main 함수**
    - `main.cpp`
    
    ```cpp
    #include <iostream>
    #include "player.h"
    #include "warrior.h"
    #include "magician.h"
    #include "thief.h"
    #include "archer.h"
    using namespace std;
    
    // 메인 함수
    int main() {
        string jobs[] = { "전사", "마법사", "도적", "궁수" };
        int job_choice = 0;
        string nickname;
    
        Player* player = nullptr;
    
        cout << "* 닉네임을 입력해주세요: ";
        cin >> nickname;
    
        cout << "<전직 시스템>" << endl;
        cout << nickname << "님, 환영합니다!" << endl;
        cout << "* 원하시는 직업을 선택해주세요." << endl;
    
        for (int i = 0; i < 4; i++) {
            cout << (i + 1) << ". " << jobs[i] << endl;
        }
    
        cout << "선택: ";
        cin >> job_choice;
    
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
            cout << "잘못된 입력입니다." << endl;
            return 1;
        }
    		
    		player->attack();
        player->printPlayerStatus();
        
        if(player != nullptr)
          delete player;
    
        return 0;
    }
    ```
    
    - `void Player::printPlayerStatus()`
    
    ```cpp
    void Player::printPlayerStatus() {
        cout << "------------------------------------" << endl;
        cout << "* 현재 능력치" << endl;
        cout << "닉네임: " << nickname << endl;
        cout << "직업: " << job_name << endl;
        cout << "Lv. " << level << endl;
        cout << "HP: " << HP << endl;
        cout << "MP: " << MP << endl;
        cout << "공격력: " << power << endl;
        cout << "방어력: " << defence << endl;
        cout << "정확도: " << accuracy << endl;
        cout << "속도: " << speed << endl;
        cout << "------------------------------------" << endl;
    }
    ```
    
</aside>
