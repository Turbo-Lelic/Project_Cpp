//1 указатель может ссылаться на свой тип данных  
//2 указатель базового класса может ссылаться на объект такового же класса или может ссылаться на любой другой класс который наследованн от него 

#include <iostream>

using namespace std;

class Gun {
public:
    virtual void Shoot() {
        cout << "BANG...\n";
    }
};

class Gun_Machine : public Gun {
public:
    void Shoot() override {
        for (int i = 0; i < 3; i++) {
            cout << "BANG... ";
        }
        cout << endl;
    }
};

class Bazzoka : public Gun {
public:
    void Shoot() override {
        cout << "BOOOOOM......\n";
    }
};

class Player {
public:
    void Shoot(Gun *gun) {
        gun->Shoot();
    }
};

signed main() {
    Gun g; Gun_Machine gm; Bazzoka b;
    g.Shoot(); gm.Shoot(); b.Shoot();
    cout << endl;
    Gun *ptr_g = &g, *ptr_gm = &gm, *ptr_b = &b;
    ptr_g->Shoot(); ptr_gm->Shoot(); ptr_b->Shoot();
    cout << endl;
    Player player;
    player.Shoot(&g); player.Shoot(&gm); player.Shoot(&b); //2

    return 0;
}