#include "boundary.h"
#include <iostream>
using namespace std;

/*
    Name: Lina Chung
    File Name: boundary.cpp
    Date: 11/19
    Version: 1.1

    Implementation

*/

Boundary::Boundary(unsigned int t, unsigned int capacity):threshold(t), cap(capacity), size(0), above(0), below(0),active(true),permInactive(false){}

Boundary::Boundary():threshold(10), cap(5), size(0), above(0), below(0), active(true), permInactive(false){}

void Boundary::reset()
{
  if (active)
    return;
  above = 0;
  below = 0;
  size = 0;

}

void Boundary::revive()
{
  if (active){
    active = false;
    permInactive = true;
  }
  if (!active && !permInactive){
    active = true;
    size = 0;
  }
}

void Boundary::track(unsigned int i)
{
  if(size >= (cap*threshold))
    active = false;
  if (active)
    if (i > threshold){
      above++;
      size++;}
    else{
    below++;
    size++;
    }
}

bool Boundary::isActive()
{
  return active;
}

int Boundary::getAbove()
{
  if (permInactive)
    return -1;
  return above;
}

int Boundary::getLow()
{
  if (permInactive)
    return -1;
  return below;
}

Boundary Boundary::operator+(unsigned int val)
{
  Boundary B(threshold + val, cap);
  return B;
}

Boundary Boundary::operator+(const Boundary& other)
{
  Boundary B(threshold + other.threshold, cap);
  return B;
}

Boundary Boundary::operator++()
{
  threshold += 1;
  return *this;
}

Boundary Boundary::operator++(int x)
{
  threshold++;
  return *this;
}

Boundary Boundary::operator+=(unsigned int val)
{
  threshold += val;
  return *this;
}

Boundary Boundary::operator+=(const Boundary& other)
{
  threshold += other.threshold;
  return *this;
}

Boundary Boundary::operator-(unsigned int val)
{
  if(threshold > val)
    return Boundary(threshold - val, cap);
  return Boundary(threshold, cap);
}

Boundary Boundary::operator-(const Boundary& other)
{
  if (threshold > other.threshold)
    return Boundary(threshold - other.threshold, cap);
  return Boundary(threshold, cap);
}

Boundary Boundary::operator--()
{
  if(threshold > 1)
    threshold -= 1;
  return *this;
}

Boundary Boundary::operator--(int x)
{
  if (threshold > 1)
    threshold-=1;
  return *this;
}

Boundary Boundary::operator-=(unsigned int val)
{
  if (threshold > val)
    threshold -= val;
  return *this;
}

Boundary Boundary::operator-=(const Boundary& other)
{
  threshold -= other.threshold;
  return *this;
}

bool Boundary::operator>(const Boundary& other)
{
  return (threshold > other.threshold);
}

bool Boundary::operator>=(const Boundary& other)
{
  return(threshold >= other.threshold);
}

bool Boundary::operator<(const Boundary& other)
{
  return (threshold < other.threshold);
}

bool Boundary::operator<=(const Boundary& other)
{
    return (threshold <= other.threshold);
}

bool Boundary::operator==(const Boundary& other)
{
  return (threshold == other.threshold);
}

bool Boundary::operator!=(const Boundary& other)
{
  return (threshold != other.threshold);
}
