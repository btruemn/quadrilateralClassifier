//
//  functions.hpp
//  Assignment3
//
//  Created by Ben Trueman on 1/15/19.
//  Copyright © 2019 Ben Trueman. All rights reserved.
//

#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <vector>

std::vector<int> parseToVector(std::string &string);

/* Classifications of Quadrilaterals
 Parallelogram: both pairs of opposite sides are parallel
 Rectangle: four right angles
 Rhombus: four sides of the same length
 Square: both rectangle and rhombus
 Trapezoid: only one pair of parallel sides
 Kite: two pairs of adjacent congruent sides
 */
void printQuadrilateralType(const std::vector<int> &vect);

#endif /* functions_hpp */
