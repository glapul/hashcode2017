.PHONY : build save run all

build:
	g++ -std=c++11 main.cpp -o binary

run:
	./run.sh

save:
	mkdir -p backup
	zip backup/`date +%Y-%m-%d.%H:%M:%S`.zip *.cpp *.h

all: build run save
