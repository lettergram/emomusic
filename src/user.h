#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>
#include "tsong.h"

class user{ 
	public:
        user();                                                   //default constructor
        user(std::string CSV);                                    //constructor, one input song name
        ~user();                                                  //default deconstructor
        std::vector<tsong> load();                                //load the list of songs (vector)

        tsong * getSong(std::string song_name);                   //gets song
        std::string findSong(int mood, int wakefullness);         //finds a song in the csv based on our parameters (+/- 20%
        void add(std::string song_name, int mood, int focus);     //append a tsong to song_list
        bool update(std::string song_name, int mood, int focus);  //updates song name, returns true if successful
	private:
        std::vector<tsong> song_list;
        std::string fileName;
        void writeToFile();
};
#endif 
