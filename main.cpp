//
//  main.cpp
//  Assignment4
//
//  Created by Ben Trueman on 1/15/19.
//  Copyright © 2019 Ben Trueman. All rights reserved.
//

//#include "functions.hpp"
#include <iostream>
#include <regex>
#include <set>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;
#define pdd pair<int, int>

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
bool isError1(std::string s){
    size_t found = s.find_first_not_of("0123456789 ");
    return (found != std::string::npos);
}

//must contain 6 ints in range 0 to 100
bool isError1(std::vector<int> vect){
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
bool isError2(std::vector<int> vect){
    std::vector<int> A = {0,0};
    std::vector<int> B = {vect[0],vect[1]};
    std::vector<int> C = {vect[2],vect[3]};
    std::vector<int> D = {vect[4],vect[5]};
    
    if(A == B || A == C || A == D || B == C || B == D || C == D){
        return true;
    }
    return false;
}

//error3 - if lines intersect - taken from https://codea.io/talk/discussion/5930/line-segment-intersection
struct Point
{
    int x;
    int y;
};

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    
    return false;
}

// To find orientation of ordered triplet (p, q, r).
// The function returns following values
// 0 --> p, q and r are colinear
// 1 --> Clockwise
// 2 --> Counterclockwise
int orientation(Point p, Point q, Point r)
{
    // See 10th slides from following link for derivation of the formula
    // http://www.dcs.gla.ac.uk/~pat/52233/slides/Geometry1x1.pdf
    int val = (q.y - p.y) * (r.x - q.x) -
    (q.x - p.x) * (r.y - q.y);
    
    if (val == 0) return 0;  // colinear
    
    return (val > 0)? 1: 2; // clock or counterclock wise
}

// The main function that returns true if line segment 'p1q1'
// and 'p2q2' intersect.
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    
    // General case
    if (o1 != o2 && o3 != o4)
        return true;
    
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    
    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    
    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    
    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
    
    return false; // Doesn't fall in any of the above cases
}

bool isError3(std::vector<int> vect){
    struct Point A = {0,0}, B = {vect[0], vect[1]}, C = {vect[2], vect[3]}, D = {vect[4], vect[5]};
    //only opposite lines can intersect
    if(doIntersect(A, B, C, D)) return true;
    if(doIntersect(B, C, D, A)) return true;
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
        try{
            parsedInput.push_back(std::stoi(number));
        }catch(const std::out_of_range& e){
            std::cout << "error 1" << std::endl;
            exit (EXIT_FAILURE);
        }
    }
    return parsedInput;
}

//slope = (Y2 - Y1)/(X2 - X1)
double slope(const int &xA, const int &yA, const int &xB, const int &yB){
//    if(yB - yA == 0 || xB - xA == 0) return 0; //return zero for horizontal or vertical lines
    double slopeAB = (double)(yB - yA)/(double)(xB - xA);
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
        if(isError1(line)){
            exitError("error 1");
        }
        vertices = parseToVector(line);
        if(isError1(vertices)){
            exitError("error 1");
        }
        assert(vertices.size() == 6);
        for(int i: vertices){
            assert(i <= 100 && i >= 0);
        }
        if(isError2(vertices)){
            exitError("error 2");
        }
        if(isError3(vertices)){
            exitError("error 3");
        }
        if(error4(vertices)){
            exitError("error 4");
        }
        printQuadrilateralType(vertices);
    }
}
