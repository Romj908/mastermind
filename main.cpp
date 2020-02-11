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
#include "mmCodes.h"
#include "mmBoard.h"

using namespace std;
using namespace MMG;

#ifdef MMG_DISPL_LETTERS
void game_session(void)
{
    
}

#endif


/*
 * 
 */
int
main(int argc, char** argv)
{   
    int nb_colors = 8; 
    int code_lenght = 6;
    int turns = 8;
    
    GameBoard game_board {nb_colors, code_lenght, turns };
    
    game_board.display(true);
    game_board.set_new_secret_code();
    
    game_board.player_turns();
    
    
#ifdef MMG_DISPL_LETTERS
    
#endif    
     return 0;

}

