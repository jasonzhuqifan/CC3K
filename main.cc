#include <iostream>
#include "GameGrid.h"

using namespace std;

int main() {
    string cmd, aux;
    GameGrid g;
    bool raceSet = false;
    g.printStart();
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
            else if (cmd == "s" || cmd == "d" || cmd == "v" ||
                     cmd == "g" || cmd == "t" || cmd == "x") {
                if (raceSet) {
                    cout << endl << "Race has been set. Restart(r) to play with new race" << endl;
                }
                else {
                    g.setRace(cmd.front());
                    raceSet = true;
                }
            }
            else if (cmd == "f") {
                g.freeze();
            }
            else if (cmd == "r") {
                raceSet = false;
                g.init();
                cout << "Game Restarted" << endl << endl;
                g.printStart();
            }
            else if (cmd == "q") {
                break;
            }
            else {
                cout << "Invalid Input" << endl;
                g.printInstruction();
            }
        }
    }
    catch (exception &e) {
        cout << &e << endl;
    }
    return 0;
}
