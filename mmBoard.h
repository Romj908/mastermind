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
  GameBoard (int nb_colors, int code_lenght, int turns, bool random=true);
  virtual ~GameBoard () {nb_instances -=1; };
  
  // implementation dependant (console or Qt)
  virtual void display(bool secret_code) = 0;
  virtual int enter_secret_code() = 0; // read user's input in some way.
  virtual int enter_user_attempt(int t) = 0; // read user's input in some way.
  virtual void final_message(bool success) = 0; // victory/defeat message
  
private:
  int rdm_secret_code(void);
  int set_secret_code(void)
  {
    return (randomize_code ?
            rdm_secret_code() :
            enter_secret_code());
  }
  
public:
  bool try_this_code(const ColorCode& candidate, Verdict& verdict);
  virtual bool player_turn(int turn);
  virtual int player_turns(void);
  
  const ColorCode&
  getCode(int i) const;
  
  const Verdict&
  getVerdict(int i) const;
  
  const ColorCode&
  getSecretCode() const;
  
  static int nbTurns() {return nb_turns;}
  
protected:
  unique_ptr<ColorCode>         up_secret_code{};
  unique_ptr<vector<ColorCode>> up_codes{};
  unique_ptr<vector<Verdict>>   up_verdicts{};
  bool                          randomize_code{};
  
private:
  static int nb_instances;
  static int nb_turns;
};

using GameBoardPtr = typename std::shared_ptr<GameBoard>;
}

#endif /* MMGBOARD_H */

