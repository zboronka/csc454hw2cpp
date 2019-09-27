CC=g++
FLAGS=-g -std=c++11
SOURCE=*.cpp
TARGET=-o main
LIBS=
all:
	$(CC) $(FLAGS) $(SOURCE) $(TARGET) $(LIBS)
