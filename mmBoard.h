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

using namespace std;


class GameBoard
{
public:
  GameBoard (int nb_colors, int nb_turns, int code_lenght);
  GameBoard (const GameBoard& orig);
  virtual ~GameBoard ();
private:
  vector<Code> toto;

};
}
#endif /* MMGBOARD_H */

