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
 * File:   ColorCodeGlyph.cpp
 * Author: jerome
 * 
 * Created on February 27, 2020, 5:03 PM
 */

#include "ColorCodeGlyph.h"

namespace MMG
{


ColorCodeGlyph::ColorCodeGlyph(const ColorCode& ccode)
{
    gaps.resize(ColorCode::lenght());
    
}


std::string
ColorCodeGlyph::ClassName() const
{
    return "ColorCodeGlyph";
}


void
ColorCodeGlyph::drawSelf(Window *w) const 
{

}



}

