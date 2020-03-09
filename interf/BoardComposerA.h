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
 * File:   BoardComposerA.h
 * Author: jerome
 *
 * Created on February 28, 2020, 2:53 PM
 */

#ifndef BOARDCOMPOSERA_H
#define BOARDCOMPOSERA_H

#include "BoardComposer.h"

namespace MMG
{

class BoardComposerA : public BoardComposer
{
public:
    BoardComposerA(GameBoardPtr game_ptr, 
                   GlyphFactoryPtr glyph_factory);
    BoardComposerA(const BoardComposerA& orig) = delete;
    virtual ~BoardComposerA();
    
    virtual void build() override;

    /* from the reference top-left point, dispose the children and compute the 
     * enclosing rectangle and the one of every children.  
     */

    virtual void compose(const Rect& win_rect ) override;
    
    virtual void draw(Window *w) const override;
private:

};
using BoardComposerAPtr = typename std::unique_ptr<BoardComposerA>;

} // MMG
#endif /* BOARDCOMPOSERA_H */

