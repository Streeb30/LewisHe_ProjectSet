#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include "Array.h"

using namespace std;

class Episode;

class Podcast{
    public:
        Podcast(const string& title, const string& host);
        ~Podcast();
        bool equals(const string& title) const;
        Episode* get(int index) const;
        int getSize() const;
        void print(ostream& ost) const;
        void printWithEpisodes(ostream& ost) const;
        void add(Episode* episode);
        friend ostream& operator<<(ostream& ost, const Podcast& p);

    private:
        Array<Episode*> episodes_array;
        string title;
        string host;
};
#endif