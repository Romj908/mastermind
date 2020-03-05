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
 * File:   PenVersionGlyphes.h
 * Author: jerome
 *
 * Design pattern : Abstract factory
 * Definition of the concrete GLYPH classes corresponding to the graphical 
 * "PenVersion" implementation which is based on calls to basic drawing 
 * functions (drawing through graphical pen)
 * These classes are instantiated by the corresponding concrete PVGlyphFactory.
 * 
 * Created on February 29, 2020, 4:35 PM
 */

#ifndef PENVERSIONGLYPHES_H
#define PENVERSIONGLYPHES_H

#include "../interf/BoardGameGlyph.h"
#include "../interf/ColorGlyph.h"
#include "../interf/ColorCodeGlyph.h"
#include "../interf/VerdictGlyph.h"
#include "../interf/ColorCodeAreaGlyph.h"
#include "../interf/VerdictsAreaGlyph.h"
#include "../interf/ColorPanelAreaGlyph.h"

/*
 * 
 */
namespace MMG
{

class PVBoardGameGlyph : public BoardGameGlyph
{
public:
    PVBoardGameGlyph();
    PVBoardGameGlyph(const PVBoardGameGlyph& orig) = delete;
    virtual ~PVBoardGameGlyph();
    
    void
    drawSelf(Window *w) const override;

    /* setup all the graphical elements (areas, etc...) */
    virtual void
    compose(const Rect& win_rect) override; 
    
private:

};

class PVColorCodeGlyph : public ColorCodeGlyph
{
public:
    PVColorCodeGlyph(const ColorCode& ccode);
    PVColorCodeGlyph(const PVColorCodeGlyph& orig) = delete;
    virtual ~PVColorCodeGlyph();
    
    void
    drawSelf(Window *w) const override;
    
    /* setup all the color codes and gaps */
    virtual void
    compose(const Rect& win_rect) override; 
    
private:

};

class PVColorGlyph : public ColorGlyph
{
public:
    PVColorGlyph(Color color);
    PVColorGlyph(const PVColorGlyph& orig) = delete;
    virtual ~PVColorGlyph();
    
    void
    draw(Window *w) const override;
    
private:

};

class PVIndicatorGlyph : public IndicatorGlyph
{
public:
    PVIndicatorGlyph();
    PVIndicatorGlyph(const PVIndicatorGlyph& orig) = delete;
    virtual ~PVIndicatorGlyph();
    
    void
    draw(Window *w) const override;
    
private:

};

class PVVerdictGlyph : public VerdictGlyph
{
public:
    PVVerdictGlyph(const Verdict& ccode);
    PVVerdictGlyph(const PVVerdictGlyph& orig) = delete;
    virtual ~PVVerdictGlyph();
    
    void
    drawSelf(Window *w) const override;
    
    /* setup every indicator and gap in the verdict */
    virtual void
    compose(const Rect& win_rect) override; 
private:

};

class PVColorCodeAreaGlyph : public ColorCodeAreaGlyph
{
public:
    PVColorCodeAreaGlyph(std::size_t nb_turns);
    PVColorCodeAreaGlyph(const PVColorCodeAreaGlyph& orig) = delete;
    virtual ~PVColorCodeAreaGlyph();
    
    virtual void
    drawSelf(Window *w) const override;
    
    /* setup all the color codes of the area */
    virtual void
    compose(const Rect& win_rect) override; 
private:

};

class PVVerdictsAreaGlyph : public VerdictsAreaGlyph
{
public:
    PVVerdictsAreaGlyph(std::size_t nb_turns);
    PVVerdictsAreaGlyph(const PVVerdictsAreaGlyph& orig) = delete;
    virtual ~PVVerdictsAreaGlyph();
    
    virtual void
    drawSelf(Window *w) const override;
    
    /* setup all the verdicts of the area  */
    virtual void
    compose(const Rect& win_rect) override; 
private:

};

class PVColorPanelAreaGlyph : public ColorPanelAreaGlyph
{
public:
    PVColorPanelAreaGlyph(std::size_t nb_colors);
    PVColorPanelAreaGlyph(const PVColorPanelAreaGlyph& orig) = delete;
    virtual ~PVColorPanelAreaGlyph();
    
    virtual void
    drawSelf(Window *w) const override;
    
    /* setup all the verdicts of the area  */
    virtual void
    compose(const Rect& win_rect) override; 
private:

};


}//MMG
#endif /* PENVERSIONGLYPHES_H */

