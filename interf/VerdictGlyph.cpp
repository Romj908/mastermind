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
 * File:   VerdictGlyph.cpp
 * Author: jerome
 * 
 * Created on March 2, 2020, 9:18 AM
 */

#include "VerdictGlyph.h"

namespace MMG
{
IndicatorGlyph::IndicatorGlyph(const Indic ic)
: indic {ic}
{
}

IndicatorGlyph::~IndicatorGlyph()
{
}

std::string
IndicatorGlyph::ClassName() const 
{
    return "IndicatorGlyph";
}

void
IndicatorGlyph::compose(const Rect& win_rect)
{
    // by default the rect is the same than the enclosing one.
    rect = win_rect;
}

void
IndicatorGlyph::draw(Window *w) const 
{

}

VerdictGlyph::VerdictGlyph(const Verdict& verdict)
:CompositeGlyph{verdict.theVect().size()}
{
}

VerdictGlyph::~VerdictGlyph()
{
}

void
VerdictGlyph::drawSelf(Window *w) const 
{

}

std::string
VerdictGlyph::ClassName() const 
{
    return "VerdictGlyph";
}

} // MMG