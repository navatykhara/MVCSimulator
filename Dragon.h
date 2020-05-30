#ifndef DRAGON_H
#define DRAGON_H

#include "QuestPlayer.h"

class Dragon: public QuestPlayer{

  public:
    Dragon(int, char, int, int);
    void move();
    void collision(QuestPlayer*);
  private:
    int velocity;

};

#endif
