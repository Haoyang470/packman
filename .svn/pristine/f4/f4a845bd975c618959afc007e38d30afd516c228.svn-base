#include <iostream>

#include "BoardObjectH.h"
#include "PlayerH.h"

void Player :: touch ()
		{ switch (status)
		  { case ALIVE : if (color1==get_Color() )
			            set_color(color2);
			          else
			             set_color(color1);
                                   break;
		    case  DEAD :
			             set_color(YELLOW);
		  }
		//std::cerr << " Player Object touched\n";
		}
