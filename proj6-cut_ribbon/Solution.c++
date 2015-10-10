// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair
#include <algorithm>  // swap

#include "Solution.h"

using namespace std;

#ifdef DBG
bool DEBUG = true;
#else
bool DEBUG = false;
#endif


// ------------
// eval
// ------------

int eval (int length, int a, int b, int c) {
  // sort a, b, c where a is the smallest
  if (b < a) swap (a, b);
  if (c < a) swap (a, c);
  if (DEBUG) cout << "length=" << length << " (sorted) " << a << " " << b << " " << c << endl;

  int cuts = (length - b - c) / a;  // Get as close as we can using smallest
  if (DEBUG) cout << "starting at cuts=" << cuts;

  return cuts;
}

// -------------
// solve
// -------------

void solve (istream& r, ostream& w) {
  // parse input
  string s;
  while (getline(r, s)) {
    istringstream sin(s);
    int length;
    int a;
    int b;
    int c;
    sin >> length >> a >> b >> c;

    // solve
    const int v = eval(length, a, b, c);
    w << v << endl;
  }
}
