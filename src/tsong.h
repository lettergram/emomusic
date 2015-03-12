#ifndef TSONG_H
#define TSONG_H
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
