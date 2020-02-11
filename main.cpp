/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
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

