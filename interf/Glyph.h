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
 * File:   Glyph.h
 * Author: jerome
 * Implementing the part-whole tree that's used to describe graphically the 
 * game board.
 * The design pattern is Composite.
 * Created on February 19, 2020, 9:32 PM
 */

#ifndef GLYPH_H
#define GLYPH_H

/*
 * STL
 */
#include <memory>
#include <vector>
//#include <list>
#include <cassert>

/* Mirza graphical layer inferface */
#include "Window.h"

using namespace mirza;

namespace MMG
{

class Glyph;
using GlyphUPtr = typename std::unique_ptr<Glyph>;
using GlyphIterator = typename std::vector<Glyph *>::iterator;


/* basic pattern */
class Glyph
{
public:

    Glyph()
    {
    }

    Glyph(const Glyph& orig)
    : rect{orig.rect}, parent{orig.parent}
    {
        // instance's name is not updated
    }
    virtual ~Glyph();


    /* Basic graphics */
    virtual void
    draw(Window *w) const = 0; // draw itself and included children if any

    /* Positioning */
    virtual bool
    contains(const Point & point) const noexcept;

    virtual Point
    getCoords(const Point & point) const noexcept;

    virtual void
    setParent(Glyph * parent) noexcept;

    virtual Glyph *
    getParent(void) const;

    virtual int
    nbChildren() const
    {
        return 0;
    }; // by default, no child (relevant for a leaf).

    // debugging
    virtual std::string
    ClassName() const = 0;

public:
    // Rectangle in the current application window, made public to benefit 
    // directly of the rich interface of the Rect class
    Rect rect;

protected:
    // apart of the root, every node has got a parent node. 
    Glyph *parent{};

    // debugging
    std::string name{}; // instance name
};


/* basic composite pattern */
class CompositeGlyph : public Glyph
{
public:

    CompositeGlyph();
    CompositeGlyph(std::size_t nb_children);
    CompositeGlyph(const CompositeGlyph& orig) = delete;
    virtual ~CompositeGlyph() {};

    int
    nbChildren() const override
    {
        return children.size();
    };

    std::string
    ClassName() const override;

public:
    /* Children management */
    virtual Glyph *
    getChild(int idx) const noexcept;

    virtual void
    setChild(int idx, GlyphUPtr&& child);

    virtual void
    deleteChild(int idx);

    virtual GlyphUPtr
    extractChild(int idx);
    
    virtual void 
    compose(const Rect& win_rect) = 0; /* Draw the composite and its children */
    
    void
    draw(Window *w) const override; /* Draw the composite and its children */
protected:
    virtual void
    drawSelf(Window *w) const = 0; // drw itself, without including children
    virtual void
    drawChildren(Window *w) const;
    
    
protected:
    // consider (as simplifications) that:
    // 1) only composite glyphes may have children.
    // 2) std::vector is well suited to the current game - better than a list 
    //  for example.
    // 3) We don't abstract the traversal operations into a Iterator pattern.
    // 4) It's a pure tree : there is no cycle like a child located above in the 
    // hierarchy)
    std::vector<GlyphUPtr> children{};

};


} // MMG

#endif /* GLYPH_H */

