OBJS = src/main.cpp src/window.cpp src/entity.cpp src/event.cpp src/creature.cpp src/resource.cpp

CC = g++

COMPILER_FLAGS = -w

LINKER_FLAGS = -lSDL2 -lSDL2_image

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o nature
