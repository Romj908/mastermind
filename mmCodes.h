/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
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
using namespace std;


//-----------------------------------------------------------------------------
namespace MMG // Master Mind Game domain name
//-----------------------------------------------------------------------------
{
const int MM_SECRETCODE_MAX_LENGHT = 6;

enum Color : char
{
  None=-1,
  Red=0, Green=1, Blue=2, Yellow=3, Braun=4, Orange=5, Gray=6, Rose=7,
  LightGreen=8, LightBlue=9, LightGray=10, LightBraun=11,
  NbColors 
};

const vector<string> colorName {  
  "Red", "Green", "Blue", "Yellow", "Braun", "Orange", "Gray", "Rose",
  "LightGreen", "LightBlue", "LightGray", "LightBraun"
};

/**
 */
enum class Indic : unsigned char
{
  None,
  Black, // one color correctly placed
  White // one color badly placed
};



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

  Color & operator[] (int i)
  {
    return &(*up)[i];
  };
private:
  unique_ptr<vector<Color> *> up; // main data

  //
  // static data & static functions
  //
private:
  // number of elements to find in the code ()
  static uint code_lenght = 0;  
  
  // remember the number of colors currently used (difficulty level)
  static Color color_limit = Color::NbColors;  // by default.
  
  static int nb_instances = 0; // number of ColorCode objects

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

class Verdict
{
public:
  Verdict () : up{new vector<Indic>(ColorCode::lenght (), Indic::None)}
  {
  };
  Verdict (const Verdict& orig); // copy ctor
  Verdict (Verdict&& orig); // move dtor

  Indic & operator[] (int i)
  {
    return &(*up)[i];
  };
private:
  unique_ptr<vector<Indic> *> up;
};

class mmCode
{
public:
  mmCode ();
  virtual ~mmCode ();
private:

};
}

#endif /* MMCODE_H */

