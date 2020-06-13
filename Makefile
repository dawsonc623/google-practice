exercises : build-dir exercise.o can-balance.o map-share.o max-span.o string-splosion.o \
		sum-numbers-stream.o without-string-regex.o main.o
	g++ --std=c++17 build/exercise.o build/can-balance.o build/max-span.o build/map-share.o \
		build/string-splosion.o build/sum-numbers-stream.o build/without-string-regex.o build/main.o -o exercises

build-dir	:
	mkdir -p build

main.o : src/main.cpp include/exercise.hpp include/exercises/can-balance.hpp include/exercises/map-share.hpp \
		include/exercises/max-span.hpp include/exercises/string-splosion.hpp include/exercises/sum-numbers-stream.hpp \
		include/exercises/without-string-regex.hpp
	g++ -c --std=c++17 src/main.cpp -Iinclude -o build/main.o

exercise.o : src/exercise.cpp include/exercise.hpp
	g++ -c --std=c++17 src/exercise.cpp -Iinclude -o build/exercise.o

can-balance.o : src/exercises/can-balance.cpp include/exercise.hpp include/exercises/can-balance.hpp
	g++ -c --std=c++17 src/exercises/can-balance.cpp -Iinclude -o build/can-balance.o

map-share.o : src/exercises/map-share.cpp include/exercise.hpp include/exercises/map-share.hpp
	g++ -c --std=c++17 src/exercises/map-share.cpp -Iinclude -o build/map-share.o

max-span.o : src/exercises/max-span.cpp include/exercise.hpp include/exercises/max-span.hpp
	g++ -c --std=c++17 src/exercises/max-span.cpp -Iinclude -o build/max-span.o

string-splosion.o : src/exercises/string-splosion.cpp include/exercise.hpp include/exercises/string-splosion.hpp
	g++ -c --std=c++17 src/exercises/string-splosion.cpp -Iinclude -o build/string-splosion.o

sum-numbers-stream.o : src/exercises/sum-numbers-stream.cpp include/exercise.hpp include/exercises/sum-numbers-stream.hpp
	g++ -c --std=c++17 src/exercises/sum-numbers-stream.cpp -Iinclude -o build/sum-numbers-stream.o

without-string-regex.o : src/exercises/without-string-regex.cpp include/exercise.hpp include/exercises/without-string-regex.hpp
	g++ -c --std=c++17 src/exercises/without-string-regex.cpp -Iinclude -o build/without-string-regex.o

clean	:
	rm exercises
	rm -fr build
