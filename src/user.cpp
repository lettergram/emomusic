#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "user.h"

user::user()
{
	song_list = NULL;
}

user::user(string CSV)
{
	/*vector of the csv file split by commas. Each vector element contains a vector representing
	one line in the CSV, which is then further split by commas. If the CSV is set up correctly, the inner 
	vector should only have 3 elements = song name, mood, focus*/
	vector <vector <string> > data; 

	ifstream infile(CSV); //read in CSV file

  	while (infile)
  	{
   	 string s;
   	 if (!getline( infile, s )) break;

 	   istringstream ss( s );
    	vector <string> record;

 	   	while (ss)
   	 	{
     		string s;
      		if (!getline( ss, s, ',' )) break;
      		record.push_back( s );
    	}

    data.push_back( record );
  	}
  	//loop through three indices for a full tsong
  	for(vector<vector<string>>::iterator it1 = data.begin; it1 != data.end(); ++it){//iterating through all lines of CSV
  		string name = *it[0];
  		int mood = *it[1];
  		int focus = *it[2];

  		tsong temp(name, mood, focus);
  		song_list.push_back(temp);//appending tsong to the list
  	}

}

vector<tsong> user::load()
{
	return song_list;
}

void user::add(string song_name, int mood, int focus)
{
	tsong temp(song_name, mood, focus);
  	song_list.push_back(temp);
}


