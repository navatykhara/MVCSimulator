Program: Assignment 5 (COMP2404 Final)
Revision Authors: Navaty Khara (101116910)
Files included:
Control.cc  Dungeon.h   Fishmen.h  Makefile  Net.h           View.cc  COMP2404_NAVATYKHARA_UMLDIAGRAM.pdf
Control.h   Fighter.cc  Hero.cc    Naga.cc   QuestPlayer.cc  View.h
Dragon.cc   Fighter.h   Hero.h     Naga.h    QuestPlayer.h   Wave.cc
Dragon.h    Fishmen.cc  main.cc    Net.cc    README.txt      Wave.h
Method of Compilation:
Type make into the terminal. Type ./a5.

Innovative Features:

1./During start-up, the program will randomly choose 1 from 2 campaigns that have been made.
  The default campaign involves the Dragon and Fighters overwhelming our Heroes.
  The new campaign that I've implemented involves the Nagas and Fishmen battling our Heroes in a war of attrition.
  This expansion picker feature can be used to implement future campaigns.

2./The addition of a regular enemy: Fishmen.
  The Fishmen are much like the Fighters but differ in that they are much more prone to damage but have on average higher strength.
  Since they are out of their natural environment, the Fishmen constantly lose health and will eventually die. If they manage to get hit
  by a Wave, the Fishmen will regenerate and begin marching forward again. The Fishmen will spawn with their nets placed at some
  random distance ahead of them to simulate the Fishmen throwing them.

3./The addition of a projectile enemy: the Wave.
  The Wave spawns at the beginning of the campaign and will continuously flow towards the left-side. Upon reaching the end, another wave will
  begin making its way to the left. All Hero's caught in the wave will be damaged and pushed back. The Waves are not all-powerful and will
  eventually simmer down as the Heroes brace the tides. Should they fail to endure, they may find themselves taking too much damage before ever doing anything.

4./The addition of a trap enemy: the Net.
  The Net spawns in front of the Fishmen to simulate the Fishmen throwing it out as they come out of the waters. The Nets are static enemies, meaning they do not move.
  However, should a Hero fall victim into one of these traps, they'll find themselves unable to move (for one iteration). The Nets force Heroes into bad positions, causing
  them to take incremental damage from the Waves as well as making it easier for Fishmen to encroach on them.

5./The addition of a status system: Impairment.
  The Net introduces a whole new system to the game, the impairment system. Units that are impaired are unable to move until the status goes away. For the nets, this is one
  iteration, though for future implementations, this is easily customizable.

6./The addition of a new Boss: the Naga.
  The Naga is a powerful serpentine entity that emerged from the Cove to protect the Emerald. She walks up and down the far-right side of the board. If she catches a Hero, she
  does not instantly kill them as she is fighting outside of waters, but she will inflict heavy damage. This will most likely kill those who have taken too much damage from
  just walking to the Cove. If the Naga is hit by a Wave, she is rejuvinated and is granted +10 strength. The Naga, like the Dragon, cannot be fought and must be evaded if they
  Heroes want to obtain the Emerald.
