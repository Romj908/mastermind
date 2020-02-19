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

namespace MMG
{
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

#ifdef MMG_DISPL_LETTERS
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
#else
// not implemented
#endif

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
void ConsoleGameBoard::final_message(bool success)
{
    if (success)
        cout << endl << "You won! :)" << endl;
    else
        cout << endl << "You have lost, sorry."<< endl;
    // wait for user input before to continue.
    char c;
    cout << endl << "<press a key to continue>";
    cin >> c;

}

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

}; // MMG
