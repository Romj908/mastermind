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
 * File:   mmCodes.cpp
 * Author: jerome
 * 
 * Created on February 6, 2020, 4:42 PM
 */
#include <cassert>
#include <array>
#include <iostream>

#include "mmCodes.h"
using namespace std;

namespace MMG // Master Mind Game domain name
{
uint ColorCode::code_lenght = 0;
int  ColorCode::nb_instances = 0;
Color ColorCode::color_limit = Color::NbColors;

ColorCode::ColorCode () 
: up{new vector<Color>(ColorCode::code_lenght, Color::None)}
{
  ColorCode::nb_instances += 1;
};

ColorCode::ColorCode (CodeSize lenght) 
: up{new vector<Color>(lenght, Color::None)}
{
  ColorCode::nb_instances += 1;
};

ColorCode::ColorCode(std::initializer_list<Color> lst)
: up{new vector<Color>(lst)}
{
}

//ColorCode::ColorCode(std::initializer_list<Color> lst)
//: up{new vector<Color>( lst.size())}
//{
//    std::copy(lst.begin(), lst.end(), *up);
//}

ColorCode::~ColorCode ()
{
  ColorCode::nb_instances -= 1;
}

bool ColorCode::setDifficulty(int code_lenght, int n_colors)
noexcept
{
    // First check that this function is called only after all existing 
    // instances have been deleted.
    assert(nb_instances == 0);

    assert(n_colors <= static_cast<int> (Color::NbColors));
    assert(n_colors >= 4);
    ColorCode::color_limit = static_cast<Color> (n_colors);

    assert(code_lenght >= 4);
    if (code_lenght > MM_SECRETCODE_MAX_LENGHT)
        code_lenght = MM_SECRETCODE_MAX_LENGHT;

    ColorCode::code_lenght = code_lenght;

    return false;
}

/* 
 * copy ctor
 * 
 */
ColorCode::ColorCode(const ColorCode& orig)
{
    // allocate a copy of the vector
    up.reset(new vector<Color>{*orig.up});
    assert(up.get()->size() == orig.up.get()->size());
    ColorCode::nb_instances += 1;
}

/* 
 * move ctor
 * 
 */
ColorCode::ColorCode(ColorCode&& orig)
{
    // call the move assignment of the unique_ptr class.
    up = std::move(orig.up);
    assert(orig.up.get() == nullptr);
    ColorCode::nb_instances += 1;
}

/* 
 * move assignment
 * 
 */
ColorCode & ColorCode::operator=(const ColorCode& orig)
{
    // allocate a copy of the vector
    up.reset(new vector<Color>{*orig.up});
}

/* 
 * copy assignment
 * 
 */
ColorCode & ColorCode::operator=(ColorCode&& orig)
{
    up = std::move(orig.up);
    assert(up.get() == nullptr);
    ColorCode::nb_instances += 1;
}

/*
 Verdict class
 */

Verdict::Verdict () 
: up{new vector<Indic>(ColorCode::lenght (), Indic::None)}
{
};
//Verdict::Verdict (const Verdict& orig)
//{
//    
//}
//
//Verdict::Verdict (Verdict&& orig)
//{
//    
//}

} // MMG