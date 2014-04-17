#ifndef _STRINGLIST_H_
#define _STRINGLIST_H_

#include <string.h>

using namespace std;

struct _stringListNode {
	string str;
	struct _stringListNode* next;
};
typedef struct _stringListNode StringListNode;
typedef StringListNode* StringListNodePtr;

class StringList {
	private:
		StringListNodePtr head;
		int length;
	public:
		StringList(void);
		~StringList(void);
		void print(void);
		void add(string s);
};

#endif
