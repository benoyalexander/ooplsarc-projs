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


// ----
// eval
// ----

TEST(Fixture, eval_1) {
  const int v = eval(1, 10);
  ASSERT_EQ(0, v);}

TEST(Fixture, eval_2) {
  const int v = eval(100, 200);
  ASSERT_EQ(0, v);}

TEST(Fixture, eval_3) {
  const int v = eval(201, 210);
  ASSERT_EQ(0, v);}

TEST(Fixture, eval_4) {
  const int v = eval(900, 1000);
  ASSERT_EQ(0, v);}

// -----
// solve
// -----

TEST(Fixture, solve_1) {
    istringstream r("1 10\n100 200\n201 210\n900 1000\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("0\n0\n0\n0\n", w.str());}

TEST(Fixture, solve_2) {
    istringstream r("10 1\n200 100\n210 201\n1000 900\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("0\n0\n0\n0\n", w.str());}
