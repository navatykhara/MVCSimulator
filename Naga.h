#ifndef NAGA_H
#define NAGA_H

#include "QuestPlayer.h"
class Naga: public QuestPlayer{

  public:
    Naga(int, char, int, int);
    void move();
    void collision(QuestPlayer*);
  private:
    int velocity;


};

#endif
