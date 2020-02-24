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
 * File:   ColorGlyph.cpp
 * Author: jerome
 * 
 * Created on February 27, 2020, 6:43 AM
 */

#include "ColorGlyph.h"

namespace MMG
{

std::string
ColorGlyph::ClassName() const
{
    return "ColorGlyph";
}

void 
ColorGlyph::draw (Window *w) const
{
    // draw the disk that's inscribed in the Glyph's rectangle, with the good 
    // color
    /* w->drawInscribedCircle(rect, color)*/
}


}// MMG