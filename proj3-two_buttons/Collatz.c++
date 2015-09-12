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
#include <utility>  // make_pair, pai

//#include <queue>    // queue
//#include <pair>     // pair
#include <limits>

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

void mathematical(int n, int m, int& min_steps) {
  while (n != m) {
    if (n > m) {
      // Blue button -1 on n OR +1 on m
      ++m;
      ++min_steps;
    } else {
      // Red button *2 on n OR /2 on m
      if ((m & 0x1) == 0) { // Even
	m >>= 1;
	++min_steps;
      } else { // Odd
	m = (m + 1) >> 1;
	++++min_steps; // 2 buttons pressed
      }
    }
  }
}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
  //  queue<pair<int, int>> state; // current, goal

  //int min_steps = 0;
  //mathematical(i, j, min_steps);
  return min_steps;
}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i) {
  w << i << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, v);}}
