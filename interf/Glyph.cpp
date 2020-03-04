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

void Glyph::setParent(Glyph * p_parent) noexcept
{
    parent = p_parent; // same than parent = gptr;
}

Glyph * 
Glyph::getParent(void) const
{
    return parent; 
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
: children{}
{
}

CompositeGlyph::CompositeGlyph(std::size_t nb_children)
: children{}
{
    children.resize(nb_children);
}


std::string
CompositeGlyph::ClassName() const
{
    return "CompositeGlyph";
}

Glyph *
CompositeGlyph::getChild(int idx) const  noexcept
{
    return children.at(idx).get();
}

void
CompositeGlyph::setChild(int idx, GlyphUPtr&& new_child_ptr)
{
    if ( children[idx].get() != nullptr )
    {
        // debug : check the link to the parent
        Glyph *parent_p = children[idx]->getParent(); // build a shared_ptr
        assert(parent_p == dynamic_cast<Glyph*>(this));
        parent_p->setParent(nullptr);
    }
    new_child_ptr->setParent(this);
    children[idx] = std::move(new_child_ptr);
}

void
CompositeGlyph::deleteChild(int idx)
{
    // if the child is valid, reset its 'parent' link and delete it.
    if ( children[idx].get() != nullptr)
    {
        // debug : check the link to the parent
        Glyph *parent_p = children[idx]->getParent(); // build a shared_ptr
        assert(parent_p == dynamic_cast<Glyph*>(this));
        // clear this pointer to the child.
        children[idx].reset();
    }
}

GlyphUPtr 
CompositeGlyph::extractChild(int idx)
{
    assert(children[idx].get() != nullptr);
    return std::move(children[idx]);
}

void
CompositeGlyph::drawChildren(Window *w) const
{
    // std::vector<GlyphUPtr>::iterator
    auto it = children.begin();
    while(it != children.end())
    {
        assert(it->get() != nullptr);
        it++;
    }    
}

void
CompositeGlyph::draw(Window *w) const
{
    drawSelf(w);
    drawChildren(w);
}


}// MMG

