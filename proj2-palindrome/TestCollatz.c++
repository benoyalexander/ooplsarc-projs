// --------------------------------
// projects/collatz/TestCollatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair

#include "gtest/gtest.h"

#include "Collatz.h"

using namespace std;

// -----------
// TestCollatz
// -----------

// ----
// read
// ----

TEST(CollatzFixture, read) {
    string s("NA\n");
    const char* p = collatz_read(s);
    ASSERT_STREQ( "NA", p);}

// ----
// eval
// ----

TEST(CollatzFixture, pal_1) {
    const bool v = is_pallindrome("revive");
    ASSERT_EQ(false, v);}
TEST(CollatzFixture, pal_2) {
    const bool v = is_pallindrome("reviver");
    ASSERT_EQ(true, v);}
TEST(CollatzFixture, pal_3) {
    const bool v = is_pallindrome("e");
    ASSERT_EQ(true, v);}
TEST(CollatzFixture, pal_4) {
    const bool v = is_pallindrome("noob");
    ASSERT_EQ(false, v);}
TEST(CollatzFixture, pal_5) {
    const bool v = is_pallindrome("noon");
    ASSERT_EQ(true, v);}
TEST(CollatzFixture, pal_6) {
    const bool v = is_pallindrome("stick");
    ASSERT_EQ(false, v);}


TEST(CollatzFixture, eval_1) {
  string s("revive");
  collatz_eval(s);
  ASSERT_STREQ("reviver", s.c_str());}

TEST(CollatzFixture, eval_2) {
  string s("ee");
  collatz_eval(s);
  ASSERT_STREQ("exe", s.c_str());}

TEST(CollatzFixture, eval_3) {
  string s("kitayuta");
  collatz_eval(s);
  ASSERT_STREQ("NA", s.c_str());}

TEST(CollatzFixture, eval_4) {
  string s("beab");
  collatz_eval(s);
  ASSERT_STREQ("baeab", s.c_str());}

TEST(CollatzFixture, eval_5) {
  string s("sdijis");
  collatz_eval(s);
  ASSERT_STREQ("sdijids", s.c_str());}

TEST(CollatzFixture, eval_6) {
  string s("lsdijfjisl");
  collatz_eval(s);
  ASSERT_STREQ("lsdijfjidsl", s.c_str());}

TEST(CollatzFixture, eval_7) {
  string s("level");
  collatz_eval(s);
  ASSERT_STREQ("levvel", s.c_str());}


// -----
// print
// -----

TEST(CollatzFixture, print) {
    ostringstream w;
    string v = "NA";
    collatz_print(w, v);
    ASSERT_STREQ("NA\n", w.str().c_str());}

// -----
// solve
// -----

TEST(CollatzFixture, solve) {
    istringstream r("revive\nee\nkitayuta\n");
    ostringstream w;
    collatz_solve(r, w);
    ASSERT_STREQ("reviver\nexe\nNA\n", w.str().c_str());}

/*
% g++ -fprofile-arcs -ftest-coverage -pedantic -std=c++11 -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lgtest -lgtest_main -lpthread



% valgrind TestCollatz                                         >  TestCollatz.out 2>&1
% gcov -b Collatz.c++     | grep -A 5 "File 'Collatz.c++'"     >> TestCollatz.out
% gcov -b TestCollatz.c++ | grep -A 5 "File 'TestCollatz.c++'" >> TestCollatz.out



% cat TestCollatz.out
==14225== Memcheck, a memory error detector
==14225== Copyright (C) 2002-2011, and GNU GPL'd, by Julian Seward et al.
==14225== Using Valgrind-3.7.0 and LibVEX; rerun with -h for copyright info
==14225== Command: TestCollatz
==14225==
Running main() from gtest_main.cc
[==========] Running 7 tests from 1 test case.
[----------] Global test environment set-up.
[----------] 7 tests from Collatz
[ RUN      ] Collatz.read
[       OK ] Collatz.read (31 ms)
[ RUN      ] Collatz.eval_1
[       OK ] Collatz.eval_1 (5 ms)
[ RUN      ] Collatz.eval_2
[       OK ] Collatz.eval_2 (3 ms)
[ RUN      ] Collatz.eval_3
[       OK ] Collatz.eval_3 (3 ms)
[ RUN      ] Collatz.eval_4
[       OK ] Collatz.eval_4 (3 ms)
[ RUN      ] Collatz.print
[       OK ] Collatz.print (17 ms)
[ RUN      ] Collatz.solve
[       OK ] Collatz.solve (10 ms)
[----------] 7 tests from Collatz (88 ms total)

[----------] Global test environment tear-down
[==========] 7 tests from 1 test case ran. (132 ms total)
[  PASSED  ] 7 tests.
==14225==
==14225== HEAP SUMMARY:
==14225==     in use at exit: 0 bytes in 0 blocks
==14225==   total heap usage: 495 allocs, 495 frees, 70,302 bytes allocated
==14225==
==14225== All heap blocks were freed -- no leaks are possible
==14225==
==14225== For counts of detected and suppressed errors, rerun with: -v
==14225== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 2 from 2)
File 'Collatz.c++'
Lines executed:100.00% of 17
Branches executed:100.00% of 18
Taken at least once:61.11% of 18
Calls executed:89.47% of 19
Creating 'Collatz.c++.gcov'
File 'TestCollatz.c++'
Lines executed:100.00% of 26
Branches executed:57.14% of 224
Taken at least once:28.57% of 224
Calls executed:54.07% of 209
Creating 'TestCollatz.c++.gcov'
*/
