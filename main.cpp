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
//#include "functions.hpp"
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;
#define pdd pair<double, double>

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

//must contain 0-9 or space only. Returns true if an errof is found http://www.cplusplus.com/reference/string/string/find_first_not_of/
bool error1(std::string s){
    size_t found = s.find_first_not_of("0123456789 ");
    return (found != std::string::npos);
}

//must contain 6 ints in range 0 to 100
bool error1(std::vector<int> vect){
    if(vect.size() != 6) return true;
    
    for(int i: vect){
        if(i < 0 || i > 100) return true;
    }
    return false;
}

void exitError(std::string error){
    std::cout << error << std::endl;
        exit (EXIT_FAILURE);
}

//"error 2" -- if any two points coincide http://www.cplusplus.com/reference/vector/vector/operators/
bool error2(std::vector<int> vect){
    std::vector<int> A = {0,0};
    std::vector<int> B = {vect[0],vect[1]};
    std::vector<int> C = {vect[2],vect[3]};
    std::vector<int> D = {vect[4],vect[5]};
    
    if(A == B || A == C || A == D || B == C || B == D || C == D){
        return true;
    }
    return false;
}

//"error 3" -- if any three points are colinear
//A1 and A2 are 0 and 1
//B1 and B2 are 2 and 3
//C1 and C2 are 4 and 5
//D1 and D2 are 6 and 7
pdd lineLineIntersection (pdd A, pdd B, pdd C, pdd D) {
    // Line AB represented as a1x + b1y = c1
    double a1 = B.second - A.second;
    double b1 = A.first - B.first;
    double c1 = a1*(A.first) + b1*(A.second);
    
    // Line CD represented as a2x + b2y = c2
    double a2 = D.second - C.second;
    double b2 = C.first - D.first;
    double c2 = a2*(C.first)+ b2*(C.second);
    
    double determinant = a1*b2 - a2*b1;
    
    if (determinant == 0)
    {
        // The lines are parallel. This is simplified
        // by returning a pair of FLT_MAX
        return make_pair((double)__FLT_MAX__, (double)__FLT_MAX__);
    }
    else
    {
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        return make_pair(x, y);
    }
}

bool error3 (const vector<int> &coords){
    pdd A = make_pair(0, 0);
    pdd B = make_pair(coords[0], coords[1]);
    pdd C = make_pair(coords[2], coords[3]);
    pdd D = make_pair(coords[4], coords[5]);
    
    //line AB BC CD DA
    pdd intersection1 = lineLineIntersection(A, B, C, D);
    pdd intersection2 = lineLineIntersection(A, D, C, B);
    
    int xMax = 0;
    int yMax = 0;
    
    for(int i = 0 ; i<coords.size(); i+=2){
        if(coords[i]>xMax){
            xMax=coords[i];
        }
    }
    
    for(int i=1; i<coords.size(); i+=2){
        if(coords[i]>yMax){
            yMax=coords[i];
        }
    }
    if (intersection1.first<xMax && intersection1.second<yMax && intersection1.first>0 && intersection1.second>0){
        //if intersection y > AB max y
        if(intersection1.second > coords[1]){
            return false;
        }
        return true;
    }
    if(intersection2.first<xMax && intersection2.second<yMax && intersection2.second>0 && intersection2.second>0){
        return true;
    }
    return false;
}

//adapted from https://www.geeksforgeeks.org/program-check-three-points-collinear/
bool collinear(int x1, int y1, int x2,int y2, int x3, int y3) {
    int a = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    return (a == 0);
}

//"error 4" -- if any three points are colinear
bool error4(std::vector<int> vect){
    if(collinear(0, 0, vect[0], vect[1], vect[2], vect[3])) return true;//A B C
    if(collinear(0, 0, vect[0], vect[1], vect[4], vect[5])) return true;//A B D
    if(collinear(0, 0, vect[2], vect[3], vect[4], vect[5])) return true;//A C D
    if(collinear(vect[0], vect[1], vect[2], vect[3], vect[4], vect[5])) return true;//B C D
    return false;
}

std::vector<int> parseToVector(std::string &string){
    std::stringstream iss(string);
    std::string number;
    std::vector<int> parsedInput;
    while (iss >> number){
        parsedInput.push_back(std::stoi(number));
    }
    return parsedInput;
}

