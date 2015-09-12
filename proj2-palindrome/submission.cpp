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
const char* collatz_read (const string& s);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length of the range [i, j]
 */
//int collatz_eval (int i, int j);
void collatz_eval (string& str);

bool is_pallindrome(const char* s);

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
void collatz_print (ostream& w, const string& v);

// -------------
// collatz_solve
// -------------

/**
 * @param r an istream
 * @param w an ostream
 */
void collatz_solve (istream& r, ostream& w);

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
#include <utility>  // make_pair, pair
#include <cstring>



using namespace std;

// ------------
// collatz_read
// ------------

const char* collatz_read (const string& s) {
  istringstream sin(s);
  string output;
  sin >> output;
  return output.c_str();}


// ------------
// is_pallindrome
// ------------

bool is_pallindrome(const char* s) {
  int y = strlen(s);
  int y_half = y >> 1;
  int x = 0;
  
  while (x < y_half) {
    if (s[x++] != s[--y])
      return false;
  }

  return true;
}
    

// ------------
// collatz_eval
// ------------

// revive
// noon
// nean -> naean
void collatz_eval (string& str) {
  const int length = str.length();

  if (is_pallindrome(str.c_str())) {
    if (length > 1) {
      if ((length & 0x1) == 0) {
	str = str.substr(0, length >> 1) + 'x' + str.substr(length >> 1);
      } else {
	str = str.substr(0, length >> 1) + str[(length >> 1)] + str.substr(length >> 1);
      }	
    } else {
      str = str + str;
    }
    return;
  }
  
  // Brute Force
  for (int x = 0; x < length + 1; ++x) {
    string sol;
    char new_char = 0;
    sol = str.substr(0, x);
    if (x < length) {
      new_char = str[length - 1 - x];
      sol += new_char;
    } else {
      new_char = str[0];
      sol += new_char;
    }
    sol += str.substr(x);
    //    cout << "trying+ " << new_char << " " << sol << endl;
    if (is_pallindrome(sol.c_str())) {
      str = sol;
      return;
    }
  }
  for (int x = length; x > 0; --x) {
    string sol;
    char new_char = 0;
    sol = str.substr(0, x);
    if (x < length) {
      new_char = str[length - x];
      sol += new_char;
    } else {
      new_char = str[0];
      sol += new_char;
    }
    sol += str.substr(x);
    //    cout << "trying- " << new_char << " " << sol << endl;
    if (is_pallindrome(sol.c_str())) {
      str = sol;
      return;
    }
  }
  str = "NA";
}


// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, const string& v) {
    w << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
      collatz_eval(s);
      collatz_print(w, s);}}
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
