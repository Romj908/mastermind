/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   GameBoard.cpp
 * Author: jerome
 * 
 * Created on February 6, 2020, 3:17 PM
 */

#include "mmBoard.h"

using namespace MMG;

int GameBoard::nb_instances = 0;
int GameBoard::nb_turns = 0;


void GameBoard::display(bool secret_code)
{
    const auto& codes = *up_codes;
    const auto& verdicts = *up_verdicts;
    
    cout << endl;
    
    for (int t = 0; t < nb_turns; t++)
    {
        cout << t << "  " << codes[t] << "  " << verdicts[t] << endl;
    }
    if (secret_code)
    {
        auto &scode = *up_secret_code;
        cout << "\n\nS  ";
        cout << scode << endl;
    }
    
}

int  GameBoard::set_new_secret_code(void)
{
    cout << endl << "Please enter the new secret code" << endl;
    unique_ptr<string> up_str {MMG::read_code_string()};
    cout << " after read_code_string" << endl;
    auto& the_str = *up_str;
    
    ColorCode& ccode  = *up_secret_code;
    ccode.update(the_str);
    cout << "\n secret:" << ccode;
    return 0;
}

int GameBoard::player_turn(int t)
{
    cout << endl << "Please enter your candidate code" << endl;
    unique_ptr<string> up_str {read_code_string()};
    string &the_str = *up_str; // dereferencing the unique_ptr
    auto& ccode_vect = *up_codes; // dereferencing the unique_ptr
    ColorCode& ccode = ccode_vect[t];  // retrieving the color code for that turn
    ccode.update(the_str);
    
    return 0;
}

int GameBoard::player_turns(void)
{
    auto& codes = *up_codes;
    auto& verdicts = *up_verdicts;
    
    for (int t = 0; t < nb_turns; t++)
    {
        this->display(false);
        this->player_turn(t);
    }
    return 0;
}