#include<iostream>
#pragma once
using namespace std;

#ifndef UNTITLED23_WEAPON_H
#define UNTITLED23_WEAPON_H

#endif //UNTITLED23_WEAPON_H

class Weapon {
protected:
    string name;
    int damage;
public:
    Weapon(const string& n, int d) : name(n), damage(d) {}
    virtual int getDamage() const { return damage; }
    virtual string getName() const { return name; }
    virtual ~Weapon() {}
};