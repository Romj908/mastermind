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
PVBoardGameGlyph::compose(const Rect& win_rect) 
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
    int nb_gaps = ccode.theVect().size();
    assert(children.size() == ccode.theVect().size());
    for (int i=0; i < nb_gaps; i++)
    {
        Color color{ ccode.getColor(i) };
        
        GlyphUPtr cg_ptr{ new PVColorGlyph{color} };
        
        setChild(i, std::move(cg_ptr));
    }

}

PVColorCodeGlyph::~PVColorCodeGlyph()
{
}

void
PVColorCodeGlyph::compose(const Rect& win_rect) 
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
PVColorGlyph::compose(const Rect& win_rect)
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
PVVerdictGlyph::compose(const Rect& win_rect) 
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
PVIndicatorGlyph::compose(const Rect& win_rect)
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

PVVerdictsAreaGlyph::PVVerdictsAreaGlyph(std::size_t nb_turns)
: VerdictsAreaGlyph{nb_turns}
{
    
}

PVVerdictsAreaGlyph::~PVVerdictsAreaGlyph()
{
    
}

void
PVVerdictsAreaGlyph::compose(const Rect& win_rect) 
{
    
}

void
PVVerdictsAreaGlyph::drawSelf(Window *w) const 
{

}

PVColorCodeAreaGlyph::PVColorCodeAreaGlyph(std::size_t nb_turns)
: ColorCodeAreaGlyph{nb_turns}
{
    
}

PVColorCodeAreaGlyph::~PVColorCodeAreaGlyph()
{
    
}

void
PVColorCodeAreaGlyph::compose(const Rect& win_rect) 
{
    
}

void
PVColorCodeAreaGlyph::drawSelf(Window *w) const 
{

}

PVColorPanelAreaGlyph::PVColorPanelAreaGlyph(std::size_t nb_colors)
: ColorPanelAreaGlyph{nb_colors}
{
    
}

PVColorPanelAreaGlyph::~PVColorPanelAreaGlyph()
{
    
}

void
PVColorPanelAreaGlyph::compose(const Rect& win_rect) 
{
    
}

void
PVColorPanelAreaGlyph::drawSelf(Window *w) const 
{

}

} // MMG

