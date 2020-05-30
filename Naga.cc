#include <iostream>
using namespace std;

#include "Naga.h"
/*

Purpose:

  The class that will define the Naga class. It's purpose is to serve as a boss which spawns at the beginning of the Tides to the Drowned Cove campaign expansion.
  It possesses all the necessary data members of a QuestPlayer. This class has defined functions like move() and collision(QuestPlayer*) for the purpose of interacting with the
  data members in specific ways. The Naga class will trek back and forth along the shores of the Cove, and though it will not instakill a player like a Dragon, it will inflict
  significant heavy damage. The Naga being a Boss will not be affected by the Heroes and thus must be evaded in order to retrieve the Emerald.

Usage:

  void move(): A function to move the Naga up and down the far-right side of the board.
  void collision(QuestPlayer*): A function whose purpose is to force other child classes to define a specific way their player interacts with other players. Since the Naga emerged from
                                the depths, submerging under the waves rejuvinates the Naga giving her increased strength.

Authors:

  Navaty Khara

Revisions:


*/


Naga::Naga(int s, char a, int x, int y): QuestPlayer(50, s, a, x, y){
  velocity = 1;
}
void Naga::move(){
  velocity = y + velocity < 0 || y + velocity > 4 ? velocity*-1: velocity;
  y += velocity;
}
void Naga::collision(QuestPlayer* qp){
  if(qp->getAvatar() == '<'){
    strength += 10;
  }

}
