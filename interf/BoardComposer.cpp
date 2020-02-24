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
 * File:   BoardComposer.cpp
 * Author: jerome
 * 
 * Abstract class implements the strategy pattern through three different 
 * abstract methods: 
 * the compositor (this class) builds the composition (Glyphes) in a first step 
 * trough the build() abstract method. 
 * Then it is able to compose it according to the current application's
 * window through the compose() method.
 * Then it is able to to display it when required ()
 * The composite composition are the graphical elements (Glyphes)
 * Strategy pattern : this class 
 * 
 * The concrete classes 
 * Created on February 28, 2020, 12:09 PM
 */

#include "BoardComposer.h"

namespace MMG
{

BoardComposer::BoardComposer(GameBoardPtr game_board,
                             GlyphFactoryPtr glyph_factory)
: game_ptr{game_board}, glyph_factory_ptr{glyph_factory}
{
    
}


}