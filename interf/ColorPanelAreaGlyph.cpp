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
 * File:   ColorPanelAreaGlyph.cpp
 * Author: jerome
 * 
 * Created on March 5, 2020, 4:42 PM
 */

#include "ColorPanelAreaGlyph.h"

namespace MMG
{

ColorPanelAreaGlyph::ColorPanelAreaGlyph(std::size_t nb_colors)
: ColorCodeGlyph{Color::NbColors} 
{
    ColorCode panel_code {  Red, Green, Blue, Yellow,  
                    Braun, Orange, Gray, Rose,
                    LightGreen, LightBlue, LightGray, LightBraun };
                    
    assert(children.size() == Color::NbColors);                
    
    for (int i; i< children.size(); i++)
    {
        ColorGlyph *p_col_gl = dynamic_cast<ColorGlyph*>(children[i].get());
        p_col_gl->setColor(panel_code[i]);
    }
    // shorten the children's vector to the number of allowed colors.
    children.resize( nb_colors );
}

ColorPanelAreaGlyph::~ColorPanelAreaGlyph()
{
}

std::string
ColorPanelAreaGlyph::ClassName() const
{
    return "ColorCodeGlyph";
}

} // MMG