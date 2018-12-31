#pragma once
#include "boundary.h"
#include <iostream>

/*
    Name: Lina Chung
    File Name: range.h
    Date: 11/19
    Version: 1.1

    Description:    USES 2 BOUNDARY OBJECTS to track the number of queries that 
                    fall above, within, and below its encapsulated range [x,y] 

    Assumptions:  
                    Both boundaries are of same size (cap), just different thresholds.
                    If user tracks value equal to min range value, it is counted as within.
                    If user tracks value equal to max range value, it is counted as above bounds.

    Interface Invariants:       User can track values of type unsigned int
                                Threshold of boundary objects does not affects functionality
                                Public functions true as long as constructor invoked
                                Range class does not have a state, can add in as many values as you want

    Class Invariants:           Values of type int are used to set range and to track
                                Only two boundary objects are used
                                If one of the boundary objects become inactive they become revived
                                You may add in as many values as you want into object range
                                There is no state for Range class                            

*/

class Range
{

private:

  Boundary lower;
  Boundary upper;

  /*
  
  Description:      checks both object states and if inactive, sets to active
                    done so client does not have to track state change of objects

  pre:              inactive lower and/or upper objects
  post:             active lower and upper objects 

  */

  void checkActive();
  
 public:

    /*

    Description:    constructor will initialize two boundary objects with default values or client values
                    initial state of objects are assumed active and valid

    pre:            unitialized
    post:           valid state
    
    */

  Range(unsigned int low, unsigned int up);
  Range();

    /*

    Description:    intakes given uint val and uses both objects to track if value is equivalent
                        to one of the boundaries, then counted below the boundary
                    after given value tracked, a boudary objects states are checked

    pre:            state valid
    post:           state valid
    
    */

  void track(unsigned int i);

    /* 

    Description:    returns amount of tracks above upper boundary of set range

    pre:            valid object
    */

  int getAbove();

    /* 
    
    Description:    returns amount of tracks within lower boundary and upper boundary of set range

    pre:            valid object
    */

  int getWithin();

    /*
    Description:    returns amount of tracks below lower boundary of set range

    pre:            valid object
    
    */

  int getBelow();

    /*

    Math operators:

        Description:    addition of integer values does not support negative vals
                        integer vals will increase range of the boundaries
                            -increments and decrements only affect upper boundary by decreaseing thresh
                        addition of integer will increase upper threshold
                        subtraction will not lower threshold below zero, only eeffects the upper boundary threshold
                        cannot add range object to integer.
    */

  Range operator+(unsigned int val);
  Range operator++();
  Range operator++(int x);
  Range operator+=(unsigned int val);
  Range operator-(unsigned int val);
  Range operator--();
  Range operator--(int x);
  Range operator-=(unsigned int val);

    /*

    Description:    when adding/subtracting two range objects
                        -lower boundaries either subtracted/added together
                            and upper boundary objects also either added/subtracted together
    */

  Range operator+(const Range& other);
  Range operator+=(const Range& other);
  Range operator-(const Range& other);
  Range operator-=(const Range& other);
  
  /*

  comparison operators:

        Description:    when comparing two range objects, only range (the difference between upper
                        and lower threshold) compared
    
    */

  bool operator>(const Range& other);
  bool operator>=(const Range& other);
  bool operator<(const Range& other);
  bool operator<=(const Range& other);
  bool operator==(const Range& other);
  bool operator!=(const Range& other);

};
