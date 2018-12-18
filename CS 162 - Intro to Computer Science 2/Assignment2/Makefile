CC = g++
exe_file = assign2	
$(exe_file): card.o deck.o hand.o player.o dealer.o game.o driver.o
	$(CC) card.o deck.o hand.o player.o dealer.o game.o driver.o -o $(exe_file)
card.o: card.cpp
	$(CC) -c card.cpp
deck.o: deck.cpp
	$(CC) -c deck.cpp
hand.o: hand.cpp
	$(CC) -c hand.cpp
player.o: player.cpp
	$(CC) -c player.cpp
dealer.o: dealer.cpp
	$(CC) -c dealer.cpp
game.o: game.cpp
	$(CC) -c game.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp

clean:
	rm -f a.out $(exe) *.o