.cpp.o:
	g++ -Wall -g -c -I./include/ -o $@ $<

play: src/main.o src/Shader.o src/Program.o src/util.o 
	g++ -Wall -g -o play $^ -lGL -lGLEW -lglfw -lGLU

clean:
	rm play src/*.o

all: play
