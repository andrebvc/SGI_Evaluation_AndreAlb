#pragma once
#include <iostream>
using namespace std;

//////////////////////
///// Question 1 /////
//////////////////////

// The basic coordinates format
struct Point2D
{
    float x;
    float y;
    
};

// The Rectangle Struct
// Here I used 4 'Point2D' coordinates to define the rectangle
// cOne is top left, cTwo is top right, then the same pattern for cThree being bottom left and cFour, bottom right
struct Rectangle
{
    Point2D cOne;
    Point2D cTwo;
    Point2D cThree;
    Point2D cFour;

    // Constructor that takes the coordinates values and creates the Rectangle with its 4 coordinates
    Rectangle(float cOneX, float cOneY, float cTwoX, float cTwoY, float cThreeX, float cThreeY, float cFourX, float cFourY) {
        cOne.x = cOneX;
        cOne.y = cOneY;
        cTwo.x = cTwoX;
        cTwo.y = cTwoY;
        cThree.x = cThreeX;
        cThree.y = cThreeY;
        cFour.x = cFourX;
        cFour.y = cFourY;
    }
};

// Function that checks if a given point is inside a specific rectangle
bool CheckIfContainedPoint(Rectangle rectangle, Point2D point)
{
    if (point.x >= rectangle.cThree.x &&
        point.x <= rectangle.cTwo.x &&
        point.y >= rectangle.cThree.y &&
        point.y <= rectangle.cTwo.y)
    {
        return true;
    }
    return false;
}

// Function that checks if a given Rectangle 'firstRec' intersects with 'secondRec'
bool CheckIfContainedRectangle(Rectangle firstRec, Rectangle secondRec)
{
    if (CheckIfContainedPoint(secondRec, firstRec.cOne) ||
        CheckIfContainedPoint(secondRec, firstRec.cTwo) ||
        CheckIfContainedPoint(secondRec, firstRec.cThree) ||
        CheckIfContainedPoint(secondRec, firstRec.cFour)) {
        return true;
    }

    if (firstRec.cOne.x >= secondRec.cFour.x || secondRec.cOne.x >= firstRec.cFour.x) {
        return false;
    }

    if (firstRec.cOne.y <= secondRec.cFour.y || secondRec.cOne.y <= firstRec.cFour.y) {
        return false;
    }

    return true;
}

//////////////////////
///// Question 2 /////
//////////////////////

// This function divides the first number by the divisible until it cannot do it anymore
int maxDivide(int number, int divisor)
{
    while (number % divisor == 0) 
    {
        number = number / divisor;
    }
        
    return number;
}

// This function is the main driver of this algorithm,
// it divides the number by 2 as many times as it can, then by 3 and then by 5.
// After that, if the ending number is 1, then the number is a valid one.
long isAValidNumber(long number)
{
    number = maxDivide(number, 2);
    number = maxDivide(number, 3);
    number = maxDivide(number, 5);

    if (number == 1) 
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

// The main function, here you receive a position and find the associated value in it
long findRequestedNumber(int position)
{
    // The i is the index, or position, currently being analyzed
    long i = 1;
    
    int count = 1;

    while (position > count) 
    {
        i++;
        if (isAValidNumber(i)) 
        {
            count++;
        }
    }
    // At the end, return the value in the requested position
    return i;
}