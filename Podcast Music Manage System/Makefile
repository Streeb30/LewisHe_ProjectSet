objects = main.o View.o Controller.o Podify.o Podcast.o Episode.o PodcastPlayer.o PodcastFactory.o Search.o
testobjects = test.o View.o TestControl.o Tester.o Podify.o Podcast.o Episode.o PodcastPlayer.o PodcastFactory.o Search.o

all: a4 test

a4: $(objects)
	g++ -o a4 $(objects)

main.o: main.cc Array.h
	g++ -c main.cc 

test: $(testobjects)
	g++ -o test $(testobjects)

test.o: test.cc Array.h
	g++ -c test.cc

Tester.o: Tester.cc Tester.h
	g++ -c Tester.cc

TestControl.o: TestControl.cc TestControl.h
	g++ -c TestControl.cc

View.o: View.h View.cc Array.h
	g++ -c View.cc

Controller.o: Controller.h Controller.cc Array.h
	g++ -c Controller.cc


Podify.o: Podify.h Podify.cc Array.h
	g++ -c Podify.cc


Podcast.o: Podcast.cc Podcast.h Array.h
	g++ -c Podcast.cc

Episode.o: Episode.cc Episode.h
	g++ -c Episode.cc
	
PodcastPlayer.o: PodcastPlayer.cc PodcastPlayer.h
	g++ -c PodcastPlayer.cc
	
PodcastFactory.o: PodcastFactory.cc PodcastFactory.h
	g++ -c PodcastFactory.cc

Search.o: Search.cc Search.h
	g++ -c Search.cc

clean:
	rm -f a4 *.o	