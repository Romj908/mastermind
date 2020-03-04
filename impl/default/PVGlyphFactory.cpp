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
 * File:   PVGlyphFactory.cpp
 * Author: jerome
 * 
 * Created on March 2, 2020, 1:54 PM
 */

#include "PVGlyphFactory.h"
#include "../../mmBoard.h"

namespace MMG
{
PVGlyphFactory::PVGlyphFactory()
{
}

PVGlyphFactory::~PVGlyphFactory()
{
}

ColorGlyphUPtr 
PVGlyphFactory::newColorGlyph(Color color) const
{
    ColorGlyphUPtr ptr{ new PVColorGlyph{color} };
    return ptr;
}

ColorCodeGlyphUPtr 
PVGlyphFactory::newColorCodeGlyph(const ColorCode& ccode) const
{
    ColorCodeGlyphUPtr ptr{ new PVColorCodeGlyph{ccode} };
    return ptr;
}

IndicatorGlyphUPtr 
PVGlyphFactory::newIndicatorGlyph() const
{
    IndicatorGlyphUPtr ptr{ new PVIndicatorGlyph };
    return ptr;
}

VerdictGlyphUPtr 
PVGlyphFactory::newVerdictGlyph(const Verdict& verdict) const
{
    VerdictGlyphUPtr ptr{ new PVVerdictGlyph{verdict} };
    return ptr;
}

BoardGameGlyphUPtr 
PVGlyphFactory::newBoardGameGlyph() const
{
    BoardGameGlyphUPtr ptr{ new PVBoardGameGlyph };
    return ptr;
}

ColorCodeAreaGlyphUPtr 
PVGlyphFactory::newColorCodeAreaGlyph(std::size_t nb_turns) const
{
    ColorCodeAreaGlyphUPtr ptr{ new PVColorCodeAreaGlyph{nb_turns} };
    return ptr;
}

VerdictsAreaGlyphUPtr 
PVGlyphFactory::newVerdictsAreaGlyph(std::size_t nb_turns) const
{
    VerdictsAreaGlyphUPtr ptr{ new PVVerdictsAreaGlyph{nb_turns} };
    return ptr;
}


} // MMG
