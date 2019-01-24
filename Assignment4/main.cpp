//
//  main.cpp
//  Assignment3
//
//  Created by Ben Trueman on 1/15/19.
//  Copyright © 2019 Ben Trueman. All rights reserved.
//

#include <iostream>
#include <regex>
#include "functions.hpp"
using namespace std;

/* Classifies Quadrilaterals according to https://www.varsitytutors.com/hotmath/hotmath_help/topics/quadrilaterals.
 In particular, see the Venn diagram at the bottom of the page. Always classify a quadrilateral as precisely as possible. In other words, a square is also a rectangle, but since "square" is the more precise classification it is what you should print.
 Your input arrives on the standard input stream and is a list of quadrilaterals, one per line. Each line describes 3 vertices, which should be treated as arriving in clockwise order, starting from an implied first vertex at 0,0.
 Input lines are of the form:
 x1 y1 x2 y2 x3 y3
 All input values are integers in the range 0..100 (inclusive).
 Does not do input validation.
 */

int main(int argc, const char * argv[]) {
    vector<int> vertices;
    string line;
    while(getline(cin, line)){
        vertices = parseToVector(line);
        printQuadrilateralType(vertices);
    }
}