//slope = (Y2 - Y1)/(X2 - X1)
double slope(const int &xA, const int &yA, const int &xB, const int &yB){
    if(yB - yA == 0 || xB - xA == 0) return 0; //return zero for horizontal or vertical lines
    double slopeAB = (double)(yB - yA)/(xB - xA);
    return slopeAB;
}

//distance between two vertices
double distance(const int &x1, const int &y1, const int &x2, const int &y2){
    double distance = 0;
    distance = sqrt(pow((x2 - x1),2) + pow((y2 - y1),2));
    return distance;
}

bool areParallel(const double &slopeA, const double &slopeB){
    return (std::abs((slopeA - slopeB)) < 0.001);
}

//are both pairs of opposite sides parallel? .
bool isParallelogram(const double &slopeAB, const double &slopeBC, const double &slopeCD, const double &slopeDA){
    return areParallel(slopeAB, slopeCD) && areParallel(slopeDA, slopeBC);
}

// Rectangle: four right angles (slopes of all 4 lines must be zero since one vertice is locked at 0,0)
bool isRectangle(const double &slopeAB, const double &slopeBC, const double &slopeCD, const double &slopeDA){
    return (slopeAB == 0 && slopeBC == 0 && slopeCD == 0 && slopeDA == 0);
}

// Rhombus: four sides of the same length
bool isRhombus(const double &distanceAB, const double &distanceBC, const double &distanceCD, const double &distanceDA){
    return (distanceAB - distanceBC + distanceCD - distanceDA == 0);
}

// Trapezoid: only one pair of parallel sides
bool isTrapezoid(const double &slopeAB, const double &slopeBC, const double &slopeCD, const double &slopeDA){
    return ((areParallel(slopeAB,slopeCD) && !areParallel(slopeBC, slopeDA)) || (!areParallel(slopeAB,slopeCD) && areParallel(slopeBC, slopeDA)));
}

// Kite: two pairs of adjacent congruent sides
bool isKite(const double &distanceAB, const double &distanceBC, const double &distanceCD, const double &distanceDA){
    int counter = 0;
    if(distanceAB == distanceBC || distanceAB == distanceDA) counter++;
    if(distanceCD == distanceDA || distanceCD == distanceBC) counter++;
    return counter == 2;
}

void printQuadrilateralType(const std::vector<int> &vect){
    if(vect.size() != 0) {
        double distanceAB = distance(0,0,vect[0],vect[1]);
        double distanceBC = distance(vect[0],vect[1],vect[2],vect[3]);
        double distanceCD = distance(vect[2],vect[3],vect[4],vect[5]);
        double distanceDA = distance(vect[4],vect[5],0,0);
        double slopeAB = slope(0,0,vect[0],vect[1]);
        double slopeBC = slope(vect[0],vect[1],vect[2],vect[3]);
        double slopeCD = slope(vect[2],vect[3],vect[4],vect[5]);
        double slopeDA = slope(0,0,vect[4],vect[5]);
        
        if(isParallelogram(slopeAB, slopeBC, slopeCD, slopeDA)){
            if(isRectangle(slopeAB, slopeBC, slopeCD, slopeDA) && isRhombus(distanceAB, distanceBC, distanceCD, distanceDA)){
                std::cout << "square" << std::endl;
            } else if (isRectangle(slopeAB, slopeBC, slopeCD, slopeDA)){
                std::cout << "rectangle" << std::endl;
            } else if (isRhombus(distanceAB, distanceBC, distanceCD, distanceDA)){
                std::cout << "rhombus" << std::endl;
            } else std::cout << "parallelogram" << std::endl;
        } else if (isTrapezoid(slopeAB, slopeBC, slopeCD, slopeDA)){
            std::cout << "trapezoid" << std::endl;
        } else if (isKite(distanceAB, distanceBC, distanceCD, distanceDA)){
            std::cout << "kite" << std::endl;
        } else std::cout << "quadrilateral" << std::endl;
    }
    //    std::cout << "BLANK LINE" << std::endl;
}

int main(int argc, const char * argv[]) {
    vector<int> vertices;
    string line;
    while(getline(cin, line)){
        if(error1(line)){
            exitError("error 1");
//            continue;
        }
        vertices = parseToVector(line);
        if(error1(vertices)){
            exitError("error 1");
//            continue;
        }
        if(error2(vertices)){
            exitError("error 2");
//            continue;
        }
        if(error3(vertices)){
            exitError("error 3");
//            continue;
        }
        if(error4(vertices)){
            exitError("error 4");
//            continue;
        }
        printQuadrilateralType(vertices);
    }
}
