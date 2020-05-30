#ifndef WAVE_H
#define WAVE_H

#include "QuestPlayer.h"

class Wave: public QuestPlayer{

  public:
    Wave(int, char, int, int);
    void move();
    void collision(QuestPlayer*);
  private:

};

#endif
