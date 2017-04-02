#include <iostream>
#include "GameGrid.h"

using namespace std;

int main() {
    string cmd, aux;
    GameGrid g;
    bool raceSet = false;
    cout << "CC3KCC3  CC3KCC3  KCC3KCC  CC  CC3" << endl;
    cout << "KCC3KCC  KCC3KCC   KCC3KC  KC  KC" << endl;
    cout << "3K       3K            3K  3K C3K" << endl;
    cout << "C3       C3            C3  C3 CC" << endl;
    cout << "CC       CC         C3KCC  CC KC" << endl;
    cout << "KC       KC         CC3KC  KC 3K" << endl;
    cout << "3K       3K            3K  3K  3K" << endl;
    cout << "C3       C3            C3  C3  C3" << endl;
    cout << "CC3KCC3  CC3KCC3   CC3KCC  CC  CC3" << endl;
    cout << "KCC3KCC  KCC3KCC  3KCC3KC  KC   CC" << endl << endl;
    cout << "Welcome to CC3K produced by Yinong Wang, Raymond Tan, and Qifan Zhu." << endl;
    cout << "To start the game, choose a race: s, d, v, g, t" << endl;
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
