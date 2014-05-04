CC = g++
FILES = main.cpp util.cpp
OPTIONS = -Wall

all: build cleanafter

build:
	$(CC) $(FILES) -o main $(OPTIONS)

cleanafter:
	rm -rf *.o
	rm -rf *~  # Remove temporary files from gedit

clean: cleanafter
	rm -f main

clear:
	rm -f main
