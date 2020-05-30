#ifndef DUNGEON_H
#define DUNEGON_H
#include <iostream>
using namespace std;
/*

Purpose:

  The class that will define the Dungeon class. It's purpose is to serve as the collection class for View. It will allow for basic search functioniality which will allow the user
  to identify the player that is currently occupying a particular space. It also allows the setting of specific players into specific areas of the dungeon. The players are represented
  as chars as defined by their avatar data members. These chars are stored in a double array of Type T if the need to use other types of data arises.

Usage:

  Dungeon(): Default constructor which initializes the 2D array.
  ~Dungeon(): Default deconstructor which deallocates the 2D array.
  T get(int, int): Gets the value at position x, y
  void set(int, int, T): Sets the value at position x, y equal to the parameter

  To use, create an object of type Dungeon.

Authors:

  Navaty Khara

Revisions:


*/

template <class T>
class Dungeon{

  public:
    Dungeon();
    ~Dungeon();
    T get(int, int);
    void set(int, int, T);
  private:
    T ** dungeon;

};

template <class T>
Dungeon<T>::Dungeon(){

  dungeon = new T*[5]();
  for(int i = 0; i < 5; i++){
    dungeon[i] = new T[25]();
  }


}

template <class T>
Dungeon<T>::~Dungeon(){

  for(int i = 0; i < 5; i++) {
    delete [] dungeon[i];
  }
  delete [] dungeon;

}

template <class T>
T Dungeon<T>::get(int i, int j){
  return dungeon[i][j];
}

template <class T>
void Dungeon<T>::set(int i, int j, T obj){
  dungeon[i][j] = obj;
}


#endif
