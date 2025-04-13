#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include <vector>
#include "Podcast.h"
#include "PodcastPlayer.h"

using namespace std;

class View {
		
	public:
		//constructors
		View();
		void menu(vector<string>&, int& choice);
		void printAllPodcasts(const Array<Podcast*>& podcasts);
		void podcastMenu( const Array<Podcast*>& podcasts, int& choice);
		void printPodcast(const Podcast*);
		// void episodeMenu(Podcast&, int& choice);
        void promptHost(string& host);
		void promptCategory(string& category);
		void printPlaylist(Array<Episode*>&);
		void playPlaylist(Array<Episode*>&);

		void promptVideo();
		void toggleVideo(bool);

	private:
		PodcastPlayer* player;
		// AudioPlayer audio_player;
		// VideoPlayer video_player;
};
#endif