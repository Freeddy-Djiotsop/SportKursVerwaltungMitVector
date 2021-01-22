#Freeddy Djiotsop

clean: run
	rm -rf *.o
run: container
	./container

container: main.o sportkurs.o person.o
	g++ -Wall -std=c++11 main.o sportkurs.o person.o -o container

main.o: main.cpp
	g++ -Wall -std=c++11 -c main.cpp

sportkurs.o: sportkurs.cpp sportkurs.hpp
	g++ -Wall -std=c++11 -c sportkurs.cpp

person.o: person.cpp person.hpp
	g++ -Wall -std=c++11 -c person.cpp