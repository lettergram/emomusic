#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "user.h"

user::user()
{
    song_list.clear();
}

user::user(std::string CSV)
{
	/*vector of the csv file split by commas. Each vector element contains a vector representing
	one line in the CSV, which is then further split by commas. If the CSV is set up correctly, the inner 
	vector should only have 3 elements = song name, mood, focus*/
	vector <vector <string> > data; 

<<<<<<< HEAD
    ifstream infile(CSV); //read in CSV file
=======
    std::ifstream infile(CSV.c_str()); //read in CSV file
>>>>>>> 22754309db1245b05cd324510a2924759d795511

  	while (infile)
  	{
   	 string s;
   	 if (!getline( infile, s )) break;

 	   std::istringstream ss( s );
    	std::vector <string> record;

 	   	while (ss)
   	 	{
     		string s;
      		if (!getline( ss, s, ',' )) break;
      		record.push_back( s );
    	}

    data.push_back( record );
  	}
  	//loop through three indices for a full tsong
<<<<<<< HEAD
    for(vector<vector<std::string>>::iterator it1 = data.begin; it1 != data.end(); ++it){//iterating through all lines of CSV
        std::string name = *it[0];
  		int mood = *it[1];
  		int focus = *it[2];
=======
    for(int i = 0; i < data.size(); i++){//iterating through all lines of CSV
        std::string name = data[i][0];
  		int mood = std::stoi(data[i][1]);
  		int focus = std::stoi(data[i][2]);
      std::cout<<mood<<endl;
>>>>>>> 22754309db1245b05cd324510a2924759d795511

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


