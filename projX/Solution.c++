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

int eval (int i, int j) {
    return 0;
}

// -------------
// solve
// -------------

void solve (istream& r, ostream& w) {
  // parse input
  string s;
  while (getline(r, s)) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;

    // solve
    const int v = eval(i, j);
    w << v << endl;
  }
}
