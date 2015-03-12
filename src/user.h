#ifndef USER_H
#define USER_H
#include <iostream>
#include <vector>
#include <fstream>
#include "tsong.h"
using namespace std;

class user{ 
	public:
		user(); 				//default constructor
		user(string CSV); //constructor, one input song name
		vector<tSong> load();   //load the list of songs (vector)
		void add(string song_name, int mood, int focus); //append a tsong to song_list
	private:
		vector<tSong> song_list;		
};
#endif 