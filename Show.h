#ifndef _SHOW_H_
#define _SHOW_H_

#include <string>
#include "StringList.h"

using namespace std;

class Show {
	private:
		int yearStart;
		int yearEnd;
		string title;
		string genre;
		string address;
		StringList actors;
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
};

#endif
