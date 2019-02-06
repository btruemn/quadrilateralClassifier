//
//  main.cpp
//  assignment3
//
//  Created by Alex Moyle on 1/15/19.
//  Copyright © 2019 Alex Moyle. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <math.h>

using namespace std;

#define pdd pair<double, double>

//error3 - if lines intersect
struct Point
{
    double x;
    double y;
};

bool inputError(string s) {
    size_t found = s.find_first_not_of("0123456789 ");
    return (found != string::npos);
}
double calculateLength (double x1, double y1, double x2, double y2){
    double distance = 0;
    
    distance = sqrt(pow((x2 - x1) , 2) + pow((y2 - y1) , 2));
    return distance;
}

void exitError(string error) {
    std::cout << "error 1" << std::endl;
    exit (EXIT_FAILURE);
}
//Returns a vector of doubles with side 1 in the [0] all the way up to 4
vector<double> findAllLengths(const vector<double> &al) {
    
    if (al.size() != 8) exitError("error 1");
    
    for (double i : al) {
        if (i < 0 || i > 100) exitError("error 1");
    }
    //originx and originy are 0 and 1
    //x1 and y1 are 0 and 1
    //x2 and y2 are 2 and 3
    //x3 and y3 are 4 and 5
    double side1 = calculateLength(al[0], al[1], al[2], al[3]);
    double side2 = calculateLength(al[2], al[3], al[4], al[5]);
    double side3 = calculateLength(al[4], al[5], al[6], al[7]);
    double side4 = calculateLength(al[6], al[7], al[0], al[1]);
    
    vector<double> allLengths;
    allLengths.push_back(side1);
    allLengths.push_back(side2);
    allLengths.push_back(side3);
    allLengths.push_back(side4);
    
    return allLengths;
}

double findSlope(double x1, double y1, double x2, double y2) {
    double vy = y2 - y1;
    double vx = x2 - x1;
    if (vy == 0 || vx == 0) {
        return 0;
    }
    double slope = vy / vx;
    return slope;
}

vector<double> findAllSlopes(const vector<double> &al) {
    
    //originx and originy are 0 and 1
    //x1 and y1 are 0 and 1
    //x2 and y2 are 2 and 3
    //x3 and y3 are 4 and 5
    double slopeOA = findSlope(al[0], al[1], al[2], al[3]);
    double slopeAB = findSlope(al[2], al[3], al[4], al[5]);
    double slopeBC = findSlope(al[4], al[5], al[6], al[7]);
    double slopeCO = findSlope(al[6], al[7], al[0], al[1]);
    
    vector<double> allSlopes;
    allSlopes.push_back(slopeOA);
    allSlopes.push_back(slopeAB);
    allSlopes.push_back(slopeBC);
    allSlopes.push_back(slopeCO);
    
    return allSlopes;
}

bool areLengthsEqual(vector<double> &allLengths) {
    double len1 = allLengths[0];
    double len2 = allLengths[1];
    double len3 = allLengths[2];
    double len4 = allLengths[0];
    if (len1 == len2 && len1 == len3 && len1 == len4) {
        return true;
    }
    return false;
}

bool areSlopesEqual(vector<double> &allSlopes) {
    double s1 = allSlopes[0];
    double s2 = allSlopes[1];
    double s3 = allSlopes[2];
    double s4 = allSlopes[3];
    if (s1 == s2 && s1 == s3 && s1 == s4) {
        return true;
    }
    return false;
}

bool isParallelogram(vector<double> &allSlopes) {
    
    if (allSlopes[0] == allSlopes[2] && allSlopes[1] == allSlopes[3] && allSlopes[0] != allSlopes[1]) {
        return true;
    }
    return false;
}

bool isRectangle(vector<double> &allLengths, vector<double> &allSlopes) {
    
    if (allLengths[0] == allLengths[2] && allLengths[1] == allLengths[3] && areSlopesEqual(allSlopes)) {
        return true;
    }
    return false;
}

bool isRhombus(vector<double> &allLengths, vector<double> &allSlopes) {
    
    if (!isParallelogram(allSlopes)) {
        return false;
    }
    if ((allSlopes[0] != allSlopes[1]) && areLengthsEqual(allLengths)) {
        return true;
    }
    return false;
}

bool isKite(vector<double> &allLengths) {
    
    int counter = 0;
    if (allLengths[0] == allLengths[1] || allLengths[0] == allLengths[3]) counter++;
    if (allLengths[1] == allLengths[2] || allLengths[2] == allLengths[3]) counter++;
    if (counter == 2) {
        return true;
    }
    return false;
}

