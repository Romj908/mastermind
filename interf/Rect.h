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
 * File:   Rect.h
 * Author: jerome
 *
 * Created on February 24, 2020, 1:54 PM
 */

#ifndef RECT_H
#define RECT_H

#include "Point.h"

namespace mirza
{

struct RectSize
{
  RectSize(int h, int w): height{h}, width{w} {}

  int height;
  int width;
};

class Rect
{
  /* 
   * instance variables:
   */
private:
  Point topLeft;
  Point botRight;

public:
  Rect ()
  : topLeft{}, botRight {}
  {
  };
  Rect (int x, int y, int width, int height)
  : topLeft{Point {x, y}}, botRight { Point {x + width - 1, y + height - 1}}
  {
  };
  Rect (const Point &topleft, const Point &botright)
  : topLeft{topleft}, botRight { botright}
  {
  };
  Rect (const Rect& orig)
  : topLeft{orig.topLeft}, botRight {orig.botRight}
  {
  };

  virtual ~Rect ();

  int
  left () const noexcept
  {
    return topLeft.x;
  }

  int
  right () const noexcept
  {
    return botRight.x;
  }

  int
  top () const noexcept
  {
    return topLeft.y;
  }

  int
  bottom () const noexcept
  {
    return botRight.y;
  }

  int
  height () const noexcept
  {
    return bottom () - top () + 1;
  }

  int
  width () const noexcept
  {
    return right () - left () + 1;
  }

  RectSize 
  size () const noexcept
  {
    RectSize r {height(), width()};
    return r;
  };
  
  void
  getCoords (int *x1, int *y1, int *x2, int *y2) const noexcept
  {
    *x1 = topLeft.x;
    *y1 = topLeft.y;
    *x2 = botRight.x;
    *y2 = botRight.y;
  };

  bool
  isNull () const noexcept
  {
    // A null rectangle has both the width and the height set to 0 
    // (i.e., right() == left() - 1 and bottom() == top() - 1)
    return right () == left () - 1 && bottom () == top () - 1;
  };

  bool
  isEmpty () const noexcept
  {
    // An empty rectangle has a left() > right() or top() > bottom(). 
    // An empty rectangle is not valid (i.e., isEmpty() == !isValid()).
    return left () > right () || top () > bottom ();
  }

  bool
  isValid () const noexcept
  {
    // A valid rectangle has a left() <= right() and top() <= bottom(). 
    // Note that non-trivial operations like intersections are not defined for 
    // invalid rectangles. 
    // A valid rectangle is not empty (i.e., isValid() == !isEmpty()).    
    return left () <= right () || top () <= bottom ();
  }

  void
  setBottom (int y) noexcept
  {
    botRight.y = y;
  }

  void
  setBottomLeft (const Point &p) noexcept
  {
    topLeft.x = p.x;
    botRight.y = p.y;
  }

  void
  setBottomRight (const Point &p) noexcept
  {
    botRight = p;
  }
  
  void
  anchorTopLeft (const Point &p) noexcept
  {
    botRight.x = p.x + height();
    botRight.y = p.y + width();
    setTopLeft(p);
  }

  void
  anchorBottomRight (const Point &p) noexcept
  {
      
  }
  
  void setCoords (int x1, int y1, int x2, int y2) noexcept
  {
    // Sets the coordinates of the rectangle's top-left corner to (x1, y1), 
    // and the coordinates of its bottom-right corner to (x2, y2).
    topLeft.x = x1;
    topLeft.y = y1;
    botRight.x = x2;
    botRight.y = y2;
  }
  
  void setHeight (int height) noexcept
  {
    botRight.y = topLeft.y + height;
  }
  

  void
  setLeft (int x) noexcept
  {
    topLeft.x = x;
  }

  void
  moveHoriz (int x) noexcept
  {
    topLeft.x += x;
    botRight.x += x;
  }
  
  void
  moveVertic (int y) noexcept
  {
    topLeft.y += y;
    botRight.y += y;
  }

  void
  setRect (int x, int y, int width, int height) noexcept
  {
    topLeft.x = x;
    topLeft.y = y;
    botRight.x = topLeft.x + width;
    botRight.y = topLeft.y + height;
  };

  void
  setRight (int x) noexcept
  {
    botRight.x = x;
  };

  void
  setSize (const RectSize &size) noexcept
  {
    botRight.x = topLeft.x + size.width;
    botRight.y = topLeft.y + size.height;
  };

  void
  setTop (int y) noexcept
  {
    topLeft.y = y;
  }

  void
  setTopLeft (const Point &p) noexcept
  {
    topLeft = p;
  }

  void
  setTopRight (const Point &p) noexcept
  {
    botRight.x = p.x;
    topLeft.y = p.y;
  }
  void setWidth (int width) noexcept
  {
    botRight.x = topLeft.x + width;
  }

  void
  setX (int x) noexcept
  {
    topLeft.x = x;
  };

  void
  setY (int y) noexcept
  {
    botRight.y = y;
  }

  void
  shrink (int dx, int dy) noexcept
  {
    topLeft.x += dx;
    topLeft.y += dy;
    botRight.x -= dx;
    botRight.y -= dy;
  }

  bool contains(int x, int y, bool proper) const;
 
  bool contains(const Point& point, bool proper) const 
  {
      return contains(point.x, point.y, proper);
  };
 
  /*
   * not-inlined functions
   */
  Rect intersected (const Rect rectangle) const;

 

};

}
#endif /* RECT_H */

