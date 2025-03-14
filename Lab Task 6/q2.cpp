#include<iostream>
#include<vector>
using namespace std;
class MediaFile{
    string path;
    int size;
    public:
    MediaFile(){}
    MediaFile(string p,int s):path(p),size(s){}
    void play(){
        cout<<"\n Media File is playing";
    }
    void stop(){
        cout<<"\n Media File Stopped";
    }
};
class VisualFile:virtual public MediaFile{
    string resolution;
    public:
    VisualFile(string p,int s,string r):resolution(r),MediaFile(p,s){}
};
class AudioMedia:virtual public MediaFile{
    int sampleRate;
    public:
    AudioMedia(string p,int s,int sample):sampleRate(sample),MediaFile(p,s){}
};
class VideoMedia:public AudioMedia,public VisualFile{
    public:
    VideoMedia(string p,int s,string r,int sample):AudioMedia(p,s,sample),VisualFile(p,s,r){}
};
int main(){
    MediaFile m("local disk c",24);
    VisualFile v("local disk c",24,"4k");
    AudioMedia a("local disk c",24,5);
    VideoMedia vid("local disk c",24,"4k",5);
    vid.play();
}