#include "PodcastPlayer.h"
#include <fstream>

using namespace std;

void AudioPlayer::play(const Episode* m, ostream& ost) const {
    ost << "Playing audio: " << m->getAudio() << endl;
}

void VideoPlayer::play(const Episode* m, ostream& ost) const {
    AudioPlayer::play(m, ost);
    ifstream videoFile(m->getVideoFile());
    if(!videoFile){
        ost << "Error! Can't not open file or it does not exist!" << endl;
        return;
    }
    string print_line;
    while(getline(videoFile, print_line)){
        ost << print_line << endl;
    }
    videoFile.close();
}
