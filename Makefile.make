EXC = VladPackManGame
OBJS = Cookie.o VladPackManGame.o Board.o VectorBoardObjects.o Player.o Wall.o Monster.o Bomb.o
DBG=-g

VladPackManGame : $(OBJS)
	g++ $(DBG) $(OBJS) -o VladPackManGame

VladPackManGame.o : BoardH.h VladPackManGame.cpp
	g++ $(DBG) -c VladPackManGame.cpp -o VladPackManGame.o

Player.o : PlayerH.h BoardObjectH.h Player.cpp
	g++ $(DBG) -c Player.cpp -o Player.o

Wall.o : WallH.h BoardObjectH.h Wall.cpp
	g++ $(DBG) -c Wall.cpp -o Wall.o

Cookie.o : CookieH.h BoardObjectH.h Cookie.cpp
	g++ $(DBG) -c Cookie.cpp -o Cookie.o

Monster.o : Monster.h BoardObjectH.h Monster.cpp
	g++ $(DBG) -c Monster.cpp -o Monster.o

Bomb.o : Bomb.h BoardObjectH.h Bomb.cpp
	g++ $(DBG) -c Bomb.cpp -o Bomb.o

Board.o : BoardH.h Board.cpp BoardObjectH.h VectorBoardObjects.h PlayerH.h WallH.h CookieH.h Monster.h Bomb.h
	g++ $(DBG) -c Board.cpp -o Board.o

VectorBoardObjects.o : VectorBoardObjects.h BoardObjectH.h VectorBoardObjects.cpp PlayerH.h CookieH.h
	g++ $(DBG) -c VectorBoardObjects.cpp -o VectorBoardObjects.o

test: test_vector
	./test_vector

test_vector : test_vector.o VectorBoardObjects.o Player.o Wall.o Cookie.o Monster.o Bomb.o
	g++ $(DBG) test_vector.o VectorBoardObjects.o Player.o Wall.o Cookie.o Monster.o Bomb.o -o test_vector

test_vector.o : test_vector.cpp VectorBoardObjects.h PlayerH.h CookieH.h Monster.h Bomb.h
	g++ $(DBG) -c test_vector.cpp -o test_vector.o

clean :
	rm -f $(OBJS) test_vector.o test_vector VladPackManGame

doc:
	doxygen Doxyfile
