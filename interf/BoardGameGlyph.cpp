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
 * File:   BoardGameGlyph.cpp
 * Author: jerome
 * 
 * Created on February 28, 2020, 4:46 PM
 */

#include "BoardGameGlyph.h"
namespace MMG
{

BoardGameGlyph::BoardGameGlyph()
: CompositeGlyph {BoardGameArea::nbAreas}
{
}

BoardGameGlyph::~BoardGameGlyph()
{
}

std::string
BoardGameGlyph::ClassName() const
{
    return "BoardGameGlyph";
}

void 
BoardGameGlyph::drawSelf(Window *w) const
{
    
}

} // MMG


