#ifndef TSONG_H
#define TSONG_H
class tSong{ 			//basic song class 
	public:
		tsong(); //default constructor
		tsong(string song_name, int mood, int focus); 

		string getTitle();
		void setTitle(string song_title);	

		int getMood();
		void setMood(int mood);

		int getFocus();
		void setFocus(int focus);
	private:
		string title;
		int mood_value; //0(sad)->100(happy)
		int focus_value 
};

#endif