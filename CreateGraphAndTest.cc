// /*
// - Rezwan Rahman
// - CSCI 335
// - HW 5: Graph Algorithms
// - CreateGraphAndTest.cc
// - Q1 Adjacency: We want to list adjacent vertices with positive edge weights.
// If our verticies are adjacent our program will print weight of edge that connects them.
// */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "graph.h"

using namespace std;

//reads graph file and checks our edges
static Graph graph_txt(string graphFile)
  {
    ifstream graph_input;
    graph_input.open(graphFile);
    if(graph_input.fail()) {cout<<"error: cant open"<<endl;}
    string read_line;

    getline(graph_input, read_line);
    int verticies = stoi(read_line);
    Graph my_graph(verticies);
    while (getline(graph_input, read_line))
    {
      stringstream ss(read_line);
      string flag;
      ss >> flag;
      int vertex1 = stoi(flag);
      // cout << fromVertex << endl;
      while (ss >> flag)
      {
        int vertex2 = stoi(flag);
        ss >> flag;
        double weight = stod(flag);
        my_graph.addingEdge(vertex1, vertex2, weight);
      }
    }
    graph_input.close();
    return my_graph;
  }

//reads adjfile, and outputs connected and not connected verticies
void adj_txt(Graph graph, string adjFile)
{
  ifstream adj_input;
  adj_input.open(adjFile);
  string my_line;
  while (getline(adj_input, my_line))
  {
    stringstream ss(my_line);
    string iter;
    ss >> iter;
    int vertex1 = stoi(iter);
    ss >> iter;
    int vertex2 = stoi(iter);
    graph.checkConnections(vertex1, vertex2);
  }
}

//will test our files and compute output
int graphTestDriver(int argc, char **argv)
{
  string graphFile = argv[1];
  string adjFile = argv[2];
  Graph graph = graph_txt(graphFile);
  adj_txt(graph, adjFile);
  return 0;
}

//main for testing
int main(int argc, char **argv)
{
  if (argc != 3)
  {
    cout << "Usage: " << argv[0] << " <GRAPH_File>"
         << "<ADJACENCY_QUERYFILE>" << endl;
    return 0;
  }

  graphTestDriver(argc, argv);

  return 0;
}