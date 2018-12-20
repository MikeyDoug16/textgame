game: game.o
	g++ -std=c++14 -Werror -Wextra game.o -o game
game.o: game.cpp game.h 
	g++ -c -std=c++14 -Werror -Wextra game.cpp 
clean: 
	rm *.o game
