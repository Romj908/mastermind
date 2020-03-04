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
 * File:   ColorCodeAreaGlyph.h
 * Author: jerome
 *
 * Created on March 2, 2020, 6:37 PM
 */

#ifndef COLORCODEAREAGLYPH_H
#define COLORCODEAREAGLYPH_H

#include "Glyph.h"

namespace MMG
{

class ColorCodeAreaGlyph : public CompositeGlyph
{
public:
    ColorCodeAreaGlyph() = delete;
    ColorCodeAreaGlyph(std::size_t nb_turns);
    ColorCodeAreaGlyph(const ColorCodeAreaGlyph& orig)  = delete;
    virtual ~ColorCodeAreaGlyph();

private:

};

using ColorCodeAreaGlyphUPtr = typename std::unique_ptr<ColorCodeAreaGlyph>;

} // MMG
#endif /* COLORCODEAREAGLYPH_H */

