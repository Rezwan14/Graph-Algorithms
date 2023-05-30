#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "graph.h"

using namespace std;

int pathfindDriver(int argc, char **argv) 
{
  string graphFile(argv[1]);
  const double& begin(atoi(argv[2]));
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
    my_graph.Dijkstr(begin);
  return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_FILE>" << "<STARTING_VERTEX>" << endl;
		return 0;
    }

    pathfindDriver(argc, argv);

    return 0;
}
