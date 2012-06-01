.cpp.o:
	g++ -Wall -g -c -I./include/ -o $@ $<

play: src/main.o src/util.o libengine.a
	g++ -Wall -g -o play $^ -lGL -lGLEW -lglfw

libengine.a: src/Engine/Shader.o src/Engine/Program.o 
	$(AR) -csr $@ $^

clean:
	rm play src/*.o src/Engine/*.o

all: play
