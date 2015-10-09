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
    istringstream r("1\n\n3\nJohn Doe\nJane Smith\nSirhan Sirhan\n1 2 3\n2 1 3\n2 3 1\n1 2 3\n3 1 2\n\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("John Doe\n", w.str());}

TEST(Fixture, solve_2) {
    istringstream r("2\n\n3\nJohn Doe\nJane Smith\nSirhan Sirhan\n1 2 3\n2 1 3\n2 3 1\n1 2 3\n3 1 2\n\n3\nJohn Doe\nJane Smith\nSirhan Sirhan\n1 2 3\n2 1 3\n2 3 1\n1 2 3\n3 1 2\n\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("John Doe\n\nJohn Doe\n", w.str());}

TEST(Fixture, solve_3) {
    istringstream r("1\n\n3\nJohn Doe\nJane Smith\nSirhan Sirhan\n1 2 3\n2 1 3\n2 3 1\n1 2 3\n\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("John Doe\nJane Smith\n", w.str());}

TEST(Fixture, solve_4) {
    istringstream r("1\n\n5\nJohn Doe\nJane Smith\nSirhan Sirhan\nBenoy Alexander\nSuzanne Alexander\n1 2 3 4 5\n5 2 1 3 4\n5 2 3 4 1\n1 2 3 4 5\n4 5 3 1 2\n4 3 5 1 2\n2 3 4 5 1\n\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("Benoy Alexander\n", w.str());}

TEST(Fixture, solve_5) {
    istringstream r("1\n\n5\nJohn Doe\nJane Smith\nSirhan Sirhan\nBenoy Alexander\nSuzanne Alexander\n1 2 3 4 5\n5 2 1 3 4\n5 2 3 4 1\n1 2 3 4 5\n4 5 3 1 2\n4 3 5 1 2\n\n");
    ostringstream w;
    solve(r, w);
    ASSERT_EQ("John Doe\nBenoy Alexander\nSuzanne Alexander\n", w.str());}

