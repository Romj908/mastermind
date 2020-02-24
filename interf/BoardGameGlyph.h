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
 * File:   BoardGameGlyph.h
 * Author: jerome
 *
 * Created on February 28, 2020, 4:46 PM
 */

#ifndef BOARDGAMEGLYPH_H
#define BOARDGAMEGLYPH_H

#include "Glyph.h"

namespace MMG // Master Mind Game domain name
{

class BoardGameGlyph : public CompositeGlyph
{
public:

    enum BoardGameArea : char
    {
        colorCodesArea = 0,
        verdictsArea = 1,
        secretCodeArea = 2,
        nbAreas
    };
    
    BoardGameGlyph();
    BoardGameGlyph(const BoardGameGlyph& orig) = delete;
    virtual ~BoardGameGlyph();

    std::string
    ClassName() const override;

    void
    drawSelf(Window *w) const override;


private:

};

using BoardGameGlyphPtr = typename std::shared_ptr<BoardGameGlyph>;

}

#endif /* BOARDGAMEGLYPH_H */

