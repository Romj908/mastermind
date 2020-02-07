/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mmCodes.cpp
 * Author: jerome
 * 
 * Created on February 6, 2020, 4:42 PM
 */
#include <cassert>
#include <iostream>

#include "mmCodes.h"
using namespace std;

namespace MMG // Master Mind Game domain name
{
uint ColorCode::code_lenght = 0;
int ColorCode::nb_instances = 0;
Color ColorCode::color_limit = Color::NbColors;

bool ColorCode::setDifficulty(int code_lenght, int n_colors)
noexcept
{
    // First check that this function is called only after all existing 
    // instances have been deleted.
    assert(nb_instances == 0);

    assert(n_colors <= static_cast<int> (Color::NbColors));
    assert(n_colors >= 4);
    ColorCode::color_limit = static_cast<Color> (n_colors);

    {
        cout << n_colors << " couleurs possibles:\n";
        int i = (int) Color::None;
        while (++i < n_colors)
        {
            cout << colorName[i] << " ";
        };
    }
    cout.flush();
    //cout << "\n";

    assert(code_lenght >= 4);
    if (code_lenght > MM_SECRETCODE_MAX_LENGHT)
        code_lenght = MM_SECRETCODE_MAX_LENGHT;

    ColorCode::code_lenght = code_lenght;

    return false;
}

/* 
 * copy ctor
 * 
 */
ColorCode::ColorCode(const ColorCode& orig)
{
    // allocate a copy of the vector
    up.reset(new vector<Color>{*orig.up});
    assert(up.get()->size() == orig.up.get()->size());
    ColorCode::nb_instances += 1;
}

/* 
 * move ctor
 * 
 */
ColorCode::ColorCode(ColorCode&& orig)
{
    // call the move assignment of the unique_ptr class.
    up = std::move(orig.up);
    assert(orig.up.get() == nullptr);
    ColorCode::nb_instances += 1;
}

/* 
 * move assignment
 * 
 */
ColorCode & ColorCode::operator=(const ColorCode& orig)
{
    // allocate a copy of the vector
    up.reset(new vector<Color>{*orig.up});
}

/* 
 * copy assignment
 * 
 */
ColorCode & ColorCode::operator=(ColorCode&& orig)
{
    up = std::move(orig.up);
    assert(up.get() == nullptr);
    ColorCode::nb_instances += 1;
}

ostream& operator<<(ostream& co, const ColorCode& cc)
{
    if (!cc.valid())
        return co;
    
    const vector<Color>& thevect = cc.theVect();
    for (auto c : thevect)
    {
        assert(c < ColorCode::limit());
        if (c != Color::None)
            co << colorName[c] << "(" << static_cast<int> (c) << ") ";
        else
            co << "----- ";

    }
    co.flush();
    return co;
}

ostream& operator<<(ostream& co, const Indic& indic)
{
    const string& str = indicName[static_cast<int> (indic)];
    co << str ;

}

ostream& operator<<(ostream& co, const Verdict& verdict)
{
    if (!verdict.valid())
        return co;
    
    const vector<Indic>& thevect = verdict.theVect();
    for (auto i : thevect)
    {
        co << i;
    }
    co.flush();
    return co;
}

} // MMG