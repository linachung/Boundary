#include <iostream>
#include "multiQ.h"
#include "boundary.h"
using namespace std;

/*
    Name: Lina Chung
    File Name: multiQ.cpp
    Date: 11/19
    Version: 1.1
    
    Implementation Invariants:  Array used is implemented as a stack for remove and add functions, and has a int top value
                                    - top is index of last added object (essentially giving count of objects added)
                                    - remove has last object entered removed, top index decreased
                                    - add sets boundary to be added to the top index
                                Default constructor takes one or no arguments, initializes size of array if user does not
                                Has a HOLDS-A relationship with boundary class
                                INACTIVE boundary cannot be added to multiQ
                                MultiQ becomes INACTIVE if array is full, or if a inactive boundary exists in array
                                Array size once set in constructor cannot be changed, only new arrays of same size can be made
                                Using pointers for dynamic allocation

*/

MultiQ::MultiQ(): trackedVals(0), belowTotal(0), state(true), index(0), capacity(1), boundList(boundList = new Boundary[capacity]){}

MultiQ::MultiQ(unsigned int cap):trackedVals(0), belowTotal(0), state(true), index(0), capacity(cap), boundList(boundList = new Boundary[capacity]){}

MultiQ::~MultiQ()
{
  delete[] boundList;
  boundList = 0;
}

MultiQ::MultiQ(const MultiQ& other)
{
  trackedVals = other.trackedVals;
  belowTotal = other.belowTotal;
  state = other.state;
  index = other.index;
  capacity = other.capacity;

  boundList = new Boundary[capacity];
  for (int i = 0; i < index; i++){
    boundList[i] = other.boundList[i];
  }
}

MultiQ MultiQ::operator=(const MultiQ& other)
{
  if (this != &other){
    trackedVals = other.trackedVals;
    belowTotal = other.belowTotal;
    state = other.state;
    index = other.index;
    capacity = other.capacity;
    boundList = new Boundary[capacity];
    for (int i = 0; i < index; i++){
      boundList[i] = other.boundList[i];
    }
  }
  return *this;
}

void MultiQ::add(Boundary item)
{
  if (!item.isActive() || !state)
    return;
  if(index == capacity-1){
    state = false;
    return;}
  item.reset();
  boundList[index] = item;
  index++;
}

void MultiQ::remove()
{
  if (index > 0)
    index--;
  if (index < capacity-1)
    state = true;
}

void MultiQ::reset(){
  delete[] boundList;
  boundList = 0;
  index = 0;
  boundList = new Boundary[capacity];
  state = true;
  belowTotal = 0;
  trackedVals = 0;
}

int MultiQ::query(unsigned int val)
{
  if(!state)
        return -1;
  int below = 0;
  for (int i = 0; i < index; i++){
    boundList[i].track(val);
    below += boundList[i].getLow();
    boundList[i].reset();
  }
  trackedVals++;
  belowTotal += below;
  return below;
}

bool MultiQ::isActive()
{
  return state;
}

bool MultiQ::isFull()
{
  return (index == capacity-1);
}

bool MultiQ::isEmpty()
{
  return (index == 0);
}

int MultiQ::getAverage()
{
  if (trackedVals > 0)
    return (belowTotal/trackedVals);
  return 0;
}

MultiQ MultiQ::operator+(const MultiQ& other)
{
  unsigned int cap = other.capacity + capacity;
  int total = index + other.index;
  MultiQ temp(cap);
  if (total == 0){
    return temp;
  }
  for (int i = 0; i < total; i++){
    if (i < index)
      temp.boundList[i] = boundList[i];
    if (i >= index)
      temp.boundList[i] = other.boundList[i-index];
  }
  for (int i = index; i < other.index; i++)
    return temp;
}

MultiQ MultiQ::operator+(const Boundary& other)
{
  MultiQ temp(capacity);
  temp = *this;
  temp.add(other);
  return temp;
}

MultiQ MultiQ::operator+=(const MultiQ& other)
{
  *this = *this + other;
  return *this;
}

MultiQ MultiQ::operator+=(const Boundary& other)
{
  this->add(other);
  return *this;
}

bool MultiQ::operator>(const MultiQ& other)
{
  return (capacity > other.capacity);
}

bool MultiQ::operator>=(const MultiQ& other)
{
  return (capacity >= other.capacity);
}

bool MultiQ::operator<(const MultiQ& other)
{
  return (capacity < other.capacity);
}

bool MultiQ::operator<=(const MultiQ& other)
{
  return (capacity <= other.capacity);
}

bool MultiQ::operator==(const MultiQ& other)
{
  return (capacity == other.capacity);
}

bool MultiQ::operator!=(const MultiQ& other)
{
  return (capacity != other.capacity);
}
