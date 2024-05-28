#ifndef PODCASTPLAYER_H
#define PODCASTPLAYER_H

#include <iostream>
#include <string>
#include "Episode.h"

using namespace std;

class PodcastPlayer {
    public:
        virtual void play(const Episode* m, ostream& ost) const = 0;
        virtual ~PodcastPlayer() {};
};

class AudioPlayer : public PodcastPlayer {
    public:
        void play(const Episode* m, ostream& ost) const override;
};

class VideoPlayer : public AudioPlayer {
    public:
        void play(const Episode* m, ostream& ost) const override;
};
#endif