//
//  main.cpp
//  Assignment4
//
//  Created by Ben Trueman on 1/15/19.
//  Copyright © 2019 Ben Trueman. All rights reserved.
//

#include <iostream>
#include <regex>
#include <set>
#include "functions.hpp"
using namespace std;

/* Classifies Quadrilaterals according to https://www.varsitytutors.com/hotmath/hotmath_help/topics/quadrilaterals.
 In particular, see the Venn diagram at the bottom of the page. Always classify a quadrilateral as precisely as possible. In other words, a square is also a rectangle, but since "square" is the more precise classification it is what you should print.
 Your input arrives on the standard input stream and is a list of quadrilaterals, one per line. Each line describes 3 vertices, which should be treated as arriving in clockwise order, starting from an implied first vertex at 0,0.
 Input lines are of the form:
 x1 y1 x2 y2 x3 y3
 All input values are integers in the range 0..100 (inclusive).

 If your program gets an invalid line of input it must print one of the strings below and then terminate. It should print:
 
 "error 1" -- if the line contains the wrong number of points, contains invalid characters, has coordinates out of the range 0..100, or otherwise fails to describe three points (six integer values)
 "error 2" -- if any two points coincide
 "error 3" -- if any two line segments representing sides cross each other
 "error 4" -- if any three points are colinear1
*/

int main(int argc, const char * argv[]) {
    vector<int> vertices;
    string line;
    while(getline(cin, line)){
        if(error1(line)){
            exitError("error 1");
            continue;
        }
        vertices = parseToVector(line);
        if(error1(vertices)){
            exitError("error 1");
            continue;
        }
        if(error2(vertices)){
            exitError("error 2");
            continue;
        }
        if(error3(vertices)){
            exitError("error 3");
            continue;
        }
        if(error4(vertices)){
            exitError("error 4");
            continue;
        }
        printQuadrilateralType(vertices);
    }
}
