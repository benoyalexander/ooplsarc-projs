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

int eval (int length, int a, int b, int c);


// -------------
// solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void solve (istream& r, ostream& w);

#endif // Solution_h
