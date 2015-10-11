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
#include <vector>

#include "Solution.h"

using namespace std;

#ifdef DBG
bool DEBUG = true;
#else
bool DEBUG = false;
#endif


// ------------
// eval
// ------------

int eval (int i, int j) {
    return 0;
}

// -------------
// solve
// -------------

void solve (istream& r, ostream& w) {
  // parse input
  string s;
  while (getline(r, s)) {
    istringstream sin(s);
    int num_players;
    int num_pairs;
    sin >> num_players >> num_pairs;
    if (DEBUG) cout << "Players=" << num_players << " Pairs=" << num_pairs << endl;

    vector<vector<int> > teams(num_players / 3);
    int team_id = 0;
    vector<int> player_on_team(num_players + 1, -1);

    for (int x = 0; x < num_pairs; ++x) {
      getline(r, s);
      istringstream sin(s);
      int p1, p2;
      sin >> p1 >> p2;
      if (DEBUG) cout << "Pairing: " << p1 << " " << p2 << endl;

      // Check to see if players are already on another team
      if (player_on_team[p1] == -1 && player_on_team[p2] == -1) {
	if (team_id >= num_players / 3) {
	  if (DEBUG) cout << "TERM: creating more teams than allowed" << endl;
	  w << "-1" << endl;
	  return;
	}
	player_on_team[p1] = team_id;
	player_on_team[p2] = team_id;
	if (DEBUG) cout << "New team #" << team_id << " for " << p1 << " " << p2 << endl;
	teams[team_id].push_back(p1);
	teams[team_id].push_back(p2);
	++team_id;
      } else if (player_on_team[p1] == -1 || player_on_team[p2] == -1) {
	if (player_on_team[p1] == -1) {
	  player_on_team[p1] = player_on_team[p2];
	  if (DEBUG) cout << p1 << " joining " << p2 << " on team #" << player_on_team[p2] << endl;
	  if (teams[player_on_team[p2]].size() >= 3) {
	    if (DEBUG) cout << "TERM: too many players on team#" << player_on_team[p2] << endl;
	    w << "-1" << endl;
	    return;
	  }
	  teams[player_on_team[p2]].push_back(p1);
	} else {
	  player_on_team[p2] = player_on_team[p1];
	  if (DEBUG) cout << p2 << " joining " << p1 << " on team #" << player_on_team[p1] << endl;
	  if (teams[player_on_team[p1]].size() >= 3) {
	    if (DEBUG) cout << "TERM: too many players on team#" << player_on_team[p1] << endl;
	    w << "-1" << endl;
	    return;
	  }
	  teams[player_on_team[p1]].push_back(p2);
	}
      } else if (player_on_team[p1] != player_on_team[p2]) {
	// Both on separate teams already
	if (DEBUG) cout << "TERM: players on separate teams already" << endl;
	w << "-1" << endl;
	return;
      }
    }

    // Need to fill remaining players on teams with available slots
    int curr_team = 0;
    for (int player = 1; player <= num_players; ++player) {
      if (player_on_team[player] == -1) {
	// Find slot on team
	while (teams[curr_team].size() >= 3) {
	  ++curr_team;
	}
	teams[curr_team].push_back(player);
	if (DEBUG) cout << "Found player " << player << " with no team and assigning to team#" << curr_team << endl;
      }
    }

    for (unsigned team = 0; team < teams.size(); ++team) {
      for (int player = 0; player < 2; ++player) {
	w << teams[team][player] << " ";
      }
      w << teams[team][2] << endl;
    }
  }
}
