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
 * File:   PVGlyphFactory.h
 * Author: jerome
 *
 * Created on March 2, 2020, 1:54 PM
 */

#ifndef PVGLYPHFACTORY_H
#define PVGLYPHFACTORY_H

#include "PenVersionGlyphes.h"
#include "../interf/GlyphFactory.h"

namespace MMG
{
class PVGlyphFactory : public GlyphFactory
{
public:
    PVGlyphFactory();
    PVGlyphFactory(const PVGlyphFactory& orig) = delete;
    virtual ~PVGlyphFactory();
    
    virtual ColorGlyphUPtr 
    newColorGlyph(Color color) const override;
    
    virtual ColorCodeGlyphUPtr 
    newColorCodeGlyph(const ColorCode& ccode) const override;
    
    virtual IndicatorGlyphUPtr 
    newIndicatorGlyph(const Indic ic) const override;
    
    virtual VerdictGlyphUPtr 
    newVerdictGlyph(const Verdict& verdict) const override;
    
    virtual BoardGameGlyphUPtr 
    newBoardGameGlyph() const override;

    virtual ColorCodeAreaGlyphUPtr 
    newColorCodeAreaGlyph(std::size_t nb_turns) const override;
    
    virtual VerdictsAreaGlyphUPtr 
    newVerdictsAreaGlyph(std::size_t nb_turns) const override;
    
    virtual ColorPanelAreaGlyphUPtr 
    newColorPanelAreaGlyph(std::size_t nb_turns) const override;
private:

};
} // MMG

#endif /* PVGLYPHFACTORY_H */

