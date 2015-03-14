#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <Qstring>

#include "user.h"

user::user(){
    song_list.clear();
}

user::user(std::string CSV){

    /*std::vector of the csv file split by commas. Each std::vector element contains a std::vector representing
	one line in the CSV, which is then further split by commas. If the CSV is set up correctly, the inner 
    std::vector should only have 3 elements = song name, mood, focus*/

    std::vector <std::vector <std::string> > data;

    fileName = CSV;

    std::ifstream infile(CSV.c_str()); //read in CSV file

  	while (infile){
     std::string s;
   	 if (!getline( infile, s )) break;

       std::istringstream ss( s );
        std::vector <std::string> record;

        // each line
 	   	while (ss){
            std::string s;
      		if (!getline( ss, s, ',' )) break;
      		record.push_back( s );
    	}

    data.push_back( record );
  	}
  	//loop through three indices for a full tsong

    for(unsigned int i = 0; i < data.size(); i++){//iterating through all lines of CSV
        std::string name = data[i][0];
        int mood = QString::fromStdString(data[i][1]).toInt();
        int focus = QString::fromStdString(data[i][2]).toInt();
        int count = QString::fromStdString(data[i][3]).toInt();
        std::cout<<mood<<std::endl;

        tsong temp(name, mood, focus, count);
  		song_list.push_back(temp);//appending tsong to the list
  	}

}

user::~user(){
    writeToFile();
}

std::vector<tsong> user::load(){
	return song_list;
}

tsong * user::getSong(std::string song_name){
    for(unsigned int i = 0; i < song_list.size(); i++){
        if(song_name.compare(song_list[i].getTitle()) == 0){
            return &song_list[i];
        }
    }
    return NULL;
}

bool user::update(std::string song_name, int mood, int focus){
    for(unsigned int i = 0; i < song_list.size(); i++){
        if(song_name.compare(song_list[i].getTitle()) == 0){
            song_list[i].setMood(mood + song_list[i].getMood());
            song_list[i].setFocus(focus + song_list[i].getFocus());
            song_list[i].setCount(song_list[i].getCount());
            return true;
        }
    }
    return false;
}

void user::add(std::string song_name, int mood, int focus){

    if(update(song_name, mood, focus))
        return;

    tsong temp(song_name, mood, focus, 1);
  	song_list.push_back(temp);
}

void user::writeToFile(){

    std::ofstream outfile;
    outfile.open(fileName.c_str(), std::ofstream::out | std::ofstream::app); //write in CSV file

    for(unsigned int i = 0; i < song_list.size(); i++){
        outfile << song_list[i].getTitle() << ",";
        outfile << song_list[i].getMood() << ",";
        outfile << song_list[i].getFocus() << ",";
        outfile << song_list[i].getCount() << ",";
        outfile << "\n";
    }

    outfile.close();
}

std::string user::findSong(int mood, int wakefullness){
    for(unsigned int i = 0; i < song_list.size(); i++){
        if(song_list[i].getMood() < song_list[i].getMood() + 20
        && song_list[i].getMood() > song_list[i].getMood() - 20){
            if(song_list[i].getFocus() < song_list[i].getFocus() + 20
            && song_list[i].getFocus() > song_list[i].getFocus() - 20){
                return  song_list[i].getTitle();
            }
        }
    }
    return "Nothing";
}
