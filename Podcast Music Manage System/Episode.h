#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>

using namespace std;

class Episode {
private:
    string podcastTitle, host, episodeTitle, category, audio, videoFile;
public:
    Episode(const string& podcastTitle, const string& host,
            const string& episodeTitle, const string& category,
            const string& audio, const string& videoFile);
   
    string getPodcastTitle() const;
    string getHost() const;
    string getEpisodeTitle() const;
    string getCategory() const;
    string getAudio() const;
    string getVideoFile() const;

    void print(ostream& ost) const;
    friend ostream& operator<<(ostream& ost, const Episode& e);
};
#endif