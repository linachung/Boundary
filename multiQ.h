#pragma once
#include <iostream>
#include "boundary.h"

/*
    Name: Lina Chung
    File Name: multiQ.h
    Date: 11/19
    Version: 1.1
    
    Assumptions:                Values of type int are used
                                State of multiQ will be updated
                                Size of array cannot be manipulated once set
                                If user wants to have more values, reset must be invoked

    Interface Invariants:       Values used are of type unsigned int
                                User size for default constructor to create array affects functionality of class
                                    -cannot add more objects than size, affects state
                                    -once size is set, it cannot be changed
                                State of MultiQ affects functionality of class
                                    -state has relationship with size and boundary status
                                Operations true, if object has been created 
                                New array of same size can be created when reset is invoked by user
                                Boundaries may be added, as long as pre conditions are met
                                MultiQ has a ACTIVE and INACTIVE state
                                    -ACTIVE as long as space left in array for more objects

    Class Invariants:           Values used are of type int
                                MultiQ can only add in array size count of objects
                                Array size of MultiQ cannot be manipulated, only a new array can be created of same size
                                MultiQ has ACTIVE and INACTIVE states
                                Adds Boundary objects to MultiQ as long as status of MultiQ is ACTIVE and object is ACTIVE
*/

class MultiQ
{

private:
  int trackedVals;
  int belowTotal;
  bool state;
  int index;
  unsigned int capacity;
  Boundary *boundList;

  /*
    initializes all private data members 
    requires users to set capacity of MultiQ or use the default
    state is set to active and assumes that users will keep track of the state changes

    Post:   state is active and index is set to 0
            default capacity is 10
            boundary array is empty 
    */

 public:
    
  MultiQ();
  MultiQ(unsigned int cap);
  ~MultiQ();
  MultiQ(const MultiQ& other);
  MultiQ operator=(const MultiQ& other);
      
    /*
    
    pre:    a boundary has been previously made by user to be tracked
            adds only if boundary object is active

    post:   if boundary is inactive or deactive, not added to MultiQ array
            if boundary active, add to array 
            index of the top is increased
            multiQ status is true if not full
    */

  void add(Boundary b);

    /*

    Description:    Removes a boundary object from the last position in array
                    Sets state to active (true) if removing excess objects.
    
    Pre:    object array is not empty
    Post:   object array may be empty and active
    
    */

  void remove();

    /*

    Description:    empties that multiQ object and sets state to active
                    assumes users may reuse multiQ object.

    post:           state active
                    index zero
                    array empty
                    no statistics tracked

    */

  void reset();

    /*
        Description:    inputs a positive integer
                        if equal or below boundary objects threshold, increments below count
                        query checks every object then resets the boundary object to reuse the objects later 
                        makes sure the Boundaries do not become inactive/invalid 
                        does not affect state of MultiQ

        pre:            active or not
        
    */

  int query(unsigned int val);

    /*
    
    Description:    checks status of array and returns
                    can be inactive or active
    
    */

  bool isActive();

    /*
    
    Description:    checks array to see if full, returns state
                    true if full,false otherwise

    */

  bool isFull();

    /* 
    
    Description:    checks to see if array is emtpy, returns state

    */

  bool isEmpty();

    /*
    
    Description:    returns average value of all counts below boundary

    */

  int getAverage();

    /*
  
    Overloaded math operators:
  
    Description:    adding two multiQ objects together:
                        - capacities are added 
                        - two arrays merged
                        - state of both objects not altered
  
  */

  MultiQ operator+(const MultiQ& other);
  MultiQ operator+=(const MultiQ& other);

  /*
  
  Description:    adding Boundary object to MultiQ object:
                    -object added to the array, but state can be affected
                    -if array is full, state becomes inactive

  pre:            active MultiQ, and valid boundary object
  post:           possible inactive MultiQ

   */

  MultiQ operator+(const Boundary& other);
  MultiQ operator+=(const Boundary& other);

  /*
  
  Comparison operators: capacity of MultiQ objects are compared
    
  */

  bool operator>(const MultiQ& other);
  bool operator>=(const MultiQ& other);
  bool operator<(const MultiQ& other);
  bool operator<=(const MultiQ& other);
  bool operator==(const MultiQ& other);
  bool operator!=(const MultiQ& other);

};
