#ifndef PODCASTFACTORY_H
#define PODCASTFACTORY_H

#include <iostream>
#include <string>
#include "Podcast.h"
#include "Search.h"
#include "Episode.h"

using namespace std;

class PodcastFactory {
		
	public:

		// create an Episode
		Episode* createEpisode(const string& pod, const string& host, const string& title);

		// create a Podcast
		Podcast* createPodcast(const string& title, const string& host);

		// create a Search
		Search* hostSearch(const string& host);
		Search* categorySearch(const string& category);
		Search* hostCatSearch(const string& artist, const string& category);

	
};
#endif