CC=g++
CFLAGS= -Wall
LDFLAGS=
EXEC= opengl
SRC= core/Src/Scene.cpp main.cpp
HEADER= core/Include/Scene.h
OBJ= $(SRC:.cpp=.o)
OBJH= $(HEADER:.h=.o)

all: $(EXEC)


opengl: $(OBJH) $(OBJ)
	$(CC) $^ -o openGL -lsfml-graphics -lsfml-window -lsfml-system -lGL -lGLU $(LDFLAGS)

%.o: %.cpp
	$(CC) -c $^ $(CFLAGS)

