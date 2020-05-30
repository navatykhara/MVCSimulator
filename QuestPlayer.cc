#include <iostream>
using namespace std;

#include "QuestPlayer.h"

/*

Purpose:

  The class that will define the QuestPlayer parent class. It's purpose is to act as a base class which all other
  players will derive from. It possesses all the necessary data members required for a combat-oriented player character such as
  health and strength as well as general data members to represent traits like position (x, y) and avatar to represent
  it. This parent class has defined virtual functions like move() and collision(QuestPlayer*) for future overrides. These
  functions were defined for the purpose of interacting with the data members in specific ways.

Usage:

  virtual void move() = 0: Abstract function whose purpose is to force other child classes to define a specific way their player moves.
  virtual void collision(QuestPlayer*) = 0: Abstract function whose purpose is to force other child classes to define a specific way their player interacts with other players.

Authors:

  Navaty Khara

Revisions:


*/

QuestPlayer::QuestPlayer(int h, int s, char a, int x, int y){
  health = h;
  strength = s;
  avatar = a;
  this->x = x;
  this->y = y;
}
int QuestPlayer::getX(){
  return x;
}
int QuestPlayer::getY(){
  return y;
}
char QuestPlayer::getAvatar(){
  return avatar;
}
int QuestPlayer::getStrength(){
  return strength;
}
int QuestPlayer::getHealth(){
  return health;
}
