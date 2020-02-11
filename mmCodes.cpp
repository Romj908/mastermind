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
 * File:   mmCodes.cpp
 * Author: jerome
 * 
 * Created on February 6, 2020, 4:42 PM
 */
#include <cassert>
#include <array>
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

#ifdef MMG_DISPL_LETTERS
void print_allowed_colors(void)
{
        cout << ColorCode::nb_colors() << " couleurs possibles: ";
        int i = (int) Color::None;
        while (++i < ColorCode::nb_colors())
        {
            cout << colorName[i] << " ";
        };
    cout << "\n";
}

static string *input_up_string(void)
{
    string *p_str = new string;
    cout << "   "; // kind of tabulation
    // nota: the term 'cin >> c' returns only when a carriage return is entered.
    // c==0 means EOF (obtained here with a Ctrl-D). There is then one loop for
    // every character still available in the stream buffer.
    for (char c; cin >> c && c> 0; )
    {
        //cout << c; cout.flush();
        p_str->push_back(c);
        if (p_str->length() >= ColorCode::lenght())
        {
            // flush the rest (if user entered too much characters)
//            using TMPBUFF = std::array<char,1024>;
//            unique_ptr<TMPBUFF> buffer{new TMPBUFF};
//            cout << buffer.get()->size();
            std::array<char,1024> buffer;
            cin.getline(buffer.data(),buffer.size()); // flush
            break;
        }
    }
    // converts to uppercase
    for (auto& it: *p_str)
    {
        it = ::toupper(it);
    }
    return p_str;
}


unique_ptr<string> read_code_string(void)
{
    bool error;
    unique_ptr<string> up_str{};
    do 
    {
        error = false;
        
        up_str.reset(input_up_string()) ;
        string &the_str = *up_str;
        assert(the_str.length() <= ColorCode::lenght());
        
        for (auto c: the_str)
        {
            if (!(c >= 'A' && c < ('A'+ColorCode::nb_colors())))
            {
                cout << "bad character " << c << "!\n";
                error = true;
                break; // exit the for : stop the scan and read new code
            }
        }
    } while (error);
    
    return up_str;
}
void ColorCode::update(const string &str)
{
    auto& vect = *up;
    int i = 0;
    for (auto c: str)
    {
        int v = c - 'A'; // translate the string value in color 
        assert(v >=0 && v < lenght());
        vect[i++] = static_cast<Color>(v);
    }
}

#endif

ostream& operator<<(ostream& co, const ColorCode& cc)
{
    if (!cc.valid())
        return co;
    
    const vector<Color>& thevect = cc.theVect();
    for (auto c : thevect)
    {
        assert(c < ColorCode::nb_colors());
        if (c != Color::None)
            co << colorName[c];
        else
            co << "*";

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