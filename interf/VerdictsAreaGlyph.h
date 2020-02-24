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
 * File:   VerdictsAreaGlyph.h
 * Author: jerome
 *
 * Created on March 2, 2020, 6:38 PM
 */

#ifndef VERDICTSAREAGLYPH_H
#define VERDICTSAREAGLYPH_H

#include "Glyph.h"

namespace MMG
{

class VerdictsAreaGlyph : public CompositeGlyph
{
public:
    VerdictsAreaGlyph();
    VerdictsAreaGlyph(const VerdictsAreaGlyph& orig) = delete;
    virtual ~VerdictsAreaGlyph();

//    void
//    drawSelf(Window *w) const override;
private:

};


using VerdictsAreaGlyphPtr = typename std::shared_ptr<VerdictsAreaGlyph>;

}//MMG
#endif /* VERDICTSAREAGLYPH_H */

