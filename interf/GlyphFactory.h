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
 * File:   GlyphFactory.h
 * Author: jerome
 *
 * Created on March 2, 2020, 1:14 PM
 */

#ifndef GLYPHFACTORY_H
#define GLYPHFACTORY_H

#include "BoardGameGlyph.h"
#include "ColorCodeGlyph.h"
#include "ColorCodeAreaGlyph.h"
#include "VerdictGlyph.h"
#include "VerdictsAreaGlyph.h"

namespace MMG
{
class GlyphFactory
{
public:
    GlyphFactory();
    virtual ~GlyphFactory();
    
    virtual ColorGlyphPtr 
    newColorGlyph(Color color) const = 0;
    
    virtual ColorCodeGlyphPtr 
    newColorCodeGlyph(const ColorCode& ccode) const = 0;
    
    virtual IndicatorGlyphPtr 
    newIndicatorGlyph() const = 0;
    
    virtual VerdictGlyphPtr 
    newVerdictGlyph(const Verdict& verdict) const = 0;
    
    virtual BoardGameGlyphPtr 
    newBoardGameGlyph() const = 0;
    
    virtual ColorCodeAreaGlyphPtr 
    newColorCodeAreaGlyph(int nb_turns) const = 0;
    
    virtual VerdictsAreaGlyphPtr 
    newVerdictsAreaGlyph(int nb_turns) const = 0;
    
private:
    static int nb_instances; 
};

using GlyphFactoryPtr = typename std::shared_ptr<GlyphFactory>;


} // MMG
#endif /* GLYPHFACTORY_H */

