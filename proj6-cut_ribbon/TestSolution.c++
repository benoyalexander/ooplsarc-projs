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

TEST(Fixture, solve_3) {
  istringstream r("100 2 2 2\n");
  ostringstream w;
  solve(r, w);
  ASSERT_EQ("50\n", w.str());}

TEST(Fixture, solve_4) {
  istringstream r("100 1 2 3\n");
  ostringstream w;
  solve(r, w);
  ASSERT_EQ("100\n", w.str());}

TEST(Fixture, solve_5) {
  istringstream r("100 23 15 50\n");
  ostringstream w;
  solve(r, w);
  ASSERT_EQ("2\n", w.str());}

TEST(Fixture, solve_6) {
  istringstream r("4000 3 4 5\n");
  ostringstream w;
  solve(r, w);
  ASSERT_EQ("1333\n", w.str());}

TEST(Fixture, solve_7) {
  istringstream r("418 18 14 17\n");
  ostringstream w;
  solve(r, w);
  ASSERT_EQ("29\n", w.str());}

TEST(Fixture, solve_8) {
  istringstream r("2683 83 26 2709\n");
  ostringstream w;
  solve(r, w);
  ASSERT_EQ("101\n", w.str());}

TEST(Fixture, solve_9) {
  istringstream r("3455 244 3301 3\n");
  ostringstream w;
  solve(r, w);
  ASSERT_EQ("27\n", w.str());}

TEST(Fixture, solve_10) {
  istringstream r("29 27 18 2\n");
  ostringstream w;
  solve(r, w);
  ASSERT_EQ("2\n", w.str());}

TEST(Fixture, solve_11) {
  istringstream r("3119 3515 1021 7\n");
  ostringstream w;
  solve(r, w);
  ASSERT_EQ("11\n", w.str());}
