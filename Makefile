CC = g++
CFLAGS = $(WARNINGS) $(DEBUG) $(DEFINE)
DEBUG = -g
#DEFINE = -DSTACK_TYPE=Oper -DLIST_TYPE=Oper -DLIST_FORMAT_STRING=""
WARNINGS = -ansi -pedantic -Wall -Wextra -D__USE_FIXED_PROTOTYPES__
OBJ = main.o BSTree2.o Show.o
#LIBS = -lncurses
APPLICATION_NAME = tvTree

.PHONY : all rebuild clean

all : $(APPLICATION_NAME)

rebuild :
	make clean
	make all

$(APPLICATION_NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(APPLICATION_NAME) $(LIBS)

main.o : main.cpp BSTree2.h Show.h
	$(CC) $(CFLAGS) -c main.cpp $(LIBS)

BSTree2.o : BSTree2.cpp BSTree2.h Show.h
	$(CC) $(CFLAGS) -c BSTree2.cpp $(LIBS)

Show.o : Show.cpp Show.h
	$(CC) $(CFLAGS) -c Show.cpp $(LIBS)

clean :
	rm -f $(APPLICATION_NAME) $(OBJ)
