#include <iostream>
#include <vector>
#include "tsong.h"
using namespace std;

tsong::tsong()
{
    title = "0";
	mood_value = 0;
	focus_value = 0;
    play_count = 0;
}

tsong::tsong(std::string song_name, int mood, int focus, int count){
	title = song_name;
	mood_value = mood;
	focus_value = focus;
    play_count = count;
}

//===========getters==================
std::string tsong::getTitle(){
	return title; 
}

int tsong::getMood(){
	return mood_value;
}

int tsong::getFocus(){
	return focus_value;
}

int tsong::getCount(){
    return play_count;
}


//===========setters==================
void tsong::setTitle(std::string song_title){
	title = song_title;
}

void tsong::setMood(int mood){
	mood_value = mood;
}

void tsong::setFocus(int focus){
	focus_value = focus;
}

void tsong::setCount(int count){
    play_count = count;
}
