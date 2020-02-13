/*
 * Copyright (C) 2020 EngIT
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* 
 * File:   main.cpp
 * Author: jerome
 *
 * Created on February 6, 2020, 11:06 AM
 */

#include <cstdlib>
#include <exception>
#include "mmCodes.h"
//#include "mmBoard.h"
#include "ConsoleGameBoard.h"
using namespace std;
using namespace MMG;

class MyException : public exception
{
public:
    const char* what() const noexcept {return "TOTO!!";};
};

void game_session(void)
{
    int nb_colors = 6; 
    int code_lenght = 5;
    int turns = 8;
    
    
    ConsoleGameBoard game_board {nb_colors, code_lenght, turns };
    
    game_board.display(true);
    game_board.player_turns();
    
}

#ifdef MMG_DISPL_LETTERS
#endif


/*
 * 
 */
int
main(int argc, char** argv)
{   
    try
    {
        while (1)
        {
            game_session();
        }
    }
    catch(MyException me)
    {
        cout << "My exception catch : " << me.what();
    }
    catch (std::exception& e)
    {
        // some of the STD facilities may trow an exception of that base class.
        cout << "STL exception catch : " << e.what();
    }
    
#ifdef MMG_DISPL_LETTERS
    
#endif    
     return 0;

}

