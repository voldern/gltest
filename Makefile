.cpp.o:
	g++ -Wall -g -c -I./include/ -o $@ $<

play: src/main.o src/Engine/Shader.o src/Engine/Program.o src/util.o 
	g++ -Wall -g -o play $^ -lGL -lGLEW -lglfw

clean:
	rm play src/*.o src/Engine/*.o

all: play
