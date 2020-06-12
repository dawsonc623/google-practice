exercises : build-dir exercise.o max-span.o string-splosion.o without-string-regex.o main.o
	g++ --std=c++17 build/exercise.o build/max-span.o build/string-splosion.o build/without-string-regex.o \
		build/main.o -o exercises

build-dir	:
	mkdir -p build

main.o : src/main.cpp include/exercise.hpp include/exercises/max-span.hpp include/exercises/string-splosion.hpp
	g++ -c --std=c++17 src/main.cpp -Iinclude -o build/main.o

exercise.o : src/exercise.cpp include/exercise.hpp
	g++ -c --std=c++17 src/exercise.cpp -Iinclude -o build/exercise.o

max-span.o : src/exercises/max-span.cpp include/exercise.hpp include/exercises/max-span.hpp
	g++ -c --std=c++17 src/exercises/max-span.cpp -Iinclude -o build/max-span.o

string-splosion.o : src/exercises/string-splosion.cpp include/exercise.hpp include/exercises/string-splosion.hpp
	g++ -c --std=c++17 src/exercises/string-splosion.cpp -Iinclude -o build/string-splosion.o

without-string-regex.o : src/exercises/without-string-regex.cpp include/exercise.hpp include/exercises/without-string-regex.hpp
	g++ -c --std=c++17 src/exercises/without-string-regex.cpp -Iinclude -o build/without-string-regex.o

clean	:
	rm exercises
	rm -fr build
