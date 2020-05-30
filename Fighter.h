#ifndef FIGHTER_H
#define FIGHTER_H

#include "QuestPlayer.h"

class Fighter: public QuestPlayer{

  public:
    Fighter(int, char, int, int);
    void move();
    void collision(QuestPlayer*);
  private:

};

#endif
