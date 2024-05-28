#include "Podcast.h"
#include "Episode.h"

using namespace std;

Podcast::Podcast(const string& title, const string& host)
    :title(title), host(host){}

Podcast::~Podcast() {
    for (int i = 0; i < episodes_array.getSize(); ++i) {
        delete episodes_array[i];
    }
}

bool Podcast::equals(const string& title) const{
    return this->title == title;
}

Episode* Podcast::get(int index) const{
    if(index < 0 || index >= episodes_array.getSize()){
        cout << "The index is out of bounds!!!" << endl;
        exit(1);
    }
    return episodes_array[index];
}

int Podcast::getSize() const{
    return episodes_array.getSize();
}

void Podcast::print(ostream& ost) const{
    ost << "The title: " << title << ", The host: " << host << endl;
}

void Podcast::printWithEpisodes(ostream& ost) const{
    print(ost);
    for(int i = 0; i < episodes_array.getSize(); i++){
        ost << "The Episode(" << i + 1 << "): ";
        episodes_array[i]->print(ost);
        ost << endl;
    }
}

void Podcast::add(Episode* episode){
    episodes_array += episode;
}

ostream& operator<<(ostream& ost, const Podcast& p){
    p.print(ost);
    return ost;
}
