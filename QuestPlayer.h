#ifndef QUESTPLAYER_H
#define QUESTPLAYER_H
#include <list>

class QuestPlayer
{
  public:
    QuestPlayer(int, int, char, int, int);
    int getX();
    int getY();
    char getAvatar();
    int getStrength();
    int getHealth();
    virtual void move() = 0;
    virtual void collision(QuestPlayer*) = 0;
  protected:
    int health;
    int strength;
    char avatar;
    int x;
    int y;
};
#endif
