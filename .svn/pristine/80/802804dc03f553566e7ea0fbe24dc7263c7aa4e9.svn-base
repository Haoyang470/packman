
EXC = VladPackManGame
OBJS = Cookie.o VladPackManGame.o Board.o ListBoardObjects.o Player.o Wall.o
DBG=-g

VladPackManGame : $(OBJS)
	g++ $(DBG)  $(OBJS) -o  VladPackManGame

VladPackManGame.o : BoardH.h VladPackManGame.cpp
	g++ $(DBG) -c VladPackManGame.cpp -o VladPackManGame.o 

Player.o : PlayerH.h BoardObjectH.h Player.cpp
	g++ $(DBG) -c Player.cpp -o Player.o 

Wall.o : WallH.h BoardObjectH.h Wall.cpp
	g++ $(DBG) -c Wall.cpp -o Wall.o 

Cookie.o : CookieH.h BoardObjectH.h Cookie.cpp
	g++ $(DBG) -c Cookie.cpp -o Cookie.o 

Board.o : BoardH.h Board.cpp BoardObjectH.h ListBoardObjectsH.h PlayerH.h WallH.h CookieH.h
	g++ $(DBG) -c Board.cpp -o Board.o 

ListBoardObjects.o : ListBoardObjectsH.h BoardObjectH.h ListBoardObjects.cpp PlayerH.h CookieH.h
	g++ $(DBG) -c ListBoardObjects.cpp -o ListBoardObjects.o 


clean :
	rm $(OBJS) VladPackManGame
