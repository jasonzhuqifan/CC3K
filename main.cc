#include <iostream>
#include <ncurses.h>
#include "GameGrid.h"

using namespace std;

int main() {
    string cmd;
    GameGrid g;
    bool raceSet = false;
    g.printStart();
    bool wasd = false;
    int ch;
    try {
        while (true) {
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
                cmd = ch;
            }
            
            if (cmd == "e" ) {
                cout << endl << "WASD Control Enabled" << endl << endl;
                wasd = true;
            }
            else if (cmd == "c" ) {
                cout << endl << "WASD Control Disabled" << endl << endl;
                wasd = false;
            }
            else if (!raceSet && (cmd == "s" || cmd == "d" || cmd == "v" ||
                                  cmd == "g" || cmd == "t" || cmd == "x")) {
                g.setRace(cmd.front());
                raceSet = true;
            }
            else if (wasd && (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w') && raceSet) {
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
                g.move(cmd);
            }
            else if (!wasd && (cmd == "no" || cmd == "we" || cmd == "so" || cmd == "ea" ||
                     cmd == "ne" || cmd == "nw" || cmd == "se" || cmd == "sw") && raceSet) {
                g.move(cmd);
            }
            else if (cmd == "u" && raceSet) {
                string dir;
                if(wasd) {
                    cout << "Please enter a direction for using" << endl;
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
                    cout << "Please enter a direction for attacking" << endl;
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
            else if (cmd == "f" && raceSet) {
                cout << "Toggle Freeze" << endl;
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
    }
    catch (exception &e) {
        cout << &e << endl;
    }
    return 0;
}
