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
 * File:   mmBoard.h
 * Author: jerome
 *
 * Created on February 6, 2020, 3:17 PM
 */

#ifndef MMBOARD_H
#define MMBOARD_H

#include <vector>
#include <memory>
#include <bits/stl_vector.h>

using namespace std;

#include "mmCodes.h"

//-----------------------------------------------------------------------------
namespace MMG // Master Mind Game domain name
{
//class GameBoard;

class GameBoard
{
public:
  GameBoard() {}
  GameBoard (int nb_colors, int code_lenght, int turns) 
  {
    assert(nb_instances == 0);
    nb_instances +=1;
    nb_turns = turns;
    ColorCode::setDifficulty(code_lenght,nb_colors);
    up_codes.reset(new vector<ColorCode>(turns));
    up_verdicts.reset(new vector<Verdict>(turns));
    up_secret_code.reset(new ColorCode{});
    current_turn = 0;
  }
  virtual ~GameBoard () {nb_instances -=1; };
  
  virtual void display(bool secret_code);
  virtual int set_new_secret_code();
  bool try_this_code(const ColorCode& candidate, Verdict& verdict);
  virtual bool player_turn(int turn);
  virtual int player_turns(void);
  
private:
  unique_ptr<ColorCode> up_secret_code{};
  unique_ptr<vector<ColorCode>> up_codes{};
  unique_ptr<vector<Verdict>>   up_verdicts{};
  
  
public:
  static int nbTurns() {return nb_turns;}
  
private:
  static int nb_instances;
  static int nb_turns;
  int current_turn;
};
}

#endif /* MMGBOARD_H */

