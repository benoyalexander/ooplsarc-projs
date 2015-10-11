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

void shrink(int& j) {
  while (j % 2 == 0) j = j >> 1;
  while (j % 3 == 0) j = j / 3;
}

void solve (istream& r, ostream& w) {
  // parse input
  string s;
  int players;
  {
    getline(r, s);
    istringstream sin(s);
    sin >> players;
    if (DEBUG) cout << "Num players " << players << endl;
  }

  getline(r, s);
  istringstream sin(s);
  int first;
  sin >> first;
  shrink(first);
  
  for (int player = 0; player < players - 1; ++player) {
    int j;
    sin >> j;
    shrink(j);

    if (first != j) {
      w << "No" << endl;
      return;
    }
  }

  w << "Yes" << endl;
}
