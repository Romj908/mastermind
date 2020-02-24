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
 * File:   Rect.cpp
 * Author: jerome
 * 
 * Created on February 24, 2020, 1:54 PM
 */

#include <cassert>
#include "Rect.h"

namespace mirza
{ 
Rect::~Rect ()
{
    
}

  bool Rect::contains(int x, int y, bool proper) const
  {
      if (proper)
      {
          return (x>topLeft.x && 
                  x< botRight.x &&
                  y>topLeft.y && 
                  y< botRight.y );
      }
      else
      {
          return (x>=topLeft.x && 
                  x<= botRight.x &&
                  y>=topLeft.y && 
                  y<= botRight.y );
      }
  }
  
Rect Rect::intersected(const Rect rectangle) const
{
    assert(0); // todo
}

} // mirza