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
#include <vector>   // vector
//#include <utility>  // make_pair, pair
//#include <algorithm>  // swap
//#include <queue>     // priority_queue

#include "Solution.h"

using namespace std;

#ifdef DBG
bool DEBUG = true;
#else
bool DEBUG = false;
#endif

class State {
public:
  //State(int cycle, int cut) : _cycle_updated(cycle), _cut(cut) {};
  void cut(int cycle) { _cycle_updated = cycle; }
  bool was_cut(int cycle) const { return _cycle_updated == cycle; }

private:
  int _cycle_updated = -1;
  //  bool _cut = false;
};

/*
bool operator<(const State& lhs, const State& rhs) {
  return lhs.cuts < rhs.cuts;
}
*/

// ------------
// eval
// ------------

int eval (const int length, int sizes[3]) {
  // sort a, b, c where a is the smallest
  if (sizes[1] < sizes[0]) swap (sizes[0], sizes[1]);
  if (sizes[2] < sizes[0]) swap (sizes[0], sizes[2]);
  if (sizes[2] < sizes[1]) swap (sizes[1], sizes[2]);

  int max_cuts = 3;
  if (sizes[0] > length) {
    assert(0);
  }
  if (sizes[1] > length) {
    max_cuts = 1;
  }
  if (sizes[2] > length) {
    max_cuts = 2;
  }
  
  if (DEBUG) cout << "length=" << length << " (sorted) " << sizes[0] << " " << sizes[1] << " " << sizes[2] << endl;

  // If smallest cut is a multiple of the length, done
  if (length % sizes[0] == 0) {
    if (DEBUG) cout << "Early out" << endl;
    return length / sizes[0];
  }

  vector<State> ribbon(8001);

  // Init
  ribbon[0].cut(0);
  int max = -1;
  bool done = false;
  
  int first_updated_pos = 0;
  for (int cycle = 1; cycle < length && !done; ++cycle) {
    bool first_updated = false;

    if (DEBUG) cout << "Cycle: " << cycle << " " << endl;

    for (int pos = first_updated_pos; pos < length; ++pos) {
      if (ribbon[pos].was_cut(cycle - 1)) {
	// Only check the cuts done last cycle
	
	if (!first_updated) {
	  first_updated = true;
	  first_updated_pos = pos;
	  if (DEBUG) cout << "First update for cycle at " << pos << endl;
	}

	for (int cuts = 0; cuts < max_cuts; ++cuts) {
	  if (DEBUG) cout << "Cutting at " << pos + sizes[cuts] << endl;
	  ribbon[pos + sizes[cuts]].cut(cycle);
	}
      }
    }

    if (first_updated_pos >= length ||
	cycle >= length) {
      done = true;
    }

    // Check to see if we cut exactly at the ribbon length
    if (ribbon[length].was_cut(cycle)) {
      if (DEBUG) cout << "This cycle had a solution..checking for new max..." << endl;
      if (cycle > max) {
	if (DEBUG) cout << "Found new max " << cycle << endl;
	max = cycle;
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
