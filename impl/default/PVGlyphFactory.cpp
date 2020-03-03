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

ColorGlyphPtr 
PVGlyphFactory::newColorGlyph(Color color) const
{
    ColorGlyphPtr ptr{ new PVColorGlyph{color} };
    return ptr;
}

ColorCodeGlyphPtr 
PVGlyphFactory::newColorCodeGlyph(const ColorCode& ccode) const
{
    ColorCodeGlyphPtr ptr{ new PVColorCodeGlyph{ccode} };
    return ptr;
}

IndicatorGlyphPtr 
PVGlyphFactory::newIndicatorGlyph() const
{
    IndicatorGlyphPtr ptr{ new PVIndicatorGlyph };
    return ptr;
}

VerdictGlyphPtr 
PVGlyphFactory::newVerdictGlyph(const Verdict& verdict) const
{
    VerdictGlyphPtr ptr{ new PVVerdictGlyph{verdict} };
    return ptr;
}

BoardGameGlyphPtr 
PVGlyphFactory::newBoardGameGlyph() const
{
    BoardGameGlyphPtr ptr{ new PVBoardGameGlyph };
    return ptr;
}

ColorCodeAreaGlyphPtr 
PVGlyphFactory::newColorCodeAreaGlyph(int nb_turns) const
{
    ColorCodeAreaGlyphPtr ptr{ new PVColorCodeAreaGlyph{nb_turns} };
    return ptr;
}

VerdictsAreaGlyphPtr 
PVGlyphFactory::newVerdictsAreaGlyph(int nb_turns) const
{
    VerdictsAreaGlyphPtr ptr{ new PVVerdictsAreaGlyph{nb_turns} };
    return ptr;
}


} // MMG
