OBJS = src/*.cpp
DEPS = inc/

CC = g++

COMPILER_FLAGS = -w -I$(DEPS)

LINKER_FLAGS = -lSDL2 -lSDL2_image

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o nature
