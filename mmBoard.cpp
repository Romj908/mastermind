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
    auto& the_str = *up_str;
    
    ColorCode& ccode  = *up_secret_code;
    ccode.update(the_str);
    //cout << "\nSecret:" << ccode;
    // scroll down to hide the secret code...
    for (int line = 0; line<100; line++)
        cout << endl;
    return 0;
}

bool 
GameBoard::try_this_code(const ColorCode& candidate, Verdict& verdict)
{
    auto &indicators = verdict.theVect();
    
    ColorCode target{*up_secret_code};  // modifiable copy of the secret code.
    ColorCode candid{candidate};        // modifiable copy of the candidate.
    int index = 0;
    
    // 1) determine how many colors have been found at the correct place.
    for (int i=0; i< ColorCode::lenght(); i++)
    {
        if (target[i] == candid[i])
        {
            indicators[index++] = Indic::Black;
            // do now consider these elements any more
            target[i] = Color::None; 
            candid[i] = Color::None;
        }
    }
    if (index == ColorCode::lenght())
        return true; // all colors are correct!
    
    // 2) determine how many colors have been found at the wrong place.
    for (int i=0; i< ColorCode::lenght(); i++)
    {
        if (candid[i] != Color::None)
        {
            for (int j=0; j< ColorCode::lenght(); j++)
            {
                if (target[j] != Color::None)
                {
                    if (target[j] == candid[i])
                    {
                        indicators[index++] = Indic::White;
                        // do now consider these elements any more
                        candid[i] = Color::None;
                        target[j] = Color::None; 
                    }
                }
            }
        }
    }
    
    return false;
}
bool GameBoard::player_turn(int t)
{
    cout << endl << "Please enter your candidate code" << endl;
    print_allowed_colors();
    unique_ptr<string> up_str {read_code_string()};
    string &the_str = *up_str; // dereferencing the unique_ptr
    auto& ccodes = *up_codes; // dereferencing the unique_ptr
    ColorCode& ccode = ccodes[t];  // retrieving the color code for that turn
    ccode.update(the_str);

    auto& verdicts = *up_verdicts; // dereferencing the unique_ptr
    Verdict& verdict = verdicts[t];  // retrieving the color code for that turn
    return try_this_code(ccode, verdict);
    
}

int GameBoard::player_turns(void)
{
    auto& codes = *up_codes;
    auto& verdicts = *up_verdicts;
    
    for (int t = 0; t < nb_turns; t++)
    {
        this->display(false);
        bool success = player_turn(t);
        if (success)
        {
            cout << endl << "You won! :)" << endl;
            return true;
        }
    }
    cout << endl << "You have lost, sorry."<< endl;
    return false;
}