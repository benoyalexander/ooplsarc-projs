// --------------------------
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Solution_h
#define Solution_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair

using namespace std;

// ------------
// eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int eval (int i, int j);


// -------------
// solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void solve (istream& r, ostream& w);

#endif // Solution_h
