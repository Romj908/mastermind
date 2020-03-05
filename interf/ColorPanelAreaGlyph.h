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
 * File:   ColorPanelAreaGlyph.h
 * Author: jerome
 *
 * Created on March 5, 2020, 4:42 PM
 */

#ifndef COLORPANELAREAGLYPH_H
#define COLORPANELAREAGLYPH_H

#include "ColorCodeGlyph.h"

namespace MMG
{

class ColorPanelAreaGlyph : public ColorCodeGlyph
{
public:
    ColorPanelAreaGlyph(std::size_t nb_colors);
    ColorPanelAreaGlyph(const ColorPanelAreaGlyph& orig) = delete;
    virtual ~ColorPanelAreaGlyph();
    
    virtual std::string
    ClassName() const override;
    
private:

};

using ColorPanelAreaGlyphUPtr = typename std::unique_ptr<ColorPanelAreaGlyph>;


} // MMG
#endif /* COLORPANELAREAGLYPH_H */

