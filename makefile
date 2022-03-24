OBJS = ./src/*.cpp

HEADERS =  -I./src/headers
OBJ_NAME = ./debug/test
FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_Image -lSDL2_Ttf -lSDL2_mixer -Wno-unused-variable

all : $(OBJS)
	g++ $(OBJS) $(INCLUDE) $(HEADERS) $(LIBRARY) $(FLAGS) -o $(OBJ_NAME)
