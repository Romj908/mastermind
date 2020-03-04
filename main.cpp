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
#include "BoardComposerA.h"
#include "PenVersionGlyphes.h"
#include "PVGlyphFactory.h"

using namespace std;
using namespace MMG;;

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
    
    GameBoardPtr    game_board_ptr { &game_board };
    GlyphFactoryPtr pvgfactory { new PVGlyphFactory{} } ;
    
    BoardComposerAPtr board_composer {};
    board_composer.reset( new BoardComposerA {game_board_ptr, pvgfactory} );
    
    board_composer->build();
    
    Rect dummy_rect {0, 0, 1024, 758};
    board_composer->compose(dummy_rect);
    
    game_board_ptr->display(true);
    game_board_ptr->player_turns();
    
}


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

