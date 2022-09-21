.PHONY: all, clean, rebuild, extra

CC = g++
CFLAGS = -c
GLFLAGS = -lglut -lGL -lGLU

BUILD_PATH = ../build/
SOURCES =  lab2_primitives.cpp
OBJECTS = $(SOURCES:.cpp=.o)

SOURCES_EXTRA = lab2_extra_task.cpp
OBJECTS_EXTRA = $(SOURCES_EXTRA:.cpp=.o)

EXECUTABLE = MAIN

all: $(OBJECTS)
	$(CC) $(BUILD_PATH)$(OBJECTS) -o $(BUILD_PATH)$(EXECUTABLE) $(GLFLAGS)
extra: $(OBJECTS_EXTRA)
	$(CC) $(BUILD_PATH)$(OBJECTS_EXTRA) -o $(BUILD_PATH)$(EXECUTABLE) $(GLFLAGS)
	$(BUILD_PATH)$(EXECUTABLE)


rebuild: clean all

rebuild_extra: clean extra

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $(BUILD_PATH)$@

clean:
	-rm  $(BUILD_PATH)*
