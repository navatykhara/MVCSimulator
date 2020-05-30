#ifndef FISHMEN_H
#define FISHMEN_H

#include "QuestPlayer.h"
class Fishmen: public QuestPlayer{

  public:
    Fishmen(int, char, int, int);
    void move();
    void collision(QuestPlayer*);
  private:


};

#endif
