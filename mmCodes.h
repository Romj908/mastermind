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

/**
 */
enum class Indic : unsigned int
{
  None = 0,
  Black = 1, // one color correctly placed
  White = 2 // one color badly placed
};

//-----------------------------------------------------------------------------
class ColorCode // in the sense of combination
{
public:
    using CodeSize = std::vector<Color>::size_type;
    
  ColorCode (); 
  ColorCode (CodeSize length);
  ColorCode( std::initializer_list<Color> lst);
  
  ColorCode (const ColorCode& orig); // copy ctor
  ColorCode (ColorCode&& orig); // move dtor

  virtual
  ~ColorCode ();

  ColorCode & operator= (const ColorCode& orig); // copy assignment
  ColorCode & operator= (ColorCode&& orig); // move assignment
    
  
  Color & operator[] (int i)
  {
    return ref ((*up)[i]);
  };
  
  Color getColor (int i) const
  {
    return (*up)[i];
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

  /* static methods returning current game's preferences */
  static int
  lenght (void)
  {
    return code_lenght;
  }

  static Color
  nb_colors (void)
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

//-----------------------------------------------------------------------------
class Verdict
{
public:
  Verdict () : up{new vector<Indic>(ColorCode::lenght (), Indic::None)}
  {
  };
  
  // move & copy constructor not required.
  //Verdict (const Verdict& orig); // copy ctor
  //Verdict (Verdict&& orig); // move ctor
  
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


} // MMG

#endif /* MMCODE_H */

