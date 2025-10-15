
#include <cstdlib>
#include <ctime>


#include "Game.h"
using namespace std;


int main() {
    srand((unsigned)time(nullptr));
    Game game;
    game.run();
    int n = 3, m = 5;
    int c = n + m;
    cout << c << endl;
    return 0;
}
