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
    istringstream r("4\n75 150 75 50\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("Yes\n", w.str());}

TEST(Fixture, solve_2) {
    istringstream r("3\n100 150 250\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("No\n", w.str());}
