// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream, cin, cout
#include <sstream>  // istringstream
#include <string>   // getline, string, to_string
#include <queue>
#include <limits>
#include <algorithm>
#include <bitset>
#include <list>

#include "Solution.h"

using namespace std;

bool DEBUG = false;

// ------------
// priority queue
// ------------
typedef pair<int, int> TVertexDistance;
struct less_vertex_min {
  // Used for heap to make a min priority queue
  bool operator()(const TVertexDistance& lhs,
		  const TVertexDistance& rhs) {
    return lhs.second > rhs.second;
  }
};


typedef vector<pair<int, int> > TVertexMinimumPrevious;  // [vertex] = < shortest dist, prev vertex >
typedef priority_queue<TVertexDistance, std::vector<TVertexDistance>, less_vertex_min> TPQMin;

void calc_paths(int max_vertex, const TypeGraph& graph, TVertexMinimumPrevious& vert_min_dist) {
  TPQMin paths;
  bitset<100001> visited;

  // initial state for pq
  TVertexDistance state(1, 0);
  paths.push(state);
  vert_min_dist[1].first = 0;
  vert_min_dist[1].second = 0;
  
  while (!paths.empty()) {
    TVertexDistance state(paths.top());
    paths.pop();
    
    const int& curr_vert = state.first;
    const int& curr_dist = state.second;

    visited.set(curr_vert);
    if (DEBUG) cout << "Visited " << curr_vert << endl;

    for (const auto x : graph.at(curr_vert)) {
      const int next_vert = x.first;
      const int next_dist = x.second;
      const int total_dist = curr_dist + next_dist;

      bool visited_next_vert = visited[next_vert];
	
      if (DEBUG) cout << "Check edge " << curr_vert << "->" << next_vert << " visited=" << visited_next_vert << " dist=" << total_dist << " min for " << next_vert << "=" << vert_min_dist[next_vert].first << endl;

      if (total_dist < vert_min_dist[next_vert].first && !visited[next_vert]) {
	vert_min_dist[next_vert].first = total_dist; // Min total dist
	vert_min_dist[next_vert].second = curr_vert; // Prev vertex
	if (DEBUG) cout << "Min: " << curr_vert << "->" << next_vert << " dist=" << vert_min_dist[next_vert].first << " prevV=" << vert_min_dist[next_vert].second << endl;	  
	if (next_vert != max_vertex) {
	  TVertexDistance state(next_vert, total_dist);
	  paths.push(state);
	  if (DEBUG) cout << "Push: " << curr_vert << "->" << next_vert << endl;
	}
      }
    }
  }
}

// ------------
// eval
// ------------

string eval (int max_vertex, const TypeGraph& graph) {
  if (graph.size() == 0) return "-1"; // no edges
  if (graph.find(max_vertex) == graph.end() || graph.at(max_vertex).size() == 0) return "-1"; // Can't get to last state

  TVertexMinimumPrevious min_paths(max_vertex + 1, make_pair(numeric_limits<int>::max(), numeric_limits<int>::max()));

  calc_paths(max_vertex, graph, min_paths);

  int vertex = max_vertex;
  list<int> path;

  while (vertex != 0) {
    if (min_paths[max_vertex].second == numeric_limits<int>::max()) {
      if (DEBUG) cout << "Vertex with MAX_INT" << endl;
      return "-1";
    }
    path.push_front(vertex);
    //cout << "Push vertex:" << vertex << " " << endl;;
    vertex = min_paths[vertex].second;
  }

  ostringstream solution;

  for (auto& item : path) {
    solution << item;
    if (item != max_vertex) {
      solution << " ";
    }
  }
  
  return solution.str();
}

// -------------
// solve
// -------------

void solve (istream& r, ostream& w) {
  // parse input

  int verts = 0;
  int edges = 0;
  {
    string s;
    getline(r, s);
    istringstream sin(s);
    sin >> verts >> edges;
  }

  TypeGraph graph;
  {
    for (int x = 0; x < edges; ++x) {
      string s;
      getline(r, s);
      istringstream sin(s);
      int i, j, k;
      sin >> i >> j >> k;

      graph[i][j] = k;
      graph[j][i] = k;
    }
  }

  // solve
  w << eval(verts, graph) << endl;
}
