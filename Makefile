.cpp.o:
	g++ -Wall -g -c -I./include/ -o $@ $<

play: src/main.o src/util.o src/IntroScene.o libengine.a
	g++ -Wall -g -o play $^ -lGL -lGLEW -lglfw -lrt

libengine.a: src/Engine/Shader.o src/Engine/Program.o src/Engine/Timer.o src/Engine/Scene.o
	$(AR) -csr $@ $^

clean:
	rm play src/*.o src/Engine/*.o

all: play
