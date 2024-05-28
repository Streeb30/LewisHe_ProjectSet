#ifndef PODIFY_H
#define PODIFY_H

#include <iostream>
#include <string>
#include "Podcast.h"
#include "Episode.h"
#include "Search.h"
#include "Array.h"

using namespace std;

class Podify{
    public:
        ~Podify();
        void addPodcast(Podcast* p);
        void addEpisode(Episode* e, const string& podcastTitle);
        const Array<Podcast*>& getPodcasts() const;
        Podcast* getPodcast(int index) const;
        Podcast* getPodcast(const string& title) const;
        void getEpisodes(Search* search, Array<Episode*>& array) const;
        void getEpisodes(Search& search, Array<Episode*>& array) const;

    private:
        Array<Podcast*> podcasts;
};
#endif