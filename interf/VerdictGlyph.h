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
 * File:   VerdictGlyph.h
 * Author: jerome
 *
 * Defining 
 * Created on March 2, 2020, 9:18 AM
 */

#ifndef VERDICTGLYPH_H
#define VERDICTGLYPH_H
#include "mmCodes.h"
#include "Glyph.h"

namespace MMG
{

/*
 * IndicGlyph
 * In the Glyph tree the graphic representation of a MMG::Indic instance.
 * It is a single white or black piece, or the empty gap if none is present.
 * It is a leaf node in the Glyph tree.  
 */
class IndicatorGlyph : public Glyph
{
public:
    IndicatorGlyph();
    IndicatorGlyph(const IndicatorGlyph& orig) = delete;
    virtual ~IndicatorGlyph();

    std::string
    ClassName() const override;


    virtual void
    compose(const Rect& win_rect) override; 

    void
    draw(Window *w) const override;
    
    void
    setValue(Indic ic)
    {
        indic = ic;
    }
    
    Indic
    getValue(void) const
    {
        return indic;
    }
    
private:
    Indic indic;
};

using IndicatorGlyphUPtr = typename std::shared_ptr<IndicatorGlyph>;



/*
 * VerdictGlyph
 * In the Glyph tree the graphic representation of a MMG::Verdict instance.
 * It corresponds on the mastermind's board to the indicators with or without 
 * their white/black pieces.  
 */
class VerdictGlyph : public CompositeGlyph
{
public:

    VerdictGlyph(const Verdict& verdict );


    ~VerdictGlyph();

    void
    drawSelf(Window *w) const override;

    std::string
    ClassName() const override;
    
    
    
private:
    //
    std::vector<IndicatorGlyphUPtr> indics;
};

using VerdictGlyphUPtr = typename std::unique_ptr<VerdictGlyph>;


}// MMG


#endif /* VERDICTGLYPH_H */

