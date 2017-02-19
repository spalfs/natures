OBJS = src/*cpp
DEPS = inc/

CC = g++ 

COMPILER_FLAGS = -w -I$(DEPS)

LINKER_FLAGS = -g -lm -lGL -lGLEW -lSDL2 -std=c++11

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o exec
