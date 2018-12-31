#include "boundary.h"
#include "range.h"
#include <iostream>
using namespace std;

/*
    Name: Lina Chung
    File Name: range.cpp
    Date: 11/19
    Version: 1.1

    Implementation Invariants:  Boundary object queries used to find queries for Range class
                                Upper and lower range values are set by user or set to default
                                Boundary low and high thresholds are set by range values
                                There is no state for range object
                                Range object does not change, only boundary object's upper and lower counts change
                                HAS-A relationship with Boundary class

*/
Range::Range()
{
  lower = Boundary(2, 2*10);
  upper = Boundary(5, 2*10);
}

Range::Range(unsigned int low, unsigned int up)
{
  lower = Boundary(low, low*up);
  upper = Boundary(up, up*low);
}

void Range::track(unsigned int x)
{
  if(lower.isActive() && upper.isActive()){
    lower.track(x);
    upper.track(x);
    checkActive();
  }
}

void Range::checkActive()
{
  if (!lower.isActive())
    lower.revive();
  if (!upper.isActive())
    upper.revive();
}

int Range::getAbove()
{
  return upper.getAbove();
}

int Range::getWithin()
{
  return upper.getLow() - lower.getLow();
}

int Range::getBelow()
{
  return lower.getLow();
}


Range Range::operator+(const Range& other)
{
  Range R;
  R.lower  = lower + other.lower;
  R.upper = upper + other.upper;
  return R;
}

Range Range::operator+(unsigned int val)
{
  Range R;
  R.lower = lower;
  R.upper = upper + val;
  return R;
}

Range Range::operator++()
{
  upper++;
  return *this;
}

Range Range::operator++(int x)
{
  upper++;
  return *this;
}

Range Range::operator+=(unsigned int val)
{
  upper += val;
  return *this;
}

Range Range::operator+=(const Range& other)
{
  upper += other.upper;
  return *this;
}

Range Range::operator-(const Range& other)
{
  Range R;
  R.upper = upper - other.upper;
  R.lower = lower - other.lower;
  return R;
}

Range Range::operator-(unsigned int val)
{
  Range R;
  R.upper = upper - val;
  R.lower = lower;
  return R;
}

Range Range::operator--()
{
  upper--;
  return *this;
}

Range Range::operator--(int x)
{
  upper--;
  return *this;
}

Range Range::operator-=(unsigned int val)
{
  upper -= val;
  return *this;
}

Range Range::operator-=(const Range& other)
{
  upper -= other.upper;
  return *this;
}

bool Range::operator>(const Range& other)
{
  Boundary temp_low = other.lower;
  Boundary temp_up = other.upper;
  return ((upper - lower) > (temp_up - temp_low));
}

bool Range::operator>=(const Range& other)
{
  Boundary temp_low = other.lower;
  Boundary temp_up = other.upper;
  return ((upper - lower) >= (temp_up - temp_low));
}

bool Range::operator<(const Range& other)
{
  Boundary temp_low = other.lower;
  Boundary temp_up = other.upper;
  return ((upper - lower) < (temp_up - temp_low));
}

bool Range::operator<=(const Range& other)
{
  Boundary temp_low = other.lower;
  Boundary temp_up = other.upper;
  return ((upper - lower) <= (temp_up - temp_low));
}

bool Range::operator==(const Range& other)
{
  Boundary temp_low = other.lower;
  Boundary temp_up = other.upper;
  return ((upper - lower) == (temp_up - temp_low));
}

bool Range::operator!=(const Range& other)
{
  Boundary temp_low = other.lower;
  Boundary temp_up = other.upper;
  return ((upper - lower) != (temp_up - temp_low));
}
