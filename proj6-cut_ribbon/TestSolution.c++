// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Solution.h"

using namespace std;


// -----
// solve
// -----

TEST(Fixture, solve_1) {
  istringstream r("5 5 3 2\n");
  ostringstream w;
  solve(r, w);
  ASSERT_EQ("2\n", w.str());}

TEST(Fixture, solve_2) {
  istringstream r("7 5 5 2\n");
  ostringstream w;
  solve(r, w);
  ASSERT_EQ("2\n", w.str());}
