#pragma once
#include<iostream>
using namespace std;
#include"Entity.h"

#ifndef UNTITLED23_ZOMBIE_H
#define UNTITLED23_ZOMBIE_H

#endif //UNTITLED23_ZOMBIE_H

class Zombie : public Entity {
    int x, y;
public:
    Zombie(const string& n, int h, int d, int sx, int sy)
            : Entity(n, h, d), x(sx), y(sy) {}

    void attack(Entity& target) override {
        cout << "\n[ZOMBIE ATTACK]" << endl;
        cout << name << " (" << health << " HP) bites " << target.getName()
             << " (" << target.getHealth() << " HP)" << endl;
        cout << ">>> Deals " << damage << " damage" << endl;
        target.takeDamage(damage);
        cout << target.getName() << " now has " << target.getHealth() << " HP\n";
    }

    int getX() const { return x; }
    int getY() const { return y; }
};