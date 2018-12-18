CC = g++
exe_file = assign3	
$(exe_file): animal.o driver.o p_bear.o penguin.o tiger.o monkey.o zoo.o
	$(CC) animal.o driver.o p_bear.o penguin.o tiger.o monkey.o zoo.o -o $(exe_file)
animal.o: animal.cpp
	$(CC) -c animal.cpp
driver.o: driver.cpp
	$(CC) -c driver.cpp
p_bear.o: p_bear.cpp
	$(CC) -c p_bear.cpp
penguin.o: penguin.cpp
	$(CC) -c penguin.cpp
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp
monkey.o: monkey.cpp
	$(CC) -c monkey.cpp
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
clean:
	rm -f a.out $(exe) *.o