#ifndef CONTROL_H
#define CONTROL_H
#include <list>

#include "QuestPlayer.h"
#include "View.h"
#include "Hero.h"
#include "Dragon.h"
#include "Fighter.h"
#include "Naga.h"
#include "Wave.h"
#include "Fishmen.h"
#include "Net.h"

using namespace std;

class Control
{
  public:
    ~Control();
    void launch();
  private:
    list<QuestPlayer*> players;
    View view;
    int expansion;
    void initPlayers();
    void initExpansion();
    bool checkRunCondition();
    void spawnFighters();
    void checkCollisions();
    void cleanup();

};

#endif
