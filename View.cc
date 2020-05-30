#include <iostream>
#include <list>

#include "View.h"

using namespace std;

/*

Purpose:

  The class that will define the View class. It's purpose is to allow the program to define a
  basic representation of the players and the dungeon they inhabit. This class is responsible for handling
  this representation. More specifically, this class is responsible for allowing the user to graphically
  print what is occurring as well as updating the changes that occur during a playthrough. View uses an
  underlying data-structure, Dungeon, to handle the data aspects of the graphics.

Usage:

  View(): Default constructor.
  ~View(): Default deconstructor.
  void display(): Prints a graphical representation of the board and its players/
  void update(list<QuestPlayer*>): Updates Dungeon to reflect the changes that have occurred since the last iteration.
  void initDungeon(): Initializes the underlying data-structure with empty spaces.

  To use, create an object of type View.

Authors:

  Navaty Khara

Revisions:


*/


View::View(){}
View::~View(){}

void View::display(){
  cout << "|";
  for(int i = 0; i < 25; i++){
    cout << "-";
  }
  cout << "|" << endl;

  for(int i = 0; i < 5; i++){
    cout << "|";
    for(int j = 0; j < 25; j++){
      cout << dungeon.get(i, j);
    }
    if(0 < i && i < 4)
      cout << "=";
    else
      cout << "|";
      if(i == 2){
        cout << " *";
      }
    cout << endl;
  }


  cout << "|";
  for(int i = 0; i < 25; i++){
    cout << "-";
  }
  cout << "|" << endl;

}
void View::update(list<QuestPlayer*> players){
  list<QuestPlayer*>::reverse_iterator it;
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 25; j++){

      dungeon.set(i,j, ' ');
      for(it = players.rbegin(); it != players.rend(); ++it){

        if((*it)->getX() == j && (*it)->getY() == i){
          dungeon.set(i,j, (*it)->getAvatar());
        }

      }

    }
  }
}

void View::initDungeon(){
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 25; j++){
      dungeon.set(i, j, ' ');
    }
  }

}
