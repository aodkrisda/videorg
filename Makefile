OBJECTS = process tutorial

all: $(OBJECTS)

clean:
	rm -f $(OBJECTS)

process: process.c
	$(CXX) $^ -o $@ `pkg-config --cflags --libs opencv`

tutorial: tutorial.c
	$(CXX) $^ -o $@ `pkg-config --cflags --libs opencv`
