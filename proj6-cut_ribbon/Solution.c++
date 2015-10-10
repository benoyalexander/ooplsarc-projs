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
#include <queue>     // priority_queue

#include "Solution.h"

using namespace std;

#ifdef DBG
bool DEBUG = true;
#else
bool DEBUG = false;
#endif

struct State {
  State(int l, int c) : length(l), cuts(c) {};
  
  int length = 0;
  int cuts = 0;
};

bool operator<(const State& lhs, const State& rhs) {
  return lhs.cuts < rhs.cuts;
}

// ------------
// eval
// ------------

int eval (const int length, int sizes[3]) {
  // sort a, b, c where a is the smallest
  if (sizes[1] < sizes[0]) swap (sizes[0], sizes[1]);
  if (sizes[2] < sizes[0]) swap (sizes[0], sizes[2]);
  if (sizes[2] < sizes[1]) swap (sizes[1], sizes[2]);

  if (sizes[0] > length) sizes[0] = 0;
  if (sizes[1] > length) sizes[1] = 0;
  if (sizes[2] > length) sizes[2] = 0;
  
  if (DEBUG) cout << "length=" << length << " (sorted) " << sizes[0] << " " << sizes[1] << " " << sizes[2] << endl;

  // If smallest cut is a multiple of the length, done
  if (length % sizes[0] == 0) {
    if (DEBUG) cout << "Early out" << endl;
    return length / sizes[0];
  }

  int max = 0;
  int start = length;
  if (sizes[0] < length) start -= sizes[0];
  if (sizes[1] < length) start -= sizes[1];
  if (sizes[2] < length) start -= sizes[2];
  if (start % length == 0) {
    start /= sizes[0];
  } else {
    start = 0;
  }
  start = 0;
  if (DEBUG) cout << "start x at " << start << endl;

  // n = a * x + b * y + c * z
  for (int x = start; x <= (length / sizes[0]); ++x) {
    for (int y = 0; y <= (sizes[1] ? length / sizes[1] : 0); ++y) {
      int value2 = sizes[0] * x + sizes[1] * y;
      if (value2 > length) {
	//if (DEBUG) cout << "too large2 " << x << " " << y << endl;
	break;
      }
      if (value2 && (length - sizes[0] * x) % value2 != 0) break;
      for (int z = 0; z <= (sizes[2] ? length / sizes[2] : 0); ++z) {
	int value = sizes[0] * x + sizes[1] * y + sizes[2] * z;
	if (value > length) {
	  //if (DEBUG) cout << "too large3 " << x << " " << y << " " << z << endl;
	  break;
	}
	if (value == length) {
	  if ((x + y + z) > max) {
	    max = x + y + z;
	    if (DEBUG) cout << "Found new max " << max << " with " << x << " " << y << " " << z << endl;
	  }
	}
      }
    }
  }

  return max;
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
    int sizes[3];
    sin >> length >> sizes[0] >> sizes[1] >> sizes[2];

    // solve
    const int v = eval(length, sizes);
    w << v << endl;
  }
}
