#include <iostream>
#include "GameGrid.h"

using namespace std;

int main() {
    string cmd, aux;
    GameGrid g;
    g.init();

    try {
        while (true) {
            cin >> cmd;
            if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" ||
                cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw" ) {
                g.move(cmd);
            }
            else if (cmd == "u") {
                string dir;
                cin >> dir;
                g.use(dir);
            }
            else if (cmd == "a") {
                string dir;
                cin >> dir;
                g.attack(dir);
            }
            else if (cmd.front() == 's' || cmd.front() == 'd' ||
                     cmd.front() == 'v' || cmd.front() == 'g' ||
                     cmd.front() == 't') {
                g.setRace(cmd.front());
            }
            else if (cmd == "f") {
                g.freeze();
            }
            else if (cmd == "r") {
                g.clearGrid();
                g.init();
            }
            else if (cmd == "q") {
                break;
            }
        }
    }
    catch (exception &e) {
        cout << &e << endl;
    }
    return 0;
}
