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
 * File:   BoardComposerA.cpp
 * Author: jerome
 * 
 * Created on February 28, 2020, 2:53 PM
 */

#include "Window.h"
#include "ColorCodeGlyph.h"
#include "BoardComposerA.h"
#include "mmBoard.h"


namespace MMG
{

BoardComposerA::BoardComposerA(GameBoardPtr game_ptr, 
                               GlyphFactoryPtr glyph_factory)
: BoardComposer{game_ptr, glyph_factory}
{
}


BoardComposerA::~BoardComposerA()
{
}



BoardGameGlyphPtr 
BoardComposerA::build()
{
    glyphes_ptr = glyph_factory_ptr->newBoardGameGlyph();
    
    /* creates the ColorCodes area*/
    auto ve_area = glyph_factory_ptr->newVerdictsAreaGlyph(GameBoard::nbTurns());
    glyphes_ptr->setChild(BoardGameGlyph::colorCodesArea, ve_area);
    /* allocate one color code per game turn */
    for (int t = 0; t< GameBoard::nbTurns(); t++)
    {
        auto ccode = game_ptr->getCode(t);
        auto ccode_glyph_ptr = glyph_factory_ptr->newColorCodeGlyph(ccode);
        ve_area->setChild(t, ccode_glyph_ptr);
    }

    /* creates the indicators area */
    auto cc_area = glyph_factory_ptr->newColorCodeAreaGlyph(GameBoard::nbTurns());
    glyphes_ptr->setChild(BoardGameGlyph::verdictsArea, cc_area);
    /* allocate one verdict per game turn */
    for (int t = 0; t< GameBoard::nbTurns(); t++)
    {
        const Verdict& verdict = game_ptr->getVerdict(t);
        auto verdict_glyph_ptr = glyph_factory_ptr->newVerdictGlyph(verdict);
        cc_area->setChild(t, verdict_glyph_ptr);
    }
    
    /* create the secret code area */
    auto scode = game_ptr->getSecretCode();
    auto scode_glyph_ptr = glyph_factory_ptr->newColorCodeGlyph(scode);
    glyphes_ptr->setChild(BoardGameGlyph::secretCodeArea, scode_glyph_ptr);
    
    return glyphes_ptr;
}

void BoardComposerA::compose(const Rect& win_rect )
{
    // place correctly the 
}

void 
BoardComposerA::draw(Window *w) const
{
    
}
}

