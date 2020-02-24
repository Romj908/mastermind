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
 * File:   Point.h
 * Author: jerome
 *
 * Created on February 24, 2020, 1:55 PM
 */

#ifndef POINT_H
#define POINT_H
namespace mirza
{
struct Point
{
  Point():x{},y{} {};
  Point(int xi, int yi):x{xi},y{yi} {};
  Point (const Point& orig) : x{orig.x}, y{orig.y}{};
  virtual ~Point ();
  int x; // horizontal axis. Origin being most top-left pixel.
  int y; // vertical axis.   Origin being most top-left pixel.  
  Point & operator=(const Point& orig) {x= orig.x; y = orig.y;};
};

}
#endif /* POINT_H */

