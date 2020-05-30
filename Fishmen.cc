#include <iostream>
using namespace std;

#include "Fishmen.h"
/*

Purpose:

  The class that will define the Fishmen class. It's purpose is to serve as an enemy which spawns during the Tides to the Drowned Cove campaign expansion.
  It possesses all the necessary data members of a QuestPlayer. This class has defined functions like move() and collision(QuestPlayer*) for the purpose of interacting with the
  data members in specific ways. The Fishmen class are few and far between though strong and cunning.They move to the left-side of the board at random, attacking Heroes they collide with.
  A fishmen is always accompanied by his net which spawns with him during each iteration. Being out of their element, the fishmen slowly lose health until hit by a wave. Once hit,
  their health is replenished.

Usage:

  void move(): A function to move the Fishmen to the left but at random vertical positions.
  void collision(QuestPlayer*): A function that forces the Fishmen to take damage upon interacting with a Hero and regain Health when interacting with a Wave.

Authors:

  Navaty Khara

Revisions:


*/

Fishmen::Fishmen(int s, char a, int x, int y): QuestPlayer(6, s, a, x, y){
}
void Fishmen::move(){
  x = x - 1 < 0 ? 0 : x - 1;
  int py = (((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 2) + 1;
  py = py == 1 ? 1 : -1;
  y += py;
  health--;
}
void Fishmen::collision(QuestPlayer* qp){
  if(!(health > 0)){
    return;
  }
  if(qp->getAvatar() == 'H' || qp->getAvatar() == 'T'){
    health -= qp->getStrength();
  }else if(qp->getAvatar() == '<'){
    health += 4;
  }
}
