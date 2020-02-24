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
 * File:   PenVersionGlyphes.cpp
 * Author: jerome
 * 
 * Created on February 29, 2020, 4:35 PM
 */

#include "PenVersionGlyphes.h"
#include "../../mmBoard.h"

namespace MMG
{
// Length of a Color element's side.
const int ColorGlyphSide = 40;

// Length of an empty element's side.
const int EmptyColorGlyphSide = 10;

// minimal horiz distance between two colors
const int ColorHorizSpace = 10; 

// minimal distances between colors and ColorCode's surrounding rectangle 
const int ColorVerticMargin = 5;  
const int ColorHorizMargin = 5;  

// Length of a Indicator element's side.
const int IndicatorGlyphSide = 20;
// Length of an empty element's side.
const int EmptyIndicatorGlyphSide = 6;

// minimal horiz distance between two colors
const int IndicatorHorizSpace = 10; 

// minimal distances between Indicators and verdict's surrounding rectangle 
const int IndicatorVerticMargin = 5;  
const int IndicatorHorizMargin = 5;  

/*PVBoardGameGlyph*/
PVBoardGameGlyph::PVBoardGameGlyph()
{
}

PVBoardGameGlyph::~PVBoardGameGlyph()
{
}

void 
PVBoardGameGlyph::drawSelf(Window *w ) const
{
    
}

/* PVColorCodeGlyph */


PVColorCodeGlyph::PVColorCodeGlyph(const ColorCode& ccode)
:ColorCodeGlyph{ccode}
{
    for (int i=0; i < ColorCode::lenght(); i++)
    {
        Color color{ ccode.getColor(i) };
        
        ColorGlyphPtr cgptr{ new PVColorGlyph(color) };
        
        setChild(i, cgptr);
    }

}

PVColorCodeGlyph::~PVColorCodeGlyph()
{
}

void 
PVColorCodeGlyph::drawSelf(Window *w ) const
{
    
}

/* PVColorGlyph */

PVColorGlyph::PVColorGlyph(Color color)
: ColorGlyph{color}
{
    rect.setHeight(ColorGlyphSide);
    rect.setWidth(ColorGlyphSide);
}

PVColorGlyph::~PVColorGlyph()
{
}

void 
PVColorGlyph::draw(Window *w ) const
{
    switch (color)
    {
    case Color::None:
        break;
    default:
        break;
    }
}



/* PVVerdictGlyph */
PVVerdictGlyph::PVVerdictGlyph(const Verdict& verdict)
:VerdictGlyph{verdict}
{
}

PVVerdictGlyph::~PVVerdictGlyph()
{
}

void 
PVVerdictGlyph::drawSelf(Window *w ) const
{
    
}

/* PVIndicatorGlyph */
PVIndicatorGlyph::PVIndicatorGlyph()
{
    rect.setHeight(IndicatorGlyphSide);
    rect.setWidth(IndicatorGlyphSide);
}

PVIndicatorGlyph::~PVIndicatorGlyph()
{
}

void 
PVIndicatorGlyph::draw(Window *w ) const
{
    switch (getValue())
    {
    case Indic::None:
        break;
    default:
        break;
    }
}

void
PVVerdictsAreaGlyph::drawSelf(Window *w) const 
{

}

void
PVColorCodeAreaGlyph::drawSelf(Window *w) const 
{

}

} // MMG

