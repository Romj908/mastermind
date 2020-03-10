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

// distances between colors and ColorCode's surrounding rectangle 
const int ColorVerticMargin = 10;  
const int ColorHorizMargin = 10;  

// distances between color codes and Area's surrounding rectangle 
const int ColorCodeAreaVerticMargin = 10;  
const int ColorCodeAreaHorizMargin = 10; 

// Vertical distance between two colors codes
const int ColorCodeVerticSpace = 10; 

// Length of a Indicator element's side.
const int IndicatorGlyphSide = 20;
// Length of an empty element's side.
const int EmptyIndicatorGlyphSide = 6;

// horiz distance between two indicators
const int IndicatorHorizSpace = 10; 

// distances between Indicators and verdict's surrounding rectangle 
const int IndicatorVerticMargin = 5;  
const int IndicatorHorizMargin = 5;  

// distances between colors and ColorCode's surrounding rectangle 
const int VerdictVerticMargin = 10;  
const int VerdictHorizMargin = 10;  

// Vertical distance between two colors codes
const int VerdictVerticSpace = 10; 

// distances between colors and ColorCode's surrounding rectangle 
const int VerdictAreaVerticMargin = 10;  
const int VerdictAreaHorizMargin = 10;  

const int BoardGameVerticMargin = 20;  
const int BoardGameHorizMargin = 20;  


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
    rect = win_rect;
    
    // area of the color codes 
    Rect ccodes_rect = win_rect;
    ccodes_rect.shrink(BoardGameVerticMargin, BoardGameHorizMargin);
    Glyph *ccode_area = getChild(BoardGameGlyph::colorCodesArea);
    ccode_area->compose(ccodes_rect);
    ccodes_rect = ccode_area->rect; // the final produced rectangle.
    
    // area of the Verdict codes. Same height than the color codes.
    Rect verdicts_rect = ccodes_rect;
    verdicts_rect.moveHoriz(verdicts_rect.width() + BoardGameHorizMargin);
    Glyph *verdicts_area = getChild(BoardGameGlyph::verdictsArea);
    verdicts_area->compose(verdicts_rect);
    verdicts_rect = verdicts_area->rect; // the final produced rectangle.
    
    // area of the color panel.
    Rect panel_rect = ccodes_rect;
    panel_rect.moveVertic(panel_rect.height() + BoardGameVerticMargin);
    Glyph *panel_area = getChild(BoardGameGlyph::colorPanelArea);
    panel_area->compose(panel_rect);
    panel_rect = panel_area->rect; // the final produced rectangle.
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
    Rect ccode_rect = win_rect; 
    
    Rect temp_rect = win_rect; // a copy
    
    temp_rect.moveVertic(ColorVerticMargin/2);
    temp_rect.moveHoriz(ColorHorizMargin/2);
    
    for (int i = 0; i< children.size(); i++)
    {
        Glyph * p_child = children[i].get(); // a ColorGlyph
        p_child->compose(temp_rect);
        temp_rect.moveHoriz(p_child->rect.width()+ColorHorizSpace);
    }
    
    ccode_rect.setHeight(temp_rect.height() - ColorHorizSpace + ColorHorizMargin/2);
    ccode_rect.setRight(temp_rect.right() + ColorHorizMargin/2);
    rect = ccode_rect;
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
    rect.setTop(win_rect.top());
    rect.setLeft(win_rect.left());
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
    Rect area_rect = win_rect; 
    
    Rect temp_rect = win_rect; // a copy
    
    temp_rect.moveVertic(ColorVerticMargin);
    temp_rect.moveHoriz(ColorHorizMargin);
    
    for (int i = 0; i< children.size(); i++)
    {
        Glyph * p_child = children[i].get(); // a ColorCodeGlyph.
        p_child->compose(temp_rect);
        temp_rect.moveVertic(p_child->rect.height()+ColorCodeVerticSpace);
    }
    
    area_rect.setHeight(area_rect.top() - temp_rect.bottom() - ColorCodeVerticSpace + ColorCodeAreaVerticMargin);
    area_rect.setRight(temp_rect.right() - temp_rect.left() + ColorCodeAreaHorizMargin);
    
    rect = area_rect;
}

void
PVColorCodeAreaGlyph::drawSelf(Window *w) const 
{

}


/* PVVerdictGlyph */
PVVerdictGlyph::PVVerdictGlyph(const Verdict& verdict)
:VerdictGlyph{verdict}
{
    int nb_gaps = verdict.theVect().size();
    assert(children.size() == verdict.theVect().size());
    for (int i=0; i < nb_gaps; i++)
    {
        Indic indic {verdict.theVect().at(i)};
        GlyphUPtr ind_ptr{ new PVIndicatorGlyph { indic } };
        
        setChild(i, std::move(ind_ptr));
    }

}

PVVerdictGlyph::~PVVerdictGlyph()
{
}

void
PVVerdictGlyph::compose(const Rect& win_rect) 
{
    Rect verdict_rect = win_rect; 
    
    Rect temp_rect = win_rect; // a copy
    
    temp_rect.moveVertic(VerdictVerticMargin/2);
    temp_rect.moveHoriz(VerdictHorizMargin/2);
    
    for (int i = 0; i< children.size(); i++)
    {
        Glyph * p_child = children[i].get(); // an IndicatorGlyph
        p_child->compose(temp_rect);
        temp_rect.moveHoriz(p_child->rect.width()+IndicatorHorizSpace);
    }
    
    verdict_rect.setHeight(temp_rect.height() - IndicatorHorizSpace + VerdictHorizMargin/2);
    verdict_rect.setRight(temp_rect.right() + VerdictHorizMargin/2);
    rect = verdict_rect;
   
}

void 
PVVerdictGlyph::drawSelf(Window *w ) const
{
    
}

PVIndicatorGlyph::PVIndicatorGlyph(const Indic ic)
: IndicatorGlyph {ic}
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
    rect.setTop(win_rect.top());
    rect.setLeft(win_rect.left());
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
    Rect area_rect = win_rect; 
    
    Rect temp_rect = win_rect; // a copy
    
    temp_rect.moveVertic(VerdictVerticMargin);
    temp_rect.moveHoriz(VerdictHorizMargin);
    
    for (int i = 0; i< children.size(); i++)
    {
        Glyph * p_child = children[i].get(); // a VerdictGlyph.
        p_child->compose(temp_rect);
        temp_rect.moveVertic(p_child->rect.height()+VerdictVerticSpace);
    }
    
    area_rect.setHeight(area_rect.top() - temp_rect.bottom() - VerdictVerticSpace + ColorVerticMargin);
    area_rect.setRight(temp_rect.right() - temp_rect.left() + ColorHorizMargin);
    
    rect = area_rect;
    
}

void
PVVerdictsAreaGlyph::drawSelf(Window *w) const 
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

