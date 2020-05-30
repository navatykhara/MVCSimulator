#include <iostream>
using namespace std;

#include "Wave.h"

/*

Purpose:

  The class that will define the Wave class. It's purpose is to serve as a projectile which spawns at the beginning of the Tides to the Drowned Cove campaign expansion.
  It possesses all the necessary data members of a QuestPlayer. This class has defined functions like move() and collision(QuestPlayer*) for the purpose of interacting with the
  data members in specific ways. The Wave class will continuously flow from the far right-side of the board to the left, knocking all Heroes back as they struggle against the tide.
  The Heroes take slight damage as they brace for impact but if they hold on, the tides will simmer and they will eventually move forward. This is just to say that the Waves will
  eventually disappear after hitting the Heroes.

Usage:

  void move(): A function whose purpose is to move the Wave to the far-left from the far-right.
  void collision(QuestPlayer*): A function whose purpose is to wittle down the waves as it hits Heroes.

Authors:

  Navaty Khara

Revisions:


*/

Wave::Wave(int s, char a, int x, int y): QuestPlayer(15, s, a, x, y){
}
void Wave::move(){
    x = x - 1 < 0 ? 24 : x - 1;
}
void Wave::collision(QuestPlayer* qp){
  if(!(health > 0)){
    return;
  }
  if(qp->getAvatar() == 'H' || qp->getAvatar() == 'T'){
    health -= qp->getStrength();
  }

}
