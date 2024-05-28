#include "Podify.h"

using namespace std;

Podify::~Podify() {
    for (int i = 0; i < podcasts.getSize(); ++i) {
        delete podcasts[i];
    }
}

void Podify::addPodcast(Podcast* p){
    podcasts += p;
}

void Podify::addEpisode(Episode* e, const string& podcastTitle){
    for(int i = 0; i < podcasts.getSize(); i++){
        if(podcasts[i]->equals(podcastTitle)){
            podcasts[i]->add(e);
            return;
        }
    }
    cout << "Error!!! Not find the provided podcast title in array!" << endl;
}

const Array<Podcast*>& Podify::getPodcasts() const{
    return podcasts;
}

Podcast* Podify::getPodcast(int index) const{
    if(index < 0 || index >= podcasts.getSize()){
        cout << "Error! Index out of bounds!" << endl;
        exit(1);
    }
    return podcasts[index];
}

Podcast* Podify::getPodcast(const string& title) const{
    for(int i = 0; i < podcasts.getSize(); i++){
        if(podcasts[i]->equals(title)){
            return podcasts[i];
        }
    }
    cout << "Error!!! Not find the provided title in podcasts array!" << endl;
    exit(1);
}

void Podify::getEpisodes(Search* search, Array<Episode*>& array) const{
    for(int i = 0; i < podcasts.getSize(); i++){
        Podcast* search_podcast = podcasts[i];
        for(int j = 0; j < search_podcast->getSize(); j++){
            Episode* search_episode = search_podcast->get(j);
            if(search->matches(search_episode)){
                array += search_episode;
            }
        }
    }
}

void Podify::getEpisodes(Search& search, Array<Episode*>& array) const{
    getEpisodes(&search, array);
}