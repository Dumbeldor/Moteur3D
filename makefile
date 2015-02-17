CC=g++
CFLAGS= -Wall
LDFLAGS=
EXEC= opengl
SRC= Scene.cpp main.cpp
HEADER= Scene.h
OBJ= $(SRC:.cpp=.o)
OBJH= $(HEADER:.h=.o)

all: $(EXEC)


opengl: $(OBJH) $(OBJ)
	$(CC) $^ -o openGL -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLU $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $^ $(CFLAGS)

