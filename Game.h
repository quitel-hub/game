#include<iostream>
#include<vector>
#include"Entity.h"
#include "Zombie.h"
#include "Player.h"
#include "Boss.h"
#include "Sword.h"
#include "Gun.h"
#include "Inventory.h"
#include "Map.h"
#pragma once

using namespace std;

#ifndef UNTITLED23_GAME_H
#define UNTITLED23_GAME_H

#endif //UNTITLED23_GAME_H

class Game {
    Player player;
    vector<Entity*> enemies;
    Map map;
    Inventory inventory;
public:
    Game() : player("Player", 100, 20, 1, 1), map(15, 15, 20) {
        enemies.push_back(new Zombie("Zombie 1", 50, 10, 5, 5));
        enemies.push_back(new Zombie("Zombie 2", 60, 15, 10, 3));
        enemies.push_back(new Boss("BOSS", 120, 20, 10, 7, 7));
        inventory.addItem(new Sword());
        inventory.addItem(new Gun());
    }

    void run() {
        cout << "=== GAME START ===" << endl;

        while (player.isAlive() && !enemies.empty()) {
            cout << "\nHealth: " << player.getHealth()
                 << " | Score: " << player.getScore() << endl;
            map.render(player, enemies);

            cout << "\n--- PLAYER TURN ---" << endl;
            cout << "W/A/S/D to move, F to attack, Q to quit: ";
            char c; cin >> c;
            c = tolower(c);

            if (c == 'q') break;
            if (c == 'w') player.move(0,-1,map.getGrid());
            if (c == 's') player.move(0,1,map.getGrid());
            if (c == 'a') player.move(-1,0,map.getGrid());
            if (c == 'd') player.move(1,0,map.getGrid());
            if (c == 'f') {
                if (!enemies.empty()) {
                    player.attack(*enemies[0]);
                    if (!enemies[0]->isAlive()) {
                        cout << enemies[0]->getName() << " defeated!" << endl;
                        player.addScore(50);
                        delete enemies[0];
                        enemies.erase(enemies.begin());
                    }
                }
            }

            if (!enemies.empty()) {
                cout << "\n--- ENEMY TURN ---" << endl;

                // --- FIX: enemy attacks ONLY if on the same map cell as player ---
                // Try to downcast to Zombie (works also for Boss which inherits Zombie)
                Zombie* z = dynamic_cast<Zombie*>(enemies[0]);
                if (z) {
                    if (z->getX() == player.getX() && z->getY() == player.getY()) {
                        enemies[0]->attack(player);
                        if (!player.isAlive()) {
                            cout << "Player has fallen!" << endl;
                        }
                    } else {
                        cout << enemies[0]->getName() << " is not in range to attack." << endl;
                    }
                } else {
                    // fallback: if it's some other entity type, call attack anyway
                    enemies[0]->attack(player);
                    if (!player.isAlive()) {
                        cout << "Player has fallen!" << endl;
                    }
                }
            }
        }

        if (player.isAlive()) cout << "\n=== Victory! All enemies defeated! ===" << endl;
        else cout << "\n=== Defeat... ===" << endl;

        cout << "Final score: " << player.getScore() << endl;
    }

    ~Game() {
        for (auto e : enemies) delete e;
    }
};