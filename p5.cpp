#include <ctime>
#include <cstdlib>
#include <iostream>
#include "MultiQ.h"
#include "Boundary.h"
#include "Range.h"
using namespace std;

/*
  Author: Lina Chung
  File: p5.cpp
  Date: 11/19
  Version: 1.0

  Description:  Tester file to test Boundary Range and MultiQ classes and their overloaded operators

  Grade: 90/100
  
*/

// Functions to test the different operators in Boundary, Range, MultiQ
void generalTest(unsigned int t1, unsigned int t2, unsigned int t3, unsigned int low, unsigned int high);
void operatorTest(unsigned int high, unsigned int low, unsigned int t);
void boundaryOpTest(unsigned int high, unsigned int low, unsigned int test_val);
void rangeOpTest(unsigned int high, unsigned int low, unsigned int t);
void multiqOpTest(unsigned int high, unsigned int low, unsigned int t);
void testAll(int SIZE, unsigned int low, unsigned int high);

int Main()
{
  srand(time(NULL));
  const int SIZE = 50;
  unsigned int rand1 = rand() % 100;
  unsigned int rand2 = rand() % 10;
  unsigned int rand3 = rand() % 1;

  const unsigned int low = 5;
  const unsigned int high = 50;

  cout << "Testing functionality of Boundary, Range, and MultiQ classes:\n";
  generalTest(rand1, rand2, rand3, low, high);

  cout << "\nTesting overloaded operators:";
  operatorTest(high,low, rand3);

  return 0;

}

void generalTest(unsigned int thresh1, unsigned int thresh2, unsigned int thresh3, unsigned int low, unsigned int high)
{

  Boundary b(thresh2, high);
  Range r(low, high);
  MultiQ m(low);

  for (int i = 0; i < low; i++){
    b.track(thresh1);
    b.track(thresh2);
  }

  cout << "Below count: " << b.getLow() << "\nAbove count: " << b.getAbove() << endl;
  for (int i = 0; i < high; i++){
    r.track(i);
    r.track(thresh3);
  }

  m.add(b);
  m.query(thresh1);
  cout << m.getAverage() << endl;

}

void operatorTest(unsigned int high, unsigned int low, unsigned int thresh)
{

  cout << "\n...Testing Boundary Operators..." << endl;
  boundaryOpTest(high, low, thresh);
  cout << "\n...Testing Range Operators..." << endl;
  rangeOpTest(high, low, thresh);
  cout << "\n...Testing MultiQ Operators..." << endl;
  multiqOpTest(high, low, thresh);

}

void boundaryOpTest(unsigned int high, unsigned int low, unsigned int val)
{

  Boundary b1(high, low*high), b2(low, low*high);
  Boundary equal1(low, low), equal2(low,high);

  if (b1 > b2)
    cout << "\nBoundary object 1 has greater threshold than Boundary 2";
  if (b2 < b1)
    cout << "\nBoundary object 2 has smaller threshold than Boundary 1";
  if(b2 != b1)
    cout << "\nBoundary 2 is not equal to Boundary 1";
  if (equal1 == equal2)
    cout << "\nBoth boundaries have equal thresholds";
  if (b2 == b1)
    cout << "\n!!!!!ERROR!!!!! Two boundary objects that have different thresholds have been found ==";

  cout<< "\n Now testing Boundary operators!";
  Boundary b3;
  b3 = b1 + val;
  b3 = b1 + b2;
  b3 += b1;
  b3++;
  b3 = b1 - val;
  b3 = b1 - b2;
  b3 -= val;
  b3--;

}

void rangeOpTest(unsigned int high, unsigned int low, unsigned int t)
{

  Range r1(low,high);
  Range r2(low*t, high*t);
  Range eRange(low, high);
  if (r1 < r2)
    cout << "Range object 1 has greater range than Range object 2" << endl;
  if (r2 > r1)
    cout << "\nRange object 2 has smaller range than Range object 1";
  if(r2 != r1)
    cout << "\nRange object 2 is not equal to Range object 1";
  if (eRange == r1)
    cout << "\nRanges have equal range";
  if (r1 == r2)
    cout << "\n!!!!! ERROR !!!!! Two range objects should not be equal";

  cout<< "\n Now testing Range operators!";
  Range R;
  R = r1 + r2;
  R = r1 - t;
  R++;
  R += t;
  R += r1;
  --R;
  R -= t;
  R -= r1;

}

void multiqOpTest(unsigned int high, unsigned int low, unsigned int t)
{

  MultiQ m1(low);
  MultiQ m2(high);
  MultiQ mEqual(low);
  Boundary bObj(high, low);

  cout << "Testing comparison operators";
  if (m1 < m2)
    cout << "\nRange object 1 has greater range than Range object 2";
  if (m2 > m1)
    cout << "\nRange object 2 has smaller range than Range object 1";
  if(m2 != m1)
    cout << "\nRange object 2 is not equal to Range object 1";
  if (mEqual == m1)
    cout << "\nBoth MultiQ objects have equal capacities";

  cout<< "\n Now testing MultiQ operators!";
  MultiQ M(high*low);
  M = m1 + m2;
  M = m1 + bObj;
  M += bObj;
  M += m1;

}

void testAll(int size, unsigned int low, unsigned int high)
{

  Boundary arrB[size];
  Range arrR[size];
  MultiQ arrM[size];

  for (int i = 0; i < size; i++){
    arrB[i].track(low);
    arrB[i].track(high);
    if (!arrB[i].isActive())
      arrB[i].revive();
    arrB[i].reset();
    arrM[i].add(arrB[i]);
  }

  for (int i = 0; i < size; i++){
    arrR[i].track(low);
    arrR[i].track(high);
    if (i >= size - 3)
      cout << arrR[i].getWithin() <<endl;
  }

}