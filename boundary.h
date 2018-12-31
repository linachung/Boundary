#pragma once
#include <iostream>

/*
    Name: Lina Chung
    File Name: boundary.h
    Date: 11/19
    Version: 1.2

    Description:    An encapsulated boundary class for objects with a threshold that tracks 
                    values entered and can be returned with queries. Object becomes invalid
                    once surpassing (threshold * capacity), and is able to be revived or reset.
                    Once an object becomes deactivated however, it is no longer able to be used.

    Assumptions:    Threshold and capacity values are of type unsigned int. 
                    If user does not input any values, it is initialized in default constructor parameters.
                    User inputs value of type int when calling query function.
                    For values equal to the threshold, they are added to above counts.
                    If multiple (threshold * capacity) is equal to total count, object is inactive.  

    Interface Invariants:   Values used are of type int
                            Treshold and capacity of boundary affects functionality of object
                            Boundary object has three states (ACTIVE,INACTIVE,DEACTIVE)
                            Default constructor takes in one,two, or no arguments
                            Values can be tracked as long as boundary object is ACTIVE
                            Boundary object becomes inactive if values entered are greater than cap*thresh
                            Has option to revive a INACTIVE object to make it active

*/

class Boundary
{
private:
  
  // private data members
  bool active;
  bool permInactive;
  unsigned int threshold;
  unsigned int cap;
  int size;
  int above;
  int below; 

    /* 
    Description:    zero argument constructor allows minimal usage of boundary object
                    arg ctor assumes user will define threshold/capacity at initialization
                        -only accepts type uint
                    assuming user can keep track of boundary size and that user knows max vals tracked

    parameters:     uint thresh aka threshold val
                        uint capacity:  maximum number of tracked values allowed

    */

public:

  Boundary();
  Boundary(unsigned int thresh, unsigned int capacity);


  /* 
  
  Description:  sets tracked data to 0
                does not change threshold
                assumes user wants same threshold and capacity
                if the object is inactive, reset will do nothing
  */

  void reset();

  /*
  Description:  revives inactive Boundary if Boundary status not permenantly deactivated
                    -sets state to active true
                if Boundary is active and revive attempted, becomes permenantly deactivated

  */
  void revive();

  /* 
    Description:    tracks user number if active
                    if inactive the integer is not tracked
                    
  */

  void track(unsigned int i);

  /*
  Description:  checks state of self and returns
                always returns state even if permanently inactive
  */

  bool isActive();

  /* 
  Description:  returns int value of number tracked values above threshold
                if class deactive, returns -1
  */

  int getAbove();

  /* 
  Description:  returns int value of number tracked values below threshold
                if class deactive, returns -1
  */

  int getLow();

  /*
  Overloaded Math Operators:
    
        Description: adding/subtracting integer to boundary object only affects threshold

 */

  Boundary operator+(unsigned int val);
  Boundary operator++();
  Boundary operator++(int x);
  Boundary operator+=(unsigned int val);
  Boundary operator-(unsigned int val);
  Boundary operator--();
  Boundary operator--(int x);
  Boundary operator-=(unsigned int val);

  /* 
  Description:  when adding/subtracting boundary objects only the thresholds are added/subtracted
  */

  Boundary operator+(const Boundary& other);
  Boundary operator+=(const Boundary& other);
  Boundary operator-(const Boundary& other);
  Boundary operator-=(const Boundary& other);


  /*
  Overloaded Conparison Operators:

    Description: only threshold is compared between Boundary objects
  */

  bool operator>(const Boundary& other);
  bool operator>=(const Boundary& other);
  bool operator<(const Boundary& other);
  bool operator<=(const Boundary& other);
  bool operator==(const Boundary& other);
  bool operator!=(const Boundary& other);

};
