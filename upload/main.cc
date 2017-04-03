#include <iostream>
#include <ncurses.h>
#include "GameGrid.h"

using namespace std;

int main() {
    string cmd;
    GameGrid g;
    bool raceSet = false;
    g.printStart();
#ifdef Bonus
    bool wasd = false;
    int ch;
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    ch = getch();
    endwin();
    if(ch == 'e') {
        wasd = true;
    }
#endif
    try {
        while (true) {
#ifndef Bonus
            cin >> cmd;
            if ((cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" ||
                 cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw") && raceSet) {
                g.move(cmd);
            }
            else if (cmd == "u" && raceSet) {
                string dir;
                cin >> dir;
                g.use(dir);
            }
            else if (cmd == "a" && raceSet) {
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
            else if (cmd == "f" && raceSet) {
                g.freeze();
            }
            else if (cmd == "r" && raceSet) {
                raceSet = false;
                g.init();
                cout << "Game Restarted" << endl << endl;
                g.printStart();
            }
            else if (cmd == "q") {
                break;
            }
            else {
                if (raceSet) {
                    cout << "Invalid Input" << endl;
                    g.printInstruction();
                } else {
                    cout << "Choose A Race to Start Game" << endl;
                    g.printRaces();
                }
            }
        }
#endif
#ifdef Bonus
        if (!wasd) {
            cin >> cmd;
        }
        else {
            initscr();
            cbreak();
            noecho();
            keypad(stdscr, TRUE);
            ch = getch();
            endwin();
            switch (ch) {
                case 'w':
                    cmd = "no";
                    break;
                case 'a':
                    cmd = "we";
                    break;
                case 's':
                    cmd = "so";
                    break;
                case 'd':
                    cmd = "ea";
                    break;
                default:
                    cmd = ch;
                    break;
            }
        }
        if (cmd == "e" ) {
            cout << "WASD Control Enabled" << endl;
            wasd = true;
        }
        else if (cmd == "c" ) {
            cout << "WASD Control Disabled" << endl;
            wasd = false;
        }
        else if ((cmd == "no" || cmd == "so" || cmd == "ea" || cmd == "we" ||
                  cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw") && raceSet) {
            g.move(cmd);
        }
        else if (cmd == "u" && raceSet) {
            string dir;
            if(wasd) {
                initscr();
                cbreak();
                noecho();
                keypad(stdscr, TRUE);
                ch = getch();
                endwin();
                switch (ch) {
                    case 'w':
                        dir = "no";
                        break;
                    case 'a':
                        dir = "we";
                        break;
                    case 's':
                        dir = "so";
                        break;
                    case 'd':
                        dir = "ea";
                        break;
                    default:
                        break;
                }
            }
            else {
                cin >> dir;
            }
            g.use(dir);
        }
        else if ((cmd == "a" || cmd == "i") && raceSet) {
            string dir;
            if(wasd) {
                initscr();
                cbreak();
                noecho();
                keypad(stdscr, TRUE);
                ch = getch();
                endwin();
                switch (ch) {
                    case 'w':
                        dir = "no";
                        break;
                    case 'a':
                        dir = "we";
                        break;
                    case 's':
                        dir = "so";
                        break;
                    case 'd':
                        dir = "ea";
                        break;
                    default:
                        break;
                }
            }
            else {
                cin >> dir;
            }
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
        else if (cmd == "f" && raceSet) {
            g.freeze();
        }
        else if (cmd == "r" && raceSet) {
            raceSet = false;
            g.init();
            cout << "Game Restarted" << endl << endl;
            g.printStart();
        }
        else if (cmd == "q") {
            break;
        }
        else {
            if (raceSet) {
                cout << "Invalid Input" << endl;
                g.printInstruction();
            } else {
                cout << "Choose A Race to Start Game" << endl;
                //g.printRaces();
            }
        }
#endif
    }
    catch (exception &e) {
        cout << &e << endl;
    }
    return 0;
}
