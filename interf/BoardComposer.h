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
 * File:   BoardComposer.h
 * Author: jerome
 *
 * BoardComposer:
 * abstract class defining the pattern used to specify various strategies when 
 * displaying the game board graphical elements. The composers (this class) 
 * works on the composition (the Glyph tree).
 * 
 * The effect of a strategy concrete class is to compute and set the
 * position and size of every glyph of the composition.
 * 
 * Created on February 28, 2020, 12:09 PM
 */

#ifndef BOARDCOMPOSER_H
#define BOARDCOMPOSER_H

#include "BoardGameGlyph.h"
#include "mmBoard.h"
#include "GlyphFactory.h"

namespace MMG
{
    

class BoardComposer
{
public:
    BoardComposer(GameBoardPtr game_ptr,
                  GlyphFactoryPtr glyph_factory);
    virtual ~BoardComposer() {};

    // build the complete tree, with no consideration of disposition.
    virtual void build() = 0;

    /* from the reference top-left point, dispose the children and compute the 
     * enclosing rectangle and the one of every children.  
     */
    virtual void compose(const Rect& win_rect ) = 0;

    /* 
     * draw the complete game board 
     */
    virtual void draw(Window *w) const = 0;
    
protected:
    BoardGameGlyphUPtr  glyphes_ptr;
    GlyphFactoryPtr     glyph_factory_ptr;
    GameBoardPtr        game_ptr;
    
    
private:
};

using BoardComposerPtr = typename std::shared_ptr<BoardComposer>;

}; // MMG
#endif /* BOARDCOMPOSER_H */

