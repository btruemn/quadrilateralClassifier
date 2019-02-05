#!/usr/bin/env python3

import random
import sys
from os.path import join as pjoin
import string

def make_randomInt_1_to_100():
    for index in range(1, 401):
        filename = "%s.txt" % index
        path_to_file = pjoin("testFiles","randomInt",filename)
        file = open(path_to_file,"w")
        for index in range(1):
            file.write("{0} {1} {2} {3} {4} {5}".format(str(random.randint(0, 100)),str(random.randint(0, 100)),str(random.randint(0, 100)),str(random.randint(0, 100)),str(random.randint(0, 100)),str(random.randint(0, 100))))
        file.close()

def make_randomNumber_101_to_sysMaxSize():
    for index in range(1, 401):
        filename = "%s.txt" % index
        path_to_file = pjoin("testFiles", "randomLargeInt", filename)
        file = open(path_to_file, "w")
        for index in range(1):
            file.write(
                "{0} {1} {2} {3} {4} {5}".format(str(random.randint(101, sys.maxsize)), str(random.randint(101, sys.maxsize)),
                                                 str(random.randint(101, sys.maxsize)), str(random.randint(101, sys.maxsize)),
                                                 str(random.randint(101, sys.maxsize)), str(random.randint(101, sys.maxsize))))
        file.close()

def make_random_ascii_string():
    for index in range(1, 401):
        filename = "%s.txt" % index
        path_to_file = pjoin("testFiles","randomASCII",filename)
        file = open(path_to_file,"w")
        for index in range(2):
            allchar = string.printable
            randomString = "".join(random.choice(allchar) for x in range(random.randint(0, 100)))
            file.write(randomString)
        file.close()

def make_square():
    for index in range(1,2):
        filename = "testSquares.txt"
        path_to_file = pjoin("testFiles","shapes",filename)
        file = open(path_to_file,"w")
        for index in range(1,101):
            file.write("{0} 0 {0} {0} 0 {0}\n".format(str(index)))
        file.close()

def make_square_key():
    for index in range(1,2):
        filename = "squareKey.txt"
        path_to_file = pjoin("testFiles","shapes",filename)
        file = open(path_to_file,"w")
        for index in range(1,101):
            file.write("square\n")
        file.close()

def make_rectangle():
 for index in range(1,2):
        filename = "testRectangles.txt"
        path_to_file = pjoin("testFiles","shapes",filename)
        file = open(path_to_file,"w")
        x = 1
        y = 2
        while x < 100 and y < 100:
            file.write("{0} 0 {0} {1} 0 {1}\n".format(str(x),str(y)))
            x += 1
            y += 1
        x = 2
        y = 1
        while x < 100 and y < 100:
            file.write("{0} 0 {0} {1} 0 {1}\n".format(str(x),str(y)))
            x += 1
            y += 1
        file.close()

def make_rectangle_key():
    for index in range(1, 2):
        filename = "rectangleKey.txt"
        path_to_file = pjoin("testFiles", "shapes", filename)
        file = open(path_to_file, "w")
        for index in range(1, 197):
            file.write("rectangle\n")
        file.close()

# Parallelogram: both pairs of opposite sides are parallel
def make_parallelogram():
    filename = "testParallelograms.txt"
    path_to_file = pjoin("testFiles", "shapes", filename)
    file = open(path_to_file, "w")
    x1 = 3
    y1 = 0
    x2 = 4
    y2 = 2
    x3 = 1
    y3 = 2
    for i in range(97):
        file.write(str(x1) + " " + str(y1)+ " " + str(x2)+ " " + str(y2)+ " " + str(x3)+ " " + str(y3) + "\n")
        x1 += 1
        x2 += 1
        y2 += 1
        y3 += 1
    file.close()

def make_parallelogram_key():
    filename = "parallelogramKey.txt"
    path_to_file = pjoin("testFiles", "shapes", filename)
    file = open(path_to_file, "w")
    for i in range(97):
        file.write("parallelogram\n")
    file.close()

# Rhombus: four sides of the same length
# Trapezoid: only one pair of parallel sides
# Kite: two pairs of adjacent congruent sides

make_randomInt_1_to_100()
make_randomNumber_101_to_sysMaxSize()
make_random_ascii_string()
make_square()
make_square_key()
make_rectangle()
make_rectangle_key()
make_parallelogram()
make_parallelogram_key()
