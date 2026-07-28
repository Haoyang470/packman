#include <iostream>
#include "BoardObjectH.h"
#include "ListBoardObjectsH.h"

ListBoardObjects:: ListBoardObjects(p_BoardObject newOne):list()
	{
	 	std::vector <p_BoardObject>:: iterator it;
	 	it=list.begin();
	 	list.insert(it,newOne);
        }

p_BoardObject ListBoardObjects:: theFirst()
	{
	   if (0 < list.size()  ) 
		{ internalIterator=list.begin();
	   	  return (*internalIterator);
		}
	   else
		return NULL;
	}


void ListBoardObjects:: addOne(p_BoardObject newOne)
	 { 
	 	std::vector <p_BoardObject>:: iterator it;
	 	it=list.begin();
	 	list.insert(it,newOne);
	 }

p_BoardObject ListBoardObjects :: theNext()
	{ 
	   internalIterator++;
	   if (internalIterator < list.end())
	   {
		   return (*internalIterator);
	   }
	   else
		return NULL;
	}

void ListBoardObjects :: removeOnePlayer()
	{
	   std::vector <p_BoardObject>:: iterator it;
	   it=list.begin();
	   while (it<list.end())
		{ if (A_PLAYER==(*it)->get_Type())
		   { list.erase(it); return;}
                  it++;
		}

	   return ;
	}


bool ListBoardObjects :: isThereAWall()
	{
	   std::vector <p_BoardObject>:: iterator it;
	   it=list.begin();
	   while (it<list.end())
		{ if (A_WALL==(*it)->get_Type())
		   {  return true;}
                  it++;
		}

	   return false ;
	}


int ListBoardObjects :: isCookieValue()
	{   int temp=0;
	   std::vector <p_BoardObject>:: iterator it;
	   it=list.begin();
	   while (it<list.end())
		{ if (A_COOKIE==(*it)->get_Type())
		   { temp= ((Cookie *)(*it))->get_value();
		     list.erase(it); 
		     return temp;
                   }
                  it++;
		}

	   return temp ;
	}
