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
    istringstream r("3 0\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("1 2 3\n", w.str());}

TEST(Fixture, solve_2) {
    istringstream r("6 4\n1 2\n2 3\n3 4\n5 6\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("-1\n", w.str());}

TEST(Fixture, solve_3) {
    istringstream r("3 3\n1 2\n2 3\n1 3\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("1 2 3\n", w.str());}

TEST(Fixture, solve_4) {
    istringstream r("6 3\n1 2\n3 4\n5 6\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("-1\n", w.str());}
