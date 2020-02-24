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
 * File:   GlyphFactory.cpp
 * Author: jerome
 * 
 * Created on March 2, 2020, 1:14 PM
 */

#include "GlyphFactory.h"

namespace MMG
{
int GlyphFactory::nb_instances{0};

GlyphFactory::GlyphFactory()
{
    assert(nb_instances == 0);
    nb_instances ++;
}

GlyphFactory::~GlyphFactory()
{
    assert(nb_instances == 1);
    nb_instances --;
}

} //MMG
