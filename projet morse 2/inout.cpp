#include <fstream>
#include <iostream>
#include <string>
#include "wavfile.h"
#include <cmath>
using namespace std;

const int NUM_SAMPLES = (WAVFILE_SAMPLES_PER_SECOND);

string getchemin(string chemin){
    string mess;
    fstream txt;
    txt.open(chemin,ios::in);
    if (txt.is_open()){
        string st;
        while(getline(txt, st)){  
            mess+=st;   
            mess+='\n';
      }
    }
    else{
        throw "Pas de fichier au chemin specifié";
    }
    txt.close();
    return mess;
}


void writechemin(string morse){
    fstream txt;
    txt.open("morse.txt",ios::out);
    if (txt.is_open()){
        txt << morse << endl;
    }
    else{
        throw "Pas de fichier au chemin specifié";
    }
    txt.close();
    return;
}

string getwav(string chemin){
    fstream audio;
    string morse;
    audio.open(chemin, ios::in);
    if (audio.is_open()){

    }
    else{
        throw "Pas de fichier au chemin specifié";
    }
    audio.close();
    return morse;
}

void createwav(string morse){
	double frequency = 800.0;
	int volume = 32000;
	int length = NUM_SAMPLES/5;

    short point[2*NUM_SAMPLES];
    short tiret[4*NUM_SAMPLES];
    short espace[5*NUM_SAMPLES];
    
    for(int i=0;i<2*length;++i) {
		double t = (double) i / WAVFILE_SAMPLES_PER_SECOND;
		if (i < length) {
            point[i] = volume*sin(frequency*t*2*M_PI);
        }
        else{
            point [i]=0;
        }
    }
    for(int i=0;i<4*length;++i) {
		double t = (double) i / WAVFILE_SAMPLES_PER_SECOND;
        if (i < 3*length) {
            tiret[i] = volume*sin(frequency*t*2*M_PI);
        }
        else{
            tiret[i]=0;
        }    
    }
    for(int i=0;i<5*length;++i) {
		espace[i]=0;
    }
    
    FILE * f = wavfile_open("morse.wav");
    if(!f) {
		throw ("Impossible de créer un fichier wav");
		return;
	}

    for (char c : morse ){
        switch (c){
            case '.' :
                wavfile_write(f, point,2*length);
                break;
            case '-' :
                wavfile_write(f, tiret,4*length);
                break;
            case ' ' :
                wavfile_write(f, espace,5*length);
                break;
        }
    }
	wavfile_close(f);
    return;
}