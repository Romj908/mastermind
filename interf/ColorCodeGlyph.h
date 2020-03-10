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
 * File:   ColorCodeGlyph.h
 * Author: jerome
 *
 * Created on February 27, 2020, 5:03 PM
 */

#ifndef COLORCODEGLYPH_H
#define COLORCODEGLYPH_H
#include "mmCodes.h"
#include "ColorGlyph.h"

namespace MMG
{
/*
 * ColorCodeGlyph
 * In the Glyph tree the graphic representation of a MMG::ColorCode instance.
 * It corresponds on the mastermind's board to a single row of gaps with or 
 * without their colored pieces .  
 */
class ColorCodeGlyph : public CompositeGlyph
{
public:

    ColorCodeGlyph(const ColorCode& ccode );


    ~ColorCodeGlyph()
    {
    }

    // derivate his own rectangle from the enclosing rectangle given as parameter
    virtual void
    compose(const Rect& win_rect) override; 
    
    virtual void
    drawSelf(Window *w) const override;

    virtual std::string
    ClassName() const override;
    
    
    
private:
};

using ColorCodeGlyphUPtr = typename std::unique_ptr<ColorCodeGlyph>;


}// MMG


#endif /* COLORCODEGLYPH_H */

