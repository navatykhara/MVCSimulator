#ifndef NET_H
#define NET_H

#include "QuestPlayer.h"
class Net: public QuestPlayer{

  public:
    Net(int, char, int, int);
    void move();
    void collision(QuestPlayer*);
  private:


};

#endif
