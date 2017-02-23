.PHONY : build save run all

build:
	g++-6 -O2 main.cpp info.cpp output.cpp sol_brute.cpp -o binary

run:
	./run.sh

save:
	mkdir -p backup
	zip backup/`date +%Y-%m-%d.%H:%M:%S`.zip *.cpp *.h

all: build run save
