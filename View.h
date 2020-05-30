#ifndef VIEW_H
#define VIEW_H

#include "Dungeon.h"
#include "QuestPlayer.h"
using namespace std;

class View
{
  public:
    View();
    ~View();
    void display();
    void update(list<QuestPlayer*>);
    void initDungeon();
  private:
    Dungeon<char> dungeon;

};

#endif
