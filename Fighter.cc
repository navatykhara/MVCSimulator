#include <iostream>
using namespace std;

#include "Fighter.h"

/*

Purpose:

  The class that will define the Fighter class. It's purpose is to serve as an enemy which spawns during he Journey to Dragon's Hollow campaign expansion.
  It possesses all the necessary data members of a QuestPlayer. This class has defined functions like move() and collision(QuestPlayer*) for the purpose of interacting with the
  data members in specific ways. The Fighter class will shamble to the left-side of the board at random, attacking Heroes they collide with. Fighters come in 3 variants as defined
  in the Control class. A fighter will only ever interact with Heroes.

Usage:

  void move(): A function to move the Fighter to the left but at random vertical positions.
  void collision(QuestPlayer*): A function that forces the Fighter to take damage upon interacting with a Hero.

Authors:

  Navaty Khara

Revisions:


*/

Fighter::Fighter(int s, char a, int x, int y): QuestPlayer(5, s, a, x, y){
}
void Fighter::move(){
    x = x - 1 < 0 ? 0 : x - 1;
    int py = (((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 2) + 1;
    py = py == 1 ? 1 : -1;
    y += py;
}
void Fighter::collision(QuestPlayer* qp){
  if(!(health > 0)){
    return;
  }
  if(qp->getAvatar() == 'H' || qp->getAvatar() == 'T'){
    health -= qp->getStrength();
  }

}
