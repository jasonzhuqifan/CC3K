#include <iostream>
#include "GameGrid.h"

using namespace std;

int main() {
    string cmd, aux;
    GameGrid g;
    bool raceSet = false;
    
    try {
        while (true) {
            cin >> cmd;
            if (cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" ||
                cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw" ) {
                g.move(cmd);
                cout << g;
            }
            else if (cmd == "u") {
                string dir;
                cin >> dir;
                g.use(dir);
                cout << g;
            }
            else if (cmd == "a") {
                string dir;
                cin >> dir;
                g.attack(dir);
                cout << g;
            }
            else if (cmd.front() == 's' || cmd.front() == 'd' ||
                     cmd.front() == 'v' || cmd.front() == 'g' ||
                     cmd.front() == 't') {
                if (raceSet) {
                    cout << "Race has been set. Restart to play with new race";
                }
                else {
                    g.setRace(cmd.front());
                    raceSet = true;
                    g.init();
                    cout << g;
                }
            }
            else if (cmd == "f") {
                g.freeze();
            }
            else if (cmd == "r") {
                raceSet = false;
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
