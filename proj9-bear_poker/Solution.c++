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
#include <vector>

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

bool mult(int i, int j) {
  for (int x = 1; x <= 3; ++x) {
    for (int y = 1; y <= 3; ++y) {
      if (i * x == j * y) {
	return true;
      }
    }
  }
  return false;
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

  vector<int> bids(players);
  getline(r, s);
  istringstream sin(s);
  for (int player = 0; player < players; ++player) {
    int j;
    sin >> j;
    bids[player] = j;
  }

  if (DEBUG) {
    cout << "Bids";
    for (int i = 0; i < players; ++i)
      cout << " " << bids[i];
    cout << endl;
  }

  for (int x = 0; x < players - 1; ++x) {
    for (int y = x+1; y < players; ++y) {
      if (!mult(bids[x], bids[y])) {
	if (DEBUG) cout << "TERM: could not find mult for " << bids[x] << " " << bids[y] << endl;
	w << "No" << endl;
	return;
      }
    }
  }

  w << "Yes" << endl;
}
