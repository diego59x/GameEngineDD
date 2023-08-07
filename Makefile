all: 
	g++ -I dpd/include -L dpd/lib -o src/pongGame src/*.cpp src/Game/*.cpp src/CustomObj/*.cpp src/Pong/*.cpp -lmingw32 -lSDL2main -lSDL2