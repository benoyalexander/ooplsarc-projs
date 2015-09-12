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
#include <map>      // map
#include <vector>   // vector

using namespace std;
typedef map< int, map< int, int > > TypeGraph;

// ------------
// eval
// ------------

string eval (int verts, const TypeGraph& graph);


// -------------
// solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void solve (istream& r, ostream& w);

#endif // Solution_h