bool isTrapezoid(vector<double> &allSlopes) {
    bool evenParallel = allSlopes[0] == allSlopes[2];
    bool oddParallel = allSlopes[1] == allSlopes[3];
    
    if ((evenParallel && !oddParallel) || (!evenParallel && oddParallel)) {
        return true;
    }
    return false;
}

bool isSquare(vector<double> &allLengths, vector<double> &allSlopes) {
    
    int counter = 0;
    if (areLengthsEqual(allLengths)) counter++;
    if (areSlopesEqual(allSlopes)) counter++;
    if (counter == 2) {
        return true;
    }
    return false;
}

//Only outputs one line of data at a time
vector<double> parseQuadData(const string input) {
    
    if (inputError(input)) {
        cout << "error 1" << endl;
        exit(EXIT_FAILURE);
    }
    istringstream iss(input);
    
    vector<string> results;
    vector<double> parsedLine;
    
    for (string input; iss>>input;)
        results.push_back(input);
    parsedLine.push_back(0.0);
    parsedLine.push_back(0.0);
    for (int i = 0; i < results.size(); i++) {
        parsedLine.push_back(stod(results[i]));
    }
    return parsedLine;
}

//"error 1" -- if the line contains the wrong number of points, contains invalid characters, has coordinates out of the
//range 0..100, or otherwise fails to describe three points (six integer values)
bool isError1(const string numbers) {
    
    vector<double> input = parseQuadData(numbers);
    for (double d : input) {
        if (d > 100 || d < 0) {
            return true;
        }
    }
    if (input.size() != 8) {
        return true;
    }
    return false;
}

//"error 2" -- if any two points coincide
bool isError2(vector<double> points) {
    vector<double> A = {points[0], points[1]};
    vector<double> B = {points[2], points[3]};
    vector<double> C = {points[4], points[5]};
    vector<double> D = {points[6], points[7]};
    
    if (A == B || A == C || A == D || B == C || B == D || C == D) {
        return true;
    }
    return false;
}

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

bool isError3(vector<double> vect){
    struct Point A = {vect[0], vect[1]}, B = {vect[2], vect[3]}, C = {vect[4], vect[5]}, D = {vect[6], vect[7]};
    //only opposite lines can intersect
    if(doIntersect(A, B, C, D)) return true;
    if(doIntersect(B, C, D, A)) return true;
    return false;
}

bool collinear(int x1, int y1, int x2, int y2, int x3, int y3) {
    int a = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2);
    if (a == 0) {
        return true;
    }
    return false;
}

//"error 4" -- if any three points are colinear
//x0 and y0 are 0 and 1
//x1 and y1 are 2 and 3
//x2 and y2 are 4 and 5
//x3 and y3 are 6 and 7
bool isError4(vector<double> d) {
    
    bool abc = collinear(d[0], d[1], d[2], d[3], d[4], d[5]);
    bool bcd = collinear(d[2], d[3], d[4], d[5], d[6], d[7]);
    bool cda = collinear(d[4], d[5], d[6], d[7], d[0], d[1]);
    bool dab = collinear(d[6], d[7], d[0], d[1], d[2], d[3]);
    
    if (abc == true || bcd == true || cda == true || dab == true) {
        return true;
    }
    return false;
}

void determineShape(vector<double> &allLengths, vector<double> &allSlopes) {
    if (isSquare(allLengths, allSlopes)) {
        cout << "square" << endl;
    } else if (isRhombus(allLengths, allSlopes)) {
        cout << "rhombus" << endl;
    } else if (isRectangle(allLengths, allSlopes)) {
        cout << "rectangle" << endl;
    } else if (isParallelogram(allSlopes)) {
        cout << "parallelogram" << endl;
    } else if (isTrapezoid(allSlopes)) {
        cout << "trapezoid" << endl;
    } else if (isKite(allLengths)) {
        cout << "kite" << endl;
    } else {
        cout << "quadrilateral" << endl;
    }
}

int main(int argc, const char * argv[]) {
    
    while (!cin.eof()) {
        string line;
        vector<double> coordinates;
        while (getline(cin, line)) {
            coordinates = parseQuadData(line);
            vector<double> coorLen = findAllLengths(coordinates);
            vector<double> allSlopes = findAllSlopes(coordinates);
            if (isError1(line)) {
                cout << "error 1" << endl;
                exit(EXIT_FAILURE);
            }
            if (isError2(coordinates)) {
                cout << "error 2" << endl;
                exit(EXIT_FAILURE);
            }
            if (isError4(coordinates)) {
                cout << "error 4" << endl;
                exit(EXIT_FAILURE);
            }
            if (isError3(coordinates)) {
                cout << "error 3" << endl;
                exit(EXIT_FAILURE);
            }
           

            determineShape(coorLen, allSlopes);
        }
    }
    return 0;
}
