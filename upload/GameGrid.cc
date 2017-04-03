#include "GameGrid.h"
#include "Drow.h"
#include "Goblin.h"
#include "Shade.h"
#include "Troll.h"
#include "Vampire.h"
#include "Student.h"

#include "Level.h"
#include "Player.h"
#include "textDisplay.h"
#include "Floor.h"

using namespace std;

GameGrid::GameGrid() {}

//GameGrid::~GameGrid(){
//    delete pc;
//}

void GameGrid::init(){
    l = make_shared<Floor>();
    shared_ptr<Floor> f = dynamic_pointer_cast<Floor>(l);
    f->init(pc);
    l = f;
}

void GameGrid::move(string dir){
    pc->move(dir);
    if (pc->hasReachedShairs()) {
        pc = pc->getTrue();
        if(pc->goUpstairs() > 2) {
            win();
        }
        else {
            init();
            cout << *l;
            pc->PrintMessages();
        }
    }
    else if (pc->hasDead()) {
        lose();
    }
    else {
        cout << *l;
        pc->PrintMessages();
    }
}

void GameGrid::use(string dir) {
    pc = l->use(pc, dir);
    if(pc->hasDead()) {
        lose();
    }
    else {
        cout << *l;
        pc->PrintMessages();
    }
}

void GameGrid::attack(string dir){
    pc->attack(dir,pc);
    if(pc->hasDead()) {
        lose();
    }
    else {
        cout << *l;
        pc->PrintMessages();
    }
}

void GameGrid::setRace(char race){
    switch (race) {
        case 's': pc = make_shared<Shade>(); break;
        case 'd': pc = make_shared<Drow>(); break;
        case 'v': pc = make_shared<Vampire>(); break;
        case 'g': pc = make_shared<Goblin>(); break;
        case 't': pc = make_shared<Troll>(); break;
        case 'x' : pc = make_shared<Student>(); break;
        default: throw "unknown race"; break;
    }
    init();
    cout << *l;
    pc->PrintMessages();
}

void GameGrid::freeze(){
    pc->setFrozen();
}

//void GameGrid::clearGrid(){
//    delete l;
//}

//ostream &operator<<(std::ostream &out, const GameGrid &g){
//    out << *(g.l);
//    g.pc->PrintMessages();
//    return out;
//}

void GameGrid::win() {
    printWin();
}

void GameGrid::lose() {
    printLose();
}

void GameGrid::printStart() {
    cout << "               CC3KCC3  CC3KCC3  KCC3KCC  CC  CC3" << endl;
    cout << "               KCC3KCC  KCC3KCC   KCC3KC  KC  KC" << endl;
    cout << "               3K       3K            3K  3K C3K" << endl;
    cout << "               C3       C3            C3  C3 CC" << endl;
    cout << "               CC       CC         C3KCC  CCKC" << endl;
    cout << "               KC       KC         CC3KC  KC 3K" << endl;
    cout << "               3K       3K            3K  3K  3K" << endl;
    cout << "               C3       C3            C3  C3  C3" << endl;
    cout << "               CC3KCC3  CC3KCC3   CC3KCC  CC  CC3" << endl;
    cout << "               KCC3KCC  KCC3KCC  3KCC3KC  KC   CC" << endl << endl;
    cout << "                                   Copyright© University of Waterloo"  << endl << endl;
    cout << "Welcome to CC3K produced by Yinong Wang, Raymond Tan, and Qifan Zhu." << endl << endl;
    cout << "               To start the game, choose a race: " << endl << endl;
    cout << "               •Shade(s) -- Score Bonus" << endl;
    cout << "               •Drow(d) -- Potion Effect Magnified" << endl;
    cout << "               •Vampire(v) -- Steal HP" << endl;
    cout << "               •Troll(t) -- Self-Healing" << endl;
    cout << "               •Goblin(g) -- Steal Gold" << endl << endl;
     cout << "              •Student(x) -- Steal Gold" << endl << endl;
    printInstruction();
}

