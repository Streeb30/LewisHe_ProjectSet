#include "Episode.h"

using namespace std;

Episode::Episode(const string& podcastTitle, const string& host,
                 const string& episodeTitle, const string& category,
                 const string& audio, const string& videoFile)
    : podcastTitle(podcastTitle), host(host), episodeTitle(episodeTitle),
      category(category), audio(audio), videoFile(videoFile) {}

string Episode::getPodcastTitle() const {
    return podcastTitle;
}

string Episode::getHost() const {
    return host;
}

string Episode::getEpisodeTitle() const {
    return episodeTitle;
}

string Episode::getCategory() const {
    return category;
}

string Episode::getAudio() const {
    return audio;
}

string Episode::getVideoFile() const {
    return videoFile;
}

void Episode::print(ostream& ost) const {
    ost << "Podcast: " << podcastTitle << ", Host: " << host
        << ", Category: " << category << ", Episode: " << episodeTitle;
}

ostream& operator<<(ostream& ost, const Episode& e) {
    e.print(ost);
    return ost;
}
