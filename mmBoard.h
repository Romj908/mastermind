/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
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
  GameBoard (int nb_colors, int nb_turns, int code_lenght)
  {
    assert(nb_instances == 0);
    nb_instances +=1;
    ColorCode::setDifficulty(code_lenght,nb_colors);
    up_codes.reset(new vector<ColorCode>(nb_turns));
  }
  virtual ~GameBoard () {nb_instances -=1; };
  
private:
  unique_ptr<vector<ColorCode>> up_codes{};
  unique_ptr<vector<Verdict>>   up_verdicts{};
  
public:
  static int nbTurns() {return nb_turns;}
  
private:
  static int nb_instances;
  static int nb_turns;
};
}

#endif /* MMGBOARD_H */

