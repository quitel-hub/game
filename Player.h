#pragma once
#include<iostream>
#include<vector>
#include"Entity.h"

using namespace std;

#ifndef UNTITLED23_PLAYER_H
#define UNTITLED23_PLAYER_H

#endif //UNTITLED23_PLAYER_H


class Player : public Entity {
    int score;
    int x, y;
public:
    Player(const string& n, int h, int d, int sx, int sy)
            : Entity(n, h, d), score(0), x(sx), y(sy) {}

    void attack(Entity& target) override {
        cout << "\n[PLAYER ATTACK]" << endl;
        cout << name << " (" << health << " HP) attacks " << target.getName()
             << " (" << target.getHealth() << " HP)" << endl;
        cout << ">>> Deals " << damage << " damage" << endl;
        target.takeDamage(damage);
        cout << target.getName() << " now has " << target.getHealth() << " HP\n";
    }

    void addScore(int points) { score += points; }
    int getScore() const { return score; }
    int getX() const { return x; }
    int getY() const { return y; }

    void move(int dx, int dy, const vector<vector<int>>& map) {
        int nx = x + dx;
        int ny = y + dy;
        if (nx >= 0 && nx < (int)map[0].size() && ny >= 0 && ny < (int)map.size()) {
            if (map[ny][nx] == 0) {
                x = nx;
                y = ny;
            } else {
                cout << "Can't move there (wall)." << endl;
            }
        }
    }
};