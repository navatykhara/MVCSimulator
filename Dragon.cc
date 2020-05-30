#include <iostream>
using namespace std;

#include "Dragon.h"
/*

Purpose:

  The class that will define the Dragon class. It's purpose is to serve as a boss which spawns at the beginning of the Journey to Dragon's Hollow campaign expansion.
  It possesses all the necessary data members of a QuestPlayer. This class has defined functions like move() and collision(QuestPlayer*) for the purpose of interacting with the
  data members in specific ways. The Dragon class will trek back and forth along the entrance of the Cave, and will instakill a player if they interact.
  The Dragon being a Boss will not be affected by the Heroes and thus must be evaded in order to retrieve the Emerald.

Usage:

  void move(): A function to move the Naga up and down the far-right side of the board.
  void collision(QuestPlayer*): A function whose purpose is to force other child classes to define a specific way their player interacts with other players. Since the Dragon does not interact
                                with other players, no code is needed.

Authors:

  Navaty Khara

Revisions:


*/

Dragon::Dragon(int s, char a, int x, int y): QuestPlayer(-1, s, a, x, y){
  velocity = 1;
}
void Dragon::move(){
  velocity = y + velocity < 1 || y + velocity > 3 ? velocity*-1: velocity;
  y += velocity;
}
void Dragon::collision(QuestPlayer* qp){


}
