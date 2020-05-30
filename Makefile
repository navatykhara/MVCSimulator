a5: main.o Control.o View.o Hero.o QuestPlayer.o Dragon.o Fighter.o Naga.o Wave.o Fishmen.o Net.o
	g++ -o a5 main.o Control.o View.o Hero.o QuestPlayer.o Dragon.o Fighter.o Naga.o Wave.o Fishmen.o Net.o

Control.o: Control.cc Control.h QuestPlayer.h View.h Hero.h Fighter.h Naga.h Fishmen.h
	g++ -c Control.cc

main.o: main.cc Control.h
	g++ -c main.cc

View.o: View.cc View.h QuestPlayer.h Dungeon.h
	g++ -c View.cc

Hero.o: Hero.cc Hero.h QuestPlayer.h
	g++ -c Hero.cc

QuestPlayer.o: QuestPlayer.cc QuestPlayer.h
	g++ -c QuestPlayer.cc

Dragon.o: Dragon.cc Dragon.h QuestPlayer.h
	g++ -c Dragon.cc

Fighter.o: Fighter.cc Fighter.h
	g++ -c Fighter.cc

Naga.o: Naga.cc Naga.h QuestPlayer.h
	g++ -c Naga.cc

Wave.o: Wave.cc Wave.h QuestPlayer.h
	g++ -c Wave.cc

Fishmen.o: Fishmen.cc Fishmen.h QuestPlayer.h
	g++ -c Fishmen.cc

Net.o: Net.cc Net.h QuestPlayer.h
	g++ -c Net.cc
	
clean:
	rm -f *.o a5
