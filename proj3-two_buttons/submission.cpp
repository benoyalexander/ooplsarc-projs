// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <string>   // string
#include <utility>  // pair

using namespace std;

// ------------
// collatz_read
// ------------

/**
 * read two ints
 * @param s a string
 * @return a pair of ints, representing the beginning and end of a range, [i, j]
 */
pair<int, int> collatz_read (const string& s);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
int collatz_eval (int i, int j);

// -------------
// collatz_print
// -------------

/**
 * print three ints
 * @param w an ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (ostream& w, int v);

// -------------
// collatz_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void collatz_solve (istream& r, ostream& w);

int cycle_length (int n);

#endif // Collatz_h
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


// ------------
// evaluate
// ------------

bool debug = true;
void evaluate (int& current, const int& goal, int steps, int& min_steps) {
  // Exit conditions
  if (current == goal) {
    // Found solution
    if (steps < min_steps) {
      min_steps = steps;
      return;
    }
  }
  if (current < 1 || steps > min_steps) {
    return;
  }

  //if (debug) cout << "NOW " << current << " " << goal << " " << steps << endl;
  if (current > goal) {
    // Blue button (sub by 1)
    current -= 1;
    if (debug) cout << "TRY-1 " << current << " " << goal << " " << steps << endl;
    evaluate(current, goal, steps + 1, min_steps);
    current += 1;
  } else {
    if ((current << 2) <= (goal << 1)) {
      // Red button (mult by 2)
      current <<= 1;
      if (debug) cout << "TRY*2 " << current << " " << goal << " " << steps << endl;
      evaluate(current, goal, steps + 1, min_steps);
      current >>= 1;
    }

    // Still might be faster to press Blue, then later *2
    // Blue button (sub by 1)
    current -= 1;
    if (debug) cout << "TRY-1 " << current << " " << goal << " " << steps << endl;
    evaluate(current, goal, steps + 1, min_steps);
    current += 1;
  }
}

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
	++++min_steps;
      }
    }
  }
}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
  //  queue<pair<int, int>> state; // current, goal

  //int min_steps = numeric_limits<int>::max();
  //evaluate(i, j, 0, min_steps);
  int min_steps = 0;
  mathematical(i, j, min_steps);
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
// -------------------------------
// projects/collatz/RunCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------

// --------
// includes
// --------

#include <iostream> // cin, cout



// ----
// main
// ----

int main () {
    using namespace std;
    //cout << cycle_length(1) << endl;
    //cout << "=======" << endl;
    //cout << cycle_length(10) << endl;
    collatz_solve(cin, cout);
    return 0;}

/*
% g++ -pedantic -std=c++11 -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz



% cat RunCollatz.in
1 10
100 200
201 210
900 1000



% RunCollatz < RunCollatz.in > RunCollatz.out



% cat RunCollatz.out
1 10 1
100 200 1
201 210 1
900 1000 1



% doxygen -g
// That creates the file Doxyfile.
// Make the following edits to Doxyfile.
// EXTRACT_ALL            = YES
// EXTRACT_PRIVATE        = YES
// EXTRACT_STATIC         = YES



% doxygen Doxyfile
// That creates the directory html/.
*/
