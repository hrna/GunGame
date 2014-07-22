CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic-errors -std=c++0x
DEPS = game_engine.h players.h
OBJ = game_engine.o players.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

GunGame: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)
clean:
	rm *.o
	rm action
