#include <iostream>
using namespace std;

#include "Net.h"

/*

Purpose:

  The class that will define the Net class. It's purpose is to serve as a trap which spawns during the Tides to the Drowned Cove campaign expansion.
  It possesses all the necessary data members of a QuestPlayer. This class has defined functions like move() and collision(QuestPlayer*) for the purpose of interacting with the
  data members in specific ways. The Net class will be thrown by the Fishmen emerge once they emerge from the Cove. As the Fishmen are out of water, they tend to be less accurate
  so the Nets will land a varied distance in front of them. If it so happens that a Hero gets caught in these Nets, they will be ensnared for one iteration as they struggle to out.
  Should they take too long, the rising tides and emerging Fishmen will soon overpower them. The nets disappear after 1 iteration.

Usage:

  void move(): As these are nets, the move function does nothing of importance
  void collision(QuestPlayer*): A function whose purpose is to wittle down the nets if it hits a Hero.

Authors:

  Navaty Khara

Revisions:


*/

Net::Net(int s, char a, int x, int y): QuestPlayer(1, s, a, x, y){
}
void Net::move(){}
void Net::collision(QuestPlayer* qp){
  if(!(health > 0)){
    return;
  }
  health -= 1;
}
