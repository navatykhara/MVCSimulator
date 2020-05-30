#ifndef HERO_H
#define HERO_H

#include "QuestPlayer.h"

class Hero : public QuestPlayer{

  public:
    Hero(int, int, char, int, int);
    void move();
    void collision(QuestPlayer*);
  private:
    int armour;
    bool impaired;

};


#endif
