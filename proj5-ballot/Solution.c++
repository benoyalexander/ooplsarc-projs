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
#include <limits>   // numeric_limits

#include "Solution.h"

using namespace std;


#ifdef DBG
bool DEBUG = true;
#else
bool DEBUG = false;
#endif

static const int MAX_BALLOTS = 1000;
static const int MAX_CANDIDATES = 20;


// ------------
// eval
// ------------

void eval (ostream& output, int num_ballots, const TypeBallots& ballots, int num_candidates, const TypeCandidates& str_candidates) {
  const int min_to_win = (num_ballots >> 1) + 1;
  if (DEBUG) cout << "Min votes to win " << min_to_win << endl;

  bool done = false;
  vector<int> candidate_num_votes(num_candidates);
  TypeVotes votes(num_candidates);  // [vector: Candidate][list: Ballot idx]

  // Initialize based on first vote
  if (DEBUG) cout << "Init first vote" << endl;
  for (int ballot_idx = 0; ballot_idx < num_ballots; ++ballot_idx) {
    const int vote_candidate = ballots[ballot_idx][0] - 1;
    ++candidate_num_votes[vote_candidate];
    votes[vote_candidate].push_back(ballot_idx);
  }
  if (DEBUG) cout << "Done Init first vote" << endl;

  while (!done) {
    int lowest_vote_count = numeric_limits<int>::max();
    int num_candidates_with_lowest_vote = 0;
    int available_candidates = 0;

    for (int x = 0; x < num_candidates; ++x) {
      const int num_votes = candidate_num_votes[x];

      if (num_votes == 0) {
	// Eliminated already
	continue;
      } else {
	++available_candidates;
      }
      
      // Check to see if we have anyone at 50%+ of the votes
      if (num_votes >= min_to_win) {
	// Found one winner
	if (DEBUG) cout << "Sole winner " << x + 1 << endl;
	output << str_candidates[x] << endl;
	done = true;
	return;
      };

      // Find the lowest count
      if (num_votes < lowest_vote_count) {
	lowest_vote_count = num_votes;
	num_candidates_with_lowest_vote = 1;
	if (DEBUG) cout << "Found new lowest vote total " << lowest_vote_count << " from candidate " << x + 1 <<  endl;
      } else if (num_votes == lowest_vote_count) {
	++num_candidates_with_lowest_vote;
	if (DEBUG) cout << "Found candidate " << x + 1 << " which is another with lowest vote total" << endl;
      }
    }

    if (DEBUG) cout << "Lowest count " << lowest_vote_count << " for " << num_candidates_with_lowest_vote << " candidates" << endl;
    
    // Check for ties and not other available candidates
    if (available_candidates == num_candidates_with_lowest_vote) {
      for (int x = 0; x < num_candidates; ++x) {
	const int num_votes = votes[x].size();
	if (num_votes == lowest_vote_count) {
	  if (DEBUG) cout << "Tie " << x + 1 << endl;
	  output << str_candidates[x] << endl;
	  done = true;
	}
      }
    }

    if (done) {
      return;
    }

    // Eliminate the lowest candidates' votes looking for the
    // highest vote for candidate who has not been eliminated
    for (int candidate = 0; candidate < num_candidates; ++candidate) {
      const int num_votes = votes[candidate].size();

      if (num_votes == lowest_vote_count) {
	if (DEBUG) cout << "Eliminate " << candidate + 1 << endl;
	// Look through all the ballots of the losing candidate
	while (votes[candidate].size()) {
	  int ballot_idx = votes[candidate].front();
	  votes[candidate].pop_front();

	  // Look for highest ranked vote who has not been eliminated
	  for (int vote = 0; vote < num_candidates; ++vote) {
	    const int new_candidate = ballots[ballot_idx][vote] - 1;

	    if (candidate_num_votes[new_candidate] != 0 &&
		candidate_num_votes[new_candidate] != lowest_vote_count) {
	      if (DEBUG) cout << "Add vote to " << new_candidate + 1 << endl;
	      votes[new_candidate].push_back(ballot_idx);
	      ++candidate_num_votes[new_candidate];
	      break;
	    }
	  }
	}

	--available_candidates;
	candidate_num_votes[candidate] = 0;
      }
    }

    assert(available_candidates);
  }
  
  return;
}

// -------------
// solve
// -------------

void solve (istream& r, ostream& w) {
  // parse input
  string s;
  int state = 0;

  int num_trials = 0;
  int num_candidates = 0, cnt_candidates = 0;
  TypeCandidates str_candidates(MAX_CANDIDATES);
  TypeBallots ballots(MAX_BALLOTS);
  int ballot_idx = 0;
  vector<int> vote(MAX_CANDIDATES);
  
  while (getline(r, s)) {
    //if (DEBUG) cout << "Next char " << r.peek() << endl;
    istringstream sin(s);

    if (state == 0) {
      // Trials
      sin >> num_trials;
      ++state;
      if (DEBUG) cout << "Trials " << num_trials << endl;
    } else if (state == 1) {
      // blank line
      ++state;
    } else if (state == 2) {
      // Num Candidates
      sin >> num_candidates;
      cnt_candidates = 0;
      ++state;
      //vote.resize(num_candidates);
      if (DEBUG) cout << "Num Cand " << num_candidates << endl;
    } else if (state == 3) {
      // Candidate names
      str_candidates[cnt_candidates] = s;
      if (DEBUG) cout << "new cand " << str_candidates[cnt_candidates] << endl;
      ++cnt_candidates;

      if (cnt_candidates >= num_candidates) {
	++state;
      }
    } else if (state == 4) {
      // Ballots
      if (DEBUG) cout << "got <" << s << ">" << endl;
      if (s == "" || r.eof()) {
	if (DEBUG) cout << "Calling eval()" << endl;
	eval(w, ballot_idx, ballots, num_candidates, str_candidates);

	--num_trials;
	if (num_trials) {
	  if (DEBUG) cout << "Next trial" << endl;
	  w << endl; // New line to separate answers
	  state = 2;
	  // Reset data structs
	  ballots.clear();
	  ballots.resize(MAX_BALLOTS);
	  ballot_idx = 0;
	} else {
	  if (DEBUG) cout << "Done with trials" << endl;
	  return;
	}
      } else {
	istringstream b(s);
	int i = 0;
	if (DEBUG) cout << "New ballot ";
	for (int x = 0; x < num_candidates; ++x) {
	  b >> i;
	  if (DEBUG) cout << i << ",";
	  vote[x] = i;
	}
	if (DEBUG) cout << endl;

	ballots[ballot_idx++] = (vote);
      }

    } else {
      cout << "Unknown state" << endl;
    }
  }

  if (DEBUG) cout << "EOF" << endl;
  if (DEBUG) cout << "Calling eval()" << endl;
  eval(w, ballot_idx, ballots, num_candidates, str_candidates);
}
