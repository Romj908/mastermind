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
 * File:   mmCodes.h
 * Author: jerome
 *
 * Created on February 6, 2020, 4:42 PM
 */

#ifndef MMCODES_H
#define MMCODES_H

#include <vector>
#include <memory>
#include <regex>
#include <cassert>
#include <iostream>
using namespace std;

//-----------------------------------------------------------------------------
namespace MMG // Master Mind Game domain name
{
const int MM_SECRETCODE_MAX_LENGHT = 6;

enum Color : char
{
  None = -1,
  Red = 0, Green = 1, Blue = 2, Yellow = 3,  
  Braun = 4, Orange = 5, Gray = 6, Rose = 7,
  LightGreen = 8, LightBlue = 9, LightGray = 10, LightBraun = 11,
  NbColors
};

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
/**
 */
enum class Indic : unsigned int
{
  None = 0,
  Black = 1, // one color correctly placed
  White = 2 // one color badly placed
};

const vector<string> indicName {
  [Indic::None]="-", [Indic::Black]="*", [Indic::White]="0"
};

//-----------------------------------------------------------------------------
class ColorCode // in the sense of combination
{
public:
  ColorCode () : up{new vector<Color>(ColorCode::code_lenght, Color::None)}
  {
    ColorCode::nb_instances += 1;
  };
  ColorCode (const ColorCode& orig); // copy ctor
  ColorCode (ColorCode&& orig); // move dtor

  virtual
  ~ColorCode ()
  {
    ColorCode::nb_instances -= 1;
  }

  ColorCode & operator= (const ColorCode& orig); // copy assignment
  ColorCode & operator= (ColorCode&& orig); // move assignment
  
  void update(const string &str);
  
  
  Color & operator[] (int i)
  {
    return ref ((*up)[i]);
  };
  // check if the object is well defined (it could have been moved) 
  bool valid() const { return up.get () != nullptr;};
  
  
  // dereference the vector and return it 
  vector<Color>& theVect() const 
  { 
    assert(this->valid());
    return *up;
  };
  
private:
  unique_ptr<vector<Color>> up; // main data

  //
  // static data & static functions
  //
private:
  // number of elements to find in the code ()
  static uint code_lenght;

  // remember the number of colors currently used (difficulty level)
  static Color color_limit; // by default.

  static int nb_instances; // number of ColorCode objects

public:

  static int
  lenght ()
  {
    return code_lenght;
  }

  static Color
  limit (void)
  {
    return color_limit;
  }

  static int
  nbInstances ()
  {
    return nb_instances;
  }

  static bool setDifficulty (int code_lenght, int nb_colours) noexcept;
  
  
};

ostream& operator<< (ostream& co, const ColorCode& cc);

#ifdef MMG_DISPL_LETTERS
/* 
 * default (alphanumerical) input of a code by the user.
 * 
 */
unique_ptr<string> read_code_string(void);

void print_allowed_colors(void);

#endif

//-----------------------------------------------------------------------------
class Verdict
{
public:
  Verdict () : up{new vector<Indic>(ColorCode::lenght (), Indic::None)}
  {
  };
  Verdict (const Verdict& orig); // copy ctor
  Verdict (Verdict&& orig); // move dtor
  virtual ~Verdict () {};

  // check if the object is well defined (it could have been moved) 
  bool valid() const { return up.get () != nullptr;};
  
  Indic & operator[] (int i)
  {
    assert(this->valid());
    return ref ((*up)[i]);
  };

  // dereference the vector and return it 
  vector<Indic>& theVect() const { return *up;};
  
private:
  unique_ptr<vector<Indic>> up;
};
ostream& operator<< (ostream& co, const Verdict& cc);
ostream& operator<< (ostream& co, const Indic& cc);


} // MMG

#endif /* MMCODE_H */

