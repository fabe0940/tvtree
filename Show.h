#ifndef _SHOW_H_
#define _SHOW_H_

#include <string>

#define _SHOW_ARRAY_LEN 25

using namespace std;

class Show {
	private:
		int yearStart;
		int yearEnd;
		string title;
		string genre;
		string address;
		string actors[_SHOW_ARRAY_LEN];
	public:
		Show();
		~Show();
		void print(void);
		void setStartYear(int y);
		void setEndYear(int y);
		void setTitle(string t);
		void setGenre(string g);
		void setAddress(string a);
		void addActor(string a);
		int hasActor(string a);
		int getYearStart(void);
		int getYearEnd(void);
		string getTitle(void);
};

#endif
