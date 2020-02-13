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
 * File:   ConsoleGameBoard.cpp
 * Author: jerome
 * 
 * Created on February 13, 2020, 6:53 PM
 */

#include "ConsoleGameBoard.h"

using namespace MMG;


void ConsoleGameBoard::str_to_code(ColorCode &ccode, const string &str)
{
    int i = 0;
    for (auto c: str)
    {
        int v = c - 'A'; // translate the string value in color 
        assert(v >=0 && v < ColorCode::nb_colors());
        ccode[i++] = static_cast<Color>(v);
    }
}

int  ConsoleGameBoard::enter_secret_code(void)
{
    cout << endl << "Please enter the new secret code" << endl;
    unique_ptr<string> up_str {MMG::read_code_string()};
    auto& the_str = *up_str;
    
    ColorCode& ccode  = *up_secret_code;
    str_to_code(ccode, the_str);
    //cout << "\nSecret:" << ccode;
    // scroll down to hide the secret code...
    for (int line = 0; line<100; line++)
        cout << endl;
    return 0;
}
int  ConsoleGameBoard::enter_user_attempt(int t)
{
    cout << endl << "Please enter your candidate code" << endl;
    print_allowed_colors();
    unique_ptr<string> up_str {read_code_string()};
    string &the_str = *up_str; // dereferencing the unique_ptr
    auto& ccodes = *up_codes; // dereferencing the unique_ptr
    ColorCode& ccode = ccodes[t];  // retrieving the color code for that turn
    
    str_to_code(ccode, the_str);
    return 0;
}

void ConsoleGameBoard::display(bool secret_code)
{
    const auto& codes = *up_codes;
    const auto& verdicts = *up_verdicts;
    
    cout << endl;
    
    for (int t = 0; t < nbTurns(); t++)
    {
        cout << t << "  " << codes[t] << "  " << verdicts[t] << endl;
    }
    if (secret_code)
    {
        auto &scode = *up_secret_code;
        cout << "\n\nS  ";
        cout << scode << endl;
    }
    
}


