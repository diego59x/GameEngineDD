all: 
	g++ -I dpd/include -L dpd/lib -o src/pongGame src/*.cpp -lmingw32 -lSDL2main -lSDL2