/*
- Rezwan Rahman
- CSCI 335
- HW 5: Graph Algorithms
- Graph.h: Contains all our helper functions
*/

#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include "binary_heap.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

//map: used in order to access graph elements
struct map
{
  int destination; //our adjacent vertex
  int flag; //our first vertex
  double weight; //weight of adjacent vertexes
};

struct path
{
    path *path_;
    vector<map> path_list;
    bool visited = false;
    double cost;
    int val; 
    path(int v): val(v){}
    double distance = numeric_limits<double>::max();
};

class Graph
{
//private data members:
//@list_ : a vector that contains our list of adjacent verticies
private:
    vector<vector<map>> &getList()
    {
        return list_;
    }
    vector<vector<map>> list_;
public:
    int verticies; 
    vector<path *> mylist; 
    //zero-param const
    Graph() {}

    //destructor
    ~Graph() {}

    //gives us the amount of Vertexes 
    void numOfVerticies(int verticies)
    {
        list_ = vector<vector<map>>(verticies);
    }

    //Param-const: gives us the number of verticies in our 
    Graph(int verticies)
    {
        numOfVerticies(verticies);
    }

    //are our edges connected
    vector<map> &connectEdges(int vertex)
    {
        return list_.at(vertex - 1);
    }

    //uses our map struct and gives each param its designated value
    void addingEdge(int flag, int destination, double weight)
    {
        map get;
        get.destination = destination;
        get.flag = flag;
        get.weight = weight;
        connectEdges(flag).push_back(get);
    }

    //helps us attain our edgeweight
    double getEdgeWeight(int vertex1, int vertex2)
    {
        for (map get : connectEdges(vertex1))
        {
            if (get.destination == vertex2) return get.weight;
        }
        return -1;
    }

    //chekcs if our verticies are connected, and prints out from the file
    void checkConnections(int vertex1, int vertex2)
    {
        double edgeWeight = getEdgeWeight(vertex1, vertex2);
        if(edgeWeight == -1)
        {
            cout << vertex1 << " " << vertex2 << ": not_connected" << endl;
        }
        else
        {
            cout << vertex1 << " " << vertex2 << ": connected " << edgeWeight << endl;
        }
    }

    void printPath(path *path_list)
    {
        if(path_list->path_ != nullptr)
        {
            printPath(path_list->path_);
        }
        cout<< path_list->val << " "; 
    }

    void Dijkstr(int vertex1)
    {
        BinaryHeap<int> queue;
        queue.insert(vertex1);
        mylist[vertex1]->distance = 0;
        while(!queue.isEmpty())
        {
            int smallest_vertex = queue.findMin();
            mylist[smallest_vertex]->visited = true;
            queue.deleteMin();
            for(unsigned int i=0; i < mylist[smallest_vertex]->path_list.size(); i++)
            {
                int amntSmallVertex = mylist[smallest_vertex]->path_list[i].flag;
                double cost = mylist[smallest_vertex]->path_list[i].weight;
                if(mylist[smallest_vertex]->visited == true && mylist[smallest_vertex]->distance + cost < mylist[amntSmallVertex]->distance)
                {
                    mylist[amntSmallVertex]->distance = mylist[smallest_vertex]->distance + cost;
                    mylist[amntSmallVertex]->path_ = mylist[smallest_vertex];
                    queue.insert(amntSmallVertex);
                }
            }
        }
        for(int i=1; i <= verticies; i++)
        {
            cout << i << ": ";
            double cost = mylist[i]->distance;
            if(cost != numeric_limits<double>::max())
            {
                path *test = mylist[i];
                printPath(test);
                cout.precision(1);
                cout << fixed << "cost: " << cost << endl;
            }
            else
            {
                cout << "not_possible" << endl; 
            }
        }
    }
    


};
#endif