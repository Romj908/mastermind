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
 * File:   ColorGlyph.h
 * Author: jerome
 *
 * Created on February 27, 2020, 6:43 AM
 */

#ifndef GLYPHCOLOR_H
#define GLYPHCOLOR_H

#include "mmCodes.h"
#include "Glyph.h"

namespace MMG
{

/*
 * ColorGlyph
 * In the Glyph tree the graphic representation of a MMG::Color instance.
 * It is the equivalent of a plastic colored piece on the mastermind's board.
 * It doesn't have any children in the glyph tree.  
 */
class ColorGlyph : public Glyph
{
public:

    ColorGlyph()
    : color{Color::None}
    {
    }

    ColorGlyph(const Color c)
    : color{c}
    {
    }

    ~ColorGlyph()
    {
    }

    void
    setColor(Color c)
    {
        color = c;
    }
    
    Color
    getColor(void) const
    {
        return color;
    }
    
    virtual void
    compose(const Rect& win_rect) override; 
    
    void
    draw(Window *w) const override;

    std::string
    ClassName() const override;
    
protected:

    Color color;
};

using ColorGlyphUPtr = typename std::unique_ptr<ColorGlyph>;


}// mirza

#endif /* GLYPHCOLOR_H */

