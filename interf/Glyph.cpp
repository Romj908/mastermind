/*
 * Copyright (C) 2020 EngIT
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY
{
}
 without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


/* 
 * File:   Glyph.cpp
 * Author: jerome
 * 
 * Created on February 19, 2020, 9:32 PM
 */

#include "Glyph.h"
#include "Rect.h"
namespace MMG
{

Glyph::~Glyph()
{
}

void Glyph::setParent(const GlyphPtr gptr) noexcept
{
    parent.operator=(gptr); // same than parent = gptr;
}

GlyphPtr 
Glyph::getParent(void) const
{
    return parent.lock(); // returns a shared_ptr
}

bool
Glyph::contains(const Point & point) const  noexcept
{
    
    return rect.contains(point, true);
}

Point
Glyph::getCoords(const Point & point) const  noexcept
{
    return Point{ point.x - rect.left(), 
                  point.y - rect.top()};
}

/* 
 * CompositeGlyph class
 * Children management 
 */
CompositeGlyph::CompositeGlyph()
{
}

CompositeGlyph::CompositeGlyph(int nb_children)
: children{}
{
    children.resize(nb_children);
}


std::string
CompositeGlyph::ClassName() const
{
    return "CompositeGlyph";
}

GlyphPtr
CompositeGlyph::getChild(int idx) const  noexcept
{
    return children.at(idx);
}

void
CompositeGlyph::setChild(int idx, GlyphPtr new_child_ptr)
{
    auto old_child_ptr = children[idx];
    if ( old_child_ptr )
    {
        // debug : check the link to the parent
        auto parent_ptr = old_child_ptr->getParent(); // build a shared_ptr
        assert(parent_ptr.get() == dynamic_cast<Glyph*>(this));
    }
    children[idx] = new_child_ptr;
    assert(dynamic_cast<Glyph*>(this));
    GlyphPtr sptr {this};
//    GlyphPtr sptr {dynamic_cast<Glyph*>(this)};
    new_child_ptr->setParent(sptr);  // implicit shared_ptr to weak_ptr conversion
}

void
CompositeGlyph::deleteChild(int idx)
{
    auto old_child_ptr = children[idx];
    // if the child is valid, reset its 'parent' link and delete it.
    if ( old_child_ptr )
    {
        // debug : check the link to the parent
        auto parent_ptr = old_child_ptr->getParent(); // build a shared_ptr
        assert(parent_ptr.get() == dynamic_cast<Glyph*>(this));
        // clear this pointer to the child.
        children[idx].reset();
        
    }
}

GlyphPtr
CompositeGlyph::extractChild(int idx)
{
    GlyphPtr ptr = children[idx];
    deleteChild(idx);
    return ptr;
}

void
CompositeGlyph::drawChildren(Window *w) const
{
    for (auto it: children)
    {
        it->draw(w);
    }
    
}

void
CompositeGlyph::draw(Window *w) const
{
    drawSelf(w);
    drawChildren(w);
}


}// MMG

