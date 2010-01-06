OBJECTS = process

all: $(OBJECTS)

clean:
	rm -f $(OBJECTS)

process: process.c
	$(CXX) $^ -o $@ `pkg-config --cflags --libs opencv`

