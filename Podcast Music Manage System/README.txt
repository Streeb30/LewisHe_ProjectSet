List of files:
Array.h
Controller.cc
Controller.h
defs.h
main.cc
Podcast.cc
Podcast.h
PodcastFactory.cc
PodcastFactory.h
PodcastPlayer.cc
PodcastPlayer.h
Podify.cc
Podify.h
Search.cc
Search.h
test.cc
TestControl.cc
TestControl.h
Tester.cc
Tester.h
View.cc
View.h
classa2.py

Execution instructions:
First you need direct to the file called assignment4 in your terminal,
and make sure you had download C++, then enter "make" in the terminal,
you will see the Makefile makes executable files for every class, and 
then you can enter "./test" in the terminal, this is call the test class
executable file, after that you can see a menu lists different options to 
test the program functionality, also you can press 7 to get marks, or enter 
0 to exit the program.


Additonal details:
I add a function called getEpisodes in Podify, it different with the original one,
this getEpisodes function take a reference to Search, it call the existing getEpisodes
by passing the address of search
