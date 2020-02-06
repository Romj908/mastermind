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

using namespace MMG; // Master Mind Game domain name

static int ColorCode::code_lenght = 0;
static int ColorCode::nb_instances = 0;
static Color ColorCode::color_limit = Color::NbColors;

static bool ColorCode::setDifficulty (int code_lenght, int n_colors)
{
    // First check that this function is called only after all existing 
    // instances have been deleted.
    assert(nb_instances == 0);
    
    assert(n_colors <= static_cast<int>(Color::NbColors));
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
    
    assert(code_lenght >= 4);
    if (code_lenght > MM_SECRETCODE_MAX_LENGHT)
        code_lenght= MM_SECRETCODE_MAX_LENGHT;
    
    ColorCode::code_lenght = code_lenght;
    
    return false;
}

ColorCode::ColorCode (const ColorCode& orig)
{
    // allocate a copy of the vector
    up = new vector<Color>{*orig.up};

    assert(up->size() == orig.size());
}

// move ctor
ColorCode::ColorCode (ColorCode&& orig)
{
    up = std::move(orig.up);
}

mmCode::mmCode() 
{
}

mmCode::mmCode(const mmCode& orig) {
}

mmCode::~mmCode() {
}