void GameGrid::printWin() {
    cout << "CONGRAT  CONGRAT  CONGRAT  CONGRAT  CONGRAT    NGR   SCONGRA  SCONGRA" << endl;
    cout << "GRATSCO  GRATSCO  GRATSCO  GRATSCO  GRATSCO    ATS   NGRATSC  NGRATSC" << endl;
    cout << "TS       TS   GR  TS   GR  TS       TS   GR    CON      CO    AT" << endl;
    cout << "ON       ON   TS  ON   TS  ON       ON   TS    GRAT     GR    CO" << endl;
    cout << "RA       RA   ON  RA   ON  RA SCON  RASCON    ATSCO     TS    GRATSC" << endl;
    cout << "SC       SC   RA  SC   RA  SC NGRA  SCNGRA    CO GR     ON    TSCONGR" << endl;
    cout << "NG       NG   SC  NG   SC  NG   SC  NG  TS    GR TS     RA         TS" << endl;
    cout << "AT       AT   NG  AT   NG  AT   NG  AT  ON    TS  NG    SC         ON" << endl;
    cout << "CONGRAT  CONGRAT  CO   AT  CONGRAT  CO  RA   CON RAT    NG    SCONGRA" << endl;
    cout << "GRATSCO  GRATSCO  GR   CO  GRATSCO  GR   CO  GRA SCO    AT    NGRATSC" << endl;
    cout << endl << endl;
    cout << "OU   NY  U WINYO  WW   OU        WI   UU   YO  WW  YOU WIN" << endl;
    cout << "WI   UU  INYOU W  NY   WI        YO   IN   WW  NY  WWINYOU" << endl;
    cout << "YO   IN  OU   NY  U    YO        WW   OU   NY  UU  NY   WI" << endl;
    cout << "WW   OU  WI   UU  IN    W        NY   WI   UU  IN  UU   YO" << endl;
    cout << "NYOU WI  YO   IN  OU   NY        UW   YO   IN  OU  IN   WW" << endl;
    cout << "U WINYO  WW   OU  WI   UU        IN   WW   OU  WI  OU   NY" << endl;
    cout << "  YOU    NY   WI  YO   IN        OU   NY   WI  YO  WI   UU" << endl;
    cout << "   WI    UU   YO  WW   OU        WI   UW   YO  WW  YO   IN" << endl;
    cout << "   YO    INYOU W  NYOU WI        YOU WINYOUW   WY  WW   OU" << endl;
    cout << "   W     OU WINY  U WINYO         WINYOU WIW   UU  NY   WI" << endl << endl;
    cout << "Your score is: " << calcScore() << endl << endl;
    cout << "Press r to restart the game" << endl << endl;
}

void GameGrid::printLose() {
    cout << "ERGAMEE    RGA    OVERGAMEEEVV  GAMEEOV       OVERGAM  OO    GA    OVERGA  E OVERG" << endl;
    cout << "OVERGAM    VER    EEOVERGAEEOO  ERGAME        EEOVERG  ME    ER   ME OVE   AME OVE" << endl;
    cout << "EE         COV    AM   VE   ME  OV            AM   VE  AM    OV   GA       RG    O" << endl;
    cout << "AM         MEOO   RG   OO   GA  EE            RG    O   RG  ME    ER       VE   ME" << endl;
    cout << "RG  EOO   RGAME   VE   ME   ER  AMEOV         VE   ME   VE  GA    OVERGA   OERGA" << endl;
    cout << "VE  AME   VE GA   OO   GA   OV  RGAME         OO   GA   EE  ER    E OVER   ME OVER" << endl;
    cout << "OO   GA   O  ER   ME   ER   EE  VE            ME   ER    E  O     AM       GA   O" << endl;
    cout << "ME   ER   ME  VE  GA   OV   AM  EO            GA   OV    A  E     RG       ER   ME" << endl;
    cout << "GAME OV  RGA  EO  ER   EE   RG  MEEOVER       ERGAMEE    RRAA     VERGAME  OV   GA" << endl;
    cout << "ERGAMEE  VER  ME  OV   AM   VE  GAMEEOE       OVERGAM     ER       OVERG   E     RG" << endl << endl;
    cout << "Press r to restart the game" << endl << endl;
}

int GameGrid::calcScore() {
    if(dynamic_pointer_cast<Shade>(pc)) {
        return pc->getGold()*1.5;
    }
    return pc->getGold();
}

void GameGrid::printInstruction() {
    cout << "            |----------------------------------------|" << endl;
    cout << "            | Instruction:                           |" << endl;
    cout << "            |   Move: <dir>(no,so,ea,we,ne,nw,se,sw) |" << endl;
    cout << "            |   Use Item: u <dir>                    |" << endl;
    cout << "            |   Attack Enemy: a <dir>                |" << endl;
    cout << "            |   Freeze Enemy: f                      |" << endl;
    cout << "            |   Restart Game: r                      |" << endl;
    cout << "            |   Quit Game: q                         |" << endl;
    cout << "            |----------------------------------------|" << endl << endl;
}
