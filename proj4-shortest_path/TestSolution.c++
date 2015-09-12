// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair
#include <stdlib.h> // rand

#include "gtest/gtest.h"

#include "Solution.h"

using namespace std;


// -----
// solve
// -----

TEST(Fixture, solve_1) {
    istringstream r("5 6\n1 2 2\n2 5 5\n2 3 4\n1 4 1\n4 3 3\n3 5 1\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("1 4 3 5\n", w.str());
}

TEST(Fixture, solve_2) {
    istringstream r("5 0\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("-1\n", w.str());
}

TEST(Fixture, solve_3) {
    istringstream r("4 4\n1 2 1\n1 3 1\n2 4 1\n3 4 1\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("1 2 4\n", w.str());
}

TEST(Fixture, solve_4) {
    istringstream r("5 5\n1 2 1\n2 3 1\n3 4 1\n1 5 100\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("1 5\n", w.str());
}

TEST(Fixture, solve_5) {
    istringstream r("3 1\n1 2 1\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("-1\n", w.str());
}

TEST(Fixture, solve_6) {
  stringstream r("100000 99999\n");
  for (int x=2; x<=100000; x++) {
    r << x-1 << " " << x << " " << rand() % 100000 + 1 << endl;
  }
  ostringstream w;
  solve(r, w);
  ASSERT_EQ("-1\n", w.str());
}

TEST(Fixture, solve_7) {
    istringstream r("10 10\n1 5 12\n2 4 140\n2 10 149\n3 6 154\n3 7 9\n3 8 226\n3 10 132\n4 10 55\n5 8 33\n7 8 173\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("1 5 8 7 3 10\n", w.str());
}
