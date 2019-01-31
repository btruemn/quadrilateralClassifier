//
//  functions.cpp
//  Assignment3
//
//  Created by Ben Trueman on 1/15/19.
//  Copyright © 2019 Ben Trueman. All rights reserved.
//

#include "functions.hpp"
#include <vector>
#include <vector>
#include <regex>
#include <sstream>
#include <cmath>
#include <iostream>

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
//    exit (EXIT_FAILURE);
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


//bool error3(std::vector<int> vect){
//    if(doIntersect(0, 0, vect[0], vect[1], vect[2], vect[3])) return true; //AB vs BC
//    if(doIntersect(vect[0], vect[1], vect[2], vect[3], vect[4], vect[5])) return true; //BC vs CD
//    if(doIntersect(vect[2], vect[3], vect[4], vect[5], 0,0)) return true; //CD vs DA
//    if(doIntersect(vect[4], vect[5], 0, 0, vect[0], vect[1])) return true; //DA vs AB
////    if(doIntersect(0, 0, vect[0], vect[1], vect[4], vect[5], 0,0)) return true;//AB vs CD
////    if(doIntersect(vect[0], vect[1], vect[2], vect[3], vect[4], vect[5], 0,0)) return true;//BC vs DA
//    return false;
//}

////A1 and A2 are 0 and 1 == 0,0
////B1 and B2 are 2 and 3 == vect[0] vect[1]
////C1 and C2 are 4 and 5 == vect[2] vect[3]
////D1 and D2 are 6 and 7 == vect[4] vect[5]
std::vector<double> lineLineIntersection(std::vector<int> vect) {
    // Line AB represented as a1x + b1y = c1
    double a1 = vect[1] - 0;
    double b1 = 0 - vect[2];
    double c1 = a1*(0) + b1*(0);

    // Line CD represented as a2x + b2y = c2
    double a2 = vect[5] - vect[3];
    double b2 = vect[2] - vect[4];
    double c2 = a2*(vect[2])+ b2*(vect[3]);

    double x = a1*b2;
    double y = a2*b1;
    double determinant = x - y;

    //Lines are parallel
    if (determinant == 0) {
        std::vector<double> returnPair;
        // The lines are parallel. This is simplified
        returnPair.push_back(__FLT_MAX__);
        returnPair.push_back(__FLT_MAX__);
        return returnPair;
    }
    //Lines intersect
    else {
        std::vector<double> returnPair;
        double x = (b2*c1 - b1*c2)/determinant;
        double y = (a1*c2 - a2*c1)/determinant;
        returnPair.push_back(x);
        returnPair.push_back(y);
        return returnPair;
    }
}

////"error 3" -- if any two line segments representing sides cross each other
//bool error3(std::vector<int> points) {
//
//    std::vector<double> intersection = lineLineIntersection(points);
//
//    //If they're parallel return false
//    if (intersection[0] == __FLT_MAX__ && intersection[1] == __FLT_MAX__) {
//        return false;
//    }
//    return true;
//}

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
    
//    if(error1(string)){
//        exitError("error 1");
//    }
    std::stringstream iss(string);
    std::string number;
    std::vector<int> parsedInput;
    while (iss >> number){
        parsedInput.push_back(std::stoi(number));
    }
//    if(error1(parsedInput)){
//        exitError("error 1");
//    }
//    if(error2(parsedInput)){
//        exitError("error 2");
//    }
//    if(error3(parsedInput)){
//        exitError("error 3");
//    }
//    if(error4(parsedInput)){
//        exitError("error 4");
//    }
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
