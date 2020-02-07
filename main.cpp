/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: jerome
 *
 * Created on February 6, 2020, 11:06 AM
 */

#include <cstdlib>
#include "mmCodes.h"

using namespace std;
using namespace MMG;


/*
 * 
 */
int
main(int argc, char** argv)
{
    cout << "Hello!";
    MMG::ColorCode::setDifficulty(6,8);
    MMG::ColorCode code1{};
    code1[0] = Green;
    code1[1] = Blue;
    cout << endl << "code1: ";
    cout << code1 << endl;
    ColorCode code2{std::move(code1)};
    cout << "code2: ";
    cout << code2 << endl;

    cout << "code1: ";
    cout << code1 << endl;

    Verdict v{};
    v[0] = Indic::Black;
    v[1] = Indic::Black;
    v[2] = Indic::White;
    v[3] = Indic::White;
    
    cout << "verdict v:\n" << v << endl;
    
    return 0;

}

