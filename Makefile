UNAME := $(shell uname)

FLAGS = -lpthread -lpcap -lm

ifeq ($(UNAME),Darwin)
	FLAGS += -framework GLUT -framework OpenGL
else
	FLAGS += -lGL -lGLU -lglut
endif

all:
	g++ main.cpp graphics.cpp net.cpp -o network $(FLAGS)

yum:
	sudo yum install -y libpcap libpcap-devel freeglut freeglut-devel

run:
	echo "LIBGL_ALWAYS_INDIRECT=1 ./network" | sudo bash

