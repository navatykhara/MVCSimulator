#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

#include "Control.h"

/*

Purpose:

  The class that will define the Control class. It's purpose is to allow the program to define a
  basic program flow that the user would experience. An expansion is randomly chosen for the playthrough;
  this includes different monsters and bosses the Heroes must overcome to obtain the Emerald. All enemies
  will be moved, checked for collision, and deleted if necessary. This basic program flow will continue to
  iterate until either all Heroes are dead or if one of the Heroes obtains the Emerald.

Usage:

  void launch(): Begins the program flow that the user would experience.
  void initPlayers(): Initializes the starting Heroes as well as the Boss of whichever expansion was chosen at the start.
  void initExpansion(): Initializes which expansion will be played during the session.
  bool checkRunCondition(): Checks whether all Heroes are dead or if one of the Heroes has managed to obtain the Emerald.
  void spawnFighters(): Spawns the expansion-appropriate fighters on the far right-side of the screen.
  void checkCollisions(): Checks for special interactions between players on the board if they happen to occupy the same space.
  void cleanup(): Cleans up any dead enemies or projectiles in the list.

  To use, create an object of type Control. Call the launch function to procceed to the program flow.

Authors:

  Navaty Khara

Revisions:


*/

Control::~Control(){
  for(list<QuestPlayer*>::iterator it = players.begin(); it != players.end(); ++it){
    delete (*it);
  }
}

void Control::launch(){
  srand((unsigned) time(NULL));

  view.initDungeon();
  initExpansion();
  initPlayers();
  view.display();

  while(checkRunCondition()){
    for(list<QuestPlayer*>::iterator it = players.begin(); it != players.end(); ++it){
      (*it)->move();
    }
    spawnFighters();
    checkCollisions();
    view.update(players);
    view.display();

    cleanup();
  }

}

void Control::initExpansion(){
  int rng = ((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 2 + 1;
  expansion = rng;
  if(rng == 1){
    cout << "Initializing Journey to Dragon's Hollow..." << endl;
  }else if(rng == 2){
    cout << "Initializing Tides to the Drowned Cove..." << endl;
  }
}
void Control::initPlayers(){

  int py = ((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 5;
  Hero *timmy = new Hero(3, 300, 'T', 0, py);
  py = ((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 5;
  Hero *harold = new Hero(1, 500, 'H', 0, py);

  players.push_back(timmy);
  players.push_back(harold);

  view.update(players);

  if(expansion == 1){
    Dragon *dragon = new Dragon(0, 'D', 24, 2);
    players.push_back(dragon);
  }else if(expansion == 2){
    Naga *naga = new Naga(10, 'N', 24, 2);
    players.push_back(naga);
    for(int i = 0; i < 5; i++){
      Wave *w = new Wave(8, '<', 24, i);
      players.push_back(w);
    }
  }
}


bool Control::checkRunCondition(){
  int survivors = 2;
  list<QuestPlayer*>::iterator it = players.begin();
  if((*it)->getX() > 24 && (*it)->getY() > 0 && (*it)->getY() < 3){
    cout << endl << "Timmy CLAIMS THE EMERALD!"<< endl;
    return false;
  }
  if((*it)->getHealth() <= 0){
    survivors--;
  }
  it++;
  if((*it)->getX() > 24 && (*it)->getY() > 0 && (*it)->getY() < 3){
    cout << endl << "Harold CLAIMS THE EMERALD!"<< endl;
    return false;
  }
  if((*it)->getHealth() <= 0){
    survivors--;
  }
  if(survivors == 0){
    cout << endl << "No survivors remaining."<< endl;
    return false;
  }
  return true;
}

void Control::spawnFighters(){
  if(expansion == 1){
    int fighterRNG = (((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 10) + 1;
    if(fighterRNG < 7){
      fighterRNG = (((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 3) + 1;
      int fy = (((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 5);
      Fighter *orc;
      switch(fighterRNG){
        case 1:
          fighterRNG = (((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 8) + 6;
          orc = new Fighter(fighterRNG, 'd', 24, fy);
          break;
        case 2:
          fighterRNG = (((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 11) + 8;
          orc = new Fighter(fighterRNG, 'b', 24, fy);
          break;
        case 3:
          fighterRNG = (((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 5) + 4;
          orc = new Fighter(fighterRNG, 'p', 24, fy);
          break;
      }
      players.push_back(orc);
    }
  }else if(expansion == 2){
    int fighterRNG = (((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 10) + 1;
    if(fighterRNG < 4){
      int fy = (((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 5);
      Fishmen *fishmen = new Fishmen(13, 'f', 24, fy);
      int fx = (((double)rand() / ((double)(RAND_MAX)+(double)(1))) * 4 + 1);
      Net *net = new Net(0, '@', 24 - fx, fy);
      players.push_back(fishmen);
      players.push_back(net);

    }
  }

}
void Control::checkCollisions(){
  for(list<QuestPlayer*>::iterator it = players.begin(); it != players.end(); ++it){
    for(list<QuestPlayer*>::iterator sit = players.begin(); sit != players.end(); ++sit){
      if((*it)->getX() == (*sit)->getX() && (*it)->getY() == (*sit)->getY() && (*it) != (*sit)){
        (*it)->collision((*sit));
      }
    }
  }
}
void Control::cleanup(){
  for(list<QuestPlayer*>::iterator it = players.begin(); it != players.end(); ++it){
    if(((*it)->getHealth() <= 0 || (*it)->getX() < 0) && ((*it)->getAvatar() != 'H' && (*it)->getAvatar() != 'T' && (*it)->getAvatar() != 'D' && (*it)->getAvatar() != 'N' && (*it)->getAvatar() != '+')){
      delete (*it);
      it = players.erase(it);
    }

  }
}
