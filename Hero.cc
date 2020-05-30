#include <iostream>
using namespace std;

#include "Hero.h"

/*

Purpose:

  The class that will define the Hero class. It's purpose is to serve as a hero which spawns during any campaign expansion.
  It possesses all the necessary data members of a QuestPlayer. This class has defined functions like move() and collision(QuestPlayer*) for the purpose of interacting with the
  data members in specific ways. The Hero class will walk to the right-side of the board at random vertical positions, interacting with any other players they collide with. These
  interactions are detailed in their respective classes.

Usage:

  void move(): A function to move the Hero to the right but at random vertical positions.
  void collision(QuestPlayer*): A function that outlines the interactions a Hero has with other players.

Authors:

  Navaty Khara

Revisions:


*/

Hero::Hero(int r, int s, char a, int x, int y): QuestPlayer(15, s, a, x, y){
  armour = r;
  impaired = false;
}

void Hero::move(){

  if(health > 0 && !(impaired)){
    int px = x + 1 > 24 && (y < 1 || y > 3) ? 0 : 1;
    int py = (((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 2)+1;
    py = py == 1 ? 1 : -1;

    py = y + py > 4 || y + py < 0 ? 0 : py;

    y += py;
    x += px;
  }
  if(impaired){
    impaired = false;
  }

}

void Hero::collision(QuestPlayer* qp){
  if(!(health > 0)){
    return;
  }

  if(qp->getAvatar() == 'b' || qp->getAvatar() == 'd' || qp->getAvatar() == 'p'){
    int damage = qp->getStrength() - armour < 0 ? 0 : qp->getStrength() - armour;
    health -= damage;
    if(health <= 0){
      avatar = '+';
    }
  }else if(qp->getAvatar() == 'D'){
    health = 0;
    avatar = '+';
  }else if(qp->getAvatar() == 'N'){
    health -= qp->getStrength();
    impaired = true;
  }else if(qp->getAvatar() == '<'){
    health -= qp->getStrength();
    avatar = health <= 0 ? '+' : avatar;
    x = x - 2 < 0 ? x : x - 2;
    qp->collision(this);
  }else if(qp->getAvatar() == '@'){
    impaired = true;
  }


}
