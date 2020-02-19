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

#include <chrono>     // take random seed from current system time.
#include <random>
#include <functional> // for std::bind()

#include "mmBoard.h"

using namespace MMG;

int GameBoard::nb_instances = 0;
int GameBoard::nb_turns = 0;

GameBoard::GameBoard (int nb_colors, 
                      int code_lenght, 
                      int turns, 
                      bool random)
        : randomize_code{random}
{
  assert(nb_instances == 0);
  nb_instances +=1;
  nb_turns = turns;
  ColorCode::setDifficulty(code_lenght,nb_colors);
  up_codes.reset(new vector<ColorCode>(turns));
  up_verdicts.reset(new vector<Verdict>(turns));
  up_secret_code.reset(new ColorCode{});
}



int  GameBoard::rdm_secret_code(void)
{
    // obtain a seed from the system clock:
    unsigned seed1 = chrono::system_clock::now().time_since_epoch().count();
    
    default_random_engine rdm_eng {seed1};
    
    uniform_int_distribution<> rdm_distr {0, ColorCode::nb_colors()-1};
    
    // bind() makes a function object based on the first param (a function or 
    // function object), called with second param as parameter.
    auto rdm_color = std::bind(rdm_distr, rdm_eng);
    
    ColorCode& ccode  = *up_secret_code;
    
    for (int i=0; i < ColorCode::lenght(); i++)
    {
        ccode[i] = static_cast<Color>(rdm_color());
    }
    // scroll down to hide the secret code...
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
    enter_user_attempt(t);
    
    auto& verdicts = *up_verdicts; // dereferencing the unique_ptr
    Verdict& verdict = verdicts[t];  // retrieving the color code for that turn
    auto& ccodes = *up_codes; // dereferencing the unique_ptr
    ColorCode& ccode = ccodes[t];  // retrieving the color code for that turn
    return try_this_code(ccode, verdict);
}

int GameBoard::player_turns(void)
{
    bool success;
    auto& codes = *up_codes;
    auto& verdicts = *up_verdicts;
    
    set_secret_code();
    
    for (int t = 0; t < nb_turns; t++)
    {
        this->display(false);
        success = player_turn(t);
        if (success)
        {
            break;
        }
    }
    // end of game.
    this->display(true);
    
    final_message(success);
    
    return success;
}