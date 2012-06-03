INCLUDES = -I./include/ 
LIBS = -lGL -lGLEW -lglfw
LIBS_DIR = 

ifdef OSX
INCLUDES += -I/opt/local/include
LIBS = -framework Cocoa -framework OpenGL -lglfw -lGLEW
LIBS_DIR = -L/opt/local/lib
endif

.cpp.o:
	g++ -Wall -g -c $(INCLUDES) -o $@ $<

play: src/main.o src/util.o src/IntroScene.o libengine.a
	g++ -Wall -g -o play $^ $(LIBS_DIR) $(LIBS)

libengine.a: src/Engine/Shader.o src/Engine/Program.o src/Engine/Timer.o src/Engine/Scene.o
	$(AR) -csr $@ $^

clean:
	rm play src/*.o src/Engine/*.o

all: play
