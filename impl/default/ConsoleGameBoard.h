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
#define MMG_DISPL_LETTERS
#ifdef MMG_DISPL_LETTERS
const vector<string> colorName {
  [Red]="A", [Green]="B", [Blue]="C", [Yellow]="D", 
  [Braun]="E", [Orange]="F", [Gray]="G", [Rose]="H",
  [LightGreen]="I", [LightBlue]="J", 
  [LightGray]="K", [LightBraun]="L"};
#else
const vector<string> colorName {
  [Red]="RD", [Green]="GN", [Blue]="BU", [Yellow]="YW", 
  [Braun]="BR", [Orange]="OE", [Gray]="GY", [Rose]="RO",
  [LightGreen]="LG", [LightBlue]="LU", 
  [LightGray]="LY", [LightBraun]="LN"};
#endif
  
const vector<string> indicName {
  [Indic::None]="-", [Indic::Black]="*", [Indic::White]="0"
};


// ConsoleGameBoard : IO are on stdio (console)

class ConsoleGameBoard : public MMG::GameBoard
{
public:
  ConsoleGameBoard (int nb_colors, int code_lenght, int turns, bool random=true)
          : GameBoard(nb_colors, code_lenght, turns, random) {};
          
  ConsoleGameBoard (const ConsoleGameBoard& orig)=delete;
  
  virtual ~ConsoleGameBoard () {cout << "\nConsoleGameBoard deleted\n";};

  // definition of pure virtual methods 
  void  display (bool secret_code) override;
  void  final_message(bool success) override;
  int   enter_secret_code(void) override;
  int   enter_user_attempt(int t) override;

#ifdef MMG_DISPL_LETTERS
private:
  void str_to_code (MMG::ColorCode &ccode, const string &str);
#endif
};

/* 
 * default (alphanumerical) input of a code by the user.
 * 
 */
unique_ptr<string> read_code_string(void);

void print_allowed_colors(void);

ostream& operator<< (ostream& co, const ColorCode& cc);
ostream& operator<< (ostream& co, const Verdict& cc);
ostream& operator<< (ostream& co, const Indic& cc);


} // MMG

#endif /* CONSOLEGAMEBOARD_H */

