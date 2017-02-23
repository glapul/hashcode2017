.PHONY : build save run all

build:
	g++-6 main.cpp info.cpp -o binary

run:
	./run.sh

save:
	mkdir -p backup
	zip backup/`date +%Y-%m-%d.%H:%M:%S`.zip *.cpp *.h

all: build run save
