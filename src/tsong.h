#ifndef TSONG_H
#define TSONG_H
<<<<<<< HEAD
=======
#include <string>
>>>>>>> 22754309db1245b05cd324510a2924759d795511
class tsong{ 			//basic song class
	public:
        tsong(); //default constructor
        tsong(std::string song_name, int mood, int focus);

        std::string getTitle();
        void setTitle(std::string song_title);

		int getMood();
        void setMood(int msood);

		int getFocus();
		void setFocus(int focus);
	private:
        std::string title;
		int mood_value; //0(sad)->100(happy)
        int focus_value;
};

#endif
