.PHONY : build save run all

build:
	g++-6 -O2 main.cpp info.cpp output.cpp sol_brute.cpp glapa.cpp -o binary

run:
	./run.sh

save:
	mkdir -p backup
	mkdir -p outputs
	zip outputs/recent_source.zip  *.cpp *.h
	cp outputs/recent_source.zip backup/`date +%Y-%m-%d.%H:%M:%S`.zip

all: build run save
