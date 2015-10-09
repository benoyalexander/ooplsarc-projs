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
#include <vector>
#include <map>
#include <list>

using namespace std;

typedef vector<vector<int> > TypeBallots; // [Ballot#][Vote#]
typedef vector<list<int> > TypeVotes; // [Candidate][List of Ballot indexes]
typedef vector<string> TypeCandidates;


// ------------
// eval
// ------------
void eval (int num_ballots, const TypeBallots& ballots, int num_candidates, const TypeCandidates& str_candidates);


// -------------
// solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void solve (istream& r, ostream& w);

#endif // Solution_h
