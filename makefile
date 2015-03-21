all: game

game: game.cpp Room.cpp PlainRoom.cpp SubmergedRoom.cpp DarkRoom.cpp GuardedRoom.cpp Outside.cpp Form.cpp Human.cpp Otter.cpp Magpie.cpp Orangutan.cpp SlowLoris.cpp WolfSpider.cpp Player.cpp Item.cpp
	g++ -std=c++0x game.cpp Room.cpp PlainRoom.cpp SubmergedRoom.cpp DarkRoom.cpp GuardedRoom.cpp Outside.cpp Form.cpp Human.cpp Otter.cpp Magpie.cpp Orangutan.cpp SlowLoris.cpp WolfSpider.cpp Player.cpp Item.cpp -o game

clean:
	rm -f *.o