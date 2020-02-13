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
 * File:   ConsoleGameBoard.h
 * Author: jerome
 *
 * Created on February 13, 2020, 6:53 PM
 */

#ifndef CONSOLEGAMEBOARD_H
#define CONSOLEGAMEBOARD_H

#include "mmBoard.h"

namespace MMG // Master Mind Game domain name
{

// ConsoleGameBoard : IO are on stdio (console)

class ConsoleGameBoard : public MMG::GameBoard
{
public:
  ConsoleGameBoard (int nb_colors, int code_lenght, int turns, bool random=true)
          : GameBoard(nb_colors, code_lenght, turns, random) {};
          
  ConsoleGameBoard (const ConsoleGameBoard& orig)=delete;
  
  virtual ~ConsoleGameBoard () {cout << "\nConsoleGameBoard deleted\n";};

  void  display (bool secret_code) override;
  int   enter_secret_code(void) override;
  int   enter_user_attempt(int t) override;

private:
  void str_to_code (MMG::ColorCode &ccode, const string &str);

};
} // MMG

#endif /* CONSOLEGAMEBOARD_H */

